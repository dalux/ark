<?php

namespace Ark\Router\Driver;

use Ark\Core\Captain;
use ReflectionClass;
use Ark\Core\Struct;
use Ark\Http\Request;
use Ark\Core\Loader;
use Ark\Router\Exception;
use Ark\Router\Driver as RouterDriver;
use Ark\Event\Adapter as EventAdapter;
use Ark\Controller\Base as BaseController;

class Native extends RouterDriver
{

    /**
     * 路由转换规则
     *
     * @var array
     */
    private $_rules = array();

    /**
     * 添加路由规则
     *
     * @param string $rule
     * @param string $redirect
     * @return $this
     */
    function addRule($rule, $redirect)
    {
        $this->_rules[$rule] = $redirect;
        return $this;
    }

    /**
     * 执行路由
     *
     * @param string $uri
     * @return string
     * @throws Exception
     */
    function doAction($uri)
    {
        //解析前事件
        $data = array('driver'=> 'Native', 'uri'=> $uri);
        $rule = array(
            'driver'=> array(Struct::FLAG_REQUIRED=> true, Struct::FLAG_TYPE=> Struct::TYPE_STRING),
            'uri'=> array(Struct::FLAG_REQUIRED=> true, Struct::FLAG_TYPE=> Struct::TYPE_STRING),
        );
        $data = EventAdapter::onListening('event.routing.before', $data, $rule);
        $uri = $data['uri'];
        //解析URI
        if (strpos($uri, '?') !== false) {
            $query = substr($uri, strpos($uri, '?') + 1);
            $query = str_replace(array('&', '='), '/', $query);
            $query = explode('/', $query);
            $query = array_chunk($query, 2);
            foreach ($query as $key=> $val) {
                Captain::getInstance()->request->add($val[0], $val[1], Request::FLAG_GET);
            }
            $uri = substr($uri, 0, strpos($uri, '?'));
        }
        //重写
        $uri = trim($this->_rewrite($uri), '/');
        //解析后事件
        $data = array('driver'=> 'Native', 'uri'=> $uri);
        $rule = array(
            'driver'=> array(Struct::FLAG_REQUIRED=> true, Struct::FLAG_TYPE=> Struct::TYPE_STRING),
            'uri'=> array(Struct::FLAG_REQUIRED=> true, Struct::FLAG_TYPE=> Struct::TYPE_STRING),
        );
        $data = EventAdapter::onListening('event.routing.finish', $data, $rule);
        $uri = $data['uri'];
        //处理URI,组装控制器类
        $urlsep = Captain::getInstance()->config->router->urlsep;
        $url_suffix = Captain::getInstance()->config->router->urlsuffix;
        $action = Captain::getInstance()->config->router->default->action;
        if (strpos($uri, $url_suffix) !== false) {
            $uri = preg_replace(sprintf('~%s$~i', $url_suffix), '', $uri);
        }
        $app_name = Captain::getInstance()->getAppName();
        $controller_dir = Captain::getInstance()->getControllerDir();
        $app_dir = Captain::getInstance()->getAppDir();
        $path_now = $controller_dir;
        if ($uri == '') {
            $controller = ucfirst(Captain::getInstance()->config->router->default->controller);
        } else {
            $controllers = array_map('ucfirst', explode($urlsep, $uri));
            $controller = implode('\\', $controllers);
            $path_now.= DIRECTORY_SEPARATOR. implode(DIRECTORY_SEPARATOR, $controllers);
            $path_now = dirname($path_now);
        }
        defined('PATH_NOW') || define('PATH_NOW', $path_now);
        Loader::setAlias('~', PATH_NOW);
        $part = str_replace($app_dir, '', $controller_dir);
        $part = trim(str_replace(array('/', '\\'), '\\', $part), '\\');
        $part = array_map('ucfirst', explode('\\', $part));
        $part = implode('\\', $part);
        $namespace = $app_name. '\\'. $part. '\\'. $controller;
        if (!class_exists($namespace)) {
            throw new Exception(sprintf(Captain::getInstance()->lang->get('router.controller_not_found'), $namespace));
        }
        $ref = new ReflectionClass($namespace);
        if ($ref->isAbstract()) {
            throw new Exception(sprintf(Captain::getInstance()->lang->get('router.controller_is_protected'), $namespace));
        }
        $instance = new $namespace();
        if (!$instance instanceof BaseController) {
            throw new Exception(sprintf(Captain::getInstance()->lang->get('router.controller_extends_error'), '\\Ark\\Controller\\Base'));
        } elseif (!method_exists($instance, $action)) {
            throw new Exception(sprintf(Captain::getInstance()->lang->get('router.action_not_found'), $namespace, $action));
        }
        $output = null;
        //自动化类
        if (method_exists($instance, '__init')) {
            $output = $instance->__init();
        }
        //目标控制器行为
        if (is_null($output)) {
            $output = $instance->{$action}();
        }
        return $output;
    }

    /**
     * 重写URL规则
     *
     * @param $uri
     * @return mixed
     * @throws Exception
     */
    private function _rewrite($uri)
    {
        foreach ($this->_rules as $key=> $val) {
            $key = '~'. $key. '~i';
            if (preg_match($key, $uri)) {
                if (is_string($val)) {
                    $uri = preg_replace($key, $val, $uri);
                    break;
                } elseif (is_callable($val)) {
                    $uri = preg_replace_callback($key, $val, $uri);
                    break;
                } elseif (!is_callable($val) && is_array($val)) {
                    throw new Exception(sprintf(Captain::getInstance()->lang->get('router.call_func_failed'), $val[0]. '::'. $val[1]. '()'));
                }
            }
        }
        if (!is_string($uri)) {
            throw new Exception(Captain::getInstance()->lang->get('router.uri_must_string'));
        }
        return $uri;
    }

}
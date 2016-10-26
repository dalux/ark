<?php

namespace Ark\Com\Router\Driver;

use Ark\Com\Http\Request;
use Ark\Core\Controller;
use Ark\Core\Loader;
use Ark\Core\Noah;
use Ark\Contract\RouterDriver;
use Ark\Com\Router\RuntimeException;

class Native implements RouterDriver
{

    /**
     * 路由转换规则
     *
     * @var array
     */
    private $_rules = array();

    /**
     * 添加路径规则
     *
     * @param $rule
     * @param $redirect
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
     * @throws RuntimeException
     */
    function doAction($uri)
    {
        if (strpos($uri, '?') !== false) {
            $query = substr($uri, strpos($uri, '?') + 1);
            $query = str_replace(array('&', '='), '/', $query);
            $query = explode('/', $query);
            $query = array_chunk($query, 2);
            Noah::getInstance()->request->del(Request::FLAG_GET);
            foreach ($query as $key=> $val) {
                Noah::getInstance()->request->add($val[0], $val[1], Request::FLAG_GET);
            }
            $uri = substr($uri, 0, strpos($uri, '?'));
        }
        $uri = trim($this->_rewrite($uri), '/');
        $urlsep = Noah::getInstance()->config->router->urlsep;
        $url_suffix = Noah::getInstance()->config->router->urlsuffix;
        $action = Noah::getInstance()->config->router->default->action;
        if (strpos($uri, $url_suffix) !== false) {
            $uri = preg_replace(sprintf('~%s$~i', $url_suffix), '', $uri);
        }
        $app_name = Noah::getInstance()->getAppName();
        $controller_dir = Noah::getInstance()->getControllerDir();
        $app_dir = Noah::getInstance()->getAppDir();
        $path_now = $controller_dir;
        $controller = '';
        if ($uri == '') {
            $controller = ucfirst(Noah::getInstance()->config->router->default->controller);
        } else {
            $controllers = array_map('ucfirst', explode($urlsep, $uri));
            $controller = implode('\\', $controllers);
            $path_now.= DIRECTORY_SEPARATOR. implode(DIRECTORY_SEPARATOR, $controllers);
        }
        defined('PATH_NOW') || define('PATH_NOW', $path_now);
        Loader::setAlias('~', PATH_NOW);
        $part = str_replace($app_dir, '', $controller_dir);
        $part = trim(str_replace(array('/', '\\'), '\\', $part), '\\');
        $part = array_map('ucfirst', explode('\\', $part));
        $part = implode('\\', $part);
        $namespace = $app_name. '\\'. $part. '\\'. $controller;
        if (!class_exists($namespace)) {
            throw new RuntimeException(sprintf(Noah::getInstance()->language->get('core.controller_not_found'), $namespace));
        }
        $instance = new $namespace();
        if (!$instance instanceof Controller) {
            throw new RuntimeException(sprintf(Noah::getInstance()->language->get('core.controller_extends_error'), '\\Ark\\Core\\Controller'));
        } elseif (!method_exists($instance, $action)) {
            throw new RuntimeException(sprintf(Noah::getInstance()->language->get('core.action_not_found'), $namespace, $action));
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
     * @throws RuntimeException
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
                    throw new RuntimeException(sprintf(Noah::getInstance()->language->get('router.call_func_failed'), $val[0]. '::'. $val[1]. '()'));
                }
            }
        }
        if (!is_string($uri)) {
            throw new RuntimeException(Noah::getInstance()->language->get('router.uri_must_string'));
        }
        return $uri;
    }

}
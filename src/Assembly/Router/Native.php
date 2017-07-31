<?php

namespace Ark\Assembly\Router;

use Ark\Core\Noah;
use ReflectionClass;
use Ark\Core\Request;
use Ark\Core\Loader;

class Native extends Father
{

    /**
     * 路由转换规则
     *
     * @var array
     */
    private $_rules = array();

    /**
     * 拦截器
     *
     * @var array
     */
    private $_interceptors = array();

    /**
     * 控制器命名空间
     *
     * @var string
     */
    private $_namespace;

    /**
     * 模块名称
     *
     * @var string
     */
    private $_module;

    /**
     * 控制器名称
     *
     * @var string
     */
    private $_controller;

    /**
     * 行为名称
     *
     * @var string
     */
    private $_action;

    /**
     * 获取模块名称
     *
     * @return string
     */
    function getModule()
    {
        return $this->_module;
    }

    /**
     * 获取控制器名称
     *
     * @return string
     */
    function getController()
    {
        return $this->_controller;
    }

    /**
     * 获取控制器名称
     *
     * @return string
     */
    function getAction()
    {
        return $this->_action;
    }

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
     * 添加拦截器规则
     *
     * @param $subspace
     * @param $operator
     * @throws Exception
     */
    function addInterceptor($subspace, $operator)
    {
        $subspace = trim($subspace, '\\');
        if (!is_callable($operator)) {
            throw new Exception(Noah::init()->lang->get('router.invalid_router_interceptor', $subspace));
        }
        $this->_interceptors[$subspace] = $operator;
    }

    /**
     * 获取指定类的拦截器
     *
     * @param $namespace
     * @return mixed
     */
    function getInterceptors($namespace)
    {
        $namespace = trim($namespace, '\\');
        $result = array();
        foreach ($this->_interceptors as $subspace=> $operator) {
            if (strpos($namespace, $subspace) !== false) {
                $result[$subspace] = $operator;
            }
        }
        //按subspace长短来重新排序
        if ($result) {
            uksort($result, function ($a, $b) {
                $len_a = strlen($a);
                $len_b = strlen($b);
                if ($len_a == $len_b) {
                    return 0;
                }
                return $len_a > $len_b ? 1 : -1;
            });
        }
        return $result;
    }

    /**
     * 准备路由数据
     *
     * @throws Exception
     */
    function ready()
    {
        $uri = $_SERVER['REQUEST_URI'];
        //解析URI
        if (strpos($uri, '?') !== false) {
            $uri = substr($uri, 0, strpos($uri, '?'));
        }
        //重写
        $uri = trim($this->_rewrite($uri), '/');
        //处理URI,组装控制器类
        $urlsep = Noah::init()->config->router->urlsep;
        $url_suffix = Noah::init()->config->router->urlsuffix;
        if (strpos($uri, $url_suffix) !== false) {
            $uri = preg_replace(sprintf('~%s$~i', $url_suffix), '', $uri);
        }
        $app_name = Noah::init()->getAppName();
        $controller_dir = Noah::init()->getControllerDir();
        $app_dir = Noah::init()->getAppDir();
        $path_now = $controller_dir;
        if ($uri == '') {
            $controller = ucfirst(Noah::init()->config->router->default->controller);
        } else {
            $controllers = array_map('ucfirst', explode($urlsep, $uri));
            $controller = implode('\\', $controllers);
            $path_now.= DIRECTORY_SEPARATOR. implode(DIRECTORY_SEPARATOR, $controllers);
            $path_now = dirname($path_now);
        }
        $part = str_replace($app_dir, '', $controller_dir);
        $part = trim(str_replace(array('/', '\\'), '\\', $part), '\\');
        $part = array_map('ucfirst', explode('\\', $part));
        $part = implode('\\', $part);
        $namespace = $app_name. '\\'. $part. '\\'. $controller;
        $this->_namespace = $namespace;
        $this->_controller = '/'. $uri;
        $this->_action = Noah::init()->config->router->default->action;
        //定义PATH_NOW常量
        defined('PATH_NOW') || define('PATH_NOW', $path_now);
        Loader::setAlias('~', PATH_NOW);
        //请求数据初始化完成
        Request::$ready = true;
        Noah::init()->set('request', function() { return Request::getInstance(); });
        if (!Loader::findClass($namespace)) {
            throw new Exception(Noah::init()->lang->get('router.controller_not_found', $namespace));
        }
    }

    /**
     * 调度
     *
     * @throws Exception
     */
    function dispatch()
    {
        $namespace = $this->_namespace;
        $action = $this->_action;
        $ref = new ReflectionClass($namespace);
        if ($ref->isAbstract()) {
            throw new Exception(Noah::init()->lang->get('router.controller_is_protected', $namespace));
        }
        //实现拦截器功能
        if ($interceptors = $this->getInterceptors($namespace)) {
            foreach ($interceptors as $interceptor) {
                $result = call_user_func_array($interceptor, array());
                if (is_string($result)) {
                    echo $result;
                    exit;
                }
            }
        }
        //实例化最终控制器对象
        $instance = new $namespace();
        if (!method_exists($instance, $action)) {
            throw new Exception(Noah::init()->lang->get('router.action_not_found', $namespace, $action));
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
        echo $output;
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
                    throw new Exception(Noah::init()->lang->get('router.call_func_failed', $val[0]. '::'. $val[1]. '()'));
                }
            }
        }
        if (!is_string($uri)) {
            throw new Exception(Noah::init()->lang->get('router.uri_must_string'));
        }
        return $uri;
    }

}
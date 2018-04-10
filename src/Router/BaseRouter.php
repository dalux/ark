<?php

namespace Brisk\Router;

use Brisk\Assembly\Kernel;
use Brisk\Assembly\Language;
use Brisk\Assembly\Loader;
use Brisk\Assembly\Request;
use Brisk\Exception\KernelException;
use Brisk\Exception\RouterException;

class BaseRouter extends RouterFather
{

    /**
     * 当前路由命名空间
     *
     * @var string
     */
    private static $_current_namespace;

    /**
     * 路由转换规则
     *
     * @var array
     */
    private static $_rules = array();

    /**
     * 控制器中的自动执行方法
     *
     * @var string
     */
    private static $_auto_method = '__init';

    /**
     * 默认控制器
     *
     * @var string
     */
    private static $_default_controller = 'Index';

    /**
     * 默认行为
     *
     * @var string
     */
    private static $_default_action = 'index';

    /**
     * URL 后缀
     *
     * @var string
     */
    private static $_url_suffix = '.html';

    /**
     * 设置默认控制器名称
     *
     * @param string $controller
     */
    static function setDefaultController($controller)
    {
        self::$_default_controller = $controller;
    }

    /**
     * 设置默认行为名称
     *
     * @param string $action
     */
    static function setDefaultAction($action)
    {
        self::$_default_action = $action;
    }

    /**
     * 设置URL 后缀名称
     *
     * @param string $suffix
     */
    static function setUrlSuffix($suffix)
    {
        self::$_url_suffix = $suffix;
    }

    /**
     * 设置类自动方法
     *
     * @param $auto_method
     */
    static function setAutoMethod($auto_method)
    {
        self::$_auto_method = $auto_method;
    }

    /**
     * 添加路由规则
     *
     * @static
     * @param string $rule
     * @param string $redirect
     */
    static function addRule($rule, $redirect)
    {
        self::$_rules[$rule] = $redirect;
    }

    /**
     * 准备路由数据
     *
     * @throws RouterException
     * @throws KernelException
     */
    function ready()
    {
        $uri = $_SERVER['REQUEST_URI'];
        //解析URI
        if (strpos($uri, '?') !== false) {
            $uri = substr($uri, 0, strpos($uri, '?'));
        }
        //重写URI
        $uri = trim($this->_rewrite($uri), '/');
        //去除url后缀
        if (self::$_url_suffix
                && strpos($uri, self::$_url_suffix) !== false) {
            $uri = preg_replace(sprintf('~%s$~i', self::$_url_suffix), '', $uri);
        }
        $app_info = Kernel::getAppInfo();
        $path_now = $app_info['controller_path'];
        $controller = ucfirst(self::$_default_controller);
        if ($uri) {
            $controllers = array_map('ucfirst', explode('/', $uri));
            $dist = end($controllers);
            if (strpos($dist, '.') || strpos($dist, '_')) {
                $dist = str_replace(array('.', '_'), '.', $dist);
                $dist = array_map('ucfirst', explode('.', $dist));
                $dist = implode('', $dist);
                $controllers[count($controllers) - 1] = $dist;
            }
            $controller = implode('\\', $controllers);
            $path_now.= DIRECTORY_SEPARATOR. implode(DIRECTORY_SEPARATOR, $controllers);
            $path_now = dirname($path_now);
        }
        //拼凑当前控制器命名空间
        $ns_part = str_replace($app_info['app_path'], '', $app_info['controller_path']);
        $ns_part = trim(str_replace(array('/', '\\'), '\\', $ns_part), '\\');
        $ns_part = array_map('ucfirst', explode('\\', $ns_part));
        $ns_part = implode('\\', $ns_part);
        $namespace = $app_info['app_name']. '\\'. $ns_part. '\\'. $controller;
        //定义PATH_NOW常量
        defined('PATH_NOW') || define('PATH_NOW', $path_now);
        Loader::setAlias('~', PATH_NOW);
        //请求数据初始化完成
        Request::setReady(true);
        Kernel::setComponent('request', function() { return Request::getInstance(); });
        if (!Loader::findClass($namespace)) {
            throw new RouterException(Language::get('router.controller_not_found', $namespace));
        }
        self::$_current_namespace = $namespace;
    }

    /**
     * 调度
     *
     * @throws RouterException
     * @throws \ReflectionException
     */
    function dispatch()
    {
        $namespace = self::$_current_namespace;
        $action = self::$_default_action;
        $auto_method = self::$_auto_method;
        //是否被保护对象
        if (!class_exists($namespace)) {
            throw new RouterException(Language::get('router.class_not_found', $namespace));
        }
        $ref = new \ReflectionClass($namespace);
        if ($ref->isAbstract()) {
            throw new RouterException(Language::get('router.controller_is_protected', $namespace));
        }
        //实例化最终控制器对象
        $instance = new $namespace();
        if (!method_exists($instance, $action)) {
            throw new RouterException(Language::get('router.action_not_found', $action));
        }
        $output = null;
        //自动化类
        if (method_exists($instance, $auto_method)) {
            $output = $instance->{$auto_method}();
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
     * @throws RouterException
     */
    private function _rewrite($uri)
    {
        foreach (self::$_rules as $key=> $val) {
            $key = '~'. $key. '~i';
            if (preg_match($key, $uri)) {
                if (is_string($val)) {
                    $uri = preg_replace($key, $val, $uri);
                    break;
                } elseif (is_callable($val)) {
                    $uri = preg_replace_callback($key, $val, $uri);
                    break;
                } elseif (!is_callable($val) && is_array($val)) {
                    throw new RouterException(Language::get('router.call_func_failed', $val[0]. '::'. $val[1]. '()'));
                }
            }
        }
        if (!is_string($uri)) {
            throw new RouterException(Language::get('router.uri_must_string'));
        }
        return $uri;
    }

}
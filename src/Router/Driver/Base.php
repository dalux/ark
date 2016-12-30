<?php

namespace  Ark\Router\Driver;

use ReflectionClass;
use Ark\Core\Loader;
use Ark\Core\Captain;
use Ark\Core\Trace;
use Ark\Core\Struct;
use Ark\Http\Request;
use Ark\Core\Controller;
use Ark\Router\Exception;
use Ark\Router\Driver as RouterDriver;
use Ark\Event\Adapter as EventAdapter;

class Base extends RouterDriver
{

    /**
     * URL模式: 普通
     *
     */
    const URL_MODE_COMMON = 1;

    /**
     * URL模式: PATHINFO
     *
     */
    const URL_MODE_PATHINFO = 2;

    /**
     * URL模式: 重写
     *
     */
    const URL_MODE_REWRITE = 3;

    /**
     * URL模式: 兼容
     *
     */
    const URL_MODE_COMPATIBLE = 4;

    /**
     * 是否支持模块
     *
     * @var bool
     */
    private $_allow_module = false;

    /**
     * 路由转换规则
     *
     * @var array
     */
    private $_rules = array();

    /**
     * 当前URL模式
     *
     * @var int
     */
    private $_url_mode = 1;

    /**
     * 控制器
     *
     * @var string
     */
    private $_controller;

    /**
     * 行为
     *
     * @var string
     */
    private $_action;

    /**
     * 模块
     *
     * @var string
     */
    private $_module;

    /**
     * 构造器
     *
     */
    function __construct()
    {
        $url_mode = self::URL_MODE_COMMON;
        if ($mode = Captain::getInstance()->config->router->urlmode) {
            $url_mode = $mode;
        }
        $this->setUrlMode($url_mode);
        Trace::set('custom', array('name'=> 'url_mode', 'value'=> $url_mode));
    }

    /**
     * 检查是否支持模块化
     *
     * @return bool
     */
    function isAllowModule()
    {
        return $this->_allow_module;
    }

    /**
     * 设置是否支持模块
     *
     * @param bool $allow
     * @return $this
     */
    function setAllowModule($allow)
    {
        $this->_allow_module = (bool)$allow;
        return $this;
    }

    /**
     * 设置URL模式
     *
     * @param $mode
     * @return $this
     */
    function setUrlMode($mode)
    {
        $this->_url_mode = $mode;
        return $this;
    }

    /**
     * 获取当前URL模式
     *
     * @return int
     */
    function getUrlMode()
    {
        return $this->_url_mode;
    }

    /**
     * 获取当前URL模式名称
     *
     * @return mixed
     */
    function getUrlModeName()
    {
        $modes = array(
            self::URL_MODE_COMMON       => 'common',
            self::URL_MODE_PATHINFO     => 'pathinfo',
            self::URL_MODE_REWRITE      => 'rewrite',
            self::URL_MODE_COMPATIBLE   => 'compatible',
        );
        return $modes[$this->_url_mode];
    }

    /**
     * 设置控制器名
     *
     * @param $controller
     * @return $this
     */
    function setController($controller)
    {
        $this->_controller = $controller;
        return $this;
    }

    /**
     * 获取当前控制器名称
     *
     * @return string
     */
    function getController()
    {
        return $this->_controller;
    }

    /**
     * 设置行为名称
     *
     * @param $action
     * @return $this
     */
    function setAction($action)
    {
        $this->_action = $action;
        return $this;
    }

    /**
     * 获取当前行为名称
     *
     * @return string
     */
    function getAction()
    {
        return $this->_action;
    }

    /**
     * 设置模块名称
     *
     * @param $module
     * @return $this
     */
    function setModule($module)
    {
        $this->_module = $module;
        return $this;
    }

    /**
     * 获取当前模块名称
     *
     * @return string
     */
    function getModule()
    {
        return $this->_module;
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
     * 执行路由解析
     *
     * @param string $uri
     * @return mixed
     * @throws Exception
     */
    function doAction($uri)
    {
        //解析前事件
        $data = array('driver'=> 'Base', 'uri'=> $uri);
        $rule = array(
            'driver'=> array(Struct::FLAG_REQUIRED=> true, Struct::FLAG_TYPE=> Struct::TYPE_STRING),
            'uri'=> array(Struct::FLAG_REQUIRED=> true, Struct::FLAG_TYPE=> Struct::TYPE_STRING),
        );
        $data = EventAdapter::onListening('event.routing.before', $data, $rule);
        $uri = $data['uri'];
        //调用路由组件，解析URI
        $result = $this->parseUri($uri);
        //解析后事件
        $data = array('driver'=> 'Base', 'result'=> $result);
        $rule = array(
            'driver'=> array(Struct::FLAG_REQUIRED=> true, Struct::FLAG_TYPE=> Struct::TYPE_STRING),
            'result'=> array(Struct::FLAG_REQUIRED=> true, Struct::FLAG_TYPE=> Struct::TYPE_ARRAY),
        );
        $data = EventAdapter::onListening('event.routing.finish', $data, $rule);
        $result = $data['result'];
        $def_controller = Captain::getInstance()->config->router->default->controller;
        $def_action = Captain::getInstance()->config->router->default->action;
        //校验result结构
        $struct = new Struct();
        $struct->setRule(array(
            'module'=> array(Struct::FLAG_REQUIRED=> false, Struct::FLAG_TYPE=> Struct::TYPE_STRING),
            'controller'=> array(Struct::FLAG_REQUIRED=> true, Struct::FLAG_TYPE=> Struct::TYPE_STRING, Struct::FLAG_DEFAULT=> $def_controller),
            'action'=> array(Struct::FLAG_REQUIRED=> true, Struct::FLAG_TYPE=> Struct::TYPE_STRING, Struct::FLAG_DEFAULT=> $def_action),
        ));
        $struct->setData($result);
        if (!$result = $struct->checkOut()) {
            throw new Exception(sprintf(Captain::getInstance()->lang->get('router.uri_parse_failed'), $struct->getMessage()));
        }
        //控制器调度
        $this->setModule($result['module']);
        $this->setController($result['controller']);
        $this->setAction($result['action']);
        return $this->dispatch();
    }

    /**
     * 解析URI数据
     *
     * @param $uri
     * @return array
     * @throws Exception
     */
    function parseUri($uri)
    {
        $module = $controller = $action = '';
        $getdata = array();
        switch ($this->_url_mode) {
            case self::URL_MODE_COMMON:
                $var_module = Captain::getInstance()->config->router->urlvar->module;
                $var_controller = Captain::getInstance()->config->router->urlvar->controller;
                $var_action = Captain::getInstance()->config->router->urlvar->action;
                $_GET = Captain::getInstance()->request->get();
                $module = $_GET[$var_module];
                $controller = $_GET[$var_controller];
                $action = $_GET[$var_action];
                unset($_GET[$var_module], $_GET[$var_controller], $_GET[$var_action]);
                $getdata = $_GET;
                $_GET = array();
                if (!$this->isAllowModule()) {
                    $module = '';
                }
                break;
            case self::URL_MODE_PATHINFO:
                $file_name = basename($_SERVER['SCRIPT_FILENAME']);
                $uri = preg_replace('/\/'. addslashes($file_name). '/', '', $uri);
                //重写
                $urlsep = Captain::getInstance()->config->router->urlsep;
                $urlsuffix = Captain::getInstance()->config->router->urlsuffix;
                $uri = str_replace('/?', $urlsep, $uri);
                $uri = str_replace(array('&', '=', '?'), $urlsep, $uri);
                $uri = trim($this->_rewrite($uri), '/');
                $uri = preg_replace(sprintf('~%s$~i', $urlsuffix), '', $uri);
                $uri_params = explode($urlsep, $uri);
                if ($this->isAllowModule()) {
                    $module = array_shift($uri_params);
                }
                $controller = array_shift($uri_params);
                $action = array_shift($uri_params);
                $uri_params = array_chunk($uri_params, 2);
                foreach ($uri_params as $key=> $val) {
                    $getdata[$val[0]] = $val[1];
                }
                break;
            case self::URL_MODE_REWRITE:
                //重写
                $urlsep = Captain::getInstance()->config->router->urlsep;
                $urlsuffix = Captain::getInstance()->config->router->urlsuffix;
                $uri = str_replace('/?', $urlsep, $uri);
                $uri = str_replace(array('&', '=', '?'), $urlsep, $uri);
                $uri = trim($this->_rewrite($uri), '/');
                $uri = preg_replace(sprintf('~%s$~i', $urlsuffix), '', $uri);
                $uri_params = explode($urlsep, $uri);
                if ($this->isAllowModule()) {
                    $module = array_shift($uri_params);
                }
                $controller = array_shift($uri_params);
                $action = array_shift($uri_params);
                $uri_params = array_chunk($uri_params, 2);
                foreach ($uri_params as $key=> $val) {
                    $getdata[$val[0]] = $val[1];
                }
                break;
            case self::URL_MODE_COMPATIBLE:
                $_GET = Captain::getInstance()->request->get();
                $urlvar = Captain::getInstance()->config->router->urlvar->compatible;
                $uri = $_GET[$urlvar];
                unset($_GET[$urlvar]);
                //重写
                $urlsep = Captain::getInstance()->config->router->urlsep;
                $urlsuffix = Captain::getInstance()->config->router->urlsuffix;
                $uri = str_replace('/?', $urlsep, $uri);
                $uri = str_replace(array('&', '=', '?'), $urlsep, $uri);
                $uri = trim($this->_rewrite($uri), '/');
                $uri = preg_replace(sprintf('~%s$~i', $urlsuffix), '', $uri);
                $uri_params = explode($urlsep, $uri);
                foreach ($_GET as $k=> $v) {
                    $uri_params[$k] = $v;
                }
                if ($this->isAllowModule()) {
                    $module = array_shift($uri_params);
                }
                $controller = array_shift($uri_params);
                $action = array_shift($uri_params);
                $uri_params = array_chunk($uri_params, 2);
                foreach ($uri_params as $key=> $val) {
                    $getdata[$val[0]] = $val[1];
                }
                $_GET = array();
                break;
        }
        if ($getdata) {
            foreach ($getdata as $key=> $val) {
                Captain::getInstance()->request->add($key, $val, Request::FLAG_GET);
            }
        }
        return array(
            'module'        => $module,
            'controller'    => $controller,
            'action'        => $action,
        );
    }

    /**
     * 目标调度
     *
     * @return mixed
     * @throws Exception
     */
    function dispatch()
    {
        if (!$this->_controller) {
            throw new Exception(Captain::getInstance()->lang->get('router.invalid_controller_name'));
        } elseif (!$this->_action) {
            throw new Exception(Captain::getInstance()->lang->get('router.invalid_action_name'));
        }
        $app_name = Captain::getInstance()->getAppName();
        $controller_dir = Captain::getInstance()->getControllerDir();
        $app_dir = Captain::getInstance()->getAppDir();
        $path_now = $controller_dir;
        $part = str_replace($app_dir, '', $controller_dir);
        $part = trim(str_replace(array('/', '\\'), '\\', $part), '\\');
        $part = array_map('ucfirst', explode('\\', $part));
        $part = implode('\\', $part);
        $namespace = $app_name. '\\'. $part;
        if ($this->_module) {
            $namespace.= '\\'. ucfirst($this->_module);
            $path_now.= DIRECTORY_SEPARATOR. $this->_module;
        }
        $namespace.= '\\'. ucfirst($this->_controller);
        if (!class_exists($namespace)) {
            throw new Exception(sprintf(Captain::getInstance()->lang->get('router.controller_not_found'), $namespace));
        }
        //定义PATH_NOW常量
        defined('PATH_NOW') || define('PATH_NOW', $path_now);
        Loader::setAlias('~', PATH_NOW);
        //
        $ref = new ReflectionClass($namespace);
        if ($ref->isAbstract()) {
            throw new Exception(sprintf(Captain::getInstance()->lang->get('router.controller_is_protected'), $namespace));
        }
        $instance = new $namespace();
        if (!$instance instanceof Controller) {
            throw new Exception(sprintf(Captain::getInstance()->lang->get('router.controller_extends_error'), '\\Ark\\Controller\\Base'));
        } elseif (!method_exists($instance, $this->_action)) {
            throw new Exception(sprintf(Captain::getInstance()->lang->get('router.action_not_found'), $namespace, $this->_action));
        }
        $output = null;
        //自动化类
        if (method_exists($instance, '__init')) {
            $output = $instance->__init();
        }
        //目标控制器行为
        if (is_null($output)) {
            $output = $instance->{$this->_action}();
        }
        return $output;
    }

    /**
     * 是否是指定模式的URL格式
     *
     * @param $uri
     * @param $url_mode
     * @return bool
     */
    function isMatch($uri, $url_mode)
    {
        switch ($url_mode) {
            case self::URL_MODE_COMMON:
                return preg_match('#^/([\w\d\_]+(\.php)?)?(\?(&?\S+=\S+)*)?$#', $uri);
            case self::URL_MODE_PATHINFO:
                return preg_match('/^\/([\w\d\_]+\.php(\/([^\/\&\=]+\/?)*)?)?$/', $uri);
            case self::URL_MODE_REWRITE:
                return preg_match('/^\/(([^\/\&\=\.]+\/?)*)?$/', $uri);
            case self::URL_MODE_COMPATIBLE:
                return preg_match('/^\/([\w\d]+\.php)?\?[\w\d]+\=\/([^\/\&\=]+\/?)*$/', $uri);
        }
        return false;
    }

    /**
     * 格式化URL到指定模式
     *
     * @param array $controller
     * @param null $action
     * @param array $params
     * @param null $module
     * @param null $url_mode
     * @return string
     */
    function makeQuery($controller, $action, array $params, $module = null, $url_mode = null)
    {
        $url_mode || $url_mode = $this->_url_mode;
        $urlvar = Captain::getInstance()->config->router->urlvar;
        switch ($url_mode) {
            case self::URL_MODE_COMMON:
                is_null($module) || $params[$urlvar->module] = $module;
                $params[$urlvar->controller] = $controller;
                $params[$urlvar->action] = $action;
                return '?'. http_build_query($params);
            case self::URL_MODE_PATHINFO:
            case self::URL_MODE_REWRITE:
                $url = '/';
                is_null($module) || $url.= $module. '/';
                $url.= $controller. '/'. $action. '/';
                foreach ($params as $k=> $v) {
                    $url.= $k. '/'. urlencode($v). '/';
                }
                return $url;
            case self::URL_MODE_COMPATIBLE:
                $url = '/';
                is_null($module) || $url.= $module. '/';
                $url.= $controller. '/'. $action. '/';
                foreach ($params as $k=> $v) {
                    $url.= $k. '/'. urlencode($v). '/';
                }
                return '?'. $urlvar->compatible. '='. $url;
        }
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
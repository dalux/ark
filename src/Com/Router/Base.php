<?php

namespace  Ark\Com\Router;

use Ark\Core\Noah;
use Ark\Toolbox\Struct;
use Ark\Contract\RouterDriver;
use Ark\Com\Event\Adapter as EventAdapter;

class Base implements RouterDriver
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
    private $_router = array();

    /**
     * 当前URL模式
     *
     * @var int
     */
    private $_url_mode = 1;

    /**
     * 构造器
     *
     */
    function __construct()
    {
        if ($url_mode = Noah::getInstance()->config->router->urlmode) {
            $this->setUrlMode($url_mode);
        }
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
     * 添加路径规则
     *
     * @param $rule
     * @param $redirect
     * @return $this
     */
    function addRouter($rule, $redirect)
    {
        $this->_router[$rule] = $redirect;
        return $this;
    }

    /**
     * 解析URI数据
     *
     * @param $uri
     * @return array
     * @throws RuntimeException
     */
    function parseUri($uri)
    {
        //解析前事件
        $data = array('driver'=> 'Base', 'uri'=> $uri);
        $rule = array(
            'driver'=> array(Struct::FLAG_REQUIRED=> true, Struct::FLAG_TYPE=> Struct::TYPE_STRING),
            'uri'=> array(Struct::FLAG_REQUIRED=> true, Struct::FLAG_TYPE=> Struct::TYPE_STRING),
        );
        $data = EventAdapter::onListening('event.router.before', $data, $rule);
        $uri = $data['uri'];
        $module = $controller = $action = '';
        $getdata = array();
        switch ($this->_url_mode) {
            case self::URL_MODE_COMMON:
                $var_module = Noah::getInstance()->config->router->urlvar->module;
                $var_controller = Noah::getInstance()->config->router->urlvar->controller;
                $var_action = Noah::getInstance()->config->router->urlvar->action;
                $_GET = Noah::getInstance()->request->get();
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
                $urlsep = Noah::getInstance()->config->router->urlsep;
                $urlsuffix = Noah::getInstance()->config->router->urlsuffix;
                $uri = str_replace('/?', $urlsep, $uri);
                $uri = str_replace(array('&', '=', '?'), $urlsep, $uri);
                $uri = trim($this->_rewrite($uri), '/');
                $uri = preg_replace(sprintf('/%s$/', addslashes($urlsuffix)), '', $uri);
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
                $urlsep = Noah::getInstance()->config->router->urlsep;
                $urlsuffix = Noah::getInstance()->config->router->urlsuffix;
                $uri = str_replace('/?', $urlsep, $uri);
                $uri = str_replace(array('&', '=', '?'), $urlsep, $uri);
                $uri = trim($this->_rewrite($uri), '/');
                $uri = preg_replace(sprintf('/%s$/', addslashes($urlsuffix)), '', $uri);
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
                $_GET = Noah::getInstance()->request->get();
                $urlvar = Noah::getInstance()->config->router->urlvar->compatible;
                $uri = $_GET[$urlvar];
                unset($_GET[$urlvar]);
                //重写
                $urlsep = Noah::getInstance()->config->router->urlsep;
                $urlsuffix = Noah::getInstance()->config->router->urlsuffix;
                $uri = str_replace('/?', $urlsep, $uri);
                $uri = str_replace(array('&', '=', '?'), $urlsep, $uri);
                $uri = trim($this->_rewrite($uri), '/');
                $uri = preg_replace(sprintf('/%s$/', addslashes($urlsuffix)), '', $uri);
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
        $result = array(
            'module'        => $module,
            'controller'    => $controller,
            'action'        => $action,
            'getdata'       => $getdata,
        );
        //解析后事件
        $data = array('driver'=> 'Base', 'result'=> $result);
        $rule = array(
            'driver'=> array(Struct::FLAG_REQUIRED=> true, Struct::FLAG_TYPE=> Struct::TYPE_STRING),
            'result'=> array(Struct::FLAG_REQUIRED=> true, Struct::FLAG_TYPE=> Struct::TYPE_ARRAY),
        );
        $data = EventAdapter::onListening('event.router.after', $data, $rule);
        return $data['result'];
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
        $urlvar = Noah::getInstance()->config->router->urlvar;
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
     * @throws RuntimeException
     */
    private function _rewrite($uri)
    {
        foreach ($this->_router as $key=> $val) {
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
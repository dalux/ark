<?php

class Ark_Router_Base extends Ark_Router_Father
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
     * 是否支持模块
     *
     * @var bool
     */
    private $_allow_module = false;

    /**
     * 路由是否准备就绪
     *
     * @var bool
     */
    private $_ready = false;

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
     * 控制器命名空间
     *
     * @var string
     */
    private $_namespace;

    /**
     * 拦截器
     *
     * @var array
     */
    private $_interceptors = array();

    /**
     * 构造器
     *
     */
    function __construct()
    {
        $url_mode = self::URL_MODE_COMMON;
        if ($mode = Ark_Core::getInstance()->config->router->urlmode) {
            $url_mode = $mode;
        }
        $this->setUrlMode($url_mode);
        Ark_Trace::set('custom', array('name'=> 'url_mode', 'value'=> $url_mode));
    }

    /**
     * 路由是否就绪
     *
     * @return bool|mixed
     */
    function isReady()
    {
        return $this->_ready;
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
        );
        return $modes[$this->_url_mode];
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
     * 获取当前控制器名称
     *
     * @return string
     */
    function getController()
    {
        return $this->_controller;
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
    function addInterceptor($subspace, callable $operator)
    {
        $subspace = trim($subspace, '\\');
        if (!is_callable($operator)) {
            throw new Ark_Router_Exception(Ark_Core::getInstance()->lang->get('router.invalid_router_interceptor', $subspace));
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
     * @throws Ark_Router_Exception
     */
    function ready()
    {
        $uri = $_SERVER['REQUEST_URI'];
        //调用路由组件，解析URI
        $result = $this->_parseUri($uri);
        $def_router = Ark_Core::getInstance()->config->router->default;
        $result['controller'] || $result['controller'] = $def_router->controller;
        $result['action'] || $result['action'] = $def_router->action;
        $this->_module = $result['module'];
        $this->_controller = $result['controller'];
        $this->_action = $result['action'];
        if (!$this->_controller) {
            throw new Exception(Ark_Core::getInstance()->lang->get('router.invalid_controller_name'));
        } elseif (!$this->_action) {
            throw new Exception(Ark_Core::getInstance()->lang->get('router.invalid_action_name'));
        }
        $app_name = Ark_Core::getInstance()->getAppName();
        $controller_dir = Ark_Core::getInstance()->getControllerPath();
        $app_dir = Ark_Core::getInstance()->getAppPath();
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
        $this->_namespace = $namespace;
        //定义PATH_NOW常量
        defined('PATH_NOW') || define('PATH_NOW', $path_now);
        Ark_Loader::setAlias('~', PATH_NOW);
        //请求数据初始化完成
        Ark_Request::setReady(true);
        Ark_Core::getInstance()->setMember('request', function() { return Ark_Request::getInstance(); });
        if (!Ark_Loader::findClass($namespace)) {
            throw new Exception(Ark_Core::getInstance()->lang->get('router.controller_not_found', $namespace));
        }
        $this->_ready = true;
    }

    /**
     * 目标调度
     *
     * @return mixed
     * @throws Exception
     */
    function dispatch()
    {
        $namespace = $this->_namespace;
        $ref = new ReflectionClass($namespace);
        if ($ref->isAbstract()) {
            throw new Ark_Router_Exception(Ark_Core::getInstance()->lang->get('router.controller_is_protected', $namespace));
        }
        //实现拦截器功能
        if ($interceptors = $this->getInterceptors($namespace)) {
            foreach ($interceptors as $interceptor) {
                $result = call_user_func_array($interceptor, array());
                if (is_string($result)) {
                    return $result;
                }
            }
        }
        $instance = new $namespace();
        if (!method_exists($instance, $this->_action)) {
            throw new Ark_Router_Exception(Ark_Core::getInstance()->lang->get('router.action_not_found', $namespace, $this->_action));
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
        echo $output;
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
        $urlvar = Ark_Core::getInstance()->config->router->urlvar;
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
                    throw new Exception(Ark_Core::getInstance()->lang->get('router.call_func_failed', $val[0]. '::'. $val[1]. '()'));
                }
            }
        }
        if (!is_string($uri)) {
            throw new Ark_Router_Exception(Ark_Core::getInstance()->lang->get('router.uri_must_string'));
        }
        return $uri;
    }

    /**
     * 解析URI数据
     *
     * @param $uri
     * @return array
     * @throws Exception
     */
    private function _parseUri($uri)
    {
        $module = $controller = $action = '';
        $getdata = array();
        switch ($this->_url_mode) {
            case self::URL_MODE_COMMON:
                $var_module = Ark_Core::getInstance()->config->router->urlvar->module;
                $var_controller = Ark_Core::getInstance()->config->router->urlvar->controller;
                $var_action = Ark_Core::getInstance()->config->router->urlvar->action;
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
                $urlsep = Ark_Core::getInstance()->config->router->urlsep;
                $urlsuffix = Ark_Core::getInstance()->config->router->urlsuffix;
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
                $urlsep = Ark_Core::getInstance()->config->router->urlsep;
                $urlsuffix = Ark_Core::getInstance()->config->router->urlsuffix;
                if (strpos($uri, '?') !== false) {
                    $getdata = $_GET;
                    $_GET = array();
                    $uri = substr($uri, 0, strpos($uri, '?'));
                    $uri = trim($this->_rewrite($uri), '/');
                    $uri = preg_replace(sprintf('~%s$~i', $urlsuffix), '', $uri);
                    $uri_params = explode($urlsep, $uri);
                    if ($this->isAllowModule()) {
                        $module = array_shift($uri_params);
                    }
                    $controller = array_shift($uri_params);
                    $action = array_shift($uri_params);
                } else {
                    $uri = str_replace(array('&', '='), $urlsep, $uri);
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
                }
                break;
        }
        if ($getdata) {
            foreach ($getdata as $key=> $val) {
                $_GET[$key] = $val;
            }
        }
        return array(
            'module'        => $module,
            'controller'    => $controller,
            'action'        => $action,
        );
    }

}
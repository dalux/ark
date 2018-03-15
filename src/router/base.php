<?php

class Ark_Router_Base extends Ark_Router_Father
{

    /**
     * 控制器名称
     *
     * @var string
     */
    protected $_controller;

    /**
     * 路由是否就绪
     *
     * @var bool
     */
    protected $_ready = false;

    /**
     * 路由转换规则
     *
     * @var array
     */
    private $_rules = array();

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
     * 路由是否就绪
     *
     * @return bool
     */
    function isReady()
    {
        return $this->_ready;
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
        $uri = preg_replace('~\.(.*?)$~i', '', $uri);
        if ($uri == '') {
            $controller = Ark_Core::getInst()->config->router->controller->default;
        } else {
            $controllers = array_map('strtolower', explode('/', $uri));
            $controller = implode(DIRECTORY_SEPARATOR, $controllers);
        }
        $path_now = Ark_Core::getAppInfo('controller_path'). DIRECTORY_SEPARATOR. rtrim($controller, '.php'). '.php';
        $this->_controller = $path_now;
        //定义PATH_NOW常量
        defined('PATH_NOW') || define('PATH_NOW', dirname($path_now));
        Ark_Loader::setAlias('~', PATH_NOW);
        //请求数据初始化完成
        Ark_Request::setReady(true);
        Ark_Core::getInst()->setMember('request', function() { return Ark_Request::getInstance(); });
        $this->_ready = true;
    }

    /**
     * 调度
     *
     * @throws Exception
     */
    function dispatch()
    {
        global $ark;
        if (!is_file($this->_controller)) {
            throw new Ark_Router_Exception(Ark_Language::get('router.controller_not_found', Ark_Loader::reducePath($this->_controller)));
        }
        parent::dispatch();
        $output = include_once($this->_controller);
        if (is_string($output)) {
            echo $output;
        }
    }

    /**
     * 重写URL规则
     *
     * @param $uri
     * @return mixed
     * @throws Ark_Router_Exception
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
                    throw new Ark_Router_Exception(Ark_Language::get('router.call_func_failed', $val[0]. '::'. $val[1]. '()'));
                }
            }
        }
        if (!is_string($uri)) {
            throw new Ark_Router_Exception(Ark_Language::get('router.uri_must_string'));
        }
        return $uri;
    }

}
<?php

namespace Brisk\Router;

use Brisk\Core\Captain;
use Brisk\Core\Request;

class NativeRouter extends RouterFather
{

    /**
     * 控制器名称
     *
     * @var string
     */
    protected $_controller;

    /**
     * 路由状态
     *
     * @var bool
     */
    protected $_ready = false;

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
     * 路由是否就绪
     *
     * @return mixed
     */
    function isReady()
    {
        return $this->_ready;
    }

    /**
     * 准备请求数据
     *
     * @return null
     */
	function ready()
	{
        //定义常量
        $debug_trace = debug_backtrace();
        $caller = current(end($debug_trace));
        define('PATH_NOW', dirname($caller));
        $this->_controller = $caller;
        //请求数据初始化完成
        Request::setReady(true);
        Captain::set('request', function() { return Request::getInstance(); });
        $this->_ready = true;
	}

}
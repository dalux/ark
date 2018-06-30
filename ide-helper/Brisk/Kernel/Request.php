<?php

namespace Brisk\Kernel;

use Brisk\Kernel\Request\Item;

class Request
{

    /**
     * @var Item
     */
    public $get;

    /**
     * @var Item
     */
    public $post;

    /**
     * @var Item
     */
    public $request;

    /**
     * @var Item
     */
    public $files;

    /**
     * @var Item
     */
    public $cookie;

    /**
     * 标记请求是否就绪
     *
     * @param bool $state
     * @return null
     */
    public static function setReady($state) {}

    /**
     * 获取请求组件实例
     *
     * @return Request
     */
    public static function getInstance() {}

    /**
     * 当前请求是否post
     *
     * @return bool
     */
    public static function isPost() {}

    /**
     * 当前请求是否ajax
     *
     * @return bool
     */
    public static function isAjax() {}

    /**
     * 获取客户端IP地址
     *
     * @param bool $convert
     * @return string
     */
    public static function getIpAddress($convert = false) {}


}

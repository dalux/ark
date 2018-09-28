<?php

namespace Brisk\Kernel;

class Request
{

    /**
     * Request type
     *
     * @var Request\Request
     */
    public $request;

    /**
     * Get type
     *
     * @var Request\Get
     */
    public $get;

    /**
     * Post type
     *
     * @var Request\Post
     */
    public $post;

    /**
     * Files type
     *
     * @var Request\Files
     */
    public $files;

    /**
     * Cookie type
     *
     * @var Request\Cookie
     */
    public $cookie;

    /**
     * Get the Request component instance
     *
     * @return Request
     */
    public static function getInstance() {}

    /**
     * Check if request is post
     *
     * @return bool
     */
    public static function isPost() {}

    /**
     * Check if request is ajax
     *
     * @return bool
     */
    public static function isAjax() {}

    /**
     * Get client IP Address
     *
     * @param bool $convert
     * @return string
     */
    public static function getIpAddress($convert = false) {}

    /**
     * @param string $flag
     */
    public function __get($flag) {}

}

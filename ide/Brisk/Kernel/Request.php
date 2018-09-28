<?php

namespace Brisk\Kernel;


class Request
{

    static private $_instance;


    static private $_ready = false;


    static private $_data = array();


    private $_request = array();


    private $_get = array();


    private $_post = array();


    private $_files = array();


    private $_cookie = array();


    private $_flag;

    /**
     * Request type
     *
     * @var Request
     */
    public $request;

    /**
     * Get type
     *
     * @var Request
     */
    public $get;

    /**
     * Post type
     *
     * @var Request
     */
    public $post;

    /**
     * Files type
     *
     * @var Request
     */
    public $files;

    /**
     * Cookie type
     *
     * @var Request
     */
    public $cookie;


    /**
     * Set Request data
     *
     * @param array $data
     * @return null
     */
    public static function setData(array $data) {}

    /**
     * Set the request readiness State
     *
     * @param bool $state
     * @return null
     */
    public static function setReady($state) {}

    /**
     * Get the Request component instance
     *
     * @return Request
     */
    public static function getInstance() {}

    /**
     * construct
     *
     * @return null
     */
    private function __construct() {}

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
     * Add request data
     *
     * @param string $name
     * @param mixed $value
     * @return Request
     */
    public function add($name, $value) {}

    /**
     * Del request item
     *
     * @param string $name
     * @return Request
     */
    public function del($name) {}

    /**
     * Gets the specified request data
     *
     * @param string $name
     * @param string $alternative
     * @return mixed
     */
    public function data($name = '', $alternative = '') {}

    /**
     * @param string $flag
     */
    public function __get($flag) {}

}

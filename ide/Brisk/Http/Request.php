<?php

namespace Brisk\Http;


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
     * Get the request data for the GET method
     *
     * @param string $name
     * @param string $alternative
     * @return mixed
     */
    public function get($name = '', $alternative = '') {}

    /**
     * Add get data
     *
     * @param string $name
     * @param mixed $value
     * @return null
     */
    public function addGetData($name, $value) {}

    /**
     * Del get item
     *
     * @param string $name
     * @return null
     */
    public function delGetData($name) {}

    /**
     * Get the request data for the POST method
     *
     * @param string $name
     * @param string $alternative
     * @return mixed
     */
    public function post($name = '', $alternative = '') {}

    /**
     * Add POST data
     *
     * @param string $name
     * @param mixed $value
     * @return null
     */
    public function addPostData($name, $value) {}

    /**
     * Del POST data
     *
     * @param string $name
     * @return null
     */
    public function delPostData($name) {}

    /**
     * Get the request data for the COOKIE method
     *
     * @param string $name
     * @param string $alternative
     * @return mixed
     */
    public function cookie($name = '', $alternative = '') {}

    /**
     * Get the request data for the FILES method
     *
     * @param string $name
     * @param string $alternative
     * @return mixed
     */
    public function files($name = '', $alternative = '') {}

    /**
     * Get the request data
     *
     * @param string $name
     * @param string $alternative
     * @return mixed
     */
    public function data($name = '', $alternative = '') {}

}

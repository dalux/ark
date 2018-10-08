<?php

namespace Brisk\Router\Driver;


class Classic extends \Brisk\Router\RouterFather
{

    static private $_module_support = false;


    static private $_rules = array();


    static private $_auto_method = '__init';


    static private $_default_module = 'Index';


    static private $_default_controller = 'Index';


    static private $_default_action = 'index';


    static private $_url_suffix = '.html';


    static private $_interceptors = array();


    private $_module;


    private $_controller;


    private $_action;


    private $_namespace;


    /**
     * Turn on routing module support
     *
     * @param string $default_module
     * @return null
     */
    public static function openModuleSupport($default_module = '') {}

    /**
     * Adding routing rewriting rules
     *
     * @param string $rule
     * @param mixed $redirect
     * @return null
     */
    public static function addRule($rule, $redirect) {}

    /**
     * Add routing interceptors
     *
     * @param string $ns_space
     * @param callable $operator
     * @return null
     */
    public static function addInterceptor($ns_space, $operator) {}

    /**
     * Get routing interceptors
     *
     * @param string $ns_space
     * @return null
     */
    public static function getInterceptors($ns_space) {}

    /**
     * Routing ready
     *
     * @return null
     */
    public function ready() {}

    /**
     * Routing path distribution
     *
     * @return null
     */
    public function dispatch() {}

    /**
     * @param string $a
     * @param string $b
     */
    public function todoUKSort($a, $b) {}

    /**
     * @param string $uri
     */
    private function _parseUri($uri) {}

    /**
     * @param string $uri
     */
    private function _rewrite($uri) {}

}

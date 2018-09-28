<?php

namespace Brisk\Kernel;

class App
{

    const NAME = 'Brisk';
    const AUTHOR = 'guodalu <112183883@qq.com>';
    const VERSION = '1.0.0';

    /**
     * Session
     * 
     * @var \Brisk\Kernel\Session
     */
    public $session;

    /**
     * Config
     * 
     * @var \Brisk\Kernel\Container
     */
    public $config;
    
    /**
     * Set get configuration item method
     *
     * @param callable $config
     * @return App
     */
    public function setConfig($config) {}


    private function __construct() {}

    /**
     * Get current object instance
     *
     * @return App
     */
    public static function getInstance() {}

    /**
     * Set directory path aliases
     *
     * @param string $alias
     * @param string $path
     * @return App
     */
    public function setAlias($alias, $path) {}

    /**
     * Set namespace path
     *
     * @param string $nspace
     * @param string $path
     * @return App
     */
    public function setNameSpace($nspace, $path) {}

    /**
     * Set the system language pack file
     *
     * @param string $language
     * @param string $path
     * @return App
     */
    public function addLanguageFile($language, $path) {}

    /**
     * Setting the system language
     *
     * @param string $language
     * @return App
     */
    public function setLanguage($language) {}

    /**
     * Adding event listener
     *
     * @param string $event
     * @param callable $listener
     * @return App
     */
    public function addEvent($event, $listener) {}

    /**
     * Start the application
     *
     * @return null
     */
    public function start() {}

    /**
     * Set up custom singleton components
     *
     * @param string $name
     * @param callable $value
     * @return App
     */
    public function setComponent($name, $value) {}

    /**
     * get custom singleton components
     *
     * @param string $name
     * @return mixed
     */
    public function getComponent($name) {}

    /**
     * Get custom singleton components
     *
     * @param string $name
     * @return mixed
     */
    public function __get($name) {}

    /**
     * Set up custom method
     *
     * @param string $name
     * @param callable $method
     * @return App
     */
    public function setMethod($name, $method) {}

    /**
     * Get custom method
     *
     * @param string $name
     * @param array $args
     * @return mixed
     */
    public function callMethod($name, array $args) {}

    /**
     * Get custom method
     *
     * @param string $name
     * @param array $args
     * @return mixed
     */
    public function __call($name, array $args) {}

    /**
     * destruct
     *
     * @return null
     */
    public function __destruct() {}

}

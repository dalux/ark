<?php

namespace Brisk\Cache\Driver;


class Memcached extends \Brisk\Cache\CacheFather
{

    private $_container;


    /**
     * Construct
     *
     * @param string $path
     * @param array $setting
     * @return null
     */
    public function __construct($path, array $setting = array()) {}

    /**
     * Set Cache data
     *
     * @param string $name
     * @param mixed $value
     * @param int $expire
     * @return bool
     */
    public function set($name, $value, $expire = 0) {}

    /**
     * Get Cache data
     *
     * @param string $name
     * @return mixed
     */
    public function get($name) {}

    /**
     * Delete Cache data
     *
     * @param string $name
     * @return bool
     */
    public function delete($name) {}

    /**
     * @param string $name
     * @param mixed $value
     */
    public function __set($name, $value) {}

    /**
     * @param string $name
     */
    public function __get($name) {}

    /**
     * Get cache data save location
     *
     * @param string $name
     * @return string
     */
    public function getCachePath($name) {}

    /**
     * Return memcached instance
     *
     * @return \Memcached
     */
    public function getInstance() {}

    /**
     * @param string $name
     */
    private function _formatPath($name) {}

}

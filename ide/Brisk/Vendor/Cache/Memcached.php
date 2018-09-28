<?php

namespace Brisk\Vendor\Cache;


class Memcached extends \Brisk\Vendor\Cache\CacheFather
{

    private $_container;


    /**
     * Construct
     *
     * @param string $save_path
     * @param array $option
     * @return null
     */
    public function __construct($save_path, array $option = array()) {}

    /**
     * Set Cache data
     *
     * @param string $name
     * @param mixed $value
     * @param int $expire
     * @return bool
     */
    public function set($name, $value, $expire = 86400) {}

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

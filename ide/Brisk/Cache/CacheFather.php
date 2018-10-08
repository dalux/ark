<?php

namespace Brisk\Cache;


abstract class CacheFather
{

    protected $_flag;


    protected $_format;


    protected $_caching = true;


    protected $_expire_time = 86400;


    /**
     * @param array $setting
     */
    public function __construct(array $setting = array()) {}

    /**
     * Set cache flag
     *
     * @param string $flag
     * @return CacheFather
     */
    public function setFlag($flag) {}

    /**
     * Setting path formatting method
     *
     * @param callable $format
     * @return CacheFather
     */
    public function setFormat($format) {}

    /**
     * Setting whether data is cached
     *
     * @param bool $caching
     * @return CacheFather
     */
    public function setCaching($caching = true) {}

    /**
     * Set cache expire time
     *
     * @param int $expire_time
     * @return CacheFather
     */
    public function setExpireTime($expire_time = 86400) {}

    /**
     * Set Cache data
     *
     * @param string $name
     * @param mixed $value
     * @param int $expire
     * @return bool
     */
    public abstract function set($name, $value, $expire = null);

    /**
     * Get Cache data
     *
     * @param string $name
     * @return mixed
     */
    public abstract function get($name);

    /**
     * Delete Cache data
     *
     * @param string $name
     * @return bool
     */
    public abstract function delete($name);

    /**
     * Get cache data save location
     *
     * @param string $name
     * @return string
     */
    public abstract function getCachePath($name);

}

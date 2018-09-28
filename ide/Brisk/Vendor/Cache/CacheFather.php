<?php

namespace Brisk\Vendor\Cache;


abstract class CacheFather
{

    protected $_flag;


    protected $_format;


    protected $_caching = true;


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
     * Set Cache data
     *
     * @param string $name
     * @param mixed $value
     * @param int $expire
     * @return bool
     */
    public abstract function set($name, $value, $expire = 86400);

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

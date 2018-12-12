<?php

namespace Brisk\Cache;

abstract class CacheFather
{

    /**
     * @var string
     */
    protected $_ext_name;

    /**
     * @var string
     */
    protected $_flag;

    /**
     * @var callable
     */
    protected $_format;

    /**
     * @var bool
     */
    protected $_caching = true;

    /**
     * @var int
     */
    protected $_expire_time = 86400;

    /**
     * CacheFather constructor.
     *
     * @param array $setting
     */
    public function __construct(array $setting = [])
    {
        foreach ($setting as $key=> $val) {
            switch ($key) {
                case 'ext_name':
                    $this->_ext_name = $val;
                    break;
                case 'flag':
                    $this->_flag = $val;
                    break;
                case 'expire_time':
                    $this->_expire_time = $val;
                    break;
                case 'format':
                    $this->_format = $val;
                    break;
            }
        }
    }

    /**
     * Set cache flag
     *
     * @param string flag
     * @return CacheFather
     */
    public function setFlag($flag)
    {
        $this->_flag = $flag;
        return $this;
    }

    /**
     * Setting path formatting method
     *
     * @param callable format
     * @return CacheFather
     */
    public function setFormat(callable $format)
    {
        $this->_format = $format;
        return $this;
    }

    /**
     * Setting whether data is cached
     *
     * @param bool caching
     * @return CacheFather
     */
    public function setCaching($caching = true)
    {
        $this->_caching = $caching;
        return $this;
    }

    /**
     * Set cache expire time
     *
     * @param int expire_time
     * @return CacheFather
     */
    public function setExpireTime($expire_time = 86400)
    {
        $this->_expire_time = $expire_time;
        return $this;
    }

    /**
     * Set Cache data
     *
     * @param string name
     * @param mixed value
     * @param int expire
     * @return bool
     */
    public abstract function set($name, $value, $expire = 0);

    /**
     * Get Cache data
     *
     * @param string name
     * @return mixed
     */
    public abstract function get($name);

    /**
     * Delete Cache data
     *
     * @param string name
     * @return bool
     */
    public abstract function delete($name);

    /**
     * Get cache data save location
     *
     * @param string name
     * @return string
     */
    public abstract function getCachePath($name);

}

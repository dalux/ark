<?php

namespace Brisk\Cache\Driver;

use Brisk\Kernel\Language;
use Brisk\Cache\CacheFather;
use Brisk\Exception\RuntimeException;

class Redis extends CacheFather
{

    /**
     * @var \Redis
     */
    private $_container;

    /**
     * 构造器
     *
     * @param string save_path
     * @param array setting
     * @return null
     */
    public function __construct($save_path, array $setting = [])
    {
        if (!extension_loaded('redis')) {
            throw new RuntimeException(Language::get('cache.extension_load_failed', 'php_redis'));
        }
        try {
            $server = explode(':', $save_path);
            $host = $server[0];
            $port = $server[1];
            $timeout = 5;
            if (isset($setting['connect_timeout'])) {
                $timeout = $setting['connect_timeout'];
            }
            $this->_container = new \Redis();
            $this->_container->connect($host, $port, $timeout);
            if (isset($setting['password'])) {
                $this->_container->auth($setting['password']);
            }
            parent::__construct($setting);
        } catch (\Exception $e) {
            throw new RuntimeException(Language::get('cache.cacher_create_failed', 'Redis'));
        }
    }
 
    /**
     * 缓存器设值
     *
     * @param string name
     * @param mixed value
     * @param null expire
     * @return bool
     */
    public function set($name, $value, $expire = 0)
    {
        $path = $this->getCachePath($name);
        if ($expire <= 0) {
            $expire_time = $this->_expire_time;
        } else {
            $expire_time = $expire;
        }
        return $this->_container->set($path, serialize($value), $expire_time);
    }
 
    /**
     * 缓存器取值
     *
     * @param string name
     * @return bool
     */
    public function get($name)
    {
        $data = null;
        $path = $this->getCachePath($name);
        if ($this->_caching) {
            $data = $this->_container->get($path);
            if ($data) {
                $data = unserialize($data);
            }
        }
        return $data;
    }
 
    /**
     * 删除缓存数据
     *
     * @param string name
     * @return mixed
     */
    public function delete($name)
    {
        $path = $this->getCachePath($name);
        $this->_container->delete($path);
        return true;
    }
 
    /**
     * 格式化变量名
     *
     * @param string name
     * @return string
     */
    public function getCachePath($name)
    {
        $path = '';
        if (!is_null($this->_flag)) {
            $path = $path. $this->_flag. '_';
        }
        if (!is_callable($this->_format)) {
            $this->_format = [$this, '_formatPath'];
        }
		$part = call_user_func_array($this->_format, [$name]);
        if (is_null($part)) {
            throw new RuntimeException(Language::get('cache.path_mustbe_notnull'));
        }
        $result = $path. $part;
        return $result;
    }
 
    /**
     * 返回redis实例
     *
     * @return \Redis
     */
    public function getInstance()
    {
        return $this->_container;
    }

    /**
     * @param $name
     * @return string
     */
	private function _formatPath($name)
	{
		return md5($name);
    }
    
}
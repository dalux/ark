<?php

namespace Brisk\Cache;

use Brisk\Assembly\Language;
use Brisk\Exception\CacheException;

class RedisCache extends CacheFather
{

    /**
     * redis
     *
     * @access private
     * @var \Redis
     */
    private $_container;

    /**
     * 构造器
     *
     * @param $save_path
     * @param array $option
     * @throws CacheException
     */
    function __construct($save_path, array $option = array())
    {
        try {
            if (!extension_loaded('redis')) {
                throw new CacheException('无法加载php_redis扩展');
            }
            list($host, $port) = explode(':', $save_path);
            $timeout = $option['timeout'] ? $option['timeout'] : 5;
            $this->_container = new \Redis();
            $this->_container->connect($host, $port, $timeout);
            $this->_container->auth($option['password']);
        } catch (\Exception $e) {
            throw new CacheException('Redis缓存器创建失败: '. $e->getMessage());
        }

    }

    /**
     * 缓存器设值
     *
     * @access public
     * @param $name
     * @param $value
     * @param $expire
     * @return bool
     * @throws CacheException
     */
    function set($name, $value, $expire = 86400)
    {
        $path = $this->getCachePath($name);
        return $this->_container->set($path, serialize($value), $expire);
    }

    /**
     * 缓存器取值
     *
     * @access public
     * @param $name
     * @return bool
     * @throws CacheException
     */
    function get($name)
    {
        $data = null;
        $path = $this->getCachePath($name);
        if ($this->_caching) {
            if (!$data = $this->_container->get($path)) {
                return null;
            }
            $data = unserialize($data);
        }
        return $data;
    }

    /**
     * 删除缓存数据
     *
     * @param $name
     * @return mixed
     * @throws CacheException
     */
    function delete($name)
    {
        $this->_container->delete($this->getCachePath($name));
        return true;
    }

    /**
     * 格式化变量名
     *
     * @access public
     * @param string $name
     * @return string
     * @throws CacheException
     */
    function getCachePath($name)
    {
        $path = '';
        if ($this->_flag) {
            $path.= $this->_flag. '_';
        }
        if (!$this->_format instanceof \Closure || !is_callable($this->_format)) {
            $this->_format = function($name) {
                return md5($name);
            };
        }
        $format = $this->_format;
        if (!$part = $format($name)) {
            throw new CacheException(Language::get('cache.path_mustbe_notnull'));
        }
        return $path. $part;
    }

    /**
     * 返回redis实例
     *
     * @return \Redis
     */
    function getInstance()
    {
        return $this->_container;
    }

}
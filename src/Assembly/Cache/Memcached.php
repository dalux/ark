<?php

namespace Ark\Assembly\Cache;

use Closure;
use Ark\Core\Captain;

class Memcached extends Father
{
    
    /**
     * MEMCACHE容器
     *
     * @access private
     * @var Memcached
     */
    private $_container;

    /**
     * 构造器
     *
     * @param $save_path
     * @param array $option
     * @throws Exception
     */
    function __construct($save_path, array $option = array())
    {
        if (!extension_loaded('memcached')) {
            throw new Exception(Captain::getInstance()->lang->get('cache.extension_load_failed', 'php_memcached'));
        }
        is_array($save_path) || $save_path = array($save_path);
        $this->_container = new \Memcached();
        foreach ($save_path as $v) {
            $url = parse_url($v);
            if ($url['host'] && $url['port']) {
                $this->_container->addServer($url['host'], $url['port']);
            }
        }
        $params = array(
            \Memcached::OPT_DISTRIBUTION=> \Memcached::DISTRIBUTION_CONSISTENT,
            \Memcached::OPT_CONNECT_TIMEOUT=> 500,
            \Memcached::OPT_COMPRESSION=> true,
            \Memcached::OPT_REMOVE_FAILED_SERVERS=> true,
        );
        if ($option) {
            $params = array_merge($params, $option);
        }
        foreach ($params as $key=> $val) {
            $this->_container->setOption($key, $val);
        }
        if (!$this->_container->getVersion()) {
            throw new Exception(Captain::getInstance()->lang->get('cache.cacher_create_failed', 'Memcached'));
        }
    }

    /**
     * 缓存设值
     * 
     * @access public
     * @param string $name
     * @param mixed $value
     * @param mixed $expire
     * @return bool
     */
    function set($name, $value, $expire = 86400)
    {
    	$path = $this->getCachePath($name);
        $this->_container->set($path, $value, $expire);
        return $this->_container->getResultCode() == \Memcached::RES_SUCCESS;
    }
    
    /**
     * 缓存取值
     * 
     * @access public
     * @param string $name
     * @return mixed
     */
    function get($name)
    {
    	$data = null;
    	$path = $this->getCachePath($name);
    	if ($this->_allow_cache) {
            $data = $this->_container->get($path);
            if ($this->_container->getResultCode() != \Memcached::RES_SUCCESS) {
                $data = null;
            }
        }
        return $data;
    }

    /**
     * 删除数据缓存
     *
     * @access public
     * @param $name
     * @return bool
     */
    function delete($name)
    {
    	$path = $this->getCachePath($name);
        $this->_container->delete($path);
        return $this->_container->getResultCode() == \Memcached::RES_SUCCESS;
    }

    /**
     * 将数据缓存到指定位置
     *
     * @access public
     * @param string $name
     * @param $value
     * @return bool
     */
    function __set($name, $value)
    {
    	return $this->set($name, $value);
    }
    
    /**
     * 取得缓存数据
     *
     * @access public
     * @param string $name
     * @return mixed
     */
    function __get($name)
    {
    	return $this->get($name);
    }

    /**
     * 格式化变量名
     *
     * @access public
     * @param string $name
     * @return string
     * @throws Exception
     */
    function getCachePath($name)
    {
        $path = '';
        if ($this->_flag) {
            $path.= $this->_flag. '_';
        }
        if (!$this->_format instanceof Closure || !is_callable($this->_format)) {
            $this->_format = function($name) {
                return md5($name);
            };
        }
        $format = $this->_format;
        if (!$part = $format($name)) {
            throw new Exception(Captain::getInstance()->lang->get('cache.path_mustbe_notnull'));
        }
        return $path. $part;
    }
    
}


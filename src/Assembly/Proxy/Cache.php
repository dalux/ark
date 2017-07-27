<?php

namespace Ark\Assembly\Proxy;

use Ark\Contract\Cache as CacheInterface;

class Cache
{
    
    /**
     * 对象适配器
     * 
     * @access private
     * @var object
     */
    private $_adapter = null;
    
    /**
     * 缓存器
     * 
     * @access private
     * @var CacheInterface
     */
    private $_cache = null;

    /**
     * 缓存名称
     *
     * @var null
     */
    private $_cache_name = null;

    /**
     * 缓存过期时间
     *
     * @var int
     */
    private $_cache_expire = 86400;
	
	/**
	 * 允许缓存的方法
	 * 
     * @access private
     * @var array
	 */
	private $_deny = array();

    /**
     * 构造器
     *
     * @access public
     * @param CacheInterface $cache
     */
    function __construct(CacheInterface $cache)
    {
        $this->_cache = $cache;
    }

	/**
     * 不允许代理的方法名范围
     * 
     * @access public
	 * @param array $deny
     * @return Cache
     */
	function deny(array $deny = null)
	{
		if (is_null($deny)) {
			return $this->_deny;
		}
		$this->_deny = $deny;
		return $this;
	}

    /**
     * 设置代理目标
     *
     * @access public
     * @param object $adapter 所代理对象
     * @param int $expire 缓存过期时间
     * @param string $name 缓存名称
     * @return Cache
     */
    function invoke($adapter, $expire, $name)
    {
        $this->_adapter = $adapter;
        $this->_cache_expire = $expire;
        $this->_cache_name = $name;
        return $this;
    }
    
    /**
     * 未知调用
     * 
     * @access public
     * @param string $name
     * @param array $args
     * @return mixed
     */
    function __call($name, $args)
    {
		//如果该方法名不允许被缓存，则直接抛回
		if ($this->_deny && in_array($name, $this->_deny)) {
			return call_user_func_array(array($this->_adapter, $name), $args);
		}
        $key = $this->name($this->_adapter, $name, $args);
        //自定义缓存名称
        if (!is_null($this->_cache_name)) {
            $key = $this->_cache_name;
        }
        $data = $this->_cache->get($key);
        //如果缓存过期时间为0，则设置缓存为过期状态
        if ($this->_cache_expire <= 0) {
            $data = null;
            $this->_cache->delete($key);
        }
        if (is_null($data)) {
            $data = call_user_func_array(array($this->_adapter, $name), $args);
            if (!is_null($data) && $this->_cache_expire > 0) {
                $this->_cache->set($key, $data);
            }
        }
        return $data;
    }
    
    /**
     * 根据缓存对象及方法生成Key值
     * 
     * @access private
     * @param object $class
     * @param string $func
     * @param array $args
     * @return string
     */
    function name($class, $func, $args) 
    {
        return get_class($class). '.'. $func. '.'. md5(serialize($args));
    }

}

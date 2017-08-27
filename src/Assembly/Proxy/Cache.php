<?php

namespace Ark\Assembly\Proxy;

use Ark\Contract\Cache as CacheInterface;

class Cache
{

    /**
     * 缓存器
     * 
     * @access private
     * @var CacheInterface
     */
    private $_cacher = null;

    /**
     * 设置代理缓存器
     *
     * @param CacheInterface $cache
     * @return $this
     */
    function setCacher(CacheInterface $cache)
    {
        $this->_cacher = $cache;
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
    function doProxy($adapter, $method, $args, $expire = 86400, $name = null)
    {
        $key = is_null($name)
            ? $this->name($adapter, $method, $args)
            : $name;
        $data = $this->_cacher->get($key);
        //如果缓存过期时间为0，则设置缓存为过期状态
        if ($expire <= 0) {
            $data = null;
            $this->_cacher->delete($key);
        }
        if (is_null($data)) {
            $data = call_user_func_array(array($adapter, $method), $args);
            if (!is_null($data) && $expire > 0) {
                $this->_cacher->set($key, $data);
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

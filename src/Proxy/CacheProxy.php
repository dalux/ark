<?php

namespace Ark\Proxy;

use Ark\Contract\ICache;
use Ark\Core\Language;
use Ark\Exception\ProxyException;

class CacheProxy
{

    /**
     * 缓存器
     * 
     * @access private
     * @var ICache
     */
    private $_cacher = null;

    /**
     * 设置代理缓存器
     *
     * @param ICache $cache
     * @return $this
     */
    function setCacher(ICache $cache)
    {
        $this->_cacher = $cache;
        return $this;
    }

    /**
     * 未知调用
     *
     * @access public
     * @param $adapter
     * @param $method
     * @param array $args
     * @param int $expire
     * @param string $name
     * @return mixed
     * @throws ProxyException
     */
    function doProxy($adapter, $method, array $args, $expire = 86400, $name = null)
    {
        if (!is_callable(array($adapter, $method))) {
            throw new ProxyException(Language::get('proxy.target_not_callable'));
        }
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
        $class_name = is_object($class)
            ? get_class($class)
            : (string)$class;
        return md5($class_name. '.'. $func. '.'.serialize($args));
    }

}

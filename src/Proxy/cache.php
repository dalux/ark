<?php

class Ark_Proxy_Cache
{

    /**
     * 缓存器
     * 
     * @access private
     * @var Ark_Cache_Contract
     */
    private $_cacher = null;

    /**
     * 设置代理缓存器
     *
     * @param Ark_Cache_Contract $cache
     * @return $this
     */
    function setCacher(Ark_Cache_Contract $cache)
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
     * @throws Exception
     */
    function doProxy($adapter, $method, array $args, $expire = 86400, $name = null)
    {
        if (!is_callable(array($adapter, $method))) {
            throw new Ark_Proxy_Exception(Ark_Language::get('proxy.target_not_callable'));
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

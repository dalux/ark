<?php

class Ark_Cache_Redis extends Ark_Cache_Father
{

    /**
     * redis
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
        try {
            if (!extension_loaded('redis')) {
                throw new Ark_Cache_Exception('无法加载php_redis扩展');
            }
            list($host, $port) = explode(':', $save_path);
            $timeout = $option['timeout'] ? $option['timeout'] : 5;
            $this->_container = new Redis();
            $this->_container->connect($host, $port, $timeout);
            $this->_container->auth($option['password']);
        } catch (Exception $e) {
            throw new Ark_Cache_Exception('Redis缓存器创建失败: '. $e->getMessage());
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
     * @throws Exception
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
     * @throws Exception
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
     * @throws Exception
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
     * @throws Ark_Cache_Exception
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
            throw new Ark_Cache_Exception(Ark_Core::getInst()->lang->get('cache.path_mustbe_notnull'));
        }
        return $path. $part;
    }

    /**
     * 返回redis实例
     *
     * @return Redis
     */
    function getInst()
    {
        return $this->_container;
    }

}
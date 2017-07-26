<?php

namespace Ark\Assembly\Cache;

abstract class Father
{

    /**
     * 超时期限
     *
     * @access protected
     * @var int
     */
    protected $_expire_time = 86400;

    /**
     * 数据项区分标志
     *
     * @access protected
     * @var string
     */
    protected $_flag;

    /**
     * 是否允许格式化缓存名称
     *
     * @access protected
     * @var bool
     */
    protected $_allow_format = true;

    /**
     * 缓存器状态是否可用
     *
     * @var bool
     */
    protected $_allow_cache = true;

    /**
     * 设置当前过期时间
     *
     * @access public
     * @param int $time
     * @return mixed
     */
    function setExpireTime($time)
    {
        $this->_expire_time = (int)$time;
        return $this;
    }

    /**
     * 取得当前过期时间
     *
     * @access public
     * @return mixed
     */
    function getExpireTime()
    {
        return $this->_expire_time;
    }

    /**
     * 取得/设置当前标志
     *
     * @access public
     * @param string $flag
     * @return $this
     */
    function setFlag($flag)
    {
        $this->_flag = $flag;
        return $this;
    }

    /**
     * 取得当前缓存存放区
     *
     * @return string
     */
    function getFlag()
    {
        return $this->_flag;
    }

    /**
     * 是否允许格式化名称
     *
     * @access public
     * @param bool|string $allow
     * @return $this
     */
    function setAllowFormat($allow = true)
    {
        $this->_allow_format = (bool)$allow;
        return $this;
    }

    /**
     * 是否允许格式化名称
     *
     * @access public
     * @return bool
     */
    function getAllowFormat()
    {
        return (bool) $this->_allow_format;
    }

    /**
     * 是否允许使用缓存器
     *
     * @access public
     * @param bool|string $allow
     * @return $this
     */
    function setAllowCache($allow = true)
    {
        $this->_allow_cache = (bool)$allow;
        return $this;
    }

    /**
     * 获取当前缓存器状态
     *
     * @return bool
     */
    function getAllowCache()
    {
        return $this->_allow_cache;
    }

    /**
     * 缓存器设值
     *
     * @access public
     * @param $name
     * @param $value
     * @return bool
     */
    abstract function set($name, $value);

    /**
     * 缓存器取值
     *
     * @access public
     * @param $name
     * @return bool
     */
    abstract function get($name);

    /**
     * 删除缓存数据
     *
     * @param $name
     * @return mixed
     */
    abstract function delete($name);

    /**
     * 缓存数据名称
     *
     * @access public
     * @param string $name 要操作的缓存名称
     * @return mixed
     */
    abstract function getCachePath($name);

}

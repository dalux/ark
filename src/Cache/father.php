<?php

abstract class Ark_Cache_Father implements Ark_Cache_Contract
{

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
    protected $_format;

    /**
     * 缓存器状态是否可用
     *
     * @var bool
     */
    protected $_caching = true;

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
     * 设置缓存名称格式化函数
     *
     * @param Closure $format
     * @return $this
     */
    function setFormat(Closure $format)
    {
        $this->_format = $format;
        return $this;
    }

    /**
     * 是否允许使用缓存器
     *
     * @access public
     * @param bool|string $caching
     * @return $this
     */
    function setCaching($caching = true)
    {
        $this->_caching = (bool)$caching;
        return $this;
    }

    /**
     * 缓存器设值
     *
     * @access public
     * @param $name
     * @param $value
     * @param int $expire
     * @return bool
     */
    abstract function set($name, $value, $expire = 86400);

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

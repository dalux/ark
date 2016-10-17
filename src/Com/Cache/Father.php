<?php

namespace Ark\Com\Cache;

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
     * @return Father
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
     * @return Father
     */
    function setAllowFormat($allow = true)
    {
        $this->_allow_format = $allow;
        return $this;
    }

}

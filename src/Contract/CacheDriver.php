<?php

namespace Ark\Contract;

interface CacheDriver
{


    /**
     * 缓存器设值
     *
     * @access public
     * @param $name
     * @param $value
     * @return bool
     */
    function set($name, $value);

    /**
     * 缓存器取值
     *
     * @access public
     * @param $name
     * @return bool
     */
    function get($name);

    /**
     * 删除缓存数据
     *
     * @param $name
     * @return mixed
     */
    function delete($name);

    /**
     * 过期时间(秒)
     *
     * @access public
     * @param integer $time
     * @return mixed
     */
    function setExpireTime($time);

    /**
     * 获取当前过期时间设置(秒)
     *
     * @access public
     * @return mixed
     */
    function getExpireTime();

    /**
     * 存储标识或文件夹
     *
     * @access public
     * @param string $flag
     * @return mixed
     */
    function setFlag($flag);

    /**
     * 获取当前存储标识
     *
     * @return mixed
     */
    function getFlag();

    /**
     * 缓存数据名称
     *
     * @access public
     * @param string $name 要操作的缓存名称
     * @return mixed
     */
    function getCachePath($name);

}

<?php

namespace Brisk\Cache;

class VoidCache extends CacheFather
{

    /**
     * 缓存器设值
     *
     * @access public
     * @param $name
     * @param $value
     * @param int $expire
     * @return bool
     */
    function set($name, $value, $expire = 86400)
    {
        return false;
    }

    /**
     * 缓存器取值
     *
     * @access public
     * @param $name
     * @return bool
     */
    function get($name)
    {
        return null;
    }

    /**
     * 删除缓存数据
     *
     * @param $name
     * @return mixed
     */
    function delete($name)
    {
        return false;
    }

    /**
     * 缓存数据名称
     *
     * @access public
     * @param string $name 要操作的缓存名称
     * @return mixed
     */
    function getCachePath($name)
    {
        return null;
    }

}
<?php

namespace Ark\Assembly\Cache;

class Invalid extends Father
{

    /**
     * 缓存器设值
     *
     * @access public
     * @param $name
     * @param $value
     * @return bool
     */
    function set($name, $value)
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
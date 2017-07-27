<?php

namespace Ark\Contract;

interface Cache
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
    function set($name, $value, $expire = 86400);

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
     * 缓存数据名称
     *
     * @access public
     * @param string $name 要操作的缓存名称
     * @return mixed
     */
    function getCachePath($name);

}
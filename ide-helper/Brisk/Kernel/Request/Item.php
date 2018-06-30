<?php

namespace Brisk\Kernel\Request;

class Item
{

    /**
     * 添加请求数据
     *
     * @param string $name
     * @param mixed $value
     * @return null
     */
    public function add($name, $value) {}

    /**
     * 删除请求数据
     *
     * @param string $name
     * @return null
     */
    public function del($name) {}

    /**
     * 获取请求数据
     *
     * @param string $name
     * @param string $alternative
     * @return mixed
     */
    public function data($name = "", $alternative = "") {}


}
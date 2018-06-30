<?php

namespace Brisk\Kernel;

class Trace
{

    /**
     * 设置跟踪信息
     *
     * @param string $flag
     * @param mixed $data
     * @return null
     */
    public static function set($flag, $data) {}

    /**
     * 取得跟踪信息
     *
     * @param string $flag
     * @return array
     */
    public static function get($flag = "") {}

}

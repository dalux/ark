<?php

namespace Brisk\Kernel;

class Handler
{

    /**
     * 设置异常处理句柄
     *
     * @param string $type
     * @param mixed $handler
     * @return null
     */
    public static function setHandler($type, $handler = null) {}

    /**
     * 处理异常显示
     *
     * @param mixed $e
     * @return null
     */
    public function display($e) {}


}

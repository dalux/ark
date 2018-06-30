<?php

namespace Brisk\Kernel;

class Server
{

    /**
     * 是否cli模式
     *
     * @return bool
     */
    public static function isCli() {}

    /**
     * 获取当前域名
     *
     * @param bool $reduce
     * @return string
     */
    public static function getDomain($reduce = true) {}

    /**
     * 获取当前子域名
     *
     * @return string
     */
    public static function getSubDomain() {}

    /**
     * 初始化cli模式数据
     *
     * @return null
     */
    public static function initCli() {}

    /**
     * 获取server数据
     *
     * @param string $item
     * @return string
     */
    public static function getItem($item = "") {}

}

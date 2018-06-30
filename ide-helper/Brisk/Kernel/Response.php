<?php

namespace Brisk\Kernel;

class Response
{

    /**
     * 设置状态码
     *
     * @param int $code
     * @param string $text
     * @return null
     */
    public function status($code, $text = "") {}

    /**
     * 设置cookie
     *
     * @param string $name
     * @param mixed $val
     * @param int $expire
     * @param string $path
     * @param string $domain
     * @param bool $secure
     * @param bool $httponly
     * @return null
     */
    public function cookie($name, $val, $expire = 0, $path = "/", $domain = "", $secure = false, $httponly = true) {}

    /**
     * 跳转
     *
     * @param string $url
     * @param bool $script
     * @param string $msg
     * @return null
     */
    public function redirect($url, $script = false, $msg = "") {}

    /**
     * 打印警告信息
     *
     * @param string $msg
     * @return null
     */
    public function alert($msg) {}

    /**
     * 不缓存输出信息
     *
     * @return null
     */
    public function noCache() {}

    /**
     * 设置页面数据过期时间
     *
     * @param int $sec
     * @return null
     */
    public function expires($sec = 3600) {}

    /**
     * 输出header信息
     *
     * @param string $item
     * @param string $val
     * @param bool $replace
     * @return null
     */
    public function header($item = "", $val = "", $replace = true) {}

}

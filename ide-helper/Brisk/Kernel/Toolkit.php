<?php

namespace Brisk\Kernel;

class Toolkit
{

    /**
     * 返回数组的print_r结果字符串表示
     *
     * @return string
     */
    public static function sprintr() {}

    /**
     * 有格式打印数组
     *
     * @return null
     */
    public static function printr() {}

    /**
     * 返回数组的var_dump结果字符串表示
     *
     * @return string
     */
    public static function svardump() {}

    /**
     * 有格式的打印数组
     *
     * @return null
     */
    public static function vardump() {}

    /**
     * 递归创建目录
     *
     * @param string $dir
     * @return null
     */
    public static function mkDir($dir) {}

    /**
     * 递归拷贝目录
     *
     * @param string $src
     * @param string $dst
     * @return null
     */
    public static function copyDir($src, $dst) {}

    /**
     * 递归删除目录
     *
     * @param string $dir_name
     * @return null
     */
    public static function removeDir($dir_name) {}

}

<?php

namespace Brisk\Kernel;

class Loader
{

    /**
     * 设置路径别名
     *
     * @param string $alias
     * @param string $path
     * @return null
     */
    public static function setAlias($alias, $path) {}

    /**
     * 设置命名空间
     *
     * @param string $nspace
     * @param string $path
     * @return null
     */
    public static function setNameSpace($nspace, $path) {}

    /**
     * 获取别名设置
     *
     * @return array
     */
    public static function getAlias() {}

    /**
     * 获取命名空间
     *
     * @return array
     */
    public static function getNameSpace() {}

    /**
     * 添加自动加载器
     *
     * @param callable $loader
     * @return null
     */
    public static function addAutoLoader($loader) {}

    /**
     * 根据类名称返回对应路径
     *
     * @param string $classname
     * @return string
     */
    public static function findClass($classname) {}

    /**
     * 根据别名路径返回真实地址
     *
     * @param string $spacename
     * @return string
     */
    public static function realPath($spacename) {}

    /**
     * 根据别名设置简化真实地址
     *
     * @param string $path
     * @return string
     */
    public static function reducePath($path) {}

}

<?php

namespace Brisk\Kernel;

class App
{

    const NAME      = "Brisk";
    const AUTHOR    = "郭大路<guodalu@qq.com>";
    const VERSION   = "1.0.2";

    /**
     * 设置app属性
     *
     * @param string $name
     * @param array $options
     * @return null
     */
    public static function set($name, array $options = array()) {}

    /**
     * 设置app名称
     *
     * @param string $name
     * @return null
     */
    public static function setName($name) {}

    /**
     * 设置app项目根目录地址
     *
     * @param string $path
     * @return null
     */
    public static function setBaseDir($path) {}

    /**
     * 设置配置文件获取函数
     *
     * @param \Closure $config
     * @return null
     */
    public static function setConfig(\Closure $config) {}

    /**
     * 设置控制器目录地址
     *
     * @param string $path
     * @return null
     */
    public static function setControllerDir($path) {}

    /**
     * 获取app名称
     *
     * @return string
     */
    public static function getName() {}

    /**
     * 获取app项目目录路径
     *
     * @return string
     */
    public static function getBaseDir() {}

    /**
     * 获取控制器目录路径
     *
     * @return string
     */
    public static function getControllerDir() {}

    /**
     * 初始化框架
     *
     * @return null
     */
    public static function init() {}

    /**
     * 获取框架实例
     *
     * @return App
     */
    public static function getInstance() {}

    /**
     * 启动框架
     *
     * @return null
     */
    public static function start() {}

    /**
     * 设置组件对象
     *
     * @param string $name
     * @param callable $value
     * @return null
     */
    public static function setComponent($name, $value) {}

    /**
     * 获取组件对象
     *
     * @param string $name
     * @return object
     */
    public function getComponent($name) {}

    /**
     * 获取组件对象
     *
     * @param string $name
     * @return object
     */
    public function __get($name) {}

    /**
     * 设置自定义方法
     *
     * @param string $name
     * @param callable $method
     * @return null
     */
    public static function setMethod($name, $method) {}

    /**
     * 调用自定义方法
     *
     * @param string $name
     * @param array $args
     * @return mixed
     */
    public function callMethod($name, array $args) {}

    /**
     * 魔术调用自定义方法
     *
     * @param string $name
     * @param array $args
     */
    public function __call($name, array $args) {}

    /**
     * 框架析构
     *
     * @return null
     */
    public function __destruct() {}

}

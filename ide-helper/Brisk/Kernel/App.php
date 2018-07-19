<?php

namespace Brisk\Kernel;

class App
{

    const NAME      = "Brisk";
    const AUTHOR    = "郭大路<guodalu@qq.com>";
    const VERSION   = "1.0.2";

    /**
     * 设置app名称
     *
     * @param string $name 应用名称，用作根命名空间
     * @param string $base_dir 应用根目录
     * @return $this
     */
    public function setApp($name, $base_dir) {}

    /**
     * 设置配置文件获取函数
     *
     * @param \Closure $config  获取配置文件函数，返回值为array
     * @return $this
     */
    public function setConfig(\Closure $config) {}

    /**
     * 设置控制器目录地址
     *
     * @param string $path 当前应用控制器路径
     * @return $this
     */
    public function setControllerDir($path) {}

    /**
     * 获取app名称
     *
     * @param string $item 获取app应用项，可选值name|base_dir
     * @return mixed
     */
    public function getApp($item = '') {}

    /**
     * 获取控制器目录路径
     *
     * @return string
     */
    public function getControllerDir() {}

    /**
     * 获取框架实例
     *
     * @return $this
     */
    public function getInstance() {}

    /**
     * 启动框架
     *
     * @return null
     */
    public function start() {}

    /**
     * 添加语言包
     * @param $language 语言
     * @param $path 包文件路径，需返回数组
     * @return $this
     */
    public function addLanguagePackage($language, $path) {}

    /**
     * 设置应用语言
     *
     * @param $language 语言名称
     * @return $this
     */
    public function setLanguage($language) {}

    /**
     * 设置组件对象
     *
     * @param string $name
     * @param callable $value
     * @return null
     */
    public function setComponent($name, $value) {}

    /**
     * 添加事件监听器
     *
     * @param $event 事件名称
     * @param $listener 监听器匿名函数
     * @return $this
     */
    public function addEventListener($event, $listener) {}

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
    public function setMethod($name, $method) {}

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

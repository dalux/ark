<?php

namespace Brisk\Cache\Driver;


class Redis extends \Brisk\Cache\CacheFather
{

    private $_container;


    /**
     * 构造器
     *
     * @param string $save_path
     * @param array $setting
     * @return null
     */
    public function __construct($save_path, array $setting = array()) {}

    /**
     * 缓存器设值
     *
     * @param string $name
     * @param mixed $value
     * @param null $expire
     * @return bool
     */
    public function set($name, $value, $expire = 0) {}

    /**
     * 缓存器取值
     *
     * @param string $name
     * @return bool
     */
    public function get($name) {}

    /**
     * 删除缓存数据
     *
     * @param string $name
     * @return mixed
     */
    public function delete($name) {}

    /**
     * 格式化变量名
     *
     * @param string $name
     * @return string
     */
    public function getCachePath($name) {}

    /**
     * 返回redis实例
     *
     * @return \Redis
     */
    public function getInstance() {}

    /**
     * @param string $name
     * @param mixed $value
     */
    public function __set($name, $value) {}

    /**
     * @param string $name
     */
    public function __get($name) {}

    /**
     * @param string $name
     */
    private function _formatPath($name) {}

}

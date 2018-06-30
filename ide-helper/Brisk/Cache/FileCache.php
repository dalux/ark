<?php

namespace Brisk\Cache;

class FileCache extends \Brisk\Cache\CacheFather
{

    /**
     * 实例化文件缓存
     *
     * @param string $save_path
     * @param array $option
     */
    public function __construct($save_path, array $option = array()) {}

    /**
     * 设置缓存
     *
     * @param string $name
     * @param mixed $value
     * @param int $expire
     * @return bool
     */
    public function set($name, $value, $expire = 86400) {}

    /**
     * 获取缓存数据
     *
     * @param string $name
     * @return mixed
     */
    public function get($name) {}

    /**
     * 删除缓存数据
     *
     * @param string $name
     * @return bool
     */
    public function delete($name) {}

    /**
     * 魔术方法设值
     *
     * @param string $name
     * @param mixed $value
     */
    public function __set($name, $value) {}

    /**
     * 魔术方法取值
     *
     * @param string $name
     * @return mixed
     */
    public function __get($name) {}

    /**
     * 获取缓存路径
     *
     * @param string $name
     * @return string
     */
    public function getCachePath($name) {}

}

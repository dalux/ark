<?php

namespace Brisk\Cache;

abstract class CacheFather implements \Brisk\Contract\ICache
{

    /**
     * 设置缓存标记
     *
     * @param string $flag
     * @return CacheFather
     */
    public function setFlag($flag) {}

    /**
     * 设置缓存名格式化方法
     *
     * @param callable $format
     * @return CacheFather
     */
    public function setFormat($format) {}

    /**
     * 设置是否开启缓存
     *
     * @param bool $caching
     * @return CacheFather
     */
    public function setCaching($caching = true) {}

    /**
     * 设置缓存内容
     *
     * @param string $name
     * @param mixed $value
     * @param int $expire
     * @return bool
     */
    public abstract function set($name, $value, $expire = 86400);

    /**
     * 获取缓存数据
     *
     * @param string $name
     * @return mixed
     */
    public abstract function get($name);

    /**
     * 删除缓存数据
     *
     * @param string $name
     * @return null
     */
    public abstract function delete($name);

    /**
     * 获取缓存路径
     *
     * @param string $name
     * @return null
     *
     */
    public abstract function getCachePath($name);

}

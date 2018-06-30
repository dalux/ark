<?php

namespace Brisk\Contract;

interface ICache
{

    /**
     * 设置缓存
     *
     * @param string $name
     * @param mixed $value
     * @param int $expire
     * @return bool
     */
    public function set($name, $value, $expire = 86400);

    /**
     * 获取缓存
     *
     * @param string $name
     * @return mixed
     */
    public function get($name);

    /**
     * 删除缓存数据
     *
     * @param string $name
     * @return bool
     */
    public function delete($name);

    /**
     * 获取缓存内容
     *
     * @param string $name
     * @return mixed
     */
    public function getCachePath($name);

    /**
     * 设置缓存标记
     *
     * @param string $flag
     * @return ICache
     */
    public function setFlag($flag);

    /**
     * 设置是否缓存
     *
     * @param bool $caching
     * @return ICache
     */
    public function setCaching($caching = true);

}

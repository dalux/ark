<?php declare(strict_types=1);

namespace Brisk\Cache;

interface ICacheDriver
{

    /**
     * 设置缓存标识
     *
     * @access public
     * @param string $flag
     * @return ICacheDriver
     */
    public function setFlag(string $flag);

    /**
     * 设置缓存是否生效
     *
     * @access public
     * @param bool $caching
     * @return ICacheDriver
     */
    public function setCaching(bool $caching = true);

    /**
     * 设置缓存默认过期时间
     *
     * @access public
     * @param int $expire_time
     * @return ICacheDriver
     */
    public function setExpireTime(int $expire_time = 86400);

    /**
     * 设置缓存数据
     *
     * @access public
     * @param string $name
     * @param mixed $value
     * @param int $expire
     * @return bool
     */
    public function set(string $name, $value, int $expire = 0);

    /**
     * 获取缓存数据
     *
     * @access public
     * @param string $name
     * @return mixed
     */
    public function get(string $name);

    /**
     * 删除缓存数据
     *
     * @access public
     * @param string $name
     * @return bool
     */
    public function delete(string $name);

    /**
     * 获取驱动器实例
     *
     * @return object
     */
    public function getInstance();

}
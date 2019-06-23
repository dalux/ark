<?php

namespace Brisk\Cache;

interface ICacheDriver
{

    /**
     * Set cache flag
     *
     * @param string flag
     * @return ICacheDriver
     */
    public function setFlag(string $flag);

    /**
     * Setting whether data is cached
     *
     * @param bool caching
     * @return ICacheDriver
     */
    public function setCaching(bool $caching = true);

    /**
     * Set cache expire time
     *
     * @param int expire_time
     * @return ICacheDriver
     */
    public function setExpireTime(int $expire_time = 86400);

    /**
     * Set Cache data
     *
     * @param string name
     * @param mixed value
     * @param int expire
     * @return bool
     */
    public function set(string $name, $value, int $expire = 0);

    /**
     * Get Cache data
     *
     * @param string name
     * @return mixed
     */
    public function get(string $name);

    /**
     * Delete Cache data
     *
     * @param string name
     * @return bool
     */
    public function delete(string $name);

}
<?php

namespace Brisk\Vendor\Cache;


class CacheProxy
{

    private $_cache;


    /**
     * Set cache instance
     *
     * @param CacheFather $cache
     * @return CacheProxy
     */
    public function setCacheDriver(\Brisk\Vendor\Cache\CacheFather $cache) {}

    /**
     * Execute cache proxy
     *
     * @param object $target
     * @param string $method
     * @param array $args
     * @param int $expire
     * @param string $name
     * @return mixed
     */
    public function doProxy($target, $method, array $args, $expire = 86400, $name = '') {}

    /**
     * @param mixed $target
     * @param string $func
     * @param array $args
     */
    private function _name($target, $func, array $args) {}

}

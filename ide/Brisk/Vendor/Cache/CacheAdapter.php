<?php

namespace Brisk\Vendor\Cache;


class CacheAdapter
{

    /**
     * Get cache driver
     *
     * @param string $driver
     * @param string $save_path
     * @param array $option
     * @return CacheFather
     */
    public static function getDriver($driver, $save_path, array $option = array()) {}

    /**
     * Get cache driver from config
     *
     * @param string $name
     * @return CacheFather
     */
    public static function getDriverFromConfig($name) {}

}

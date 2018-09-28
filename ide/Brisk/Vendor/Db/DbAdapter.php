<?php

namespace Brisk\Vendor\Db;


class DbAdapter
{

    /**
     * Get Database driver
     *
     * @param string $driver
     * @param string $dsn
     * @param array $option
     * @return DbFather
     */
    public static function getDriver($driver, $dsn, array $option = array()) {}

    /**
     * Get Database driver from config
     *
     * @param string $name
     * @return DbFather
     */
    public static function getDriverFromConfig($name) {}

}

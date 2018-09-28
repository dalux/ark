<?php

namespace Brisk\Vendor\View;


class ViewAdapter
{

    /**
     * Get View driver
     *
     * @param string $driver
     * @param array $options
     * @return ViewFather
     */
    public static function getDriver($driver, array $options = array()) {}

    /**
     * Get View driver from config
     *
     * @return ViewFather
     */
    public static function getDriverFromConfig() {}

}

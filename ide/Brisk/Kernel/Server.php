<?php

namespace Brisk\Kernel;


class Server
{

    static private $_data = array();


    /**
     * Check if it is CLI mode
     *
     * @return bool
     */
    public static function isCli() {}

    /**
     * Get current Server domain name
     *
     * @param bool $reduce
     * @return string
     */
    public static function getDomain($reduce = true) {}

    /**
     * Get server sub-domain name
     *
     * @return string
     */
    public static function getSubDomain() {}

    /**
     * Init cli mode
     *
     * @return null
     */
    public static function initCli() {}

    /**
     * Get current Server parameters
     *
     * @param string $item
     * @return mixed
     */
    public static function getItem($item = '') {}

}

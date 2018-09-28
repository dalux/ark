<?php

namespace Brisk\Kernel;


class Trace
{

    static private $_trace = array();


    /**
     * Set trace data
     *
     * @param string $flag
     * @param mixed $data
     * @return null
     */
    public static function set($flag, $data) {}

    /**
     * Get trace data
     *
     * @param string $flag
     * @return mixed
     */
    public static function get($flag = '') {}

}

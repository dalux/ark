<?php

namespace Brisk\Kernel;


class Timer
{

    static private $_marks = array();


    /**
     * Mark Time Label
     *
     * @param string $flag
     * @return null
     */
    public static function mark($flag = '') {}

    /**
     * Check for the presence of a time label
     *
     * @param string $flag
     * @return bool
     */
    public static function isMarked($flag) {}

    /**
     * Get the most recent time-consuming
     *
     * @return float
     */
    public static function lastUsed() {}

    /**
     * Get total time-consuming
     *
     * @return float
     */
    public static function totalUsed() {}

    /**
     * Get time-consuming based on specified tags
     *
     * @param string $start
     * @param string $end
     * @return float
     */
    public static function pick($start, $end) {}

}

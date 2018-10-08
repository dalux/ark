<?php

namespace Brisk\Kernel;


class Toolkit
{

    /**
     * Get array variable string
     *
     * @param array $params
     * @return string
     */
    public static function sprintr(array $params) {}

    /**
     * Formatted print array variable
     *
     * @param array $params
     * @return null
     */
    public static function printr(array $params) {}

    /**
     * Get array variable string
     *
     * @param array $params
     * @return string
     */
    public static function svardump(array $params) {}

    /**
     * Formatted print array variable
     *
     * @param array $params
     * @return null
     */
    public static function vardump(array $params) {}

    /**
     * Recursively create a directory
     *
     * @param string $dir
     * @return bool
     */
    public static function mkDir($dir) {}

    /**
     * Recursively copy a directory
     *
     * @param string $src
     * @param string $dst
     * @return null
     */
    public static function copyDir($src, $dst) {}

    /**
     * Recursively remove a directory
     *
     * @param string $dir_name
     * @return null
     */
    public static function removeDir($dir_name) {}

    /**
     * Once include file
     *
     * @param string $file
     * @return null
     */
    public static function includeOnce($file) {}

    /**
     * Check to see if the classname declared
     *
     * @param string $classname
     * @return null
     */
    public static function classDeclared($classname) {}

    /**
     * Check to see if the file included
     *
     * @param string $file
     * @return null
     */
    public static function fileIncluded($file) {}

}

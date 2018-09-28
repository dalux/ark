<?php

namespace Brisk\Kernel;


class Loader
{

    static private $_alias = array();


    static private $_namespaces = array();


    /**
     * Set directory path aliases
     *
     * @param string $alias
     * @param string $path
     * @return null
     */
    public static function setAlias($alias, $path) {}

    /**
     * Set namespace path
     *
     * @param string $nspace
     * @param string $path
     * @return null
     */
    public static function setNameSpace($nspace, $path) {}

    /**
     * Get aliases
     *
     * @return array
     */
    public static function getAlias() {}

    /**
     * Set namespace path
     *
     * @return array
     */
    public static function getNameSpace() {}

    /**
     * Automatically load class name
     *
     * @param string $classname
     * @return null
     */
    public static function autoLoad($classname) {}

    /**
     * Find the class name corresponding file
     *
     * @param string $classname
     * @return string
     */
    public static function findClass($classname) {}

    /**
     * Find the corresponding file
     *
     * @param string $spacename
     * @return string
     */
    public static function realPath($spacename) {}

    /**
     * Convert file path format
     *
     * @param string $path
     * @return string
     */
    public static function reducePath($path) {}

    /**
     * @param string $nspace
     */
    private static function _parse($nspace) {}

}

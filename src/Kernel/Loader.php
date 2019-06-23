<?php

namespace Brisk\Kernel;

use Brisk\Exception\RuntimeException;

class Loader
{

    /**
     *
     * @var array
     */
	private static $_alias = [];

    /**
     *
     * @var array
     */
	private static $_namespaces = [];

    /**
     * Set directory path aliases
     *
     * @param string $alias
     * @param string $path
     * @return null
     */
	public static function setAlias($alias, $path)
	{
		self::$_alias[$alias] = $path;
	}

    /**
     * Set namespace path
     *
     * @param string $nspace
     * @param string $path
     * @return void
     */
	public static function addNameSpace($nspace, $path)
	{
        $nspace = rtrim($nspace, '\\');
		$nspath = [];
		if (isset(self::$_namespaces[$nspace])) {
			$nspath = self::$_namespaces[$nspace];
		}
		if (!in_array($path, $nspath)) {
			$nspath[] = $path;
		}
		self::$_namespaces[$nspace] = $nspath;
	}

    /**
     * Get aliases
     *
     * @param string $alias
     * @return array
     */
    public static function getAlias($alias = null)
    {
        return is_null($alias)
            ? self::$_alias
            : self::$_alias[$alias];
    }

    /**
     * Set namespace path
     *
     * @param string $nspace
     * @return array
     */
    public static function getNameSpace($nspace = null)
    {
        return is_null($nspace)
            ? self::$_namespaces
            : self::$_namespaces[$nspace];
    }

    /**
     * Automatically load class name
     *
     * @param string $classname
     * @return void
     */
    public static function autoLoad($classname)
    {
	    if ($path = self::findClass($classname)) {
            include_once($path);
        }
    }

    /**
     * Find the class name corresponding file
     *
     * @param string $classname
     * @return string
     */
    public static function findClass($classname)
    {
        $formal = [];
        foreach (self::$_namespaces as $key=> $val) {
            $key = ltrim($key, '\\');
            $classname = ltrim($classname, '\\');
            if (preg_match('/^'. addslashes($key). '\\\\/', $classname)) {
                if (!$formal || strlen($key) > strlen($formal['key'])) {
                    $formal['key'] = $key;
                    $formal['val'] = $val;
                }
            }
        }
        if (!$formal) {
            return '';
        }
        $path = '';
        foreach ($formal['val'] as $item) {
            $in_framework = $item == self::getAlias('*');
            $item = rtrim($item, DIRECTORY_SEPARATOR). DIRECTORY_SEPARATOR;
            $classname = preg_replace('/^'. addslashes($formal['key']). '\\\\/', '', $classname);
            $_path = str_replace('\\', DIRECTORY_SEPARATOR, $item. $classname);
            $_path = preg_replace('/\\.php$/', '', $_path). '.php';
            if (is_file($_path)) {
                $path = $_path;
                if ($in_framework) {
                    break;
                }
            }
        }
        return $path;
    }

    /**
     * Find the corresponding file
     *
     * @param string spacename
     * @return string
     */
    public static function realPath($spacename)
    {
		$parsed = self::_parse($spacename);
		if (count($parsed) > 0) {
			$alias = $parsed[0];
			$space = $parsed[1];
			return str_replace(['/', '\\'], DIRECTORY_SEPARATOR, self::$_alias[$alias]. $space);
        }
		throw new RuntimeException(Language::format('core.format_path_failed', $spacename));
    }

    /**
     * Convert file path format
     *
     * @param string $path
     * @return string
     */
    public static function reducePath($path)
    {
        foreach (self::$_alias as $key=> $val) {
            $path = str_replace($val, $key, $path);
        }
        return str_replace('\\', '/', $path);
    }

    /**
     *
     * @param string $nspace
     * @return array
     */
	private static function _parse($nspace)
	{
		$alias = substr($nspace, 0, 1);
		$path = substr($nspace, 1);
        if (!array_key_exists($alias, self::$_alias)) {
            return [];
        }
        return [$alias, $path];
	}

}
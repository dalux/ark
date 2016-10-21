<?php

namespace Ark\Core;

class Loader
{

    /**
     * 地址空间别名
     *
     * @var array
     */
    private static $_alias = array(
        '*'=> PATH_LIB,
        '.'=> PATH_APP,
    );

    /**
     * 注册关键地址
     *
     * @var array
     */
    private static $_namespaces = array();

    /**
     * 注册路径别名
     *
     * @param $alias
     * @param $path
     * @throws RuntimeException
     */
    static function setAlias($alias, $path)
    {
        if (in_array($alias, array('*', '.'))) {
            throw new RuntimeException(sprintf(Noah::getInstance()->language->get('core.deny_alias_redeclare'), $alias));
        }
        self::$_alias[$alias] = $path;
    }

    /**
     * 注册命名空间地址
     *
     * @param $namespace
     * @param $path
     * @throws RuntimeException
     */
    static function setNameSpace($namespace, $path)
    {
        //如果要重定义系统内建命名空间
        $namespace = str_replace(array_search('\\', '/'), '\\', $namespace);
        if (preg_match('/^Ark\\\\/i', $namespace)) {
            $class_name = preg_replace('/^Ark/i', '', $namespace);
            $tmp_path = str_replace('\\', DIRECTORY_SEPARATOR, PATH_LIB. $class_name);
            if (!isset(self::$_namespaces[$namespace])
                    || !in_array($tmp_path, self::$_namespaces[$namespace])) {
                self::$_namespaces[$namespace][] = $tmp_path;
            }
        }
        self::$_namespaces[$namespace][] = $path;
    }

    /**
     * 获取别名配置
     *
     * @return array
     */
    static function getAlias()
    {
        return self::$_alias;
    }

    /**
     * 获取已注册命名空间
     *
     * @return array
     */
    static function getNameSpace()
    {
        return self::$_namespaces;
    }

    /**
     * 设置自动加载器
     *
     * @param $loader
     * @throws RuntimeException
     */
    static function addAutoLoader($loader)
    {
        if (!is_callable($loader)) {
            throw new RuntimeException(Noah::getInstance()->language->get('core.invalid_autoloader'));
        }
        spl_autoload_register($loader);
    }

    /**
     * 本框架自动加载器
     *
     * @param $class
     */
    static function autoLoad($class)
    {
        if ($path = self::findClass($class)) {
            self::import($path);
        }
    }

    /**
     * 根据命名空间类名规则找到真实路径
     *
     * @param $class_name
     * @return string
     */
    static function findClass($class_name)
    {
        $formal = array();
        foreach (self::$_namespaces as $key=> $val) {
            if (preg_match('/^'. addslashes($key). '/', $class_name)) {
                if (!$formal || strlen($key) > strlen($formal['key'])) {
                    $formal['key'] = $key;
                    $formal['val'] = $val;
                }
            }
        }
        if (!$formal) {
            return '';
        }
        foreach ($formal['val'] as $item) {
            $item = rtrim($item, DIRECTORY_SEPARATOR). DIRECTORY_SEPARATOR;
            $class_name = preg_replace('/^'. addslashes($formal['key']). '/', '', $class_name);
            $path = str_replace('\\', DIRECTORY_SEPARATOR, $item. $class_name);
            if (!preg_match('/\.php$/', $path)) {
                $path = $path. '.php';
            }
            if (is_file($path)) {
                return $path;
            }
        }
        return '';
    }

    /**
     * 格式化文件路径
     *
     * @param $spacename
     * @return string
     * @throws RuntimeException
     */
    static function realPath($spacename)
    {
        $first_char = substr($spacename, 0, 1);
        if (!isset(self::$_alias[$first_char])) {
            throw new RuntimeException(Noah::getInstance()->language->get('core.format_path_failed'));
        }
        $parsed = self::_parse($spacename);
        list($alias, $space) = $parsed;
        return str_replace(array('/', '\\'), DIRECTORY_SEPARATOR, self::$_alias[$alias]. $space);
    }

    /**
     * 简化系统路径地址
     *
     * @param $path
     * @return string
     */
    static function reducePath($path)
    {
        foreach (self::$_alias as $key=> $val) {
            $path = str_replace($val, $key, $path);
        }
        return str_replace('\\', '/', $path);
    }

    /**
     * 加载文件
     *
     * @access public
     * @static
     * @param string $path 命名空间
     * @param bool $once 是否只加载一次
     * @return mixed
     */
    static function import($path, $once = true)
    {
        $first_char = substr($path, 0, 1);
        if (isset(self::$_alias[$first_char])) {
            $path = self::realPath($path);
        }
        return $once ? include_once($path) : include($path);
    }

	/**
	 * 解析命名空间
	 * 
     * @access private
     * @param string $namespace
     * @return mixed
	 */
	private static function _parse($namespace)
	{
        if (!is_string($namespace) 
              || !in_array($namespace[0], array_keys(self::$_alias))
              || $namespace[1] != '/') {
            return false;
        }
        return array($namespace[0], substr($namespace, 1));
	}
    
}
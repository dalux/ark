<?php declare(strict_types=1);

namespace Brisk\Kernel;

use Brisk\Exception\RuntimeException;

class Loader
{

    /**
     * 路径别名
     *
     * @var array
     */
	private static $_alias = [];

    /**
     * 命名空间
     *
     * @var array
     */
	private static $_namespaces = [];

    /**
     * 设置路径别名
     *
     * @access public
     * @param string $alias
     * @param string $path
     * @return void
     */
	public static function setAlias($alias, $path)
	{
		self::$_alias[$alias] = $path;
	}

    /**
     * 添加命名空间
     *
     * @access public
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
     * 获取别名路径信息
     *
     * @access public
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
     * 获取命名空间信息
     *
     * @access public
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
     * 自动加载文件
     *
     * @access public
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
     * 根据类名获取文件路径
     *
     * @access public
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
     * 加载文件
     *
     * @access public
     * @param string $spacename
     * @return string
     */
    public static function import(string $spacename)
    {
        return include_once(self::realPath($spacename));
    }

    /**
     * 获取指定空间路径对应的真实文件路径
     *
     * @access public
     * @param string $spacename
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
		$err = Language::format('core.format_path_failed', $spacename);
		throw new RuntimeException($err);
    }

    /**
     * 格式化完整路径到空间简略地址
     *
     * @access public
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
     * 解析空间路径地址
     *
     * @access private
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
<?php declare(strict_types=1);

namespace Brisk\Kernel;

class Trace
{

    /**
     * 跟踪数据
     * 
     * @var array
     */
	private static $_trace = [];

    /**
     * 设置跟踪数据
     *
     * @access public
     * @param string $flag
     * @param mixed $data
     * @return void
     */
	public static function set(string $flag, $data)
	{
		if (isset(self::$_trace[$flag])) {
			self::$_trace[$flag] = array_merge(self::$_trace[$flag], [$data]);
		} else {
			self::$_trace[$flag] = [$data];
		}
		if (count(self::$_trace[$flag]) > 1000) {
			self::$_trace[$flag] = array_slice(self::$_trace[$flag], -1000);
		}
	}

    /**
     * 获取跟踪数据
     *
     * @access public
     * @param string $flag
     * @return mixed
     */
	public static function get(string $flag)
	{
        return self::$_trace[$flag] ?? null;
	}

}
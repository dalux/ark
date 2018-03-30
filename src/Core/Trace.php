<?php

namespace Brisk\Core;

class Trace
{
	
	/**
	 * 数据库跟踪信息
	 * 
	 * @access private
	 * @var array
	 */
	private static $_trace = array();
	
	/**
	 * 设置跟踪信息
	 * 
	 * @access public
	 * @param string $flag
	 * @param mixed $data
	 * @return bool
	 */
	static function set($flag, $data)
	{
		self::$_trace[$flag][] = $data;
		if (count(self::$_trace[$flag]) > 1000 && Server::isCli()) {
			self::$_trace[$flag] = array_slice(self::$_trace[$flag], -1000);
		}
		return true;
	}
	
	/**
	 * 获取跟踪信息
	 * 
	 * @access public
	 * @param string $flag
	 * @return mixed
	 */
	static function get($flag = null)
	{
        if (is_null($flag)) {
            return self::$_trace;
        } elseif (isset(self::$_trace[$flag])) {
            return self::$_trace[$flag];
        } else {
            return null;
        }
	}
	
	
}
<?php

class Ark_Timer
{

	/**
	 * 时间标记点
	 * 
	 * @access private
	 * @staticvar 
	 * @var array
	 */
    private static $_marks = array();

    /**
     * 标记起始时间
     *
     * @access public
     * @static
     * @param null $flag
     * @return null
     */
    static function mark($flag = null)
    {
		if (is_null($flag)) {
			return self::$_marks;
		}
    	self::$_marks[(string)$flag] = microtime(true);
    }

	/**
	 * 查询是否有标记过
	 *
	 * @access public
	 * @static
	 * @param string $flag
	 * @return bool
	 */
	static function isMarked($flag)
	{
		return isset(self::$_marks[(string)$flag]);
	}
    
    /**
     * 获取最近两次标记的时间值
     * 
     * @access public
     * @static 
     * @return float
     */
    static function lastUsed()
    {
		$copy = self::$_marks;
		$newer = array_pop($copy);
		$older = array_pop($copy);
		$copy = null;
    	return number_format($newer - $older, 3, '.', '');
    }
    
    /**
     * 获取当前点到最初点的时间值
     * 
     * @access public
     * @return float
     */
    static function totalUsed()
    {
    	$copy = self::$_marks;
		$newest = array_pop($copy);
		$oldest = array_shift($copy);
		$copy = null;
    	return number_format($newest - $oldest, 3, '.', '');
    }

    /**
     * 选取时间点
     *
     * @access public
     * @static
     * @param $start
     * @param $end
     * @return mixed
     */
    static function pick($start, $end)
    {
		if (is_null($start) 
				|| is_null($end) 
				|| !isset(self::$_marks[$start]) 
				|| !isset(self::$_marks[$end])) {
			return  false;
		}
		$newer = self::$_marks[$end];
		$older = self::$_marks[$start];
    	return number_format($newer - $older, 3, '.', '');
    }

}
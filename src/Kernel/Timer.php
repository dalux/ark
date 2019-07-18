<?php declare(strict_types=1);

namespace Brisk\Kernel;

class Timer
{

    /**
     * 时间点数据
     * 
     * @var array
     */
    private static $_marks = [];

    /**
     * 标记
     *
     * @access public
     * @param string $flag
     * @return void
     */
    public static function mark(string $flag)
    {
    	self::$_marks[$flag] = microtime(true);
    }

    /**
     * 检查时间点是否已标记
     *
     * @access public
     * @param string $flag
     * @return bool
     */
	public static function isMarked(string $flag)
	{
		return isset(self::$_marks[$flag]);
	}

    /**
     * 获取最近两个时间点耗时
     *
     * @access public
     * @return float
     */
    public static function lastUsed()
    {
		$newer = end(self::$_marks);
		prev(self::$_marks);
		$older = current(self::$_marks);
		reset(self::$_marks);
		$reduce = $newer - $older;
    	return floatval(number_format($reduce, 3, '.', ''));
    }

    /**
     * 获取总耗时时间
     *
     * @access public
     * @return float
     */
    public static function totalUsed()
    {
		$oldest = current(self::$_marks);
		$newest = end(self::$_marks);
		reset(self::$_marks);
		$reduce = $newest - $oldest;
    	return floatval(number_format($reduce, 3, '.', ''));
    }

    /**
     * 获取指定时间点间的耗时
     *
     * @access public
     * @param string $start
     * @param string $end
     * @return float
     */
    public static function pick(string $start, string $end)
    {
		if ($start == ''
				|| $end == ''
				|| !isset(self::$_marks[$start])
				|| !isset(self::$_marks[$end])) {
			return  false;
		}
		$newer = self::$_marks[$end];
		$older = self::$_marks[$start];
		$reduce = $newer - $older;
    	return floatval(number_format($reduce, 3, '.', ''));
    }

}
<?php declare(strict_types=1);

namespace Brisk;

class Timer
{

    /**
     * @var array
     */
    private static $_marks = [];

    /**
     * Mark Time Label
     *
     * @param string $flag
     * @return void
     */
    public static function mark(string $flag)
    {
    	self::$_marks[$flag] = microtime(true);
    }

    /**
     * Check for the presence of a time label
     *
     * @param string $flag
     * @return bool
     */
	public static function isMarked(string $flag)
	{
		return isset(self::$_marks[$flag]);
	}

    /**
     * Get the most recent time-consuming
     *
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
     * Get total time-consuming
     *
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
     * Get time-consuming based on specified tags
     *
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
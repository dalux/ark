<?php

namespace Brisk\Kernel;

class Timer
{

    /**
     * 标记时间点
     *
     * @param string $flag
     * @return null
     */
    public static function mark($flag = "") {}

    /**
     * 是否存在时间点标记
     *
     * @param string $flag
     * @return bool
     */
    public static function isMarked($flag) {}

    /**
     * 上一个时间标记用时
     *
     * @return string
     */
    public static function lastUsed() {}

    /**
     * 截止当前总用时长
     *
     * @return string
     */
    public static function totalUsed() {}

    /**
     * 计算起止标签所耗时长
     *
     * @param string $start
     * @param string $end
     * @return string
     */
    public static function pick($start, $end) {}

}

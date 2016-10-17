<?php

namespace Ark\Com\Cache;

class Signal
{

    /**
     * 缓存信号：正常
     *
     */
    const SIGNAL_NORMAL = 0;

    /**
     * 缓存信号：过期
     *
     */
    const SIGNAL_EXPIRE = 1;

    /**
     * 当前信号
     *
     * @var int
     */
    private static $_signal = self::SIGNAL_NORMAL;

    /**
     * 设置当前上下文缓存信号
     *
     * @param $signal
     */
    static function setSignal($signal)
    {
        self::$_signal = $signal;
    }

    /**
     * 获取当前缓存信号设置
     *
     * @return int
     */
    static function getSignal()
    {
        return self::$_signal;
    }

}
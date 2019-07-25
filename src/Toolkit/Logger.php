<?php declare(strict_types=1);

namespace Library\Toolkit;

class Logger
{

    const NOTICE    = 'notice';
    const WARNING   = 'warning';
    const ERROR     = 'error';

    /**
     * 显示日志
     *
     * @param $level
     * @param mixed ...$args
     */
    public static function show($level, ...$args)
    {
        echo self::parse($level, $args). PHP_EOL;
    }

    /**
     * 返回格式化日志
     *
     * @param $level
     * @param mixed ...$args
     * @return string
     */
    public static function format($level, ...$args)
    {
        return self::parse($level, $args);
    }

    /**
     * 解析
     *
     * @param $level
     * @param array $args
     * @return string
     */
    private static function parse($level, array $args)
    {
        $sep = '/';
        $log = ['['. date('Y-m-d H:i:s'). ']'];
        foreach ($args as $arg) {
            $log[] = $arg;
        }
        return $level. ': '. implode(' / ', $log);
    }

}
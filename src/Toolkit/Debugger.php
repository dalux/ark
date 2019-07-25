<?php declare(strict_types=1);

namespace Brisk\Toolkit;

use Brisk\Kernel\Toolkit;

class Debugger
{

    /**
     * 日志文件
     *
     * @var string
     */
    private static $_log_file = '/tmp/debugger.log';

    /**
     * 设置日志文件
     *
     * @access public
     * @param string $file
     * @return void
     */
    public static function setLogFile(string $file)
    {
        self::$_log_file = $file;
    }

    /**
     * 以printr输出变量
     *
     * @access public
     * @param mixed ...$args
     * @return void
     */
    public static function varprint(...$args)
    {
        $trace = debug_backtrace();
        $log = 'at '. date('Y-m-d H:i:s'). PHP_EOL;
        $log.= 'on '. $trace[0]['file']. '(line:'. $trace[0]['line']. ')'. PHP_EOL;
        foreach ($args as $key=> $arg) {
            $log.= $key. ')=> '. Toolkit::sprintr($arg). PHP_EOL;
        }
        $log.= PHP_EOL;
        file_put_contents(self::$_log_file, $log, FILE_APPEND);
    }

    /**
     * 以vardump输出变量
     *
     * @access public
     * @param mixed ...$args
     * @return void
     */
    public static function vardump(...$args)
    {
        $trace = debug_backtrace();
        $log = 'at '. date('Y-m-d H:i:s'). PHP_EOL;
        $log.= 'on '. $trace[0]['file']. '(line:'. $trace[0]['line']. ')'. PHP_EOL;
        foreach ($args as $key=> $arg) {
            $log.= $key. ')=> '. Toolkit::svardump($arg);
        }
        $log.= PHP_EOL;
        file_put_contents(self::$_log_file, $log, FILE_APPEND);
    }

}
<?php declare(strict_types=1);

namespace Brisk\Http;

class Env
{

    /**
     * 初始化环境参数
     *
     * @access public
     * @return void
     */
    public static function init()
    {
        if (self::isCli()) {
            $argv = $_SERVER['argv'];
            array_shift($argv);
            foreach ($argv as $arg) {
                if (substr($arg, 0, 2) != '--') {
                    continue;
                }
                $arg = ltrim($arg, '--');
                $key = substr($arg, 0, strpos($arg, '='));
                $val = substr($arg, (strpos($arg, '=') + 1));
                if ($key == 'domain') {
                    $_SERVER['HTTP_HOST'] = $val;
                } elseif ($key == 'route') {
                    $_SERVER['REQUEST_URI'] = $val;
                } else {
                    $_GET[$key] = $val;
                }
            }
        }
    }

    /**
     * 检查当前是否cli模式
     *
     * @access public
     * @return bool
     */
    public static function isCli()
    {
        return isset($_SERVER['argv']) && isset($_SERVER['argc']);
    }
 
}
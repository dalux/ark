<?php declare(strict_types=1);

namespace Brisk\Http;

class Env
{

    /**
     * initialize
     *
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
     * Check if it is CLI mode
     *
     * @return bool
     */
    public static function isCli()
    {
        return isset($_SERVER['argv']) && isset($_SERVER['argc']);
    }
 
}
<?php

namespace Brisk\Http;

class Middleware
{

    /**
     * @var array
     */
    private static $_data = [];

    /**
     * before middleware
     *
     * @param string route
     * @param callable callback
     * @return void
     */
    public static function before(string $route, callable $callback)
    {
        self::$_data['before'][$route][] = $callback;
    }

    /**
     * after middleware
     *
     * @param string route
     * @param callable callback
     * @return void
     */
    public static function after(string $route, callable $callback)
    {
        self::$_data['after'][$route][] = $callback;
    }

    /**
     * get middleware
     *
     * @param string route
     * @param string type
     * @return array
     */
    public static function get(string $route, string $type)
    {
        $callbacks = [];
        if (isset(self::$_data[$type])) {
            $setting = self::$_data[$type];
            foreach ($setting as $key=> $val) {
                if (strpos($key, ':') !== false) {
                    $key = preg_replace_callback('~/\\:([^\\/]+)~', function($matches) {
                        $result = $matches[1];
                        if (strpos($result, '@') !== false) {
                            $result = explode('@', $result);
                            $name = $result[0];
                            $type = $result[1];
                            if ($type == 'int') {  //支持int限定
                                $p = sprintf('/(?P<%s>\d+)', $name);
                            } else {
                                $p = sprintf('/(?P<%s>%s)', $name, $type);
                            }
                            return $p;
                        } else {
                            return sprintf('/(?P<%s>[^\\/]+)', $result);
                        }
                    }, $key);
                }
                if (preg_match(sprintf('~^%s$~', $key), $route)) {
                    $callbacks = $val;
                    break;
                }
            }
        }
        return $callbacks;
    }

    /**
     * 清理中间件
     * 
     * @return void
     */
    public static function clean()
    {
        self::$_data = [];
    }

}
<?php declare(strict_types=1);

namespace Brisk\Http;

use Brisk\Kernel\Event;
use Brisk\Kernel\Language;
use Brisk\Exception\RuntimeException;

class Router
{

    /**
     * 路由规则
     * 
     * @var array
     */
    private static $_rules  = [];

    /**
     * 当前路由请求
     * 
     * @var string
     */
    private static $_route;

    /**
     * 获取当前路由
     *
     * @access public
     * @return string
     */
    public static function getRoute()
    {
        return self::$_route;
    }

    /**
     * 设置路由规则
     *
     * @access public
     * @param string $pattern
     * @param string|array $callback
     * @param string|array $interceptor
     * @return void
     */
    public static function addRule(string $pattern, $callback, $interceptor = null)
    {
        self::$_rules[$pattern] = [$callback, $interceptor];
    }

    /**
     * 获取已定义的路由规则
     *
     * @access public
     * @return array
     */
    public static function getRules()
    {
        return self::$_rules;
    }

    /**
     * 路由调度
     *
     * @access public
     * @return string
     */
    public static function dispatch()
    {
        if (!$uri = $_SERVER['REQUEST_URI']) {
            throw new RuntimeException(Language::format('http.invalid_require_uri'));
        }
        //解析URI
        if (strpos($uri, '?') !== false) {
            $uri = substr($uri, 0, strpos($uri, '?'));
			$query = substr($uri, strpos($uri, '?') + 1);
			if (Env::isCli() && $query) {
                $items = explode('&', $query);
                if (is_array($items)) {
                    foreach ($items as $item) {
                        $name = substr($item, 0, strpos($item, '='));
                        $value = substr($item, strpos($item, '=') + 1);
                        if (!isset($_GET[$name])) {
                            $_GET[$name] = $value;
                        }
                    }
                }
			}
        }
        self::$_route = $uri;
        //遍历规则
        $route = $callback = $interceptor = null;
        foreach (self::$_rules as $key=> $val) {
            if (strpos($key, ':') !== false) {
                $pattern = preg_replace_callback('~/\\:([^\\/]+)~', function($matches) {
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
                if (preg_match(sprintf('~^%s$~i', $pattern), $uri, $matches)) {
                    //如有别名，则加入_GET全局数组中
                    foreach ($matches as $k=> $v) {
                        if (is_string($k)) {
                            $_GET[$k] = $v;
                        }
                    }
                    $route = $key;
                    $callback = $val[0];
                    $interceptor = $val[1];
                    break;
                }
            } elseif (preg_match(sprintf('~^%s$~', $key), $uri, $matches)) {
                $route = $key;
                $callback = $val[0];
                $interceptor = $val[1];
                break;
            }
        }
        if (is_null($route)) {
            throw new RuntimeException(Language::format('http.router_not_defined', $uri));
        }
        //请求初始化
        Request::init($_GET);
        //路由解析器是否可用
        if (is_string($callback)
                && strpos($callback, '@') !== false) {
            $callback = explode('@', $callback);
        }
        //拦截器是否定义
        $list_interceptor = [];
        if (is_callable($interceptor)) {
            $list_interceptor = [$interceptor];
        } elseif (is_string($interceptor)) {
            if (strpos($interceptor, '@') !== false) {
                $interceptor = explode('@', $interceptor);
            }
            $list_interceptor = [$interceptor];
        } elseif (is_array($interceptor)) {
            foreach ($interceptor as $key => $val) {
                $list_interceptor[$key] = $val;
                if (is_string($val)) {
                    if (strpos($val, '@') !== false) {
                        $val = explode('@', $val);
                        $list_interceptor[$key] = $val;
                    }
                }
            }
        }
        //路由就绪事件
        $data = [
            'route'         => self::$_route,
            'callback'      => $callback,
            'interceptor'   => $list_interceptor,
        ];
        $data = Event::fire('event.router.ready', $data);
        $callback = $data['callback'];
        $list_interceptor = $data['interceptor'];
        if (!is_callable($callback)) {
            throw new RuntimeException(Language::format('http.router_not_callable', $uri));
        }
        if ($list_interceptor) {
            foreach ($list_interceptor as $val) {
                if (!is_callable($val)) {
                    throw new RuntimeException(Language::format('http.interceptor_not_callable', $uri));
                }
            }
            foreach ($list_interceptor as $val) {
                $result = call_user_func_array($val, []);
                if (!is_null($result)) {
                    return $result;
                }
            }
        }
        //控制器
        return call_user_func_array($callback, []);
    }

}
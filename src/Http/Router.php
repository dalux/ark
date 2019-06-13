<?php declare(strict_types=1);

namespace Brisk\Http;

use Brisk\Language;
use Brisk\Exception\RuntimeException;

class Router
{

    /**
     * @var array
     */
    private static $_rules  = [];

    /**
     * @var string
     */
    private static $_route;

    /**
     * get current route
     *
     * @return string
     */
    public static function getRoute()
    {
        return self::$_route;
    }

    /**
     * add route operator
     *
     * @param string pattern
     * @param callable callback
     * @return void
     */
    public static function addRule(string $pattern, callable $callback)
    {
        self::$_rules[$pattern] = $callback;
    }

    /**
     * get declared route
     *
     * @return array
     */
    public static function getRules()
    {
        return self::$_rules;
    }

    /**
     * Routing dispatch
     *
     * @return string
     */
    public static function dispatch()
    {
        if (!$uri = $_SERVER['REQUEST_URI']) {
            throw new RuntimeException(Language::format('router.invalid_require_uri'));
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
                if (preg_match(sprintf('~^%s$~i', $pattern), self::$_route, $matches)) {
                    //如有别名，则加入_GET全局数组中
                    foreach ($matches as $k=> $v) {
                        if (is_string($k)) {
                            $_GET[$k] = $v;
                        }
                    }
                    $route = $key;
                    $callback = $val;
                    break;
                }
            } elseif (preg_match(sprintf('~^%s$~', $key), self::$_route, $matches)) {
                $route = $key;
                $callback = $val;
                break;
            }
        }
        if (is_null($route)) {
            throw new RuntimeException(Language::format('router.route_not_defined', self::$_route));
        }
        //路由生命周期请求对象实例
        $request  = new Request($_GET);
        //路由生命周期响应对象实例
        $response = new Response();
        //清理函数
        $clean = function() use ($request, $response) {
            $response->clean();
            $request->clean();
            Middleware::clean();
        };
        //前置中间件
        $before_middlewares = Middleware::get(self::$_route, 'before');
        foreach ($before_middlewares as $middleware) {
            if (!is_callable($middleware)) {
                continue;
            }
            call_user_func_array($middleware, [$request, $response]);
            if ($response->isTerminated()) {
                $content = $response->getContent();
                $clean();
                return $content;
            }
        }
        //控制器
        call_user_func_array($callback, [$request, $response]);
        if ($response->isTerminated()) {
            $content = $response->getContent();
            $clean();
            return $content;
        }
        //后置中间件
        $after_middlewares = Middleware::get(self::$_route, 'after');
        foreach ($after_middlewares as $middleware) {
            if (!is_callable($middleware)) {
                continue;
            }
            call_user_func_array($middleware, [$request, $response]);
            if ($response->isTerminated()) {
                $content = $response->getContent();
                $clean();
                return $content;
            }
        }
        $content = $response->getContent();
        $clean();
        return $content;
    }

}
<?php declare(strict_types=1);

namespace Brisk\Http;

use Brisk\Exception\ActionNotFoundException;
use Brisk\Kernel\Event;
use Brisk\Exception\RuntimeException;
use Brisk\Kernel\Language;
use Brisk\Kernel\Loader;
use Brisk\Exception\ControllerNotFoundException;

class Router
{

    private static $_namespace;
    private static $_auto_controller;
    private static $_auto_ation         = '__init';
    private static $_default_controller = 'Index';
    private static $_default_action     = '__index';
    private static $_url_suffix;
    private static $_rules              = [];
    private static $_namespace_prefix   = 'App\Controller';
    private static $_request;

    /**
     * 设置控制器命名空间前缀
     *
     * @access public
     * @param string $prefix
     * @param string|null $basedir
     * @return void
     */
    public static function setControllerNameSpace(string $prefix, string $basedir = null)
    {
        self::$_namespace_prefix = trim($prefix, '\\');
        if ($basedir) {
            Loader::addNameSpace($prefix, $basedir);
        }
    }

    /**
     * 设置自化访问的拦截控制器名称
     *
     * @access public
     * @param string $controller
     * @return void
     */
    public static function setAutoController(string $controller)
    {
        self::$_auto_controller = ucfirst($controller);
    }

    /**
     * 设置自动化访问控制器行为名称
     *
     * @access public
     * @param string $action
     * @return void
     */
    public static function setAutoAction(string $action)
    {
        self::$_auto_ation = $action;
    }

    /**
     * 设置默认控制器名称
     *
     * @access public
     * @param string $controller
     * @return void
     */
    public static function setDefaultController(string $controller)
    {
        self::$_default_controller = ucfirst($controller);
    }

    /**
     * 设置默认行为名称
     *
     * @access public
     * @param string $action
     * @return void
     */
    public static function setDefaultAction(string $action)
    {
        self::$_default_action = $action;
    }

    /**
     * 设置默认URL文件后缀名
     *
     * @access public
     * @param string $suffix
     * @return void
     */
    public static function setUrlSuffix(string $suffix)
    {
        self::$_url_suffix = $suffix;
    }

    /**
     * 设置uri重写规则
     *
     * @access public
     * @param string $pattern
     * @param callable $callback
     * @return void
     */
    public static function setRewrite(string $pattern, callable $callback)
    {
        self::$_rules[$pattern] = $callback;
    }

    /**
     * 获取请求
     *
     * @access public
     * @return string
     */
    public static function getRequest()
    {
        return self::$_request;
    }

    /**
     * 路由调度
     *
     * @access public
     * @return mixed
     * @throws \ReflectionException
     */
    public static function dispatch()
    {
        $uri = $_SERVER['REQUEST_URI'] ?? '';
        if (!$uri || $uri == '/') {
            $uri = '/'. strtolower(self::$_default_controller);
        }
        //uri处理
        $query = [];
        if (strpos($uri, '?') !== false) {
            $query[] = substr($uri, strpos($uri, '?') + 1);
            $uri = substr($uri, 0, strpos($uri, '?'));
        }
        //重写uri
        $uri = self::rewrite($uri);
        if (strpos($uri, '?') !== false) {
            $query[] = substr($uri, strpos($uri, '?') + 1);
            $uri = substr($uri, 0, strpos($uri, '?'));
        }
        self::$_request = $uri;
        //整理get参数
        foreach ($query as $val) {
            $plist = explode('&', $val);
            foreach ($plist as $k=> $v) {
                $pk = substr($v, 0, strpos($v, '='));
                $pv = substr($v, strpos($v, '=') + 1);
                $_GET[$pk] = $pv;
            }
        }
        $uri = trim($uri, '/');
        //文件后缀名
        $suffix = self::$_url_suffix;
        if ($suffix && strpos($uri, $suffix) !== false) {
            $uri = preg_replace(sprintf('~%s$~i', $suffix), '', $uri);
        }
        $controller = self::$_default_controller;
        if ($uri != '') {
            $controller = implode('\\', array_map('ucfirst', explode('/', $uri)));
        }
        self::$_namespace = self::$_namespace_prefix. '\\'. $controller;
        //请求初始化
        Request::init($_GET);
        //调度
        $list = [];
        //自动拦截器
        if (self::$_auto_controller) {
            $auto_controller = self::$_auto_controller;
            //命名空间路径树
            $part = str_replace(self::$_namespace_prefix. '\\', '', self::$_namespace);
            $part = explode('\\', $part);
            $tree = [];
            $tree[] = self::$_namespace_prefix . '\\' . $auto_controller;
            if (count($part) > 1) {
                $basepath = self::$_namespace_prefix . '\\';
                foreach ($part as $k => $v) {
                    $basepath = $basepath . $v . '\\';
                    $tree[] = $basepath . $auto_controller;
                }
            }
            foreach ($tree as $ns) {
                $list[] = [
                    'namespace'     => $ns,
                    'is_required'   => false
                ];
            }
        }
        $list[] = [
            'namespace'     => self::$_namespace,
            'is_required'   => true
        ];
        $data = [
            'uri'           => self::$_request,
            'controllers'    => $list
        ];
        $data = Event::fire('event.router.ready', $data);
        $list = $data['controllers'];
        if (!is_array($list)) {
            throw new RuntimeException(Language::format('router.controller_is_empty'));
        }
        //循环访问控制器方法
        $auto_action = self::$_auto_ation;
        $action = self::$_default_action;
        foreach ($list as $val) {
            if (!$val['namespace']) {
                throw new RuntimeException(Language::format('router.invalid_controller_name', $val['namespace']));
            }
            //控制器是否存在
            if (!Loader::findClass($val['namespace'])) {
                if ($val['is_required']) {
                    throw new ControllerNotFoundException(Language::format('router.controller_not_found', $val['namespace']));
                }
                continue;
            }
            //是否被保护对象
            $ref = new \ReflectionClass($val['namespace']);
            if ($ref->isAbstract()) {
                throw new RuntimeException(Language::format('router.controller_is_protected', $val['namespace']));
            }
            $instance = new $val['namespace']();
            if (!method_exists($instance, $action)) {
                throw new ActionNotFoundException(Language::format('router.action_not_found', $val['namespace'], $action));
            }
            //自动化类
            if (method_exists($instance, $auto_action)) {
                $output = $instance->$auto_action();
                if (Response::isEnd() || !is_null($output)) {
                    return $output;
                }
            }
            $output = $instance->$action();
            if (Response::isEnd() || !is_null($output)) {
                return $output;
            }
        }
    }

    /**
     * 重写URI
     *
     * @access public
     * @param string $uri
     * @return string
     */
    public static function rewrite(string $uri)
    {
        foreach (self::$_rules as $key=> $val) {
            $key = '~'. $key. '~i';
            if (preg_match($key, $uri)) {
                if (is_callable($val)) {
                    $uri = preg_replace_callback($key, $val, $uri);
                } elseif (is_string($val)) {
                    $uri = preg_replace($key, $val, $uri);
                }
                if (!is_string($uri)) {
                    throw new RuntimeException(Language::format('router.rewrite_result_error'));
                }
            }
        }
        return $uri;
    }

}
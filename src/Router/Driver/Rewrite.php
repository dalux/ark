<?php

namespace Brisk\Router\Driver;

use Brisk\Kernel\App;
use Brisk\Kernel\Language;
use Brisk\Kernel\Request;
use Brisk\Kernel\Server;
use Brisk\Router\RouterFather;
use Brisk\Exception\ControllerException;
use Brisk\Exception\RouterException;
use Brisk\Exception\ConfigurationException;
use Brisk\Exception\ActionNotFoundException;
use Brisk\Exception\ControllerNotFoundException;

class Rewrite extends RouterFather
{

    /**
     * @var string
     */
    private static $_current_namespace;

    /**
     * @var array
     */
    private static $_rules = [];

    /**
     * @var string
     */
    private static $_auto_method = '__init';

    /**
     * @var string
     */
    private static $_default_controller = 'Index';

    /**
     * @var string
     */
    private static $_default_action = 'index';

    /**
     * @var string
     */
    private static $_url_suffix = '.html';

    /**
     * @var array
     */
    private static $_interceptors = [];

    /**
     * Adding routing rewriting rules
     *
     * @param string $rule
     * @param callable $redirect
     * @return void
     */
    public static function addRule($rule, callable $redirect)
    {
        self::$_rules[$rule] = $redirect;
    }

    /**
     * Add routing interceptors
     *
     * @param string ns_space
     * @param callable operator
     * @return null
     */
    public static function addInterceptor($ns_space, callable $operator)
    {
        $ns_space = ltrim($ns_space, '\\');
        self::$_interceptors[$ns_space] = $operator;
    }

    /**
     * Get routing interceptors
     *
     * @param string ns_space
     * @return null
     */
    public static function getInterceptors($ns_space)
    {
        $ns_space = ltrim($ns_space, '\\');
        $result = [];
        foreach (self::$_interceptors as $key=> $val) {
            if (strpos($ns_space, $key) !== false) {
                $result[$key] = $val;
            }
        }
        //按subspace长短来重新排序
        if (count($result)>0) {
            uksort($result, function($a, $b) {
                $len_a = strlen($a);
                $len_b = strlen($b);
                if ($len_a == $len_b) {
                    return 0;
                }
                return $len_a > $len_b ? 1 : -1;
            });
        }
        return $result;
    }

    /**
     * Routing ready
     *
     * @return null
     */
    public function ready()
    {
		if (!App::init()->config->hasKey('router/option/base_namespace')) {
			throw new ConfigurationException(Language::get('core.config_not_found', 'router/option/base_namespace'));
		}
        $option = App::init()->config->get('router/option');
		$base_namespace = trim($option['base_namespace'], '\\');
        
        $uri = $_SERVER['REQUEST_URI'];

        $controller = self::$_default_controller;
        if (isset($option['default_controller'])) {
            $controller = $option['default_controller'];
        }
        $controller = ucfirst($controller);

        $url_suffix = self::$_url_suffix;
        if (isset($option['url_suffix'])) {
            $url_suffix = $option['url_suffix'];
        }
        //解析URI
        if (strpos($uri, '?') != false) {
			$query = substr($uri, strpos($uri, '?') + 1);
            $uri = substr($uri, 0, strpos($uri, '?'));
			if (Server::isCli() && $query != '') {
				$list_query = explode('&', $query);
				foreach ($list_query as $query_item) {
					$query_name = substr($query_item, 0, strpos($query_item, '='));
					$query_val = substr($query_item, strpos($query_item, '=') + 1);
					if (!isset($_GET[$query_name])) {
						$_GET[$query_name] = $query_val;
					}
				}
			}
        }
        //重写URI
        $uri = trim($this->_rewrite($uri), '/');
        //去除url后缀
        if ($url_suffix && strpos($uri, $url_suffix) !== false) {
            $uri = preg_replace(sprintf('~%s$~i', $url_suffix), '', $uri);
        }
        if ($uri != '') {
            $controllers = array_map('ucfirst', explode('/', $uri));
            $dist = end($controllers);
            if (strpos($dist, '.') || strpos($dist, '_')) {
                $dist = str_replace(['.', '_'], '.', $dist);
				$dist = explode('.', $dist);
                $dist = array_map('ucfirst', $dist);
                $dist = implode('', $dist);
				$c = count($controllers);
                $controllers[($c - 1)] = $dist;
            }
            $controller = implode('\\', $controllers);
        }
        //拼凑当前控制器命名空间
        $ns_space = $base_namespace. '\\'. $controller;
        self::$_current_namespace = $ns_space;
        
        //请求数据初始化完成
        Request::ready($_GET);
        
    }

    /**
     * Routing path distribution
     *
     * @return null
     * @throws \ReflectionException
     */
    public function dispatch()
    {
        $ns_space = self::$_current_namespace;
        if (!class_exists($ns_space)) {
            throw new ControllerNotFoundException(Language::get('router.controller_not_found', $ns_space));
        }
        $option = App::init()->config->get('router/option');
        $action = self::$_default_action;
        $auto_method = self::$_auto_method;
        if (isset($option['default_action'])) {
            $action = $option['default_action'];
        }
        if (isset($option['auto_method'])) {
            $auto_method = $option['auto_method'];
        }
        //是否被保护对象
        $ref = new \ReflectionClass($ns_space);
        if ($ref->isAbstract()) {
            throw new ControllerException(Language::get('router.controller_is_protected', $ns_space));
        }
        //实现拦截器功能
        $interceptors = self::getInterceptors($ns_space);
        if (count($interceptors) > 0) {
            foreach ($interceptors as $op) {
                $result = call_user_func_array($op, []);
                if (is_string($result)) {
                    echo $result;
                    exit;
                }
            }
        }
        //实例化最终控制器对象
        $instance = new $ns_space();
        if (!method_exists($instance, $action)) {
            throw new ActionNotFoundException(Language::get('router.action_not_found', $action));
        }
        $output = null;
        //自动化类
        if (method_exists($instance, $auto_method)) {
            $output = $instance->$auto_method();
        }
        //目标控制器行为
        if (is_null($output)) {
            $output = $instance->$action();
        }
        echo $output;
    }

    /**
     * @param string $uri
     * @return string
     */
    private function _rewrite($uri)
    {
        foreach (self::$_rules as $key=> $val) {
            $key = '~'. $key. '~i';
            if (preg_match($key, $uri)) {
                $uri = preg_replace_callback($key, $val, $uri);
            }
        }
        if (!is_string($uri)) {
            throw new RouterException(Language::get('router.uri_must_string'));
        }
        return $uri;
    }

}
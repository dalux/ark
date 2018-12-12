<?php

namespace Brisk\Router\Driver;

use Brisk\Kernel\App;
use Brisk\Kernel\Language;
use Brisk\Http\Request;
use Brisk\Router\RouterFather;
use Brisk\Exception\ControllerException;
use Brisk\Exception\RouterException;
use Brisk\Exception\ConfigurationException;
use Brisk\Exception\ActionNotFoundException;
use Brisk\Exception\ControllerNotFoundException;

class Classic extends RouterFather
{

    /**
     * @var bool
     */
	private static $_module_support = false;

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
	private static $_default_module = 'Index';

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
     * @var string
     */
	private $_module;

    /**
     * @var string
     */
	private $_controller;

    /**
     * @var string
     */
	private $_action;

    /**
     * @var string
     */
	private $_namespace;

    /**
     * Turn on routing module support
     *
     * @param string $default_module
     * @return void
     */
	public static function openModuleSupport($default_module = null)
	{
		self::$_module_support = true;
		if ($default_module) {
			self::$_default_module = $default_module;
		}
	}

    /**
     * Adding routing rewriting rules
     *
     * @param string $rule
     * @param mixed $redirect
     * @return void
     */
	public static function addRule($rule, callable $redirect)
	{
		self::$_rules[$rule] = $redirect;
	}

    /**
     * Add routing interceptors
     *
     * @param string $ns_space
     * @param callable $operator
     * @return void
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
     * @return array
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
     * @return void
     */
	public function ready()
	{
		if (!App::init()->config->hasKey('router/option/base_namespace')) {
			throw new ConfigurationException(Language::get('core.config_not_found', 'router/option/base_namespace'));
		}
		$base_namespace = trim(App::init()->config->get('router/option/base_namespace'), '\\');
		$uri = $_SERVER['REQUEST_URI'];
		//去除文件
		$result = $this->_parseUri($uri);
		$this->_module = $result['module'];
		$this->_controller = $result['controller'];
		$this->_action = $result['action'];
		$params = $result['params'];
		$ns_space = $base_namespace;
		if ($this->_module) {
		    $ns_space = $ns_space. '\\'. ucfirst($this->_module);
		}
		$ns_space = $ns_space. '\\'. ucfirst($this->_controller);
		$this->_namespace = $ns_space;
		//请求数据初始化完成
		Request::setData($params);
		Request::setReady(true);	
	}

    /**
     * Routing path distribution
     *
     * @return void
     * @throws \ReflectionException
     */
	public function dispatch()
	{
		$ns_space = $this->_namespace;
		if (!class_exists($ns_space)) {
			throw new ControllerNotFoundException(Language::get('router.controller_not_found', $ns_space));
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
		$action = $this->_action;
		$option = App::init()->config->get('router/option');
		$auto_method = self::$_auto_method;
        if (isset($option['auto_method'])) {
            $auto_method = $option['auto_method'];
        }
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
     * @param $uri
     * @return array
     */
	private function _parseUri($uri)
	{
		$config = App::init()->config->get('router/option');
		//去除pathinfo模式时的文件名称
		$script_name = basename($_SERVER['SCRIPT_FILENAME']);
		$uri = preg_replace('~/'. $script_name. '~i', '', $uri);
		//如果为空url串，则返回默认值
		if ($uri == '' || $uri == '/') {
			$module = '';
			if (self::$_module_support) {
				$module = self::$_default_module;
			}
			$controller = self::$_default_controller;
			$action = self::$_default_action;
			if (isset($config['default_controller'])) {
				$controller = $config['default_controller'];
			}
			if (isset($config['default_action'])) {
				$action = $config['default_action'];
			}
			return [
				'module'=> $module,
				'controller'=> $controller,
				'action'=> $action,
				'params'=> []
			];
		}
		$url_suffix = self::$_url_suffix;
		if (isset($config['url_suffix'])) {
			$url_suffix = $config['url_suffix'];
		}
		//
		$query = '';
		$pos = strpos($uri, "?");
		if ($pos !== false) {
			$query = substr($uri, $pos+1);
			$uri = substr($uri, 0, $pos);
		}
		$uri = trim($this->_rewrite($uri), '/');
		$uri = preg_replace('~'. $url_suffix. '$~i', '', $uri);
		$uri_items = explode('/', $uri);
		$module = '';
		if (self::$_module_support) {
			$module = array_shift($uri_items);
		}
		$controller = array_shift($uri_items);
		if ($controller == '') {
			$controller = self::$_default_controller;
		}
		$action = array_shift($uri_items);
		if ($action == '') {
			$action = self::$_default_action;
		}
		$result = [];
		if (count($uri_items) > 0) {
			$uri_items = array_chunk($uri_items, 2);
			foreach ($uri_items as $key=> $val) {
				$result[$val[0]] = $val[1];
			}
		}
		if ($query != '') {
			$query = explode('&', $query);
			foreach ($query as $val) {
				$val = explode('=', $val);
				$result[$val[0]] = $val[1];
			}
		}
		if (isset($result['_m'])) {
			$module = $result['_m'];
			unset($result['_m']);
		}
		if (isset($result['_c'])) {
			$controller = $result['_c'];
			unset($result['_c']);
		}
		if (isset($result['_a'])) {
			$action = $result['_a'];
			unset($result['_a']);
		}
		return [
			'module'=> $module,
			'controller'=> $controller,
			'action'=> $action,
			'params'=> $result
		];
	}

    /**
     *
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
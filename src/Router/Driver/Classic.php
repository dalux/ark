<?php

namespace Brisk\Router\Driver;

use Brisk\Kernel\App;
use Brisk\Kernel\Language;
use Brisk\Kernel\Request;
use Brisk\Router\RouterFather;
use Brisk\Exception\ControllerException;
use Brisk\Exception\RouterException;
use Brisk\Exception\ConfigurationException;
use Brisk\Exception\ActionNotFoundException;

class Classic extends RouterFather
{

    /**
     * @var bool
     */
	private $_module_support = false;

    /**
     * @var array
     */
	private $_rules = [];

    /**
     * @var string
     */
	private $_auto_method = '__init';

    /**
     * @var string
     */
	private $_default_module = 'Index';

    /**
     * @var string
     */
	private $_default_controller = 'Index';

    /**
     * @var string
     */
	private $_default_action = 'index';

    /**
     * @var string
     */
	private $_url_suffix = '.html';

    /**
     * @var array
     */
	private $_interceptors = [];

    /**
     * @var string
     */
	private $_request;

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
     * @return Classic
     */
	public function openModuleSupport($default_module = null)
	{
		$this->_module_support = true;
		if ($default_module) {
			$this->_default_module = $default_module;
		}
		return $this;
	}

    /**
     * 获取当前请求URI
     *
     * @return string
     */
	public function getRequest()
    {
        return $this->_request;
    }

    /**
     * 设置当前请求URI
     *
     * @param $request
     * @return $this
     */
    public function setRequest($request)
    {
        $this->_request = $request;
        return $this;
    }

    /**
     * 获取当前请求对应的类命名空间
     *
     * @return string
     */
    public function getNameSpace()
    {
        return $this->_namespace;
    }

    /**
     * Adding routing rewriting rules
     *
     * @param string $rule
     * @param mixed $redirect
     * @return Classic
     */
	public function addRule($rule, callable $redirect)
	{
		$this->_rules[$rule] = $redirect;
		return $this;
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
        $request = '/'. $this->_controller. '/'. $this->_action;
		$params = $result['params'];
        $namespace = $base_namespace;
		if ($this->_module) {
            $namespace = $namespace. '\\'. ucfirst($this->_module);
		    $request = '/'. $this->_module. $request;
		}
        $this->setRequest($request);
        $namespace = $namespace. '\\'. ucfirst($this->_controller);
		$this->_namespace = $namespace;
		//请求数据初始化完成
        Request::ready($params);
	}

    /**
     * Routing path distribution
     *
     * @return string
     * @throws \ReflectionException
     */
	public function dispatch()
	{
		$namespace = $this->_namespace;
        //是否被保护对象
        $ref = new \ReflectionClass($namespace);
        if ($ref->isAbstract()) {
            throw new ControllerException(Language::get('router.controller_is_protected', $namespace));
        }
        //实例化最终控制器对象
		$instance = new $namespace();
		$action = $this->_action;
        if (!method_exists($instance, $action)) {
            throw new ActionNotFoundException(Language::get('router.action_not_found', $action));
        }
        $output = null;
		//自动化类
		$option = App::init()->config->get('router/option');
		$auto_method = $this->_auto_method;
        if (isset($option['auto_method'])) {
            $auto_method = $option['auto_method'];
        }
        if (method_exists($instance, $auto_method)) {
			$output = $instance->$auto_method();
			if (!is_null($output)) {
				return $output;
			}
		}
        //目标控制器行为
        return $instance->$action();
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
			if ($this->_module_support) {
				$module = $this->_default_module;
			}
			$controller = $this->_default_controller;
			$action = $this->_default_action;
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
		$url_suffix = $this->_url_suffix;
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
		if ($this->_module_support) {
			$module = array_shift($uri_items);
		}
		$controller = array_shift($uri_items);
		if ($controller == '') {
			$controller = $this->_default_controller;
		}
		$action = array_shift($uri_items);
		if ($action == '') {
			$action = $this->_default_action;
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
		isset($result['_m']) && $module = $result['_m'];
		isset($result['_c']) && $controller = $result['_c'];
		isset($result['_a']) && $action = $result['_a'];
		unset($result['_m'], $result['_c'], $result['_a']);
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
        foreach ($this->_rules as $key=> $val) {
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
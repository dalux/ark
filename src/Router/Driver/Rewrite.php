<?php

namespace Brisk\Router\Driver;

use Brisk\Kernel\App;
use Brisk\Kernel\Event;
use Brisk\Kernel\Language;
use Brisk\Kernel\Request;
use Brisk\Kernel\Server;
use Brisk\Router\RouterFather;
use Brisk\Exception\ControllerException;
use Brisk\Exception\RouterException;
use Brisk\Exception\ConfigurationException;
use Brisk\Exception\ActionNotFoundException;

class Rewrite extends RouterFather
{

    /**
     * @var string
     */
    private $_namespace;

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
     * 获取当前控制器类命名空间
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
     * @param callable $redirect
     * @return Rewrite
     */
    public function addRule($rule, callable $redirect)
    {
        $this->_rules[$rule] = $redirect;
        return $this;
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
        $controller = $this->_default_controller;
        if (isset($option['default_controller'])) {
            $controller = $option['default_controller'];
            if ($uri == '/') {
                $uri = '/'. strtolower($option['default_controller']);
            }
        }
        $controller = ucfirst($controller);
        $url_suffix = $this->_url_suffix;
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
        $this->setRequest($uri);
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
        $namespace = $base_namespace. '\\'. $controller;
        $this->_namespace = $namespace;
        //请求数据初始化完成
        Request::ready($_GET);
    }

    /**
     * Routing path distribution
     *
     * @return string
     * @throws \ReflectionException
     */
    public function dispatch()
    {
        $option = App::init()->config->get('router/option');
        $action = $this->_default_action;
        $auto_method = $this->_auto_method;
        if (isset($option['default_action'])) {
            $action = $option['default_action'];
        }
        if (isset($option['auto_method'])) {
            $auto_method = $option['auto_method'];
        }
        $namespace = $this->_namespace;
        //是否被保护对象
        $ref = new \ReflectionClass($namespace);
        if ($ref->isAbstract()) {
            throw new ControllerException(Language::get('router.controller_is_protected', $namespace));
        }
        //实例化最终控制器对象
        $instance = new $namespace();
        $data = [
            'instance'      => $instance,
            'action'        => $action,
            'auto_method'   => $auto_method,
        ];
        $data = Event::trigger('event.router.dispatch', $data);
        $action = $data['action'];
        $auto_method = $data['auto_method'];
        if (!method_exists($instance, $action)) {
            throw new ActionNotFoundException(Language::get('router.action_not_found', $action));
        }
        $output = null;
        //自动化类
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
<?php

namespace Brisk\Assembly;

use Brisk\Contract\IRouter;
use Brisk\Exception\CoreException;
use Brisk\Exception\EventException;

class Core
{

    /**
     * 框架名称
    /**
     * 应用名称
     *
     * @var string
     */
    private static $_app_name;

    /**
     * 配置文件获取器
     *
     * @var array
     */
    private static $_config_path = array();

    /**
     * 应用目录
     *
     * @var string
     */
    private static $_app_path;

    /**
     * 控制器根目录
     *
     * @var string
     */
    private static $_controller_path;

    /**
     * 框架是否就绪
     *
     * @var bool
     */
    private static $_inited = false;

    /**
     * 唯一实例
     *
     * @var Engine
     */
    private static $_instance;
	
    /**
     * 存储区
     *
     * @var array
     */
    private static $_storage = array();

    /**
     * 私有构造方法
     *
     */
    private function __construct() {}

    /**
     * 设置应用程序集根命名空间及其基本路径
     *
     * @param string $name
     * @param array $option
     */
    static function setApp($name, $option = array())
    {
        self::$_app_name = $name;
        isset($option['app_path']) && self::$_app_path = rtrim($option['app_path'], '/\\');
        isset($option['config_path']) && self::$_config_path = $option['config_path'];
        isset($option['controller_path']) && self::$_controller_path = rtrim($option['controller_path'], '/\\');
    }

    /**
     * 获取app相关数据
     *
     * @param null $item
     * @return array
     */
    static function getAppInfo($item = null)
    {
        $info = array(
            'app_name'          => self::$_app_name,
            'app_path'          => self::$_app_path,
            'config_path'       => self::$_config_path,
            'controller_path'   => self::$_controller_path,
        );
        return is_null($item) ? $info : $info[$item];
    }

    /**
     * 框架准备
     *
     */
    static function init()
    {

		if (!self::$_inited) {
            //初始化内存占用
            $memory_usage = memory_get_usage();
            //引入必要文件
			require_once __DIR__. '/Timer.php';
			require_once __DIR__. '/Trace.php';
			require_once __DIR__. '/Loader.php';
			require_once __DIR__. '/Toolkit.php';
			require_once __DIR__. '/Handler.php';
			require_once __DIR__. '/Request.php';
			require_once __DIR__. '/Event.php';
			require_once __DIR__. '/Container.php';
            require_once __DIR__. '/Server.php';
            require_once __DIR__. '/Language.php';
            require_once __DIR__. '/../Exception/CoreException.php';
            //框架变量实例
			self::$_instance = new self();
			//默认屏蔽错误提示
			ini_set('display_errors', '1');
			//启动时间
			Timer::mark('sys_startup');
			//初始内存占用数
			Trace::set('memory', $memory_usage);
			//配置项默认为空对象
			self::$_storage['config'] = array(
				'instance'=> new Container(),
				'system'=> 1
			);
			//定义常量
			$debug_trace = debug_backtrace();
			defined('PATH_LIB') || define('PATH_LIB', dirname(__DIR__));
			defined('PATH_WEB') || define('PATH_WEB', dirname($debug_trace[0]['file']));
			//注册框架类库基地址
			Loader::setNameSpace('Brisk', PATH_LIB);
			//语言包
            Language::addPackage(Loader::realPath('*/Language'));
			//异常报告
			Handler::setHandler(Handler::TYPE_EXCEPTION);
			//后续类文件自动加载
			Loader::addAutoLoader(array('Brisk\Assembly\Loader', 'autoLoad'));
			//初始化CLI模式
			Server::isCli() && Server::initCli();
			//注册内置组件
			self::$_storage['container'] = array(
				'instance'=> function() { return new Container(); },
				'system'=> 1,
			);
			self::$_storage['response'] = array(
				'instance'=> function() { return new Response(); },
				'system'=> 1,
			);
		}
        //准备就绪
        self::$_inited = true;

    }

    /**
     * 取实例化对象
     *
     * @access public
     * @return Engine
     */
    static function getInst()
    {
        return self::$_instance;
    }

    /**
     * 启动框架
     *
     * @access public
     * @return mixed
     * @throws CoreException
     * @throws EventException
     */
    static function start()
    {
        //检测必要应用配置
        if (!self::$_app_name) {
            throw new CoreException(Language::get('core.invalid_app_name'));
        }
        self::$_app_path || self::$_app_path = PATH_WEB;
        if (!is_dir(self::$_app_path)) {
            throw new CoreException(Language::get('core.invalid_app_path'));
        }
        //注册应用程序基地址
        Loader::setNameSpace(self::$_app_name, self::$_app_path);
        Loader::setAlias('@', self::$_app_path);
        defined('PATH_APP') || define('PATH_APP', self::$_app_path);
        //配置文件
        $config = array();
        //如果配置文件目录是匿名函数
        if (self::$_config_path instanceof \Closure) {
            $getter = self::$_config_path;
            $config_path = (string)$getter();
        } else {
            $config_path = self::$_config_path;
        }
        //如果是目录
        if (is_dir($config_path)) {
            $config_files = glob($config_path . '/*.php');
            foreach ($config_files as $file) {
                $result = include($file);
                if (!is_array($result)) {
                    throw new CoreException(Language::get('core.invalid_config_format', basename($file)));
                }
                $key = strtolower(basename($file));
                $key = preg_replace('/\.php$/', '', $key);
                $config[$key] = $result;
            }
        } elseif (is_file($config_path)) {  //是文件
            $config = include($config_path);
            if (!is_array($config)) {
                throw new CoreException(Language::get('core.invalid_config_format', basename($config_path)));
            }
        }
        if (!$config) {
            throw new CoreException(Language::get('core.invalid_configuration'));
        }
        self::$_storage['config']['instance'] = new Container($config);
        //控制器地址检测
        if (!self::$_controller_path) {
            self::$_controller_path = self::$_app_path . DIRECTORY_SEPARATOR . 'Controller';
        }
        defined('PATH_CTRL') || define('PATH_CTRL', self::$_controller_path);
        //时区设置
        $timezone = 'Asia/Shanghai';
        $instance = self::$_storage['config']['instance'];
        if ($instance->global->timezone) {
            $timezone = $instance->global->timezone;
        }
        date_default_timezone_set($timezone);
        //错误报告
        if (!is_null($instance->global->error_reporting)) {
            ini_set('display_errors', '1');
            error_reporting($instance->global->error_reporting);
        }
        //路由
        self::$_storage['router'] = array(
            'instance'=>  function() { return Engine::getRouterDriver(); },
            'system'=> 1,
        );
        //监听系统启动就绪事件
        Event::onListening('event.framework.ready');
        if (!self::$_instance->router instanceof IRouter) {
            $lang = Language::get('router.driver_implement_error', get_class(self::$_instance->router), '\Brisk\Contract\IRouter');
            throw new CoreException($lang);
        }
        //路由调度准备
        self::$_instance->router->ready();
        //路由准备就绪
        Event::onListening('event.router.ready');
        //路由并呈现控制器内容
        self::$_instance->router->dispatch();
    }

    /**
     * 设值
     *
     * @param $name
     * @param $value
     */
    static function set($name, \Closure $value)
    {
        if (!isset(self::$_storage[$name])
                || !self::$_storage[$name]['system']) {
            self::$_storage[$name] = array('instance'=> $value, 'system'=> 0);
        }
    }

    /**
     * 取值
     *
     * @param $name
     * @return mixed
     * @throws CoreException
     */
    function get($name)
    {
        //常规取值
        if (!$instance = self::$_storage[$name]['instance']) {
            throw new CoreException(Language::get('core.object_not_found', $name));
        } elseif ($instance instanceof \Closure && is_callable($instance)) {    //支持匿名函数
            if (!$instance = $instance()) {
                throw new CoreException(Language::get('core.invlid_custom_member', $name));
            }
            self::$_storage[$name]['instance'] = $instance;
        }
        return $instance;
    }

    /**
     * 魔术方法取值
     *
     * @param $name
     * @return mixed
     * @throws CoreException
     */
    function __get($name)
    {
        return $this->get($name);
    }

    /**
     * 析构函数
     *
     * @return null
     * @throws EventException
     */
    function __destruct()
    {
        //结束时间点
        Timer::mark('sys_shutdown');
        //内存占用
        Trace::set('memory', memory_get_usage());
        //结束事件
        Event::onListening('event.framework.shutdown');
    }

}
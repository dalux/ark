<?php

namespace Brisk\Kernel;

use Brisk\Router\RouterFather;
use Brisk\Router\RouterAdapter;
use Brisk\Exception\RuntimeException;
use Brisk\Exception\RouterException;
use Brisk\Exception\ConfigurationException;

class App
{

    const NAME		= 'Brisk';
    const AUTHOR	= 'guodalu <112183883@qq.com>';
    const VERSION	= '1.0.0';

    /**
     * @var App
     */
	private static $_instance;

    /**
     * @var array
     */
	private static $_storage = [];

	private static $_methods = [];

    /**
     * 插件目录
     *
     * @var array
     */
	private $_plugin_dir = [];

    /**
     * Construct
     *
     * @return null
     */
    private function __construct() {}

    /**
     * Get current object instance
     *
     * @return App
     */
    public static function init()
    {
        //版本检查
        if (version_compare(phpversion(), '5.6.0') < 0) {
            echo 'php version is too low, please use php5.6 and above version'. PHP_EOL;
            exit;
        }
        if (is_null(self::$_instance)) {
            require __DIR__. '/Loader.php';
            require __DIR__. '/Trace.php';
            require __DIR__. '/Timer.php';
            require __DIR__. '/Event.php';
            require __DIR__. '/Language.php';
            require __DIR__. '/Container.php';
            require __DIR__. '/ExceptionHandler.php';
            //默认错误提示
            ini_set('display_errors', '1');
            //框架变量实例
            self::$_instance = new self();
            //配置项默认为空对象
            self::$_storage['config'] = [
                'instance'=> new Container(),
                'system'=> 1
            ];
            Loader::setAlias('*', dirname(__DIR__));
            Loader::addNameSpace('Brisk', dirname(__DIR__));
            $handler = new ExceptionHandler();
            self::$_instance->setExceptionHandler([$handler, 'display']);
        }
        return self::$_instance;
    }

    /**
     * Set directory path aliases
     *
     * @param string alias
     * @param string path
     * @return App
     */
    public function setAlias($alias, $path)
    {
        Loader::setAlias($alias, $path);
        return $this;
    }

    /**
     * 设置异常处理句柄
     * 
     * @param callable $handler
     * @return App
     */
    public function setExceptionHandler(callable $handler)
    {
        restore_exception_handler();
        set_exception_handler(function($e) use ($handler) {
            $result = call_user_func_array($handler, array($e));
            echo $result;
        });
        return $this;
    }

    /**
     * Set namespace path
     *
     * @param string nspace
     * @param string path
     * @return App
     */
    public function addNameSpace($name, $path)
    {
        Loader::addNameSpace($name, $path);
        return $this;
    }

    /**
     * Set the system language pack file
     *
     * @param string language
     * @param string path
     * @return App
     */
    public function addLanguageFile($language, $path)
    {
        Language::addPackageFile($language, $path);
        return $this;
    }

    /**
     * 添加插件文件目录
     *
     * @param $path
     * @return $this
     */
    public function addPluginDir($path)
    {
        $this->_plugin_dir[] = $path;
        return $this;
    }

    /**
     * Setting the system language
     *
     * @param string language
     * @return App
     */
    public function setLanguage($language)
    {
        Language::setLanguage($language);
        return $this;
    }

    /**
     * Adding event listener
     *
     * @param string event
     * @param callable listener
     * @return App
     */
	public function addEvent($event, callable $listener)
	{
        Event::add($event, $listener);
        return $this;
	}

    /**
     * Start the application
     *
     * @param callable $config
     * @return string
     */
    public function runAs(callable $config)
    {
        //后续类文件自动加载
        spl_autoload_register(['\\Brisk\\Kernel\\Loader', 'autoLoad']);
        //初始化CLI模式
        if (Server::isCli()) Server::initCli();
        //配置文件
        $config = call_user_func_array($config, []);
        if (!is_array($config)) {
            throw new ConfigurationException(Language::get('core.invalid_configuration'));
        }
        $instance = new Container($config);
        //时区设置
        $timezone = 'Asia/Shanghai';
        if ($instance->hasKey('global/timezone')) {
            $timezone = $instance->get('global/timezone');
        }
        date_default_timezone_set($timezone);
        //错误报告
        if ($instance->haskey('global/error_reporting')) {
            error_reporting($instance->get('global/error_reporting'));
        }
        self::$_storage['config']['instance'] = $instance;
        //默认插件目录
        $this->_plugin_dir[] = Loader::realPath('*/Plugin');
        //加载插件
        foreach ($this->_plugin_dir as $plugin_dir) {
            $register = $plugin_dir. '/Register.php';
            if (is_file($register)) {
                include_once($register);
            } else {
                $files = glob($plugin_dir. '/*/Register.php');
                foreach ($files as $file) {
                    include_once($file);
                }
            }
        }
        //监听系统启动就绪事件
        Event::trigger('event.framework.ready');
        //路由
        self::$_storage['router'] = [
            'instance'=> RouterAdapter::getDriverFromConfig(),
            'system'=> 1
        ];
        if (!$this->getObject('router') instanceof RouterFather) {
            $lang = Language::get('core.class_extends_error', get_class($this->getObject('router')), '\\Brisk\\Router\\RouterFather');
            throw new RouterException($lang);
        }
        //路由调度准备
        $this->getObject('router')->ready();
        //路由准备就绪
        Event::trigger('event.router.ready');
        //路由并呈现控制器内容
        return $this->getObject('router')->dispatch();
    }

    /**
     * Set up custom singleton components
     *
     * @param string name
     * @param callable value
     * @return App
     */
    public function setObject($name, callable $value)
    {
        if (!isset(self::$_storage[$name])
                || !self::$_storage[$name]['system']) {
            self::$_storage[$name] = ['instance'=> $value, 'system'=> 0];
        }
        return $this;
    }

    /**
     * 设置自定义方法
     *
     * @param $name
     * @param callable $method
     * @return App
     */
    public function setMethod($name, callable $method)
    {
        if (!isset(self::$_methods[$name])
                || !isset(self::$_methods[$name]['system'])) {
            self::$_methods[$name] = ['method'=> $method, 'system'=> 0];
        }
        return $this;
    }

    /**
     * get custom singleton components
     *
     * @param string name
     * @return object
     */
    public function getObject($name)
    {
        $instance = self::$_storage[$name]['instance'];
        if (is_null($instance)) {
            throw new RuntimeException(Language::get('core.object_not_found', $name));
        } elseif (is_callable($instance)) {
            if (!$instance = call_user_func_array($instance, [])) {
                throw new RuntimeException(Language::get('core.invlid_custom_member', $name));
            }
            self::$_storage[$name]['instance'] = $instance;
        }
        return $instance;
    }

    /**
     * 调用自定义方法
     *
     * @param $name
     * @param array $args
     * @return mixed
     */
    public function callMethod($name, array $args)
    {
        $method = self::$_methods[$name]['method'];
        if (is_null($method)) {
            throw new RuntimeException(Language::get('core.method_not_found', $name));
        }
        if (!isset(self::$_methods[$name]['result'])) {
            self::$_methods[$name]['result'] = [];
        }
        $args_key = md5(serialize($args));
        $result = self::$_methods[$name]['result'][$args_key];
        if (is_object($result) || is_resource($result)) {
            return $result;
        }
        $result = call_user_func_array($method, $args);
        if (is_object($result) || is_resource($result)) {
            self::$_methods[$name]['result'][$args_key] = $result;
        }
        return $result;
    }

    /**
     * Get custom singleton components
     *
     * @param string name
     * @return mixed
     */
    public function __get($name)
    {
        return $this->getObject($name);
    }

    /**
     * 魔术方法调用自定义方法
     *
     * @param $name
     * @param $args
     * @return mixed
     */
    public function __call($name, $args)
    {
        return $this->callMethod($name, $args);
    }

    /**
     * destruct
     *
     * @return null
     */
    public function __destruct()
    {
        Event::trigger('event.framework.shutdown');
    }

}
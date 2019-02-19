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
	private static $_storage = array();

    /**
     * Construct
     *
     * @return null
     */
    private function __construct()
    {
        require __DIR__. '/Handler.php';
        require __DIR__. '/Loader.php';
        require __DIR__. '/Trace.php';
        require __DIR__. '/Timer.php';
        require __DIR__. '/Event.php';
        require __DIR__. '/Language.php';
        require __DIR__. '/Container.php';
        //版本检查
        if (version_compare(phpversion(), '5.6.0') < 0) {
            echo 'php version is too low, please use php5.6 and above version'. PHP_EOL;
            exit;
        }
        //启动时间
        Timer::mark('sys_startup');
        //初始内存占用数
        Trace::set('memory', memory_get_usage());
        //默认错误提示
        ini_set('display_errors', '1');
    }

    /**
     * Get current object instance
     *
     * @param string $dirname
     * @return App
     */
    public static function init($dirname = null)
    {
        if (is_null(self::$_instance)) {
            //框架变量实例
            self::$_instance = new self();
            //配置项默认为空对象
            self::$_storage['config'] = [
                'instance'=> new Container(),
                'system'=> 1
            ];
            Loader::setAlias('*', dirname(__DIR__));
            Loader::setNameSpace('Brisk', dirname(__DIR__));
            //异常报告
            Handler::setHandler();
            //后续类文件自动加载
            spl_autoload_register(['\\Brisk\\Kernel\\Loader', 'autoLoad']);
            //初始化CLI模式
            if (Server::isCli()) {
                Server::initCli();
            }
        }
        if (!is_null($dirname) 
                && !Loader::getAlias('.')
                && is_dir($dirname)) {
            Loader::setAlias('.', $dirname);
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
     * Set namespace path
     *
     * @param string nspace
     * @param string path
     * @return App
     */
    public function setNameSpace($name, $path)
    {
        Loader::setNameSpace($name, $path);
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
     * @return null
     */
    public function runAs(callable $config)
    {
        //配置文件
        $config = call_user_func_array($config, []);
        if (!is_array($config)) {
            throw new ConfigurationException(Language::get('core.invalid_configuration'));
        }
        $instance = new Container($config);
        //应用根目录检测
        if (!Loader::getAlias('.')) {
            throw new RuntimeException(Language::get('core.invalid_webroot_path'));
        }
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
        //路由
        self::$_storage['router'] = [
            'instance'=> RouterAdapter::getDriverFromConfig(),
            'system'=> 1
        ];
        //监听系统启动就绪事件
        Event::trigger('event.framework.ready');
        if (!$this->getObject('router') instanceof RouterFather) {
            $lang = Language::get('core.class_extends_error', get_class($this->getObject('router')), '\\Brisk\\Router\\RouterFather');
            throw new RouterException($lang);
        }
        //路由调度准备
        $this->getObject('router')->ready();
        //路由准备就绪
        Event::trigger('event.router.ready');
        //路由并呈现控制器内容
        $this->getObject('router')->dispatch();
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
     * destruct
     *
     * @return null
     */
    public function __destruct()
    {
        Timer::mark('sys_shutdown');
        Trace::set('memory', memory_get_usage());
        Event::trigger('event.framework.shutdown');
    }

}
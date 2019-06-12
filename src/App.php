<?php declare(strict_types=1);

namespace Brisk;

use Brisk\Http\Env;
use Brisk\Http\Router;
use Brisk\Http\Response;
use Brisk\Exception\RuntimeException;
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
    
    /**
     * Construct
     *
     * @return null
     */
    private function __construct()
    {
    }

    /**
     * 初始化
     */
    public static function init()
    {
        if (is_null(self::$_instance)) {
            require __DIR__. '/Exception/RuntimeException.php';
            require __DIR__. '/Http/Env.php';
            require __DIR__. '/Loader.php';
            require __DIR__. '/Container.php';
            require __DIR__. '/Exception.php';
            //初始化环境数据
            Env::init();
            //配置项默认为空对象
            self::$_storage['config'] = ['instance'=> new Container(), 'system'=> true];
            //异常处理
            self::setExceptionHandler([new Exception(), 'handler']);
            //版本检查
            if (version_compare(phpversion(), '7.2.0') < 0) {
                throw new RuntimeException('php version is too low, please use php7.2 and above version');
            }
            //默认错误提示
            ini_set('display_errors', '1');
            //后续类文件自动加载
            spl_autoload_register(['\\Brisk\\Loader', 'autoLoad']);
            //框架变量实例
            self::$_instance = new self();
            //框架路径别名
            Loader::setAlias('*', __DIR__);
            Loader::addNameSpace('Brisk', __DIR__);
        }
        return self::$_instance;
    }

    /**
     * 设置异常处理句柄
     * 
     * @param callable handler
     * @return void
     */
    public static function setExceptionHandler(callable $handler)
    {
        restore_exception_handler();
        set_exception_handler($handler);
    }

    /**
     * 设置错误处理句柄
     * 
     * @param callable handler
     * @return void
     */
    public static function setErrorHandler(callable $handler, int $type)
    {
        restore_error_handler();
        set_error_handler($handler, $type);
    }

    /**
     * Start the application
     *
     * @param callable config
     * @param bool return
     * @return mixed
     */
    public static function runAs(callable $config, bool $retval = false)
    {
        //配置文件
        $config = call_user_func_array($config, []);
        if (!is_array($config)) {
            throw new ConfigurationException(Language::format('core.invalid_configuration'));
        }
        $instance = new Container($config);
        //时区设置
        $timezone = 'Asia/Shanghai';
        if ($instance->hasKey('global/timezone')) {
            $timezone = $instance->global->timezone->value();
        }
        date_default_timezone_set($timezone);
        //错误报告
        if ($instance->haskey('global/error_reporting')) {
            error_reporting($instance->global->error_reporting->value());
        }
        self::$_storage['config']['instance'] = $instance;
        //监听系统启动就绪事件
        Event::fire('event.framework.ready');
        //路由
        self::$_storage['router'] = [
            'instance'  => new Router(),
            'system'    => true
        ];
        self::$_storage['response'] = [
            'instance'  => new Response(),
            'system'    => true
        ];
        $router = self::$_storage['router']['instance'];
        //路由调度准备
        $router->ready();
        $response = $router->dispatch();
        if ($retval) {
            return $response;
        }
        $response->send();
    }

    /**
     * Set up custom singleton components
     *
     * @param string name
     * @param callable value
     * @return void
     */
    public static function set(string $name, callable $value)
    {
        if (!isset(self::$_storage[$name]) 
                || !self::$_storage[$name]['system']) {
            self::$_storage[$name] = ['instance'=> value, 'system'=> false];
        }
    }

    /**
     * get custom singleton components
     *
     * @param string name
     * @return var
     */
    public static function get(string $name = null)
    {
        if (is_null($name)) {
            return self::$_storage;
        }
        $instance = self::$_storage[$name]['instance'];
        if (is_null($instance)) {
            throw new RuntimeException(Language::format('core.object_not_found', $name));
        }
        if (is_callable($instance)) {
            $instance = call_user_func_array($instance, []);
            if (!$instance) {
                throw new RuntimeException(Language::format('core.invlid_custom_member', $name));
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
    public function __get(string $name)
    {
        return $this->get($name);
    }

    /**
     * destruct
     *
     * @return void
     */
    public function __destruct()
    {
        Event::fire('event.framework.shutdown');
    }

}
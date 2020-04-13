<?php declare(strict_types=1);

namespace Brisk\Kernel;

use Brisk\Cache\CacheAdapter;
use Brisk\Cache\ICacheDriver;
use Brisk\Db\DbAdapter;
use Brisk\Db\IDbDriver;
use Brisk\Http\Env;
use Brisk\Http\Router;
use Brisk\Session\ISessionDriver;
use Brisk\Session\SessionAdapter;
use Brisk\View\IViewDriver;
use Brisk\View\ViewAdapter;
use Brisk\Exception\RuntimeException;

class App
{

    const NAME		= 'Brisk';
    const AUTHOR	= 'guodalu <112183883@qq.com>';
    const VERSION	= '1.0.0';

    /**
     * app对象实例
     *
     * @var App
     */
	private static $_instance;

    /**
     * 数据存储
     *
     * @var array
     */
    private static $_storage    = [];
    
    /**
     * 构造函数
     *
     * @access public
     * @return void
     */
    private function __construct()
    {
    }

    /**
     * 初始化
     *
     * @access public
     * @return App
     */
    public static function init()
    {
        if (is_null(self::$_instance)) {
            require dirname(__DIR__). '/Kernel/Loader.php';
            require dirname(__DIR__). '/Kernel/Container.php';
            require dirname(__DIR__). '/Kernel/Exception.php';
            require dirname(__DIR__). '/Http/Env.php';
            require dirname(__DIR__). '/Exception/RuntimeException.php';
            //框架路径别名
            Loader::setAlias('*', dirname(__DIR__));
            Loader::addNameSpace('Brisk', dirname(__DIR__));
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
            spl_autoload_register(['Brisk\Kernel\Loader', 'autoLoad']);
            //框架变量实例
            self::$_instance = new self();
        }
        return self::$_instance;
    }

    /**
     * 设置异常处理句柄
     *
     * @access public
     * @param callable $handler
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
     * @access public
     * @param callable $handler
     * @param int $type
     * @return void
     */
    public static function setErrorHandler(callable $handler, int $type)
    {
        restore_error_handler();
        set_error_handler($handler, $type);
    }

    /**
     * 开始运行
     *
     * @access public
     * @param callable $config
     * @return void
     * @throws \ReflectionException
     */
    public static function runAs(callable $config)
    {
        //配置文件
        $config = call_user_func_array($config, []);
        if (!is_array($config)) {
            throw new RuntimeException(Language::format('core.invalid_configuration'));
        }
        $instance = new Container($config);
        //时区设置
        $timezone = 'Asia/Shanghai';
        if ($instance->has('global/timezone')) {
            $timezone = $instance->global->timezone->value();
        }
        date_default_timezone_set($timezone);
        //错误报告
        if ($instance->has('global/error_reporting')) {
            error_reporting($instance->global->error_reporting->value());
        }
        self::$_storage['config']['instance'] = $instance;
        //监听系统启动就绪事件
        Event::fire('event.framework.ready');
        //路由
        Router::ready();
        if ($output = Router::dispatch()) {
            echo $output;
        }
    }

    /**
     * 设置单例对象
     *
     * @access public
     * @param string $name
     * @param mixed $value
     * @return void
     */
    public static function set(string $name, $value)
    {
        if (!isset(self::$_storage[$name]) 
                || !self::$_storage[$name]['system']) {
            self::$_storage[$name] = ['instance'=> $value, 'system'=> false];
        }
    }

    /**
     * 获取自定义对象实例
     *
     * @access public
     * @param string $name
     * @return mixed
     */
    public static function get(string $name)
    {
        if (!self::has($name)) {
            throw new RuntimeException(Language::format('core.object_not_found', $name));
        }
        $instance = self::$_storage[$name]['instance'];
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
     * 是否存在自定义对象实例
     *
     * @access public
     * @param string $name
     * @return bool
     */
    public static function has(string $name)
    {
        return isset(self::$_storage[$name]);
    }

    /**
     * 获取自定义对象实例
     *
     * @access public
     * @param string $name
     * @return mixed
     */
    public function __get(string $name)
    {
        return self::get($name);
    }

    /**
     * 析构函数
     *
     * @access public
     * @return void
     */
    public function __destruct()
    {
        Event::fire('event.framework.shutdown');
    }

}
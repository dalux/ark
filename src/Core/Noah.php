<?php

namespace Ark\Core;

use Closure;
use Ark\Com\Http\Server;
use Ark\Com\Http\Request;
use Ark\Com\Http\Response;
use Ark\Com\Cache\Driver\File as FileCache;
use Ark\Com\Event\Adapter as EventAdapter;
use Ark\Com\View\Adapter as ViewAdapter;
use Ark\Com\Session\Adapter as SessionAdapter;
use Ark\Com\Router\Adapter as RouterAdapter;

const Name = 'Ark';
const Version = '1.0';
const Eamil = 'guodalu <guodalu@qq.com>';

class Noah
{

    /**
     * 组件存储
     *
     * @var Container
     */
    private $_container;

    /**
     * 配置文件
     *
     * @var array
     */
    private $_config;

    /**
     * 配置文件获取器
     *
     * @var Closure
     */
    private $_config_dir;

    /**
     * 是否缓存配置项
     *
     * @var bool
     */
    private $_config_caching = false;

    /**
     * 配置项缓存目录
     *
     * @var string
     */
    private $_config_cache_dir = '';

    /**
     * 预处理逻辑
     *
     * @var string
     */
    private $_prepare = array();

    /**
     * 应用名称
     *
     * @var string
     */
    private $_app_name;

    /**
     * 控制器根目录
     *
     * @var string
     */
    private $_controller_dir;

    /**
     * 唯一实例
     *
     * @var Noah
     */
    private static $_instance;

    /**
     * 取实例化对象
     *
     * @access public
     * @return Noah
     */
    static function getInstance()
    {
        if (is_null(self::$_instance)) {
            self::$_instance = new self();
        }
        return self::$_instance;
    }

    /**
     * 私有构造方法
     *
     */
    private function __construct()
    {
        require_once __DIR__. '/Container.php';
        require_once __DIR__. '/Timer.php';
        require_once __DIR__. '/Exception.php';
        require_once __DIR__. '/RuntimeException.php';
        require_once __DIR__. '/Trace.php';
        require_once __DIR__. '/Loader.php';
        require_once __DIR__. '/Spanner.php';
        require_once __DIR__. '/../Com/Http/Request.php';
        //初始化内存占用
        $memory_usage = memory_get_usage();
        //默认显示错误提示
        ini_set('display_errors', '1');
        error_reporting(E_ALL^E_NOTICE^E_WARNING^E_DEPRECATED);
        //全局容器
        $this->_container = new Container();
        //启动时间
        Timer::mark('sys_startup');
        //初始内存占用数
        Trace::set('memory', $memory_usage);
        //配置项默认为空对象
        $this->_config = new Container();
        //定义常量
        $debug_trace = debug_backtrace();
        defined('PATH_LIB') || define('PATH_LIB', dirname(__DIR__));
        defined('PATH_APP') || define('PATH_APP', dirname($debug_trace[1]['file']));
    }

    /**
     * 配置文件缓存目录
     *
     * @param string $path
     * @return $this
     */
    function setConfigDir($path)
    {
        $this->_config_dir = $path;
        return $this;
    }

    /**
     * 缓存配置数据
     *
     * @param null $save_path
     * @return $this
     */
    function cacheConfigTo($save_path = null)
    {
        $this->_config_caching = true;
        $this->_config_cache_dir = $save_path;
        return $this;
    }

    /**
     * 设置应用程序集根命名空间及其基本路径
     *
     * @param string $name
     * @return $this
     */
    function setAppName($name)
    {
        $this->_app_name = $name;
        return $this;
    }

    /**
     * 获取App名称
     *
     * @return string
     */
    function getAppName()
    {
        return $this->_app_name;
    }

    /**
     * 获取应用根目录地址
     *
     * @return string
     */
    function getAppDir()
    {
        return PATH_APP;
    }

    /**
     * 设置控制器根目录
     *
     * @param $controller_dir
     * @return $this
     */
    function setControllerDir($controller_dir)
    {
        $this->_controller_dir = $controller_dir;
        return $this;
    }

    /**
     * 获取控制器根目录地址
     *
     * @return string
     */
    function getControllerDir()
    {
        return $this->_controller_dir;
    }

    /**
     * 预处理逻辑
     *
     * @param Closure $prepare
     * @return $this
     */
    function addPrepare(Closure $prepare = null)
    {
        if (is_callable($prepare)) {
            $this->_prepare[] = $prepare;
        }
        return $this;
    }

    /**
     * 获取配置信息
     *
     * @return array|mixed
     * @throws RuntimeException
     */
    function getConfig()
    {
        //获取配置文件目录
        $config_path = '';
        //如果配置文件目录是匿名函数
        if ($this->_config_dir instanceof Closure) {
            $getter = $this->_config_dir;
            $result = (string)$getter();
            if (is_dir($result)) {
                $config_path = $result;
            }
        } elseif (is_dir($this->_config_dir)) {
            $config_path = $this->_config_dir;
        }
        if (!$config_path) {
            throw new RuntimeException($this->language->get('core.invalid_config_dir'));
        }
        //如果配置文件允许缓存
        $config = array();
        if ($this->_config_caching) {
            //默认配置文件缓存目录为WEB根目录
            $config_cache_dir = PATH_APP;
            //重新获取配置文件目录
            if (is_dir($this->_config_cache_dir)) {
                $config_cache_dir = $this->_config_cache_dir;
            }
            //取配置文件
            $cache = new FileCache($config_cache_dir, array('allow_format' => false));
            //取不到缓存则重获取并重新缓存之
            if (!$config = $cache->get(basename($config_path))) {
                $config_files = glob($config_path . '/*.php');
                foreach ($config_files as $file) {
                    $result = include($file);
                    $key = strtolower(basename($file));
                    $key = preg_replace('/\.php$/', '', $key);
                    if ($result) {
                        $config[$key] = $result;
                    }
                }
                $cache->set(basename($config_path), $config, 8640000);
            }
            unset($cache);
        } else {
            $config_files = glob($config_path . '/*.php');
            foreach ($config_files as $file) {
                $result = include($file);
                $key = strtolower(basename($file));
                $key = preg_replace('/\.php$/', '', $key);
                if ($result) {
                    $config[$key] = $result;
                }
            }
        }
        return $config;
    }

    /**
     * 启动框架
     *
     * @access public
     * @return Noah
     * @throws RuntimeException
     */
    function run()
    {
        //注册框架类库基地址
        Loader::setNameSpace('Ark', PATH_LIB);
        //语言包选择器
        $this->set('language', function() { return new Language(); });
        //异常报告
        Exception::setHandler();
        //后续类文件自动加载
        Loader::addAutoLoader(array('\\Ark\\Core\\Loader', 'autoLoad'));
        //初始化CLI模式
        Server::isCli() && Server::initCli();
        //检测必要应用配置
        if (!$this->_app_name) {
            throw new RuntimeException($this->language->get('core.invalid_app_property'));
        }
        //注册应用程序基地址
        Loader::setNameSpace($this->_app_name, PATH_APP);
        //配置文件
        if (!$config = $this->getConfig()) {
            throw new RuntimeException($this->language->get('core.invalid_configuration'));
        }
        $this->_config = new Container($config);
        //控制器地址检测
        if (!$this->_controller_dir) {
            $this->_controller_dir = PATH_APP . DIRECTORY_SEPARATOR . 'Controller';
        } elseif (strpos($this->_controller_dir, PATH_APP) === false) {
            throw new RuntimeException($this->language->get('core.invalid_controller_dir'));
        }
        //时区设置
        $timezone = 'Asia/Shanghai';
        if ($this->_config->global->timezone) {
            $timezone = $this->_config->global->timezone;
        }
        date_default_timezone_set($timezone);
        //错误报告
        if (!is_null($this->_config->global->show_error)) {
            ini_set('display_errors', $this->_config->global->show_error ? '1' : '0');
        }
        if (!is_null($this->_config->global->error_reporting)) {
            error_reporting($this->_config->global->error_reporting);
        }

        //注册内置组件
        $this
            ->set('response', function() { return new Response(); })
            ->set('request', function() { return Request::getInstance(); })
            ->set('view', function() { return ViewAdapter::getDriver(); })
            ->set('router', function() { return RouterAdapter::getDriver(); })
            ->set('session', function() { return SessionAdapter::getDriver(); });

        //外部组件加载
        $plugin_dir = $this->config->global->plugin_dir;
        if (is_dir($plugin_dir)) {
            if (is_file($custom_register = $plugin_dir. '/register.php')) {
                $list_plugins = include($custom_register);
                is_array($list_plugins) || $list_plugins = array();
            } else {
                $list_plugins = glob($plugin_dir . '/*/register.php');
            }
            $prepares = array();
            foreach ($list_plugins as $item) {
                $result = include($item);
                if ($result instanceof Closure) {
                    $prepares[] = $result;
                }
            }

            //合并为预处理程序
            $this->_prepare = array_merge($this->_prepare, $prepares);
        }

        //执行各个预处理
        if ($this->_prepare) {
            foreach ($this->_prepare as $val) {
                $val();
            }
        }

        //监听系统启动事件
        EventAdapter::onListening('event.ark.startup');

        echo $this->router->doAction($_SERVER['REQUEST_URI']);

    }

    /**
     * 设值
     *
     * @param $name
     * @param $value
     * @return Noah
     */
    function set($name, $value)
    {
        $denied = array('container', 'config');
        if (in_array($name, $denied)) {
            return $this;
        }
        $name = trim($name, '_');
        $name = "__base_{$name}__";
        $this->_container->$name = $value;
        return $this;
    }

    /**
     * 设置
     *
     * @param string $name
     * @param mixed $value
     * @return Noah
     */
    function __set($name, $value)
    {
        $this->set($name, $value);
    }

    /**
     * 取值
     *
     * @param $name
     * @return mixed
     * @throws RuntimeException
     */
    function get($name)
    {
        if (in_array($name, array('container', 'config'))) {
            $name = '_'. $name;
            return $this->$name;
        }
        $name = trim($name, '_');
        //常规取值
        $key = "__base_{$name}__";
        if (!$instance = $this->_container->$key) {
            throw new RuntimeException(sprintf($this->language->get('core.object_not_found'), $name));
        } elseif ($instance instanceof Closure && is_callable($instance)) {    //支持匿名函数
            $instance = $instance();
            if (!is_null($instance)) {
                $this->_container->$key = $instance;
            }
        }
        return $instance;
    }


    /**
     * 取组件
     *
     * @param string $name
     * @return mixed
     * @throws Exception
     */
    function __get($name)
    {
        return $this->get($name);
    }

    /**
     * 析构函数
     *
     * @return null
     */
    function __destruct()
    {
        //结束时间点
        Timer::mark('sys_shutdown');
        //内存占用
        Trace::set('memory', memory_get_usage());
        //结束事件
        EventAdapter::onListening('event.ark.shutdown');
    }

}


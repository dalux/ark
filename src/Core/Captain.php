<?php

namespace Ark\Core;

use Closure;
use Ark\Http\Server;
use Ark\Http\Request;
use Ark\Http\Response;
use Ark\View\Adapter as ViewAdapter;
use Ark\Cache\Driver\File as FileCache;
use Ark\Router\Adapter as RouterAdapter;
use Ark\Session\Adapter as SessionAdapter;

const Name      = 'Ark';
const Version   = '1.0';
const Eamil     = 'guodalu <guodalu@qq.com>';

class Captain
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
     * 应用目录
     *
     * @var string
     */
    private $_app_dir;

    /**
     * 钩子程序目录
     *
     * @var array
     */
    private $_hook_dir = array();

    /**
     * 控制器根目录
     *
     * @var string
     */
    private $_controller_dir;

    /**
     * 唯一实例
     *
     * @var $this
     */
    private static $_instance;

    /**
     * 取实例化对象
     *
     * @access public
     * @return Captain
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
        require_once __DIR__. '/Trace.php';
        require_once __DIR__. '/Loader.php';
        require_once __DIR__. '/Toolkit.php';
        require_once __DIR__. '/Handler.php';
        require_once __DIR__. '/../Http/Request.php';
        //初始化内存占用
        $memory_usage = memory_get_usage();
        //默认屏蔽错误提示
        ini_set('display_errors', '0');
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
     * @return Captain
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
     * @return Captain
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
     * @param null $dir
     * @return Captain
     */
    function setApp($name, $dir = null)
    {
        $this->_app_name = ucfirst($name);
        $dir || $dir = PATH_APP;
        $this->_app_dir = $dir;
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
        return $this->_app_dir;
    }

    /**
     * 添加钩子程序目录
     *
     * @param string $dir
     * @return Captain
     */
    function addHookDir($dir)
    {
        $this->_hook_dir[] = $dir;
        return $this;
    }

    /**
     * 获取钩子程序目录
     *
     * @return array
     */
    function getHookDir()
    {
        return $this->_hook_dir;
    }

    /**
     * 设置控制器根目录
     *
     * @param $controller_dir
     * @return Captain
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
     * @return Captain
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
     * @throws Exception
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
            throw new Exception($this->lang->get('core.invalid_config_dir'));
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
     * @return mixed
     * @throws Exception
     */
    function run()
    {
        //注册框架类库基地址
        Loader::setNameSpace('Ark', PATH_LIB);
        //语言包选择器
        $this->set('lang', function() { return new Language(); });
        //异常报告
        Handler::setHandler('exception');
        //后续类文件自动加载
        Loader::addAutoLoader(array('\\Ark\\Core\\Loader', 'autoLoad'));
        //初始化CLI模式
        Server::isCli() && Server::initCli();
        //检测必要应用配置
        if (!$this->_app_name) {
            throw new Exception($this->lang->get('core.invalid_app_name'));
        } elseif (!is_dir($this->_app_dir)) {
            throw new Exception($this->lang->get('core.invalid_app_dir'));
        }
        //注册应用程序基地址
        Loader::setNameSpace($this->_app_name, $this->_app_dir);
        Loader::setAlias('@', $this->_app_dir);
        //配置文件
        if (!$config = $this->getConfig()) {
            throw new Exception($this->lang->get('core.invalid_configuration'));
        }
        $this->_config = new Container($config);
        //控制器地址检测
        if (!$this->_controller_dir) {
            $this->_controller_dir = $this->_app_dir . DIRECTORY_SEPARATOR . 'Controller';
        } elseif (strpos($this->_controller_dir, $this->_app_dir) === false) {
            throw new Exception($this->lang->get('core.invalid_controller_dir'));
        }
        //时区设置
        $timezone = 'Asia/Shanghai';
        if ($this->_config->global->timezone) {
            $timezone = $this->_config->global->timezone;
        }
        date_default_timezone_set($timezone);
        //错误报告
        if (!is_null($this->_config->global->error_reporting)) {
            ini_set('display_errors', '1');
            error_reporting($this->_config->global->error_reporting);
        }

        //注册内置组件
        $this
            ->set('response', function() { return new Response(); })
            ->set('request', function() { return Request::getInstance(); })
            ->set('view', function() { return ViewAdapter::getDriver(); })
            ->set('router', function() { return RouterAdapter::getDriver(); })
            ->set('session', function() { return SessionAdapter::getDriver(); });

        //钩子程序加载
        $prepares = array();
        foreach ($this->_hook_dir as $hook_dir) {
            if (is_dir($hook_dir)) {
                //允许根目录定制钩子程序列表
                if (is_file($custom_register = $hook_dir. '/register.php')) {
                    $list_hooks = include($custom_register);
                    is_array($list_hooks) || $list_hooks = array();
                } else {  //自动加载每个子目录下对应的钩子注册程序
                    $list_hooks = glob($hook_dir . '/*/register.php');
                }
                foreach ($list_hooks as $item) {
                    $result = include($item);
                    if ($result instanceof Closure) {
                        $prepares[] = $result;
                    }
                }
            }
        }

        //合并为预处理程序
        if ($prepares) {
            $this->_prepare = array_merge($this->_prepare, $prepares);
        }

        //执行各个预处理
        if ($this->_prepare) {
            foreach ($this->_prepare as $val) {
                $val();
            }
        }

        //监听系统启动事件
        Event::onListening('event.ark.startup');

        //路由并呈现控制器内容
        echo $this->router->doAction($_SERVER['REQUEST_URI']);

    }

    /**
     * 设值
     *
     * @param $name
     * @param $value
     * @return Captain
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
     * @return Captain
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
     * @throws Exception
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
            throw new Exception(sprintf($this->lang->get('core.object_not_found'), $name));
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
        Event::onListening('event.ark.shutdown');
    }

}

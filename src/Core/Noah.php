<?php

namespace Ark\Core;

use Closure;
use Ark\Assembly\Router as RouterAdapter;
use Ark\Contract\Router as RouterInterface;

const Name      = 'Ark';
const Version   = '1.1';
const Eamil     = 'guodalu <guodalu@qq.com>';

class Noah
{

    /**
     * 存储区
     *
     * @var array
     */
    private $_storage = array();

    /**
     * 自定义方法体
     *
     * @var array
     */
    private $_method = array();

    /**
     * 配置文件获取器
     *
     * @var array
     */
    private $_config_path = array();

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
    private $_app_path;

    /**
     * 控制器根目录
     *
     * @var string
     */
    private $_controller_path;

    /**
     * 框架是否就绪
     *
     * @var bool
     */
    private $_ready = false;

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
        require_once __DIR__. '/Timer.php';
        require_once __DIR__. '/Exception.php';
        require_once __DIR__. '/Trace.php';
        require_once __DIR__. '/Loader.php';
        require_once __DIR__. '/Toolkit.php';
        require_once __DIR__. '/Handler.php';
        require_once __DIR__. '/Request.php';
        require_once __DIR__. '/Event.php';
        require_once __DIR__. '/Container.php';
    }

    /**
     * 配置文件缓存目录
     *
     * @param mixed $path
     * @return Noah
     */
    function setConfigPath($path)
    {
        $this->_config_path = $path;
        return $this;
    }

    /**
     * 设置应用程序集根命名空间及其基本路径
     *
     * @param string $name
     * @param null $path
     * @return Noah
     */
    function setApp($name, $path = null)
    {
        $this->_app_name = $name;
        $path || $path = PATH_WEB;
        $this->_app_path = rtrim($path, '/\\');
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
    function getAppPath()
    {
        return $this->_app_path;
    }

    /**
     * 设置控制器根目录
     *
     * @param $controller_path
     * @return Noah
     */
    function setControllerPath($controller_path)
    {
        $this->_controller_path = rtrim($controller_path, '/\\');
        return $this;
    }

    /**
     * 获取控制器根目录地址
     *
     * @return string
     */
    function getControllerPath()
    {
        return $this->_controller_path;
    }

    /**
     * 获取配置信息
     *
     * @return array|mixed
     * @throws Exception
     */
    function getConfig()
    {
        $config = array();
        //如果未设置,默认使用应用程序目录config下的localhost.php配置文件
        if (!$this->_config_path) {
            $this->_config_path = function() {
                $path = Loader::realPath('./config');
                $host = Server::getDomain();
                $full = Server::getDomain(false);
                if (is_file($file = $path. '/'. $full. '.php')
                        || is_file($file = $path. '/'. $host. '.php')) {
                    return $file;
                }
                return $path. '/localhost.php';
            };
        }
        //如果配置文件目录是匿名函数
        if ($this->_config_path instanceof Closure) {
            $getter = $this->_config_path;
            $config_path = (string)$getter();
        } else {
            $config_path = $this->_config_path;
        }
        //如果是目录
        if (is_dir($this->_config_path)) {
            $config_files = glob($config_path . '/*.php');
            foreach ($config_files as $file) {
                $result = include($file);
                if (!is_array($result)) {
                    throw new Exception($this->lang->get('core.invalid_config_format', basename($file)));
                }
                $key = strtolower(basename($file));
                $key = preg_replace('/\.php$/', '', $key);
                if ($result) {
                    $config[$key] = $result;
                }
            }
        } elseif (is_file($config_path)) {
            $config = include($config_path);
            if (!is_array($config)) {
                throw new Exception($this->lang->get('core.invalid_config_format', basename($config_path)));
            }
        } else {
            throw new Exception($this->lang->get('core.invalid_config_path'));
        }
        return $config;
    }

    /**
     * 框架是否准备就绪
     *
     * @return bool
     */
    function isReady()
    {
        return $this->_ready;
    }

    /**
     * 框架准备
     *
     */
    function init()
    {
        //初始化内存占用
        $memory_usage = memory_get_usage();
        //默认屏蔽错误提示
        ini_set('display_errors', '0');
        //启动时间
        Timer::mark('sys_startup');
        //初始内存占用数
        Trace::set('memory', $memory_usage);
        //配置项默认为空对象
        $this->_storage['config'] = array(
            'instance'=> new Container(),
            'system'=> 1
        );
        //定义常量
        $debug_trace = debug_backtrace();
        defined('PATH_LIB') || define('PATH_LIB', dirname(__DIR__));
        defined('PATH_WEB') || define('PATH_WEB', dirname($debug_trace[1]['file']));
        //注册框架类库基地址
        Loader::setNameSpace('Ark', PATH_LIB);
        //语言包选择器
        $this->_storage['lang'] = array(
            'instance'=> function() { return new Language(); },
            'system'=> 1
        );
        //异常报告
        Handler::setHandler('exception');
        //后续类文件自动加载
        Loader::addAutoLoader(array('\Ark\Core\Loader', 'autoLoad'));
        //初始化CLI模式
        Server::isCli() && Server::initCli();
        //注册内置组件
        $this->_storage['container'] = array(
            'instance'=> function() { return new Container(); },
            'system'=> 1,
        );
        $this->_storage['response'] = array(
            'instance'=> function() { return new Response(); },
            'system'=> 1,
        );
        //准备就绪
        $this->_ready = true;
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
        if (!$this->_ready) {
            throw new Exception($this->lang->get('core.framework_not_ready'));
        }
        //检测必要应用配置
        if (!$this->_app_name) {
            throw new Exception($this->lang->get('core.invalid_app_name'));
        } elseif (!is_dir($this->_app_path)) {
            throw new Exception($this->lang->get('core.invalid_app_path'));
        }
        //注册应用程序基地址
        Loader::setNameSpace($this->_app_name, $this->_app_path);
        Loader::setAlias('@', $this->_app_path);
        defined('PATH_APP') || define('PATH_APP', $this->_app_path);
        //配置文件
        if (!$config = $this->getConfig()) {
            throw new Exception($this->lang->get('core.invalid_configuration'));
        }
        $this->_storage['config']['instance'] = new Container($config);
        //控制器地址检测
        if (!$this->_controller_path) {
            $this->_controller_path = $this->_app_path . DIRECTORY_SEPARATOR . 'Controller';
        } elseif (strpos($this->_controller_path, $this->_app_path) === false) {
            throw new Exception($this->lang->get('core.invalid_controller_path'));
        }
        defined('PATH_CTRL') || define('PATH_CTRL', $this->_controller_path);
        //时区设置
        $timezone = 'Asia/Shanghai';
        $instance = $this->_storage['config']['instance'];
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
        $this->_storage['router'] = array(
            'instance'=>  function() { return RouterAdapter::getDriver(); },
            'system'=> 1,
        );
        //监听系统启动就绪事件
        Event::onListening('event.framework.ready');

        if (!$this->router instanceof RouterInterface) {
            $lang = Noah::getInstance()->lang->get('router.driver_implement_error', get_class($this->router), '\\Ark\\Contract\\Router');
            throw new Exception($lang);
        }
        //路由调度准备
        $this->router->ready();
        //路由准备就绪
        Event::onListening('event.router.ready');
        //路由并呈现控制器内容
        $this->router->dispatch();
    }

    /**
     * 设值
     *
     * @param $name
     * @param $value
     * @return Noah
     */
    function setMember($name, $value)
    {
        if (!isset($this->_storage[$name])
                || !$this->_storage[$name]['system']) {
            $this->_storage[$name] = array('instance'=> $value, 'system'=> 0);
        }
        return $this;
    }

    /**
     * 设置自定义方法
     *
     * @param $name
     * @param callable $method
     * @return $this
     * @throws Exception
     */
    function setMethod($name, callable $method)
    {
        if (!is_callable($method)) {
            throw new Exception($this->lang->get('core.invalid_custom_method', $name));
        } elseif (!isset($this->_method[$name]) || !$this->_method[$name]['system']) {
            $this->_method[$name] = array('method' => $method, 'system' => 0);
        }
        return $this;
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
        //常规取值
        if (!$instance = $this->_storage[$name]['instance']) {
            throw new Exception($this->lang->get('core.object_not_found', $name));
        } elseif ($instance instanceof Closure && is_callable($instance)) {    //支持匿名函数
            $instance = $instance();
            if (!is_null($instance)) {
                $this->_storage[$name]['instance'] = $instance;
            }
        }
        return $instance;
    }

    /**
     * 魔术方法取值
     *
     * @param $name
     * @return mixed
     * @throws Exception
     */
    function __get($name)
    {
        return $this->get($name);
    }

    /**
     * 调用自定义方法
     *
     * @param $name
     * @param $args
     * @return mixed
     * @throws Exception
     */
    function call($name, $args)
    {
        if (!isset($this->_method[$name])) {
            throw new Exception($this->lang->get('core.custom_method_notfound', $name));
        }
        $method = $this->_method[$name]['method'];
        return call_user_func_array($method, $args);
    }

    /**
     * 魔术方法调用自定义方法
     *
     * @param $name
     * @param $args
     * @return mixed
     * @throws Exception
     */
    function __call($name, $args)
    {
        return $this->call($name, $args);
    }

    /**
     * 析构函数
     *
     * @return null
     * @throws Exception
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


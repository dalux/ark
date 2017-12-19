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
     * 配置文件获取器
     *
     * @var array
     */
    private $_config_path = array();

    /**
     * 预处理逻辑
     *
     * @var string
     */
    private $_prepare = array();

    /**
     * 自定义方法体
     *
     * @var array
     */
    private $_custom_method = array();

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
    private $_trigger_dir = array();

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
     * @return Noah
     */
    static function init()
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
        require_once __DIR__. '/Request.php';
        //初始化内存占用
        $memory_usage = memory_get_usage();
        //默认屏蔽错误提示
        ini_set('display_errors', '0');
        //启动时间
        Timer::mark('sys_startup');
        //初始内存占用数
        Trace::set('memory', $memory_usage);
        //配置项默认为空对象
        $this->_storage['config'] = new Container();
        //定义常量
        $debug_trace = debug_backtrace();
        defined('PATH_LIB') || define('PATH_LIB', dirname(__DIR__));
        defined('PATH_WEB') || define('PATH_WEB', dirname($debug_trace[1]['file']));
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
     * @param null $dir
     * @return Noah
     */
    function setApp($name, $dir = null)
    {
        $this->_app_name = $name;
        $dir || $dir = PATH_WEB;
        $this->_app_dir = rtrim($dir, '/\\');
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
     * @return Noah
     */
    function addTriggerDir($dir)
    {
        $this->_trigger_dir[] = $dir;
        return $this;
    }

    /**
     * 获取钩子程序目录
     *
     * @return array
     */
    function getTriggerDir()
    {
        return $this->_trigger_dir;
    }

    /**
     * 设置控制器根目录
     *
     * @param $controller_dir
     * @return Noah
     */
    function setControllerDir($controller_dir)
    {
        $this->_controller_dir = rtrim($controller_dir, '/\\');
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
     * @return Noah
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
        $this->_storage['lang'] = function() { return new Language(); };
        //异常报告
        Handler::setHandler('exception');
        //后续类文件自动加载
        Loader::addAutoLoader(array('\Ark\Core\Loader', 'autoLoad'));
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
        defined('PATH_APP') || define('PATH_APP', $this->_app_dir);
        //配置文件
        if (!$config = $this->getConfig()) {
            throw new Exception($this->lang->get('core.invalid_configuration'));
        }
        $this->_storage['config'] = new Container($config);
        //控制器地址检测
        if (!$this->_controller_dir) {
            $this->_controller_dir = $this->_app_dir . DIRECTORY_SEPARATOR . 'Controller';
        } elseif (strpos($this->_controller_dir, $this->_app_dir) === false) {
            throw new Exception($this->lang->get('core.invalid_controller_dir'));
        }
        defined('PATH_CTRL') || define('PATH_CTRL', $this->_controller_dir);
        //时区设置
        $timezone = 'Asia/Shanghai';
        if ($this->_storage['config']->global->timezone) {
            $timezone = $this->_storage['config']->global->timezone;
        }
        date_default_timezone_set($timezone);
        //错误报告
        if (!is_null($this->_storage['config']->global->error_reporting)) {
            ini_set('display_errors', '1');
            error_reporting($this->_storage['config']->global->error_reporting);
        }

        //注册内置组件
        $this
            ->setMember('container', function() { return new Container(); })
            ->setMember('response', function() { return new Response(); })
            ->setMember('router', function() { return RouterAdapter::getDriver(); });

        //钩子程序加载
        $prepares = array();
        foreach ($this->_trigger_dir as $trigger_dir) {
            if (is_dir($trigger_dir)) {
                //允许根目录定制钩子程序列表
                if (is_file($custom_register = $trigger_dir. '/register.php')) {
                    $list_triggers = include($custom_register);
                    is_array($list_triggers) || $list_triggers = array();
                } else {  //自动加载每个子目录下对应的钩子注册程序
                    $list_triggers = glob($trigger_dir . '/*/register.php');
                }
                foreach ($list_triggers as $item) {
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

        if (!$this->router instanceof RouterInterface) {
            $lang = Noah::init()->lang->get('router.driver_implement_error', get_class($this->router), '\\Ark\\Contract\\Router');
            throw new Exception($lang);
        }

        //路由调度准备
        $this->router->ready();

        //监听系统启动就绪事件
        Event::onListening('event.framework.ready');

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
        if (!in_array($name, array('config'))) {
            $this->_storage[$name] = $value;
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
    function getMember($name)
    {
        //常规取值
        if (!$instance = $this->_storage[$name]) {
            throw new Exception($this->lang->get('core.object_not_found', $name));
        } elseif ($instance instanceof Closure && is_callable($instance)) {    //支持匿名函数
            $instance = $instance();
            if (!is_null($instance)) {
                $this->_storage[$name] = $instance;
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
        return $this->getMember($name);
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
        }
        $this->_custom_method[$name] = $method;
        return $this;
    }

    /**
     * 调用自定义方法
     *
     * @param $name
     * @param $args
     * @return mixed
     * @throws Exception
     */
    function callMethod($name, $args)
    {
        if (!isset($this->_custom_method[$name])) {
            throw new Exception($this->lang->get('core.custom_method_notfound', $name));
        }
        $method = $this->_custom_method[$name];
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
        return $this->callMethod($name, $args);
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
        Event::onListening('event.framework.shutdown');
    }

}


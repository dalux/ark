<?php declare(strict_types=1);

namespace Brisk\Session;

use Brisk\Kernel\App;
use Brisk\Kernel\Language;
use Brisk\Kernel\Loader;
use Brisk\Exception\RuntimeException;
use Brisk\Exception\ClassNotFoundException;

class SessionAdapter
{

    /**
     * 通过配置文件获取session控制器
     *
     * @access public
     * @return ISessionDriver
     */
    public static function getDriverFromConfig()
    {
        if (!App::init()->config->has('session/driver')) {
            throw new RuntimeException(Language::format('core.config_not_found', 'session/driver'));
        } elseif (!App::init()->config->has('session/setting/save_path')) {
            throw new RuntimeException(Language::format('core.config_not_found', 'session/setting/save_path'));
        }
        $driver = App::init()->config->session->driver->value();
        $setting = App::init()->config->session->setting->value();
        if (Loader::findClass($driver) == '') {
            throw new ClassNotFoundException(Language::format('core.class_not_found', $driver));
        }
        $instance = new $driver($setting);
        if (!$instance instanceof ISessionDriver) {
            throw new RuntimeException(Language::format('core.class_implement_error', $driver, 'Brisk\Session\ISessionDriver'));
        }
        return $instance;
    }

}
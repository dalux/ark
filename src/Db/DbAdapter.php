<?php declare(strict_types=1);

namespace Brisk\Db;

use Brisk\Kernel\App;
use Brisk\Kernel\Language;
use Brisk\Kernel\Loader;
use Brisk\Exception\RuntimeException;
use Brisk\Exception\ClassNotFoundException;

class DbAdapter
{

    /**
     * 根据配置文件生成数据库连接实例
     *
     * @access public
     * @param string $name
     * @return IDbDriver
     */
    public static function getDriverFromConfig(string $name)
    {
		$path = 'database/'. $name;
        if (!App::init()->config->exist($path)) {
            throw new RuntimeException(Language::format('core.config_not_found', $path));
        } elseif (!App::init()->config->exist($path. '/driver')) {
            throw new RuntimeException(Language::format('core.config_not_found', $path. '/driver'));
        } elseif (!App::init()->config->exist($path. '/setting')) {
            throw new RuntimeException(Language::format('core.config_not_found', $path. '/option'));
        }
        $driver = App::init()->config->database->$name->driver->value();
        $setting = App::init()->config->database->$name->setting->value();
        if (Loader::findClass($driver) == "") {
            throw new ClassNotFoundException(Language::format('core.class_not_found', $driver));
        }
        $dsn = $setting['dsn'];
        $username = $setting['username'];
        $password = $setting['password'];
        $option = $setting['option'];
		$instance = new $driver($dsn, $username, $password, $option);
        if (!$instance instanceof IDbDriver) {
            throw new RuntimeException(Language::format('core.class_implement_error', $driver, 'Brisk\Db\IDbDriver'));
        }
        return $instance;
    }

}
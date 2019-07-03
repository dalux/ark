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
     * Get Database driver from config
     *
     * @param string name
     * @return IDbDriver
     */
    public static function getDriverFromConfig(string $name)
    {
		$path = 'database/'. $name;
        if (!App::get('config')->exist($path)) {
            throw new RuntimeException(Language::format('core.config_not_found', $path));
        } elseif (!App::get('config')->exist($path. '/driver')) {
            throw new RuntimeException(Language::format('core.config_not_found', $path. '/driver'));
        } elseif (!App::get('config')->exist($path. '/option/config')) {
            throw new RuntimeException(Language::format('core.config_not_found', $path. '/option/config'));
        }
        $driver = App::get('config')->database->$name->driver->value();
        $option = App::get('config')->database->$name->option->value();
        if (Loader::findClass($driver) == "") {
            throw new ClassNotFoundException(Language::format('core.class_not_found', $driver));
        }
		$instance = new $driver($option['config'], $option['setting']);
        if (!$instance instanceof IDbDriver) {
            throw new RuntimeException(Language::format('core.class_implement_error', $driver, '\Brisk\Db\IDbDriver'));
        }
        return $instance;
    }

}
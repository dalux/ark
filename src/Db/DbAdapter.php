<?php declare(strict_types=1);

namespace Brisk\Db;

use Brisk\App;
use Brisk\Language;
use Brisk\Loader;
use Brisk\Exception\ClassNotFoundException;
use Brisk\Exception\ConfigurationException;
use Brisk\Exception\RuntimeException;

class DbAdapter
{

    /**
     * Get Database driver from config
     *
     * @param string name
     * @return DbFather
     */
    public static function getDriverFromConfig(string $name)
    {
		$path = 'database/'. $name;
        if (!App::get('config')->hasKey($path)) {
            throw new ConfigurationException(Language::format('core.config_not_found', $path));
        } elseif (!App::get('config')->hasKey($path. '/driver')) {
            throw new ConfigurationException(Language::format('core.config_not_found', $path. '/driver'));
        } elseif (!App::get('config')->hasKey($path. '/option/config')) {
            throw new ConfigurationException(Language::format('core.config_not_found', $path. '/option/config'));
        }
        $driver = App::get('config')->database->$name->driver->value();
        $option = App::get('config')->database->$name->option->value();
        if (!Loader::findClass($driver)) {
            throw new ClassNotFoundException(Language::format('core.class_not_found', $driver));
        }
		$instance = new $driver($option['config'], $option['setting']);
        if (!$instance instanceof DbFather) {
            throw new RuntimeException(Language::format('core.class_extends_error', $driver, '\\Brisk\\Db\\DbFather'));
        }
        return $instance;
    }

}
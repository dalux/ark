<?php declare(strict_types=1);

namespace Brisk\Cache;

use Brisk\App;
use Brisk\Loader;
use Brisk\Language;
use Brisk\Exception\RuntimeException;
use Brisk\Exception\ConfigurationException;
use Brisk\Exception\ClassNotFoundException;

class CacheAdapter
{

    /**
     * Get cache driver from config
     *
     * @param string $name
     * @return CacheFather
     */
    public static function getDriverFromConfig(string $name)
    {
        $path = 'cache/'. $name;
        if (!App::get('config')->hasKey($path)) {
            throw new ConfigurationException(Language::format('core.config_not_found', $path));
        } elseif (!App::get('config')->hasKey($path. '/driver')) {
            throw new ConfigurationException(Language::format('core.config_not_found', $path. '/driver'));
        } elseif (!App::get('config')->hasKey($path. '/option/path')) {
            throw new ConfigurationException(Language::format('core.config_not_found', $path. '/option/path'));
        }
        $driver = App::get('config')->cache->$name->driver->value();
        $option = App::get('config')->cache->$name->option->value();
        if (Loader::findClass($driver) == "") {
            throw new ClassNotFoundException(Language::format('core.class_not_found', $driver));
        }
        $instance = new $driver($option['path'], $option['setting']);
        if (!$instance instanceof CacheFather) {
            throw new RuntimeException(Language::format('core.class_extends_error', $driver, '\\Brisk\\Cache\\CacheFather'));
        }
        return $instance;
    }



}
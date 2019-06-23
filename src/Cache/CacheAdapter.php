<?php

namespace Brisk\Cache;

use Brisk\Kernel\App;
use Brisk\Kernel\Language;
use Brisk\Kernel\Loader;
use Brisk\Exception\RuntimeException;
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
        if (!App::get('config')->exist($path)) {
            throw new RuntimeException(Language::format('core.config_not_found', $path));
        } elseif (!App::get('config')->exist($path. '/driver')) {
            throw new RuntimeException(Language::format('core.config_not_found', $path. '/driver'));
        } elseif (!App::get('config')->exist($path. '/option/path')) {
            throw new RuntimeException(Language::format('core.config_not_found', $path. '/option/path'));
        }
        $driver = App::get('config')->cache->$name->driver->value();
        $option = App::get('config')->cache->$name->option->value();
        if (Loader::findClass($driver) == "") {
            throw new ClassNotFoundException(Language::format('core.class_not_found', $driver));
        }
        $instance = new $driver($option['path'], $option['setting']);
        if (!$instance instanceof ICacheDriver) {
            throw new RuntimeException(Language::format('core.class_implement_error', $driver, '\\Brisk\\Cache\\ICacheDriver'));
        }
        return $instance;
    }



}
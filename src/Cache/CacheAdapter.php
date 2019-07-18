<?php declare(strict_types=1);

namespace Brisk\Cache;

use Brisk\Kernel\App;
use Brisk\Kernel\Language;
use Brisk\Kernel\Loader;
use Brisk\Exception\RuntimeException;
use Brisk\Exception\ClassNotFoundException;

class CacheAdapter
{

    /**
     * 根据配置生成缓存驱动器实例
     *
     * @access public
     * @param string $name
     * @return ICacheDriver
     */
    public static function getDriverFromConfig(string $name)
    {
        $path = 'cache/'. $name;
        if (!App::init()->config->exist($path)) {
            throw new RuntimeException(Language::format('core.config_not_found', $path));
        } elseif (!App::init()->config->exist($path. '/driver')) {
            throw new RuntimeException(Language::format('core.config_not_found', $path. '/driver'));
        } elseif (!App::init()->config->exist($path. '/option/path')) {
            throw new RuntimeException(Language::format('core.config_not_found', $path. '/option/path'));
        }
        $driver = App::init()->config->cache->$name->driver->value();
        $option = App::init()->config->cache->$name->option->value();
        if (Loader::findClass($driver) == "") {
            throw new ClassNotFoundException(Language::format('core.class_not_found', $driver));
        }
        $instance = new $driver($option['path'], $option['setting']);
        if (!$instance instanceof ICacheDriver) {
            throw new RuntimeException(Language::format('core.class_implement_error', $driver, '\Brisk\Cache\ICacheDriver'));
        }
        return $instance;
    }



}
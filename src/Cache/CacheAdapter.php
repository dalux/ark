<?php

namespace Brisk\Cache;

use Brisk\Kernel\App;
use Brisk\Kernel\Trace;
use Brisk\Kernel\Language;
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
    public static function getDriverFromConfig($name)
    {
        $path = 'cache/'. $name;
        if (!App::init()->config->hasKey($path)) {
            throw new ConfigurationException(Language::get('core.config_not_found', $path));
        } elseif (!App::init()->config->hasKey($path. '/driver')) {
            throw new ConfigurationException(Language::get('core.config_not_found', $path. '/driver'));
        } elseif (!App::init()->config->hasKey($path. '/option/path')) {
            throw new ConfigurationException(Language::get('core.config_not_found', $path. '/option/path'));
        }
        $driver = App::init()->config->get($path. '/driver');
        $option = App::init()->config->get($path. '/option');
        $instance = new $driver($option['path'], $option['setting']);
        if (!$instance instanceof CacheFather) {
            throw new RuntimeException(Language::get('core.class_extends_error', $driver, '\\Brisk\\Cache\\CacheFather'));
        }
        return $instance;
    }



}
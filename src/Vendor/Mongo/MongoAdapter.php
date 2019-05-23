<?php

namespace Brisk\Vendor\Mongo;

use Brisk\Kernel\App;
use Brisk\Kernel\Trace;
use Brisk\Kernel\Language;
use Brisk\Exception\ClassNotFoundException;
use Brisk\Exception\ConfigurationException;
use Brisk\Exception\RuntimeException;

class MongoAdapter
{

    /**
     * Get Database driver from config
     *
     * @param string name
     * @return MongoFather
     */
    public static function getDriverFromConfig($name)
    {
		$path = 'database/'. $name;
        if (!App::init()->config->hasKey($path)) {
            throw new ConfigurationException(Language::get('core.config_not_found', $path));
        } elseif (!App::init()->config->hasKey($path. '/driver')) {
            throw new ConfigurationException(Language::get('core.config_not_found', $path. '/driver'));
        } elseif (!App::init()->config->hasKey($path. '/option/config')) {
            throw new ConfigurationException(Language::get('core.config_not_found', $path. '/option/config'));
        }
        $driver = App::init()->config->get($path. '/driver');
        $option = App::init()->config->get($path. '/option');
		$instance = new $driver($option['config'], $option['setting']);
        if (!$instance instanceof MongoFather) {
            throw new RuntimeException(Language::get('core.class_extends_error', $driver, '\\Brisk\\Vendor\\Mongo\\MongoFather'));
        }
        return $instance;
    }

}
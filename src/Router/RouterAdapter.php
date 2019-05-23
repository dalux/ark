<?php

namespace Brisk\Router;

use Brisk\Kernel\App;
use Brisk\Kernel\Trace;
use Brisk\Kernel\Language;
use Brisk\Exception\RouterException;
use Brisk\Exception\ConfigurationException;
use Brisk\Exception\ClassNotFoundException;

class RouterAdapter
{

    /**
     * Get router driver
     *
     * @return RouterFather
     */
    public static function getDriverFromConfig()
    {
        if (!App::init()->config->hasKey('router/driver')) {
            throw new ConfigurationException(Language::get('core.config_not_found', 'router/driver'));
        }
        $driver = App::init()->config->get('router/driver');
        $instance = new $driver();
        if (!$instance instanceof RouterFather) {
            throw new RouterException(Language::get('core.class_extends_error', $driver, '\\Brisk\\Router\\RouterFather'));
        }
        return $instance;
    }
	
}
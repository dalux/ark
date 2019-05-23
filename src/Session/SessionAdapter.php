<?php

namespace Brisk\Session;

use Brisk\Kernel\App;
use Brisk\Kernel\Trace;
use Brisk\Kernel\Language;
use Brisk\Exception\RuntimeException;
use Brisk\Exception\ConfigurationException;
use Brisk\Exception\ClassNotFoundException;

class SessionAdapter
{

    /**
     * 通过配置文件获取session控制器
     *
     * @return SessionFather
     */
    public static function getDriverFromConfig()
    {
        if (!App::init()->config->hasKey('session/driver')) {
            throw new ConfigurationException(Language::get('core.config_not_found', 'session/driver'));
        }
        $driver = App::init()->config->get('session/driver');
        $option = [];
        if (App::init()->config->hasKey('session/option')) {
            $option = App::init()->config->get('session/option');
        }
        $instance = new $driver($option);
        if (!$instance instanceof SessionFather) {
            throw new RuntimeException(Language::get('core.class_extends_error', $driver, '\\Brisk\\Session\\SessionFather'));
        }
        return $instance;
    }

}
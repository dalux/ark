<?php

namespace Brisk\Session;

use Brisk\App;
use Brisk\Language;
use Brisk\Loader;
use Brisk\Exception\RuntimeException;
use Brisk\Exception\ClassNotFoundException;

class SessionAdapter
{

    /**
     * 通过配置文件获取session控制器
     *
     * @return ISessionDriver
     */
    public static function getDriverFromConfig()
    {
        if (!App::get('config')->hasKey('session/driver')) {
            throw new RuntimeException(Language::format('core.config_not_found', 'session/driver'));
        }
        $driver = App::get('config')->session->driver->value();
        if (Loader::findClass($driver) == '') {
            throw new ClassNotFoundException(Language::format('core.class_not_found', $driver));
        }
        $option = [];
        if (App::get('config')->hasKey('session/option')) {
            $option = App::get('config')->session->option->value();
        }
        $instance = new $driver($option);
        if (!$instance instanceof ISessionDriver) {
            throw new RuntimeException(Language::format('core.class_implement_error', $driver, '\\Brisk\\Session\\ISessionDriver'));
        }
        return $instance;
    }

}
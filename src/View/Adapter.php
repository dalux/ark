<?php

namespace Ark\Com\View;

use Ark\Core\Noah;
use Ark\Core\Trace;
use Ark\Contract\ViewDriver;

class Adapter
{

    /**
     * 获取视图引擎实例
     *
     * @return ViewDriver
     * @throws RuntimeException
     */
    static function getDriver()
    {
        $config = Noah::getInstance()->config->view->toArray();
        if (!$driver = $config['driver']) {
            throw new RuntimeException(Noah::getInstance()->language->get('view.invalid_driver_name'));
        }
        $name = sprintf('__base_view_%s__', $driver);
        $instance = Noah::getInstance()->container->$name;
        if (!$instance || !$instance instanceof ViewDriver) {
            $class_name = sprintf('\\Ark\\Com\\View\\Driver\\'. ucfirst($driver));
            if (!class_exists($class_name)) {
                throw new RuntimeException(sprintf(Noah::getInstance()->language->get('view.driver_not_found'), $class_name));
            }
            $instance = new $class_name();
            if (!$instance instanceof ViewDriver) {
                throw new RuntimeException(sprintf(Noah::getInstance()->language->get('view.driver_implement_error'), $class_name, '\\Ark\\Contract\\ViewDriver'));
            }
            Noah::getInstance()->container->$name = $instance;
            Trace::set('driver', array('view'=> $driver));
        }
        return $instance;
    }

}


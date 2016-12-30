<?php

namespace Ark\View;

use Ark\Core\Captain;
use Ark\Core\Trace;

class Adapter
{

    /**
     * 获取视图引擎实例
     *
     * @return Driver
     * @throws Exception
     */
    static function getDriver()
    {
        $config = Captain::getInstance()->config->view->toArray();
        if (!$driver = $config['driver']) {
            throw new Exception(Captain::getInstance()->lang->get('view.invalid_driver_name'));
        }
        $name = '__base_view_driver__';
        $instance = Captain::getInstance()->container->$name;
        if (!$instance || !$instance instanceof Driver) {
            if (!class_exists($driver, false)) {
                throw new Exception(sprintf(Captain::getInstance()->lang->get('view.driver_not_found'), $driver));
            }
            $instance = new $driver();
            if (!$instance instanceof Driver) {
                throw new Exception(sprintf(Captain::getInstance()->lang->get('view.driver_implement_error'), $driver, '\\Ark\\View\\Driver'));
            }
            Captain::getInstance()->container->$name = $instance;
            Trace::set('driver', array('view'=> $driver));
        }
        return $instance;
    }

}


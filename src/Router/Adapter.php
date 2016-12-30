<?php

namespace Ark\Router;

use Ark\Core\Loader;
use Ark\Core\Captain;
use Ark\Core\Trace;

class Adapter
{

    /**
     * 获取路由驱动器
     *
     * @return Driver
     * @throws Exception
     */
    static function getDriver()
    {
        $config = Captain::getInstance()->config->router->toArray();
        if (!$driver = $config['driver']) {
            throw new Exception(Captain::getInstance()->lang->get('router.invalid_driver_name'));
        }
        $name = '__base_router_driver__';
        $instance = Captain::getInstance()->container->$name;
        if (!$instance || !$instance instanceof Driver) {
            if (!Loader::findClass($driver)) {
                throw new Exception(sprintf(Captain::getInstance()->lang->get('router.driver_not_found'), $driver));
            }
            $instance = new $driver();
            if (!$instance instanceof Driver) {
                throw new Exception(sprintf(Captain::getInstance()->lang->get('router.driver_implement_error'), $driver, '\\Ark\\Router\\Driver'));
            }
            Captain::getInstance()->container->$name = $instance;
            Trace::set('driver', array('router'=> $driver));
        }
        return $instance;
    }

}
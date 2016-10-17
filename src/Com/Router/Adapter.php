<?php

namespace Ark\Com\Router;

use Ark\Core\Noah;
use Ark\Core\Trace;
use Ark\Contract\RouterDriver;

class Adapter
{

    /**
     * 获取路由驱动器
     *
     * @return RouterDriver
     * @throws RuntimeException
     */
    static function getDriver()
    {
        $config = Noah::getInstance()->config->router->toArray();
        if (!$driver = $config['driver']) {
            throw new RuntimeException(Noah::getInstance()->language->get('router.invalid_driver_name'));
        }
        $name = sprintf('__base_router_%s__', $driver);
        $instance = Noah::getInstance()->container->$name;
        if (!$instance || !$instance instanceof RouterDriver) {
            $class_name = sprintf('\\Ark\\Com\\Router\\'. ucfirst($driver));
            if (!class_exists($class_name)) {
                throw new RuntimeException(sprintf(Noah::getInstance()->language->get('router.driver_not_found'), $class_name));
            }
            $instance = new $class_name();
            if (!$instance instanceof RouterDriver) {
                throw new RuntimeException(sprintf(Noah::getInstance()->language->get('router.driver_implement_error'), $class_name, '\\Ark\\Contract\\RouterDriver'));
            }
            Noah::getInstance()->container->$name = $instance;
            Trace::set('driver', array('router'=> $driver));
        }
        return $instance;
    }

}
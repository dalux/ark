<?php

namespace Ark\Assembly;

use Ark\Core\Loader;
use Ark\Core\Captain;
use Ark\Core\Trace;
use Ark\Assembly\Router\Father;
use Ark\Assembly\Router\Exception;

class Router
{

    /**
     * 获取路由驱动器
     *
     * @return Father
     * @throws Exception
     */
    static function getDriver()
    {
        $config = Captain::getInstance()->config->router->toArray();
        if (!$driver = $config['driver']) {
            throw new Exception(Captain::getInstance()->lang->get('router.invalid_driver_name'));
        } elseif (!Loader::findClass($driver)) {
            throw new Exception(sprintf(Captain::getInstance()->lang->get('router.driver_not_found'), $driver));
        }
        $instance = new $driver();
        Trace::set('driver', array('router'=> $driver));
        return $instance;
    }

}
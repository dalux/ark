<?php

namespace Ark\Assembly;

use Ark\Core\Loader;
use Ark\Core\Noah;
use Ark\Core\Trace;
use Ark\Assembly\Router\Exception;
use Ark\Contract\Router as RouterInterface;

class Router
{

    /**
     * 获取路由驱动器
     *
     * @return RouterInterface
     * @throws Exception
     */
    static function getDriver()
    {
        $config = Ark_Core::getInstance()->config->router->toArray();
        if (!$driver = $config['driver']) {
            throw new Exception(Ark_Core::getInstance()->lang->get('router.invalid_driver_name'));
        } elseif (!Loader::findClass($driver)) {
            throw new Exception(Ark_Core::getInstance()->lang->get('router.driver_not_found', $driver));
        }
        $instance = new $driver();
        if (!$instance instanceof RouterInterface) {
            throw new Exception(Ark_Core::getInstance()->lang->get('router.driver_implement_error', $driver, '\\Ark\\Contract\\Router'));
        }
        Trace::set('driver', array('router'=> $driver));
        return $instance;
    }

}
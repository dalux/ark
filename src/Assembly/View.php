<?php

namespace Ark\Assembly;

use Ark\Core\Captain;
use Ark\Core\Trace;
use Ark\Core\Loader;
use Ark\Assembly\View\Father;
use Ark\Assembly\View\Exception;

class View
{

    /**
     * 获取视图引擎实例
     *
     * @return Father
     * @throws Exception
     */
    static function getDriver()
    {
        $config = Captain::getInstance()->config->view->toArray();
        if (!$driver = $config['driver']) {
            throw new Exception(Captain::getInstance()->lang->get('view.invalid_driver_name'));
        } elseif (!Loader::findClass($driver)) {
            throw new Exception(sprintf(Captain::getInstance()->lang->get('view.driver_not_found'), $driver));
        }
        $instance = new $driver();
        if (!$instance instanceof Father) {
            throw new Exception(sprintf(Captain::getInstance()->lang->get('view.driver_implement_error'), $driver, '\\Ark\\View\\Driver'));
        }
        Trace::set('driver', array('view'=> $driver));
        return $instance;
    }

}


<?php

namespace Ark\Assembly;

use Ark\Core\Captain;
use Ark\Core\Trace;
use Ark\Core\Loader;
use Ark\Assembly\Session\Father;
use Ark\Assembly\Session\Exception;

class Adapter
{

    /**
     * 获取会话引擎实例
     *
     * @return Father
     * @throws Exception
     */
    static function getDriver()
    {
        $config = Captain::getInstance()->config->session->toArray();
        if (!$driver = $config['driver']) {
            throw new Exception(Captain::getInstance()->lang->get('sess.invalid_driver_name'));
        } elseif (!Loader::findClass($driver)) {
            throw new Exception(sprintf(Captain::getInstance()->lang->get('sess.driver_not_found'), $driver));
        }
        $instance = new $driver();
        if (!$instance instanceof Father) {
            throw new Exception(sprintf(Captain::getInstance()->lang->get('sess.driver_implement_error'), $driver, '\\Ark\\Assembly\\Session\\Father'));
        }
        Trace::set('driver', array('session'=> $driver));
        return $instance;
    }

}
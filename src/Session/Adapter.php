<?php

namespace Ark\Session;

use Ark\Core\Captain;
use Ark\Core\Trace;

class Adapter
{

    /**
     * 获取会话引擎实例
     *
     * @return Driver
     * @throws Exception
     */
    static function getDriver()
    {
        $config = Captain::getInstance()->config->session->toArray();
        if (!$driver = $config['driver']) {
            throw new Exception(Captain::getInstance()->lang->get('sess.invalid_driver_name'));
        }
        $name = '__base_session_driver__';
        $instance = Captain::getInstance()->container->$name;
        if (!$instance || !$instance instanceof Driver) {
            if (!class_exists($driver, false)) {
                throw new Exception(sprintf(Captain::getInstance()->lang->get('sess.driver_not_found'), $driver));
            }
            $instance = new $driver();
            if (!$instance instanceof Driver) {
                throw new Exception(sprintf(Captain::getInstance()->lang->get('sess.driver_implement_error'), $driver, '\\Ark\\Session\\Driver'));
            }
            Captain::getInstance()->container->$name = $instance;
            Trace::set('driver', array('session'=> $driver));
        }
        return $instance;
    }

}
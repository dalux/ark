<?php

namespace Ark\Com\Session;

use Ark\Core\Noah;
use Ark\Core\Trace;
use Ark\Contract\SessionDriver;

class Adapter
{

    /**
     * 获取会话引擎实例
     *
     * @return SessionDriver
     * @throws RuntimeException
     */
    static function getDriver()
    {
        $config = Noah::getInstance()->config->session->toArray();
        if (!$driver = $config['driver']) {
            throw new RuntimeException(Noah::getInstance()->language->get('sess.invalid_driver_name'));
        }
        $name = sprintf('__base_session_%s__', $driver);
        $instance = Noah::getInstance()->container->$name;
        if (!$instance || !$instance instanceof SessionDriver) {
            $class_name = sprintf('\\Ark\\Com\\Session\\'. ucfirst($driver));
            if (!class_exists($class_name)) {
                throw new RuntimeException(sprintf(Noah::getInstance()->language->get('sess.driver_not_found'), $class_name));
            }
            $instance = new $class_name();
            if (!$instance instanceof SessionDriver) {
                throw new RuntimeException(sprintf(Noah::getInstance()->language->get('sess.driver_implement_error'), $class_name, '\\Ark\\Contract\\SessionDriver'));
            }
            Noah::getInstance()->container->$name = $instance;
            Trace::set('driver', array('session'=> $driver));
        }
        return $instance;
    }

}
<?php

namespace Ark\Com\Database;

use Ark\Core\Noah;
use Ark\Core\Trace;
use Ark\Contract\CacheProxy;
use Ark\Contract\DatabaseDriver;

class Adapter
{

    /**
     * 获取数据库引擎实例
     *
     * @access public
     * @static
     * @param $name
     * @throws RuntimeException
     */
    static function getDriver($name)
    {
        $config = Noah::getInstance()->config->database->$name;
        if (!$config) {
            throw new RuntimeException(sprintf(Noah::getInstance()->language->get('db.config_not_found'), $name));
        }
        $config = $config->toArray();
        $ori_name = $name;
        $name = sprintf('__base_db_%s__', $name);
        $instance = Noah::getInstance()->container->$name;
        if (!$instance
                || !$instance instanceof DatabaseDriver
                || !$instance instanceof CacheProxy) {
            $driver = $config['driver'];
            $driver_path = ucfirst($driver);
            if (strpos($driver, '_') !== false) {
                $drivers = explode('_', $driver);
                $drivers = array_map('ucfirst', $drivers);
                $driver_path = implode('\\', $drivers);
            }
            $dsn = $config['dsn'];
            $option = $config['option'];
            $class_name = sprintf('\\Ark\\Com\\Database\\'. $driver_path);
            if (!class_exists($class_name)) {
                throw new RuntimeException(sprintf(Noah::getInstance()->language->get('db.driver_not_found'), $class_name));
            }
            $instance = new $class_name($dsn, $option);
            if (!$instance instanceof DatabaseDriver || !$instance instanceof CacheProxy) {
                throw new RuntimeException(sprintf(Noah::getInstance()->language->get('db.driver_implement_error'), $class_name, '\\Ark\\Contract\\DatabaseDriver', '\\Ark\\Contract\\CacheProxy'));
            }
            Noah::getInstance()->container->$name = $instance;
            Trace::set('driver', array('database'=> sprintf('%s[%s]', $ori_name, $driver)));
        }
        return $instance;
    }

}


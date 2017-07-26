<?php

namespace Ark\Assembly;

use Ark\Core\Captain;
use Ark\Core\Loader;
use Ark\Core\Trace;
use Ark\Assembly\Database\Father;
use Ark\Assembly\Database\Exception;

class Database
{

    /**
     * 获取数据库引擎实例
     *
     * @access public
     * @static
     * @param $name
     * @throws Exception
     */
    static function getDriver($name)
    {
        $config = Captain::getInstance()->config->database->$name;
        if (!$config) {
            throw new Exception(sprintf(Captain::getInstance()->lang->get('db.config_not_found'), $name));
        }
        /* @var \Ark\Core\Container $config */
        $config = $config->toArray();
        $driver = $config['driver'];
        $dsn = $config['dsn'];
        $option = $config['option'];
        if (!Loader::findClass($driver)) {
            throw new Exception(sprintf(Captain::getInstance()->lang->get('db.driver_not_found'), $driver));
        }
        $instance = new $driver($dsn, $option);
        if (!$instance instanceof Father) {
            throw new Exception(sprintf(Captain::getInstance()->lang->get('db.driver_implement_error'), $driver, '\\Ark\\Assembly\\Database\\Father'));
        }
        Trace::set('driver', array('database'=> sprintf('%s[%s]', $name, $driver)));
        return $instance;
    }

}


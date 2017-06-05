<?php

namespace Ark\Cache;

use Ark\Core\Captain;
use Ark\Core\Loader;
use Ark\Core\Trace;
use Ark\Core\Container;

class Adapter
{

    /**
     * 获取缓存引擎实例
     *
     * @param null $name
     * @return Driver
     * @throws Exception
     */
    static function getDriver($name)
    {
        $config = Captain::getInstance()->config->cache->$name;
        if (!$config) {
            throw new Exception(sprintf(Captain::getInstance()->lang->get('cache.config_not_found'), $name));
        }
        /* @var Container $config */
        $config = $config->toArray();
        $driver = $config['driver'];
        $save_path = $config['save_path'];
        $option = $config['option'];
        if (!Loader::findClass($driver)) {
            throw new Exception(sprintf(Captain::getInstance()->lang->get('cache.driver_not_found'), $driver));
        }
        $instance = new $driver($save_path, $option);
        if (!$instance instanceof Driver) {
            throw new Exception(sprintf(Captain::getInstance()->lang->get('cache.driver_implement_error'), $driver, '\\Ark\\Cache\\Father'));
        }
        Trace::set('driver', array('cache'=> sprintf('%s[%s]', $name, $driver)));
        return $instance;
    }

}



<?php

namespace Ark\Cache;

use Ark\Core\Captain;
use Ark\Core\Trace;
use Ark\Core\Container;

class Adapter
{

    /**
     * 获取缓存引擎实例
     *
     * @param null $name
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
        $ori_name = $name;
        $name = sprintf('__base_cache_%s__', $name);
        $instance = Captain::getInstance()->container->$name;
        if (!$instance || !$instance instanceof Driver) {
            $driver = $config['driver'];
            $save_path = $config['save_path'];
            $option = $config['option'];
            if (!class_exists($driver, false)) {
                throw new Exception(sprintf(Captain::getInstance()->lang->get('cache.driver_not_found'), $driver));
            }
            $instance = new $driver($save_path, $option);
            if (!$instance instanceof Driver) {
                throw new Exception(sprintf(Captain::getInstance()->lang->get('cache.driver_implement_error'), $driver, '\\Ark\\Cache\\Father'));
            }
            Captain::getInstance()->container->$name = $instance;
            Trace::set('driver', array('cache'=> sprintf('%s[%s]', $ori_name, $driver)));
        }
        return $instance;
    }

}



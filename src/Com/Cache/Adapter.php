<?php

namespace Ark\Com\Cache;

use Ark\Core\Noah;
use Ark\Core\Trace;
use Ark\Contract\CacheDriver;

class Adapter
{

    /**
     * 获取缓存引擎实例
     *
     * @param null $name
     * @throws RuntimeException
     */
    static function getDriver($name)
    {
        $config = Noah::getInstance()->config->cache->$name;
        if (!$config) {
            throw new RuntimeException(sprintf(Noah::getInstance()->language->get('cache.config_not_found'), $name));
        }
        $config = $config->toArray();
        $ori_name = $name;
        $name = sprintf('__base_cache_%s__', $name);
        $instance = Noah::getInstance()->container->$name;
        if (!$instance || !$instance instanceof CacheDriver) {
            $driver = $config['driver'];
            $save_path = $config['save_path'];
            $option = $config['option'];
            $class_name = sprintf('\\Ark\\Com\\Cache\\Driver\\'. ucfirst($driver));
            if (!class_exists($class_name)) {
                throw new RuntimeException(sprintf(Noah::getInstance()->language->get('cache.driver_not_found'), $class_name));
            }
            $instance = new $class_name($save_path, $option);
            if (!$instance instanceof CacheDriver) {
                throw new RuntimeException(sprintf(Noah::getInstance()->language->get('cache.driver_implement_error'), $class_name, '\\Ark\\Contract\\CacheDriver'));
            }
            Noah::getInstance()->container->$name = $instance;
            Trace::set('driver', array('cache'=> sprintf('%s[%s]', $ori_name, $driver)));
        }
        return $instance;
    }

}



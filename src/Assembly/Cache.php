<?php

namespace Ark\Assembly;

use Ark\Core\Captain;
use Ark\Core\Loader;
use Ark\Core\Trace;
use Ark\Core\Container;
use Ark\Assembly\Cache\Exception;
use Ark\Contract\Cache as CacheInterface;

class Cache
{

    /**
     * 获取驱动器
     *
     * @param null $name
     * @return CacheInterface
     * @throws Exception
     */
    static function getDriver($name)
    {
        $config = Captain::getInstance()->config->cache->$name;
        if (!$config) {
            throw new Exception(Captain::getInstance()->lang->get('cache.config_not_found', $name));
        }
        /* @var Container $config */
        $config = $config->toArray();
        $driver = $config['driver'];
        $save_path = $config['save_path'];
        $option = $config['option'];
        if (!Loader::findClass($driver)) {
            throw new Exception(Captain::getInstance()->lang->get('cache.driver_not_found', $driver));
        }
        $instance = new $driver($save_path, $option);
        if (!$instance instanceof CacheInterface) {
            throw new Exception(Captain::getInstance()->lang->get('cache.driver_implement_error', $driver, '\\Ark\\Contract\\CacheInterface'));
        }
        Trace::set('driver', array('cache'=> sprintf('%s[%s]', $name, $driver)));
        return $instance;
    }

}

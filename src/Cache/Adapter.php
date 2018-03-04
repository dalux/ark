<?php

class Ark_Cache_Adapter
{

    /**
     * 获取驱动器
     *
     * @param null $name
     * @return Ark_Cache_Contract
     * @throws Ark_Cache_Exception
     */
    static function getDriver($name)
    {
        $config = Ark_Core::getInstance()->config->cache->$name;
        if (!$config) {
            throw new Ark_Cache_Exception(Ark_Core::getInstance()->lang->get('cache.config_not_found', $name));
        }
        /* @var Ark_Container $config */
        $config = $config->toArray();
        $driver = $config['driver'];
        $save_path = $config['save_path'];
        $option = $config['option'];
        if (!Ark_Loader::findClass($driver)) {
            throw new Ark_Cache_Exception(Ark_Core::getInstance()->lang->get('cache.driver_not_found', $driver));
        }
        $instance = new $driver($save_path, $option);
        if (!$instance instanceof Ark_Cache_Contract) {
            throw new Ark_Cache_Exception(Ark_Core::getInstance()->lang->get('cache.driver_implement_error', $driver, 'Ark_Cache_Contract'));
        }
        Ark_Trace::set('driver', array('cache'=> sprintf('%s[%s]', $name, $driver)));
        return $instance;
    }

}

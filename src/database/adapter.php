<?php

class Ark_Database_Adapter
{

    /**
     * 获取数据库引擎实例
     *
     * @access public
     * @static
     * @param $name
     * @return mixed
     * @throws Ark_Database_Exception
     */
    static function getDriver($name)
    {
        $config = Ark_Core::getInst()->config->database;
        if (!$config || !$config = $config->$name) {
            throw new Ark_Database_Exception(Ark_Language::get('db.config_not_found', $name));
        }
        /* @var Ark_Container $config */
        $config = $config->toArray();
        $driver = $config['driver'];
        $dsn = $config['dsn'];
        $option = $config['option'];
        if (!Ark_Loader::findClass($driver)) {
            throw new Ark_Database_Exception(Ark_Language::get('db.driver_not_found', $driver));
        }
        $instance = new $driver($dsn, $option);
        if (!$instance instanceof Ark_Database_Contract) {
            throw new Ark_Database_Exception(Ark_Language::get('db.driver_implement_error', $driver, 'Ark_Database_Contract'));
        }
        Ark_Trace::set('driver', array('database'=> sprintf('%s[%s]', $name, $driver)));
        return $instance;
    }

}


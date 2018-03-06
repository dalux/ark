<?php

class Ark_Session_Adapter
{

    /**
     * 获取会话引擎实例
     *
     * @return SessionInterface
     * @throws Exception
     */
    static function getDriver()
    {
        $config = Ark_Core::getInstance()->config->session->toArray();
        if (!$driver = $config['driver']) {
            throw new Exception(Ark_Core::getInstance()->lang->get('sess.invalid_driver_name'));
        } elseif (!Loader::findClass($driver)) {
            throw new Exception(Ark_Core::getInstance()->lang->get('sess.driver_not_found', $driver));
        }
        $instance = new $driver();
        if (!$instance instanceof SessionInterface) {
            throw new Exception(Ark_Core::getInstance()->lang->get('sess.driver_implement_error', $driver, '\\Ark\\Contract\\Session'));
        }
        Trace::set('driver', array('session'=> $driver));
        return $instance;
    }

}
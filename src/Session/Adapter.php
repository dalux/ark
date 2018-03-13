<?php

class Ark_Session_Adapter
{

    /**
     * 获取会话引擎实例
     *
     * @return Ark_Session_Contract
     * @throws Exception
     */
    static function getDriver()
    {
        $config = Ark_Core::getInst()->config->session->toArray();
        if (!$driver = $config['driver']) {
            throw new Ark_Exception(Ark_Core::getInst()->lang->get('sess.invalid_driver_name'));
        } elseif (!Ark_Loader::findClass($driver)) {
            throw new Ark_Exception(Ark_Core::getInst()->lang->get('sess.driver_not_found', $driver));
        }
        $instance = new $driver();
        if (!$instance instanceof Ark_Session_Contract) {
            throw new Ark_Exception(Ark_Core::getInst()->lang->get('sess.driver_implement_error', $driver, 'Ark_Session_Contract'));
        }
        Ark_Trace::set('driver', array('session'=> $driver));
        return $instance;
    }

}
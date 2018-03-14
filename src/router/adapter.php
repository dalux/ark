<?php

class Ark_Router_Adapter
{

    /**
     * 获取路由驱动器
     *
     * @return Ark_Router_Contract
     * @throws Exception
     */
    static function getDriver()
    {
        $config = Ark_Core::getInst()->config->router->toArray();
        if (!$driver = $config['driver']) {
            throw new Exception(Ark_Core::getInst()->lang->get('router.invalid_driver_name'));
        } elseif (!Ark_Loader::findClass($driver)) {
            throw new Ark_Router_Exception(Ark_Core::getInst()->lang->get('router.driver_not_found', $driver));
        }
        $instance = new $driver();
        if (!$instance instanceof Ark_Router_Contract) {
            throw new Ark_Router_Exception(Ark_Core::getInst()->lang->get('router.driver_implement_error', $driver, 'Ark_Router_Contract'));
        }
        Ark_Trace::set('driver', array('router'=> $driver));
        return $instance;
    }

}
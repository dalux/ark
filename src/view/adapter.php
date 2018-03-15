<?php

class Ark_View_Adapter
{

    /**
     * 获取视图引擎实例
     *
     * @return Ark_View_Contract
     * @throws Exception
     */
    static function getDriver()
    {
        $config = Ark_Core::getInst()->config->view->toArray();
        if (!$driver = $config['driver']) {
            throw new Ark_View_Exception(Ark_Language::get('view.invalid_driver_name'));
        } elseif (!Ark_Loader::findClass($driver)) {
            throw new Ark_View_Exception(Ark_Language::get('view.driver_not_found', $driver));
        }
        $instance = new $driver();
        if (!$instance instanceof Ark_View_Contract) {
            throw new Ark_View_Exception(Ark_Language::get('view.driver_implement_error', $driver, 'Ark_View_Contract'));
        }
        Ark_Trace::set('driver', array('view'=> $driver));
        return $instance;
    }

}


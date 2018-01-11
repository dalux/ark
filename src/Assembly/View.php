<?php

namespace Ark\Assembly;

use Ark\Core\Noah;
use Ark\Core\Trace;
use Ark\Core\Loader;
use Ark\Assembly\View\Exception;
use Ark\Contract\View as ViewInterface;

class View
{

    /**
     * 获取视图引擎实例
     *
     * @return ViewInterface
     * @throws Exception
     */
    static function getDriver()
    {
        $config = Noah::getInstance()->config->view->toArray();
        if (!$driver = $config['driver']) {
            throw new Exception(Noah::getInstance()->lang->get('view.invalid_driver_name'));
        } elseif (!Loader::findClass($driver)) {
            throw new Exception(Noah::getInstance()->lang->get('view.driver_not_found', $driver));
        }
        $instance = new $driver();
        if (!$instance instanceof ViewInterface) {
            throw new Exception(Noah::getInstance()->lang->get('view.driver_implement_error', $driver, '\\Ark\\Contract\\View'));
        }
        Trace::set('driver', array('view'=> $driver));
        return $instance;
    }

}


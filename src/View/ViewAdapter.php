<?php

namespace Brisk\View;

use Brisk\Kernel\App;
use Brisk\Kernel\Trace;
use Brisk\Kernel\Language;
use Brisk\Exception\ClassNotFoundException;
use Brisk\Exception\ConfigurationException;
use Brisk\Exception\RuntimeException;

class ViewAdapter
{

    /**
     * Get View driver from config
     *
     * @return ViewFather
     */
    public static function getDriverFromConfig()
    {
        if (!App::init()->config->hasKey('view/driver')) {
            throw new ConfigurationException(Language::get('core.config_not_found', 'view/driver'));
        } elseif (!App::init()->config->hasKey('view/option/template_dir')) {
            throw new ConfigurationException(Language::get('core.config_not_found', 'view/option/template_dir'));
        }
        $driver = App::init()->config->get('view/driver');
        $option = App::init()->config->get('view/option');
        if (!class_exists($driver)) {
            throw new ClassNotFoundException(Language::get('core.class_not_found', $driver));
        }
        $instance = new $driver($option);
        if (!$instance instanceof ViewFather) {
            throw new RuntimeException(Language::get('core.class_extends_error', $driver, '\\Brisk\\View\\ViewFather'));
        }
        Trace::set('driver', ['view'=> $driver]);
        return $instance;
    }

}
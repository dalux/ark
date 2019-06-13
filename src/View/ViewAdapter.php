<?php declare(strict_types=1);

namespace Brisk\View;

use Brisk\App;
use Brisk\Loader;
use Brisk\Language;
use Brisk\Exception\ClassNotFoundException;
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
        if (!App::get('config')->exist('view/driver')) {
            throw new RuntimeException(Language::format('core.config_not_found', 'view/driver'));
        } elseif (!App::get('config')->exist('view/option/template_dir')) {
            throw new RuntimeException(Language::format('core.config_not_found', 'view/option/template_dir'));
        }
        $driver = App::get('config')->view->driver->value();
        $option = App::get('config')->view->option->value();
        if (Loader::findClass($driver) == '') {
            throw new ClassNotFoundException(Language::format('core.class_not_found', $driver));
        }
        $instance = new $driver($option);
        if (!$instance instanceof IViewDriver) {
            throw new RuntimeException(Language::format('core.class_implement_error', $driver, '\\Brisk\\View\\IViewDriver'));
        }
        return $instance;
    }

}
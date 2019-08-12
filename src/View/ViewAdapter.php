<?php declare(strict_types=1);

namespace Brisk\View;

use Brisk\Kernel\App;
use Brisk\Kernel\Loader;
use Brisk\Kernel\Language;
use Brisk\Exception\ClassNotFoundException;
use Brisk\Exception\RuntimeException;

class ViewAdapter
{

    /**
     * 根据配置生成模板驱动器实例
     *
     * @access public
     * @return IViewDriver
     */
    public static function getDriverFromConfig()
    {
        if (!App::init()->config->has('view/driver')) {
            throw new RuntimeException(Language::format('core.config_not_found', 'view/driver'));
        } elseif (!App::init()->config->has('view/setting/template_dir')) {
            throw new RuntimeException(Language::format('core.config_not_found', 'view/setting/template_dir'));
        }
        $driver = App::init()->config->view->driver->value();
        $setting = App::init()->config->view->setting->value();
        if (Loader::findClass($driver) == '') {
            throw new ClassNotFoundException(Language::format('core.class_not_found', $driver));
        }
        $instance = new $driver($setting);
        if (!$instance instanceof IViewDriver) {
            throw new RuntimeException(Language::format('core.class_implement_error', $driver, 'Brisk\View\IViewDriver'));
        }
        return $instance;
    }

}
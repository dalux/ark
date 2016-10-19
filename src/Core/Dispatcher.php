<?php

namespace Ark\Core;

class Dispatcher
{

    /**
     * 控制器
     *
     * @var string
     */
    protected $_controller;

    /**
     * 行为
     *
     * @var string
     */
    protected $_action;

    /**
     * 模块
     *
     * @var string
     */
    protected $_module;

    /**
     *  模板路径
     *
     * @var string
     */
    protected $_template;

    /**
     * 设置模块名称
     *
     * @param $module
     * @return $this
     */
    final function setModule($module)
    {
        $this->_module = $module;
        return $this;
    }

    /**
     * 获取当前模块名称
     *
     * @return string
     */
    final function getModule()
    {
        return $this->_module;
    }

    /**
     * 设置控制器名
     *
     * @param $controller
     * @return $this
     */
    final function setController($controller)
    {
        $this->_controller = $controller;
        return $this;
    }

    /**
     * 获取当前控制器名称
     *
     * @return string
     */
    final function getController()
    {
        return $this->_controller;
    }

    /**
     * 设置行为名称
     *
     * @param $action
     * @return $this
     */
    final function setAction($action)
    {
        $this->_action = $action;
        return $this;
    }

    /**
     * 获取当前行为名称
     *
     * @return string
     */
    final function getAction()
    {
        return $this->_action;
    }

    /**
     * 执行控制器行为
     *
     * @return mixed
     * @throws RuntimeException
     */
    final function doAction()
    {
        if (!$this->_controller) {
            throw new RuntimeException(Noah::getInstance()->language->get('core.invalid_controller_name'));
        } elseif (!$this->_action) {
            throw new RuntimeException(Noah::getInstance()->language->get('core.invalid_action_name'));
        }
        $app_name = Noah::getInstance()->getAssemblyName();
        $controller_dir = Noah::getInstance()->getControllerDir();
        $app_dir = Noah::getInstance()->getAssemblyDir();
        $path_now = $controller_dir;
        $part = str_replace($app_dir, '', $controller_dir);
        $part = trim(str_replace(array('/', '\\'), '\\', $part), '\\');
        $part = array_map('ucfirst', explode('\\', $part));
        $part = implode('\\', $part);
        $namespace = $app_name. '\\'. $part;
        if ($this->_module) {
            $namespace.= '\\'. ucfirst($this->_module);
            $path_now.= DIRECTORY_SEPARATOR. $this->_module;
        }
        $namespace.= '\\'. ucfirst($this->_controller);
        if (!class_exists($namespace)) {
            throw new RuntimeException(sprintf(Noah::getInstance()->language->get('core.controller_not_found'), $namespace));
        }
        //定义PATH_NOW常量
        defined('PATH_NOW') || define('PATH_NOW', $path_now);
        Loader::setAlias('~', PATH_NOW);
        //
        $instance = new $namespace();
        if (!$instance instanceof Controller) {
            throw new RuntimeException(sprintf(Noah::getInstance()->language->get('core.controller_extends_error'), '\\Ark\\Core\\Controller'));
        } elseif (!method_exists($instance, $this->_action)) {
            throw new RuntimeException(sprintf(Noah::getInstance()->language->get('core.action_not_found'), $namespace, $this->_action));
        }
        $output = null;
        //自动化类
        if (method_exists($instance, '__init')) {
            $output = $instance->__init();
        }
        //目标控制器行为
        if (is_null($output)) {
            $output = $instance->{$this->_action}();
        }
        return $output;
    }

}
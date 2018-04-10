<?php

namespace Brisk\Assembly;

use Brisk\Contract\ICache;
use Brisk\Contract\IDatabase;
use Brisk\Contract\IRouter;
use Brisk\Contract\ISession;
use Brisk\Contract\IView;
use Brisk\Exception\CacheException;
use Brisk\Exception\DatabaseException;
use Brisk\Exception\RouterException;
use Brisk\Exception\SessionException;
use Brisk\Exception\ViewException;

class Engine
{
    /**
     * 获取驱动器
     *
     * @param null $name
     * @return ICache
     * @throws CacheException
     */
    static function getCacheDriver($name)
    {
        $config = Kernel::getInstance()->config->cache;
        if (!$config || !$config = $config->$name) {
            throw new CacheException(Language::get('cache.config_not_found', $name));
        }
        /* @var Container $config */
        $config = $config->toArray();
        $driver = $config['driver'];
        $save_path = $config['save_path'];
        $option = $config['option'];
        if (!Loader::findClass($driver)) {
            throw new CacheException(Language::get('cache.driver_not_found', $driver));
        }
        $instance = new $driver($save_path, $option);
        if (!$instance instanceof ICache) {
            throw new CacheException(Language::get('cache.driver_implement_error', $driver, 'Brisk\Contract\ICache'));
        }
        Trace::set('driver', array('cache'=> sprintf('%s[%s]', $name, $driver)));
        return $instance;
    }


    /**
     * 获取数据库引擎实例
     *
     * @access public
     * @static
     * @param $name
     * @return mixed
     * @throws DatabaseException
     */
    static function getDatabaseDriver($name)
    {
        $config = Kernel::getInstance()->config->database;
        if (!$config || !$config = $config->$name) {
            throw new DatabaseException(Language::get('db.config_not_found', $name));
        }
        /* @var Container $config */
        $config = $config->toArray();
        $driver = $config['driver'];
        $dsn = $config['dsn'];
        $option = $config['option'];
        if (!Loader::findClass($driver)) {
            throw new DatabaseException(Language::get('db.driver_not_found', $driver));
        }
        $instance = new $driver($dsn, $option);
        if (!$instance instanceof IDatabase) {
            throw new DatabaseException(Language::get('db.driver_implement_error', $driver, 'Brisk\Contract\IDatabase'));
        }
        Trace::set('driver', array('database'=> sprintf('%s[%s]', $name, $driver)));
        return $instance;
    }

    /**
     * 获取路由驱动器
     *
     * @return IRouter
     * @throws RouterException
     */
    static function getRouterDriver()
    {
        $config = Kernel::getInstance()->config->router->toArray();
        if (!$driver = $config['driver']) {
            throw new RouterException(Language::get('router.invalid_driver_name'));
        } elseif (!Loader::findClass($driver)) {
            throw new RouterException(Language::get('router.driver_not_found', $driver));
        }
        $instance = new $driver();
        if (!$instance instanceof IRouter) {
            throw new RouterException(Language::get('router.driver_implement_error', $driver, 'Brisk\Contract\IRouter'));
        }
        Trace::set('driver', array('router'=> $driver));
        return $instance;
    }

    /**
     * 获取会话引擎实例
     *
     * @return ISession
     * @throws SessionException
     */
    static function getSessionDriver()
    {
        $config = Kernel::getInstance()->config->session->toArray();
        if (!$driver = $config['driver']) {
            throw new SessionException(Language::get('sess.invalid_driver_name'));
        } elseif (!Loader::findClass($driver)) {
            throw new SessionException(Language::get('sess.driver_not_found', $driver));
        }
        $instance = new $driver();
        if (!$instance instanceof ISession) {
            throw new SessionException(Language::get('sess.driver_implement_error', $driver, 'Brisk\Contract\ISession'));
        }
        Trace::set('driver', array('session'=> $driver));
        return $instance;
    }

    /**
     * 获取视图引擎实例
     *
     * @return IView
     * @throws ViewException
     */
    static function getViewDriver()
    {
        $config = Kernel::getInstance()->config->view->toArray();
        if (!$driver = $config['driver']) {
            throw new ViewException(Language::get('view.invalid_driver_name'));
        } elseif (!Loader::findClass($driver)) {
            throw new ViewException(Language::get('view.driver_not_found', $driver));
        }
        $instance = new $driver();
        if (!$instance instanceof IView) {
            throw new ViewException(Language::get('view.driver_implement_error', $driver, 'Brisk\Contract\IView'));
        }
        Trace::set('driver', array('view'=> $driver));
        return $instance;
    }

}
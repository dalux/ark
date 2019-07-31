<?php declare(strict_types=1);

namespace Brisk\Kernel;

use Brisk\Cache\CacheAdapter;
use Brisk\Db\DbAdapter;
use Brisk\Session\SessionAdapter;
use Brisk\View\ViewAdapter;

class Adapter
{

    /**
     * 获取数据库驱动器
     *
     * @access public
     * @param string $name
     * @return \Brisk\Db\IDbDriver
     */
    public static function getDbDriver(string $name)
    {
        return DbAdapter::getDriverFromConfig($name);
    }

    /**
     * 获取会话驱动器对象
     *
     * @access public
     * @return \Brisk\Session\ISessionDriver
     */
    public static function getSessionDriver()
    {
        return SessionAdapter::getDriverFromConfig();
    }

    /**
     * 获取缓存驱动器对象
     *
     * @param string $name
     * @return \Brisk\Cache\ICacheDriver
     */
    public static function getCacheDriver(string $name)
    {
        return CacheAdapter::getDriverFromConfig($name);
    }

    /**
     * 获取视图驱动器对象
     *
     * @access public
     * @return \Brisk\View\IViewDriver
     */
    public static function getViewDriver()
    {
        return ViewAdapter::getDriverFromConfig();
    }

}
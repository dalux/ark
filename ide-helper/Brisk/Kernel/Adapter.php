<?php

namespace Brisk\Kernel;

use Brisk\Contract\ICache;
use Brisk\Contract\IDatabase;
use Brisk\Contract\IRouter;
use Brisk\Contract\ISession;
use Brisk\Contract\IView;

class Adapter
{

    /**
     * 获取缓存驱动器
     *
     * @param string $name
     * @return ICache
     */
    public static function getCacheDriver($name) {}

    /**
     * 获取数据库连接驱动器
     *
     * @param string $name
     * @return IDatabase
     */
    public static function getDatabaseDriver($name) {}

    /**
     * 获取路由驱动器
     *
     * @return IRouter
     */
    public static function getRouterDriver() {}

    /**
     * 获取会话驱动器
     *
     * @return ISession
     */
    public static function getSessionDriver() {}

    /**
     * 获取视图驱动器
     *
     * @return IView
     */
    public static function getViewDriver() {}

}

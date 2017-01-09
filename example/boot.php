<?php

//引入框架核心文件
require_once __DIR__. '/../src/Core/Captain.php';

//使用命名空间
use Ark\Core\Captain;
use Ark\Core\Loader;
use Ark\Http\Server;
use Ark\Database\Adapter as DatabaseAdapter;
use Ark\Cache\Adapter as CacheAdapter;

//该文件可以用作多入口模式下的一个公共文件,供其他如admin.php/index.php/user.php等文件包含调用,
//当前,如果你的应用不复杂,也可以只使用该文件当作入口文件即可

//实例化框架
$_ = Captain::getInstance();
//设置应用程序根空间名称及基本路径
$_->setApp('App', Loader::realPath('./mvc/home'))
    //设置配置文件夹路径
    ->setConfigDir(function() {
        $path = Loader::realPath('./config');
        $host = Server::getDomain();
        $full = Server::getDomain(false);
        if (is_dir($dir = $path. '/'. $full)
                || is_dir($dir = $path. '/'. $host)) {
            return $dir;
        }
        return $path. '/localhost';
    })
    //添加钩子程序存放目录
    ->addHookDir(Loader::realPath('*/Hook'))
    //框架启动前的预处理逻辑,可以于此添加一些全局性事务
    ->addPrepare(function() {

        Loader::setNameSpace('App\\Model', Loader::realPath('@/model'));
        Loader::setNameSpace('App\\Helper', Loader::realPath('@/helper'));

        Captain::getInstance()
            ->set('db', function() { return DatabaseAdapter::getDriver('master'); })
            ->set('cache', function() { return CacheAdapter::getDriver('file'); });

    })
    ->run();
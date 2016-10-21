<?php

//引入框架核心文件
require_once __DIR__. '/../src/Core/Noah.php';

//使用命名空间
use Ark\Core\Noah;
use Ark\Core\Loader;
use Ark\Com\Http\Server;
use Ark\Com\Event\Adapter as EventAdapter;
use Ark\Com\Event\RuntimeException;
use Ark\Com\Database\Adapter as DbAdapter;
use Ark\Com\Cache\Adapter as CacheAdapter;

//该文件可以用作多入口模式下的一个公共文件,供其他如admin.php/index.php/user.php等文件包含调用,
//当前,如果你的应用不复杂,也可以只使用该文件当作入口文件即可

//实例化框架
Noah::getInstance()
    //设置应用程序根空间名称及基本路径
    ->setApp('App', Loader::realPath('./'))
    //设置配置文件夹路径
    ->setConfigDir(function() {
        $path = Loader::realPath('./Config');
        $host = Server::getDomain();
        $full = Server::getDomain(false);
        if (is_dir($dir = $path. '/'. $full)
            || is_dir($dir = $path. '/'. $host)) {
            return $dir;
        }
        return $path. '/localhost';
    })
    //将配置文件解析结果缓存起来
    //->cacheConfigTo(Loader::realPath('./runtime'))
    //框架启动前的预处理逻辑,可以于此添加一些全局性事务
    ->addPrepare(function() {

        //添加数据库查询执行前事件,执行些诸如检查SQL语句之类的动作
        EventAdapter::addListener('event.query.before', function($data) {
            //检查SQL语句
            $sql = strtolower($data['sql']);
            if (!preg_match('/^insert|^select|^begin/', $sql)
                && strpos($sql, ' where ') === false) {
                throw new RuntimeException(sprintf('SQL语句缺少"where"条件[%s]', $data['sql']));
            }
            return $data;
        });

        //注册全局性组件,可以于各控制器中直接以$this->{$varname}来调用
        //比如调用下面的db组件, 可能任意控制器或继承Sailor类的实例中调用$this->db
        Noah::getInstance()
            ->set('db', function() { return DbAdapter::getDriver('master'); })
            ->set('cache', function() { return CacheAdapter::getDriver('file'); });

    });
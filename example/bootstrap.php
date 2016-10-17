<?php

//引入框架核心文件
require_once __DIR__. '/../src/Core/Noah.php';

//使用命名空间
use Ark\Core\Noah;
use Ark\Core\Loader;
use Ark\Com\Http\Server;
use Ark\Event\Adapter as EventAdapter;
use Ark\Event\RuntimeException;
use Ark\Com\Database\Adapter as DbAdapter;
use Ark\Com\Cache\Adapter as CacheAdapter;

//实例化框架
Noah::getInstance()
    ->setProfile(function() {
        $path = Loader::realPath('./profile');
        $host = Server::getDomain();
        $full = Server::getDomain(false);
        if (is_dir($dir = $path. '/'. $full)
            || is_dir($dir = $path. '/'. $host)) {
            return $dir;
        }
        return $path. '/localhost';
    }, false)
    ->addPrepare(function() {

        EventAdapter::addListener('event.query.before', function($data) {
            //检查SQL语句
            $sql = strtolower($data['sql']);
            if (!preg_match('/^insert|^select|^begin/', $sql)
                && strpos($sql, ' where ') === false) {
                throw new RuntimeException(sprintf('SQL语句缺少"where"条件[%s]', $data['sql']));
            }
            return $data;
        });

        Noah::getInstance()
            ->set('db', function() { return DbAdapter::getDriver('master'); })
            ->set('cache', function() { return CacheAdapter::getDriver('file'); });


    });
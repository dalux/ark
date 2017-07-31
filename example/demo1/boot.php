<?php

//引入框架核心文件
require_once __DIR__. '/../../src/Core/Captain.php';

//实例化框架
\Ark\Core\Captain::init()
    //设置配置文件夹路径
    ->setConfigDir(function() {
        $path = \Ark\Core\Loader::realPath('./config');
        $host = \Ark\Core\Server::getDomain();
        $full = \Ark\Core\Server::getDomain(false);
        if (is_dir($dir = $path. '/'. $full)
                || is_dir($dir = $path. '/'. $host)) {
            return $dir;
        }
        return $path. '/localhost';
    })
    ->addTriggerDir(\Ark\Core\Loader::realPath('*/Trigger'))
    ->addPrepare(function() {

        //数据库执行前事件
        \Ark\Core\Event::addListener('event.query.before', function($data) {
            //检查SQL语句
            $sql = strtolower($data['sql']);
            if (!preg_match('/^(insert|select|begin)/', $sql)
                    && strpos($sql, ' where ') === false) {
                throw new \Ark\Assembly\Database\Exception(sprintf('SQL语句缺少"where"条件[%s]', $data['sql']));
            }
            return $data;
        });

        //常用组件
        \Ark\Core\Captain::getInstance()
            ->set('session', function() { return \Ark\Assembly\Session::getDriver(); })
            ->set('db', function() { return \Ark\Assembly\Database::getDriver('master'); })
            ->set('cache', function() { return \Ark\Assembly\Cache::getDriver('file'); });

    });
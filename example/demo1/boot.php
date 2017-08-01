<?php

//引入框架核心文件
require_once __DIR__. '/../../src/Core/Noah.php';

//实例化框架
\Ark\Core\Noah::init()
    //设置配置文件夹路径
    ->setConfigPath(\Ark\Core\Loader::realPath('./config/localhost.php'), false)
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
        \Ark\Core\Noah::init()
            ->setMember('session', function() { return \Ark\Assembly\Session::getDriver(); })
            ->setMember('db', function() { return \Ark\Assembly\Database::getDriver('master'); })
            ->setMember('cache', function() { return \Ark\Assembly\Cache::getDriver('file'); });

    });
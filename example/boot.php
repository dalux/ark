<?php

//引入框架核心文件
require_once __DIR__. '/../src/Core/Noah.php';

//实例化框架
\Ark\Core\Ark_Core::init()
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
        \Ark\Core\Ark_Core::init()
            ->setMember('session', function() { return \Ark\Assembly\Session::getDriver(); })
            ->setMember('mysql', function() { return \Ark\Assembly\Database::getDriver('mysql'); })
            ->setMember('oracle', function() { return  \Ark\Assembly\Database::getDriver('oracle'); });

        \Ark\Core\Ark_Core::init()
            ->setMethod('db', function($name = null) {
                if ($name == 'mysql' || is_null($name)) {
                    return \Ark\Core\Ark_Core::init()->mysql;
                } elseif ($name == 'oracle') {
                    return \Ark\Core\Ark_Core::init()->oracle;
                }
            });

    });
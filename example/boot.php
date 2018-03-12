<?php

//引入框架核心文件
require_once __DIR__. '/../src/Core.php';

//实例化框架
Ark_Core::getInstance()
    ->init()
    ->addTriggerDir(Ark_Loader::realPath('*/Trigger'))
    ->addPrepare(function() {

        //数据库执行前事件
        Ark_Event::addListener('event.query.before', function($data) {
            //检查SQL语句
            $sql = strtolower($data['sql']);
            if (!preg_match('/^(insert|select|begin)/', $sql)
                    && strpos($sql, ' where ') === false) {
                throw new Ark_Database_Exception(sprintf('SQL语句缺少"where"条件[%s]', $data['sql']));
            }
            return $data;
        });

        //常用组件
        Ark_Core::init()
            ->setMember('session', function() { return Ark_Session_Adapter::getDriver(); })
            ->setMember('mysql', function() { return Ark_Database_Adapter::getDriver('mysql'); })
            ->setMember('oracle', function() { return  Ark_Database_Adapter::getDriver('oracle'); });

        Ark_Core::init()
            ->setMethod('db', function($name = null) {
                if ($name == 'mysql' || is_null($name)) {
                    return Ark_Core::init()->mysql;
                } elseif ($name == 'oracle') {
                    return Ark_Core::init()->oracle;
                }
            });

    });
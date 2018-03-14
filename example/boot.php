<?php

//引入框架核心文件
require_once __DIR__. '/../src/Core.php';

//实例化框架
Ark_Core::init();
Ark_Core::setApp('App', array(
    'app_path'          => Ark_Loader::realPath('./'),
    'config_path'       => Ark_Loader::realPath('./config/localhost.php'),
    'controller_path'   => Ark_Loader::realPath('./logic'),
));
Ark_Core::setMember('session', function() { return Ark_Session_Adapter::getDriver(); });
Ark_Core::setMember('mysql', function() { return Ark_Database_Adapter::getDriver('mysql'); });
Ark_Core::setMember('oracle', function() { return  Ark_Database_Adapter::getDriver('oracle'); });

Ark_Core::setMethod('db', function($name = null) {
	if ($name == 'mysql' || is_null($name)) {
		return Ark_Core::getInst()->mysql;
	} elseif ($name == 'oracle') {
		return Ark_Core::getInst()->oracle;
	}
});

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

Ark_Core::start();
<?php

//引入框架核心文件
require_once __DIR__. '/../src/Core.php';

//初始化框架
Ark_Core::init();

//设置 app 应用信息
Ark_Core::setApp('App', array(
    'app_path'          => Ark_Loader::realPath('./'),
    'config_path'       => Ark_Loader::realPath('./config/localhost.php'),
    'controller_path'   => Ark_Loader::realPath('./logic'),
));

//框架初始化完毕事件
Ark_Event::addListener('event.framework.ready', function($data) {
	Ark_Loader::setNameSpace('App_Helper', Ark_Loader::realPath('./logic'));
	return $data;
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

//启动框架
Ark_Core::start();
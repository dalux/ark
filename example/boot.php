<?php

//引入框架核心文件
require_once __DIR__. '/../src/Assembly/Core.php';

//初始化框架
\Brisk\Assembly\Core::init();

//设置 app 应用信息
\Brisk\Assembly\Core::setApp('App', array(
    'app_path'          => \Brisk\Assembly\Loader::realPath('./'),
    'config_path'       => \Brisk\Assembly\Loader::realPath('./config/localhost.php'),
    'controller_path'   => \Brisk\Assembly\Loader::realPath('./logic'),
));

//框架初始化完毕事件
\Brisk\Assembly\Event::addListener('event.framework.ready', function($data) {
	\Brisk\Assembly\Loader::setNameSpace('App_Helper', \Brisk\Assembly\Loader::realPath('./logic'));
	return $data;
});

//数据库执行前事件
\Brisk\Assembly\Event::addListener('event.query.before', function($data) {
	//检查SQL语句
	$sql = strtolower($data['sql']);
	if (!preg_match('/^(insert|select|begin)/', $sql)
			&& strpos($sql, ' where ') === false) {
		throw new \Brisk\Exception\DatabaseException(sprintf('SQL语句缺少"where"条件[%s]', $data['sql']));
	}
	return $data;
});

//启动框架
\Brisk\Assembly\Core::start();
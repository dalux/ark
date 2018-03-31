<?php

require_once __DIR__. '/Tracker/Tracker.php';

//设置cookie
Brisk\Assembly\Core::getInst()->container->__tracker__ = array(
    'name'=> 'test',
    'pass'=> '12345678'
);

//注册框架内置事件
Brisk\Assembly\Event::addListener('event.router.ready', function($data) {
    //开启debug模式
    if ($tracker = Brisk\Assembly\Core::getInst()->container->__tracker__) {
        list($name, $pass) = array($tracker->name, $tracker->pass);
        $token = Brisk\Assembly\Core::getInst()->request->cookie($name);
        if ($token == $pass && !Brisk\Assembly\Server::isCli()) {
            Brisk\Assembly\Core::getInst()->config->global->debug = true;
        }
    }
    //Debug内容
    $tracker = new Tracker();
    return $tracker->handle($data);
}, 'open.debug');

//框架结束事件
Brisk\Assembly\Event::addListener('event.framework.shutdown', function($data) {
    $tracker = new Tracker();
    return $tracker->handle($data);
}, 'close.debug');

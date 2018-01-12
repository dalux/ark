<?php

require_once __DIR__. '/Tracker/Tracker.php';

use Ark\Core\Event;
use Ark\Core\Noah;
use Ark\Core\Server;

//设置cookie
Noah::getInstance()->container->__tracker__ = array(
    'name'=> 'test',
    'pass'=> '12345678'
);

//注册框架内置事件
Event::addListener('event.router.ready', function($data) {
    //开启debug模式
    if ($tracker = Noah::getInstance()->container->__tracker__) {
        list($name, $pass) = array($tracker->name, $tracker->pass);
        $token = Noah::getInstance()->request->cookie($name);
        if ($token == $pass && !Server::isCli()) {
            Noah::getInstance()->config->global->debug = true;
        }
    }
    //Debug内容
    $tracker = new Tracker();
    return $tracker->handle($data);
}, 'open.debug');

//框架结束事件
Event::addListener('event.framework.shutdown', function($data) {
    $tracker = new Tracker();
    return $tracker->handle($data);
}, 'close.debug');

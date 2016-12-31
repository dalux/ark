<?php

use Ark\Core\Event;
use Ark\Core\Captain;
use Ark\Http\Server;

return function() {

    require_once __DIR__. '/src/Tracker.php';

    //设置cookie
    Captain::getInstance()->container->__tracker__ = array(
        'name'=> 'test',
        'pass'=> '12345678'
    );

    //注册框架内置事件
    Event::addListener('event.ark.startup', function($data) {
        //开启debug模式
        if ($tracker = Captain::getInstance()->container->__tracker__) {
            list($name, $pass) = array($tracker->name, $tracker->pass);
            $token = Captain::getInstance()->request->cookie($name);
            if ($token == $pass && !Server::isCli()) {
                Captain::getInstance()->config->global->debug = true;
            }
        }
        //Debug内容
        $tracker = new Tracker();
        return $tracker->handle($data);
    });

    //框架结束事件
    Event::addListener('event.ark.shutdown', function($data) {
        $tracker = new Tracker();
        return $tracker->handle($data);
    });

};
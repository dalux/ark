<?php

use Ark\Core\Noah;
use Ark\Com\Http\Server;
use Ark\Com\Event\Adapter as EventAdapter;

return function() {

    require_once __DIR__. '/src/Tracker.php';

    //设置cookie
    Noah::getInstance()->container->__tracker__ = array(
        'name'=> 'test',
        'pass'=> '12345678'
    );

    //注册框架内置事件
    EventAdapter::addListener('event.ark.startup', function($data) {
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
    });

    //框架结束事件
    EventAdapter::addListener('event.ark.shutdown', function($data) {
        $tracker = new Tracker();
        return $tracker->handle($data);
    });

};
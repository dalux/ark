<?php

//模拟原生PHP单入口路由器
return array(
    'driver'=> '\Ark\Assembly\Router\Native',
    'urlsuffix'=> '.html',
    'urlsep'=> '/',
    'default'=> array(
        'controller'=> 'index',
        'action'=> 'index'
    ),
);

<?php

/*
//通用单入口路由器
return array(
    'driver'=> '\Ark\Assembly\Router\Base',
    'urlmode'=> \Ark\Assembly\Router\Base::URL_MODE_REWRITE,
    'urlsuffix'=> '',
    'urlsep'=> '/',
    'urlvar'=> array(
        'module'=> '_m',
        'controller'=> '_c',
        'action'=> '_a',
    ),
    'default'=> array(
        'module'=> '',
        'controller'=> 'index',
        'action'=> 'index',
    ),
);
*/

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

/*
//多入口路由
return array(
    'driver'=> '\Ark\Assembly\Router\Multiple',
    'global_var'=> '_',
    'interceptor'=> '__init__.php',
);
*/
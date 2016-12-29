<?php

/*
//通用路由器
return array(
    'driver'=> '\Ark\Router\Driver\Base',
    'urlmode'=> \Ark\Router\Driver\Base::URL_MODE_REWRITE,
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

//原生PHP路由器
return array(
    'driver'=> '\Ark\Router\Driver\Native',
    'urlsuffix'=> '.html',
    'urlsep'=> '/',
    'default'=> array(
        'controller'=> 'index',
        'action'=> 'index'
    ),
);
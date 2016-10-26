<?php

/*
//通用路由器
return array(
    'driver'=> 'base',
    'urlmode'=> \Ark\Com\Router\Driver\Base::URL_MODE_REWRITE,
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

//模拟原始PHP程序路由
return array(
    'driver'=> 'native',
    'urlsuffix'=> '.html',
    'urlsep'=> '/',
    'default'=> array(
        'controller'=> 'index',
        'action'=> 'startup'
    ),
);
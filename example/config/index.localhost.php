<?php

return array(
    'global'=> array(
        //是否调试模式
        'debug'=> true,
        //时区
        'timezone'=> 'Asia/Shanghai',
        //错误报告级别
        'error_reporting'=> E_ALL^E_NOTICE^E_WARNING^E_DEPRECATED,
    ),
    'router'=> array(
        'driver'=> '\Ark\Assembly\Router\Native',
        'urlsuffix'=> '.html',
        'urlsep'=> '/',
        'default'=> array(
            'controller'=> 'index',
            'action'=> 'index'
        ),
    ),
    'session'=> array(
        'driver'=> '\Ark\Assembly\Session\File',
        'expire_time'=> 1440,
        'save_path'=> \Ark\Core\Loader::realPath('./runtime/session/'),
    ),
    'database'=> array(
        'mysql'=> array(
            'driver'=> '\Ark\Assembly\Database\Pdo\Mysql',
            'dsn'=> 'mysql://root:123456@127.0.0.1:3306/book?charset=utf8',
            'option'=> array(),
        ),
    ),
    'view'=> array(
        'driver'=> '\Ark\Assembly\View\Native',
        'template_ext'=> '.phtml',
        'template_dir'=> \Ark\Core\Loader::realPath('@/view/'),
    ),
);

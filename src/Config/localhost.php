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
        'master'=> array(
            'driver'=> '\Ark\Assembly\Database\Pdo\Mysql',
            'dsn'=> 'mysql://username:password@127.0.0.1:3306/dbname?charset=utf8',
            'option'=> array('type'=> 'new'),
        ),
    ),
    'cache'=> array(
        'file'=> array(
            'driver'=> '\Ark\Assembly\Cache\File',      //文件缓存引擎
            'save_path'=> \Ark\Core\Loader::realPath('./runtime/cache/'),    //缓存文件保存地址
            'option'=> array('ext_name'=> '.cache'),
        ),
        'memcache'=> array(
            'driver'=> '\Ark\Assembly\Cache\Memcached',  //引擎名称，对应缓存类名
            'save_path'=> array('127.0.0.1:11211'),  //memcached服务器地址，单服务器时为'127.0.0.1:11211'
            'option'=> array(),     //初始化连接参数
        ),
    ),
    'view'=> array(
        'driver'=> '\Ark\Assembly\View\Native',
        'template_ext'=> '.phtml',
        'template_dir'=> \Ark\Core\Loader::realPath('@/view/'),
    ),
);
<?php

return array(
    'file'=> array(
        'driver'=> 'file',      //文件缓存引擎
        'save_path'=> \Ark\Core\Loader::realPath('./data/cache/'),    //缓存文件保存地址
        'option'=> array('ext_name'=> '.cache'),
    ),
    'memcache'=> array(
        'driver'=> 'memcached',  //引擎名称，对应缓存类名
        'save_path'=> array('127.0.0.1:11211'),  //memcached服务器地址，单服务器时为'127.0.0.1:11211'
        'option'=> array(),     //初始化连接参数
    ),
);
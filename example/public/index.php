<?php

require_once __DIR__. '/../boot.php';

\Ark\Core\Noah::init()
    //设置应用命名空间及目录
    ->setApp('App', \Ark\Core\Loader::realPath('./logic/index'))
    //设置该应用配置文件夹路径
    ->setConfigPath(\Ark\Core\Loader::realPath('./config/index.localhost.php'))
    ->addPrepare(function() {

    })
    ->run();

<?php

//引入框架核心文件
require_once __DIR__. '/bootstrap.php';

//使用命名空间
use Ark\Core\Noah;
use Ark\Core\Loader;

//实例化框架
Noah::getInstance()
    ->setApp('App', Loader::realPath('./assembly'))
    ->setControllerDir(Loader::realPath('./assembly/Controller/Admin'))
    ->run();
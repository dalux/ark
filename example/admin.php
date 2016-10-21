<?php

require_once __DIR__. '/bootstrap.php';

use Ark\Core\Noah;
use Ark\Core\Loader;

//可以将admin.domain.com类似的子域名请求解析到该admin.php文件上
//实现类似多入口的功能,并且于此文件中指定该入口控制器的根目录到./Controller/Admin下
//以便跟其他域的目录分开

Noah::getInstance()
    ->setControllerDir(Loader::realPath('./Controller/Admin'))
    ->run();
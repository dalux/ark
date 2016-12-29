<?php

require_once __DIR__. '/bootstrap.php';

use Ark\Core\Captain;
use Ark\Core\Loader;

//可以将user.domain.com类似的子域名请求解析到该admin.php文件上
//实现类似多入口的功能,并且于此文件中指定该入口控制器的根目录到./Controller/User下
//以便跟其他域的目录分开,并且可以于此文件中继续调用addPrepare()方法,指定框架运行前的预处理动作

Captain::getInstance()
    ->setControllerDir(Loader::realPath('./mvc/home/Controller/User'))
    ->addPrepare(function() {
        Captain::getInstance()->router->setAllowModule(true);
    })
    ->run();
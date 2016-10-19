<?php

require_once __DIR__. '/bootstrap.php';

use Ark\Core\Noah;

Noah::getInstance()
    ->addPrepare(function() {
        Noah::getInstance()->router->addRouter('/index/index/honghu/\w+/?', '/index/index/name/honghu/age/123');
    })
    ->run();
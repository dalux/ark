<?php

require_once __DIR__. '/boot.php';

use Ark\Core\Loader;
use Ark\Core\Captain;

Captain::getInstance()
    ->setApp('App', Loader::realPath('./app/single'))
    ->addPrepare(function() {

    })
    ->run();
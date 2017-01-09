<?php

require_once __DIR__. '/boot.php';

use Ark\Core\Loader;
use Ark\Core\Captain;

Captain::getInstance()
    ->setApp('Home', Loader::realPath('./app/home'))
    ->addPrepare(function() {

    })
    ->run();
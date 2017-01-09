<?php

require_once __DIR__. '/boot.php';

use Ark\Core\Loader;
use Ark\Core\Captain;

$_ = Captain::getInstance()
    ->setApp('Web', Loader::realPath('./app/multiple'))
    ->addPrepare(function() {

    });

$_->run();
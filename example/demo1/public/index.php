<?php

require_once __DIR__. '/../boot.php';

\Ark\Core\Captain::init()
    ->setApp('App', \Ark\Core\Loader::realPath('./logic/index'))
    ->addPrepare(function() {

    })
    ->run();

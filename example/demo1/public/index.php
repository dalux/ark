<?php

require_once __DIR__. '/../boot.php';

\Ark\Core\Noah::init()
    ->setApp('App', \Ark\Core\Loader::realPath('./logic/index'))
    ->addPrepare(function() {

    })
    ->run();

<?php

require_once __DIR__. '/../boot.php';

\Ark\Core\Noah::init()
    ->setApp('App', \Ark\Core\Loader::realPath('./logic/index'))
    ->setConfigPath(\Ark\Core\Loader::realPath('./config/index.localhost.php'))
    ->addPrepare(function() {

    })
    ->run();

<?php

require_once __DIR__. '/../boot.php';

\Ark\Core\Ark_Core::init()
    ->setApp('App', \Ark\Core\Loader::realPath('./logic/index'))
    ->setConfigPath(\Ark\Core\Loader::realPath('./config/index.localhost.php'))
    ->addPrepare(function() {

    })
    ->run();

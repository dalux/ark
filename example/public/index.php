<?php

require_once __DIR__. '/../boot.php';

Ark_Core::getInst()
    ->setApp('App', Ark_Loader::realPath('./'))
    ->setControllerPath(Ark_Loader::realPath('./logic'))
    ->setConfigPath(Ark_Loader::realPath('./config/localhost.php'))
    ->run();
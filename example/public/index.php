<?php

require_once __DIR__. '/../boot.php';

Ark_Core::getInstance()
    ->setApp('App', Ark_Loader::realPath('./'))
    ->setConfigPath(Ark_Loader::realPath('./config/localhost.php'))
    ->run();
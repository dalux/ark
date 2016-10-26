<?php

require_once __DIR__. '/bootstrap.php';

use Ark\Core\Noah;

Noah::getInstance()
    ->addPrepare(function() {})
    ->run();
<?php

require_once __DIR__. '/bootstrap.php';

use Ark\Core\Captain;

Captain::getInstance()
    ->addPrepare(function() {})
    ->run();
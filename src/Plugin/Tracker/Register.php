<?php

use Brisk\Kernel\Event;
use Brisk\Kernel\Server;
use Brisk\Vendor\Spy\Tracker;

Event::add('event.framework.ready', function($data) {
    if (!Server::isCli()) {
        $tracker = new Tracker();
        $tracker->beginTrace();
    }
    return $data;
});

Event::add('event.framework.shutdown', function($data) {
    if (!Server::isCli()) {
        $tracker = new Tracker();
        $tracker->endTrace();
    }
    return $data;
});
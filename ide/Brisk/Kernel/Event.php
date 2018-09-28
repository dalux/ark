<?php

namespace Brisk\Kernel;


class Event
{

    static private $_listener = array();


    /**
     * Adding event listeners
     *
     * @param string $event
     * @param callable $listener
     * @return null
     */
    public static function add($event, $listener) {}

    /**
     * Gets all listeners for the specified event
     *
     * @param string $event
     * @return array
     */
    public static function get($event) {}

    /**
     * Triggering listener events
     *
     * @param string $event
     * @param array $data
     * @return array
     */
    public static function fire($event, array $data = array()) {}

}

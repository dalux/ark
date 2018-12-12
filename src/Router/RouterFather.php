<?php

namespace Brisk\Router;

abstract class RouterFather
{

    /**
     * Routing ready
     *
     * @return void
     */
    public abstract function ready();

    /**
     * Routing path distribution
     *
     * @return void
     */
    public abstract function dispatch();

}
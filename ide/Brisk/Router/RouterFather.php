<?php

namespace Brisk\Router;


abstract class RouterFather
{

    /**
     * Routing ready
     *
     * @return null
     */
    public abstract function ready();

    /**
     * Routing path distribution
     *
     * @return null
     */
    public abstract function dispatch();

}

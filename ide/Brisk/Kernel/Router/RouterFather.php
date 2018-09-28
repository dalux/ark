<?php

namespace Brisk\Kernel\Router;


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

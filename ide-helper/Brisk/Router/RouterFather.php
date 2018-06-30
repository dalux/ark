<?php

namespace Brisk\Router;

abstract class RouterFather implements \Brisk\Contract\IRouter
{

    /**
     * 路由准备
     *
     * @return mixed
     */
    public abstract function ready();

    /**
     * 路由调度
     *
     * @return mixed
     */
    public abstract function dispatch();

}

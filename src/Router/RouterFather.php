<?php

namespace Brisk\Router;

use Brisk\Contract\IRouter;
use Brisk\Exception\RouterException;

abstract class RouterFather implements IRouter
{

    /**
     * 路由数据准备
     *
     * @return mixed
     */
    abstract function ready();

    /**
     * 路由调度
     *
     * @return mixed
     * @throws RouterException
     */
    abstract function dispatch();


}
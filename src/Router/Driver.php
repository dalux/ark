<?php

namespace Ark\Router;

abstract class Driver
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
     */
    abstract function dispatch();


}
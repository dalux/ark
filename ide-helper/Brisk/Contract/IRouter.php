<?php

namespace Brisk\Contract;

interface IRouter
{

    /**
     * 路由准备动作
     *
     * @return mixed
     */
    public function ready();

    /**
     * 路由调度动作
     *
     * @return mixed
     */
    public function dispatch();

}

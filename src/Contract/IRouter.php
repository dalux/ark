<?php

namespace Ark\Contract;

interface IRouter
{


    /**
     * 路由数据准备就绪
     *
     * @return mixed
     */
    function ready();

    /**
     * 路由调度
     *
     * @return mixed
     */
    function dispatch();


}
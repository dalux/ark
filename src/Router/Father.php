<?php

abstract class Ark_Router_Father implements Ark_Router_Contract
{

    /**
     * 路由数据准备
     *
     * @return mixed
     */
    abstract function ready();

    /**
     * 路由是否准备就绪
     *
     * @return bool
     */
    abstract function isReady();

    /**
     * 路由调度
     *
     * @return mixed
     */
    abstract function dispatch();

    /**
     * 获取模块名称
     *
     * @return mixed
     */
    abstract function getModule();

    /**
     * 获取控制器名称
     *
     * @return mixed
     */
    abstract function getController();

    /**
     * 获取行为名称
     *
     * @return mixed
     */
    abstract function getAction();


}
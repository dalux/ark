<?php

namespace Brisk\Router;

abstract class RouterFather
{

    /**
     * 获取请求地址
     *
     * @return string
     */
    public abstract function getRequest();

    /**
     * 获取当前请求对应的类命名空间
     *
     * @return string
     */
    public abstract function getNameSpace();

    /**
     * 添加URI重写规则
     *
     * @param $rule
     * @param callable $redirect
     * @return RouterFather
     */
    public abstract function addRule($rule, callable $redirect);

    /**
     * 路由准备
     *
     * @return void
     */
    public abstract function ready();

    /**
     * 路由调度
     *
     * @return string
     */
    public abstract function dispatch();

}
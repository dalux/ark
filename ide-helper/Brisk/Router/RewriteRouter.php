<?php

namespace Brisk\Router;

class RewriteRouter extends \Brisk\Router\RouterFather
{

    /**
     * 添加路由重写规则
     *
     * @param string $rule
     * @param mixed $redirect
     * @return null
     */
    public static function addRule($rule, $redirect) {}

    /**
     * 添加命名空间拦截器
     *
     * @param string $namespace
     * @param callable $operator
     * @return null
     */
    public static function addInterceptor($namespace, $operator) {}

    /**
     * 获取当前命名空间已设置的拦截器
     *
     * @param string $namespace
     * @return array
     */
    public static function getInterceptors($namespace) {}

    /**
     * 路由准备
     *
     * @return mixed|void
     */
    public function ready() {}

    /**
     * 路由调度
     *
     * @return mixed|void
     */
    public function dispatch() {}

}

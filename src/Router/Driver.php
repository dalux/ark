<?php

namespace Ark\Router;

abstract class Driver
{

    /**
     * 解析Uri并寻址
     *
     * @param $uri
     * @return mixed
     */
    abstract function doAction($uri);

    /**
     * 添加路径规则
     *
     * @param string $rule
     * @param string $redirect
     * @return $this
     */
    abstract function addRule($rule, $redirect);


}
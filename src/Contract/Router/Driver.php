<?php

namespace Ark\Contract;

interface RouterDriver
{

    /**
     * 解析Uri并寻址
     *
     * @param $uri
     * @return mixed
     */
    function doAction($uri);

    /**
     * 添加路径规则
     *
     * @param string $rule
     * @param string $redirect
     * @return $this
     */
    function addRule($rule, $redirect);


}
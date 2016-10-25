<?php

namespace Ark\Contract;

interface RouterDriver
{

    /**
     * 解析Uri并寻址
     *
     * @param $uri
     * @return array
     */
    function doAction($uri);


}
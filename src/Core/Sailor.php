<?php

namespace Ark\Core;

abstract class Sailor
{

    function __get($name)
    {
        return Noah::getInstance()->get($name);
    }

    function __call($name, $args)
    {
        return Noah::getInstance()->call($name, $args);
    }

}
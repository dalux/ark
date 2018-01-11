<?php

namespace Ark\Core;

abstract class Sailor
{

    function __get($name)
    {
        return Noah::getInstance()->getMember($name);
    }

    function __call($name, $args)
    {
        return Noah::getInstance()->callMethod($name, $args);
    }

}
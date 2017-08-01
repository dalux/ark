<?php

namespace Ark\Core;

abstract class Sailor
{

    function __get($name)
    {
        return Noah::init()->getMember($name);
    }

    function __call($name, $args)
    {
        return Noah::init()->callMethod($name, $args);
    }

}
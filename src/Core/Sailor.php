<?php

namespace Ark\Core;

abstract class Sailor
{

    function __get($name)
    {
        return Noah::init()->get($name);
    }

}
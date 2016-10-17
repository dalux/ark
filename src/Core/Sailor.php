<?php

namespace Ark\Core;

abstract class Sailor
{

    function __get($name)
    {
        return Noah::getInstance()->get($name);
    }

}
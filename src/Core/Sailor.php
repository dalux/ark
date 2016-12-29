<?php

namespace Ark\Core;

abstract class Sailor
{

    function __get($name)
    {
        return Captain::getInstance()->get($name);
    }

}
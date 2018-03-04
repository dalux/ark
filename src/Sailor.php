<?php

abstract class Ark_Sailor
{

    function __get($name)
    {
        return Ark_Core::getInstance()->get($name);
    }

    function __call($name, $args)
    {
        return Ark_Core::getInstance()->call($name, $args);
    }

}
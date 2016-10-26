<?php

namespace App\Controller;

use Ark\Core\Controller;

abstract class Init extends Controller
{

    function __init()
    {
        var_dump('inited');
    }

    function index()
    {
        var_dump('done');
    }

}
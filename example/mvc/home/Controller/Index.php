<?php

namespace App\Controller;

use Ark\Core\Controller;

class Index extends Controller
{

    function __init()
    {
    	echo __METHOD__;
    }

    function index()
    {
    	echo "index method.";
    }

}
<?php

namespace App\Controller;

use Ark\Core\Controller;

class Index extends Controller
{

    function index()
    {
        return $this->display();
    }

}
<?php

namespace App\Controller;

use Ark\Core\Controller;

class Init extends Controller
{

    function __init()
    {
        //这里是自动化类行为
        echo 'hello,';
    }

}
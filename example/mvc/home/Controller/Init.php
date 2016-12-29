<?php

namespace App\Controller;

use Ark\Controller\Base;

abstract class Init extends Base
{

    function __init()
    {
        //这里是自动化类行为
        echo 'hello,';
    }

}
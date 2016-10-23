<?php

namespace App\Controller;

use Ark\Com\Database\SqlBuilder;
use Ark\Core\Controller;

class Index extends Controller
{

    function index()
    {
        echo '欢迎使用Ark框架,有问题请咨询QQ:112183883';
    }

}
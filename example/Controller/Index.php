<?php

namespace App\Controller;

use Ark\Com\Database\SqlBuilder;

class Index extends Init
{

    function index()
    {
        parent::index();
        echo '欢迎使用Ark框架,有问题请咨询QQ:112183883';
    }

}
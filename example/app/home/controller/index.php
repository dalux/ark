<?php

namespace Home\Controller;

use Ark\Core\Sailor;
use Ark\Database\Querier;

class Index extends Sailor
{

    function index()
    {
        $delete = Querier::delete('mysql')
            ->from('users')
            ->where('id=:id', 1, false)
            ->where('uid=:uid', 22)
            ->getSQL();
        echo $delete;
    }

}
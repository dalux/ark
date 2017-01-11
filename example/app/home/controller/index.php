<?php

namespace Home\Controller;

use Ark\Core\Sailor;
use Ark\Database\Querier;

class Index extends Sailor
{

    function index()
    {
        $delete = Querier::select('mysql')
            ->from('users')
            ->where('job=:job', 21)
            ->group(array('name'))
            ->having('id=? and name=:name', 1, 'hong');
        echo $delete->getSQL();
        print_r($delete->getBind());
    }

}
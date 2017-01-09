<?php

namespace Home\Controller;

use Ark\Core\Sailor;

class Index extends Sailor
{

    function index()
    {
        var_dump(__NAMESPACE__. '::'. __METHOD__);
    }

}
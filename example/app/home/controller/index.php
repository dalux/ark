<?php

namespace Home\Controller;

use Ark\Core\Sailor;
use Ark\Core\Toolkit;
use Ark\Core\Trace;
use Ark\Database\Querier;

class Index extends Sailor
{

    function index()
    {
        $data = Querier::select('oci')
            ->from(array('a'=> 'bm_category_2017'), array('*'))
            ->where('a.pid>:pid', 1)
            ->where('a.cid<:cid', 5)
            ->limit(10)
            ->invoke($this->db)
            ->cache(86400, 'bm_category_2017_1', $this->cache)
            ->fetchAll();
        Toolkit::showPrint($data, Trace::get('database'));
    }

}
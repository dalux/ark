<?php

namespace App\Controller;

use Ark\Core\Captain;
use Ark\Core\Sailor;
use Ark\Core\Toolkit;

class Index extends Sailor
{

	function index() 
	{
        Toolkit::Printr(Noah::init()->config->cache->toArray());
		echo 'hello';
	}

}

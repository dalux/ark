<?php

namespace Ark\Com\Session\Driver;

use Ark\Core\Noah;
use Ark\Toolbox\Spanner;

class File extends Father
{

    /**
     * 构造函数
     *
     * @access public
     */
	function __construct()
	{
		$config = Noah::getInstance()->config->session->toArray();
		ini_set('session.save_handler', 'files');
		ini_set('session.cache_expire', $config['expire_time']);
		if (file_exists($config['save_path'])
		        || (!file_exists($config['save_path']) && Spanner::mkdir($config['save_path']))) {
			ini_set('session.save_path', $config['save_path']);
		}
	}
	
}

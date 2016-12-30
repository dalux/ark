<?php

namespace Ark\Session\Driver;

use Ark\Core\Captain;
use Ark\Core\Toolkit;
use Ark\Session\Driver as SessionDriver;

class File extends SessionDriver
{

    /**
     * 构造函数
     *
     * @access public
     */
	function __construct()
	{
		$config = Captain::getInstance()->config->session->toArray();
		ini_set('session.save_handler', 'files');
		ini_set('session.cache_expire', $config['expire_time']);
		if (file_exists($config['save_path'])
		        || (!file_exists($config['save_path']) && Toolkit::mkdir($config['save_path']))) {
			ini_set('session.save_path', $config['save_path']);
		}
	}
	
}
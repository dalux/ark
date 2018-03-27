<?php

namespace Ark\Session;

class FileSession extends SessionFather
{

    /**
     * 构造函数
     *
     * @access public
     */
	function __construct()
	{
		$config = Ark_Core::getInst()->config->session->toArray();
		ini_set('session.save_handler', 'files');
		ini_set('session.cache_expire', $config['expire_time']);
		if (file_exists($config['save_path'])
		        || (!file_exists($config['save_path']) && Ark_Toolkit::mkdir($config['save_path']))) {
			ini_set('session.save_path', $config['save_path']);
		}
	}
	
}

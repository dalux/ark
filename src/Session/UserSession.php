<?php

namespace Brisk\Session;

use Brisk\Contract\ICache;
use Brisk\Assembly\Core;
use Brisk\Assembly\Language;
use Brisk\Exception\SessionException;

class UserSession extends SessionFather
{

    /**
     * 缓存器
     *
     * @var ICache
     */
    protected $_container;

    /**
     * 过期时间
     *
     * @var int
     */
    protected $_expire_time = 86400;

    /**
     * 构造函数
     *
     * @access public
     */
	function __construct()
	{
        $config = Core::getInst()->config->session->toArray();
        //检查
        if ($config['save_path'] instanceof \Closure) {    //支持匿名函数
            $this->_container = $config['save_path']();
        } else {
            $this->_container = $config['save_path'];
        }
        if (!$this->_container instanceof ICache) {
            throw new SessionException(Language::get('sess.cacher_implement_error'), 'Brisk\Contract\ICache');
        }
        $this->_container->setFlag('session');
        $this->_expire_time = $config['expire_time'];
		session_set_save_handler(
			array($this, 'open'), array($this, 'close'), array($this, 'read'),
			array($this, 'write'), array($this, 'destroy'), array($this, 'gc')
		);
	}

    /**
     * sessioin_handler::_open
     *
     * @param string $save_path 保存路径
     * @param string $session_name session名称
     * @return bool
     */
    function open($save_path, $session_name)
    {
    	return true;
    }
    
    /**
     * sessioin_handler::_close
     * 
     * @return bool
     */
    function close()
    {
    	return true;
    }
	
    /**
     * sessioin_handler::_read
     * 
     * @param string $session_id
     * @return mixed
     */
    function read($session_id)
    {
        return $this->_container->get($session_id);
    }
    
    /**
     * sessioin_handler::_write
     * 
     * @param string $session_id
     * @param mixed $session_data
     * @return mixed
     */
    function write($session_id, $session_data)
    {
    	return $this->_container->set($session_id, $session_data, $this->_expire_time);
    }

    /**
     * sessioin_handler::_destroy
     *
     * @param string $session_id
     * @return mixed
     */
    function destroy($session_id)
    {
    	return $this->_container->delete($session_id);
    }

    /**
     * sessioin_handler::_gc
     *
     * @param $max_lifetime
     * @return mixed
     */
    function gc($max_lifetime)
    {
    	//wait...
    }
	
}
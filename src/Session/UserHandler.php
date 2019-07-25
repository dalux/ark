<?php declare(strict_types=1);

namespace Brisk\Session;

use Brisk\Cache\ICacheDriver;
use Brisk\Toolkit\Debugger;
use SessionHandlerInterface;

class UserHandler implements SessionHandlerInterface
{

    /**
     * 数据缓存器
     * 
     * @var ICacheDriver
     */
    private $_cache;

    /**
     * 构造函数
     *
     * @access public
     * @param ICacheDriver $cache
     * @return void
     */
    public function __construct(ICacheDriver $cache)
    {
        $this->_cache = $cache;
    }

    /**
     * 打开session会话连接
     *
     * @access public
     * @param string $save_path
     * @param string $session_name
     * @return bool
     */
    public function open($save_path, $session_name)
    {
        Debugger::vardump('open', $save_path, $session_name);
    	return true;
    }

    /**
     * 关闭session会话连接
     *
     * @access public
     * @return bool
     */
    public function close()
    {
    	return true;
    }

    /**
     * 读取session会话数据
     *
     * @access public
     * @param string $session_id
     * @return mixed
     */
    public function read($session_id)
    {
        Debugger::vardump('read', $session_id);
        return $this->_cache->get($session_id);
    }

    /**
     * 写入session数据
     *
     * @access public
     * @param string $session_id
     * @param string $session_data
     * @return bool
     */
    public function write($session_id, $session_data)
    {
        Debugger::vardump('write', $session_id, $session_data);
    	return $this->_cache->set($session_id, $session_data);
    }

    /**
     * 销毁session数据
     *
     * @access public
     * @param string $session_id
     * @return bool
     */
    public function destroy($session_id)
    {
        Debugger::vardump('destroy', $session_id);
    	return $this->_cache->delete($session_id);
    }

    /**
     * gc
     *
     * @access public
     * @param int $max_lifetime
     * @return bool
     */
    public function gc($max_lifetime)
    {
    	return true;
    }

}
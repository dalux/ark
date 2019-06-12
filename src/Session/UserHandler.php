<?php

namespace Brisk\Session;

use Brisk\Cache\CacheFather;
use SessionHandlerInterface;

class UserHandler implements SessionHandlerInterface
{

    /**
     * @var CacheFather
     */
    private $_cache;

    /**
     * UserHandler constructor.
     *
     * @param CacheFather $cache
     */
    public function __construct(CacheFather $cache)
    {
        $this->_cache = $cache;
    }

    /**
     * @param string $save_path
     * @param string $session_name
     * @return bool
     */
    public function open(string $save_path, string $session_name)
    {
    	return true;
    }

    /**
     * @return bool
     */
    public function close()
    {
    	return true;
    }

    /**
     * @param string $session_id
     * @return mixed|string
     */
    public function read(string $session_id)
    {
        return $this->_cache->get($session_id);
    }

    /**
     * @param string $session_id
     * @param string $session_data
     * @return bool
     */
    public function write(string $session_id, string $session_data)
    {
    	return $this->_cache->set($session_id, $session_data);
    }

    /**
     * @param string $session_id
     * @return bool
     */
    public function destroy(string $session_id)
    {
    	return $this->_cache->delete($session_id);
    }

    /**
     * @param int $max_lifetime
     * @return bool
     */
    public function gc(int $max_lifetime)
    {
    	return true;
    }

}
<?php

namespace Brisk\Session;

abstract class SessionFather
{

    /**
     * @var int
     */
    protected $_expire_time = 1440;

    /**
     * SessionFather constructor.
     * @param array $option
     */
    public function __construct(array $option = [])
    {
        if (isset($option['setting'])) {
            foreach ($option['setting'] as $k=> $v) {
                ini_set($k, $v);
            }
        }
    }

    /**
     * Set the session expire time
     *
     * @param int expire_time
     * @return SessionFather
     */
    public function setExpireTime(int $expire_time = 1440)
    {
        $this->_expire_time = $expire_time;
        return $this;
    }

    /**
     * Start the session service
     *
     * @param int session_id
     * @return null
     */
    public function start(int $session_id = null)
    {
        if (!is_null($session_id)) {
			session_id($session_id);
		}
		session_cache_limiter('private,must-revalidate');
        session_start();
    }

    /**
     * Get Session data
     *
     * @param string name
     * @return mixed
     */
    public function get(string $name = null)
    {
        return is_null($name) ? $_SESSION : $_SESSION[$name];
    }

    /**
     * Set Session data
     *
     * @param string name
     * @param mixed value
     * @return SessionFather
     */
    public function set(string $name, $value)
    {
        $_SESSION[$name] = $value;
        return $this;
    }

    /**
     * Delete Session data
     *
     * @param string name
     * @return SessionFather
     */
    public function delete(string $name)
    {
        unset($_SESSION[$name]);
        return $this;
    }

    /**
     * Clean all Session data
     *
     * @return null
     */
    public function clean()
    {
        return session_destroy();
    }

}
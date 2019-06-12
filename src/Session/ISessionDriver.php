<?php

namespace Brisk\Session;

interface ISessionDriver
{

    /**
     * Start the session service
     *
     * @param int session_id
     * @return null
     */
    public function start(int $session_id = null);

    /**
     * Set the session expire time
     *
     * @param int expire_time
     * @return ISessionDriver
     */
    public function setExpireTime(int $expire_time = 1440);

    /**
     * Get Session data
     *
     * @param string name
     * @return mixed
     */
    public function get(string $name = null);
    
    /**
     * Set Session data
     *
     * @param string name
     * @param mixed value
     * @return ISessionDriver
     */
    public function set(string $name, $value);

    /**
     * Delete Session data
     *
     * @param string name
     * @return ISessionDriver
     */
    public function delete(string $name);

    /**
     * Clean all Session data
     *
     * @return null
     */
    public function clean();

}
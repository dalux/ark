<?php

namespace Brisk\Session;


abstract class SessionFather
{

    protected $_expire_time = 1440;


    /**
     * @param array $option
     */
    public function __construct(array $option = array()) {}

    /**
     * Set the session expire time
     *
     * @param int $expire_time
     * @return SessionFather
     */
    public function setExpireTime($expire_time = 1440) {}

    /**
     * Start the session service
     *
     * @param int $session_id
     * @return null
     */
    public function start($session_id = '') {}

    /**
     * Get Session data
     *
     * @param string $name
     * @return mixed
     */
    public function get($name = '') {}

    /**
     * Set Session data
     *
     * @param string $name
     * @param mixed $value
     * @return SessionFather
     */
    public function set($name, $value) {}

    /**
     * Delete Session data
     *
     * @param string $name
     * @return SessionFather
     */
    public function delete($name) {}

    /**
     * Clean all Session data
     *
     * @return null
     */
    public function clean() {}

    /**
     * @param string $name
     */
    public function __get($name) {}

    /**
     * @param string $name
     * @param mixed $value
     */
    public function __set($name, $value) {}

}

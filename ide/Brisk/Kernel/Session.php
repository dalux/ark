<?php

namespace Brisk\Kernel;


class Session
{

    /**
     * Start the session service
     *
     * @param int $session_id
     * @return null
     */
    public function start($session_id = 0) {}

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
     * @return Session
     */
    public function set($name, $value) {}

    /**
     * Delete Session data
     *
     * @param string $name
     * @return Session
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

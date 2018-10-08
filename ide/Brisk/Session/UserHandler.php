<?php

namespace Brisk\Session;


class UserHandler implements \SessionHandlerInterface
{

    private $_cache;


    /**
     * @param CacheFather $cache
     */
    public function __construct(CacheFather $cache) {}

    /**
     * @param string $save_path
     * @param string $session_name
     */
    public function open($save_path, $session_name) {}


    public function close() {}

    /**
     * @param string $session_id
     */
    public function read($session_id) {}

    /**
     * @param string $session_id
     * @param string $session_data
     */
    public function write($session_id, $session_data) {}

    /**
     * @param string $session_id
     */
    public function destroy($session_id) {}

    /**
     * @param int $max_lifetime
     */
    public function gc($max_lifetime) {}

}

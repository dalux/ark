<?php

namespace Brisk\Session\Driver;


class Redis extends \Brisk\Session\SessionFather
{

    private $_host;


    private $_port;


    private $_password;


    /**
     * @param array $option
     */
    public function __construct(array $option = array()) {}

    /**
     * Start the session service
     *
     * @param string $session_id
     * @return null
     */
    public function start($session_id = '') {}

}

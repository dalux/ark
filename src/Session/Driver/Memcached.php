<?php

namespace Brisk\Session\Driver;

use Brisk\Language;
use Brisk\Session\SessionFather;
use Brisk\Session\UserHandler;
use Brisk\Cache\Driver\Memcached as MemcachedCache;
use Brisk\Exception\ConfigurationException;

class Memcached extends SessionFather
{

    /**
     * @var string
     */
    private $_host;

    /**
     * @var string
     */
    private $_port;

    /**
     * Memcached constructor.
     *
     * @param array $option
     */
    public function __construct(array $option = [])
    {
        if (!isset($option['config'])) {
            throw new ConfigurationException(Language::format('core.config_not_found', 'session/option/config'));
        }
        $server = $option['config'];
        $this->_host = $server['host'];
        $this->_port = $server['port'];
        ini_set('session.save_handler', 'user');
        parent::__construct($option);
    }

    /**
     * Start the session service
     *
     * @param int session_id
     * @return void
     */
    public function start($session_id = null)
    {
        $path = $this->_host. ':'. $this->_port;
        $memcached = new MemcachedCache($path);
        $memcached->setFlag('sess');
        $memcached->setExpireTime($this->_expire_time);
        $handler = new UserHandler($memcached);
        session_set_save_handler($handler, true);
        parent::start($session_id);
    }

}
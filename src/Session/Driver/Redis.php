<?php

namespace Brisk\Session\Driver;

use Brisk\Kernel\Language;
use Brisk\Session\UserHandler;
use Brisk\Session\SessionFather;
use Brisk\Cache\Driver\Redis as RedisCache;
use Brisk\Exception\ConfigurationException;

class Redis extends SessionFather
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
     * @var string
     */
    private $_password;

    /**
     * Redis constructor.
     *
     * @param array $option
     */
    public function __construct(array $option = [])
    {
        if (!isset($option['config'])) {
            throw new ConfigurationException(Language::get('core.config_not_found', 'session/option/config'));
        }
        $server = $option['config'];
        $this->_host = $server['host'];
        $this->_port = $server['port'];
        $this->_password = $server['password'];
        ini_set('session.save_handler', 'user');
        parent::__construct($option);
    }

    /**
     * Start the session service
     *
     * @param int $session_id
     * @return void
     */
    public function start($session_id = null)
    {
        $path = $this->_host. ':'. $this->_port;
        $redis = new RedisCache($path, ['password'=> $this->_password]);
        $redis->setFlag('sess');
        $redis->setExpireTime($this->_expire_time);
        $handler = new UserHandler($redis);
        session_set_save_handler($handler, true);
        parent::start($session_id);
    }
    
}
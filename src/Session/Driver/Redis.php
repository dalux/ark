<?php declare(strict_types=1);

namespace Brisk\Session\Driver;

use Brisk\Kernel\Language;
use Brisk\Session\UserHandler;
use Brisk\Session\SessionFather;
use Brisk\Cache\Driver\Redis as RedisCache;
use Brisk\Exception\RuntimeException;

class Redis extends SessionFather
{

    /**
     * redis主机
     * 
     * @var string
     */
    private $_host;

    /**
     * redis端口
     *
     * @var string
     */
    private $_port;

    /**
     * 密码
     *
     * @var string
     */
    private $_password;

    /**
     * 构造函数
     *
     * @access public
     * @param array $option
     * @return void
     */
    public function __construct(array $option = [])
    {
        if (!isset($option['config'])) {
            throw new RuntimeException(Language::format('core.config_not_found', 'session/option/config'));
        }
        ini_set('session.save_handler', 'user');
        $server = $option['config'];
        $this->_host = $server['host'];
        $this->_port = $server['port'];
        $this->_password = $server['password'];
        if ($server['expire_time']) {
            $this->_expire_time = $server['expire_time'];
        }
        parent::__construct($option);
    }

    /**
     * 开启会话处理
     *
     * @access public
     * @param string $session_id
     * @return void
     */
    public function start(string $session_id = null)
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
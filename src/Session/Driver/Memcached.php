<?php declare(strict_types=1);

namespace Brisk\Session\Driver;

use Brisk\Kernel\Language;
use Brisk\Session\SessionFather;
use Brisk\Session\UserHandler;
use Brisk\Cache\Driver\Memcached as MemcachedCache;
use Brisk\Exception\RuntimeException;

class Memcached extends SessionFather
{

    /**
     * memcached主机地址
     * 
     * @var string
     */
    private $_host;

    /**
     * memcached监听端口
     *
     * @var string
     */
    private $_port;

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
        $memcached = new MemcachedCache($path);
        $memcached->setFlag('sess');
        $memcached->setExpireTime($this->_expire_time);
        $handler = new UserHandler($memcached);
        session_set_save_handler($handler, true);
        parent::start($session_id);
    }

}
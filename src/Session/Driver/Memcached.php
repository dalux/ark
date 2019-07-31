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
     * @param array $setting
     * @return void
     */
    public function __construct(array $setting = [])
    {
        if (!isset($setting['save_path'])
                || strpos($setting['save_path'], ':') === false) {
            throw new RuntimeException(Language::format('core.config_not_found', 'session/setting/save_path'));
        }
        $server = explode(':', $setting['save_path']);
        $this->_host = $server[0];
        $this->_port = $server[1];
        if ($setting['expire_time']) {
            $this->_expire_time = $setting['expire_time'];
        }
        parent::__construct($setting);
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
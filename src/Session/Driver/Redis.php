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
        $this->_password = $setting['password'];
        if (isset($setting['expire_time'])) {
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
        $redis = new RedisCache($path, ['password'=> $this->_password]);
        $redis->setFlag('sess');
        $redis->setExpireTime($this->_expire_time);
        $handler = new UserHandler($redis);
        session_set_save_handler($handler, true);
        parent::start($session_id);
    }
    
}
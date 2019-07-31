<?php declare(strict_types=1);

namespace Brisk\Session\Driver;

use Brisk\Kernel\Language;
use Brisk\Session\UserHandler;
use Brisk\Session\SessionFather;
use Brisk\Cache\Driver\File as FileCache;
use Brisk\Exception\RuntimeException;

class File extends SessionFather
{

    /**
     * 文件缓存路径
     * 
     * @var string
     */
    private $_path;

    /**
     * 构造函数
     *
     * @access public
     * @param array $setting
     * @return void
     */
    public function __construct(array $setting = [])
    {
        if (!isset($setting['save_path'])) {
            throw new RuntimeException(Language::format('core.config_not_found', 'session/setting/save_path'));
        }
        $this->_path = $setting['save_path'];
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
        $cache = new FileCache($this->_path);
        $cache->setFlag('sess');
        $cache->setExpireTime($this->_expire_time);
        $handler = new UserHandler($cache);
        session_set_save_handler($handler, true);
        parent::start($session_id);
    }

}
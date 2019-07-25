<?php declare(strict_types=1);

namespace Brisk\Session\Driver;

use Brisk\Kernel\Language;
use Brisk\Session\UserHandler;
use Brisk\Session\SessionFather;
use Brisk\Cache\Driver\File;
use Brisk\Exception\RuntimeException;

class FileCache extends SessionFather
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
     * @param array $option
     * @return void
     */
    public function __construct(array $option = [])
    {
        if (!isset($option['config'])) {
            throw new RuntimeException(Language::format('core.config_not_found', 'session/option/config'));
        }
        $config = $option['config'];
        $this->_path = $config['save_path'];
        if ($config['expire_time']) {
            $this->_expire_time = $config['expire_time'];
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
        $cache = new File($this->_path);
        $cache->setFlag('sess');
        $cache->setExpireTime($this->_expire_time);
        $handler = new UserHandler($cache);
        session_set_save_handler($handler, true);
        ini_set('session.save_handler', 'user');
        parent::start($session_id);
    }

}
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
     * @var string
     */
    private $_path;

    /**
     * FileCache constructor.
     *
     * @param array $option
     */
    public function __construct(array $option = [])
    {
        if (!isset($option['config'])) {
            throw new RuntimeException(Language::format('core.config_not_found', 'session/option/config'));
        }
        $config = $option['config'];
        $this->_path = $config['path'];
        ini_set('session.save_handler', 'user');
        parent::__construct($option);
    }

    /**
     * Start the session service
     *
     * @param int session_id
     * @return void
     */
    public function start(int $session_id = null)
    {
        $cache = new File($this->_path);
        $cache->setFlag('sess');
        $cache->setExpireTime($this->_expire_time);
        $handler = new UserHandler($cache);
        session_set_save_handler($handler, true);
        parent::start($session_id);
    }

}
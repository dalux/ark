<?php declare(strict_types=1);

namespace Brisk\Session\Driver;

use Brisk\Exception\RuntimeException;
use Brisk\Kernel\Language;
use Brisk\Session\SessionFather;
use Brisk\Toolkit\Dir;

class Native extends SessionFather
{

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
        ini_set('session.save_handler', 'files');
        ini_set('session.cache_expire', (string)$setting['expire_time']);
        $save_path = $setting['save_path'];
        if (!is_dir($save_path) && !Dir::create($save_path, 0600)) {
            throw new RuntimeException(Language::format('core.invalid_session_path', $save_path));
        }
        ini_set('session.save_path', $save_path);
        parent::__construct($setting);
    }

}
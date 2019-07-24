<?php declare(strict_types=1);

namespace Brisk\Session\Driver;

use Brisk\Exception\RuntimeException;
use Brisk\Kernel\Language;
use Brisk\Session\SessionFather;
use Brisk\Toolkit\Dir;

class Files extends SessionFather
{

    public function __construct(array $option = [])
    {
        if (!isset($option['config'])) {
            throw new RuntimeException(Language::format('core.config_not_found', 'session/option/config'));
        }
        $config = $option['config'];
        ini_set('session.save_handler', 'files');
        ini_set('session.cache_expire', (string)$config['expire_time']);
        if (is_dir($config['save_path']) || Dir::create($config['save_path'], 0600)) {
            ini_set('session.save_path', $config['save_path']);
        }
        parent::__construct($option);
    }

}
<?php declare(strict_types=1);

namespace Brisk\Cache;

use Brisk\Kernel\Language;
use Brisk\Exception\RuntimeException;

class Proxy
{

    /**
     * @var ICacheDriver
     */
    private $_cache;

    /**
     * Set cache instance
     *
     * @param ICacheDriver cache
     * @return Proxy
     */
    public function setCacher(ICacheDriver $cache)
    {
        $this->_cache = $cache;
        return $this;
    }

    /**
     * Execute cache proxy
     *
     * @param object target
     * @param string method
     * @param array args
     * @param int expire
     * @param string name
     * @return mixed
     */
    public function do(object $target, string $method, array $args, int $expire = 86400, string $name = null)
    {
        if (!is_callable([$target, $method])) {
            throw new RuntimeException(Language::format('proxy.target_not_callable'));
        }
        $key = $name;
		if ($name == '') {
			$key = $this->_name($target, $method, $args);
		}
        $data = $this->_cache->get($key);
        if ($expire < 1) {
            $data = null;
            $this->_cache->delete($key);
        }
        if (is_null($data)) {
            $data = call_user_func_array([$target, $method], $args);
            if (!is_null($data) && $expire > 0) {
                $this->_cache->set($key, $data, $expire);
            }
        }
        return $data;
    }

    /**
     *
     * @param object $target
     * @param string $func
     * @param array $args
     * @return string
     */
    private function _name(object $target, string $func, array $args)
    {
        return md5(get_class($target). '.'. $func. '.'. serialize($args));
    }

}

<?php

namespace Brisk\Cache;

use Brisk\Kernel\Language;
use Brisk\Exception\RuntimeException;

class CacheProxy
{

    /**
     * @var CacheFather
     */
    private $_cache;

    /**
     * Set cache instance
     *
     * @param CacheFather cache
     * @return CacheProxy
     */
    public function setCacheDriver(CacheFather $cache)
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
    public function doProxy($target, $method, array $args, $expire = 86400, $name = null)
    {
        if (!is_callable([$target, $method])) {
            throw new RuntimeException(Language::get('proxy.target_not_callable'));
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
    private function _name($target, $func, array $args)
    {
        return md5(get_class($target). '.'. $func. '.'. serialize($args));
    }

}

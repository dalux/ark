<?php

namespace Brisk\Cache\Driver;

use Brisk\Kernel\Language;
use Brisk\Cache\CacheFather;
use Brisk\Exception\RuntimeException;

class Memcached extends CacheFather
{

    private $_container;

    /**
     * Construct
     *
     * @param string path
     * @param array setting
     * @return null
     */
    public function __construct($path, array $setting = [])
    {
        if (!extension_loaded('memcached')) {
            throw new RuntimeException(Language::get('cache.extension_load_failed', 'php_memcached'));
        }
        $this->_container = new \Memcached();
        $servers = is_array($path) ? $path : [$path];
        foreach ($servers as $k=> $v) {
            $url = parse_url($v);
            if ($url['host'] && $url['port']) {
                $this->_container->addServer($url['host'], $url['port']);
            }
        }
        $params = [
            \Memcached::OPT_DISTRIBUTION=> \Memcached::DISTRIBUTION_CONSISTENT,
            \Memcached::OPT_LIBKETAMA_COMPATIBLE=> true,
            \Memcached::OPT_CONNECT_TIMEOUT=> 500,
            \Memcached::OPT_COMPRESSION=> true,
            \Memcached::OPT_REMOVE_FAILED_SERVERS=> true
        ];
        if (!is_null($setting['memcached_options']) && is_array($setting['memcached_options'])) {
            $params = array_merge($params, $setting['memcached_options']);
        }
        foreach ($params as $key=> $val) {
            $this->_container->setOption($key, $val);
        }
        $is_valid = false;
        $stats = $this->_container->getStats();
        foreach ($stats as $item) {
            if ($item['pid'] > 0) {
                $is_valid = true;
                break;
            }
        }
        if (!$is_valid) {
            throw new RuntimeException(Language::get('cache.cacher_create_failed', 'Memcached'));
        }
        parent::__construct($setting);
    }

    /**
     * Set Cache data
     *
     * @param string name
     * @param mixed value
     * @param int expire
     * @return bool
     */
    public function set($name, $value, $expire = 0)
    {
        $path = $this->getCachePath($name);
        if ($expire <= 0) {
            $expire_time = $this->_expire_time;
        } else {
            $expire_time = $expire;
        }
        $this->_container->set($path, $value, $expire_time);
        return $this->_container->getResultCode() == \Memcached::RES_SUCCESS;
    }

    /**
     * Get Cache data
     *
     * @param string name
     * @return mixed
     */
    public function get($name)
    {
    	$path = $this->getCachePath($name);
    	if ($this->_caching) {
            $data = $this->_container->get($path);
            $code = $this->_container->getResultCode();
            if ($code != \Memcached::RES_SUCCESS) {
                $data = null;
            }
        }
        return $data;
    }

    /**
     * Delete Cache data
     *
     * @param string name
     * @return bool
     */
    public function delete($name)
    {
        $path = $this->getCachePath($name);
        $this->_container->delete($path);
        $code = $this->_container->getResultCode();
        return $code == \Memcached::RES_SUCCESS;
    }

    /**
     * Get cache data save location
     *
     * @param string name
     * @return string
     */
    public function getCachePath($name)
    {
        $path = '';
        if (!is_null($this->_flag)) {
            $path = $path. $this->_flag. '_';
        }
        if (!is_callable($this->_format)) {
            $this->_format = [$this, '_formatPath'];
        }
		$part = call_user_func_array($this->_format, [$name]);
        if (is_null($part)) {
            throw new RuntimeException(Language::get('cache.path_mustbe_notnull'));
        }
        $result = $path. $part;
        return $result;
    }

    /**
     * Return memcached instance
     *
     * @return \Memcached
     */
    public function getInstance()
    {
        return $this->_container;
    }

    /**
     * @param $name
     * @return string
     */
	private function _formatPath($name)
	{
		return md5($name);
	}

}
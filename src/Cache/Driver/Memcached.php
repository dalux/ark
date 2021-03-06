<?php declare(strict_types=1);

namespace Brisk\Cache\Driver;

use Brisk\Kernel\Language;
use Brisk\Cache\CacheFather;
use Brisk\Exception\RuntimeException;

class Memcached extends CacheFather
{

    /**
     * memcached实例
     *
     * @var \Memcached
     */
    private $_container;

    /**
     * 构造函数
     *
     * @access public
     * @param string $save_path
     * @param array $option
     * @return void
     */
    public function __construct(string $save_path, array $option = [])
    {
        if (!extension_loaded('memcached')) {
            throw new RuntimeException(Language::format('cache.extension_load_failed', 'php_memcached'));
        }
        $this->_container = new \Memcached();
        $servers = is_array($save_path) ? $save_path : [$save_path];
        foreach ($servers as $k=> $v) {
            $server = explode(':', $v);
            if (isset($server[0]) && isset($server[1])) {
                $this->_container->addServer($server[0], $server[1]);
            }
        }
        $params = [
            \Memcached::OPT_DISTRIBUTION            => \Memcached::DISTRIBUTION_CONSISTENT,
            \Memcached::OPT_LIBKETAMA_COMPATIBLE    => true,
            \Memcached::OPT_CONNECT_TIMEOUT         => 500,
            \Memcached::OPT_COMPRESSION             => true,
            \Memcached::OPT_REMOVE_FAILED_SERVERS   => true
        ];
        if (isset($option['memopt'])
                && is_array($option['memopt'])) {
            $params = array_merge($params, $option['memopt']);
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
            throw new RuntimeException(Language::format('cache.cacher_create_failed', 'Memcached'));
        }
        parent::__construct($option);
    }

    /**
     * 设置缓存数据
     *
     * @access public
     * @param string $name
     * @param mixed $value
     * @param int $expire
     * @return bool
     */
    public function set(string $name, $value, int $expire = 0)
    {
        $path = $this->getCachePath($name);
        $expire || $expire = $this->_expire_time;
        if ($expire > 86400 * 30 && $expire < time()) $expire = time() + $expire;
        $this->_container->set($path, $value, $expire);
        return $this->_container->getResultCode() == \Memcached::RES_SUCCESS;
    }

    /**
     * 获取缓存数据
     *
     * @access public
     * @param string $name
     * @return mixed
     */
    public function get(string $name)
    {
    	$path = $this->getCachePath($name);
    	if ($this->_caching) {
            $data = $this->_container->get($path);
            if ($this->_container->getResultCode() != \Memcached::RES_SUCCESS) {
                $data = null;
            }
        }
        return $data;
    }

    /**
     * 删除缓存数据
     *
     * @access public
     * @param string $name
     * @return bool
     */
    public function delete(string $name)
    {
        $path = $this->getCachePath($name);
        $this->_container->delete($path);
        return $this->_container->getResultCode() == \Memcached::RES_SUCCESS;
    }

    /**
     * 获取缓存数据存储路径
     *
     * @access public
     * @param string $name
     * @return string
     */
    public function getCachePath(string $name)
    {
        $path = '';
        if (!is_null($this->_flag)) {
            $path = $path. $this->_flag. '_';
        }
        if (!is_callable($this->_format)) {
            $this->_format = function($name) {
                return md5($name);
            };
        }
		$part = call_user_func_array($this->_format, [$name]);
        if (is_null($part)) {
            throw new RuntimeException(Language::format('cache.path_mustbe_notnull'));
        }
        $result = $path. $part;
        return $result;
    }

    /**
     * 返回memcached实例
     *
     * @access public
     * @return \Memcached
     */
    public function getInstance()
    {
        return $this->_container;
    }

}
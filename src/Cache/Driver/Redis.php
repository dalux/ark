<?php declare(strict_types=1);

namespace Brisk\Cache\Driver;

use Brisk\Kernel\Language;
use Brisk\Cache\CacheFather;
use Brisk\Exception\RuntimeException;

class Redis extends CacheFather
{

    /**
     * @var \Redis
     */
    private $_container;

    /**
     * 构造器
     *
     * @param string $save_path
     * @param array $setting
     * @return null
     */
    public function __construct(string $save_path, array $setting = [])
    {
        if (!extension_loaded('redis')) {
            throw new RuntimeException(Language::format('cache.extension_load_failed', 'php_redis'));
        }
        try {
            $server = explode(':', $save_path);
            $host = $server[0];
            $port = $server[1];
            $timeout = 5;
            if (isset($setting['connect_timeout'])) {
                $timeout = $setting['connect_timeout'];
            }
            $this->_container = new \Redis();
            $this->_container->connect($host, $port, $timeout);
            if (isset($setting['password'])) {
                $this->_container->auth($setting['password']);
            }
            parent::__construct($setting);
        } catch (\Exception $e) {
            throw new RuntimeException(Language::format('cache.cacher_create_failed', 'Redis'));
        }
    }
 
    /**
     * 缓存器设值
     *
     * @param string $name
     * @param mixed $value
     * @param int $expire
     * @return bool
     */
    public function set(string $name, $value, int $expire = 0)
    {
        $path = $this->getCachePath($name);
        $expire || $expire = $this->_expire_time;
        return $this->_container->set($path, serialize($value), $expire);
    }
 
    /**
     * 缓存器取值
     *
     * @param string $name
     * @return bool
     */
    public function get(string $name)
    {
        $path = $this->getCachePath($name);
        $data = null;
        if ($this->_caching) {
            if ($data = $this->_container->get($path)) {
                $data = unserialize($data);
            }
        }
        return $data;
    }
 
    /**
     * 删除缓存数据
     *
     * @param string $name
     * @return mixed
     */
    public function delete(string $name)
    {
        $path = $this->getCachePath($name);
        $this->_container->delete($path);
        return true;
    }
 
    /**
     * 格式化变量名
     *
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
            $this->_format = [$this, '_formatPath'];
        }
		$part = call_user_func_array($this->_format, [$name]);
        if (is_null($part)) {
            throw new RuntimeException(Language::format('cache.path_mustbe_notnull'));
        }
        $result = $path. $part;
        return $result;
    }
 
    /**
     * 返回redis实例
     *
     * @return \Redis
     */
    public function getInstance()
    {
        return $this->_container;
    }

    /**
     * @param string $name
     * @return string
     */
	private function _formatPath(string $name)
	{
		return md5($name);
    }
    
}
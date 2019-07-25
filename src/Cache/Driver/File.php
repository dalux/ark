<?php declare(strict_types=1);

namespace Brisk\Cache\Driver;

use Brisk\Kernel\Language;
use Brisk\Toolkit\Dir;
use Brisk\Cache\CacheFather;
use Brisk\Exception\RuntimeException;

class File extends CacheFather
{

    /**
     * 缓存文件后缀名
     *
     * @var string
     */
	private $_ext_name = '.cache';

    /**
     * 缓存文件存放目录
     *
     * @var string
     */
    private $_dir = '';

    /**
     * 构造器
     *
     * @access public
     * @param string $path
     * @param array $setting
     * @return void
     */
    public function __construct(string $path, array $setting = [])
    {
        $this->_dir = $path;
        if (!is_dir($this->_dir) && !Dir::create($this->_dir)) {
            throw new RuntimeException(Language::format('cache.dir_create_failed', $this->_dir));
        } elseif (!is_readable($this->_dir) || !is_writable($this->_dir)) {
            throw new RuntimeException(Language::format('cache.dir_permission_error', $this->_dir));
        }
        if (!is_null($setting['ext_name'])) {
			$this->_ext_name = $setting["ext_name"];
        }
        parent::__construct($setting);
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
        $expire += time();
        file_put_contents('/tmp/cache.log', $name. ', '. $path. ', '. $expire. ', '. serialize($value). PHP_EOL, FILE_APPEND);
        $writed = file_put_contents($path, $expire. serialize($value));
    	return $writed ? true : false;
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
		if (!file_exists($path) || !$this->_caching) {
			@unlink($path);
			return null;
		}
		$content = file_get_contents($path);
		if ($content === false) {
			unlink($path);
			return null;
        }
		$timeflag = intval(substr($content, 0, 10));
		if ($timeflag < time()) {
			unlink($path);
			return null;
        }
        $tmp = unserialize(substr($content, 10));
		if ($tmp !== false) {
			return $tmp;
		}
		return null;
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
    	if (file_exists($path)) {
			$deleted = unlink($path);
    		return $deleted ? true : false;
    	}
    	return true;
    }

    /**
     * 获取缓存保存完整文件路径
     *
     * @access public
     * @param string $name
     * @return string
     */
    public function getCachePath(string $name)
    {
        $path = rtrim($this->_dir, DIRECTORY_SEPARATOR);
        if (!is_null($this->_flag)) {
            $path = $path. '/'. $this->_flag;
        }
        $path = $path. '/';
        if (!is_callable($this->_format)) {
            $this->_format = function($name) {
                $name = md5($name);
                return substr($name, 0, 1). '/'. substr($name, 1, 1). '/'. $name;
            };
        }
        $part = call_user_func_array($this->_format, [$name]);
        if (is_null($part)) {
            throw new RuntimeException(Language::format('cache.path_mustbe_notnull'));
        }
        $path = $path. $part. $this->_ext_name;
        $path = str_replace(['\\', '/'], DIRECTORY_SEPARATOR, $path);
        if (!file_exists(dirname($path)) && !Dir::create(dirname($path))) {
            throw new RuntimeException(Language::format('cache.dir_create_failed', $path));
        }
        return $path;
    }

    /**
     * 获取文件缓存对象实例
     *
     * @access public
     * @return File
     */
    public function getInstance()
    {
        return $this;
    }

}
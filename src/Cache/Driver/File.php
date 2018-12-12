<?php

namespace Brisk\Cache\Driver;

use Brisk\Kernel\Language;
use Brisk\Kernel\Toolkit;
use Brisk\Cache\CacheFather;
use Brisk\Exception\RuntimeException;

class File extends CacheFather
{

    /**
     * @var string
     */
	private $_ext_name = '.cache';

    /**
     * @var string
     */
    private $_dir = '';

    /**
     * Construct
     *
     * @param string path
     * @param array setting
     * @return void
     */
    public function __construct($path, array $setting = [])
    {
        $this->_dir = $path;
        if (!is_dir($this->_dir) && !Toolkit::mkDir($this->_dir)) {
            throw new RuntimeException(Language::get('cache.dir_create_failed', $this->_dir));
        } elseif (!is_readable($this->_dir) || !is_writable($this->_dir)) {
            throw new RuntimeException(Language::get('cache.dir_permission_error', $this->_dir));
        }
        if (!is_null($setting['ext_name'])) {
			$this->_ext_name = $setting["ext_name"];
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
            $expire_time = time() + $this->_expire_time;
        } else {
            $expire_time = time() + $expire;
        }
    	return file_put_contents($path, $expire_time. serialize($value)) ? true : false;
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
		if (!file_exists($path) || !$this->_caching) {
			unlink($path);
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
     * Delete Cache data
     *
     * @param string name
     * @return bool
     */
    public function delete($name)
    {
        $path = $this->getCachePath($name);
    	if (file_exists($path)) {
			$deleted = unlink($path);
    		return $deleted ? true : false;
    	}
    	return true;
    }

    /**
     * Get cache data save location
     *
     * @param string name
     * @return string
     */
    public function getCachePath($name)
    {
        $path = rtrim($this->_dir, DIRECTORY_SEPARATOR);
        if (!is_null($this->_flag)) {
            $path = $path. '/'. $this->_flag;
        }
        $path = $path. '/';
        if (!is_callable($this->_format)) {
            $this->_format = [$this, '_formatPath'];
        }
        $part = call_user_func_array($this->_format, [$name]);
        if (is_null($part)) {
            throw new RuntimeException(Language::get('cache.path_mustbe_notnull'));
        }
        $path = $path. $part. $this->_ext_name;
        $path = str_replace(['\\', '/'], DIRECTORY_SEPARATOR, $path);
        if (!file_exists(dirname($path)) && !Toolkit::mkDir(dirname($path))) {
            throw new RuntimeException(Language::get('cache.dir_create_failed', $path));
        }
        return $path;
    }

    /**
     *
     * @param $name
     * @return string
     */
	private function _formatPath($name)
	{
		$name = md5($name);
        return substr($name, 0, 1). '/'. substr($name, 1, 1). '/'. $name;
	}
    
}
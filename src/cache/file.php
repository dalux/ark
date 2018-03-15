<?php

class Ark_Cache_File extends Ark_Cache_Father
{
	
	/**i
	 * 缓存文件后缀
	 * 
	 * @access private
	 * @var string
	 */
	private $_ext_name = '.cache';
	
    /**
     * 缓存目录
     *
     * @access private
     * @var string
     */
    private $_dir = '';

    /**
     * 构造器
     *
     * @param $save_path
     * @param array $option
     * @throws Ark_Exception
     * @throws Ark_Cache_Exception
     */
    function __construct($save_path, array $option = array())
    {
        $this->_dir = $save_path;
        if (!is_dir($this->_dir) && !Ark_Toolkit::mkDir($this->_dir)) {
            throw new Ark_Cache_Exception(Ark_Language::get('cache.dir_create_failed', $this->_dir));
        } elseif (!is_readable($this->_dir) || !is_writable($this->_dir)) {
            throw new Ark_Cache_Exception(Ark_Language::get('cache.dir_permission_error', $this->_dir));
        }
        is_null($option['ext_name']) || $this->_ext_name = $option['ext_name'];
        is_null($option['flag']) || $this->_flag = $option['flag'];
    }

    /**
     * 缓存设值
     *
     * @access public
     * @param string $name
     * @param mixed $value
     * @param mixed $expire
     * @return bool
     * @throws Ark_Exception
     */
    function set($name, $value, $expire = 86400)
    {
    	$path = $this->getCachePath($name);
        $expire_time = time() + $expire;
    	return file_put_contents($path, $expire_time . serialize($value)) ? true : false;
    }

    /**
     * 缓存取值
     *
     * @access public
     * @param string $name
     * @return mixed
     * @throws Ark_Exception
     * @throws Ark_Cache_Exception
     */
    function get($name)
    {
    	$path = $this->getCachePath($name);
        if (!file_exists($path)
                || !$this->_caching
                || !($content = file_get_contents($path))
                || intval(substr($content, 0, 10)) < time()) {
            @unlink($path);
            return null;
        }
        $tmp = @unserialize(substr($content, 10));
        return $tmp !== false ? $tmp : null;
    }

    /**
     * 删除数据缓存
     *
     * @access public
     * @param $name
     * @return bool
     * @throws Ark_Exception
     */
    function delete($name)
    {
    	$path = $this->getCachePath($name);
    	if (file_exists($path)) {
    		return @unlink($path) ? true : false;
    	}
    	return true;
    }

    /**
     * 将数据缓存到指定位置
     *
     * @access public
     * @param string $name
     * @param $value
     * @return bool
     * @throws Ark_Exception
     */
    function __set($name, $value)
    {
    	return $this->set($name, $value);
    }

    /**
     * 取得缓存数据
     *
     * @access public
     * @param string $name
     * @return mixed
     * @throws Ark_Exception
     */
    function __get($name)
    {
        return $this->get($name);
    }

    /**
     * 取得缓存文件路径
     *
     * @access private
     * @param string $name
     * @return string
     * @throws Ark_Exception
     * @throws Ark_Cache_Exception
     */
    function getCachePath($name)
    {
        $path = rtrim($this->_dir, DIRECTORY_SEPARATOR);
        if ($this->_flag) {
            $path.= "/{$this->_flag}";
        }
        $path.= '/';
        if (!$this->_format instanceof Closure || !is_callable($this->_format)) {
            $this->_format = function($name) {
                $name = md5($name);
                return "{$name[0]}/{$name[1]}/{$name}";
            };
        }
        $format = $this->_format;
        if (!$part = $format($name)) {
            throw new Ark_Cache_Exception(Ark_Language::get('cache.path_mustbe_notnull'));
        }
        $path.= $part. $this->_ext_name;
        $path = str_replace(array('\\', '/'), DIRECTORY_SEPARATOR, $path);
        if (!file_exists(dirname($path)) && !Ark_Toolkit::mkDir(dirname($path))) {
            throw new Ark_Cache_Exception(Ark_Language::get('cache.dir_create_failed', $path));
        }
        return $path;
    }
    
}
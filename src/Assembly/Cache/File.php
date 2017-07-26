<?php

namespace Ark\Assembly\Cache;

use Ark\Core\Captain;
use Ark\Core\Toolkit;

class File extends Father
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
     * @throws Exception
     */
    function __construct($save_path, array $option = array())
    {
        $this->_dir = $save_path;
        if (!is_dir($this->_dir) && !Toolkit::mkDir($this->_dir)) {
            throw new Exception(sprintf(Captain::getInstance()->lang->get('cache.dir_create_failed'), $this->_dir));
        } elseif (!is_readable($this->_dir) || !is_writable($this->_dir)) {
            throw new Exception(sprintf(Captain::getInstance()->lang->get('cache.dir_permission_error'), $this->_dir));
        }
        is_null($option['ext_name']) || $this->_ext_name = $option['ext_name'];
        is_null($option['flag']) || $this->_flag = $option['flag'];
        is_null($option['allow_format']) || $this->_allow_format = (bool)$option['allow_format'];
    }

    /**
     * 缓存设值
     * 
     * @access public
     * @param string $name
     * @param mixed $value
     * @param mixed $expire
     * @return bool
     */
    function set($name, $value, $expire = null)
    {
        $expire || $expire = $this->_expire_time;
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
     */
    function get($name)
    {
    	$path = $this->getCachePath($name);
        if (!file_exists($path)
                || !$this->_allow_cache
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
     * @throws Exception
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
     * @throws Exception
     */
    function getCachePath($name)
    {
        $path = rtrim($this->_dir, DIRECTORY_SEPARATOR);
        if ($this->_flag) {
            $path.= "/{$this->_flag}";
        }
        if ($this->_allow_format) {
            if (strpos($name, '.') === false) {
                $name = md5($name);
                $path.= "/{$name[0]}/{$name[1]}/";
            } else {
                $names = explode('.', $name);
                array_pop($names);
                $names = implode('/', $names);
                $path.= "/{$names}/";
            }
        } else {
            $path.= "/";
        }
        $path = str_replace(array('\\', '/'), DIRECTORY_SEPARATOR, $path);
        if (!file_exists($path) && !Toolkit::mkDir($path)) {
            throw new Exception(sprintf(Captain::getInstance()->lang->get('cache.dir_create_failed'), $path));
        }
        return $path. $name. $this->_ext_name;
    }
    
}
<?php

namespace Ark\Http;

class Request
{

    /**
     * GET类型
     *
     * @var int
     */
    const FLAG_GET = 1;

    /**
     * POST类型
     *
     * @var int
     */
    const FLAG_POST = 2;

    /**
     * FILE类型
     *
     * @var int
     */
    const FLAG_FILE = 3;

    /**
     * 请求对象实例
     *
     * @var Request
     */
    private static $_instance;

	/**
	 * 所有请求数据
	 *
	 * @access private
	 * @var array
	 */
	private $_request = array();

	/**
	 * get请求数据
	 *
	 * @access private
	 * @var array
	 */
	private $_get = array();

	/**
	 * post请求数据
	 *
	 * @access private
	 * @var array
	 */
	private $_post = array();

    /**
     * 文件上传数据
     *
     * @access private
     * @var array
     */
	private $_files = array();

    /**
     * 取请求实例
     *
     * @return Request
     */
    static function getInstance()
    {
        if (is_null(self::$_instance)) {
            self::$_instance = new self();
        }
        return self::$_instance;
    }

    /**
     * 构造器
     *
     */
    private function __construct()
    {
        $this->_get = $_GET;
        $this->_post = $_POST;
        $this->_request = $_REQUEST;
        $this->_files = $_FILES;
        $_GET = $_POST = $_REQUEST = $_FILES = array();
    }

    /**
     * 当前是否是post请求
     *
     * @access public
     * @param null $name
     * @return bool
     */
	function isPost($name = null)
	{
        $ispost = "POST" == strtoupper($_SERVER["REQUEST_METHOD"]);
        if ($ispost && $name) {
            return isset($this->_post[$name]) && !empty($this->_post[$name]);
        }
        return $ispost;
	}

    /**
     * 当前请求是否ajax请求
     *
     * @access public
     * @return bool
     */
    function isAjax()
    {
        if (isset($_SERVER['HTTP_X_REQUESTED_WITH'])) {
            return $_SERVER['HTTP_X_REQUESTED_WITH'] == 'XMLHttpRequest';
        }
        return false;
    }

    /**
     * 获取来访者IP地址
     *
     * @access public
     * @param bool $convert
     * @return string
     */
    function getIpAddress($convert = false)
    {
        static $ip;
        if (is_null($ip)){
            $ips = array();
            isset($_SERVER['HTTP_CLIENT_IP']) && $ips[] = $_SERVER['HTTP_CLIENT_IP'];
            if (isset($_SERVER['HTTP_X_FORWARDED_FOR'])) {
                foreach (explode(',', $_SERVER['HTTP_X_FORWARDED_FOR']) as $ip) {
                    $ips[] = $ip;
                }
            }
            isset($_SERVER['HTTP_X_FORWARDED']) && $ips[] = $_SERVER['HTTP_X_FORWARDED'];
            isset($_SERVER['HTTP_FORWARDED_FOR']) && $ips[] = $_SERVER['HTTP_FORWARDED_FOR'];
            isset($_SERVER['HTTP_FORWARDED']) && $ips[] = $_SERVER['HTTP_FORWARDED'];
            isset($_SERVER['REMOTE_ADDR']) && $ips[] = $_SERVER['REMOTE_ADDR'];
            $ips = array_filter($ips);
            while (($ip = array_shift($ips))) {
                if (false !== ip2long($ip)) {
                    break;
                }
            }
        }
        return $convert ? sprintf('%u', ip2long($ip)) : $ip;
    }

    /**
     * 获取客户端请求时的cookie
     *
     * @access public
     * @static
     * @param string $name
     * @param null $default
     * @return mixed
     */
    function cookie($name = null, $default = null)
    {
        if (is_null($name)) {
            return $_COOKIE;
        }
        $value = $_COOKIE[$name];
        return is_null($value) ? $default : $value;
    }

    /**
     * 取GET数据
     *
     * @access public
     * @param null $name
     * @param null $default
     * @return mixed
     */
    function get($name = null, $default = null)
    {
        if (is_null($name)) {
            return $this->_get;
        }
        $value = $this->_get[$name];
        return is_null($value) ? $default : $value;
    }

    /**
     * 取POST数据
     *
     * @access public
     * @param null $name
     * @param null $default
     * @return mixed
     */
    function post($name = null, $default = null)
    {
        if (is_null($name)) {
            return $this->_post;
        }
        $value = $this->_post[$name];
        return is_null($value) ? $default : $value;
    }

    /**
     * 取FILES数据
     *
     * @access public
     * @param null $name
     * @param null $default
     * @return mixed
     */
    function files($name = null, $default = null)
    {
        if (is_null($name)) {
            return $this->_files;
        }
        $value = $this->_files[$name];
        return is_null($value) ? $default : $value;
    }

    /**
     * 新增请求数据
     *
     * @param string $name
     * @param mixed $value
     * @param int $flag
     * @return mixed
     */
    function add($name, $value, $flag)
    {
        if ($flag == self::FLAG_GET) {
            $this->_request[$name] = $this->_get[$name] = $value;
        } elseif ($flag == self::FLAG_POST) {
            $this->_request[$name] = $this->_post[$name] = $value;
        }
    }

    /**
     * 删除请求项
     *
     * @param string $flag
     * @param null $name
     * @return mixed
     */
    function del($flag, $name = null)
    {
        if ($flag == self::FLAG_GET) {
            if (!is_null($name) && isset($this->_get[$name])) {
                unset($this->_get[$name], $this->_request[$name]);
            } elseif (is_null($name)) {
                foreach ($this->_get as $k=> $v) {
                    unset($this->_get[$k], $this->_request[$k]);
                }
            }
        } elseif ($flag == self::FLAG_POST) {
            if (!is_null($name) && isset($this->_post[$name])) {
                unset($this->_post[$name], $this->_request[$name]);
            } elseif (is_null($name)) {
                foreach ($this->_post as $k=> $v) {
                    unset($this->_post[$k], $this->_request[$k]);
                }
            }
        }
    }

    /**
     * 取所有数据
     *
     * @access public
     * @param null $name
     * @param null $default
     * @return mixed
     */
    function data($name = null, $default = null)
    {
        if (is_null($name)) {
            return $this->_request;
        }
        $value = $this->_request[$name];
        return is_null($value) ? $default : $value;
    }

    /**
     * 取数据
     *
     * @access public
     * @param string $name
     * @return mixed
     */
    function __get($name)
    {
        if (isset($this->_request[$name])) {
            return $this->_request[$name];
        }
        return null;
    }

}


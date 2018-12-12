<?php

namespace Brisk\Http;

use Brisk\Kernel\Event;
use Brisk\Kernel\Language;
use Brisk\Exception\RuntimeException;

class Request
{

    private static $_instance;
	private static $_ready  = false;
	private static $_data   = [];

	private $_request       = [];
	private $_get           = [];
	private $_post          = [];
	private $_files         = [];
    private $_cookie        = [];

    /**
     * Set Request data
     *
     * @param array data
     * @return null
     */
	public static function setData(array $data)
	{
		self::$_data = array_merge(self::$_data, $data);
	}

    /**
     * Set the request readiness State
     *
     * @param bool state
     * @return void
     */
    public static function setReady($state)
    {
		self::$_ready = $state;
	}

    /**
     * Get the Request component instance
     *
     * @return Request
     */
    public static function getInstance()
    {
        if (!self::$_ready) {
            throw new RuntimeException(Language::get('http.request_not_ready'));
        } elseif (is_null(self::$_instance)) {
			self::$_instance = new self();
		}
        return self::$_instance;
    }

    /**
     * construct
     *
     * @return null
     */
    private function __construct()
    {
		$data = ['get'=> self::$_data, 'post'=> $_POST, 'cookie'=> $_COOKIE, 'files'=> $_FILES];
		$data = Event::trigger('event.request.ready', $data);
        $this->_get = $data['get'];
        $this->_post = $data['post'];
        $this->_cookie = $data['cookie'];
        $this->_files = $data['files'];
        $this->_request = array_merge($this->_get, $this->_post);
    }

    /**
     * Check if request is post
     *
     * @return bool
     */
	public static function isPost()
	{
        return 'POST' == strtoupper($_SERVER['REQUEST_METHOD']);
	}

    /**
     * Check if request is ajax
     *
     * @return bool
     */
    public static function isAjax()
    {
        if (isset($_SERVER['HTTP_X_REQUESTED_WITH'])) {
            return $_SERVER['HTTP_X_REQUESTED_WITH'] == 'XMLHttpRequest';
        }
        return false;
    }

    /**
     * Get client IP Address
     *
     * @param bool $convert
     * @return string
     */
    public static function getIpAddress($convert = false)
    {
		$ips = [];
		if (isset($_SERVER['HTTP_CLIENT_IP'])) {
			$ips[] = $_SERVER['HTTP_CLIENT_IP'];
		}
		if (isset($_SERVER['HTTP_X_FORWARDED_FOR'])) {
			$forwarded = explode(',', $_SERVER['HTTP_X_FORWARDED_FOR']);
			foreach ($forwarded as $ip) {
				$ips[] = $ip;
			}
		}
		if (isset($_SERVER['HTTP_X_FORWARDED'])) {
			$ips[] = $_SERVER['HTTP_X_FORWARDED'];
		}
		if (isset($_SERVER['HTTP_FORWARDED_FOR'])) {
			$ips[] = $_SERVER['HTTP_FORWARDED_FOR'];
		}
		if (isset($_SERVER['HTTP_FORWARDED'])) {
			$ips[] = $_SERVER['HTTP_FORWARDED'];
		}
		if (isset($_SERVER['REMOTE_ADDR'])) {
			$ips[] = $_SERVER['REMOTE_ADDR'];
		}
		$ips = array_filter($ips);
		$ip = '';
		while (true) {
			$ip = array_shift($ips);
			if (false !== ip2long($ip)) {
				break;
			}
		}
        return $convert ? sprintf('%u', ip2long($ip)) : $ip;
    }

    /**
     * Get the request data for the GET method
     *
     * @param string $name
     * @param string $default
     * @return mixed
     */
    public function get($name, $default = null)
    {
        return isset($this->_get[$name])
            ? $this->_get[$name]
            : $default;
    }

    /**
     * Get the request data for the POST method
     *
     * @param string name
     * @param string $default
     * @return mixed
     */
    public function post($name, $default = null)
    {
        return isset($this->_post[$name])
            ? $this->_post[$name]
            : $default;
    }

    /**
     * Get the request data for the COOKIE method
     *
     * @param string name
     * @param string $default
     * @return string
     */
    public function cookie($name, $default = null)
    {
        return isset($this->_cookie[$name])
            ? $this->_cookie[$name]
            : $default;
    }

    /**
     * Get the request data for the FILES method
     *
     * @param string name
     * @param array $default
     * @return array
     */
    public function files($name, $default = array())
    {
        return isset($this->_files[$name])
            ? $this->_files[$name]
            : $default;
    }

    /**
     * Get the request data
     *
     * @param string name
     * @param string alternative
     * @return mixed
     */
    public function data($name, $default = null)
    {
		return isset($this->_request[$name])
            ? $this->_request[$name]
            : $default;
    }

    /**
     * 获取所有请求数据
     *
     * @return array
     */
    public function toArray()
    {
        return [
            'get'   => $this->_get,
            'post'  => $this->_post,
            'cookie'=> $this->_cookie,
            'files' => $this->_files
        ];
    }

}


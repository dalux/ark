<?php

namespace Brisk\Kernel;

use Brisk\Exception\RuntimeException;

class Request
{

	private static $_ready      = false;
	private static $_data       = [];
	private static $_request    = [];
	private static $_get        = [];
	private static $_post       = [];
    private static $_cookie     = [];

    /**
     * Set the request readiness State
     *
     * @param bool state
     * @return void
     */
    public static function ready(array $data)
    {
        self::$_data = array_merge(self::$_data, $data);
        $data = ['get'=> self::$_data, 'post'=> $_POST, 'cookie'=> $_COOKIE];
        $data = Event::trigger('event.request.ready', $data);
        $_GET = self::$_get = $data['get'];
        $_POST = self::$_post = $data['post'];
        $_COOKIE = self::$_cookie = $data['cookie'];
        $_REQUEST = self::$_request = array_merge(self::$_get, self::$_post, self::$_cookie);
		self::$_ready = true;
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
		isset($_SERVER['HTTP_CLIENT_IP'])       && $ips[] = $_SERVER['HTTP_CLIENT_IP'];
		if (isset($_SERVER['HTTP_X_FORWARDED_FOR'])) {
			$forwarded = explode(',', $_SERVER['HTTP_X_FORWARDED_FOR']);
			foreach ($forwarded as $ip) {
				$ips[] = $ip;
			}
		}
		isset($_SERVER['HTTP_X_FORWARDED'])     && $ips[] = $_SERVER['HTTP_X_FORWARDED'];
		isset($_SERVER['HTTP_FORWARDED_FOR'])   && $ips[] = $_SERVER['HTTP_FORWARDED_FOR'];
		isset($_SERVER['HTTP_FORWARDED'])       && $ips[] = $_SERVER['HTTP_FORWARDED'];
		isset($_SERVER['REMOTE_ADDR'])          && $ips[] = $_SERVER['REMOTE_ADDR'];
		$ip = '';
		$ips = array_filter($ips);
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
    public static function get($name = null, $default = null)
    {
        if (!self::$_ready) {
            throw new RuntimeException(Language::get('core.request_not_ready'));
        }
        if (is_null($name)) {
            return self::$_get;
        }
        return isset(self::$_get[$name])
            ? self::$_get[$name]
            : $default;
    }

    /**
     * Get the request data for the POST method
     *
     * @param string name
     * @param string $default
     * @return mixed
     */
    public static function post($name = null, $default = null)
    {
        if (!self::$_ready) {
            throw new RuntimeException(Language::get('core.request_not_ready'));
        }
        if (is_null($name)) {
            return self::$_post;
        }
        return isset(self::$_post[$name])
            ? self::$_post[$name]
            : $default;
    }

    /**
     * Get the request data for the POST method
     *
     * @param string name
     * @param string $default
     * @return mixed
     */
    public static function cookie($name = null, $default = null)
    {
        if (!self::$_ready) {
            throw new RuntimeException(Language::get('core.request_not_ready'));
        }
        if (is_null($name)) {
            return self::$_cookie;
        }
        return isset(self::$_cookie[$name])
            ? self::$_cookie[$name]
            : $default;
    }

    /**
     * Get the request data
     *
     * @param string name
     * @param string alternative
     * @return mixed
     */
    public static function data($name = null, $default = null)
    {
        if (!self::$_ready) {
            throw new RuntimeException(Language::get('core.request_not_ready'));
        }
        if (is_null($name)) {
            return self::$_request;
        }
		return isset(self::$_request[$name])
            ? self::$_request[$name]
            : $default;
    }

}


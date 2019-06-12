<?php declare(strict_types=1);

namespace Brisk\Http;

use Brisk\Event;
use Brisk\Language;
use Brisk\Exception\RuntimeException;

class Request
{

    const TYPE_GET              = 'get';
    const TYPE_POST             = 'post';
    const TYPE_COOKIE           = 'cookie';
    const TYPE_FILES            = 'files';

	private static $_ready      = false;
	private static $_request    = [];
	private static $_get        = [];
	private static $_post       = [];
    private static $_cookie     = [];
    private static $_files      = [];

    /**
     * Set the request readiness State
     *
     * @param bool state
     * @return void
     */
    public static function ready(array $data)
    {
        $data = [
            self::TYPE_GET      => $data, 
            self::TYPE_POST     => $_POST, 
            self::TYPE_COOKIE   => $_COOKIE, 
            self::TYPE_FILES    => $_FILES
        ];
        $data = Event::fire('event.request.ready', $data);
        self::$_get         = $data[self::TYPE_GET];
        self::$_post        = $data[self::TYPE_POST];
        self::$_cookie      = $data[self::TYPE_COOKIE];
        self::$_files       = $data[self::TYPE_FILES];
        self::$_request     = array_merge(self::$_get, self::$_post, self::$_cookie);
        self::$_ready       = true;
        $_GET               = self::$_get;
        $_POST              = self::$_post;
        $_COOKIE            = self::$_cookie;
        $_REQUEST           = self::$_request;
        $_FILES             = self::$_files;
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
        return 'XMLHttpRequest' == $_SERVER['HTTP_X_REQUESTED_WITH'];
    }

    /**
     * Get the request data for the GET method
     *
     * @param string name
     * @param string sub
     * @return mixed
     */
    public static function get(string $name = null, $sub = null)
    {
        self::check();
        return is_null($name) 
            ? self::$_get
            : self::$_get[$name] ?? $sub;
    }

    /**
     * Get the request data for the POST method
     *
     * @param string name
     * @param string sub
     * @return var
     */
    public static function post(string $name = null, $sub = null)
    {
        self::check();
        return is_null($name)
            ? self::$_post
            : self::$_post[$name] ?? $sub;
    }

    /**
     * Get the request data for the POST method
     *
     * @param string name
     * @param string sub
     * @return var
     */
    public static function cookie(string $name = null, $sub = null)
    {
        self::check();
        return is_null($name)
            ? self::$_cookie
            : self::$_cookie[$name] ?? $sub;
    }

    /**
     * Get the request data for the files method
     *
     * @param string name
     * @return var
     */
    public static function files(string $name = null)
    {
        self::check();
        return is_null($name) 
            ? self::$_files 
            : self::$_files[$name];
    }

    /**
     * Get the request data
     *
     * @param string name
     * @param string sub
     * @return var
     */
    public static function data(string $name = null, $sub = null)
    {
        self::check();
        return is_null($name)
            ? self::$_request
            : self::$_request[$name] ?? $sub;
    }

    /**
     * 添加request请求数据项
     *
     * @param string type
     * @param string name
     * @param var data
     * @return void
     */
    public static function add(string $type, string $name, $data)
    {
        self::check();
        switch ($type) {
            case self::TYPE_GET:
                self::$_get[$name] = $data;
                $_GET = self::$_get;
                break;
            case self::TYPE_POST:
                self::$_post[$name] = $data;
                $_POST = self::$_post;
                break;
            case self::TYPE_COOKIE:
                self::$_cookie[$name] = $data;
                $_COOKIE = self::$_cookie;
                break;
        }
        $_REQUEST = self::$_request 
            = array_merge(self::$_get, self::$_post, self::$_cookie);
    }

    /**
     * 删除request请求数据项
     *
     * @param string type
     * @param string name
     * @param var data
     * @return void
     */
    public static function delete(string $type, string $name)
    {
        self::check();
        switch ($type) {
            case self::TYPE_GET:
                unset(self::$_get[$name]);
                $_GET = self::$_get;
                break;
            case self::TYPE_POST:
                unset(self::$_post[$name]);
                $_POST = self::$_post;
                break;
            case self::TYPE_COOKIE:
                unset(self::$_cookie[$name]);
                $_COOKIE = self::$_cookie;
                break;
        }
        $_REQUEST = self::$_request 
            = array_merge(self::$_get, self::$_post, self::$_cookie);
    }

    /**
     * 请求是否准备就绪
     * 
     * @return void
     */
    public static function check()
    {
        if (!self::$_ready) {
            $error = Language::format('core.request_not_ready');
            throw new RuntimeException($error);
        }
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
        if ($ips = array_filter($ips)) {
            while (true) {
                $ip = array_shift($ips);
                if (false !== ip2long($ip)) {
                    break;
                }
            }
        }
        return $convert ? sprintf('%u', ip2long($ip)) : $ip;
    }

}


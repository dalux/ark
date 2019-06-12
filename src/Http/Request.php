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
        if (!self::$_ready) {
            throw new RuntimeException(Language::format('core.request_not_ready'));
        }
        if (is_null($name)) {
            return self::$_get;
        }
        return isset(self::$_get[$name]) ? self::$_get[$name] : $sub;
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
        if (!self::$_ready) {
            throw new RuntimeException(Language::format('core.request_not_ready'));
        }
        if (is_null($name)) {
            return self::$_post;
        }
        return isset(self::$_post[$name]) ? self::$_post[$name] : $sub;
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
        if (!self::$_ready) {
            throw new RuntimeException(Language::format('core.request_not_ready'));
        }
        if (is_null($name)) {
            return self::$_cookie;
        }
        return isset(self::$_cookie[$name]) ? self::$_cookie[$name] : $sub;
    }

    /**
     * Get the request data for the files method
     *
     * @param string name
     * @return var
     */
    public static function files(string $name = null)
    {
        if (!self::$_ready) {
            throw new RuntimeException(Language::format('core.request_not_ready'));
        }
        if (is_null($name)) {
            return self::$_files;
        }
        return self::$_files[$name];
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
        if (!self::$_ready) {
            throw new Exception(Language::format('core.request_not_ready'));
        }
        if (is_null($name)) {
            return self::$_request;
        }
		return isset(self::$_request[$name]) ? self::$_request[$name] : $sub;
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
        if (!self::$_ready) {
            throw new RuntimeException(Language::format('core.request_not_ready'));
        }
        $type = strtolower($type);
        $types = [self::TYPE_GET, self::TYPE_POST, self::TYPE_COOKIE];
        if (!in_array(type, types)) {
            throw new RuntimeException(Language::format('core.request_type_nosupport', $type));
        }
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
        self::$_request = array_merge(self::$_get, self::$_post, self::$_cookie);
        $_REQUEST = self::$_request;
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
        if (!self::$_ready) {
            throw new RuntimeException(Language::format('core.request_not_ready'));
        }
        $type = strtolower($type);
        $types = [self::TYPE_GET, self::TYPE_POST, self::TYPE_COOKIE];
        if (!in_array($type, $types)) {
            throw new RuntimeException(Language::format('core.request_type_nosupport', $type));
        }
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
        self::$_request = array_merge(self::$_get, self::$_post, self::$_cookie);
        $_REQUEST = self::$_request;
    }

}


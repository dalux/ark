<?php declare(strict_types=1);

namespace Brisk\Http;

use Brisk\Exception\RuntimeException;
use Brisk\Kernel\Event;
use Brisk\Kernel\Language;

class Request
{

    const TYPE_GET              = 1;
    const TYPE_POST             = 2;
    const TYPE_COOKIE           = 3;
    const TYPE_FILES            = 4;

    private static $_data       = [];
    private static $_ready      = false;
    
    /**
     * 构造函数
     *
     * @access public
     * @param array $getdata
     * @return void
     */
    public static function init(array $getdata = [])
    {
        if (!self::$_ready) {
            $data = [
                self::TYPE_GET => $getdata,
                self::TYPE_POST => $_POST,
                self::TYPE_COOKIE => $_COOKIE,
                self::TYPE_FILES => $_FILES
            ];
            $data = Event::fire('event.request.ready', $data);
            $get = $data[self::TYPE_GET];
            $post = $data[self::TYPE_POST];
            $cookie = $data[self::TYPE_COOKIE];
            $files = $data[self::TYPE_FILES];
            $request = array_merge($get, $post, $cookie);
            $_GET = [];
            $_POST = [];
            $_COOKIE = [];
            $_REQUEST = [];
            $_FILES = [];
            self::$_data['get'] = $get;
            self::$_data['post'] = $post;
            self::$_data['cookie'] = $cookie;
            self::$_data['files'] = $files;
            self::$_data['request'] = $request;
            self::$_ready = true;
        }
    }

    /**
     * 检查当前请求是否post
     *
     * @access public
     * @return bool
     */
	public static function isPost()
	{
        return 'POST' == strtoupper($_SERVER['REQUEST_METHOD']);
	}

    /**
     * 检查当前请求是否ajax
     *
     * @access public
     * @return bool
     */
    public static function isAjax()
    {
        return 'XMLHttpRequest' == $_SERVER['HTTP_X_REQUESTED_WITH'];
    }

    /**
     * 检查请求是否就绪
     *
     * @access public
     * @return void
     */
    public static function checkReady()
    {
        if (!self::$_ready) {
            throw new RuntimeException(Language::get('http.request_not_ready'));
        }
    }

    /**
     * 获取get数据
     *
     * @access public
     * @param string $name
     * @param string $sub
     * @return mixed
     */
    public static function get(string $name = null, $sub = null)
    {
        self::checkReady();
        $get = self::$_data['get'];
        return is_null($name) ? $get : ($get[$name] ?? $sub);
    }

    /**
     * 获取post数据
     *
     * @access public
     * @param string $name
     * @param string $sub
     * @return mixed
     */
    public static function post(string $name = null, $sub = null)
    {
        self::checkReady();
        $post = self::$_data['post'];
        return is_null($name) ? $post : ($post[$name] ?? $sub);
    }

    /**
     * 获取cookie数据
     *
     * @access public
     * @param string $name
     * @param string $sub
     * @return mixed
     */
    public static function cookie(string $name = null, $sub = null)
    {
        self::checkReady();
        $cookie = self::$_data['cookie'];
        return is_null($name) ? $cookie : ($cookie[$name] ?? $sub);
    }

    /**
     * 获取上传文件数据
     *
     * @access public
     * @param string $name
     * @return mixed
     */
    public static function files(string $name = null)
    {
        self::checkReady();
        $files = self::$_data['files'];
        return is_null($name) ? $files : $files[$name];
    }

    /**
     * 获取request数据
     *
     * @access public
     * @param string $name
     * @param string $sub
     * @return mixed
     */
    public static function data(string $name = null, $sub = null)
    {
        self::checkReady();
        $request = self::$_data['request'];
        return is_null($name) ? $request : ($request[$name] ?? $sub);
    }

    /**
     * 添加request请求数据项
     *
     * @access public
     * @param string $type
     * @param string $name
     * @param mixed $data
     * @return bool
     */
    public static function add(string $type, string $name, $data)
    {
        self::checkReady();
        $map = [
            self::TYPE_GET      => 'get',
            self::TYPE_POST     => 'post',
            self::TYPE_COOKIE   => 'cookie',
            self::TYPE_FILES    => 'files',
        ];
        if (!isset($map[$type])) {
            return false;
        }
        $flag = $map[$type];
        self::$_data[$flag][$name] = $data;
        self::$_data['request'] = array_merge(
            self::$_data['get'],
            self::$_data['post'],
            self::$_data['cookie']
        );
        return true;
    }

    /**
     * 删除request请求数据项
     *
     * @access public
     * @param string $type
     * @param string $name
     * @param mixed $data
     * @return bool
     */
    public static function delete(string $type, string $name)
    {
        self::checkReady();
        $map = [
            self::TYPE_GET      => 'get',
            self::TYPE_POST     => 'post',
            self::TYPE_COOKIE   => 'cookie',
            self::TYPE_FILES    => 'files',
        ];
        if (!isset($map[$type])) {
            return false;
        }
        $flag = $map[$type];
        unset(self::$_data[$flag][$name]);
        self::$_data['request'] = array_merge(
            self::$_data['get'],
            self::$_data['post'],
            self::$_data['cookie']
        );
        return true;
    }

    /**
     * 获取当前客户端的IP地址
     *
     * @access public
     * @param bool $convert
     * @return string|float
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


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
            ];
            $data = Event::fire('event.request.ready', $data);
            $_GET = $data[self::TYPE_GET];
            $_POST = $data[self::TYPE_POST];
            $_COOKIE = $data[self::TYPE_COOKIE];
            $_REQUEST = array_merge($_GET, $_POST);
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
        return is_null($name) ? $_GET : ($_GET[$name] ?? $sub);
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
        return is_null($name) ? $_POST : ($_POST[$name] ?? $sub);
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
        return is_null($name) ? $_COOKIE : ($_COOKIE[$name] ?? $sub);
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
        return is_null($name) ? $_FILES : $_FILES[$name];
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
        return is_null($name) ? $_REQUEST : ($_REQUEST[$name] ?? $sub);
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
        if ($type == self::TYPE_GET) {
            $_GET[$name] = $data;
        } elseif ($type == self::TYPE_POST) {
            $_POST[$name] = $data;
        } elseif ($type == self::TYPE_COOKIE) {
            $_COOKIE[$name] = $data;
        }
        $_REQUEST = array_merge($_GET, $_POST);
        return true;
    }

    /**
     * 删除request请求数据项
     *
     * @access public
     * @param string $type
     * @param string $name
     * @return bool
     */
    public static function delete(string $type, string $name)
    {
        self::checkReady();
        if ($type == self::TYPE_GET) {
            unset($_GET[$name]);
        } elseif ($type == self::TYPE_POST) {
            unset($_POST[$name]);
        } elseif ($type == self::TYPE_COOKIE) {
            unset($_COOKIE[$name]);
        }
        $_REQUEST = array_merge($_GET, $_POST);
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


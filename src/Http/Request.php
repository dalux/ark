<?php declare(strict_types=1);

namespace Brisk\Http;

use Brisk\Event;

class Request
{

    private static $_data       = [];
    private $_instid;

    const TYPE_GET              = 1;
    const TYPE_POST             = 2;
    const TYPE_COOKIE           = 3;
    const TYPE_FILES            = 4;

    /**
     * 构造函数
     * 
     * @param array $getdata
     * @return void
     */
    public function __construct(array $getdata = [])
    {
        $id = uniqid();
        $data = [
            self::TYPE_GET      => $getdata, 
            self::TYPE_POST     => $_POST, 
            self::TYPE_COOKIE   => $_COOKIE, 
            self::TYPE_FILES    => $_FILES
        ];
        $data = Event::fire('event.request.ready', $data);
        $get        = $data[self::TYPE_GET];
        $post       = $data[self::TYPE_POST];
        $cookie     = $data[self::TYPE_COOKIE];
        $files      = $data[self::TYPE_FILES];
        $request    = array_merge($get, $post, $cookie);
        $_GET       = [];
        $_POST      = [];
        $_COOKIE    = [];
        $_REQUEST   = [];
        $_FILES     = [];
        self::$_data[$id]['get']        = $get;
        self::$_data[$id]['post']       = $post;
        self::$_data[$id]['cookie']     = $cookie;
        self::$_data[$id]['files']      = $files;
        self::$_data[$id]['request']    = $request;
        $this->_instid = $id;
    }

    /**
     * Check if request is post
     *
     * @return bool
     */
	public function isPost()
	{
        return 'POST' == strtoupper($_SERVER['REQUEST_METHOD']);
	}

    /**
     * Check if request is ajax
     *
     * @return bool
     */
    public function isAjax()
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
    public function get(string $name = null, $sub = null)
    {
        $get = self::$_data[$this->_instid]['get'];
        return is_null($name) ? $get : ($get[$name] ?? $sub);
    }

    /**
     * Get the request data for the POST method
     *
     * @param string name
     * @param string sub
     * @return var
     */
    public function post(string $name = null, $sub = null)
    {
        $post = self::$_data[$this->_instid]['post'];
        return is_null($name) ? $post : ($post[$name] ?? $sub);
    }

    /**
     * Get the request data for the POST method
     *
     * @param string name
     * @param string sub
     * @return mixed
     */
    public function cookie(string $name = null, $sub = null)
    {
        $cookie = self::$_data[$this->_instid]['cookie'];
        return is_null($name) ? $cookie : ($cookie[$name] ?? $sub);
    }

    /**
     * Get the request data for the files method
     *
     * @param string name
     * @return mixed
     */
    public function files(string $name = null)
    {
        $files = self::$_data[$this->_instid]['files'];
        return is_null($name) ? $files : $files[$name];
    }

    /**
     * Get the request data
     *
     * @param string name
     * @param string sub
     * @return mixed
     */
    public function data(string $name = null, $sub = null)
    {
        $request = self::$_data[$this->_instid]['request'];
        return is_null($name) ? $request : ($request[$name] ?? $sub);
    }

    /**
     * 添加request请求数据项
     *
     * @param string type
     * @param string name
     * @param mixed data
     * @return bool
     */
    public function add(string $type, string $name, $data)
    {
        $id = $this->_instid;
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
        self::$_data[$id][$flag][$name] = $data;
        self::$_data[$id]['request'] = array_merge(
            self::$_data[$id]['get'], 
            self::$_data[$id]['post'],
            self::$_data[$id]['cookie']
        );
        return true;
    }

    /**
     * 删除request请求数据项
     *
     * @param string type
     * @param string name
     * @param var data
     * @return void
     */
    public function delete(string $type, string $name)
    {
        $id = $this->_instid;
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
        unset(self::$_data[$id][$flag][$name]);
        self::$_request = array_merge(
            self::$_data[$id]['get'], 
            self::$_data[$id]['post'],
            self::$_data[$id]['cookie']
        );
        return true;
    }

    /**
     * Get client IP Address
     *
     * @param bool $convert
     * @return string
     */
    public function getIpAddress($convert = false)
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

    /**
     * clean
     * 
     * @return void
     */
    public function clean()
    {
        unset(self::$_data[$this->_instid]);
    }

}


<?php

namespace Ark\Core;

class Response
{    

    /**
     * 状态
     *
     * @access private
     * @var array
     */
    private $_status_texts = array(
      100 => 'Continue',
      101 => 'Switching Protocols',
      200 => 'OK',
      201 => 'Created',
      202 => 'Accepted',
      203 => 'Non-Authoritative Information',
      204 => 'No Content',
      205 => 'Reset Content',
      206 => 'Partial Content',
      300 => 'Multiple Choices',
      301 => 'Moved Permanently',
      302 => 'Found',
      303 => 'See Other',
      304 => 'Not Modified',
      305 => 'Use Proxy',
      306 => 'Unused',
      307 => 'Temporary Redirect',
      400 => 'Bad Request',
      401 => 'Unauthorized',
      402 => 'Payment Required',
      403 => 'Forbidden',
      404 => 'Not Found',
      405 => 'Method Not Allowed',
      406 => 'Not Acceptable',
      407 => 'Proxy Authentication Required',
      408 => 'Request Timeout',
      409 => 'Conflict',
      410 => 'Gone',
      411 => 'Length Required',
      412 => 'Precondition Failed',
      413 => 'Request Entity Too Large',
      414 => 'Request-URI Too Long',
      415 => 'Unsupported Media Type',
      416 => 'Requested Range Not Satisfiable',
      417 => 'Expectation Failed',
      500 => 'Internal Server Error',
      501 => 'Not Implemented',
      502 => 'Bad Gateway',
      503 => 'Service Unavailable',
      504 => 'Gateway Timeout',
      505 => 'HTTP Version Not Supported',
    );

    /**
     * 取得/设置状态
     *
     * @access public
     * @param int    $code 编号, 为空时返回当前状态编号
     * @param string $text 内容
     * @return mixed
     */
    function status($code, $text = null)
    {
        $status_code = isset($this->_status_texts[$code]) ? $code : 200;
        $status_text = is_null($text) ? $this->_status_texts[$status_code] : $text;
        $protocol = $_SERVER['SERVER_PROTOCOL'];
        $protocol || $protocol = 'HTTP/1.1';
		header("$protocol $status_code $status_text");
        return $this;
    }

    /**
     * 设置响应COOKIE
     *
     * @access public
     * @param string $var
     * @param string $val
     * @param int $expire
     * @param string $path
     * @param string $domain
     * @param bool $secure
     * @param bool $httponly
     * @return mixed
     */
    function cookie($var, $val, $expire = 0, $path = '/', $domain = '', $secure = false, $httponly = true)
    {
        setcookie($var, $val, time() + $expire, $path, $domain, (bool)$secure, (bool)$httponly);
        return $this;
    }

    /**
     * 页面跳转
     *
     * @access public
     * @param string $url
     * @param bool $script
     * @param string $msg
     * @return null
     */
    function redirect($url, $script = false, $msg = null)
    {
        if (!$script) {
            $this->header('Location', $url);
            exit;
        }
        $str = '<script type="text/javascript">';
        is_null($msg) || $str.= 'alert("'. $msg. '");';
        $str.= 'location.href="'. $url. '";</script>';
        echo $str;
        exit;
    }

    /**
     * 显示一个js警告框
     *
     * @access public
     * @param string $msg
     * @return null
     */
    function alert($msg)
    {
        $str = '<script type="text/javascript">alert("' . $msg . '");</script>';
        echo $str;
    }

    /**
     * 设置客户端不缓存
     *
     * @access public
     * @return null
     */
    function noCache()
    {
        $this->header('Expires', 'Mon, 26 Jul 1999 01:00:00 GMT');
        $this->header('Last-Modified', gmdate("D, d M Y H:i:s"). ' GMT');
        $this->header('Cache-Control', 'no-store, no-cache, must-revalidate');
        $this->header('Cache-Control', 'post-check=0, pre-check=0', false);
        $this->header('Pragma', 'no-cache');
        return $this;
    }


    /**
     * 设置客户端过期时间
     *
     * @access public
     * @param int $sec
     * @return null
     */
    function expires($sec = 3600)
    {
        return $this->header('Expires', date('D, d M Y H:i:s', time() + $sec). ' GMT');
    }

    /**
     * 设置头部变量
     *
     * @access public
     * @param string $var
     * @param mixed $val
     * @param bool $replace
     * @return mixed
     */
    function header($var = null, $val = null, $replace = true)
    {
        header("$var: $val", $replace);
        return $this;
    }

}
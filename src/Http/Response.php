<?php declare(strict_types=1);

namespace Brisk\Http;

class Response
{

    /**
     * 状态
     *
     * @var string
     */
    const FLAG_END      = 'end';
    const FLAG_STOP     = 'stop';

    /**
     * 响应是否结束
     *
     * @var bool
     */
    private static $_flag;

    /**
     * 状态码映射表
     *
     * @var array
     */
    private static $_status     = [
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
        505 => 'HTTP Version Not Supported'
    ];

    /**
     * 发送状态码
     *
     * @access public
     * @param int $code
     * @return void
     */
    public static function code(int $code)
    {
        $status_code = self::$_status[$code] ?? 200;
        $status_text = self::$_status[$status_code];
        $protocol = $_SERVER['SERVER_PROTOCOL'] ?? 'HTTP/1.1';
        self::setHeader($protocol. ' '. $status_code. ' '. $status_text);
    }

    /**
     * 设置头信息
     *
     * @access public
     * @param string $header
     * @param bool $replace
     * @return void
     */
    public static function setHeader(string $header, bool $replace = true)
    {
        header($header, $replace);
    }

    /**
     * 设置cookie信息
     *
     * @access public
     * @param string $name
     * @param string $value
     * @param int $expire
     * @param string $path
     * @param string $domain
     * @param bool $httponly
     * @param bool $secure
     * @return void
     */
    public static function setCookie(string $name, $value, int $expire = 86400, string $path = '/', string $domain = '', bool $httponly = true, bool $secure = false)
    {
        setcookie($name, $value, time() + $expire, $path, $domain, $secure, $httponly);
    }

    /**
     * 设置客户端不缓存数据
     *
     * @access public
     * @return void
     */
    public static function noCache()
    {
        self::setHeader('Expires: Mon, 26 Jul 1999 01:00:00 GMT');
        self::setHeader('Last-Modified: '. gmdate('D, d M Y H:i:s'). ' GMT');
        self::setHeader('Cache-Control: no-store, no-cache, must-revalidate');
        self::setHeader('Cache-Control: post-check=0, pre-check=0', false);
        self::setHeader('Pragma: no-cache');
    }

    /**
     * 是否结束响应流程
     *
     * @access public
     * @return null
     */
    public static function end()
    {
        self::$_flag = self::FLAG_END;
        return null;
    }

    /**
     * 是否结束响应流程
     *
     * @access public
     * @return null
     */
    public static function stop()
    {
        self::$_flag = self::FLAG_STOP;
        return null;
    }

    /**
     * 获取当前状态标识
     *
     * @return bool
     */
    public static function getFlag()
    {
        return self::$_flag;
    }

    /**
     * 设置客户端数据缓存过期时间
     *
     * @access public
     * @param int $sec
     * @return void
     */
    public static function setExpires(int $sec = 3600)
    {
        self::setHeader('Expires: '. date('D, d M Y H:i:s', time() + $sec). ' GMT');
    }

    /**
     * 跳转
     *
     * @access public
     * @param string $url
     * @param bool $script
     * @param string $msg
     * @return null
     */
    public static function redirect(string $url, bool $script = false, string $msg = null)
    {
        if (!$script) {
            self::setHeader('Location: '. $url);
            exit();
        }
        $content = '<script>';
        is_null($msg) || $content.= 'alert("'. $msg. '");';
        $content.= 'location.href="'. $url. '";';
        $content.= '</script>';
        echo $content;
        return self::end();
    }

}
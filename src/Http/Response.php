<?php declare(strict_types=1);

namespace Brisk\Http;

class Response
{

    private static $_header     = [];
    private static $_cookie     = [];
    private static $_end        = false;
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
    private static $_content;

    /**
    * set header parameter
    *
    * @param int code
    * @param string text
    * @return void
    */
    public static function status(int $code, string $text = null)
    {
        $status_code = self::$_status[$code] ?? 200;
        $status_text = is_null($text) ? self::$_status[$status_code] : $text;
        $protocol = $_SERVER['SERVER_PROTOCOL'];
        is_null($protocol) && $protocol = 'HTTP/1.1';
        self::setHeader($protocol. ' '. $status_code. ' '. $status_text);
    }

    /**
    * set header parameter
    *
    * @param string var
    * @param mixed val
    * @param bool replace
    * @return void
    */
    public static function setHeader(string $header, bool $replace = true)
    {
        self::$_header[] = ['header'=> $header, 'replace'=> $replace];
    }

    /**
     * set cookie
     *
     * @param string name
     * @param string value
     * @param int expire
     * @param string path
     * @param string domain
     * @param bool httponly
     * @param bool secure
     * @return void
     */
    public static function setCookie(string $name, $value, int $expire = 86400, string $path = '/', string $domain = '', bool $httponly = true, bool $secure = false)
    {
        self::$_cookie[] = [
            'name'      => $name,
            'value'     => $value,
            'expire'    => $expire,
            'path'      => $path,
            'domain'    => $domain,
            'httponly'  => $httponly,
            'secure'    => $secure
        ];
    }

    /**
     * sets no cache
     *
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
     * set expire time
     *
     * @param int sec
     * @return void
     */
    public static function setExpires(int $sec = 3600)
    {
        self::setHeader('Expires: '. date('D, d M Y H:i:s', time() + $sec). ' GMT');
    }
    
    /**
     * 设置响应结束标记
     * 
     * @return void
     */
    public static function end()
    {
        self::$_end = true;
    }

    /**
     * 响应是否已结束
     * 
     * @return bool
     */
    public static function isTerminated()
    {
        return self::$_end;
    }

    /**
     * set output content
     * 
     * @param string content
     * @return mixed
     */
    public static function setContent(string $content)
    {
        self::$_content = $content;
    }

    /**
     * get output content
     * 
     * @return string
     */
    public static function getContent()
    {
        return self::$_content;
    }

    /**
     * send header and content
     * 
     * @return void
     */
    public static function send()
    {
        self::sendHeader();
        self::sendContent();
    }

    /**
     * send header and cookie to client
     * 
     * @return void
     */
    public static function sendHeader()
    {
        foreach (self::$_header as $v) {
            header($v['header'], $v['replace']);
        }
        foreach (self::$_cookie as $v) {
            setcookie($v['name'], $v['value'], time() + $v['expire'], $v['path'], $v['domain'], $v['secure'], $v['httponly']);
        }
    }

    /**
     * send content to client
     * 
     * @return void
     */
    public static function sendContent()
    {
        if (self::$_content) {
            echo self::$_content;
        }
    }

}
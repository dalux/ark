<?php declare(strict_types=1);

namespace Brisk\Http;

class Response
{

    private static $_data       = [];
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
    private $_instid;

    /**
     * 私有构造器
     * 
     */
    public function __construct()
    {
        $id = uniqid();
        self::$_data[$id] = [
            'content'   => '', 
            'end'       => false
        ];
        $this->_instid = $id;
    }

    /**
    * set header parameter
    *
    * @param int code
    * @param string text
    * @return void
    */
    public function status(int $code, string $text = null)
    {
        $status_code = self::$_status[$code] ?? 200;
        $status_text = is_null($text) ? self::$_status[$status_code] : $text;
        $protocol = $_SERVER['SERVER_PROTOCOL'];
        is_null($protocol) && $protocol = 'HTTP/1.1';
        $this->setHeader($protocol. ' '. $status_code. ' '. $status_text);
    }

    /**
    * set header parameter
    *
    * @param string var
    * @param mixed val
    * @param bool replace
    * @return void
    */
    public function setHeader(string $header, bool $replace = true)
    {
        header($header, $replace);
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
    public function setCookie(string $name, $value, int $expire = 86400, string $path = '/', string $domain = '', bool $httponly = true, bool $secure = false)
    {
        setcookie($name, $value, time() + $expire, $path, $domain, $secure, $httponly);
    }

    /**
     * sets no cache
     *
     * @return void
     */
    public function noCache()
    {
        $this->setHeader('Expires: Mon, 26 Jul 1999 01:00:00 GMT');
        $this->setHeader('Last-Modified: '. gmdate('D, d M Y H:i:s'). ' GMT');
        $this->setHeader('Cache-Control: no-store, no-cache, must-revalidate');
        $this->setHeader('Cache-Control: post-check=0, pre-check=0', false);
        $this->setHeader('Pragma: no-cache');
    }

    /**
     * set expire time
     *
     * @param int sec
     * @return void
     */
    public function setExpires(int $sec = 3600)
    {
        $this->setHeader('Expires: '. date('D, d M Y H:i:s', time() + $sec). ' GMT');
    }
    
    /**
     * 设置响应结束标记
     * 
     * @return void
     */
    public function end()
    {
        self::$_data[$this->_instid]['end'] = true;
    }

    /**
     * 响应是否已结束
     * 
     * @return bool
     */
    public function isTerminated()
    {
        return self::$_data[$this->_instid]['end'];
    }

    /**
     * set output content
     * 
     * @param string content
     * @return mixed
     */
    public function setContent(string $content)
    {
        self::$_data[$this->_instid]['content'] = $content;
    }

    /**
     * get output content
     * 
     * @return string
     */
    public function getContent()
    {
        return self::$_data[$this->_instid]['content'];
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
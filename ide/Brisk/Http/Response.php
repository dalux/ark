<?php

namespace Brisk\Http;


class Response
{

    static private $_status_texts = array(100 => 'Continue', 101 => 'Switching Protocols', 200 => 'OK', 201 => 'Created', 202 => 'Accepted', 203 => 'Non-Authoritative Information', 204 => 'No Content', 205 => 'Reset Content', 206 => 'Partial Content', 300 => 'Multiple Choices', 301 => 'Moved Permanently', 302 => 'Found', 303 => 'See Other', 304 => 'Not Modified', 305 => 'Use Proxy', 306 => 'Unused', 307 => 'Temporary Redirect', 400 => 'Bad Request', 401 => 'Unauthorized', 402 => 'Payment Required', 403 => 'Forbidden', 404 => 'Not Found', 405 => 'Method Not Allowed', 406 => 'Not Acceptable', 407 => 'Proxy Authentication Required', 408 => 'Request Timeout', 409 => 'Conflict', 410 => 'Gone', 411 => 'Length Required', 412 => 'Precondition Failed', 413 => 'Request Entity Too Large', 414 => 'Request-URI Too Long', 415 => 'Unsupported Media Type', 416 => 'Requested Range Not Satisfiable', 417 => 'Expectation Failed', 500 => 'Internal Server Error', 501 => 'Not Implemented', 502 => 'Bad Gateway', 503 => 'Service Unavailable', 504 => 'Gateway Timeout', 505 => 'HTTP Version Not Supported');


    /**
     * sets gets status text
     *
     * @param int $code
     * @param string $text
     * @return null
     */
    public static function status($code, $text = '') {}

    /**
     * set cookie
     *
     * @param string $name
     * @param string $value
     * @param int $expire
     * @param string $path
     * @param string $domain
     * @param boolean $secure
     * @param boolean $httponly
     * @return null
     */
    public static function cookie($name, $value, $expire = 0, $path = '/', $domain = '', $secure = false, $httponly = true) {}

    /**
     * redirect page
     *
     * @param string $url
     * @param bool $script
     * @param string $msg
     * @return null
     */
    public static function redirect($url, $script = false, $msg = '') {}

    /**
     * alert message
     *
     * @param string $msg
     * @return null
     */
    public static function alert($msg) {}

    /**
     * sets no cache
     *
     * @return null
     */
    public static function noCache() {}

    /**
     * set expire time
     *
     * @param int $sec
     * @return null
     */
    public static function expires($sec = 3600) {}

    /**
     * set header parameter
     *
     * @param string $name
     * @param string $value
     * @param bool $is_replace
     * @param string $var
     * @param mixed $val
     * @param bool $replace
     * @return mixed
     */
    public static function header($name, $value, $is_replace = true) {}

}

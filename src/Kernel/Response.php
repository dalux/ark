<?php

namespace Brisk\Kernel;

class Response
{

    /**
     * @var array
     */
    private static $_status_texts = [
        100=> 'Continue',
        101=> 'Switching Protocols',
        200=> 'OK',
        201=> 'Created',
        202=> 'Accepted',
        203=> 'Non-Authoritative Information',
        204=> 'No Content',
        205=> 'Reset Content',
        206=> 'Partial Content',
        300=> 'Multiple Choices',
        301=> 'Moved Permanently',
        302=> 'Found',
        303=> 'See Other',
        304=> 'Not Modified',
        305=> 'Use Proxy',
        306=> 'Unused',
        307=> 'Temporary Redirect',
        400=> 'Bad Request',
        401=> 'Unauthorized',
        402=> 'Payment Required',
        403=> 'Forbidden',
        404=> 'Not Found',
        405=> 'Method Not Allowed',
        406=> 'Not Acceptable',
        407=> 'Proxy Authentication Required',
        408=> 'Request Timeout',
        409=> 'Conflict',
        410=> 'Gone',
        411=> 'Length Required',
        412=> 'Precondition Failed',
        413=> 'Request Entity Too Large',
        414=> 'Request-URI Too Long',
        415=> 'Unsupported Media Type',
        416=> 'Requested Range Not Satisfiable',
        417=> 'Expectation Failed',
        500=> 'Internal Server Error',
        501=> 'Not Implemented',
        502=> 'Bad Gateway',
        503=> 'Service Unavailable',
        504=> 'Gateway Timeout',
        505=> 'HTTP Version Not Supported'
    ];

    /**
    * sets gets status text
    *
    * @param int    code 
    * @param string text
    * @return null
    */
    public static function status($code, $text = '')
    {
        $status_code = 200;
        if (isset(self::$_status_texts[$code])) {
            $status_code = $code;
        }
        $status_text = $text;
        if ($text == '') {
            $status_text = self::$_status_texts[$status_code];
        }
        $protocol = $_SERVER['SERVER_PROTOCOL'];
        if (is_null($protocol)) {
            $protocol = 'HTTP/1.1';
        }
        header($protocol. ' '. $status_code. ' '. $status_text);
    }

    /**
     * set cookie
     *
     * @param string $name
     * @param string $value
     * @param int expire
     * @param string $path
     * @param string $domain
     * @param bool $secure
     * @param bool $httponly
     * @return void
     */
    public static function cookie($name, $value, $expire = 0, $path = '/', $domain = '', $secure = false, $httponly = true)
    {
        setcookie($name, $value, time() + $expire, $path, $domain, $secure, $httponly);
    }

    /**
     * redirect page
     *
     * @param string $url
     * @param bool $script
     * @param string $msg
     * @return void
     */
    public static function redirect($url, $script = false, $msg = '')
    {
        if (!$script) {
            self::header('Location', $url);
            exit;
        }
        $str = '<script>';
        if ($msg != '') {
            $str = $str. 'alert("'. $msg. '");';
        }
        $str = $str. 'location.href="'. $url. '";</script>';
        echo $str;
        exit;
    }

    /**
     * alert message
     *
     * @param string $msg
     * @return void
     */
    public static function alert($msg)
    {
        echo '<script>alert("' . $msg . '");</script>';
    }

    /**
     * sets no cache
     *
     * @return void
     */
    public static function noCache()
    {
        self::header('Expires', 'Mon, 26 Jul 1999 01:00:00 GMT');
        self::header('Last-Modified', gmdate('D, d M Y H:i:s'). ' GMT');
        self::header('Cache-Control', 'no-store, no-cache, must-revalidate');
        self::header('Cache-Control', 'post-check=0, pre-check=0', false);
        self::header('Pragma', 'no-cache');
    }

    /**
     * set expire time
     *
     * @param int $sec
     * @return void
     */
    public static function expires($sec = 3600)
    {
        self::header('Expires', date('D, d M Y H:i:s', time() + $sec). ' GMT');
    }

    /**
    * set header parameter
    *
    * @param string var
    * @param mixed val
    * @param bool replace
    * @return void
    */
    public static function header($name, $value, $is_replace = true)
    {
        header($name. ': '. $value, $is_replace);
    }

}
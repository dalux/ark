<?php declare(strict_types=1);

namespace Brisk\Http;

class Response
{

    const FLAG_NEXT     = 1;
    const FLAG_STOP     = 2;

    private $_content   = '';
    private $_flag;
    private $_header    = [];
    private $_cookie    = [];
    private $_status    = [
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
    * set header parameter
    *
    * @param int code
    * @param string text
    * @return Response
    */
    public function status(int $code, string $text = null)
    {
        $status_code = 200;
        if (isset($this->_status[$code])) {
            $status_code = $code;
        }
        $status_text = $text;
        if (is_null($text)) {
            $status_text = $this->_status[$status_code];
        }
        $protocol = $_SERVER['SERVER_PROTOCOL'];
        if (is_null($protocol)) {
            $protocol = 'HTTP/1.1';
        }
        return $this->addHeader($protocol. ' '. $status_code. ' '. $status_text);
    }

    /**
    * set header parameter
    *
    * @param string var
    * @param mixed val
    * @param bool replace
    * @return Response
    */
    public function addHeader(string $header, bool $replace = true)
    {
        $this->_header[] = ['header'=> $header, 'replace'=> $replace];
        return $this;
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
     * @return Response
     */
    public function addCookie(string $name, $value, int $expire = 86400, string $path = '/', string $domain = '', bool $httponly = true, bool $secure = false)
    {
        $this->_cookie[] = [
            'name'      => $name,
            'value'     => $value,
            'expire'    => $expire,
            'path'      => $path,
            'domain'    => $domain,
            'httponly'  => $httponly,
            'secure'    => $secure
        ];
        return $this;
    }

    /**
     * sets no cache
     *
     * @return void
     */
    public function setNoCache()
    {
        $this->addHeader('Expires: Mon, 26 Jul 1999 01:00:00 GMT');
        $this->addHeader('Last-Modified: '. gmdate('D, d M Y H:i:s'). ' GMT');
        $this->addHeader('Cache-Control: no-store, no-cache, must-revalidate');
        $this->addHeader('Cache-Control: post-check=0, pre-check=0', false);
        $this->addHeader('Pragma: no-cache');
        return $this;
    }    

    /**
     * set expire time
     *
     * @param int sec
     * @return void
     */
    public function setExpires(int $sec = 3600)
    {
        $this->addHeader('Expires: '. date('D, d M Y H:i:s', time() + $sec). ' GMT');
        return $this;
    }
    
    /**
     * send end flag to top controller
     * 
     * @param string content
     * @return Response
     */
    public function next(string $content = null)
    {
        if (!is_null($content)) {
            $this->_content = $content;
        }
        $this->_flag = self::FLAG_NEXT;
        return $this;
    }

    /**
     * send break flag to top controller
     * 
     * @param string content
     * @return Response
     */
    public function stop(string $content = null)
    {
        if (!is_null($content)) {
            $this->_content = $content;
        }
        $this->_flag = self::FLAG_STOP;
        return $this;
    }

    /**
     * set output content
     * 
     * @param string content
     * @return Response
     */
    public function setContent(string $content)
    {
        $this->_content = $content;
        return $this;
    }

    /**
     * get flag
     * 
     * @return int
     */
    public function getFlag()
    {
        return $this->_flag;
    }

    /**
     * get flag
     * 
     * @return string
     */
    public function getContent()
    {
        return $this->_content;
    }

    /**
     * send header and content
     * 
     * @return void
     */
    public function send()
    {
        $this->sendHeader();
        $this->sendContent();
    }

    /**
     * send header and cookie to client
     * 
     * @return void
     */
    public function sendHeader()
    {
        if (!is_null($this->_flag)) {
            foreach ($this->_header as $v) {
                header($v['header'], $v['replace']);
            }
            foreach ($this->_cookie as $v) {
                setcookie($v['name'], $v['value'], time() + $v['expire'], $v['path'], $v['domain'], $v['secure'], $v['httponly']);
            }
        }
    }

    /**
     * send content to client
     * 
     * @return void
     */
    public function sendContent()
    {
        if ($this->_content) {
            echo $this->_content;
        }
    }

}
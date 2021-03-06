<?php declare(strict_types=1);

namespace Brisk\Http;

class Domain
{

    /**
     * 获取当前域名
     *
     * @access public
     * @param bool $reduce
     * @return string
    */
    public static function get(bool $reduce = true)
    {
        $domain = strtolower($_SERVER['HTTP_HOST']);
        if ($domain != 'localhost' && !preg_match('/\\d{1,3}\\.\\d{1,3}\\.\\d{1,3}\\.\\d{1,3}/i', $domain)) {
            $pattern = '/^(.*?)\\.([^\\.]+?)\\.((dev|com|cn|net|com|org|org|cc|de|net|co|tv|hk|me|info|name|biz|so|mobi|gov|wang)(\\.[a-zA-Z]+)?)$/i';
            $matches = [];
            $matched = preg_match_all($pattern, $domain, $matches);
            if ($reduce && $matched > 0) {
                return sprintf('%s.%s', $matches[2][0], $matches[3][0]);
            }
        }
        return $domain;
    }

    /**
     * 获取域名前缀
     *
     * @access public
     * @return string
    */
    public static function getPrefix()
    {
        $domain = strtolower($_SERVER['HTTP_HOST']);
        $host = self::get(true);
        $prefix = trim(str_replace($host, '', $domain), '.');
        return $prefix != '' ? $prefix : 'www';
    }

}
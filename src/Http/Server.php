<?php

namespace Ark\Http;

class Server
{

    /**
     * 当前请求的域名
     *
     * @access public
     * @static
     * @param bool $reduce 是否简化
     * @return string
     */
    static function getDomain($reduce = true)
    {
        $domain = strtolower($_SERVER['HTTP_HOST']);
        $pattern = '/^(.*)\.([^\.]+?)\.(dev|dev.*|com|cn|clone|net|com.cn|org|org.cn|cc|de|net.cn|co|tv|hk|me|info|name|biz|so|mobi|gov.cn)?$/';
        if ($reduce && preg_match_all($pattern, $domain, $matches)) {
            return sprintf('%s.%s', $matches[2][0], $matches[3][0]);
        }
        return $domain;
    }

    /**
     * 获取当前请求的子域名
     *
     * @access public
     * @static
     * @return string
     */
    static function getSubDomain()
    {
        $domain = strtolower($_SERVER['HTTP_HOST']);
        $host = self::getDomain(true);
        $prefix = trim(str_replace($host, '', $domain), '.');
        return $prefix ? $prefix : 'www';
    }

    /**
     * 重新整理CLI模式下各请求数据
     *
     * @access public
     */
    static function initCli()
    {
        $argv = $_SERVER['argv'];
        array_shift($argv);
        foreach ($argv as $arg) {
            $arg = ltrim($arg, '--');
            list($k, $v) = explode('=', $arg);
            if (strpos($k, '.') && strtoupper(substr($k, 0, 7)) == 'SERVER.') {
                $_SERVER[strtoupper(substr($k, 7))] = $v;
            } elseif ($k == 'uri') {
                $_SERVER['REQUEST_URI'] = $v;
                unset($_GET['uri']);
            } else {
                $_GET[$k] = $v;
            }
        }
        if ($domain = $_GET['domain']) {
            $_SERVER['HTTP_HOST'] = $domain;
            unset($_GET['domain']);
        }
    }

    /**
     * 当前是否处于CLI模式
     *
     * @return bool
     */
    static function isCli()
    {
        $is_cli = false;
        if (!isset($_SERVER['HTTP_HOST'])
                || !isset($_SERVER['SERVER_PROTOCOL'])
                || false === strpos($_SERVER['SERVER_PROTOCOL'], 'HTTP')) {
            $is_cli = true;
        }
        return $is_cli;
    }

    /**
     * 获取$_SERVER下的项目
     *
     * @param $name
     * @param array $args
     * @return mixed
     */
    function __callStatic($name, $args = array())
    {
        if (preg_match('/^get/', $name)) {
            preg_match_all('/[A-Z][a-z]+/', $name, $matches);
            if ($matches = $matches[0]) {
                $name = strtoupper(implode('_', $matches));
                return $_SERVER[$name];
            }
        }
    }

}

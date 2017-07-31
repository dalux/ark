<?php

namespace Ark\Toolkit;

use Ark\Core\Noah;

class DbTool
{

    /**
     * 为值添加引号
     *
     * @access public
     * @param mixed $value
     * @param string $dbtype
     * @return mixed
     */
    static function quote($value, $dbtype = 'mysql')
    {
        if (is_array($value)) {
            foreach ($value as $key=> $val) { $value[$key] = self::quote($val, $dbtype); }
            return implode(',', $value);
        } elseif (is_int($value) || is_float($value)) {
            return $value;
        }
        switch ($dbtype) {
            case 'oci':
                return "'" . str_replace("'", "''", $value) . "'";
            case 'mysql':
            case 'pgsql':
            case 'sqlite':
            case 'sqlsrv':
            default:
                return "'" . addslashes($value) . "'";
        }
    }

    /**
     * 设置SQL取值的偏移量
     *
     * @access public
     * @param integer $limit 每页显示数据量
     * @param integer $page 当前页数
     * @param integer $count 总数据量
     * @return integer
     */
    static function getOffset($limit, $page, $count = 0)
    {
        if ($count) {
            $maxpage = self::getMaxPages($limit, $count);
            $page > $maxpage && $page = $maxpage;
        }
        return $limit * ($page > 0 ? $page - 1 : 0);
    }

    /**
     * 当前数据库最大分页数
     *
     * @access public
     * @param integer $limit 每页显示数据量
     * @param integer $count 总数据量
     * @return integer
     */
    static function getMaxPages($limit, $count = 0)
    {
        return ceil($count/$limit);
    }

    /**
     * 解析数据库连接字符串
     *
     * @access public
     * @param string $url
     * @return mixed
     * @throws Exception
     */
    static function parseConnectUrl($url)
    {
        if (!$parsed = parse_url($url)) {
            throw new Exception(Noah::init()->lang->get('db.invalid_conn_string', $url));
        }
        $config = array(
            'type'=> $parsed['scheme'],
            'host'=> $parsed['host'],
            'port'=> $parsed['port'],
            'user'=> $parsed['user'],
            'pass'=> $parsed['pass'],
            'name'=> trim($parsed['path'], '/'),
        );
        if ($query = $parsed['query']) {
            $query = explode('&', $query);
            foreach ($query as $key=> $val) {
                $expr = explode('=', $val);
                if ($expr[0] && $expr[1] !== '') {
                    $config[$expr[0]] = $expr[1];
                }
            }
        }
        return $config;
    }

}
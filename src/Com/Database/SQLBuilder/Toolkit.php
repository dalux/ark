<?php

namespace Ark\Com\Database\SQLBuilder;

use Ark\Core\Noah;

class Toolkit
{

    /**
     * 格式化范围参数值
     *
     * @access public
     * @param string  $column
     * @param mixed   $value
     * @param boolean $in  范围内?
     * @return object
     */
    static function quoteIn($column, $value, $in = true)
    {
        if (is_array($value)) {
            $value = array_map('trim', $value);
            count($value) == 1 && $value = current($value);
        }
        $expr = $column. (is_array($value) ? (($in ? '' : ' NOT'). ' IN (?)') : (($in ? '' : '!'). '=?'));
        return str_replace('?', self::quote($value), $expr);
    }

    /**
     * 为值添加引号
     *
     * @access public
     * @param mixed $value
     * @return mixed
     */
    static function quote($value)
    {
        if (is_array($value)) {
            foreach ($value as $key=> $val) { $value[$key] = self::quote($val); }
            return implode(',', $value);
        } elseif (is_int($value) || is_float($value)) {
            return $value;
        } else {
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
     * @throws RuntimeException
     */
    static function parseConnectUrl($url)
    {
        if (!$parsed = parse_url($url)) {
            throw new RuntimeException(sprintf(Noah::getInstance()->language->get('tbox.invalid_db_connstr'), $url));
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
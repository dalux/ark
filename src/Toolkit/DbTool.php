<?php

namespace Ark\Toolkit;

class DbTool
{

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

}
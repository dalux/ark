<?php

namespace Ark\Toolkit\Querier;

use Ark\Toolkit\Querier;

abstract class Father
{

    /**
     * 当前数据库类型
     *
     * @var string
     */
    protected $_db_type;

    /**
     * 语句组成部分初始值
     *
     * @access protected
     * @var array
     */
    protected $_parts = array();

    /**
     * SQL绑定参数
     *
     * @var array
     */
    protected $_db_bind = array();

    /**
     * 查询条件
     *
     * @access public
     * @param string $cond
     * @return Select
     */
    function where($cond)
    {
        $values = func_get_args();
        array_shift($values);
        $this->_parts['where'][] = array('cond'=> $cond, 'val'=> $values);
        return $this;
    }

    /**
     * 查询in条件
     *
     * @access public
     * @param string $field
     * @param mixed $value
     * @return Father
     */
    function whereIn($field, $value)
    {
        $expr = $field. ' IN (?)';
        if ($value instanceof Select) {
            $value = $value->getRealSQL();
        } else {
            $value = Querier::init($this->_db_type)->quote($value);
        }
        $expr = str_replace('?', $value, $expr);
        return $this->where($expr);
    }

    /**
     * 查询notin条件
     *
     * @access public
     * @param string $field
     * @param mixed $value
     * @return Father
     */
    function whereNotIn($field, $value)
    {
        $expr = $field. ' NOT IN (?)';
        if ($value instanceof Select) {
            $value = $value->getRealSQL();
        } else {
            $value = Querier::init($this->_db_type)->quote($value);
        }
        $expr = str_replace('?', $value, $expr);
        return $this->where($expr);
    }

    /**
     * 查询exists条件
     *
     * @access public
     * @param mixed $query
     * @return Father
     */
    function whereExists($query)
    {
        $expr = 'EXISTS (?)';
        if ($query instanceof Select) {
            $query = $query->getRealSQL();
        }
        $expr = str_replace('?', $query, $expr);
        return $this->where($expr);
    }

    /**
     * 查询notexists条件
     *
     * @access public
     * @param mixed $query
     * @return Father
     */
    function whereNotExists($query)
    {
        $expr = 'NOT EXISTS (?)';
        if ($query instanceof Select) {
            $query = $query->getRealSQL();
        }
        $expr = str_replace('?', $query, $expr);
        return $this->where($expr);
    }

    /**
     * 查询like条件
     *
     * @access public
     * @param $field
     * @param $expr
     * @param string $escape
     * @return Father
     */
    function whereLike($field, $expr, $escape = '')
    {
        $expr = "{$field} LIKE '{$expr}'";
        $escape && $expr.= " ESCAPE '{$escape}'";
        return $this->where($expr);
    }

    /**
     * 查询not like条件
     *
     * @access public
     * @param $field
     * @param $expr
     * @param string $escape
     * @return Father
     */
    function whereNotLike($field, $expr, $escape = '')
    {
        $expr = "{$field} NOT LIKE '{$expr}'";
        $escape && $expr.= " ESCAPE '{$escape}'";
        return $this->where($expr);
    }

    /**
     * 获取where片段
     *
     * @access public
     * @return string
     */
    function pickWherePart()
    {
        $where = array();
        if ($where_part = $this->_parts['where']) {
            foreach ($where_part as $key=> $val) {
                $part = '';
                $cond = $val['cond'];
                $value = $val['val'];
                if (is_null($value)) {
                    $part = $cond;
                    if ($cond instanceof self) {
                        $part.= '(' . $cond->pickWherePart() . ')';
                    }
                } else {
                    $part.= $this->_parseExpr($cond, $value);
                }
                if (!is_null($where_part[$key+1])) {
                    $part.= ' AND ';
                }
                $where[] = $part;
            }
        }
        return $where ? implode(' ', $where) : null;
    }


    /**
     * 获取SQL
     *
     * @return string
     */
    abstract function getSQL();

    /**
     * 返回完全的SQL语句
     *
     * @return string
     */
    function getRealSQL()
    {
        $sql = $this->getSQL();
        $bind = $this->getBind();
        foreach ($bind as $key=> $val) {
            $sql = preg_replace('/'. $key. '/', Querier::init($this->_db_type)->quote($val);, $sql, 1);
        }
        return $sql;
    }

    /**
     * 获取绑定参数
     *
     * @return array
     */
    function getBind()
    {
        return $this->_db_bind;
    }

    /**
     * 字符串化
     *
     * @access public
     * @return string
     */
    function __toString()
    {
        return $this->getRealSQL();
    }

    /**
     * 解析表达式中的值
     *
     * @access public
     * @abstract
     * @param string $expr
     * @param mixed $value
     * @return string
     */
    protected function _parseExpr($expr, $value = null)
    {
        $pattern = '/(\?|\:[\w\d]+)/';
        if (preg_match_all($pattern, $expr, $matches)) {
            $matches = $matches[1];
            foreach ($matches as $k=> $v) {
                if ($v == '?') {
                    $val = $value;
                    if (is_array($value)) {
                        $val = $value[$k];
                    }
                    if ($val instanceof self) {
                        $val = $val->getRealSQL();
                    } elseif (preg_match('/^\{\{.*?\}\}$/', $val) || preg_match('/.*?\(.*?\)/', $val)) {
                        $val = str_replace(array('{{', '}}'), '', $val);
                    } else {
                        $val = Querier::init($this->_db_type)->quote($val);
                    }
                    $expr = preg_replace('/\?/', $val, $expr, 1);
                } else {
                    $val = $value;
                    if (is_array($value)) {
                        $val = $value[$k];
                    }
                    if ($val instanceof self) {
                        $val = $val->getRealSQL();
                        $expr = preg_replace("/$v/", $val, $expr, 1);
                    } elseif (preg_match('/^\{\{.*?\}\}$/', $val) || preg_match('/.*?\(.*?\)/', $val)) {
                        $val = str_replace(array('{{', '}}'), '', $val);
                        $expr = preg_replace("/$v/", $val, $expr, 1);
                    } else {
                        $this->_db_bind[$v] = $val;
                    }
                }
            }
        }
        return $expr;
    }

}
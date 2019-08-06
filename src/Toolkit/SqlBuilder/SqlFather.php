<?php declare(strict_types=1);

namespace Brisk\Toolkit\SqlBuilder;

abstract class SqlFather
{

    /**
     * 数据库类型
     * 
     * @var string
     */
    protected $_db_type = '';

    /**
     * sql语句片断
     *
     * @var array
     */
    protected $_parts = [];

    /**
     * 最终生成的sql语句
     * 
     * @var string
     */
    protected $_sql = '';

    /**
     * sql参数绑定
     *
     * @var array
     */
    protected $_db_bind = [];

    /**
     * 当前sql是否绑定
     *
     * @var bool
     */
    protected $_compiled = false;

    /**
     * 引号包裹
     *
     * @access public
     * @param mixed $value
     * @return string
     */
    public function quote($value)
    {
        if (is_array($value)) {
            foreach ($value as $key=> $val) {
                $value[$key] = $this->quote($val);
            }
            return implode(',', $value);
        } elseif (is_int($value) || is_float($value) || preg_match('/.*?\(.*?\)/', $value)) {
            return $value;
        } else {
            return '\'' . addslashes($value) . '\'';
        }
    }

    /**
     * 设置where条件
     *
     * @access public
     * @param string $expr
     * @param array $value
     * @return SqlFather|Select|Update|Delete|Insert
     */
    public function where(string $expr, ...$value)
    {
        $this->_parts['where'][] = ['cond'=> $expr, 'val'=> $value];
        return $this;
    }

    /**
     * 设置where in 条件
     *
     * @access public
     * @param string $field
     * @param mixed $value
     * @return SqlFather|Select|Update|Delete|Insert
     */
    public function whereIn(string $field, $value)
    {
        if ($value instanceof Select) {
            $value = $value->getRealSQL();
            $expr = $field. ' IN (' . $value. ')';
        } elseif (is_array($value) && count($value) == 1) {
            $value = current($value);
            $expr = $field. '='. $this->quote($value);
        } elseif (is_array($value)) {
            $value = $this->quote($value);
            $expr = $field. ' IN ('. $value. ')';
        } else {
            $expr = $field. '='. $this->quote($value);
        }
        return $this->where($expr);
    }

    /**
     * 设置where not in 条件
     *
     * @access public
     * @param string $field
     * @param mixed $value
     * @return SqlFather|Select|Update|Delete|Insert
     */
    public function whereNotIn(string $field, $value)
    {
        if ($value instanceof Select) {
            $value = $value->getRealSQL();
            $expr = $field . ' NOT IN (' . $value . ')';
        } elseif (is_array($value) && count($value) == 1) {
            $value = current($value);
            $expr = $field. '!='. $this->quote($value);
        } elseif (is_array($value)) {
            $value = $this->quote($value);
            $expr = $field. ' NOT IN ('. $value. ')';
        } else {
            $expr = $field. '!='. $this->quote($value);
        }
        return $this->where($expr);
    }

    /**
     * 设置where exists子查询条件
     *
     * @access public
     * @param string $query
     * @return SqlFather|Select|Update|Delete|Insert
     */
    public function whereExists($query)
    {
        $expr = 'EXISTS (?)';
        if ($query instanceof Select) {
            $query = $query->getRealSQL();
        }
        $expr = str_replace('?', $query, $expr);
        return $this->where($expr);
    }

    /**
     * 设置where not exists子查询条件
     *
     * @access public
     * @param string $query
     * @return SqlFather|Select|Update|Delete|Insert
     */
    public function whereNotExists($query)
    {
        $expr = 'NOT EXISTS (?)';
        if ($query instanceof Select) {
            $query = $query->getRealSQL();
        }
        $expr = str_replace('?', $query, $expr);
        return $this->where($expr);
    }

    /**
     * 设置like查询条件
     *
     * @access public
     * @param string $field
     * @param string $expr
     * @param string $escape
     * @return SqlFather|Select|Update|Delete|Insert
     */
    public function whereLike(string $field, string $expr, string $escape = null)
    {
        $expr = $field. ' LIKE \''. $expr. '\'';
        if ($escape) {
			$expr = $expr. ' ESCAPE \''. $escape. '\'';
		}
        return $this->where($expr);
    }

    /**
     * 设置notlike查询条件
     *
     * @access public
     * @param string $field
     * @param string $expr
     * @param string $escape
     * @return SqlFather|Select|Update|Delete|Insert
     */
    public function whereNotLike(string $field, string $expr, string $escape = null)
    {
        $expr = $field. ' NOT LIKE \''. $expr. '\'';
        if ($escape) {
			$expr = $expr. ' ESCAPE \''. $escape. '\'';
		}
        return $this->where($expr);
    }

    /**
     * 获取where条件语句片段
     *
     * @access protected
     * @return string
     */
    protected function pickWherePart()
    {
        $where = [];
		$where_part = $this->_parts['where'] ?? null;
        if (!is_null($where_part)) {
            foreach ($where_part as $key=> $val) {
                $cond = $val['cond'];
                $value = $val['val'];
                $part = $cond instanceof SqlFather
                    ? '(' . $cond->pickWherePart() . ')'
                    : $this->_parseExpr($cond, $value);
                if (isset($where_part[$key+1])
                        && !is_null($where_part[$key+1])) {
                    $part = $part. ' AND ';
                }
                $where[] = $part;
            }
        }
        return $where ? implode(' ', $where) : '';
    }

    /**
     * 获取当前sql绑定参数
     *
     * @access public
     * @return array
     */
    public function getBind()
    {
        return $this->_db_bind;
    }

    /**
     * 当前当前生成的sql语句，可能含有bind占位符
     *
     * @access public
     * @return string
     */
    public function getSQL()
    {
        if (!$this->_compiled) {
            $this->compile();
        }
        return $this->_sql;
    }

    /**
     * 获取最终sql语句
     *
     * @access public
     * @return string
     */
    public function getRealSQL()
    {
        $sql = $this->getSQL();
        $bind = $this->getBind();
        foreach ($bind as $key=> $val) {
            $sql = preg_replace('/'. $key. '/', $this->quote($val), $sql, 1);
        }
        return $sql;
    }

    /**
     * 输出最终sql语句
     *
     * @access public
     * @return string
     */
    public function __toString()
    {
        return $this->getRealSQL();
    }

    /**
     * 编译当前sql
     *
     * @access protected
     * @return SqlFather
     */
    protected abstract function compile();

    /**
     * 解析表达
     *
     * @access protected
     * @param string $expr
     * @param null $value
     * @return string
     */
    protected function _parseExpr(string $expr, $value = null)
    {
        //特殊处理
        if (is_null($value)
                || is_array($value) && count($value) == 0) {
            if (preg_match('/\{\{.*?\}\}/', $expr)) {
                return str_replace(['{{', '}}'], '', $expr);
            }
            return $expr;
        }
		$matches = [];
		$is_match = preg_match_all('/(\?|\:[\w\d]+)/i', $expr, $matches);
        if ($is_match > 0) {
            $matches = $matches[1];
            foreach ($matches as $k=> $v) {
                $val = $value;
                if (is_array($value)) {
                    $val = isset($value[$k]) ? $value[$k] : null;
                }
                if ($v == '?') {
                    if ($val instanceof SqlFather) {
                        $val = $val->getRealSQL();
                    } elseif (is_string($val) && (preg_match('/\{\{.*?\}\}/', $val))) {
                        $val = str_replace(['{{', '}}'], '', $val);
                    } else {
                        $val = $this->quote($val);
                    }
                    $expr = preg_replace('/\?/', $val, $expr, 1);
                } elseif (strpos($v, ':') !== false) {
                    $this->_db_bind[$v] = [
                        'type'  => gettype($val),
                        'value' => $val
                    ];
                }
            }
        }
        return $expr;
    }

}
<?php declare(strict_types=1);

namespace Brisk\Sql;

abstract class SqlFather
{

    /**
     * @var string
     */
    protected $_db_type = '';

    /**
     * @var array
     */
    protected $_parts = [];

    /**
     * @var string
     */
    protected $_sql = '';

    /**
     * @var array
     */
    protected $_db_bind = [];

    /**
     * @var bool
     */
    protected $_compiled = false;

    /**
     * Put quotation marks on a field
     *
     * @param mixed value
     * @param string dbtype
     * @return string
     */
    public function quote($value)
    {
        if (is_int($value) || is_float($value)
                || preg_match('/^\\{\\{.*?\\}\\}$/', $value)
                || preg_match('/^[a-zA-Z0-9\-\_]*?\(.*?\)$/', $value)) {
            return $value;
        } elseif (is_array($value)) {
            foreach ($value as $key=> $val) {
				$value[$key] = $this->quote($val);
			}
            return implode(',', $value);
        } else {
            return '\'' . addslashes($value) . '\'';
        }
    }

    /**
     * Setting the sql statement where condition
     *
     * @param string expr
     * @param mixed dbtype
     * @return SqlFather
     */
    public function where(string $expr, $value = null)
    {
		$val = [];
		if (!is_null($value)) {
		    $val = is_array($value) ? $value : [$value];
		}
        $this->_parts['where'][] = ['cond'=> $expr, 'val'=> $val];
        return $this;
    }

    /**
     * Setting the sql statement whereIn condition
     *
     * @param string field
     * @param mixed value
     * @return SqlFather
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
     * Setting the sql statement whereNotIn condition
     *
     * @param string field
     * @param mixed value
     * @return SqlFather
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
     * Setting the sql statement whereExists condition
     *
     * @param string query
     * @return SqlFather
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
     * Setting the sql statement whereNotExists condition
     *
     * @param string query
     * @return SqlFather
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
     * Setting the sql statement whereLike condition
     *
     * @param string field
     * @param string expr
     * @param string escape
     * @return SqlFather
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
     * Setting the sql statement whereNotLike condition
     *
     * @param string field
     * @param string expr
     * @param string escape
     * @return SqlFather
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
     * Get the where fragment in the sql statement
     *
     * @return string
     */
    protected function pickWherePart()
    {
        $where = [];
		$where_part = $this->_parts['where'];
        if (!is_null($where_part)) {
            foreach ($where_part as $key=> $val) {
                $part = '';
                $cond = $val['cond'];
                $value = $val['val'];
                if (is_null($value)) {
                    $part = $cond;
                    if ($cond instanceof SqlFather) {
                        $part = $part. '(' . $cond->pickWherePart() . ')';
                    }
                } else {
                    $part = $part. $this->_parseExpr($cond, $value);
                }
                if (!is_null($where_part[$key+1])) {
                    $part = $part. ' AND ';
                }
                $where[] = $part;
            }
        }
        return $where ? implode(' ', $where) : '';
    }

    /**
     * Get the bind data
     *
     * @return array
     */
    public function getBind()
    {
        return $this->_db_bind;
    }

    /**
     * Get the full sql statement
     *
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
     * Get the full sql statement
     *
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

    public function __toString()
    {
        return $this->getRealSQL();
    }

    /**
     * Compile the sql statment and query bind parameter
     *
     * @return SqlFather
     */
    protected abstract function compile();

    /**
     *
     *
     * @param string $expr
     * @param null $value
     * @return string
     */
    protected function _parseExpr(string $expr, $value = null)
    {
        //特殊处理
        if (is_null($value)
                || is_array($value) && count($value) == 0) {
            if (preg_match('/^\\{\\{.*?\\}\\}/', $expr)
                    || preg_match('/.*?\(.*?\)/', $expr)) {
                return str_replace(['{{', '}}'], '', $expr);
            }
            return $expr;
        }
		$matches = [];
		$is_match = preg_match_all('/(\\?|\\:[\\w\\d]+)/i', $expr, $matches);
        if ($is_match > 0) {
            $matches = $matches[1];
            foreach ($matches as $k=> $v) {
                if ($v == '?') {
                    $val = $value;
                    if (is_array($value)) {
                        $val = $value[$k];
                    }
                    if ($val instanceof SqlFather) {
                        $val = $val->getRealSQL();
                    } elseif (preg_match('/^\\{\\{.*?\\}\\}/', $val) || preg_match('/.*?\(.*?\)/', $val)) {
                        $val = str_replace(['{{', '}}'], '', $val);
                    } else {
                        $val = $this->quote($val);
                    }
                    $expr = preg_replace('/\?/', $val, $expr, 1);
                } else {
                    $val = $value;
                    if (is_array($value)) {
                        $val = $value[$k];
                    }
                    if ($val instanceof SqlFather) {
                        $val = $val->getRealSQL();
                        $expr = preg_replace('/v/', $val, $expr, 1);
                    } elseif (preg_match('/^\\{\\{.*?\\}\\}/', $val) || preg_match('/.*?\\(.*?\\)/', $val)) {
                        $val = str_replace(['{{', '}}'], '', $val);
                        $expr = preg_replace('/v/', $val, $expr, 1);
                    } else {
                        $this->_db_bind[$v] = $val;
                    }
                }
            }
        }
        return $expr;
    }

}
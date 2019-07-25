<?php declare(strict_types=1);

namespace Brisk\Toolkit\SqlBuilder;

use Brisk\Kernel\Language;
use Brisk\Kernel\Toolkit;
use Brisk\Exception\SqlCompileException;

abstract class Select extends SqlFather
{

    /**
     * 设置查询表名及字段
     *
     * @access public
     * @param array $table
     * @param array $columns
     * @return Select
     */
	public function from(array $table, array $columns = ['*'])
    {
        $this->_parts['from'] = [[$table, $columns]];
        return $this;
    }

    /**
     * 设置同时查询表名
     *
     * @access public
     * @param array $table
     * @param array $columns
     * @return Select
     */
    public function andFrom(array $table, array $columns = ['*'])
    {
        $this->_parts['andfrom'][] = [$table, $columns];
        return $this;
    }

    /**
     * 设置组分条件
     *
     * @access public
     * @param string $column
     * @param array $columns
     * @return Select
     */
    public function groupby(string $column, ...$columns)
    {
        $this->_parts['group'][] = $column;
        foreach ($columns as $val) {
            $this->_parts['group'][] = $val;
        }
        return $this;
    }

    /**
     * 设置分组查询结果过滤条件
     *
     * @access public
     * @param string $cond
     * @param array $value
     * @return Select
     */
    public function having(string $cond, ...$value)
    {
        $this->_parts['having'][] = ['cond'=> $cond, 'val'=> $value];
        return $this;
    }

    /**
     * 设置查询结果数量限制
     *
     * @access public
     * @param int $count
     * @param int $offset
     * @return Select
     */
    public function limit(int $count = 0, int $offset = 0)
    {
        $count && $this->_parts['limit'] = $count;
		$offset && $this->_parts['offset'] = $offset;
        return $this;
    }

    /**
     * 设置排序参数
     *
     * @access public
     * @param string $col
     * @param bool $asc
     * @return Select
     */
    public function orderby(string $col, bool $asc = true)
    {
        $this->_parts['order'][] = [$col, $asc];
        return $this;
    }

    /**
     * 设置左链接表、关联条件、查询字段
     *
     * @access public
     * @param array $table
     * @param string $cond
     * @param array $fields
     * @return Select
     */
    public function joinLeft(array $table, string $cond, array $fields = [])
    {
        return $this->_join($table, $cond, $fields, 'joinLeft');
    }

    /**
     * 设置内联接表、关联条件、查询字段
     *
     * @access public
     * @param array $table
     * @param string $cond
     * @param array $fields
     * @return Select
     */
    public function joinInner(array $table, string $cond, array $fields = [])
    {
        return $this->_join($table, $cond, $fields, 'joinInner');
    }

    /**
     * 设置右联接表、关联条件、查询字段
     *
     * @access public
     * @param array $table
     * @param string $cond
     * @param array $fields
     * @return Select
     */
    public function joinRight(array $table, string $cond, array $fields = [])
    {
        return $this->_join($table, $cond, $fields, 'joinRight');
    }

    /**
     * 联接
     *
     * @access protected
     * @param array $table
     * @param string $cond
     * @param array $fields
     * @param string $jointype
     * @return Select
     */
    protected function _join(array $table, string $cond, array $fields, string $jointype)
    {
        $this->_parts['join'][] = [$jointype, $table, $cond, $fields];
        return $this;
    }

    /**
     * 获取查询语句片段
     *
     * @access protected
     * @return string
     */
    protected function pickSelectPart()
    {
		$fields = $table = $join = [];
		if (isset($this->_parts['from'])) {
            $from_part = $this->_parts['from'];
            if (isset($this->_parts['andfrom'])) {
                $from_part = array_merge($from_part, $this->_parts['andfrom']);
            }
            if (count($from_part) > 0) {
                foreach ($from_part as $key => $val) {
                    //表名及名称
                    $from_table = Toolkit::each($val[0]);
                    $k = $from_table['key'];
                    $v = $from_table['value'];
                    //判断表是否需要加别名
                    if (is_integer($k)) {
                        $alias = '';
                        $table[] = $v;
                    } else {
                        $alias = $k;
                        $table[] = $v . ' ' . $alias;
                    }
                    //遍历取值字段名及别名
                    foreach ($val[1] as $k => $v) {
                        $v = trim($v);
                        //系统函数或对象调用
                        if (is_string($v) && preg_match('/^\\{\\{.*?\\}\\}/', $v)) {
                            $v = str_replace(['{{', '}}'], '', $v);
                            if (is_integer($k)) {
                                $val[1][$k] = $v;
                            } else {
                                $val[1][$k] = $v . ' ' . $k;
                            }
                        } else {
                            if (is_integer($k)) {
                                if ($alias) {
                                    $val[1][$k] = $alias . '.' . $v;
                                } else {
                                    $val[1][$k] = $v;
                                }
                            } else {
                                if ($alias) {
                                    $val[1][$k] = $alias . '.' . $v . ' ' . $k;
                                } else {
                                    $val[1][$k] = $v . ' ' . $k;
                                }
                            }
                        }
                        $fields[] = $val[1][$k];
                    }
                }
                if (isset($this->_parts['join'])) {
                    $join_part = $this->_parts['join'];
                    if (count($join_part) > 0) {
                        foreach ($join_part as $key => $val) {
                            $join_flag = $val[0];
                            $join_table = $val[1];
                            $join_cond = $val[2];
                            $join_fields = $val[3];
                            if (in_array($join_flag, ['joinLeft', 'joinInner', 'joinRight', 'joinFull'])) {
                                $keys = [
                                    'joinLeft' => 'LEFT JOIN',
                                    'joinInner' => 'INNER JOIN',
                                    'joinRight' => 'RIGHT JOIN',
                                    'joinFull' => 'FULL JOIN'
                                ];
                                $join_table = Toolkit::each($join_table);
                                $k = $join_table[0];
                                $v = $join_table[1];
                                //是否存在表别名
                                if (is_integer($k)) {
                                    $alias = '';
                                    $join[] = $keys[$join_flag] . ' ' . $v . ' ON ' . $join_cond . ' ';
                                } else {
                                    $alias = $k;
                                    $join[] = $keys[$join_flag] . ' ' . $v . ' ' . $alias . ' ON ' . $join_cond . ' ';
                                }
                                //字段别名检测
                                foreach ($join_fields as $k => $v) {
                                    $v = trim($v);
                                    //系统函数或对象调用
                                    if (is_string($v) && preg_match('/^\\{\\{.*?\\}\\}/', $v)) {
                                        $v = str_replace(['{{', '}}'], '', $v);
                                        if (is_integer($k)) {
                                            $join_fields[$k] = $v;
                                        } else {
                                            $join_fields[$k] = $v . ' ' . $k;
                                        }
                                    } else {
                                        if (is_integer($k)) {
                                            $join_fields[$k] = $alias
                                                ? $alias . '.' . $v
                                                : $v;
                                        } else {
                                            $join_fields[$k] = $alias
                                                ? $alias . '.' . $v . ' ' . $k
                                                : $v . ' ' . $k;
                                        }
                                    }
                                    $fields[] = $join_fields[$k];
                                }
                            }
                        }
                    }
                }
            }
        }
        if ($fields && $table) {
			$select = 'SELECT '. implode(', ', $fields). ' FROM '. implode(', ', $table);
            if (count($join) > 0) {
				$select = $select. ' '. implode(' ', $join);
			}
            return $select;
        }
        return null;
    }

    /**
     * 获取分组片段
     *
     * @access protected
     * @return string
     */
    protected function pickGroupPart()
    {
        $group = [];
        if (isset($this->_parts['group'])) {
            $group_part = $this->_parts['group'];
            if (count($group_part) > 0) {
                foreach ($group_part as $key => $val) {
                    $group[] = $val;
                }
            }
        }
        return implode(', ', $group);
    }

    /**
     * 获取having过滤条件片段
     *
     * @access protected
     * @return string
     */
    protected function pickHavingPart()
    {
        $having = [];
        if (isset($this->_parts['having'])) {
            $having_part = $this->_parts['having'];
            if (count($having_part) > 0) {
                foreach ($having_part as $key => $val) {
                    $part = '';
                    $cond = $val['cond'];
                    $value = $val['val'];
                    if (is_null($value)) {
                        $part = $cond;
                        if ($cond instanceof Select) {
                            $part = $part . '(' . $cond->pickHavingPart() . ')';
                        }
                    } else {
                        $part = $part . $this->_parseExpr($cond, $value);
                    }
                    if (isset($having_part[$key + 1]) && !is_null($having_part[$key + 1])) {
                        $part = $part . ' AND ';
                    }
                    $having[] = $part;
                }
            }
        }
        return $having ? implode(' ', $having) : null;
    }

    /**
     * 获取排序语句片段
     *
     * @access protected
     * @return string
     */
    protected function pickOrderPart()
    {
        $order = [];
        if (isset($this->_parts['order'])) {
            $order_part = $this->_parts['order'];
            if (count($order_part) > 0) {
                foreach ($order_part as $k => $v) {
                    if (is_null($v[1])) {
                        $order[] = $v[0];
                    } else {
                        $by = (bool)$v[1];
                        $order[] = $v[0] . ' ' . ($by ? 'ASC' : 'DESC');
                    }
                }
            }
        }
        return $order ? implode(', ', $order) : null;
    }

    /**
     * 获取limit限制语句片段
     *
     * @access protected
     * @return string
     */
    protected function pickLimitPart()
    {
        $limit = '';
        if (isset($this->_parts['limit'])) {
            $limit_part = $this->_parts['limit'];
            if ($limit_part != '') {
                $offset_part = isset($this->_parts['offset'])
                    ? $this->_parts['offset']
                    : '';
                if ($offset_part != '') {
                    $limit = $limit_part . ' OFFSET ' . $offset_part;
                } else {
                    $limit = $limit_part;
                }
            }
        }
        return $limit;
    }

    /**
     * 编译sql语句
     *
     * @access protected
     * @return Select
     */
    protected function compile()
    {
        if (!$select = $this->pickSelectPart()) {
            throw new SqlCompileException(Language::format('sql.query_compile_failed'));
        }
        $where = $this->pickWherePart();
        $group = $this->pickGroupPart();
        $having = $this->pickHavingPart();
        $order = $this->pickOrderPart();
        $limit = $this->pickLimitPart();
        $where && $select = $select. ' WHERE '. $where;
        $group && $select = $select. ' GROUP BY '. $group;
        $having && $select = $select. ' HAVING '. $having;
        $order && $select = $select. ' ORDER BY '. $order;
        $limit && $select = $select. ' LIMIT '. $limit;
        $this->_sql = $select;
        $this->_compiled = true;
        return $this;
    }

}
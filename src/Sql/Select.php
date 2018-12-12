<?php

namespace Brisk\Sql;

use Brisk\Kernel\Language;
use Brisk\Exception\SqlCompileException;
use Brisk\Kernel\Toolkit;

abstract class Select extends SqlFather
{

    /**
     * Setting the from field in the sql statement
     *
     * @param mixed table
     * @param array columns
     * @return Select
     */
	public function from($table, array $columns = ['*'])
    {
        is_array($table) || $table = [$table];
        $columns || $columns = ['*'];
        $this->_parts['from'][] = [$table, $columns];
        return $this;
    }

    /**
     * Setting the group field in the sql statement
     *
     * @param array columns
     * @return Select
     */
    public function group($columns)
    {
        is_array($columns) || $columns = [$columns];
		foreach ($columns as $k=> $v) {
            $this->_parts['group'][] = $v;
        }
        return $this;
    }

    /**
     * Setting the having field in the sql statement
     *
     * @param string cond
     * @param array $args
     * @return Select
     */
    public function having($cond, ...$args)
    {
        $this->_parts['having'][] = ['cond'=> $cond, 'val'=> $args];
        return $this;
    }

    /**
     * Setting the limit field in the sql statement
     *
     * @param int count
     * @param int offset
     * @return Select
     */
    public function limit($count = 0, $offset = 0)
    {
        $count && $this->_parts['limit'] = $count;
		$offset && $this->_parts['offset'] = $offset;
        return $this;
    }

    /**
     * Setting the order field in the sql statement
     *
     * @param string col
     * @param bool asc
     * @return Select
     */
    public function order($col, $asc = true)
    {
        $this->_parts['order'][] = [$col, $asc];
        return $this;
    }

    /**
     * Setting the joinLeft field in the sql statement
     *
     * @param string|array table
     * @param string cond
     * @param array fields
     * @return Select
     */
    public function joinLeft($table, $cond, array $fields = [])
    {
        return $this->_join($table, $cond, $fields, 'joinLeft');
    }

    /**
     * Setting the joinInner field in the sql statement
     *
     * @param string|array table
     * @param string cond
     * @param array fields
     * @return Select
     */
    public function joinInner($table, $cond, array $fields = [])
    {
        return $this->_join($table, $cond, $fields, 'joinInner');
    }

    /**
     * Setting the joinRight field in the sql statement
     *
     * @param string|array table
     * @param string cond
     * @param array fields
     * @return Select
     */
    public function joinRight($table, $cond, array $fields = [])
    {
        return $this->_join($table, $cond, $fields, 'joinRight');
    }

    /**
     *
     * @param string|array $table
     * @param string $cond
     * @param array $fields
     * @param string $jointype
     * @return Select
     */
    protected function _join($table, $cond, array $fields, $jointype)
    {
        is_array($table) || $table = [$table];
        $this->_parts['join'][] = [$jointype, $table, $cond, $fields];
        return $this;
    }

    /**
     * Get the select fragment in the sql statement
     *
     * @return string
     */
    public function pickSelectPart()
    {
		$fields = [];
		$table = [];
		$join = [];
		$from_part = $this->_parts['from'];
        if (count($from_part) > 0) {
            foreach ($from_part as $key=> $val) {
                //表名及名称
				$from_table = each($val[0]);
				$k = $from_table['key'];
				$v = $from_table['value'];
                //判断表是否需要加别名
                if (is_integer($k)) {
                    $alias = '';
                    $table[] = $v;
                } else {
                    $alias = $k;
                    $table[] = $v. ' '. $alias;
                }
                //遍历取值字段名及别名
                foreach ($val[1] as $k=> $v) {
                    $v = trim($v);
                    //系统函数或对象调用
                    if (preg_match('/^\\{\\{.*?\\}\\}/', $v)) {
                        $v = str_replace(['{{', '}}'], '', $v);
						if (is_integer($k)) {
							$val[1][$k] = $v;
						} else {
							$val[1][$k] = $v. ' '. $k;
						}
                    } else {
                        if (is_integer($k)) {
							if ($alias) {
								$val[1][$k] = $alias. '.'. $v;
							} else {
								$val[1][$k] = $v;
							}
                        } else {
							if ($alias) {
								$val[1][$k] = $alias. '.'. $v. ' '. $k;
							} else {
								$val[1][$k] = $v. ' '. $k;
							}
                        }
                    }
                    $fields[] = $val[1][$k];
                }
            }
			$join_part = $this->_parts['join'];
            if (count($join_part) > 0) {
                foreach ($join_part as $key=> $val) {
					$join_flag = $val[0];
					$join_table = $val[1];
					$join_cond = $val[2];
					$join_fields = $val[3];
                    if (in_array($join_flag, ['joinLeft', 'joinInner', 'joinRight', 'joinFull'])) {
                        $keys = [
                            'joinLeft'=> 'LEFT JOIN',
                            'joinInner'=> 'INNER JOIN',
                            'joinRight'=> 'RIGHT JOIN',
                            'joinFull'=> 'FULL JOIN'
                        ];
						$join_table = each($join_table);
						$k = $join_table[0];
						$v = $join_table[1];
                        //是否存在表别名
                        if (is_integer($k)) {
                            $alias = '';
                            $join[] = $keys[$join_flag]. ' '. $v. ' ON '. $join_cond. ' ';
                        } else {
                            $alias = $k;
                            $join[] = $keys[$join_flag]. ' '. $v. ' '. $alias. ' ON '. $join_cond. ' ';
                        }
                        //字段别名检测
                        foreach ($join_fields as $k=> $v) {
                            $v = trim($v);
                            //系统函数或对象调用
                            if (preg_match('/^\\{\\{.*?\\}\\}/', $v)) {
                                $v = str_replace(['{{', '}}'], '', $v);
								if (is_integer($k)) {
									$join_fields[$k] = $v;
								} else {
								    $join_fields[$k] = $v. ' '. $k;
								}
                            } else {
                                if (is_integer($k)) {
                                    $join_fields[$k] = $alias
                                        ? $alias. '.'. $v
                                        : $v;
                                } else {
                                    $join_fields[$k] = $alias
                                        ? $alias. '.'. $v. ' '. $k
                                        : $v. ' '. $k;
                                }
                            }
                            $fields[] = $join_fields[$k];
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
     * Get the group fragment in the sql statement
     *
     * @return string
     */
    public function pickGroupPart()
    {
        $group = [];
		$group_part = $this->_parts['group'];
        if (count($group_part) > 0) {
            foreach ($group_part as $key=> $val) {
                $group[] = $val;
            }
        }
        return implode(', ', $group);
    }

    /**
     * Get the having fragment in the sql statement
     *
     * @return string
     */
    public function pickHavingPart()
    {
        $having = [];
		$having_part = $this->_parts['having'];
        if (count($having_part) > 0) {
            foreach ($having_part as $key=> $val) {
                $part = '';
                $cond = $val['cond'];
                $value = $val['val'];
                if (is_null($value)) {
                    $part = $cond;
                    if ($cond instanceof Select) {
                        $part = $part. '('. $cond->pickHavingPart(). ')';
                    }
                } else {
                    $part = $part. $this->_parseExpr($cond, $value);
                }
                if (!is_null($having_part[$key+1])) {
                    $part = $part. ' AND ';
                }
				$having[] = $part;
            }
        }
        return $having ? implode(' ', $having) : null;
    }

    /**
     * Get the order fragment in the sql statement
     *
     * @return string
     */
    public function pickOrderPart()
    {
        $order = [];
		$order_part = $this->_parts['order'];
        if (count($order_part) > 0) {
            foreach ($order_part as $k=> $v) {
                if (is_null($v[1])) {
                    $order[] = $v[0];
                } else {
					$by = (bool)$v[1];
                    $order[] = $v[0]. ' '. ($by ? 'ASC' : 'DESC');
                }
            }
        }
        return $order ? implode(', ', $order) : null;
    }

    /**
     * Get the limit fragment in the sql statement
     *
     * @return string
     */
    public function pickLimitPart()
    {
        $limit = '';
		$limit_part = $this->_parts['limit'];
        if ($limit_part != '') {
			$offset_part = $this->_parts['offset'];
			if ($offset_part != '') {
				$limit = $limit_part. ' OFFSET '. $offset_part;
			} else {
				$limit = $limit_part;
			}
        }
        return $limit;
    }

    /**
     * Compile the select statment
     *
     * @return Select
     */
    public function compile()
    {
        if (!$select = $this->pickSelectPart()) {
            throw new SqlCompileException(Language::get('sql.query_compile_failed'));
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
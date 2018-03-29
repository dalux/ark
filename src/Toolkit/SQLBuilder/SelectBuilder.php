<?php

namespace Ark\Toolkit\SQLBuilder;

abstract class SelectBuilder extends BuilderFather
{
    
    /**
     * 要查询的表
     *
     * @access public
     * @param mixed $table
     * @param array $columns
     * @return SelectBuilder
     */
    function from($table, array $columns = array('*')) 
    {
		is_array($table) || $table = array($table);
        $this->_parts['from'][] = array($table, $columns);
        return $this;
    }
    
    /**
     * 分组方法
     *
     * @access public
     * @param mixed $column
     * @return SelectBuilder
     */
    function group($column)
    {
        is_array($column) || $column = array($column);
        foreach ($column as $v) {
            $this->_parts['group'][] = $v;
        }
        return $this;
    }

    /**
     * 分组条件
     *
     * @access public
     * @param $cond
     * @return SelectBuilder
     */
    function having($cond)
    {
        $values = func_get_args();
        array_shift($values);
        $this->_parts['having'][] = array('cond'=> $cond, 'val'=> $values);
        return $this;
    }

    /**
     * 限制条件
     *
     * @access public
     * @param int $count
     * @param int $offset
     * @return SelectBuilder
     */
    function limit($count = 0, $offset = 0) 
    {
        $count	&& ($this->_parts['limit']	= (int)$count);
        $offset && ($this->_parts['offset']  = (int)$offset);
        return $this;
    }

    /**
     * 排序条件
     *
     * @access public
     * @param string $col
     * @param boolean $asc
     * @return SelectBuilder
     */
    function order($col, $asc = true) 
    {
        $this->_parts['order'][] = array($col, $asc);
        return $this;
    }

    /**
     * 左联接
     *
     * @access public
     * @param array $table
     * @param string $cond
     * @param array $fetch
     * @return SelectBuilder
     */
    function joinLeft($table, $cond, $fetch = array('*')) 
    {
        return $this->_join($table, $cond, $fetch, 'joinLeft');
    }

    /**
     * 内联接
     *
     * @access public
     * @param array $table
     * @param string $cond
     * @param array $fetch
     * @return SelectBuilder
     */
    function joinInner($table, $cond, $fetch = array('*')) 
    {
        return $this->_join($table, $cond, $fetch, 'joinInner');
    }

    /**
     * 右联接
     *
     * @access public
     * @param array $table
     * @param string $cond
     * @param array $fetch
     * @return SelectBuilder
     */
    function joinRight($table, $cond, $fetch = array('*')) 
    {
        return $this->_join($table, $cond, $fetch, 'joinRight');
    }
    
    /**
     * 添加联接
     * 
     * @access protected
     * @param array $table 表名
     * @param string $cond 联接条件
     * @param array $fetch 当前表取值字段
     * @param string $jointype 联接类型
     * @return SelectBuilder
     */
    protected function _join($table, $cond, $fetch, $jointype) 
    {
        is_array($table) || $table = array($table);
        is_array($fetch) || $fetch = array($fetch);
        $this->_parts['join'][] = array($jointype, $table, $cond, $fetch);
        return $this;
    }

    /**
     * 获取select片段
     *
     * @access public
     * @return string
     */
    function pickSelectPart()
    {
        $fields = $table = $join = array();
        if ($from_part = $this->_parts['from']) {
            foreach ($from_part as $key=> $val) {
                //表名及名称
                list($k, $v) = each($val[0]);
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
                    if (preg_match('/^\{\{.*?\}\}$/', $v)) {
                        $v = str_replace(array('{{', '}}'), '', $v);
                        $val[1][$k] = is_integer($k) ? $v : $v. ' '. $k;
                    } else {
                        if (is_integer($k)) {
                            $val[1][$k] = $alias ? $alias. '.'. $v : $v;
                        } else {
                            $val[1][$k] = $alias ? $alias. '.'. $v. ' '. $k : $v. ' '. $k;
                        }
                    }
                    $fields[] = $val[1][$k];
                }
            }
            if ($join_part = $this->_parts['join']) {
                foreach ($join_part as $key=> $val) {
                    list($join_flag, $join_table, $join_cond, $join_fields) = $val;
                    if (in_array($join_flag, array('joinLeft', 'joinInner', 'joinRight', 'joinFull'))) {
                        $keys = array(
                            'joinLeft'=> 'LEFT JOIN',
                            'joinInner'=> 'INNER JOIN',
                            'joinRight'=> 'RIGHT JOIN',
                            'joinFull'=> 'FULL JOIN',
                        );
                        list($k, $v) = each($join_table);
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
                            if (preg_match('/^\{\{.*?\}\}$/', $v)) {
                                $v = str_replace(array('{{', '}}'), '', $v);
                                $join_fields[$k] = is_integer($k) ? $v : $v. ' '. $k;
                            } else {
                                if (is_integer($k)) {
                                    $join_fields[$k] = $alias ? $alias. '.'. $v : $v;
                                } else {
                                    $join_fields[$k] = $alias ? $alias. '.'. $v. ' '. $k : $v. ' '. $k;
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
            $join && $select.= ' '. implode(' ', $join);
            return $select;
        }
        return null;
    }

    /**
     * 获取group片段
     *
     * @access public
     * @return string
     */
    function pickGroupPart()
    {
        $group = array();
        if ($group_part = $this->_parts['group']) {
            foreach ($group_part as $key=> $val) {
                $group[] = $val;
            }
        }
        return implode(', ', $group);
    }

    /**
     * 获取having片段
     *
     * @access public
     * @return string
     */
    function pickHavingPart()
    {
        $having = array();
        if ($having_part = $this->_parts['having']) {
            foreach ($having_part as $key=> $val) {
                $part = '';
                $cond = $val['cond'];
                $value = $val['val'];
                if (is_null($value)) {
                    $part = $cond;
                    if ($cond instanceof self) {
                        $part.= '('. $cond->pickHavingPart(). ')';
                    }
                } else {
                    $part.= $this->_parseExpr($cond, $value);
                }
                if (!is_null($having_part[$key+1])) {
                    $part.= ' AND ';
                }
				$having[] = $part;
            }
        }
        return $having ? implode(' ', $having) : null;
    }

    /**
     * 获取order片段
     *
     * @access public
     * @return string
     */
    function pickOrderPart()
    {
        $order = array();
        if ($order_part = $this->_parts['order']) {
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
     * 获取limit片段
     *
     * @access public
     * @return string
     */
    function pickLimitPart()
    {
        $limit = null;
        if ($limit_part = $this->_parts['limit']) {
            $offset_part = $this->_parts['offset'];
            $limit = $offset_part ? $limit_part. ' OFFSET '. $offset_part : $limit_part;
        }
        return $limit;
    }

    /**
     * 拼凑sql语句
     *
     * @access protected
     * @return string
     */
    function getSQL() 
    {
        if ($select = $this->pickSelectPart()) {
            $where = $this->pickWherePart();
            $group = $this->pickGroupPart();
            $having = $this->pickHavingPart();
            $order = $this->pickOrderPart();
            $limit = $this->pickLimitPart();
            $where && $select.= ' WHERE '. $where;
            $group && $select.= ' GROUP BY '. $group;
            $having && $select.= ' HAVING '. $having;
            $order && $select.= ' ORDER BY '. $order;
            $limit && $select.= ' LIMIT '. $limit;
            return $select;
        }
        return null;
    }

}
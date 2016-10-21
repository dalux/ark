<?php

namespace Ark\Com\Database\SQLBuilder;

class Update extends Father
{

    /**
     * 要更新的表及更新值
     *
     * @access public
     * @param mixed $table 要更新的表
     * @param array $updates 要更新的字段及其值
     * @return Father
     */
    function set($table, array $updates = array()) 
    {
		is_array($table) || $table = array($table);
        $this->_parts['update'][] = $table;
        $this->_parts['set'][] = $updates;
        return $this;
    }

    /**
     * 拼凑sql语句
     *
     * @access private
     * @return string
     */
    function getSQL() 
    {
        $update_part = $this->_parts['update'];
        $set_part = $this->_parts['set'];
        if ($update_part && $set_part) {
            $update = $set = array();
            foreach ($update_part as $key=> $val) {
                list($k, $v) = each($val);
                if (is_integer($k)) {
                    $alias = '';
                    $update[] = $v;
                } else {
                    $alias = $k;
                    $update[] = $v. ' '. $alias;
                }
                foreach ($set_part[$key] as $_key=> $_val) {
                    $_val = is_object($_val) && $_val instanceof Expr
                        ? $_val
                        : Toolkit::quote($_val);
                    $set[] = $alias 
                        ? $alias. '.'. $_key. '='. $_val
                        : $_key. '='. $_val;
                }
            }
            $update = 'UPDATE '. implode(', ', $update). ' SET '. implode(', ', $set);
            if ($where = $this->pickWherePart()) {
                $update.= ' WHERE '. $where;
            }
            return $update;
        }
        return null;
    }
    
}
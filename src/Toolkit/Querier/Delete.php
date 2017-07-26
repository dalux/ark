<?php

namespace Ark\Toolkit\Querier;

class Delete extends Father
{
        
    /**
     * 要删除的表
     *
     * @access public
     * @param string $table
     * @return Delete
     */
    function from($table) 
    {
        is_array($table) || $table = array($table);
        $this->_parts['from'] = $table;
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
        if ($from = $this->_parts['from']) {
            list($alias, $table) = each($from);
            $delete = is_integer($alias)
                ? 'DELETE FROM '. $table
                : 'DELETE FROM '. $table. ' '. $alias;
            if ($where = $this->pickWherePart()) {
                $delete.= ' WHERE '. $where;
            }
            return $delete;
        }
        return null;
    }

}
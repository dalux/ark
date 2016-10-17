<?php

namespace Ark\Toolbox\SQLBuilder\Delete;

use Ark\Toolbox\SQLBuilder\Delete;

class Mysql extends Delete
{
    
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
            $alias = is_integer($alias) ? '' : $alias;
            $delete = 'DELETE FROM '. $table. ' '. $alias;
            if ($where = $this->pickWherePart()) {
                $delete.= ' WHERE '. $where;
            }
            return $delete;
        }
        return null;

    }

}
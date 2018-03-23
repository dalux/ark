<?php

class Ark_Sql_Builder_Delete_Mysql extends Ark_Sql_Builder_Delete
{

    /**
     * 数据库类型
     *
     * @var string
     */
    protected $_db_type = 'mysql';

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
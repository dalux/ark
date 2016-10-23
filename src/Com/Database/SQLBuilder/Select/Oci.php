<?php

namespace Ark\Com\Database\SQLBuilder\Select;

use Ark\Com\Database\SQLBuilder\Select;

class Oci extends Select
{


    /**
     * 数据库类型
     *
     * @var string
     */
    protected $_db_type = 'oci';


    /**
     * 获取where片段
     *
     * @access public
     * @return string
     */
    function pickLimitPart()
    {
        return null;
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
            $where && $select.= ' WHERE '. $where;
            $group && $select.= ' GROUP BY '. $group;
            $having && $select.= ' HAVING '. $having;
            $order && $select.= ' ORDER BY '. $order;
            if ($limit = $this->_parts['limit']) {
                if ($offset = $this->_parts['offset']) {
                    $select = sprintf('select * from (select tmptable1.*, rownum tmprn from (%s) tmptable1 where rownum<=%u) where tmprn>%u', $select, $offset+$limit, $offset);
                } else {
                    $select = sprintf('select tmptable1.* from (%s) tmptable1 where rownum<=%u', $select, $limit);
                }
            }
            return $select;
        }

        return null;

    }

}
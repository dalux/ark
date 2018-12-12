<?php

namespace Brisk\Sql\Select;

use Brisk\Sql\Select;

use Brisk\Kernel\Language;
use Brisk\Exception\SqlCompileException;
use Brisk\Sql\SqlFather;

class Oci extends Select
{

    /**
     * @var string
     */
    protected $_db_type = 'Oci';

    /**
     * Put quotation marks on a field
     *
     * @param mixed value
     * @return string
     */
    public function quote($value)
    {
        if (is_array($value)) {
			foreach ($value as $key=> $val) {
				$value[$key] = $this->quote($val);
			}
            return implode(',', $value);
        } elseif (is_int($value) || is_float($value)) {
            return $value;
        }
        return '\'' . str_replace('\'', '\'\'', $value) . '\'';
    }

    /**
     * @return string
     */
    public function pickLimitPart()
    {
        return '';
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
        $where && $select = $select. ' WHERE '. $where;
        $group && $select = $select. ' GROUP BY '. $group;
        $having && $select = $select. ' HAVING '. $having;
        $order && $select = $select. ' ORDER BY '. $order;
        if ($limit = $this->_parts['limit']) {
            if ($offset = $this->_parts['offset']) {
                $select = sprintf('select * from (select tmptable1.*, rownum tmprn from (%s) tmptable1 where rownum<=%u) where tmprn>%u', $select, $offset+$limit, $offset);
            } else {
                $select = sprintf('select tmptable1.* from (%s) tmptable1 where rownum<=%u', $select, $limit);
            }
        }
        $this->_sql = $select;
        $this->_compiled = true;
        return $this;
    }

}
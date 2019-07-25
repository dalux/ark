<?php declare(strict_types=1);

namespace Brisk\Toolkit\SqlBuilder\Select;

use Brisk\Kernel\Language;
use Brisk\Exception\SqlCompileException;
use Brisk\Toolkit\SqlBuilder\Select;

class Oci extends Select
{

    /**
     * 数据库类型
     * 
     * @var string
     */
    protected $_db_type = 'Oci';

    /**
     * 为数据添加引号
     *
     * @access public
     * @param mixed $value
     * @return string
     */
    public function quote($value)
    {
        if (is_int($value) || is_float($value)
                || preg_match('/^\\{\\{.*?\\}\\}/', $value)
                || preg_match('/.*?\(.*?\)/', $value)) {
            return $value;
        } elseif (is_array($value)) {
            foreach ($value as $key=> $val) {
                $value[$key] = $this->quote($val);
            }
            return implode(',', $value);
        } else {
            return '\'' . str_replace('\'', '\'\'', $value) . '\'';
        }
    }

    /**
     * 获取limit语句片段
     *
     * @access public
     * @return string
     */
    public function pickLimitPart()
    {
        return '';
    }

    /**
     * 编译当前sql
     *
     * @access public
     * @return Select
     */
    public function compile()
    {
        if (!$select = $this->pickSelectPart()) {
            throw new SqlCompileException(Language::format('sql.query_compile_failed'));
        }
        $where = $this->pickWherePart();
        $group = $this->pickGroupPart();
        $having = $this->pickHavingPart();
        $order = $this->pickOrderPart();
        $where && $select = $select. ' WHERE '. $where;
        $group && $select = $select. ' GROUP BY '. $group;
        $having && $select = $select. ' HAVING '. $having;
        $order && $select = $select. ' ORDER BY '. $order;
        if (isset($this->_parts['limit'])) {
            $limit = $this->_parts['limit'];
            if (isset($this->_parts['offset'])) {
                $offset = $this->_parts['offset'];
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
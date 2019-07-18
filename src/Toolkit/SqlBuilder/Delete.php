<?php declare(strict_types=1);

namespace Brisk\Toolkit\SqlBuilder;

use Brisk\Kernel\Language;
use Brisk\Exception\SqlCompileException;

abstract class Delete extends SqlFather
{

    /**
     * 设置要删除数据的表名
     *
     * @access public
     * @param mixed $table
     * @return Delete
     */
    public function from($table)
    {
        is_array($table) || $table = [$table];
        $this->_parts['from'] = $table;
        return $this;
    }

    /**
     * 编译当前sql
     *
     * @access protected
     * @return Delete
     */
    protected function compile()
    {
		$from = $this->_parts['from'];
        if (count($from) == 0) {
            throw new SqlCompileException(Language::format('sql.query_compile_failed'));
        }
        $from = each($from);
        $alias = $from['key'];
        $table = $from['value'];
        $delete = is_integer($alias)
            ? 'DELETE FROM '. $table
            : 'DELETE FROM '. $table. ' '. $alias;
        $where = $this->pickWherePart();
        if ($where) {
            $delete = $delete. ' WHERE '. $where;
        }
        $this->_sql = $delete;
        $this->_compiled = true;
        return $this;
    }

}
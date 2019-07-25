<?php declare(strict_types=1);

namespace Brisk\Toolkit\SqlBuilder\Delete;

use Brisk\Kernel\Toolkit;
use Brisk\Toolkit\SqlBuilder\Delete;
use Brisk\Kernel\Language;
use Brisk\Exception\SqlCompileException;

class Mysql extends Delete
{

    /**
     * 数据库类型
     *
     * @var string
     */
    protected $_db_type = 'mysql';

    /**
     * 编译当前sql
     *
     * @access public
     * @return Delete
     */
    public function compile()
    {
        if (!isset($this->_parts['from'])
                || count($this->_parts['from']) == 0) {
            throw new SqlCompileException(Language::format('sql.query_compile_failed'));
        }
        $from = $this->_parts['from'];
        $from = Toolkit::each($from);
        $alias = $from['key'];
        $table = $from['value'];
        if (is_integer($alias)) {
            $alias = '';
        }
        $delete = 'DELETE FROM '. $table. ' '. $alias;
        if ($where = $this->pickWherePart()) {
            $delete = $delete. ' WHERE '. $where;
        }
        $this->_sql = $delete;
        $this->_compiled = true;
        return $this;
    }

}
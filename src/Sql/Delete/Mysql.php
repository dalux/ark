<?php declare(strict_types=1);

namespace Brisk\Sql\Delete;

use Brisk\Sql\Delete;
use Brisk\Language;
use Brisk\Exception\SqlCompileException;

class Mysql extends Delete
{

    /**
     * @var string
     */
    protected $_db_type = 'mysql';

    /**
     * Compile the delete statment
     *
     * @return Delete
     */
    public function compile()
    {
        $from = $this->_parts['from'];
        if (count($from) == 0) {
            throw new SqlCompileException(Language::format('sql.query_compile_failed'));
        }
        $from = each($from);
        $alias = $from[0];
        $table = $from[1];
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
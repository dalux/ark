<?php declare(strict_types=1);

namespace Brisk\Toolkit\SqlBuilder;

use Brisk\Kernel\Language;
use Brisk\Exception\SqlCompileException;

abstract class Update extends SqlFather
{

    /**
     * Setting the set field in the sql statement
     *
     * @param mixed table
     * @param array updates
     * @return Update
     */
    public function set(string $table, array $updates = [])
    {
        is_array($table) || $table = [$table];
        $this->_parts['update'] = $table;
        $this->_parts['set'] = $updates;
        return $this;
    }

    /**
     * Compile the update statment
     *
     * @return Update
     */
    protected function compile()
    {
        $update_part = $this->_parts['update'];
        $set_part = $this->_parts['set'];
        if (count($update_part) == 0 || count($set_part) == 0) {
            throw new SqlCompileException(Language::format('sql.query_compile_failed'));
        }
        $update = 'UPDATE';
        $set = [];
        $update_part = each($update_part);
        $k = $update_part['key'];
        $v = $update_part['value'];
        if (is_integer($k)) {
            $alias = '';
            $sql = $update. ' '. $v;
        } else {
            $alias = $k;
            $sql = $update. ' '. $v. ' '. $alias;
        }
        foreach ($set_part as $key=> $val) {
            if (preg_match('/^\\{\\{.*?\\}\\}$/', $val)) {
                $val = str_replace(['{{', '}}'], '', $val);
                $set[] = $alias
                    ? $alias. '.'. $key. '='. $val
                    : $key. '='. $val;
            } else {
                $this->_db_bind[':'. $key] = $val;
                $set[] = $alias
                    ? $alias. '.'. $key. '=:'. $key
                    : $key. '=:'. $key;
            }
        }
        $sql = $sql. ' SET '. implode(', ', $set);
        $where = $this->pickWherePart();
        if ($where) {
            $sql = $sql. ' WHERE '. $where;
        }
        $this->_sql = $sql;
        $this->_compiled = true;
        return $this;
    }
    
}
<?php declare(strict_types=1);

namespace Brisk\Toolkit\SqlBuilder;

use Brisk\Kernel\Language;
use Brisk\Exception\SqlCompileException;
use Brisk\Kernel\Toolkit;

abstract class Update extends SqlFather
{

    /**
     * 设置更新的表及字段值
     *
     * @access public
     * @param array $table
     * @param array $updates
     * @return Update
     */
    public function set(array $table, array $updates = [])
    {
        $this->_parts['update'] = $table;
        $this->_parts['set'] = $updates;
        return $this;
    }

    /**
     * 编译当前update语句
     *
     * @return Update
     */
    protected function compile()
    {
        if (!isset($this->_parts['update'])
                || count($this->_parts['update']) == 0
                || !isset($this->_parts['set'])
                || count($this->_parts['set']) == 0) {
            throw new SqlCompileException(Language::format('sql.query_compile_failed'));
        }
        $update_part = $this->_parts['update'];
        $set_part = $this->_parts['set'];
        $update = 'UPDATE';
        $set = [];
        $update_part = Toolkit::each($update_part);
        $k = $update_part['key'];
        $v = $update_part['value'];
        if (is_integer($k)) {
            $alias = '';
            $sql = $update . ' ' . $v;
        } else {
            $alias = $k;
            $sql = $update . ' ' . $v . ' ' . $alias;
        }
        foreach ($set_part as $key => $val) {
            if (is_string($val) && preg_match('/\{\{.*?\}\}$/', $val)) {
                $val = str_replace(['{{', '}}'], '', $val);
                $set[] = $alias
                    ? $alias . '.' . $key . '=' . $val
                    : $key . '=' . $val;
            } else {
                $this->_db_bind[':' . $key] = ['type'=> gettype($val), 'value'=> $val];
                $set[] = $alias
                    ? $alias . '.' . $key . '=:' . $key
                    : $key . '=:' . $key;
            }
        }
        $sql = $sql . ' SET ' . implode(', ', $set);
        $where = $this->pickWherePart();
        if ($where) {
            $sql = $sql . ' WHERE ' . $where;
        }
        $this->_sql = $sql;
        $this->_compiled = true;
        return $this;
    }
    
}
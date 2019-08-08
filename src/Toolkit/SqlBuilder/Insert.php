<?php declare(strict_types=1);

namespace Brisk\Toolkit\SqlBuilder;

use Brisk\Kernel\Language;
use Brisk\Exception\SqlCompileException;

abstract class Insert extends SqlFather
{

    /**
     * 设置要插入的表及数据数组
     *
     * @access public
     * @param string $table
     * @param array $data
     * @return Insert
     */
    public function into(string $table, array $data)
    {
        $this->_parts['table'] = $table;
        $this->_parts['data'] = $data;
        return $this;
    }

    /**
     * 获取insert语句片段
     *
     * @access protected
     * @return string
     */
    protected function pickInsertPart()
    {
        $result = '';
        if (isset($this->_parts['table']) && isset($this->_parts['data'])) {
            $table = $this->_parts['table'];
            $data  = $this->_parts['data'];
            if ($table && count($data) > 0) {
                $result = $result . 'INSERT INTO ' . $table;
                $result = $result . '(' . implode(', ', array_keys($data)) . ')';
            }
        }
        return $result;
    }

    /**
     * 获取values语句片段
     *
     * @access protected
     * @return string
     */
    protected function pickValuesPart()
    {
        $result = '';
        if (isset($this->_parts['data'])) {
            $data = $this->_parts['data'];
            $result = 'VALUES';
            foreach ($data as $k => $v) {
                if (is_string($v) && preg_match('/\{\{.*?\}\}/', $v)) {
                    $v = str_replace(['{{', '}}'], '', $v);
                    $data[$k] = $v;
                } else {
                    $this->_db_bind[':' . $k] = ['type'=> gettype($v), 'value'=> $v];
                    $data[$k] = ':' . $k;
                }
            }
            $result = $result . '(' . implode(', ', $data) . ')';
        }
        return $result;
    }

    /**
     * 编译当前sql语句
     *
     * @access protected
     * @return Insert
     */
    protected function compile()
    {
        if (!isset($this->_parts['table'])
                || !isset($this->_parts['data'])
                || count($this->_parts['data']) == 0) {
            throw new SqlCompileException(Language::format('sql.query_compile_failed'));
        }
        $insert = $this->pickInsertPart();
        $values = $this->pickValuesPart();
        $this->_sql = $insert. ' '. $values;
        $this->_compiled = true;
        return $this;
    }
    
}
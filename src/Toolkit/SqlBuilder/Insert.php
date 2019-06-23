<?php declare(strict_types=1);

namespace Brisk\Toolkit\SqlBuilder;

use Brisk\Kernel\Language;
use Brisk\Exception\SqlCompileException;

abstract class Insert extends SqlFather
{

    /**
     * Setting the into field in the sql statement
     *
     * @param string table
     * @param array data
     * @return Insert
     */
    public function into(string $table, array $data)
    {
        $this->_parts['table'] = $table;
        $this->_parts['data'] = $data;
        return $this;
    }

    /**
     * Get the insert fragment in the sql statement
     *
     * @return string
     */
    protected function pickInsertPart()
    {
		$table = $this->_parts['table'];
        $data = $this->_parts['data'];
        $result = '';
        if ($table && count($data) > 0) {
            $result = $result. 'INSERT INTO '. $table;
            $result = $result. '('. implode(', ', array_keys($data)). ')';
        }
        return $result;
    }

    /**
     * Get the values fragment in the sql statement
     *
     * @return string
     */
    protected function pickValuesPart()
    {
        $data = $this->_parts['data'];
        $result = 'VALUES';
        foreach ($data as $k=> $v) {
            if (is_string($v) && preg_match('/^\\{\\{.*?\\}\\}$/', $v)) {
                $v = str_replace(['{{', '}}'], '', $v);
                $data[$k] = $v;
            } else {
                $this->_db_bind[':'. $k] = $v;
                $data[$k] = ':'. $k;
            }
        }
        $result = $result. '('. implode(', ', $data). ')';
        return $result;
    }

    /**
     * Compile the insert statment
     *
     * @return Insert
     */
    protected function compile()
    {
        if (count($this->_parts['table']) == 0
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
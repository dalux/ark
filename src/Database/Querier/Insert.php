<?php

namespace Ark\Database\Querier;

use Ark\Database\Toolkit;

class Insert extends Father
{
    
    /**
     * 要插入数据的表
     *
     * @access public
     * @param string $table 要插入的表
     * @param array $fields 表字段
     * @return Insert
     */
    function into($table, array $fields) 
    {
        $this->_parts['table'] = $table;
        $this->_parts['fields'] = $fields;
        return $this;
    }

    /**
     * 要插入数据的表
     *
     * @param $values
     * @return Insert
     */
    function values($values)
    {
        $this->_parts['values'] = $values;
        return $this;
    }

    /**
     * 获取insert片段
     *
     * @return string
     */
    function pickInsertPart()
    {
        $table = $this->_parts['table'];
        $fields = $this->_parts['fields'];
        $result = '';
        if ($table && $fields) {
            $result.= 'INSERT INTO '. $table;
            $result.= '('. implode(', ', array_values($fields)). ')';
        }
        return $result;
    }


    /**
     * 取得VALUES片段
     *
     * @return string
     */
    function pickValuesPart()
    {
        $val = $this->_parts['values'];
        $result = '';
        //单数据
        if (is_array($val)) {
            $result.= 'VALUES';
            foreach ($val as $k=> $v) {
                $v = trim($v);
                if (preg_match('/^\{\{.*?\}\}$/', $v) || preg_match('/.*?\(.*?\)/', $v)) {
                    $v = str_replace(array('{{', '}}'), '', $v);
                    $val[$k] = ':'. $k;
                    $this->_db_bind[':'. $k] = $v;
                } else {
                    $val[$k] = ':'. $k;
                    $this->_db_bind[':'. $k] = Toolkit::quote($v, $this->_db_type);
                }
            }
            $result.= '('. implode(', ', $val). ')';
        } elseif ($val instanceof Select) {
            $result.= '('. $val->getRealSQL(). ')';
        }
        return $result;
    }

    /**
     * 拼凑sql语句
     *
     * @access public
     * @return string
     */
    function getSQL() 
    {
        $insert = $this->pickInsertPart();
        $values = $this->pickValuesPart();
        if ($insert && $values) {
            return $insert. ' '. $values;
        }
        return null;
    }
    
}
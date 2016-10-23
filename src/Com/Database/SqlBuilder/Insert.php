<?php

namespace Ark\Com\Database\SqlBuilder;

use Ark\Com\Database\Toolkit;

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
        $this->_parts['values'][] = $values;
        return $this;
    }
    
    /**
     * 清空已写入的数据
     *
     * @return Insert
     */
    function clearValues()
    {
        $this->_parts['values'] = array();
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
            foreach ($fields as $k=> $v) {
                $fields[$k] = $v;
            }
            $result.= '('. implode(', ', $fields). ')';
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
        $values = $this->_parts['values'];
        $result = '';
        $count = count($values);
        //单数据
        if ($count == 1) {
            $val = $values[0];
            if (is_array($val)) {
                $result.= 'VALUES';
                foreach ($val as $k=> $v) {
                    $v = trim($v);
                    if (preg_match('/^\{\{.*?\}\}$/', $v) || preg_match('/.*?\(.*?\)/', $v)) {
                        $v = str_replace(array('{{', '}}'), '', $v);
                        $val[$k] = $v;
                    } else {
                        $val[$k] = Toolkit::quote($v, $this->_db_type);
                    }
                }
                $result.= '('. implode(', ', $val). ')';
            } elseif ($val instanceof Select) {
                $result.= '('. $val->getSQL(). ')';
            }
            return $result;
        } elseif ($count > 1) { //多数据            
            $part = array();
            foreach ($values as $key=> $val) {
                if (is_array($val)) {
                    foreach ($val as $k=> $v) {
                        $v = trim($v);
                        if (preg_match('/^\{\{.*?\}\}$/', $v) || preg_match('/.*?\(.*?\)/', $v)) {
                            $v = str_replace(array('{{', '}}'), '', $v);
                            $val[$k] = $v;
                        } else {
                            $val[$k] = Toolkit::quote($v, $this->_db_type);
                        }
                    }
                    $part[] = '('. implode(', ', $val). ')';
                } elseif ($val instanceof Select) {
                    $part[] = '('. $val->getSQL(). ')';
                }
            }
            $result.= 'VALUES'. implode(', ', $part);
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
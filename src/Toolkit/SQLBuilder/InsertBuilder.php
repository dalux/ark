<?php

namespace Ark\Toolkit\SQLBuilder;

abstract class InsertBuilder extends BuilderFather
{
    
    /**
     * 要插入数据的表
     *
     * @access public
     * @param string $table 要插入的表
     * @param array $data 数据
     * @return InsertBuilder
     */
    function into($table, array $data)
    {
        $this->_parts['table'] = $table;
        $this->_parts['data'] = $data;
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
        $data = $this->_parts['data'];
        $result = '';
        if ($table && $data) {
            $result.= 'INSERT INTO '. $table;
            $result.= '('. implode(', ', array_keys($data)). ')';
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
        $data = $this->_parts['data'];
        $result = 'VALUES';
        foreach ($data as $k=> $v) {
            if (preg_match('/^\{\{.*?\}\}$/', $v)) {
                $v = str_replace(array('{{', '}}'), '', $v);
                $data[$k] = $v;
            } else {
                $this->_db_bind[':'. $k] = $v;
                $data[$k] = ':'. $k;
            }
        }
        $result.= '('. implode(', ', $data). ')';
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
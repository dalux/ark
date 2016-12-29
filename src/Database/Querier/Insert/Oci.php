<?php

namespace Ark\Database\Querier\Insert;

use Ark\Database\Toolkit;
use Ark\Database\Querier\Insert;
use Ark\Database\Querier\Select;

class Oci extends Insert
{

    /**
     * 数据库类型
     *
     * @var string
     */
    protected $_db_type = 'oci';

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
                    $part[] = 'SELECT '. implode(', ', $val). ' FROM DUAL';
                } elseif ($val instanceof Select) {
                    $part[] = $val->getSQL();
                }
            }
            $result.= implode(' UNION ALL ', $part);
        }
        return $result;
    }

}
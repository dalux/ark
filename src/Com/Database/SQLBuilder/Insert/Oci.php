<?php

namespace Ark\Com\Database\SQLBuilder\Insert;

use Ark\Com\Database\SQLBuilder\Expr;
use Ark\Com\Database\SQLBuilder\Insert;
use Ark\Com\Database\SQLBuilder\Select;
use Ark\Com\Database\SQLBuilder\Toolkit;

class Oci extends Insert
{

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
                    if (is_object($v) && $v instanceof Expr) {
                        $val[$k] = $v;
                    } else {
                        $val[$k] = Toolkit::quote($v);
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
                        if (is_object($v) && $v instanceof Expr) {
                            $val[$k] = $v;
                        } else {
                            $val[$k] = Toolkit::quote($v);
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
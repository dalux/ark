<?php declare(strict_types=1);

namespace Brisk\Toolkit;

class Verifier
{

    /**
     * 数据校验器
     *
     * @param array $data
     * @param array $rule
     */
    public static function check(array $data, array $rule)
    {
        foreach ($rule as $field=> $item) {
            $value = $data[$field];
            foreach ($item as $k=> $v) {
                //必填项校验
                if ($k == 'required' && $v) {
                    if (is_string($v)) {
                        $special = [];
                        foreach ($rule as $_k=> $_v) {
                            if ($_v['required'] === $v) {
                                $special[$_k] = $_v;
                            }
                        }
                        $pass = false;
                        foreach ($special as $_k=> $_v) {
                            $_value = $data[$_k];
                            if ($_value || is_integer($_value)) {
                                $pass = true;
                            }
                        }
                        if (!$pass) {
                            $msg = Language::format('tool.validator_field_missing', $field);
                            throw new RuntimeException($msg);
                        }
                    } elseif (is_null($value)
                            || is_string($value) && trim($value) == ''
                            || is_array($value) && count($value) == 0) {
                        $msg = Language::format('tool.validator_field_missing', $field);
                        throw new RuntimeException($msg);
                    }
                }
                //以下校验在值不为空时进行
                if (!is_null($value)) {
                    //类型校验
                    if ($k == 'type') {
                        $type = strtolower(gettype($value));
                        $v = strtolower($v);
                        $number = ['double', 'float', 'real', 'integer', 'int'];
                        if (in_array($type, $number)
                                || $type == 'string' && $v == 'number' && is_numeric($value)) {
                            $type = 'number';
                        } elseif ($type == 'resource') {
                            $type = 'object';
                        }
                        if ($v != $type) {
                            $msg = Language::format('tool.validator_field_errtype', $field, $v, $type);
                            throw new RuntimeException($msg);
                        }
                    }
                    //范围校验
                    if ($k == 'range' && is_array($v)) {
                        if (!in_array($value, $v)) {
                            $msg = Language::format('tool.validator_field_outrange', $field);
                            throw new RuntimeException($msg);
                        }
                    }
                    //最小值校验
                    if ($k == 'min_value' && $value < $v) {
                        $msg = Language::format('tool.validator_filed_lessthan', $field, $v);
                        throw new RuntimeException($msg);
                    }
                    //最大值校验
                    if ($k == 'max_value' && $value > $v) {
                        $msg = Language::format('tool.validator_filed_morethan', $field, $v);
                        throw new RuntimeException($msg);
                    }
                    //最小长度校验
                    if ($k == 'min_length' && is_string($value) && strlen($value) < $v) {
                        $msg = Language::format('tool.validator_filed_minlength', $field, $v, strlen($value));
                        throw new RuntimeException($msg);
                    }
                    //最大长度校验
                    if ($k == 'max_length' && is_string($value) && strlen($value) > $v) {
                        $msg = Language::format('tool.validator_filed_maxlength', $field, $v, strlen($value));
                        throw new RuntimeException($msg);
                    }
                    //是否相等校验
                    if ($k == 'equal') {
                        if (is_string($value) && $value != $v) {
                            $msg = Language::format('tool.validator_filed_noequal', $field, $v, $value);
                            throw new RuntimeException($msg);
                        } elseif (is_object($value) && !$value instanceof $v) {
                            $msg = Language::format('tool.validator_filed_errobject', $field, get_class($v));
                            throw new RuntimeException($msg);
                        }
                    }
                    //是否匹配规则
                    if ($k == 'match' && !preg_match($v, $value)) {
                        $msg = Language::format('tool.validator_filed_nomatch', $field, $v);
                        throw new RuntimeException($msg);
                    }
                }
            }
        }
    }

}
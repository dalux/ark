<?php

namespace Ark\Toolkit;

use Ark\Core\Loader;
use Ark\Core\Captain;

class Struct
{

    const FLAG_REQUIRED             = 'required';
    const FLAG_TYPE                 = 'type';
    const FLAG_RANGE                = 'range';
    const FLAG_MIN_LENGTH           = 'min_length';
    const FLAG_MAX_LENGTH           = 'max_length';
    const FLAG_MIN_VALUE            = 'min_value';
    const FLAG_MAX_VALUE            = 'max_value';
    const FLAG_EQUAL                = 'equal';
    const FLAG_MATCH                = 'match';
    const FLAG_DEFAULT              = 'default';
    const FLAG_SPECIAL_REQUIRED     = 'special_required';

    const TYPE_NUMBER               = 'number';
    const TYPE_STRING               = 'string';
    const TYPE_ARRAY                = 'array';
    const TYPE_OBJECT               = 'object';

    /**
     * 要校验的数据
     *
     * @var array
     */
    private $_data = array();

    /**
     * 数据校验规则
     *
     * @var array|mixed
     */
    private $_rule = array();

    /**
     * 校验结果消息
     *
     * @var string
     */
    private $_message = '';

    /**
     * 校验时使用的文本编码
     *
     * @var string
     */
    private $_encode = 'utf-8';

    /**
     * 设置校验规则文件
     *
     * @param $path
     * @throws Exception
     */
    function setRuleFile($path)
    {
        if (!$this->_rule = Loader::import($path, false)) {
            throw new Exception(Captain::getInstance()->lang->get('struct.load_rulefile_failed', $path));
        } elseif (!is_array($this->_rule)) {
            throw new Exception(Captain::getInstance()->lang->get('struct.return_type_error', $path));
        }
    }

    /**
     * 设置校验规则
     *
     * @param array $rule
     * @return $this
     */
    function setRule(array $rule)
    {
        $this->_rule = $rule;
        return $this;
    }

    /**
     * 设置要校验的数据
     *
     * @param array $data
     * @return $this
     */
    function setData(array $data)
    {    
        $this->_data = $data;
        return $this;
    }

    /**
     * 设置字符编码
     *
     * @param $encode
     * @return Struct
     */
    function setEncode($encode)
    {
        $this->_encode = $encode;
        return $this;
    }

    /**
     * 数据校验结果, 成功则返回数组, 失败返回false
     *
     * @return mixed
     * @throws Exception
     */
    function checkOut()
    {
        $valid = true;
        $this->_message = '';
        $language = Captain::getInstance()->lang;
        foreach ($this->_rule as $key=> $val) {
            foreach ($val as $k=> $v) {
                if ($k == self::FLAG_REQUIRED && $v) {
                    $have = true;
                    if (is_null($this->_data[$key])) {
                        $have = false;
                    } elseif (is_string($this->_data[$key]) && trim($this->_data[$key]) == '') {
                        $have = false;
                    } elseif (is_array($this->_data[$key]) && count($this->_data[$key]) == 0) {
                        $have = false;
                    }
                    if (!$have && !array_key_exists(self::FLAG_DEFAULT, $this->_rule[$key])) {
                        $this->_message = $language->get('struct.field_is_required', $key);
                        $valid = false;
                        break 2;
                    }
                } elseif ($k == self::FLAG_SPECIAL_REQUIRED) {
                    $keys = array_map('trim', explode(',', $this->_data[$key]));
                    $have = false;
                    foreach ($keys as $item) {
                        if (!is_null($this->_data[$item])) {
                            $have = true;
                        }
                    }
                    if (!$have) {
                        $keys[] = $key;
                        $this->_message = $language->get('struct.field_more_than', implode(',', $keys));
                        $valid = false;
                        break 2;
                    }
                } elseif ($k == self::FLAG_TYPE) {
                    if (!is_null($this->_data[$key])) {
                        $v = strtolower($v);
                        $type = strtolower(gettype($this->_data[$key]));
                        if (in_array($type, array('double', 'float', 'real', 'integer', 'int'))) {
                            $type = self::TYPE_NUMBER;
                        }
                        if ($v != $type) {
                            $this->_message = $language->get('struct.field_type_nomatch', $key, $v, $type);
                            $valid = false;
                            break 2;
                        }
                    }
                } elseif ($k == self::FLAG_RANGE && is_array($v)) {
                    if (!is_null($this->_data[$key])
                            && !in_array($this->_data[$key], $v)) {
                        $this->_message = $language->get('struct.field_outof_range', $key);
                        $valid = false;
                        break 2;
                    }
                } elseif ($k == self::FLAG_MIN_VALUE) {
                    if (!is_null($this->_data[$key])
                            && $this->_data[$key] < $v) {
                        $this->_message = $language->get('struct.value_greater_than', $key, $v);
                        $valid = false;
                        break 2;
                    }
                } elseif ($k == self::FLAG_MAX_VALUE) {
                    if (!is_null($this->_data[$key])
                            && $this->_data[$key] > $v) {
                        $this->_message = $language->get('struct.value_less_than', $key, $v);
                        $valid = false;
                        break 2;
                    }
                } elseif ($k == self::FLAG_MIN_LENGTH) {
                    if (!is_null($this->_data[$key])
                            && is_string($this->_data[$key])
                            && mb_strlen($this->_data[$key], $this->_encode) < $v) {
                        $this->_message = $language->get('struct.length_greater_than', $key, $v, mb_strlen($this->_data[$key], 'utf-8'));
                        $valid = false;
                        break 2;
                    }
                } elseif ($k == self::FLAG_MAX_LENGTH) {
                    if (!is_null($this->_data[$key])
                            && is_string($this->_data[$key])
                            && mb_strlen($this->_data[$key], $this->_encode) > $v) {
                        $this->_message = $language->get('struct.length_less_than', $key, $v, mb_strlen($this->_data[$key], 'utf-8'));
                        $valid = false;
                        break 2;
                    }
                } elseif ($k == self::FLAG_EQUAL) {
                    if (!is_null($this->_data[$key])
                            && is_string($this->_data[$key])
                            && $this->_data[$key] != $v) {
                        $this->_message = $language->get('struct.content_not_equal', $key, $v, $this->_data[$key]);
                        $valid = false;
                        break 2;
                    } elseif (!is_null($this->_data[$key])
                            && is_object($this->_data[$key])
                            && !$this->_data[$key] instanceof $v) {
                        $this->_message = $language->get('struct.object_not_instanceof', $key, get_class($v));
                        $valid = false;
                        break 2;
                    }
                } elseif ($k == self::FLAG_MATCH) {
                    if (!is_null($this->_data[$key])
                            && !preg_match($v, $this->_data[$key])) {
                        $this->_message = $language->get('struct.regexp_not_match', $key, $v);
                        $valid = false;
                        break 2;
                    }
                } elseif ($k == self::FLAG_DEFAULT) {
                    if (array_key_exists($key, $this->_data) && $this->_data[$key] == '') {
                        $this->_data[$key] = $v;
                    }
                }
            }
        }
        return $valid ? $this->_data : false;
    }

    /**
     * 校验失败后获取错误提示
     *
     * @access public
     * @return string
     */
    function getMessage()
    {
        return $this->_message;
    }

}
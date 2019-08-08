<?php declare(strict_types=1);

namespace Brisk\Toolkit\SqlBuilder\Insert;

use Brisk\Toolkit\SqlBuilder\Insert;

class Oci extends Insert
{

    /**
     * 数据库类型
     *
     * @var string
     */
    protected $_db_type = 'Oci';

    /**
     * 为数据添加引号
     *
     * @access public
     * @param mixed value
     * @return string
     */
    public function quote($value)
    {
        if (is_array($value)) {
            foreach ($value as $key=> $val) {
                $value[$key] = $this->quote($val);
            }
            return implode(',', $value);
        } elseif (is_int($value) || is_float($value)) {
            return $value;
        } elseif (preg_match('/\{\{.*?\}\}/', $value)) {
            return str_replace(['{{', '}}'], '', $value);
        } else {
            return '\'' . str_replace('\'', '\'\'', $value) . '\'';
        }
    }
    
}
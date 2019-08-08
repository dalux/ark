<?php declare(strict_types=1);

namespace Brisk\Toolkit\SqlBuilder\Delete;

use Brisk\Toolkit\SqlBuilder\Delete;

class Oci extends Delete
{

    /**
     * 数据库类型
     *
     * @var string
     */
	protected $_db_type = 'oci';

    /**
     * 为数据添加引号
     *
     * @access public
     * @param mixed $value
     * @return string
     */
	public function quote($value)
	{
        if (is_array($value)) {
            foreach ($value as $key=> $val) {
                $value[$key] = $this->quote($val);
            }
            return implode(',', $value);
        } elseif (is_int($value) || is_float($value) || preg_match('/.*?\(.*?\)$/', $value)) {
            return $value;
        } else {
            return '\'' . str_replace('\'', '\'\'', $value) . '\'';
        }
	}
	
}
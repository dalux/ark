<?php declare(strict_types=1);

namespace Brisk\Sql\Insert;

use Brisk\Sql\Insert;

class Oci extends Insert
{

    /**
     * @var string
     */
    protected $_db_type = 'Oci';

    /**
     * Put quotation marks on a field
     *
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
        }
        return '\'' . str_replace('\'', '\'\'', $value) . '\'';
    }
    
}
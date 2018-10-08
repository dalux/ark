<?php

namespace Brisk\Sql\Select;


class Oci extends \Brisk\Sql\Select
{

    protected $_db_type = 'Oci';


    /**
     * Put quotation marks on a field
     *
     * @param mixed $value
     * @return string
     */
    public function quote($value) {}


    public function pickLimitPart() {}

    /**
     * Compile the select statment
     *
     * @return Select
     */
    public function compile() {}

}

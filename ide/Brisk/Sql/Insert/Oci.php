<?php

namespace Brisk\Sql\Insert;


class Oci extends \Brisk\Sql\Insert
{

    protected $_db_type = 'Oci';


    /**
     * Put quotation marks on a field
     *
     * @param mixed $value
     * @return string
     */
    public function quote($value) {}

}

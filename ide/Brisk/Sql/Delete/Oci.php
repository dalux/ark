<?php

namespace Brisk\Sql\Delete;


class Oci extends \Brisk\Sql\Delete
{

    protected $_db_type = 'oci';


    /**
     * Put quotation marks on a field
     *
     * @param mixed $value
     * @return string
     */
    public function quote($value) {}

}

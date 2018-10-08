<?php

namespace Brisk\Sql\Update;


class Oci extends \Brisk\Sql\Update
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

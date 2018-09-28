<?php

namespace Brisk\Vendor\Querier\Select;


class Oci extends \Brisk\Vendor\Querier\Select
{

    protected $_db_type = 'oci';



    public function pickLimitPart() {}

    /**
     * Get the full sql statement
     *
     * @return string
     */
    public function getSQL() {}

}

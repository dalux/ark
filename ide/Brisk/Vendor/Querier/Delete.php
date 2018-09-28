<?php

namespace Brisk\Vendor\Querier;


abstract class Delete extends \Brisk\Vendor\Querier\QuerierFather
{

    /**
     * Setting the from field in the sql statement
     *
     * @param mixed $table
     * @return Delete
     */
    public function from($table) {}

    /**
     * Get the full sql statement
     *
     * @return string
     */
    public function getSQL() {}

}

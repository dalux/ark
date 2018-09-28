<?php

namespace Brisk\Vendor\Querier;


abstract class Update extends \Brisk\Vendor\Querier\QuerierFather
{

    /**
     * Setting the set field in the sql statement
     *
     * @param mixed $table
     * @param array $updates
     * @return Update
     */
    public function set($table, array $updates = array()) {}

    /**
     * Get the full sql statement
     *
     * @return string
     */
    public function getSQL() {}

}

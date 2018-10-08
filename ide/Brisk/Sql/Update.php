<?php

namespace Brisk\Sql;


abstract class Update extends \Brisk\Sql\SqlFather
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
     * Compile the update statment
     *
     * @return Update
     */
    public function compile() {}

}

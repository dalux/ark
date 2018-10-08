<?php

namespace Brisk\Sql;


abstract class Delete extends \Brisk\Sql\SqlFather
{

    /**
     * Setting the from field in the sql statement
     *
     * @param mixed $table
     * @return Delete
     */
    public function from($table) {}

    /**
     * Compile the delete statment
     *
     * @return Delete
     */
    public function compile() {}

}

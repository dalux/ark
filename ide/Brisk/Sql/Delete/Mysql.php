<?php

namespace Brisk\Sql\Delete;


class Mysql extends \Brisk\Sql\Delete
{

    protected $_db_type = 'mysql';


    /**
     * Compile the delete statment
     *
     * @return Delete
     */
    public function compile() {}

}

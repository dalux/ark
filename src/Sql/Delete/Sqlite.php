<?php declare(strict_types=1);

namespace Brisk\Sql\Delete;

use Brisk\Sql\Delete;

class Sqlite extends Delete
{

    /**
     * @var string
     */
    protected $_db_type = 'sqlite';
    
}
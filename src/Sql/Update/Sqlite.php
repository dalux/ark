<?php declare(strict_types=1);

namespace Brisk\Sql\Update;

use Brisk\Sql\Update;

class Sqlite extends Update
{

    /**
     * @var string
     */
    protected $_db_type = 'sqlite';
    
}
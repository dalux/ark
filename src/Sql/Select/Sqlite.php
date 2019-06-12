<?php declare(strict_types=1);

namespace Brisk\Sql\Select;

use Brisk\Sql\Select;

class Sqlite extends Select
{

    /**
     * @var string
     */
    protected $_db_type = 'sqlite';
    
}
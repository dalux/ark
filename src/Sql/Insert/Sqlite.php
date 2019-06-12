<?php declare(strict_types=1);

namespace Brisk\Sql\Insert;

use Brisk\Sql\Insert;

class Sqlite extends Insert
{

    /**
     * @var string
     */
    protected $_db_type = 'sqlite';
    
}
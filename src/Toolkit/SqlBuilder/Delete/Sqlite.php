<?php declare(strict_types=1);

namespace Brisk\Toolkit\SqlBuilder\Delete;

use Brisk\Toolkit\SqlBuilder\Delete;

class Sqlite extends Delete
{

    /**
     * @var string
     */
    protected $_db_type = 'sqlite';
    
}
<?php declare(strict_types=1);

namespace Brisk\Toolkit\SqlBuilder\Delete;

use Brisk\Toolkit\SqlBuilder\Delete;

class Pgsql extends Delete
{

    /**
     * @var string
     */
    protected $_db_type = 'pgsql';
    
}
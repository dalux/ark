<?php declare(strict_types=1);

namespace Brisk\Toolkit\SqlBuilder\Select;

use Brisk\Toolkit\SqlBuilder\Select;

class Sqlite extends Select
{

    /**
     * @var string
     */
    protected $_db_type = 'sqlite';
    
}
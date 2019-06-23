<?php declare(strict_types=1);

namespace Brisk\Toolkit\SqlBuilder\Insert;

use Brisk\Toolkit\SqlBuilder\Insert;

class Sqlite extends Insert
{

    /**
     * @var string
     */
    protected $_db_type = 'sqlite';
    
}
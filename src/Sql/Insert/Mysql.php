<?php declare(strict_types=1);

namespace Brisk\Sql\Insert;

use Brisk\Sql\Insert;

class Mysql extends Insert
{

    /**
     * @var string
     */
	protected $_db_type = 'mysql';
    
}
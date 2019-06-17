<?php declare(strict_types=1);

use Brisk\Toolkit\SqlBuilder\Select;

class Pgsql extends Select
{

    /**
     * @var string
     */
    protected $_db_type = 'pgsql';

}
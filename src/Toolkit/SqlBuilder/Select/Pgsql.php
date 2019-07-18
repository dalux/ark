<?php declare(strict_types=1);

use Brisk\Toolkit\SqlBuilder\Select;

class Pgsql extends Select
{

    /**
     * 数据库类型
     * 
     * @var string
     */
    protected $_db_type = 'pgsql';

}
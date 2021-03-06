<?php declare(strict_types=1);

namespace Brisk\Toolkit\SqlBuilder\Delete;

use Brisk\Toolkit\SqlBuilder\Delete;

class Sqlsrv extends Delete
{

    /**
     * 数据库类型
     *
     * @var string
     */
    protected $_db_type = 'sqlsrv';
    
}
<?php declare(strict_types=1);

namespace Brisk\Toolkit\SqlBuilder\Select;

use Brisk\Toolkit\SqlBuilder\Select;

class Sqlsrv extends Select
{

    /**
     * 数据库类型
     * 
     * @var string
     */
    protected $_db_type = 'sqlsrv';

}
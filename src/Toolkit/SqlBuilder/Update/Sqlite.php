<?php declare(strict_types=1);

namespace Brisk\Toolkit\SqlBuilder\Update;

use Brisk\Toolkit\SqlBuilder\Update;

class Sqlite extends Update
{

    /**
     * 数据库类型
     * 
     * @var string
     */
    protected $_db_type = 'sqlite';
    
}
<?php declare(strict_types=1);

namespace Brisk\Toolkit\SqlBuilder\Insert;

use Brisk\Toolkit\SqlBuilder\Insert;

class Sqlsrv extends Insert
{

    /**
     * 数据库类型
     *
     * @var string
     */
	protected $_db_type = 'sqlsrv';
	
}
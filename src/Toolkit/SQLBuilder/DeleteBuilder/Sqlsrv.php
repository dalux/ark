<?php

namespace Ark\Sql\Builder\DeleteBuilder;

use Ark\Toolkit\SQLBuilder\DeleteBuilder;

class Sqlsrv extends DeleteBuilder
{

    /**
     * 数据库类型
     *
     * @var string
     */
    protected $_db_type = 'sqlsrv';

}
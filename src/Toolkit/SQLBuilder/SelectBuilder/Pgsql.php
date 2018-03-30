<?php

namespace Brisk\Toolkit\SQLBuilder\SelectBuilder;

use Brisk\Toolkit\SQLBuilder\SelectBuilder;

class Pgsql extends SelectBuilder
{

    /**
     * 数据库类型
     *
     * @var string
     */
    protected $_db_type = 'pgsql';

}
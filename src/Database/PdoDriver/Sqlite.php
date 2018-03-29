<?php

namespace Ark\Database\PdoDriver;

use Ark\Database\PdoDriver;
use Ark\Exception\DatabaseException;
use Ark\Exception\EventException;

class Sqlite extends PdoDriver
{

    /**
     * 构造器
     *
     * @param null $dsn
     * @param array $option
     * @throws DatabaseException
     * @throws EventException
     */
    function __construct($dsn, array $option = array())
    {
        $params = array(
            \PDO::ATTR_ERRMODE              => \PDO::ERRMODE_EXCEPTION,
            \PDO::ATTR_ORACLE_NULLS         => \PDO::NULL_EMPTY_STRING,
            \PDO::ATTR_EMULATE_PREPARES     => false,
        );
        if ($option) {
            $params = array_merge($params, $option);
        }
        parent::__construct($dsn, null, null, $params);
    }

}
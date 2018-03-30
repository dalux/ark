<?php

namespace Brisk\Database\PdoDriver;

use Brisk\Database\PdoDriver;
use Brisk\Exception\DatabaseException;
use Brisk\Exception\EventException;

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
<?php

namespace Ark\Database\PdoDriver;

use Ark\Database\PdoDriver;
use Ark\Database\Toolkit;
use Ark\Exception\DatabaseException;
use Ark\Exception\EventException;

class Pgsql extends PdoDriver
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
        $database = Toolkit::parseConnectUrl($dsn);
        $conn_str = sprintf('%s:host=%s;port=%s;dbname=%s;', $database['type'], $database['host'], $database['port'], $database['name']);
        if ($charset = $database['charset']) {
            $conn_str.= sprintf('charset=%s', $charset);
        }
        $params = array(
            \PDO::ATTR_ERRMODE              => \PDO::ERRMODE_EXCEPTION,
            \PDO::ATTR_ORACLE_NULLS         => \PDO::NULL_EMPTY_STRING,
            \PDO::ATTR_EMULATE_PREPARES     => false,
        );
        if ($option) {
            $params = array_merge($params, $option);
        }
        parent::__construct($conn_str, $database['user'], $database['pass'], $params);
    }

}
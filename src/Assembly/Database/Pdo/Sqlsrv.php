<?php

namespace Ark\Assembly\Database\Pdo;

use Ark\Assembly\Database;
use Ark\Assembly\Database\Pdo;

class Sqlsrv extends Pdo
{

    /**
     * 构造器
     *
     * @param null $dsn
     * @param array $option
     * @throws Database\Exception
     * @throws \Ark\Core\Exception
     */
    function __construct($dsn, array $option = array())
    {
        $database = Database::parseConnectUrl($dsn);
        $conn_str = sprintf('%s:Server=%s,%s;Database=%s;', $database['type'], $database['host'], $database['port'], $database['name']);
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
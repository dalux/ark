<?php

namespace Ark\Com\Database\Pdo;

use Ark\Com\Database\Pdo;

class Sqlite extends Pdo
{

    /**
     * 构造器
     *
     * @param null $dsn
     * @param array $option
     */
    function __construct($dsn, array $option = array())
    {
        $params = array(
            \PDO::ATTR_ERRMODE       => \PDO::ERRMODE_EXCEPTION,
            \PDO::ATTR_ORACLE_NULLS  => \PDO::NULL_EMPTY_STRING,
        );
        if ($option) {
            $params = array_merge($params, $option);
        }
        parent::__construct($dsn, null, null, $params);
    }

}
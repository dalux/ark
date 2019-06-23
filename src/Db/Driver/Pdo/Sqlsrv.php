<?php

namespace Brisk\Db\Driver\Pdo;

use Brisk\Db\Driver\PdoFather;

class Sqlsrv extends PdoFather
{

    public function __construct(array $config, array $setting = [])
    {
        $dsn = sprintf('sqlsrv:Server=%s,%s;Database=%s;', $config['host'], $config['port'], $config['dbname']);
        if ($charset = $config['charset']) {
            $dsn = $dsn. sprintf('charset=%s', $charset);
        }
        $params = [
            \PDO::ATTR_ERRMODE              => \PDO::ERRMODE_EXCEPTION,
            \PDO::ATTR_ORACLE_NULLS         => \PDO::NULL_EMPTY_STRING,
            \PDO::ATTR_EMULATE_PREPARES     => false
        ];
        if (count($setting)>0) {
            $params = array_merge($params, $setting);
        }
        parent::__construct($dsn, $config['username'], $config['password'], $params);
    }

}
<?php declare(strict_types=1);

namespace Brisk\Db\Driver\Pdo;

use Brisk\Db\Driver\PdoFather;

class Sqlite extends PdoFather
{

    public function __construct(array $config, array $setting = [])
    {
        $dsn = sprintf('sqlite:%s', $config['dbname']);
        $params = [
            \PDO::ATTR_ERRMODE              => \PDO::ERRMODE_EXCEPTION,
            \PDO::ATTR_ORACLE_NULLS         => \PDO::NULL_EMPTY_STRING,
            \PDO::ATTR_EMULATE_PREPARES     => false
        ];
        if (count($setting)>0) {
            $params = array_merge($params, $setting);
        }
        parent::__construct($dsn, null, null, $params);
    }

}
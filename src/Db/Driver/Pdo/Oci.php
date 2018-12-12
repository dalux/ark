<?php

namespace Brisk\Db\Driver\Pdo;

use Brisk\Db\Driver\PdoFather;

class Oci extends PdoFather
{

    public function __construct(array $config, array $setting = [])
    {
        $dsn = $config['host'];
        if ($config['host'] && $config['dbname']) {
            $port = $config['port'];
            if ($port) {
				$port = 1521;
            }
            $dsn = '//'. $config['host']. ':'. $port. '/'. $config['dbname'];
        }
        $dsn = sprintf('oci:dbname=%s;', $dsn);
		$charset = $config['charset'];
        if ($charset) {
            $dsn = $dsn. sprintf('charset=%s', $charset);
        }
        $params = [
            \PDO::ATTR_ERRMODE              => \PDO::ERRMODE_EXCEPTION,
            \PDO::ATTR_ORACLE_NULLS         => \PDO::NULL_EMPTY_STRING,
            \PDO::ATTR_CASE                 => \PDO::CASE_LOWER,
            \PDO::ATTR_EMULATE_PREPARES     => false
        ];
        if (count($setting)>0) {
            $params = array_merge($params, $setting);
        }
        parent::__construct($dsn, $config['username'], $config['password'], $params);
    }


    /**
     * Get next id
     *
     * @param string|null $seq
     * @return int
     */
    public function nextInsertId($seq = null)
    {
        return parent::fetchOne("select $seq.nextval from dual");
    }

}
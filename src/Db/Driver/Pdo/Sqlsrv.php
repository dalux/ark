<?php declare(strict_types=1);

namespace Brisk\Db\Driver\Pdo;

use Brisk\Db\Driver\PdoFather;
use Brisk\Exception\RuntimeException;
use Brisk\Kernel\Language;

class Sqlsrv extends PdoFather
{

    /**
     * 构造函数
     *
     * @access public
     * @param array $config
     * @param array $setting
     * @return void
     */
    public function __construct(array $config, array $setting = [])
    {
        $username   = $config['username']   ?? '';
        $password   = $config['password']   ?? '';
        $host       = $config['host']       ?? '';
        $port       = $config['port']       ?? 1433;
        $dbname     = $config['dbname']     ?? '';
        $charset    = $config['charset']    ?? '';
        if (!$host || !$username) {
            throw new RuntimeException(Language::format('db.invalid_connect_config', 'host,username'));
        }
        $dsn = sprintf('sqlsrv:Server=%s,%s;Database=%s;', $host, $port, $dbname);
        if ($charset) {
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
        parent::__construct($dsn, $username, $password, $params);
    }

}
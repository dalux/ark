<?php declare(strict_types=1);

namespace Brisk\Db\Driver\Pdo;

use Brisk\Db\Driver\PdoFather;

class Pgsql extends PdoFather
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
        $dsn = sprintf('pgsql:host=%s;port=%s;dbname=%s;', $config['host'], $config['port'], $config['dbname']);
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
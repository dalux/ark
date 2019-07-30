<?php declare(strict_types=1);

namespace Brisk\Db\Driver\Pdo;

use Brisk\Db\Driver\PdoFather;
use Brisk\Exception\RuntimeException;
use Brisk\Kernel\Language;

class Oci extends PdoFather
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
        $port       = $config['port']       ?? 1521;
        $dbname     = $config['dbname']     ?? '';
        $charset    = $config['charset']    ?? '';
        if (!$host || !$username) {
            throw new RuntimeException(Language::format('db.invalid_connect_config', 'host,username'));
        }
        $dsn = $dbname ? '//'. $host. ':'. $port. '/'. $dbname : $host;
        $dsn = sprintf('oci:dbname=%s;', $dsn);
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
        parent::__construct($dsn, $username, $password, $params);
    }


    /**
     * 获取下一条数据序列ID
     *
     * @access public
     * @param string $seq
     * @return int
     */
    public function nextInsertId($seq)
    {
        return parent::fetchScalar("select $seq.nextval from dual");
    }

}
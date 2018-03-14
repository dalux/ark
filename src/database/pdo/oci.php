<?php

class Ark_Database_Pdo_Oci extends Ark_Database_Pdo
{

    /**
     * 构造器
     *
     * @param null $dsn
     * @param array $option
     * @throws Ark_Database_Exception
     * @throws Exception
     */
    function __construct($dsn, array $option = array())
    {
        $database = Ark_Database_Toolkit::parseConnectUrl($dsn);
        $conn_str = $database['host'];
        if ($database['host'] && $database['name']) {
            $database['port'] || $database['port'] = 1521;
            $conn_str = '//'. $database['host']. ':'. $database['port']. '/'. $database['name'];
        }
        $conn_str = sprintf("%s:dbname=%s;", $database['type'], $conn_str);
        if ($charset = $database['charset']) {
            $conn_str.= sprintf('charset=%s', $charset);
        }
        $params = array(
            PDO::ATTR_ERRMODE              => PDO::ERRMODE_EXCEPTION,
            PDO::ATTR_ORACLE_NULLS         => PDO::NULL_EMPTY_STRING,
            PDO::ATTR_CASE                 => PDO::CASE_LOWER,
            PDO::ATTR_EMULATE_PREPARES     => false,
        );
        if ($option) {
            $params = array_merge($params, $option);
        }
        parent::__construct($conn_str, $database['user'], $database['pass'], $params);
    }

}
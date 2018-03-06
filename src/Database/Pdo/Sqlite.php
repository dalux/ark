<?php

class Ark_Database_Pdo_Sqlite extends Ark_Database_Pdo
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
        $params = array(
            PDO::ATTR_ERRMODE              => PDO::ERRMODE_EXCEPTION,
            PDO::ATTR_ORACLE_NULLS         => PDO::NULL_EMPTY_STRING,
            PDO::ATTR_EMULATE_PREPARES     => false,
        );
        if ($option) {
            $params = array_merge($params, $option);
        }
        parent::__construct($dsn, null, null, $params);
    }

}
<?php

namespace Brisk\Db;


abstract class DbFather
{

    /**
     * Execute a sql with bind options
     *
     * @param string $sql
     * @param array $bind
     * @return mixed
     */
    public abstract function query($sql, array $bind = array());

    /**
     * Execute fetchAll method with bind options
     *
     * @param string $sql
     * @param array $bind
     * @return array
     */
    public abstract function fetchAll($sql, array $bind = array());

    /**
     * Execute fetchRow method with bind options
     *
     * @param string $sql
     * @param array $bind
     * @return mixed
     */
    public abstract function fetchRow($sql, array $bind = array());

    /**
     * Execute fetchOne method with bind options
     *
     * @param string $sql
     * @param array $bind
     * @return mixed
     */
    public abstract function fetchOne($sql, array $bind = array());

    /**
     * Start a new Transaction
     *
     * @return bool
     */
    public abstract function beginTransaction();

    /**
     * Commit a Transaction
     *
     * @return bool
     */
    public abstract function commit();

    /**
     * Rollback a Transaction
     *
     * @return bool
     */
    public abstract function rollback();

    /**
     * Check if the current sql is in a transaction
     *
     * @return bool
     */
    public abstract function inTransaction();

    /**
     * Get last insert id
     *
     * @param string $seq
     * @return int
     */
    public abstract function lastInsertId($seq = '');

    /**
     * Gets the number of rows as a result of the last sql execution
     *
     * @return int
     */
    public abstract function lastRowCount();

    /**
     * Get current driver name
     *
     * @return string
     */
    public abstract function getDriverName();

    /**
     * Get pdo instance
     *
     * @return \PDO
     */
    public abstract function getInstance();

}

<?php declare(strict_types=1);

namespace Brisk\Db;

interface IDbDriver
{

    /**
     * Execute a sql with bind options
     *
     * @param string sql
     * @param array bind
     * @return bool
     */
    public function query(string $sql, array $bind = []);

    /**
     * Execute fetchAll method with bind options
     *
     * @param string sql
     * @param array bind
     * @return array
     */
    public function fetchAll(string $sql, array $bind = []);

    /**
     * Execute fetchRow method with bind options
     *
     * @param string sql
     * @param array bind
     * @return array
     */
    public function fetchOne(string $sql, array $bind = []);

    /**
     * Execute fetchOne method with bind options
     *
     * @param string sql
     * @param array bind
     * @return mixed
     */
    public function fetchScalar(string $sql, array $bind = []);

    /**
     * Start a new Transaction
     *
     * @return bool
     */
    public function beginTransaction();

    /**
     * Commit a Transaction
     *
     * @return bool
     */
    public function commit();

    /**
     * Rollback a Transaction
     *
     * @return bool
     */
    public function rollback();

    /**
     * Check if the current sql is in a transaction
     *
     * @return bool
     */
    public function inTransaction();

    /**
     * Get last insert id
     *
     * @param string seq
     * @return int
     */
    public function lastInsertId(string $seq = null);

    /**
     * Gets the number of rows as a result of the last sql execution
     *
     * @return int
     */
    public function lastRowCount();

    /**
     * Get current driver name
     *
     * @return string
     */
    public function getDriverName();

    /**
     * 获取数据连接资源实例
     * 
     * @return resource
     */
    public function getInstance();

}
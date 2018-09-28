<?php

namespace Brisk\Vendor\Db;


class Pdo extends \Brisk\Vendor\Db\DbFather
{

    private $_instance;


    private $_fetch_mode = \PDO::FETCH_ASSOC;


    private $_row_count = 0;


    /**
     * Construct
     *
     * @param string $dsn
     * @param array $option
     * @return null
     */
    public function __construct($dsn, array $option = array()) {}

    /**
     * Execute a sql with bind options
     *
     * @param string $sql
     * @param array $bind
     * @return mixed
     */
    public function query($sql, array $bind = array()) {}

    /**
     * Execute fetchAll method with bind options
     *
     * @param string $sql
     * @param array $bind
     * @return array
     */
    public function fetchAll($sql, array $bind = array()) {}

    /**
     * Execute fetchOne method with bind options
     *
     * @param string $sql
     * @param array $bind
     * @return mixed
     */
    public function fetchOne($sql, array $bind = array()) {}

    /**
     * Execute fetchRow method with bind options
     *
     * @param string $sql
     * @param array $bind
     * @return array
     */
    public function fetchRow($sql, array $bind = array()) {}

    /**
     * Start a new Transaction
     *
     * @return bool
     */
    public function beginTransaction() {}

    /**
     * Commit a Transaction
     *
     * @return bool
     */
    public function commit() {}

    /**
     * Rollback a Transaction
     *
     * @return bool
     */
    public function rollback() {}

    /**
     * Check if the current sql is in a transaction
     *
     * @return bool
     */
    public function inTransaction() {}

    /**
     * Get next id
     *
     * @return int
     */
    public function nextInsertId() {}

    /**
     * Get last insert id
     *
     * @param string $seq
     * @return int
     */
    public function lastInsertId($seq = '') {}

    /**
     * Gets the number of rows as a result of the last sql execution
     *
     * @return int
     */
    public function lastRowCount() {}

    /**
     * Set Pdo fetch mode
     *
     * @param int $mode
     * @return Pdo
     */
    public function setFetchMode($mode) {}

    /**
     * Get current driver name
     *
     * @return string
     */
    public function getDriverName() {}

    /**
     * Get pdo instance
     *
     * @return \PDO
     */
    public function getInstance() {}

    /**
     * @param string $sql
     * @param array $bind
     */
    private function _query($sql, array $bind = array()) {}

    /**
     * @param string $dsn
     * @param array $option
     */
    private function _getConnection($dsn, array $option = array()) {}

}

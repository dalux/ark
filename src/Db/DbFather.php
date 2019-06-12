<?php declare(strict_types=1);

namespace Brisk\Db;

use Brisk\Sql\Delete;
use Brisk\Sql\Insert;
use Brisk\Sql\Select;
use Brisk\Sql\Update;

abstract class DbFather implements IDbDriver
{

    /**
     * Execute a sql with bind options
     *
     * @param string sql
     * @param array bind
     * @return bool
     */
    public abstract function query(string $sql, array $bind = []);

    /**
     * Execute fetchAll method with bind options
     *
     * @param string sql
     * @param array bind
     * @return array
     */
    public abstract function fetchAll(string $sql, array $bind = []);

    /**
     * Execute fetchRow method with bind options
     *
     * @param string sql
     * @param array bind
     * @return array
     */
    public abstract function fetchOne(string $sql, array $bind = []);

    /**
     * Execute fetchOne method with bind options
     *
     * @param string sql
     * @param array bind
     * @return mixed
     */
    public abstract function fetchScalar(string $sql, array $bind = []);

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
     * @param string seq
     * @return int
     */
    public abstract function lastInsertId(string $seq = null);

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
     * select语句sql对象
     *
     * @return Select
     */
    public function select()
    {
        $dbtype = ucfirst($this->getDriverName());
        $classname = '\\Brisk\\Sql\\Select\\'. $dbtype;
        return new $classname();
    }

    /**
     * update语句sql对象
     *
     * @return Update
     */
    public function update()
    {
        $dbtype = ucfirst($this->getDriverName());
        $classname = '\\Brisk\\Sql\\Update\\'. $dbtype;
        return new $classname();
    }

    /**
     * delete语句sql对象
     *
     * @return Delete
     */
    public function delete()
    {
        $dbtype = ucfirst($this->getDriverName());
        $classname = '\\Brisk\\Sql\\Delete\\'. $dbtype;
        return new $classname();
    }

    /**
     * insert语句sql对象
     *
     * @return Insert
     */
    public function insert()
    {
        $dbtype = ucfirst($this->getDriverName());
        $classname = '\\Brisk\\Sql\\Insert\\'. $dbtype;
        return new $classname();
    }


}
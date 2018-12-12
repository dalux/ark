<?php

namespace Brisk\Db;

use Brisk\Sql\Delete;
use Brisk\Sql\Insert;
use Brisk\Sql\Select;
use Brisk\Sql\Update;

abstract class DbFather
{

    /**
     * Execute a sql with bind options
     *
     * @param string sql
     * @param array bind
     * @return bool
     */
    public abstract function query($sql, array $bind = []);

    /**
     * Execute fetchAll method with bind options
     *
     * @param string sql
     * @param array bind
     * @return array
     */
    public abstract function fetchAll($sql, array $bind = []);

    /**
     * Execute fetchRow method with bind options
     *
     * @param string sql
     * @param array bind
     * @return array
     */
    public abstract function fetchRow($sql, array $bind = []);

    /**
     * Execute fetchOne method with bind options
     *
     * @param string sql
     * @param array bind
     * @return int
     */
    public abstract function fetchOne($sql, array $bind = []);

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
    public abstract function lastInsertId($seq = null);

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
        if (!class_exists($classname)) {
            throw new ClassNotFoundException(Language::get('core.class_not_found', $classname));
        }
        return new $classname();;
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
        if (!class_exists($classname)) {
            throw new ClassNotFoundException(Language::get('core.class_not_found', $classname));
        }
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
        if (!class_exists($classname)) {
            throw new ClassNotFoundException(Language::get('core.class_not_found', $classname));
        }
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
        if (!class_exists($classname)) {
            throw new ClassNotFoundException(Language::get('core.class_not_found', $classname));
        }
        return new $classname();
    }


}
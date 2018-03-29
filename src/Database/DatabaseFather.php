<?php

namespace Ark\Database;

use Ark\Contract\IDatabase;

abstract class DatabaseFather implements IDatabase
{

    /**
     * 执行一条SQL语句，并返回受影响的行数
     *
     * @access public
     * @param string $sql
     * @param array $bind
     * @return int
     */
    abstract function query($sql, array $bind = array());

    /**
     * 获取所有数据记录
     *
     * @access public
     * @param string $sql
     * @param array $bind
     * @return array
     */
    abstract function fetchAll($sql, array $bind = array());

    /**
     * 获取当行数据
     *
     * @access public
     * @param string $sql
     * @param array $bind
     * @return array
     */
    abstract function fetch($sql, array $bind = array());

    /**
     * 获取第一行第一列数据，一般用在聚合函数中
     *
     * @access public
     * @param string $sql
     * @param array $bind
     * @return int
     */
    abstract function fetchOne($sql, array $bind = array());

    /**
     * 开启事务处理
     *
     * @access public
     * @return mixed
     */
    abstract function beginTransaction();

    /**
     * 提交事务处理
     *
     * @access public
     * @return mixed
     */
    abstract function commit();

    /**
     * 回滚事务处理
     *
     * @access public
     * @return mixed
     */
    abstract function rollback();

    /**
     * 是否处于事务中
     *
     * @return bool
     */
    abstract function inTransaction();

    /**
     * 最后一次写入的主键ID
     *
     * @access public
     * @param string $seq
     * @return mixed
     */
    abstract function lastInsertId($seq = null);

    /**
     * 最后一次事务影响的行数
     *
     * @access public
     * @return mixed
     */
    abstract function lastRowCount();

    /**
     * 获取驱动名称
     *
     * @return string
     */
    abstract function getDriverName();

    /**
     * 获取数据库对象原生实例
     *
     * @return mixed
     */
    abstract function getInstance();

}
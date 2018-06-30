<?php

namespace Brisk\Database;

abstract class DatabaseFather implements \Brisk\Contract\IDatabase
{

    /**
     * 执行数据库查询
     *
     * @param string $sql
     * @param array $bind
     * @return mixed
     */
    public abstract function query($sql, array $bind = array());

    /**
     * 获取多行记录
     *
     * @param string $sql
     * @param array $bind
     * @return array
     */
    public abstract function fetchAll($sql, array $bind = array());

    /**
     * 获取单行记录
     *
     * @param string $sql
     * @param array $bind
     * @return array
     */
    public abstract function fetchRow($sql, array $bind = array());

    /**
     * 获取首行首列数据
     *
     * @param string $sql
     * @param array $bind
     * @return mixed
     */
    public abstract function fetchOne($sql, array $bind = array());

    /**
     * 开启事务处理
     *
     * @return mixed
     */
    public abstract function beginTransaction();

    /**
     * 提交事务处理
     *
     * @return mixed
     */
    public abstract function commit();

    /**
     * 回滚事务处理
     *
     * @return mixed
     */
    public abstract function rollback();

    /**
     * 是否处于事务中
     *
     * @return mixed
     */
    public abstract function inTransaction();

    /**
     * 最后插入的数据ID
     *
     * @param string $seq
     */
    public abstract function lastInsertId($seq = "");

    /**
     * 最后一次操作影响行数
     *
     * @return mixed
     */
    public abstract function lastRowCount();

    /**
     * 数据库连接驱动名称
     *
     * @return mixed
     */
    public abstract function getDriverName();

    /**
     * 获取数据库连接实例
     *
     * @return mixed
     */
    public abstract function getInstance();

}

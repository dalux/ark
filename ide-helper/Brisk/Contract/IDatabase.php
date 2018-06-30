<?php

namespace Brisk\Contract;

interface IDatabase
{

    /**
     * 执行一个查询
     *
     * @param string $sql
     * @param array $bind
     * @return mixed
     */
    public function query($sql, array $bind = array());

    /**
     * 获取多行记录
     *
     * @param string $sql
     * @param array $bind
     * @return array
     */
    public function fetchAll($sql, array $bind = array());

    /**
     * 获取单行记录
     *
     * @param string $sql
     * @param array $bind
     * @return array
     */
    public function fetchRow($sql, array $bind = array());

    /**
     * 获取首行首列记录
     *
     * @param string $sql
     * @param array $bind
     * @return mixed
     */
    public function fetchOne($sql, array $bind = array());

    /**
     * 开始事务处理
     *
     * @return mixed
     */
    public function beginTransaction();

    /**
     * 提交事务处理
     *
     * @return mixed
     */
    public function commit();

    /**
     * 回滚事务处理
     *
     * @return mixed
     */
    public function rollback();

    /**
     * 获取最后一次写入的ID
     *
     * @param string $seq
     */
    public function lastInsertId($seq = "");

    /**
     * 获取最后执行影响行数
     *
     * @return mixed
     */
    public function lastRowCount();

    /**
     * 获取当前驱动器名称
     *
     * @return mixed
     */
    public function getDriverName();

    /**
     * 获取当前数据库连接实例
     *
     * @return mixed
     */
    public function getInstance();

}

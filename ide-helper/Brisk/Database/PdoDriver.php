<?php

namespace Brisk\Database;

class PdoDriver extends \Brisk\Database\DatabaseFather
{

    /**
     * 构造器
     *
     * @param string $dsn
     * @param string $user
     * @param string $pass
     * @param array $options
     */
    public function __construct($dsn = "", $user = "", $pass = "", array $options = array()) {}

    /**
     * 执行查询
     *
     * @param string $sql
     * @param array $bind
     * @return mixed
     */
    public function query($sql, array $bind = array()) {}

    /**
     * 获取多行数据
     *
     * @param string $sql
     * @param array $bind
     * @return array
     */
    public function fetchAll($sql, array $bind = array()) {}

    /**
     * 获取首行首列记录
     *
     * @param string $sql
     * @param array $bind
     * @return mixed
     */
    public function fetchOne($sql, array $bind = array()) {}

    /**
     * 获取单行记录
     *
     * @param string $sql
     * @param array $bind
     * @return array
     */
    public function fetchRow($sql, array $bind = array()) {}

    /**
     * 开启事务处理
     *
     * @return mixed|void
     */
    public function beginTransaction() {}

    /**
     * 提交事务处理
     *
     * @return mixed|void
     */
    public function commit() {}

    /**
     * 回滚事务处理
     *
     * @return mixed|void
     */
    public function rollback() {}

    /**
     * 是否处于事务中
     *
     * @return bool
     */
    public function inTransaction() {}

    /**
     * 获取下一个主键ID
     *
     * @return int
     */
    public function nextInsertId() {}

    /**
     * 获取上一个写入的ID
     *
     * @param string $seq
     * @return int
     */
    public function lastInsertId($seq = "") {}

    /**
     * 获取最后一次操作影响行数
     *
     * @return mixed|void
     */
    public function lastRowCount() {}

    /**
     * 设置取值模式
     *
     * @param int $mode
     * @return null
     */
    public function setFetchMode($mode) {}

    /**
     * 获取当前驱动器实例名称
     *
     * @return string
     */
    public function getDriverName() {}

    /**
     * 获取pdo连接实例
     *
     * @return mixed|void
     */
    public function getInstance() {}

}

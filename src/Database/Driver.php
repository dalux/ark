<?php

namespace Ark\Database;

use Ark\Database\Querier;
use Ark\Cache\Driver as CacheDriver;

abstract class Driver
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
     * 获取select助手
     *
     * @return Querier\Select
     */
    abstract function select();

    /**
     * 获取update助手
     *
     * @return Querier\Update
     */
    abstract function update();

    /**
     * 获取insert助手
     *
     * @return Querier\Insert
     */
    abstract function insert();

    /**
     * 获取delete助手
     *
     * @return Querier\Delete
     */
    abstract function delete();

    /**
     * 缓存SQL语句
     *
     * @param $expire
     * @param $name
     * @param CacheDriver $cache
     * @return mixed
     */
    abstract function cache($expire, $name, CacheDriver $cache);

}
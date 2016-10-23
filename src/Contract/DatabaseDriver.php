<?php

namespace Ark\Contract;

use Ark\Com\Database\SqlBuilder;

interface DatabaseDriver
{

    /**
     * 执行一条SQL语句，并返回受影响的行数
     *
     * @access public
     * @param string $sql
     * @param array $bind
     * @return int
     */
    function query($sql, array $bind = array());

    /**
     * 获取所有数据记录
     *
     * @access public
     * @param string $sql
     * @param array $bind
     * @return array
     */
    function fetchAll($sql, array $bind = array());

    /**
     * 获取当行数据
     *
     * @access public
     * @param string $sql
     * @param array $bind
     * @return array
     */
    function fetchRow($sql, array $bind = array());

    /**
     * 获取第一行第一列数据，一般用在聚合函数中
     *
     * @access public
     * @param string $sql
     * @param array $bind
     * @return int
     */
    function fetchScalar($sql, array $bind = array());

    /**
     * 开启事务处理
     *
     * @access public
     * @return mixed
     */
    function beginTransaction();

    /**
     * 提交事务处理
     *
     * @access public
     * @return mixed
     */
    function commit();

    /**
     * 回滚事务处理
     *
     * @access public
     * @return mixed
     */
    function rollback();

    /**
     * 最后一次写入的主键ID
     *
     * @access public
     * @param string $seq
     * @return mixed
     */
    function lastInsertId($seq = null);

    /**
     * 最后一次事务影响的行数
     *
     * @access public
     * @return mixed
     */
    function lastRowCount();

    /**
     * 获取驱动名称
     *
     * @return string
     */
    function getDriverName();

    /**
     * 获取select助手
     *
     * @return SqlBuilder\Select
     */
    function select();

    /**
     * 获取update助手
     *
     * @return SqlBuilder\Update
     */
    function update();

    /**
     * 获取insert助手
     *
     * @return SqlBuilder\Insert
     */
    function insert();

    /**
     * 获取delete助手
     *
     * @return SqlBuilder\Delete
     */
    function delete();

}
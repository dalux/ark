<?php declare(strict_types=1);

namespace Brisk\Db;

use Brisk\Toolkit\SqlBuilder\Delete;
use Brisk\Toolkit\SqlBuilder\Insert;
use Brisk\Toolkit\SqlBuilder\Select;
use Brisk\Toolkit\SqlBuilder\Update;

interface IDbDriver
{

    /**
     * 执行SQL
     *
     * @access public
     * @param string $sql
     * @param array $bind
     * @return bool
     */
    public function query(string $sql, array $bind = []);

    /**
     * 获取多行数据
     *
     * @access public
     * @param string $sql
     * @param array $bind
     * @return array
     */
    public function fetchAll(string $sql, array $bind = []);

    /**
     * 获取单行数据
     *
     * @access public
     * @param string $sql
     * @param array $bind
     * @return array
     */
    public function fetchOne(string $sql, array $bind = []);

    /**
     * 获取单行单列数据
     *
     * @access public
     * @param string $sql
     * @param array $bind
     * @return mixed
     */
    public function fetchScalar(string $sql, array $bind = []);

    /**
     * 开始事务处理
     *
     * @return bool
     */
    public function beginTransaction();

    /**
     * 提交事务
     *
     * @return bool
     */
    public function commit();

    /**
     * 回滚事务
     *
     * @return bool
     */
    public function rollback();

    /**
     * 检查当前是否处于事务处理中
     *
     * @return bool
     */
    public function inTransaction();

    /**
     * 获取最后一条插入的记录ID
     *
     * @param string seq
     * @return int
     */
    public function lastInsertId(string $seq = null);

    /**
     * 获取上一次sql影响的行数
     *
     * @return int
     */
    public function lastRowCount();

    /**
     * 获取当前数据库驱动器名称
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

    /**
     * select语句对象
     *
     * @access public
     * @return Select
     */
    public function select();

    /**
     * update语句对象
     *
     * @access public
     * @return Update
     */
    public function update();

    /**
     * delete语句sql对象
     *
     * @access public
     * @return Delete
     */
    public function delete();

    /**
     * insert语句sql对象
     *
     * @access public
     * @return Insert
     */
    public function insert();

}
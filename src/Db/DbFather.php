<?php declare(strict_types=1);

namespace Brisk\Db;

use Brisk\Toolkit\SqlBuilder\Delete;
use Brisk\Toolkit\SqlBuilder\Insert;
use Brisk\Toolkit\SqlBuilder\Select;
use Brisk\Toolkit\SqlBuilder\Update;

abstract class DbFather implements IDbDriver
{

    /**
     * 执行sql语句
     *
     * @access public
     * @param string $sql
     * @param array $bind
     * @return bool
     */
    public abstract function query(string $sql, array $bind = []);

    /**
     * 获取多行数据
     *
     * @access public
     * @param string $sql
     * @param array $bind
     * @return array
     */
    public abstract function fetchAll(string $sql, array $bind = []);

    /**
     * 获取单行数据
     *
     * @access public
     * @param string $sql
     * @param array $bind
     * @return array
     */
    public abstract function fetchOne(string $sql, array $bind = []);

    /**
     * 获取单行单列数据
     *
     * @access public
     * @param string $sql
     * @param array $bind
     * @return mixed
     */
    public abstract function fetchScalar(string $sql, array $bind = []);

    /**
     * 开启事务
     *
     * @access public
     * @return bool
     */
    public abstract function beginTransaction();

    /**
     * 提交事务
     *
     * @access public
     * @return bool
     */
    public abstract function commit();

    /**
     * 回滚事务
     *
     * @access public
     * @return bool
     */
    public abstract function rollback();

    /**
     * 当前是否处于事务中
     *
     * @access public
     * @return bool
     */
    public abstract function inTransaction();

    /**
     * 获取最后一次写入的ID
     *
     * @access public
     * @param string $seq
     * @return int
     */
    public abstract function lastInsertId(string $seq = null);

    /**
     * 获取最后一次sql影响的行数
     *
     * @access public
     * @return int
     */
    public abstract function lastRowCount();

    /**
     * 获取当前驱动器名称
     *
     * @access public
     * @return string
     */
    public abstract function getDriverName();

    /**
     * 获取数据库连接资源对象
     *
     * @access public
     * @return resource
     */
    public abstract function getInstance();

    /**
     * select语句对象
     *
     * @access public
     * @return Select
     */
    public function select()
    {
        $dbtype = ucfirst($this->getDriverName());
        $classname = 'Brisk\Toolkit\SqlBuilder\Select\\'. $dbtype;
        return new $classname();
    }

    /**
     * update语句对象
     *
     * @access public
     * @return Update
     */
    public function update()
    {
        $dbtype = ucfirst($this->getDriverName());
        $classname = 'Brisk\Toolkit\SqlBuilder\Update\\'. $dbtype;
        return new $classname();
    }

    /**
     * delete语句sql对象
     *
     * @access public
     * @return Delete
     */
    public function delete()
    {
        $dbtype = ucfirst($this->getDriverName());
        $classname = 'Brisk\Toolkit\SqlBuilder\Delete\\'. $dbtype;
        return new $classname();
    }

    /**
     * insert语句sql对象
     *
     * @access public
     * @return Insert
     */
    public function insert()
    {
        $dbtype = ucfirst($this->getDriverName());
        $classname = 'Brisk\Toolkit\SqlBuilder\Insert\\'. $dbtype;
        return new $classname();
    }


}
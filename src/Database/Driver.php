<?php

namespace Ark\Database;

use Ark\Cache\Proxy;
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
     * 获取数据库对象原生实例
     *
     * @return mixed
     */
    abstract function getInstance();

    /**
     * select对象
     *
     * @access public
     * @return Querier\Select;
     */
    function select()
    {
        $driver = ucfirst($this->getDriverName());
        $class = '\\Ark\\Database\\Querier\\Select\\'. $driver;
        /* @var Querier\Select $instance */
        $instance = new $class();
        return $instance->invoke($this);
    }

    /**
     * update对象
     *
     * @access public
     * @return Querier\Update;
     */
    function update()
    {
        $driver = ucfirst($this->getDriverName());
        $class = '\\Ark\\Database\\Querier\\Update\\'. $driver;
        /* @var Querier\Update $instance */
        $instance = new $class();
        return $instance->invoke($this);
    }

    /**
     * insert对象
     *
     * @access public
     * @return Querier\Insert
     */
    function insert()
    {
        $driver = ucfirst($this->getDriverName());
        $class = '\\Ark\\Database\\Querier\\Insert\\'. $driver;
        /* @var Querier\Insert $instance */
        $instance = new $class();
        return $instance->invoke($this);
    }

    /**
     * delete对象
     *
     * @access public
     * @return Querier\Delete
     */
    function delete()
    {
        $driver = ucfirst($this->getDriverName());
        $class = '\\Ark\\Database\\Querier\\Delete\\'. $driver;
        /* @var Querier\Delete $instance */
        $instance = new $class();
        return $instance->invoke($this);
    }

    /**
     * 缓存SQL语句
     *
     * @param $expire
     * @param $name
     * @param CacheDriver $cache
     * @return mixed
     */
    function cache($expire, $name, CacheDriver $cache)
    {
        $proxy = new Proxy($cache);
        return $proxy->invoke($this, $expire, $name);
    }

}
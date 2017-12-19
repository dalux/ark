<?php

namespace Ark\Assembly\Database;

use Ark\Core\Trace;
use Ark\Core\Timer;
use Ark\Core\Event;

class Pdo extends Father
{

    /**
     * PDO对象
     *
     * @var \PDO
     */
    protected $_instance;

    /**
    * 数据库取值方式
    *
    * @access protected
    * @var string
    */
    protected $_fetch_mode = \PDO::FETCH_ASSOC;

    /**
     * SQL语句执行后影响到的行数
     *
     * @access protected
     * @var integer
     */
    protected $_row_count = 0;

    /**
     * 构造函数
     *
     * @access public
     * @param null $dsn
     * @param null $user
     * @param null $pass
     * @param array $options
     * @throws Exception
     */
	function __construct($dsn = null, $user = null, $pass = null, array $options = array())
	{
		try {
            Timer::mark('db_connect_begin');
            $instance = new \PDO($dsn, $user, $pass, $options);
            Timer::mark('db_connect_end');
            $data = array(
                'container'=> $this,
                'instance'=> $instance,
                'driver'=> $instance->getAttribute(\PDO::ATTR_DRIVER_NAME),
            );
            $data = Event::onListening('event.dbconnect.finish', $data);
            $this->_instance = $data['instance'];
		} catch(\PDOException $e) {
			throw new Exception($e->getMessage());
		}
	}

    /**
     * 执行SQL语句并返回一个PDOStatement对象
     *
     * @param string $sql
     * @param array $bind
     * @return \PDOStatement
     * @throws Exception
     */
    protected function _query($sql, $bind = array())
    {
        try {
            Timer::mark('db_query_begin');
            is_string($sql) || $sql = (string)$sql;
            /* @var \PDOStatement $smt */
            $smt = $this->_instance->prepare($sql);
            if ($bind) {
                foreach ($bind as $key=> $val) {
                    is_string($key) || $key += 1;
                    //binParam按引用传递第二个参数,如果此处写$val,则execute执行时,值会全变为最后一次的$val值
                    $smt->bindParam($key, $bind[$key]);
                }
            }
            $smt->execute();
            $smt->setFetchMode($this->_fetch_mode);
            $this->_row_count = $smt->rowCount();
            Timer::mark('db_query_end');
            Trace::set('database', array($smt->queryString, sprintf('%.4f', Timer::lastUsed())));
            return $smt;
        } catch(\PDOException $e) {
            /* @var \PDOStatement $smt */
            $data = array(
                'sql'=> $smt->queryString,
                'error'=> $e->getMessage(),
                'driver'=> $this->getDriverName(),
            );
            $data = Event::onListening('event.query.failed', $data);
            throw new Exception($data['error']);
        }
    }

    /**
     * 执行一个SQL语句
     *
     * @access public
     * @param string $sql
     * @param array $bind
     * @return int
     * @throws Exception
     */
    function query($sql, array $bind = array())
    {
        $data = array(
            'method'=> __METHOD__,
            'sql'=> (string)$sql,
            'bind'=> $bind,
            'driver'=> $this->getDriverName(),
        );
        $data = Event::onListening('event.query.before', $data);
        $smt = $this->_query($data['sql'], $data['bind']);
        $result = true;
        $smt = null;
        $data['result'] = $result;
        $data = Event::onListening('event.query.finish', $data);
        return $data['result'];
    }

    /**
     * 返回所有数据
     *
     * @access public
     * @param string $sql
     * @param array $bind
     * @return mixed
     * @throws Exception
     */
    function fetchAll($sql, array $bind = array())
    {
        $data = array(
            'method'=> __METHOD__,
            'sql'=> (string)$sql,
            'bind'=> $bind,
            'driver'=> $this->getDriverName(),
        );
        $data = Event::onListening('event.query.before', $data);
        $smt = $this->_query($data['sql'], $data['bind']);
        $result = $smt->fetchAll($this->_fetch_mode);
        $smt = null;
        $data['result'] = $result;
        $data = Event::onListening('event.query.finish', $data);
        return $data['result'];
    }

    /**
     * 返回第一行第一列数据，一般用在聚合函数中
     *
     * @access public
     * @param string $sql
     * @param array $bind
     * @return mixed
     * @throws Exception
     */
    function fetchOne($sql, array $bind = array())
    {
        $data = array(
            'method'=> __METHOD__,
            'sql'=> (string)$sql,
            'bind'=> $bind,
            'driver'=> $this->getDriverName(),
        );
        $data = Event::onListening('event.query.before', $data);
        $smt = $this->_query($data['sql'], $data['bind']);
        $result = $smt->fetchColumn(0);
        $smt = null;
        $data['result'] = $result;
        $data = Event::onListening('event.query.finish', $data);
        return $data['result'];
    }

    /**
     * 返回单行数据
     *
     * @access public
     * @param string $sql
     * @param array $bind
     * @return mixed
     * @throws Exception
     */
    function fetch($sql, array $bind = array())
    {
        $data = array(
            'method'=> __METHOD__,
            'sql'=> (string)$sql,
            'bind'=> $bind,
            'driver'=> $this->getDriverName(),
        );
        $data = Event::onListening('event.query.before', $data);
        $smt = $this->_query($data['sql'], $data['bind']);
        $result = $smt->fetch($this->_fetch_mode);
        $smt = null;
        $data['result'] = $result;
        $data = Event::onListening('event.query.finish', $data);
        return $data['result'];
    }

    /**
     * 开启事务处理
     *
     * @return mixed
     */
    function beginTransaction()
    {
        return $this->_instance->beginTransaction();
    }

    /**
     * 提交事务处理
     *
     * @return mixed
     */
    function commit()
    {
        return $this->_instance->commit();
    }

    /**
     * 回滚事务处理
     *
     * @return mixed
     */
    function rollback()
    {
        return $this->_instance->rollback();
    }

    /**
     * 是否处于事务中
     *
     * @return bool
     */
    function inTransaction()
    {
        return $this->_instance->inTransaction();
    }

    /**
     * 取序列的下一个值
     *
     * @return null
     * @internal param null $seq
     */
    function nextInsertId()
    {
        return null;
    }

    /**
     * 返回上一次插入的数据ID
     *
     * @access public
     * @param string $seq
     * @return integer
     */
    function lastInsertId($seq = null)
    {
        return $this->_instance->lastInsertId();
    }

	/**
	 * 返回受影响的行数
	 *
	 * @access public
	 * @return integer
	 */
	function lastRowCount()
	{
		return $this->_row_count;
	}

    /**
     * 获取驱动器名称
     *
     * @access public
     * @return string
     */
    function getDriverName()
    {
        return $this->_instance->getAttribute(\PDO::ATTR_DRIVER_NAME);
    }

    /**
     * 获取PDO对象实例
     *
     * @return \PDO
     */
    function getInstance()
    {
        return $this->_instance;
    }

}
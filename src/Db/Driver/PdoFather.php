<?php

namespace Brisk\Db\Driver;

use Brisk\Kernel\Event;
use Brisk\Kernel\Timer;
use Brisk\Kernel\Trace;
use Brisk\Db\DbFather;
use Brisk\Exception\PdoException;

abstract class PdoFather extends DbFather
{

    /**
     * @var \PDO
     */
    protected $_instance;

    /**
     * @var int
     */
    protected $_row_count = 0;

    /**
     * Construct
     *
     * @param string dsn
     * @param string username
     * @param string password
     * @param array option
     * @return null
     */
	public function __construct($dsn, $username, $password, array $option = [])
	{
		try {
            Timer::mark('db_connect_begin');
            $instance = new \PDO($dsn, $username, $password, $option);
            Timer::mark('db_connect_end');
            $data = [
                'container'=> $this,
                'instance'=> $instance,
                'driver'=> $instance->getAttribute(\PDO::ATTR_DRIVER_NAME)
            ];
            $data = Event::trigger('event.dbconnect.finish', $data);
            $this->_instance = $data['instance'];
		} catch (\PDOException $e) {
			throw new PdoException($e->getMessage());
		}
	}

    /**
     * Execute a sql with bind options
     *
     * @param string sql
     * @param array bind
     * @return bool
     */
    public function query($sql, array $bind = [])
    {
		$data = [
            'method'=> __METHOD__,
            'sql'=> $sql,
            'bind'=> $bind,
            'driver'=> $this->getDriverName()
        ];
        $data = Event::trigger('event.query.before', $data);
		$smt = $this->_query($data['sql'], $data['bind']);
        $data['result'] = true;
        $data = Event::trigger('event.query.finish', $data);
        return $data['result'];
    }

    /**
     * Execute fetchAll method with bind options
     *
     * @param string sql
     * @param array bind
     * @return array
     */
    public function fetchAll($sql, array $bind = [])
    {
		$data = [
            'method'=> __METHOD__,
            'sql'=> $sql,
            'bind'=> $bind,
            'driver'=> $this->getDriverName()
        ];
        $data = Event::trigger('event.query.before', $data);
        $smt = $this->_query($data['sql'], $data['bind']);
        $result = $smt->fetchAll();
        $data['result'] = $result;
        $data = Event::trigger('event.query.finish', $data);
        return $data['result'];
    }

    /**
     * Execute fetchOne method with bind options
     *
     * @param string sql
     * @param array bind
     * @return int
     */
    public function fetchOne($sql, array $bind = [])
    {
        $data = [
            'method'=> __METHOD__,
            'sql'=> $sql,
            'bind'=> $bind,
            'driver'=> $this->getDriverName()
        ];
        $data = Event::trigger('event.query.before', $data);
        $smt = $this->_query($data['sql'], $data['bind']);
        $data['result'] = $smt->fetchColumn(0);
        $data = Event::trigger('event.query.finish', $data);
        return $data['result'];
    }

    /**
     * Execute fetchRow method with bind options
     *
     * @param string sql
     * @param array bind
     * @return array
     */
    public function fetchRow($sql, array $bind = [])
    {
		$data = [
            'method'=> __METHOD__,
            'sql'=> $sql,
            'bind'=> $bind,
            'driver'=> $this->getDriverName()
        ];
        $data = Event::trigger('event.query.before', $data);
        $smt = $this->_query($data['sql'], $data['bind']);
        $data['result'] = $smt->fetch();
        $data = Event::trigger('event.query.finish', $data);
        return $data['result'];
    }

    /**
     * Start a new Transaction
     *
     * @return bool
     */
    public function beginTransaction()
    {
        return $this->_instance->beginTransaction();
    }

    /**
     * Commit a Transaction
     *
     * @return bool
     */
    public function commit()
    {
        return $this->_instance->commit();
    }

    /**
     * Rollback a Transaction
     *
     * @return bool
     */
    public function rollback()
    {
        return $this->_instance->rollback();
    }

    /**
     * Check if the current sql is in a transaction
     *
     * @return bool
     */
    public function inTransaction()
    {
        return $this->_instance->inTransaction();
    }

    /**
     * Get last insert id
     *
     * @param string seq
     * @return int
     */
    public function lastInsertId($seq = null)
    {
        return $this->_instance->lastInsertId();
    }

    /**
     * Gets the number of rows as a result of the last sql execution
     *
     * @return int
     */
	public function lastRowCount()
	{
		return $this->_row_count;
	}

    /**
     * Get current driver name
     *
     * @return string
     */
    public function getDriverName()
    {
        return $this->_instance->getAttribute(\PDO::ATTR_DRIVER_NAME);
    }

    /**
     * Get pdo instance
     *
     * @return \PDO
     */
    public function getInstance()
    {
        return $this->_instance;
    }

    /**
     * 执行查询并返回statement对象
     *
     * @param string $sql
     * @param array $bind
     * @return \PDOStatement
     */
    private function _query($sql, array $bind = [])
    {
        try {
            Timer::mark('db_query_begin');
			$smt = $this->_instance->prepare($sql);
            if (count($bind) > 0) {
                foreach ($bind as $key=> $val) {
					if (!is_string($key)) {
						$key = $key + 1;
					}
                    //binParam按引用传递第二个参数,如果此处写val,则execute执行时,值会全变为最后一次的val值
                    $smt->bindParam($key, $bind[$key]);
                }
            }
            if (!$smt->execute()) {
                throw new \PDOException('PDOStatement execute failed');
            }
            $smt->setFetchMode(\PDO::FETCH_ASSOC);
            $this->_row_count = $smt->rowCount();
            Timer::mark('db_query_end');
            Trace::set('database', [$smt->queryString, sprintf('%.4f', Timer::lastUsed())]);
            return $smt;
        } catch (\PDOException $e) {
            $data = [
                'sql'=> $smt->queryString,
                'error'=> $e->getMessage(),
                'driver'=> $this->getDriverName()
            ];
            $data = Event::trigger('event.query.failed', $data);
            throw new PdoException($data['error']);
        }
    }

}
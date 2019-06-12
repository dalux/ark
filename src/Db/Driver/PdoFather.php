<?php declare(strict_types=1);

namespace Brisk\Db\Driver;

use Brisk\Event;
use Brisk\Timer;
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
	public function __construct(string $dsn, string $username, string $password, array $option = [])
	{
		try {
		    $data = [
		        'object'    => $this,
                'dsn'       => $dsn,
                'username'  => $username,
                'password'  => $password,
                'option'    => $option,
            ];
		    $data = Event::fire('event.dbconnect.before', $data);
            Timer::mark('db_connect_begin');
            $instance = new \PDO($data['dsn'], $data['username'], $data['password'], $data['option']);
            Timer::mark('db_connect_end');
            $data = [
                'object'    => $this,
                'dsn'       => $dsn,
                'username'  => $username,
                'password'  => $password,
                'option'    => $option,
                'instance'  => $instance,
                'driver'    => $instance->getAttribute(\PDO::ATTR_DRIVER_NAME),
                'timeused'  => Timer::lastUsed()
            ];
            $data = Event::fire('event.dbconnect.finish', $data);
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
    public function query(string $sql, array $bind = [])
    {
		$data = [
            'object'    => $this,
            'method'    => __METHOD__,
            'sql'       => $sql,
            'bind'      => $bind,
            'driver'    => $this->getDriverName()
        ];
        $data = Event::fire('event.dbquery.before', $data);
        Timer::mark('db_query_before');
		$smt = $this->_query($data['sql'], $data['bind']);
		Timer::mark('db_query_finish');
        $data['result'] = true;
        $data['query'] = $smt->queryString;
        $data['timeused'] = Timer::lastUsed();
        $data = Event::fire('event.dbquery.finish', $data);
        return $data['result'];
    }

    /**
     * Execute fetchAll method with bind options
     *
     * @param string sql
     * @param array bind
     * @return array
     */
    public function fetchAll(string $sql, array $bind = [])
    {
		$data = [
            'object'    => $this,
            'method'    => __METHOD__,
            'sql'       => $sql,
            'bind'      => $bind,
            'driver'    => $this->getDriverName()
        ];
        $data = Event::fire('event.dbquery.before', $data);
        Timer::mark('db_query_before');
        $smt = $this->_query($data['sql'], $data['bind']);
        $result = $smt->fetchAll();
        Timer::mark('db_query_finish');
        $data['result'] = $result;
        $data['query'] = $smt->queryString;
        $data['timeused'] = Timer::lastUsed();
        $data = Event::fire('event.dbquery.finish', $data);
        return $data['result'];
    }

    /**
     * Execute fetchOne method with bind options
     *
     * @param string sql
     * @param array bind
     * @return int
     */
    public function fetchOne(string $sql, array $bind = [])
    {
        $data = [
            'object'    => $this,
            'method'    => __METHOD__,
            'sql'       => $sql,
            'bind'      => $bind,
            'driver'    => $this->getDriverName()
        ];
        $data = Event::fire('event.dbquery.before', $data);
        Timer::mark('db_query_before');
        $smt = $this->_query($data['sql'], $data['bind']);
        $data['result'] = $smt->fetchColumn(0);
        Timer::mark('db_query_finish');
        $data['query'] = $smt->queryString;
        $data['timeused'] = Timer::lastUsed();
        $data = Event::fire('event.dbquery.finish', $data);
        return $data['result'];
    }

    /**
     * Execute fetchRow method with bind options
     *
     * @param string sql
     * @param array bind
     * @return array
     */
    public function fetchRow(string $sql, array $bind = [])
    {
		$data = [
            'object'    => $this,
            'method'    => __METHOD__,
            'sql'       => $sql,
            'bind'      => $bind,
            'driver'    => $this->getDriverName()
        ];
        $data = Event::fire('event.dbquery.before', $data);
        Timer::mark('db_query_before');
        $smt = $this->_query($data['sql'], $data['bind']);
        $data['result'] = $smt->fetch();
        Timer::mark('db_query_finish');
        $data['query'] = $smt->queryString;
        $data['timeused'] = Timer::lastUsed();
        $data = Event::fire('event.dbquery.finish', $data);
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
    public function lastInsertId(string $seq = null)
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
    private function _query(string $sql, array $bind = [])
    {
        try {
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
            return $smt;
        } catch (\PDOException $e) {
            $data = [
                'object'    => $this,
                'method'    => __METHOD__,
                'sql'       => $smt->queryString,
                'error'     => $e->getMessage(),
                'driver'    => $this->getDriverName()
            ];
            $data = Event::fire('event.dbquery.failed', $data);
            throw new PdoException($data['error']);
        }
    }

}
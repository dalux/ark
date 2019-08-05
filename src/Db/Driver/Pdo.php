<?php declare(strict_types=1);

namespace Brisk\Db\Driver;

use Brisk\Kernel\Event;
use Brisk\Kernel\Timer;
use Brisk\Db\DbFather;
use Brisk\Exception\PdoException;
use Brisk\Kernel\Toolkit;

class Pdo extends DbFather
{

    /**
     * pdo连接实例
     * 
     * @var \PDO
     */
    private $_instance;

    private $_dsn;

    private $_user;

    /**
     * 最近影响行数
     *
     * @var int
     */
    private $_row_count = 0;

    /**
     * 构造函数
     *
     * @access public
     * @param string $dsn
     * @param string $username
     * @param string $password
     * @param array $option
     * @return void
     */
	public function __construct(string $dsn, string $username, string $password, array $option = [])
	{
		try {
            $default = [
                \PDO::ATTR_ERRMODE              => \PDO::ERRMODE_EXCEPTION,
                \PDO::ATTR_ORACLE_NULLS         => \PDO::NULL_EMPTY_STRING,
                \PDO::ATTR_CASE                 => \PDO::CASE_LOWER,
                \PDO::ATTR_EMULATE_PREPARES     => false
            ];
            $option = $default + $option;
		    $data = [
		        'driver'    => $this,
                'method'    => __METHOD__,
                'dsn'       => $dsn,
                'username'  => $username,
                'password'  => $password,
                'option'    => $option,
            ];
		    $data = Event::fire('event.dbconnect.before', $data);
            Timer::mark('db_connect_begin');
            $this->_instance = new \PDO($data['dsn'], $data['username'], $data['password'], $data['option']);
            Timer::mark('db_connect_end');
            $data = [
                'driver'    => $this,
                'dsn'       => $dsn,
                'username'  => $username,
                'password'  => $password,
                'option'    => $option,
                'instance'  => $this->_instance,
                'timeused'  => Timer::lastUsed()
            ];
            $data = Event::fire('event.dbconnect.finish', $data);
            $this->_dsn = $data['dsn'];
            $this->_user = $data['username'];
            $this->_instance = $data['instance'];
		} catch (\PDOException $e) {
			throw new PdoException($e->getMessage());
		}
	}

    /**
     * 执行sql语句
     *
     * @access public
     * @param string $sql
     * @param array $bind
     * @return bool
     */
    public function query(string $sql, array $bind = [])
    {
		$data = [
            'driver'    => $this,
            'method'    => __METHOD__,
            'sql'       => $sql,
            'bind'      => $bind,
        ];
        $data = Event::fire('event.dbquery.before', $data);
        Timer::mark('db_query_before');
		$smt = $this->_query($data['sql'], $data['bind']);
		Timer::mark('db_query_finish');
        $data['result'] = true;
        $data['timeused'] = Timer::lastUsed();
        $data = Event::fire('event.dbquery.finish', $data);
        return $data['result'];
    }

    /**
     * 获取多行数据
     *
     * @access public
     * @param string $sql
     * @param array $bind
     * @return array
     */
    public function fetchAll(string $sql, array $bind = [])
    {
		$data = [
            'driver'    => $this,
            'method'    => __METHOD__,
            'sql'       => $sql,
            'bind'      => $bind,
        ];
        $data = Event::fire('event.dbquery.before', $data);
        Timer::mark('db_query_before');
        $smt = $this->_query($data['sql'], $data['bind']);
        $result = $smt->fetchAll();
        Timer::mark('db_query_finish');
        $data['result'] = $result;
        $data['timeused'] = Timer::lastUsed();
        $data = Event::fire('event.dbquery.finish', $data);
        return $data['result'];
    }

    /**
     * 获取单行数据
     *
     * @access public
     * @param string sql
     * @param array bind
     * @return array
     */
    public function fetchOne(string $sql, array $bind = [])
    {
		$data = [
            'driver'    => $this,
            'method'    => __METHOD__,
            'sql'       => $sql,
            'bind'      => $bind,
        ];
        $data = Event::fire('event.dbquery.before', $data);
        Timer::mark('db_query_before');
        $smt = $this->_query($data['sql'], $data['bind']);
        $data['result'] = $smt->fetch();
        Timer::mark('db_query_finish');
        $data['timeused'] = Timer::lastUsed();
        $data = Event::fire('event.dbquery.finish', $data);
        return $data['result'];
    }

    /**
     * 获取单行单列数据
     *
     * @access public
     * @param string $sql
     * @param array $bind
     * @return int
     */
    public function fetchScalar(string $sql, array $bind = [])
    {
        $data = [
            'driver'    => $this,
            'method'    => __METHOD__,
            'sql'       => $sql,
            'bind'      => $bind,
        ];
        $data = Event::fire('event.dbquery.before', $data);
        Timer::mark('db_query_before');
        $smt = $this->_query($data['sql'], $data['bind']);
        $data['result'] = $smt->fetchColumn(0);
        Timer::mark('db_query_finish');
        $data['timeused'] = Timer::lastUsed();
        $data = Event::fire('event.dbquery.finish', $data);
        return $data['result'];
    }

    /**
     * 开始事务
     *
     * @access public
     * @return bool
     */
    public function beginTransaction()
    {
        return $this->_instance->beginTransaction();
    }

    /**
     * 提交事务
     *
     * @access public
     * @return bool
     */
    public function commit()
    {
        return $this->_instance->commit();
    }

    /**
     * 回滚事务
     *
     * @access public
     * @return bool
     */
    public function rollback()
    {
        return $this->_instance->rollback();
    }

    /**
     * 当前是否处于事务中
     *
     * @access public
     * @return bool
     */
    public function inTransaction()
    {
        return $this->_instance->inTransaction();
    }

    /**
     * 获取上一条语句插入的ID
     *
     * @access public
     * @param string $seq
     * @return int
     */
    public function lastInsertId(string $seq = null)
    {
        return $this->_instance->lastInsertId();
    }

    /**
     * 获取上一条语句影响的行数
     *
     * @access public
     * @return int
     */
	public function lastRowCount()
	{
		return $this->_row_count;
	}

    /**
     * 获取当前数据库连接驱动名称
     *
     * @access public
     * @return string
     */
    public function getDriverName()
    {
        return $this->_instance->getAttribute(\PDO::ATTR_DRIVER_NAME);
    }

    /**
     * 获取数据库连接实例
     *
     * @access public
     * @return \PDO
     */
    public function getInstance()
    {
        return $this->_instance;
    }

    /**
     * 执行查询并返回statement对象
     *
     * @access private
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
                    $idx = $key;
					if (!is_string($key)) {
						$idx = $idx + 1;
					}
                    switch ($bind[$key]['type']) {
                        case 'string':
                            $smt->bindValue($idx, $bind[$key]['value'], \PDO::PARAM_STR);
                            break;
                        case 'float':
                        case 'integer':
                        case 'int':
                        case 'double':
                            $smt->bindValue($idx, $bind[$key]['value'], \PDO::PARAM_INT);
                            break;
                        case 'boolean':
                        case 'bool':
                            $smt->bindValue($idx, $bind[$key]['value'], \PDO::PARAM_BOOL);
                            break;
                        case 'null':
                            $smt->bindValue($idx, 'NULL', \PDO::PARAM_NULL);
                            break;
                    }
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
                'driver'    => $this,
                'method'    => __METHOD__,
                'sql'       => $sql,
                'bind'      => $bind,
                'error'     => $e->getMessage(),
            ];
            $data = Event::fire('event.dbquery.failed', $data);
            throw new PdoException($data['error']);
        }
    }

}
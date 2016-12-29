<?php

namespace Ark\Com\Database\Driver;

use Ark\Core\Trace;
use Ark\Core\Timer;
use Ark\Core\Struct;
use Ark\Com\Cache\Proxy;
use Ark\Contract\CacheDriver;
use Ark\Contract\CacheProxy;
use Ark\Contract\DatabaseDriver;
use Ark\Com\Database\SqlBuilder;
use Ark\Com\Event\Adapter as EventAdapter;

class Pdo extends \PDO implements DatabaseDriver, CacheProxy
{

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
     * 查询开始前的事件检验规则
     *
     * @var array
     */
    protected $_rule_query_before = array(
        'method'    => array(Struct::FLAG_REQUIRED=> true,  Struct::FLAG_TYPE=> Struct::TYPE_STRING),
        'sql'       => array(Struct::FLAG_REQUIRED=> true,  Struct::FLAG_TYPE=> Struct::TYPE_STRING),
        'bind'      => array(Struct::FLAG_REQUIRED=> false, Struct::FLAG_TYPE=> Struct::TYPE_ARRAY),
        'driver'    => array(Struct::FLAG_REQUIRED=> true,  Struct::FLAG_TYPE=> Struct::TYPE_STRING),
    );

    /**
     * 查询结束后的事件校验规则
     *
     * @var array
     */
    protected $_rule_query_finish = array(
        'method'    => array(Struct::FLAG_REQUIRED=> true, Struct::FLAG_TYPE=> Struct::TYPE_STRING),
        'sql'       => array(Struct::FLAG_REQUIRED=> true, Struct::FLAG_TYPE=> Struct::TYPE_STRING),
        'bind'      => array(Struct::FLAG_REQUIRED=> false, Struct::FLAG_TYPE=> Struct::TYPE_ARRAY),
        'result'    => array(Struct::FLAG_REQUIRED=> true, Struct::FLAG_TYPE=> Struct::TYPE_ARRAY),
        'driver'    => array(Struct::FLAG_REQUIRED=> true, Struct::FLAG_TYPE=> Struct::TYPE_STRING),
    );

    /**
     * 查询失败时的事件校验规则
     *
     * @var array
     */
    protected $_rule_query_failed = array(
        'sql'       => array(Struct::FLAG_REQUIRED=> true, Struct::FLAG_TYPE=> Struct::TYPE_STRING),
        'error'     => array(Struct::FLAG_REQUIRED=> true, Struct::FLAG_TYPE=> Struct::TYPE_STRING),
        'driver'    => array(Struct::FLAG_REQUIRED=> true, Struct::FLAG_TYPE=> Struct::TYPE_STRING),
    );

    /**
     * 构造函数
     *
     * @access public
     * @param null $dsn
     * @param null $user
     * @param null $pass
     * @param array $options
     * @throws PdoException
     */
	function __construct($dsn = null, $user = null, $pass = null, array $options = array())
	{
		try {
            Timer::mark('db_connect_begin');
			parent::__construct($dsn, $user, $pass, $options);
            Timer::mark('db_connect_end');
		} catch(\PDOException $e) {
			throw new PdoException($e->getMessage());
		}
	}

    /**
     * 执行SQL语句并返回一个PDOStatement对象
     *
     * @param string $sql
     * @param array $bind
     * @return \PDOStatement
     * @throws PdoException
     */
    protected function _query($sql, $bind = array())
    {
        try {
            Timer::mark('db_query_begin');
            is_string($sql) || $sql = (string)$sql;
            $smt = $this->prepare($sql);
            if ($bind) {
                foreach ($bind as $key=> $val) {
                    is_string($key) || $key += 1;
                    $smt->bindParam($key, $val);
                }
            }
            $smt->execute();
            $smt->setFetchMode($this->_fetch_mode);
            $this->_row_count = $smt->rowCount();
            Timer::mark('db_query_end');
            Trace::set('database', array($smt->queryString, sprintf('%.4f', Timer::lastUsed())));
            return $smt;
        } catch(\PDOException $e) {
            $data = array(
                'sql'=> $smt->queryString,
                'error'=> $e->getMessage(),
                'driver'=> $this->getDriverName(),
            );
            $data = EventAdapter::onListening('event.query.failed', $data, $this->_rule_query_failed);
            throw new PdoException($data['error']);
        }
    }

    /**
     * 执行一个SQL语句
     *
     * @access public
     * @param string $sql
     * @param array $bind
     * @return int
     * @throws PdoException
     */
    function query($sql, array $bind = array())
    {
        $data = array(
            'method'=> __METHOD__,
            'sql'=> (string)$sql,
            'bind'=> $bind,
            'driver'=> $this->getDriverName(),
        );
        $data = EventAdapter::onListening('event.query.before', $data, $this->_rule_query_before);
        $result = $this->_query($data['sql'], $data['bind'])->rowCount();
        $data['result'] = $result;
        $data = EventAdapter::onListening('event.query.finish', $data, $this->_rule_query_finish);
        return $data['result'];
    }

    /**
     * 返回所有数据
     *
     * @access public
     * @param string $sql
     * @param array $bind
     * @return mixed
     * @throws PdoException
     */
    function fetchAll($sql, array $bind = array())
    {
        $data = array(
            'method'=> __METHOD__,
            'sql'=> (string)$sql,
            'bind'=> $bind,
            'driver'=> $this->getDriverName(),
        );
        $data = EventAdapter::onListening('event.query.before', $data, $this->_rule_query_before);
        $result = $this->_query($data['sql'], $data['bind'])->fetchAll($this->_fetch_mode);
        $data['result'] = $result;
        $data = EventAdapter::onListening('event.query.finish', $data, $this->_rule_query_finish);
        return $data['result'];
    }

    /**
     * 返回第一行第一列数据，一般用在聚合函数中
     *
     * @access public
     * @param string $sql
     * @param array $bind
     * @return mixed
     * @throws PdoException
     */
    function fetchScalar($sql, array $bind = array())
    {
        $data = array(
            'method'=> __METHOD__,
            'sql'=> (string)$sql,
            'bind'=> $bind,
            'driver'=> $this->getDriverName(),
        );
        $data = EventAdapter::onListening('event.query.before', $data, $this->_rule_query_before);
        $result = $this->_query($data['sql'], $data['bind'])->fetchColumn(0);
        $data['result'] = $result;
        $data = EventAdapter::onListening('event.query.finish', $data, $this->_rule_query_finish);
        return $data['result'];
    }

    /**
     * 返回单行数据
     *
     * @access public
     * @param string $sql
     * @param array $bind
     * @return mixed
     * @throws PdoException
     */
    function fetchRow($sql, array $bind = array())
    {
        $data = array(
            'method'=> __METHOD__,
            'sql'=> (string)$sql,
            'bind'=> $bind,
            'driver'=> $this->getDriverName(),
        );
        $data = EventAdapter::onListening('event.query.before', $data, $this->_rule_query_before);
        $result = $this->_query($data['sql'], $data['bind'])->fetch($this->_fetch_mode);
        $data['result'] = $result;
        $data = EventAdapter::onListening('event.query.finish', $data, $this->_rule_query_finish);
        return $data['result'];
    }

    /**
     * 取序列的下一个值
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
        return parent::lastInsertId($seq);
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
        return $this->getAttribute(\PDO::ATTR_DRIVER_NAME);
    }

    /**
     * 缓存代理
     *
     * @access public
     * @param int $expire
     * @param null $name
     * @param CacheDriver $cache
     * @return CacheProxy
     */
    function cache($expire, $name, CacheDriver $cache)
    {
        $proxy = new Proxy($cache);
        return $proxy->invoke($this, $expire, $name);
    }

    /**
     * select对象
     *
     * @access public
     * @return SqlBuilder\Select;
     */
    function select()
    {
        $class = '\\Ark\\Com\\Database\\SqlBuilder\\Select\\'. ucfirst($this->getDriverName());
        $instance = new $class();
        return $instance->invoke($this);
    }

    /**
     * update对象
     *
     * @access public
     * @return SqlBuilder\Update;
     */
    function update()
    {
        $class = '\\Ark\\Com\\Database\\SqlBuilder\\Update\\'. ucfirst($this->getDriverName());
        $instance = new $class();
        return $instance->invoke($this);
    }

    /**
     * insert对象
     *
     * @access public
     * @return SqlBuilder\Insert
     */
    function insert()
    {
        $class = '\\Ark\\Com\\Database\\SqlBuilder\\Insert\\'. ucfirst($this->getDriverName());
        $instance = new $class();
        return $instance->invoke($this);
    }

    /**
     * delete对象
     *
     * @access public
     * @return SqlBuilder\Delete
     */
    function delete()
    {
        $class = '\\Ark\\Com\\Database\\SqlBuilder\\Delete\\'. ucfirst($this->getDriverName());
        $instance = new $class();
        return $instance->invoke($this);
    }

}
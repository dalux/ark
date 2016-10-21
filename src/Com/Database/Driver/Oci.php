<?php

namespace Ark\Com\Database\Driver;

use Ark\Core\Noah;
use Ark\Core\Trace;
use Ark\Core\Timer;
use Ark\Toolbox\Struct;
use Ark\Toolbox\Database;
use Ark\Contract\CacheProxy;
use Ark\Com\Cache\Proxy;
use Ark\Contract\CacheDriver;
use Ark\Contract\DatabaseDriver;
use Ark\Com\Event\Adapter as EventAdapter;

class Oci implements DatabaseDriver, CacheProxy
{

    /**
     * 连接对象实例
     *
     * @access private
     * @var resource
     */
    private $_instance;

    /**
     * 数据库取值模式
     *
     * @access private
     * @var string
     */
    private $_fetch_mode = OCI_ASSOC;

    /**
     * 事务提交模式
     *
     * @access private
     * @var int
     */
    private $_commit_mode = OCI_COMMIT_ON_SUCCESS;

    /**
     * 最近一次执行SQL语句所影响的行数
     *
     * @access private
     * @var integer
     */
    private $_row_count = 0;

    /**
     * 查询开始前的事件检验规则
     *
     * @var array
     */
    private $_rule_query_before = array(
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
    private $_rule_query_finish = array(
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
    private $_rule_query_failed = array(
        'sql'       => array(Struct::FLAG_REQUIRED=> true, Struct::FLAG_TYPE=> Struct::TYPE_STRING),
        'error'     => array(Struct::FLAG_REQUIRED=> true, Struct::FLAG_TYPE=> Struct::TYPE_STRING),
        'driver'    => array(Struct::FLAG_REQUIRED=> true, Struct::FLAG_TYPE=> Struct::TYPE_STRING),
    );

    /**
     * 构造器
     *
     * @param $dsn
     * @param array $option
     * @throws OciException
     */
    function __construct($dsn, array $option = array())
    {
        if (!function_exists('oci_connect')) {
            throw new OciException(Noah::getInstance()->language->get('db.extension_load_failed'), 'oci8');
        }
        $database = Database::parseConnectUrl($dsn);
        $dbstring = $database['host'];
        if ($database['host'] && $database['name']) {
            $database['port'] || $database['port'] = 1521;
            $dbstring = '//'. $database['host']. ':'. $database['port']. '/'. $database['name'];
        }
        Timer::mark('db_connect_begin');
        $this->_instance = oci_new_connect($database['user'], $database['pass'], $dbstring, $database['charset']);
        Timer::mark('db_connect_end');
        if (!$this->_instance) {
            throw new OciException(Noah::getInstance()->language->get('db.connect_failed'));
        }
    }

    /**
     * 执行一条SQL语句，并返回结果记录源
     *
     * @access public
     * @param string $sql
     * @param array $bind
     * @return mixed
     * @throws OciException
     */
    function _query($sql, array $bind = array())
    {
        Timer::mark('db_query_begin');
        is_string($sql) || $sql = (string)$sql;
        $resource = oci_parse($this->_instance, $sql);
        if (!$resource) {
            Trace::set('database', array($sql, sprintf('%.3fs', -1)));
            throw new OciException(Noah::getInstance()->language->get('db.parse_sql_failed'));
        }
        if ($bind) {
            foreach ($bind as $key=> &$val) {
                oci_bind_by_name($resource, $key, $val, empty($val) ? 255 : strlen($val));
            }
        }
        $result = oci_execute($resource, $this->_commit_mode);
        $this->_catch($resource, $sql);
        Timer::mark('db_query_end');
        $this->_row_count = $result ? oci_num_rows($resource) : 0;
        Trace::set('database', array($sql, sprintf('%.3fs', Timer::lastUsed())));
        return $resource;
    }

    /**
     * 执行操作，返回影响行数
     *
     * @access public
     * @param string $sql
     * @param array $bind
     * @return int
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
        $this->_query($data['sql'], $data['bind']);
        $data['result'] = $this->lastRowCount();
        $data = EventAdapter::onListening('event.query.finish', $data, $this->_rule_query_finish);
        return $data['result'];
    }

    /**
     * 执行带返回值的操作
     *
     * @access public
     * @param string $sql
     * @param array $bind
     * @return array
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
        $resource = $this->_query($data['sql'], $data['bind']);
        $result = array();
        while ($row = oci_fetch_array($resource, $this->_fetch_mode)) {
            $result[] = array_change_key_case($row, CASE_LOWER);
        }
        $data['result'] = $result;
        $data = EventAdapter::onListening('event.query.finish', $data, $this->_rule_query_finish);
        return $data['result'];
    }

    /**
     * 获取第一行第一列的值，一般用在聚合函数
     *
     * @access public
     * @param string $sql
     * @param array $bind
     * @return mixed
     */
    function fetchOne($sql, array $bind = array())
    {
        $data = array(
            'method'=> __METHOD__,
            'sql'=> (string)$sql,
            'bind'=> $bind,
            'driver'=> $this->getDriverName(),
        );
        $data = EventAdapter::onListening('event.query.before', $data, $this->_rule_query_before);
        $resource = $this->_query($data['sql'], $data['bind']);
        $result = oci_fetch_row($resource);
        $data['result'] = current($result);
        $data = EventAdapter::onListening('event.query.finish', $data, $this->_rule_query_finish);
        return $data['result'];
    }

    /**
     * 获取单行数据
     *
     * @access public
     * @param string $sql
     * @param array $bind
     * @return mixed
     */
    function fetch($sql, array $bind = array())
    {
        $data = array(
            'method'=> __METHOD__,
            'sql'=> (string)$sql,
            'bind'=> $bind,
            'driver'=> $this->getDriverName(),
        );
        $data = EventAdapter::onListening('event.query.before', $data, $this->_rule_query_before);
        $resource = $this->_query($data['sql'], $data['bind']);
        $result = array_change_key_case(oci_fetch_array($resource, $this->_fetch_mode), CASE_LOWER);
        $data['result'] = $result;
        $data = EventAdapter::onListening('event.query.finish', $data, $this->_rule_query_finish);
        return $data['result'];
    }

    /**
     * 该序列的当前值
     *
     * @access public
     * @param string $seq
     * @return integer
     */
    function lastInsertId($seq = null)
    {
        return $this->fetchOne("select $seq.currval from dual");
    }

    /**
     * 取该序列下一条数据的值
     *
     * @access public
     * @param string $seq
     * @return integer
     */
    function nextInsertId($seq = null)
    {
        return $this->fetchOne("select $seq.nextval from dual");
    }

    /**
     * 返回最近执行的SQL语句所影响到的行数
     *
     * @access public
     * @return integer
     */
    function lastRowCount()
    {
        return $this->_row_count;
    }

    /**
     * 开始事务处理
     *
     * @access public
     * @return bool
     */
    function beginTransaction()
    {
        $this->_commit_mode = OCI_NO_AUTO_COMMIT;
        return true;
    }

    /**
     * 提交当前事务
     *
     * @access public
     * @return bool
     */
    function commit()
    {
        oci_commit($this->_instance);
        $this->_commit_mode = OCI_COMMIT_ON_SUCCESS;
        return true;
    }

    /**
     * 回滚当前事务
     *
     * @access public
     * @return bool
     */
    function rollback()
    {
        oci_rollback($this->_instance);
        $this->_commit_mode = OCI_COMMIT_ON_SUCCESS;
        return true;
    }

    /**
     * 获取驱动器名称
     *
     * @access public
     * @return string
     */
    function getDriverName()
    {
        return 'Oci';
    }

    /**
     * 缓存代理
     *
     * @access public
     * @param int $expire
     * @param null $name
     * @param CacheDriver $cache
     * @return Oci
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
     * @return \Ark\Toolbox\SQLBuilder\Select\Oci
     */
    function select()
    {
        $instance = new \Ark\Toolbox\SQLBuilder\Select\Oci();
        return $instance->invoke($this);
    }

    /**
     * update对象
     *
     * @access public
     * @return \Ark\Toolbox\SQLBuilder\Update\Oci()
     */
    function update()
    {
        $instance = new \Ark\Toolbox\SQLBuilder\Update\Oci();
        return $instance->invoke($this);
    }

    /**
     * insert对象
     *
     * @access public
     * @return \Ark\Toolbox\SQLBuilder\Insert\Oci
     */
    function insert()
    {
        $instance = new \Ark\Toolbox\SQLBuilder\Insert\Oci();
        return $instance->invoke($this);
    }

    /**
     * delete对象
     *
     * @access public
     * @return \Ark\Toolbox\SQLBuilder\Delete\Oci
     */
    function delete()
    {
        $instance = new \Ark\Toolbox\SQLBuilder\Delete\Oci();
        return $instance->invoke($this);
    }

    /**
     * expr表达式对象
     *
     * @access public
     * @param $expr
     * @return Expr
     */
    function expr($expr)
    {
        return new Expr($expr);
    }

    /**
     * 捕捉数据库运行时错误
     *
     * @access private
     * @param resource $resource
     * @param string $sql
     * @return null
     * @throws OciException
     */
    private function _catch($resource = null, $sql = null)
    {
        if ($error = oci_error($resource)) {
            $data = array(
                'sql'=> $sql,
                'error'=> $error['message'],
                'driver'=> $this->getDriverName(),
            );
            $data = EventAdapter::onListening('event.query.failed', $data, $this->_rule_query_failed);
            throw new OciException($data['error']);
        }
    }

}
<?php

namespace Ark\Database\Querier;

use Ark\Core\Captain;
use Ark\Database\Toolkit;
use Ark\Cache\Driver as CacheDriver;
use Ark\Database\Driver as DatabaseDriver;
use Ark\Database\Exception;

abstract class Father
{

    /**
     * 当前数据库类型
     *
     * @var string
     */
    protected $_db_type;

    /**
     * 语句组成部分初始值
     *
     * @access protected
     * @var array
     */
    protected $_parts = array();

    /**
     * 数据库对象实例
     *
     * @access protected
     * @var DatabaseDriver
     */
    protected $_db;

    /**
     * SQL绑定参数
     *
     * @var array
     */
    protected $_db_bind = array();

    /**
     * 当前SQL语句是否需要缓存
     *
     * @access protected
     * @var boolean
     */
    protected $_need_cache = false;

    /**
     * 缓存过期时间
     *
     * @access protected
     * @var integer
     */
    protected $_cache_expire = 86400;

    /**
     * 缓存名称
     *
     * @var string
     */
    protected $_cache_name = null;

    /**
     * 缓存引擎名称
     *
     * @access protected
     * @var CacheDriver
     */
    protected $_cache_adapter;

    /**
     * 设置缓存代理
     *
     * @access public
     * @param integer $expire
     * @param null $name
     * @param CacheDriver $cache
     * @return Father
     */
    function cache($expire, $name, CacheDriver $cache)
    {
        $this->_need_cache = true;
        $this->_cache_expire = $expire;
        $this->_cache_name = $name;
        $this->_cache_adapter = $cache;
        return $this;
    }

    /**
     * 引用数据库对象
     *
     * @access public
     * @param DatabaseDriver $db
     * @return mixed
     */
    function invoke(DatabaseDriver $db)
    {
        $this->_db = $db;
        return $this;
    }

    /**
     * 查询条件
     *
     * @access public
     * @param string $cond
     * @return Select
     */
    function where($cond)
    {
        $values = func_get_args();
        array_shift($values);
        $this->_parts['where'][] = array(array('cond'=> $cond, 'val'=> $values), null);
        return $this;
    }

    /**
     * and查询
     *
     * @param $cond
     * @return Select
     */
    function andWhere($cond)
    {
        $values = func_get_args();
        array_shift($values);
        $this->_parts['where'][] = array(array('cond'=> $cond, 'val'=> $values), true);
        return $this;
    }

    /**
     * OR查询
     *
     * @param $cond
     * @return Select
     */
    function orWhere($cond)
    {
        $values = func_get_args();
        array_shift($values);
        $this->_parts['where'][] = array(array('cond'=> $cond, 'val'=> $values), false);
        return $this;
    }

    /**
     * 获取where片段
     *
     * @access public
     * @return string
     */
    function pickWherePart()
    {
        $where = array();
        if ($where_part = $this->_parts['where']) {
            foreach ($where_part as $key=> $val) {
                $part = '';
                if (!is_null($val[1])) {
                    $part.= $val[1] ? ' AND ' : ' OR ';
                }
                $cond = $val[0]['cond'];
                $value = $val[0]['val'];
                if (is_null($value)) {
                    $part = $cond;
                    if ($cond instanceof self) {
                        $part.= '(' . $cond->pickWherePart() . ')';
                    }
                } else {
                    $part.= $this->_parseExpr($cond, $value);
                }
                $where[] = $part;
            }
        }
        return $where ? implode(' ', $where) : null;
    }

    /**
     * 调用数据库fetch方法
     *
     * @access public
     * @return string
     * @throws Exception
     */
    function fetch()
    {
        if (!$this->_db) {
            throw new Exception(Captain::getInstance()->lang->get('tbox.no_db_instance'));
        }
        $instance = $this->_db;
        if ($this->_need_cache) {
            $instance = $instance->cache($this->_cache_expire, $this->_cache_name, $this->_cache_adapter);
        }
        return $instance->fetch($this->getSQL(), $this->_db_bind);
    }

    /**
     * 调用数据库fetchAll方法
     *
     * @access public
     * @return string
     * @throws Exception
     */
    function fetchAll()
    {
        if (!$this->_db) {
            throw new Exception(Captain::getInstance()->lang->get('tbox.no_db_instance'));
        }
        $instance = $this->_db;
        if ($this->_need_cache) {
            $instance = $instance->cache($this->_cache_expire, $this->_cache_name, $this->_cache_adapter);
        }
        return $instance->fetchAll($this->getSQL(), $this->_db_bind);
    }

    /**
     * 调用数据库fetchOne方法
     *
     * @access public
     * @return string
     * @throws Exception
     */
    function fetchOne()
    {
        if (!$this->_db) {
            throw new Exception(Captain::getInstance()->lang->get('tbox.no_db_instance'));
        }
        $instance = $this->_db;
        if ($this->_need_cache) {
            $instance = $instance->cache($this->_cache_expire, $this->_cache_name, $this->_cache_adapter);
        }
        return $instance->fetchOne($this->getSQL(), $this->_db_bind);
    }

    /**
     * 调用数据库query方法
     *
     * @access public
     * @return string
     * @throws Exception
     */
    function query()
    {
        if (!$this->_db) {
            throw new Exception(Captain::getInstance()->lang->get('tbox.no_db_instance'));
        }
        $instance = $this->_db;
        if ($this->_need_cache) {
            $instance = $instance->cache($this->_cache_expire, $this->_cache_name, $this->_cache_adapter);
        }
        return $instance->query($this->getSQL(), $this->_db_bind);
    }

    /**
     * 获取SQL
     *
     * @return string
     */
    function getSQL()
    {
        return '';
    }

    /**
     * 返回完全的SQL语句
     *
     * @return string
     */
    function getRealSQL()
    {
        $sql = $this->getSQL();
        $bind = $this->getBind();
        foreach ($bind as $key=> $val) {
            $sql = preg_replace('/'. $key. '/', $val, $sql, 1);
        }
        return $sql;
    }

    /**
     * 获取绑定参数
     *
     * @return array
     */
    function getBind()
    {
        return $this->_db_bind;
    }

    /**
     * 字符串化
     *
     * @access public
     * @return string
     */
    function __toString()
    {
        return $this->getSQL();
    }

    /**
     * 解析表达式中的值
     *
     * @access public
     * @abstract
     * @param string $expr
     * @param mixed $value
     * @return string
     */
    protected function _parseExpr($expr, $value = null)
    {
        $pattern = '/(\?|\:[\w\d]+)/';
        if (preg_match_all($pattern, $expr, $matches)) {
            $matches = $matches[1];
            foreach ($matches as $k=> $v) {
                if ($v == '?') {
                    $val = $value;
                    if (is_array($value)) {
                        $val = $value[$k];
                    }
                    if ($val instanceof self) {
                        $val = $val->getRealSQL();
                    } elseif (preg_match('/^\{\{.*?\}\}$/', $val) || preg_match('/.*?\(.*?\)/', $val)) {
                        $val = str_replace(array('{{', '}}'), '', $val);
                    } else {
                        $val = Toolkit::quote($val, $this->_db_type);
                    }
                    $expr = preg_replace('/\?/', $val, $expr, 1);
                } else {
                    $val = $value;
                    if (is_array($value)) {
                        $val = $value[$k];
                    }
                    if ($val instanceof self) {
                        $val = $val->getRealSQL();
                        $expr = preg_replace("/$v/", $val, $expr, 1);
                    } elseif (preg_match('/^\{\{.*?\}\}$/', $val) || preg_match('/.*?\(.*?\)/', $val)) {
                        $val = str_replace(array('{{', '}}'), '', $val);
                        $expr = preg_replace("/$v/", $val, $expr, 1);
                    } else {
                        $val = Toolkit::quote($val, $this->_db_type);
                        $this->_db_bind[$v] = $val;
                    }
                }
            }
        }
        return $expr;
    }

}
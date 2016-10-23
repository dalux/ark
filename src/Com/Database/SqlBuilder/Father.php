<?php

namespace Ark\Com\Database\SqlBuilder;

use Ark\Core\Noah;
use Ark\Core\Sailor;
use Ark\Contract\CacheProxy;
use Ark\Com\Database\Toolkit;
use Ark\Contract\CacheDriver;
use Ark\Contract\DatabaseDriver;
use Ark\Toolbox\RuntimeException;

abstract class Father extends Sailor implements CacheProxy
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
     * @var DatabaseDriver|CacheProxy
     */
    protected $_db;

    /**
     * 当前数据库对象是否允许缓存
     *
     * @access protected
     * @var boolean
     */
    protected $_allow_cache = false;

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
        //当前数据库对象是否可以被缓存
        if ($this->_db instanceof CacheProxy) {
            $this->_allow_cache = true;
        }
        return $this;
    }

    /**
     * 查询条件
     *
     * @access public
     * @param string $cond
     * @param mixed $value
     * @param bool $and
     * @return Father
     */
    function where($cond, $value = null, $and = true)
    {
        if (is_null($value)
            || $cond instanceof self) {
            $_part = $cond;
        } else {
            $_part = $this->_parseExpr($cond, $value);
        }
        $this->_parts['where'][] = array($_part, $and);
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
            foreach ($where_part as $k=> $v) {
                if ($v[0] instanceof self) {
                    $v[0] = '('. $v[0]->pickWherePart(). ')';
                }
                $tmp = $v[0];
                if ($where_part[$k+1]) {
                    $tmp.= $v[1] ? ' AND ' : ' OR ';
                }
                $where[] = $tmp;
            }
        }
        return $where ? implode(' ', $where) : null;
    }

    /**
     * 调用数据库fetch方法
     *
     * @access public
     * @param array $bind
     * @return string
     * @throws RuntimeException
     */
    function fetchRow($bind = array())
    {
        if (!$this->_db) {
            throw new RuntimeException(Noah::getInstance()->language->get('tbox.no_db_instance'));
        }
        $instance = $this->_db;
        if ($this->_allow_cache && $this->_need_cache) {
            $instance = $instance->cache($this->_cache_expire, $this->_cache_name, $this->_cache_adapter);
        }
        return $instance->fetch($this->getSQL(), $bind);
    }

    /**
     * 调用数据库fetchAll方法
     *
     * @access public
     * @param array $bind
     * @return string
     * @throws RuntimeException
     */
    function fetchAll($bind = array())
    {
        if (!$this->_db) {
            throw new RuntimeException(Noah::getInstance()->language->get('tbox.no_db_instance'));
        }
        $instance = $this->_db;
        if ($this->_allow_cache && $this->_need_cache) {
            $instance = $instance->cache($this->_cache_expire, $this->_cache_name, $this->_cache_adapter);
        }
        return $instance->fetchAll($this->getSQL(), $bind);
    }

    /**
     * 调用数据库fetchOne方法
     *
     * @access public
     * @param array $bind
     * @return string
     * @throws RuntimeException
     */
    function fetchScalar($bind = array())
    {
        if (!$this->_db) {
            throw new RuntimeException(Noah::getInstance()->language->get('tbox.no_db_instance'));
        }
        $instance = $this->_db;
        if ($this->_allow_cache && $this->_need_cache) {
            $instance = $instance->cache($this->_cache_expire, $this->_cache_name, $this->_cache_adapter);
        }
        return $instance->fetchOne($this->getSQL(), $bind);
    }

    /**
     * 调用数据库query方法
     *
     * @access public
     * @param array $bind
     * @return string
     * @throws RuntimeException
     */
    function query($bind = array())
    {
        if (!$this->_db) {
            throw new RuntimeException(Noah::getInstance()->language->get('tbox.no_db_instance'));
        }
        $instance = $this->_db;
        if ($this->_allow_cache && $this->_need_cache) {
            $instance = $instance->cache($this->_cache_expire, $this->_cache_name, $this->_cache_adapter);
        }
        return $instance->query($this->getSQL(), $bind);
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
     * 输出当前SQL语句到屏显
     *
     * @return null
     */
    function showSQL()
    {
        echo $this->getSQL(). PHP_EOL;
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
        $pattern = '/(\?|:int:|:integer:|:float:|:double:|:string:|:str:|:float\.(\d):|:double\.(\d):|:bool:|:boolean:)/';
        if (preg_match_all($pattern, $expr, $matches)) {
            $matches = $matches[1];
            foreach ($matches as $k=> $v) {
                if ($v == '?') {
                    if (is_object($value) && $value instanceof self) {
                        $value = $value->getSQL();
                    } elseif (preg_match('/^\{\{.*?\}\}$/', $value) || preg_match('/.*?\(.*?\)/', $value)) {
                        $value = str_replace(array('{{', '}}'), '', $value);
                    } else {
                        $value = Toolkit::quote($value, $this->_db_type);
                    }
                    $expr = preg_replace('/\?/', $value, $expr, 1);
                } elseif ($v == ':int:' || $v == ':integer:') {
                    $expr = preg_replace('/:(int|integer):/', (int)$value, $expr, 1);
                } elseif ($v == ':float:' || $v == ':double:') {
                    $expr = preg_replace('/:(float|double):/', (float)$value, $expr, 1);
                } elseif ($v == ':string:' || $v == ':str:') {
                    $expr = preg_replace('/:(string|str):/', Toolkit::quote($value, $this->_db_type), $expr, 1);
                } elseif (preg_match('/:(float|double)\.(\d):/', $v)) {
                    $expr = preg_replace('/:(float|double)\.(\d):/e', "number_format(floatval('$value'), $2, '.', '')", $expr, 1);
                } elseif ($v == ':bool:' || $v == ':boolean:') {
                    $expr = preg_replace('/:(bool|boolean):/', (bool)$value ? 1 : 0, $expr, 1);
                }
            }
        }
        return $expr;
    }

}
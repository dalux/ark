<?php

namespace Ark\Toolkit;

use Ark\Contract\Cache;
use Ark\Contract\Database;
use Ark\Assembly\Proxy\Cache as Proxy;

class Querier
{

    /**
     * 当前表名
     *
     * @var string
     */
    protected $_tb;

    /**
     * 数据库连接配置
     *
     * @var Database
     */
    protected $_db;

    /**
     * 缓存时间
     *
     * @var int
     */
    protected $_expire;

    /**
     * 缓存结果名称
     *
     * @var string
     */
    protected $_cache_name;

    /**
     * 缓存代理
     *
     * @var Proxy
     */
    protected $_proxy;

    /**
     * 条件标记列表
     *
     * @var array
     */
    protected $_where_mark = array(
        '='         => ' = ',
        'EQ'        => ' = ',       //等于
        '!='        => ' != ',
        'NEQ'       => ' != ',      //不等于
        '>'         => '>',
        'GT'        => ' > ',       //大于
        '>='        => ' >= ',
        'GTE'       => ' >= ',      //大于等于
        '<'         => ' < ',
        'LT'        => ' < ',       //小于
        '<='        => ' <= ',
        'LTE'       => ' <= ',      //小于等于
        'LIKE'      => ' LIKE ',
        'NOTLIKE'   => ' NOT LIKE ',
        'BETWEEN'   => ' BETWEEN ',
        'IN'        => ' IN ',
        'NOTIN'     => ' NOT IN ',
        'IS'        => ' IS ',
        'ISNOT'     => ' IS NOT '
    );

    /**
     * 构造器
     *
     * @param $table
     * @param Database $db
     */
    function __construct(Database $db)
    {
        $this->setDb($db);
    }

    /**
     * 静态方法初始化
     *
     * @param $table
     * @param Database $db
     * @return Querier
     */
    static function init(Database $db)
    {
        return new self($db);
    }

    /**
     * 构造器
     *
     * @param $table
     * @param $db
     * @throws DDatabase_exception
     */
    function invoke($table)
    {
        $this->_tb = $table;
        return $this;
    }

    /**
     * 设置数据库驱动器
     *
     * @param Database $db
     * @return $this
     */
    function setDb(Database $db)
    {
        $this->_db = $db;
        return $this;
    }

    /**
     * 缓存代理
     *
     * @access public
     * @param int $expire
     * @param null $name
     * @param Cache $cache
     * @return Querier
     */
    function cache($expire, $name, Cache $cache)
    {
        $this->_proxy = new Proxy();
        $this->_proxy->setCacher($cache);
        $this->_expire = $expire;
        $this->_cache_name = $name;
        return $this;
    }

    /**
     * 新增数据
     *
     * @access public
     * @final
     * @param array $data 数据键值对数组
     * @param bool $return_primarykey 是否返回新增的ID主键
     * @return mixed
     */
    function insert(array $data, $return_primarykey = false)
    {
        $insert = SQLBuilder::insert($this->_db->getDriverName())->into($this->_tb, $data);
        $added = $this->_db->query($insert);
        return $added ? ($return_primarykey ? $this->_db->lastInsertId() : true) : false;
    }

    /**
     * 编辑数据
     *
     * @access public
     * @final
     * @param array $data 数据键值对
     * @param array $condition 编辑条件
     * @return integer
     */
    function update(array $data, array $condition)
    {
        $update = SQLBuilder::update($this->_db->getDriverName())->set($this->_tb, $data);
        foreach ($condition as $k=> $v) {
            if (is_array($v)) {
                $kk = strtoupper(current(array_keys($v)));
                $vv = current($v);
                if ($this->_where_mark[$kk] && $vv) {
                    if (preg_match('/^(IS|ISNOT)$/i', $kk)) {
                        $update->where($k . $this->_where_mark[$kk] . $vv);
                    } elseif (preg_match('/^(BETWEEN)$/i', $kk) && $vv[0] && $vv[1]) {
                        $update->where($k . $this->_where_mark[$kk] . $vv[0] . ' AND ' . $vv[1]);
                    } elseif (preg_match('/^(IN|NOTIN)$/i', $kk)) {
                        $vv = SQLBuilder::quote($vv);
                        $update->where($k . $this->_where_mark[$kk] . '('.$vv.')');
                    } else {
                        $update->where($k . $this->_where_mark[$kk] . ' ?', $vv);
                    }
                    continue;
                }
            }
            $update->whereIn($k, $v);
        }
        return $this->_db->query($update);
    }

    /**
     * 删除表数据
     *
     * @access public
     * @final
     * @param array $condition 删除条件
     * @return int
     */
    function delete(array $condition = array())
    {
        $delete = SQLBuilder::delete($this->_db->getDriverName())->from($this->_tb);
        foreach ($condition as $k=> $v) {
            if (is_array($v)) {
                $kk = strtoupper(current(array_keys($v)));
                $vv = current($v);
                if ($this->_where_mark[$kk] && $vv) {
                    if (preg_match('/^(IS|ISNOT)$/i', $kk)) {
                        $delete->where($k . $this->_where_mark[$kk] . $vv);
                    } elseif (preg_match('/^(BETWEEN)$/i', $kk) && $vv[0] && $vv[1]) {
                        $delete->where($k . $this->_where_mark[$kk] . $vv[0] . ' AND ' . $vv[1]);
                    } elseif (preg_match('/^(IN|NOTIN)$/i', $kk)) {
                        $vv = SQLBuilder::quote($vv);
                        $delete->where($k . $this->_where_mark[$kk] . '('.$vv.')');
                    } else {
                        $delete->where($k . $this->_where_mark[$kk] . ' ?', $vv);
                    }
                    continue;
                }
            }
            $delete->whereIn($k, $v);
        }
        return $this->_db->query($delete);
    }


    /**
     * 取单行数据值
     *
     * @access protected
     * @final
     * @param array $condition 取值条件
     * @param array $fields 取值字段
     * @return array
     */
    function fetch($condition = array(), $fields = array('*'))
    {
        $select = SQLBuilder::select($this->_db->getDriverName())->from($this->_tb, $fields);
        foreach ($condition as $k=> $v) {
            if (is_array($v)) {
                $kk = strtoupper(current(array_keys($v)));
                $vv = current($v);
                if ($this->_where_mark[$kk] && $vv) {
                    if (preg_match('/^(IS|ISNOT)$/i', $kk)) {
                        $select->where($k . $this->_where_mark[$kk] . $vv);
                    } elseif (preg_match('/^(BETWEEN)$/i', $kk) && $vv[0] && $vv[1]) {
                        $select->where($k . $this->_where_mark[$kk] . $vv[0] . ' AND ' . $vv[1]);
                    } elseif (preg_match('/^(IN|NOTIN)$/i', $kk)) {
                        $vv = SQLBuilder::quote($vv);
                        $select->where($k . $this->_where_mark[$kk] . '('.$vv.')');
                    } else {
                        $select->where($k . $this->_where_mark[$kk] . ' ?', $vv);
                    }
                    continue;
                }
            }
            $select->whereIn($k, $v);
        }
        if (!is_null($this->_expire)) {
            return $this->_proxy->doProxy($this->_db, 'fetch', array('sql'=> (string)$select), $this->_expire, $this->_cache_name);
        }
        return $this->_db->fetch($select);
    }

    /**
     * 取聚合函数结果值
     *
     * @access protected
     * @final
     * @param array $condition
     * @param array $fields
     * @return mixed
     */
    function fetchOne($condition = array(), $fields = array('count(*)'))
    {
        $select = SQLBuilder::select($this->_db->getDriverName())->from($this->_tb, $fields);
        foreach ($condition as $k=> $v) {
            if (is_array($v)) {
                $kk = strtoupper(current(array_keys($v)));
                $vv = current($v);
                if ($this->_where_mark[$kk] && $vv) {
                    if (preg_match('/^(IS|ISNOT)$/i', $kk)) {
                        $select->where($k . $this->_where_mark[$kk] . $vv);
                    } elseif (preg_match('/^(BETWEEN)$/i', $kk) && $vv[0] && $vv[1]) {
                        $select->where($k . $this->_where_mark[$kk] . $vv[0] . ' AND ' . $vv[1]);
                    } elseif (preg_match('/^(IN|NOTIN)$/i', $kk)) {
                        $vv = SQLBuilder::quote($vv);
                        $select->where($k . $this->_where_mark[$kk] . '('.$vv.')');
                    } else {
                        $select->where($k . $this->_where_mark[$kk] . ' ?', $vv);
                    }
                    continue;
                }
            }
            $select->whereIn($k, $v);
        }
        if (!is_null($this->_expire)) {
            return $this->_proxy->doProxy($this->_db, 'fetchOne', array('sql'=> (string)$select), $this->_expire, $this->_cache_name);
        }
        return $this->_db->fetchOne($select);
    }

    /**
     * 取多行数据结果
     *
     * @access protected
     * @final
     * @param array $condition
     * @param array $order
     * @param int $count
     * @param int $offset
     * @param array $fields
     * @return array
     */
    function fetchAll($condition = array(), $order = array(), $count = 0, $offset = 0, $fields = array('*'))
    {
        $select = SQLBuilder::select($this->_db->getDriverName())->from($this->_tb, $fields)->limit($count, $offset);
        foreach ($order as $k=> $v) {
            $select->order($k, $v);
        }
        foreach ($condition as $k => $v) {
            if (is_array($v)) {
                $kk = strtoupper(current(array_keys($v)));
                $vv = current($v);
                if ($this->_where_mark[$kk] && $vv) {
                    if (preg_match('/^(IS|ISNOT)$/i', $kk)) {
                        $select->where($k . $this->_where_mark[$kk] . $vv);
                    } elseif (preg_match('/^(BETWEEN)$/i', $kk) && $vv[0] && $vv[1]) {
                        $select->where($k . $this->_where_mark[$kk] . $vv[0] . ' AND ' . $vv[1]);
                    } elseif (preg_match('/^(IN|NOTIN)$/i', $kk)) {
                        $vv = SQLBuilder::quote($vv);
                        $select->where($k . $this->_where_mark[$kk] . '('.$vv.')');
                    } else {
                        $select->where($k . $this->_where_mark[$kk] . ' ?', $vv);
                    }
                    continue;
                }
            }
            $select->whereIn($k, $v);
        }
        if (!is_null($this->_expire)) {
            return $this->_proxy->doProxy($this->_db, 'fetchAll', array('sql'=> (string)$select), $this->_expire, $this->_cache_name);
        }
        return $this->_db->fetchAll($select);
    }

}
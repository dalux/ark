<?php

namespace Ark\Database;

use Ark\Core\Sailor;
use Ark\Cache\Driver as CacheDriver;
use Ark\Database\Driver as DatabaseDriver;

class Mapper extends Sailor
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
     * @var DatabaseDriver
     */
    protected $_db;

    /**
     * 缓存时间
     *
     * @var int
     */
    protected $_expire;

    /**
     * 缓存引擎配置名称
     *
     * @var CacheDriver
     */
    protected $_cache;

    /**
     * 缓存结果名称
     *
     * @var string
     */
    protected $_cache_name;

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
     * @param DatabaseDriver $db
     */
    function __construct($table, DatabaseDriver $db)
    {
        $this->_tb = $table;
        $this->_db = $db;
    }

    /**
     * 缓存代理
     *
     * @access public
     * @param int $expire
     * @param null $name
     * @param CacheDriver $cache
     * @return Mapper
     */
    function cache($expire, $name, CacheDriver $cache)
    {
        $this->_expire = $expire;
        $this->_cache = $cache;
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
        $added = $this->_db
            ->insert()
            ->into($this->_tb, array_keys($data))
            ->values(array_values($data))
            ->query();
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
        $update = $this->_db
            ->update()
            ->set($this->_tb, $data);
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
                        $vv = Toolkit::quote($vv, $this->_db->getDriverName());
                        $update->where($k . $this->_where_mark[$kk] . '('.$vv.')');
                    } else {
                        $update->where($k . $this->_where_mark[$kk] . ' ?', $vv);
                    }
                    continue;
                }
            }
            $update->whereIn($k, $v);
        }
        return $update->query();
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
        $delete = $this->_db
            ->delete()
            ->from($this->_tb);
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
                        $vv = Toolkit::quote($vv, $this->_db->getDriverName());
                        $delete->where($k . $this->_where_mark[$kk] . '('.$vv.')');
                    } else {
                        $delete->where($k . $this->_where_mark[$kk] . ' ?', $vv);
                    }
                    continue;
                }
            }
            $delete->whereIn($k, $v);
        }
        return $delete->query();
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
    function fetchRow($condition = array(), $fields = array('*'))
    {
        $select = $this->_db
            ->select()
            ->from($this->_tb, $fields);
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
                        $vv = Toolkit::quote($vv, $this->_db->getDriverName());
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
            $select->cache($this->_expire, $this->_cache_name, $this->_cache);
        }
        return $select->fetchRow();
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
    function fetchScalar($condition = array(), $fields = array('count(*)'))
    {
        $select = $this->_db
            ->select()
            ->from($this->_tb, $fields);
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
                        $vv = Toolkit::quote($vv, $this->_db->getDriverName());
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
            $select->cache($this->_expire, $this->_cache_name, $this->_cache);
        }
        return $select->fetchScalar();
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
        $select = $this->_db
            ->select()
            ->from($this->_tb, $fields)
            ->limit($count, $offset);
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
                        $vv = Toolkit::quote($vv, $this->_db->getDriverName());
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
            $select->cache($this->_expire, $this->_cache_name, $this->_cache);
        }
        return $select->fetchAll();
    }

}
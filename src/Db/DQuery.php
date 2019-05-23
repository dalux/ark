<?php

namespace Brisk\Db;

use Brisk\Kernel\Language;
use Brisk\Cache\CacheProxy;
use Brisk\Cache\CacheFather;
use Brisk\Exception\RuntimeException;
use Brisk\Kernel\Toolkit;

class DQuery
{

    /**
     * @var DbFather
     */
    private $_conn = null;

    /**
     * @var string
     */
    private $_tb;

    /**
     * @var int
     */
    private $_expire;

    /**
     * @var string
     */
    private $_cache_name;

    /**
     * @var CacheProxy
     */
    private $_proxy;

    /**
     * @var array
     */
    private $_where_mark = [
        '='         => ' = ',
        'EQ'        => ' = ',
        '!='        => ' != ',
        'NEQ'       => ' != ',
        '>'         => '>',
        'GT'        => ' > ',
        '>='        => ' >= ',
        'GTE'       => ' >= ',
        '<'         => ' < ',
        'LT'        => ' < ',
        '<='        => ' <= ',
        'LTE'       => ' <= ',
        'LIKE'      => ' LIKE ',
        'NOTLIKE'   => ' NOT LIKE ',
        'BETWEEN'   => ' BETWEEN ',
        'IN'        => ' IN ',
        'NOTIN'     => ' NOT IN ',
        'IS'        => ' IS ',
        'ISNOT'     => ' IS NOT '
    ];

    /**
     * Setting database connection objects
     *
     * @param DbFather $conn
     * @param null $table
     * @return $this
     */
    public static function open(DbFather $conn, $table = null)
    {
        return new self($conn, $table);
    }

    /**
     * Get database connection objects
     *
     * @return DbFather
     */
    public function getConn()
    {
        return $this->_conn;
    }

    /**
     * Construct
     *
     * @param DbFather $conn
     * @param null $table
     */
    private function __construct(DbFather $conn, $table = null)
    {
        $this->_conn = $conn;
        $this->_tb = $table;
        if (is_null($this->_conn)) {
            throw new RuntimeException(Language::get('db.invalid_connection_object'));
        }
    }

    /**
     * Set the table that you want to operate on
     *
     * @param string tb
     * @return DQuery
     */
    public function table($tb)
    {
        $this->_tb = $tb;
        return $this;
    }

    /**
     * Set Cache proxy
     *
     * @param int $expire
     * @param CacheFather $cache
     * @param string $name
     * @return DQuery
     */
    public function cache($expire, CacheFather $cache, $name = null)
    {
        $this->_expire = $expire;
        $this->_cache_name = $name;
        $this->_proxy = new CacheProxy();
        $this->_proxy->setCacheDriver($cache);
        return $this;
    }

    /**
     * 获取上一次插入的ID
     *
     * @param string|null $seq
     * @return int
     */
    public function getLastInsertId($seq = null)
    {
        return $this->_conn->lastInsertId($seq);
    }

    /**
     * 获取上一次SQL执行影响的行数
     *
     * @return int
     */
    public function getLastRowCount()
    {
        return $this->_conn->lastRowCount();
    }

    /**
     * Insert new data
     *
     * @param array data
     * @param bool return_id
     * @return bool
     */
    public function insert(array $data)
    {
        if (!$this->_tb) {
            throw new RuntimeException(Language::get('db.invalid_table_name'));
        }
        $insert = $this->_conn->insert()->into($this->_tb, $data);
        return $this->_conn->query($insert->getRealSQL());
    }

    /**
     * Update data with condition
     *
     * @param array data
     * @param array condition
     * @return bool
     */
    public function update(array $data, array $condition)
    {
        if (!$this->_tb) {
            throw new RuntimeException(Language::get('db.invalid_table_name'));
        }
        $update = $this->_conn->update()->set($this->_tb, $data);
        foreach ($condition as $k=> $v) {
            if (is_array($v)) {
                $kk = strtoupper(current(array_keys($v)));
                $vv = current($v);
                if ($this->_where_mark[$kk] && $vv != '') {
                    if (preg_match('/^(IS|ISNOT)/i', $kk)) {
                        $update->where($k. $this->_where_mark[$kk]. $vv);
                    } elseif (preg_match('/^(BETWEEN)/i', $kk) && $vv[0] != '' && $vv[1] != '') {
                        $update->where($k. $this->_where_mark[$kk]. $vv[0] . ' AND ' . $vv[1]);
                    } elseif (preg_match('/^(IN|NOTIN)/i', $kk)) {
                        $vv = $update->quote($vv);
                        $update->where($k. $this->_where_mark[$kk]. '('. $vv. ')');
                    } else {
                        $update->where($k. $this->_where_mark[$kk]. ' ?', $vv);
                    }
                    continue;
                }
            }
            $update->whereIn($k, $v);
        }
        return $this->_conn->query($update->getRealSQL());
    }

    /**
     * Delete data
     *
     * @param array condition
     * @return bool
     */
    public function delete(array $condition)
    {
        if (!$this->_tb) {
            throw new RuntimeException(Language::get('db.invalid_table_name'));
        }
        $delete = $this->_conn->delete()->from($this->_tb);
        foreach ($condition as $k=> $v) {
            if (is_array($v)) {
                $kk = strtoupper(current(array_keys($v)));
                $vv = current($v);
                if ($this->_where_mark[$kk] && $vv != '') {
                    if (preg_match('/^(IS|ISNOT)/i', $kk)) {
                        $delete->where($k. $this->_where_mark[$kk]. $vv);
                    } elseif (preg_match('/^(BETWEEN)/i', $kk) && $vv[0] != '' && $vv[1] != '') {
                        $delete->where($k. $this->_where_mark[$kk]. $vv[0]. ' AND '. $vv[1]);
                    } elseif (preg_match('/^(IN|NOTIN)/i', $kk)) {
                        $vv = $delete->quote($vv);
                        $delete->where($k. $this->_where_mark[$kk]. '('. $vv. ')');
                    } else {
                        $delete->where($k. $this->_where_mark[$kk]. ' ?', $vv);
                    }
                    continue;
                }
            }
            $delete->whereIn($k, $v);
        }
        return $this->_conn->query($delete->getRealSQL());
    }

    /**
     * Get single-row data
     *
     * @param array condition
     * @param array fields
     * @return array
     */
    public function fetchRow(array $condition, array $fields = ['*'])
    {
        if (!$this->_tb) {
            throw new RuntimeException(Language::get('db.invalid_table_name'));
        }
        $select = $this->_conn->select()->from($this->_tb, $fields);
        foreach ($condition as $k=> $v) {
            if (is_array($v)) {
                $kk = strtoupper(current(array_keys($v)));
                $vv = current($v);
                if ($this->_where_mark[$kk] && $vv != '') {
                    if (preg_match('/^(IS|ISNOT)/i', $kk)) {
                        $select->where($k. $this->_where_mark[$kk]. $vv);
                    } elseif (preg_match('/^(BETWEEN)/i', $kk) && $vv[0] != '' && $vv[1] != '') {
                        $select->where($k. $this->_where_mark[$kk]. $vv[0]. ' AND '. $vv[1]);
                    } elseif (preg_match('/^(IN|NOTIN)/i', $kk)) {
                        $vv = $select->quote($vv);
                        $select->where($k. $this->_where_mark[$kk]. '('. $vv. ')');
                    } else {
                        $select->where($k. $this->_where_mark[$kk]. ' ?', $vv);
                    }
                    continue;
                }
            }
            $select->whereIn($k, $v);
        }
        if (!is_null($this->_expire)) {
            return $this->_proxy->doProxy($this->_conn, 'fetchRow', ['sql'=> $select->getRealSQL()], $this->_expire, $this->_cache_name);
        }
        return $this->_conn->fetchRow($select->getRealSQL());
    }

    /**
     * Get single-row and single-colume data
     *
     * @param array condition
     * @param array fields
     * @return int
     */
    public function fetchOne(array $condition = [], array $fields = ['*'])
    {
        if (!$this->_tb) {
            throw new RuntimeException(Language::get('db.invalid_table_name'));
        }
        $select = $this->_conn->select()->from($this->_tb, $fields);
        foreach ($condition as $k=> $v) {
            if (is_array($v)) {
                $kk = strtoupper(current(array_keys($v)));
                $vv = current($v);
                if ($this->_where_mark[$kk] && $vv != '') {
                    if (preg_match('/^(IS|ISNOT)/i', $kk)) {
                        $select->where($k. $this->_where_mark[$kk]. $vv);
                    } elseif (preg_match('/^(BETWEEN)/i', $kk) && $vv[0] != '' && $vv[1] != '') {
                        $select->where($k. $this->_where_mark[$kk]. $vv[0]. ' AND '. $vv[1]);
                    } elseif (preg_match('/^(IN|NOTIN)/i', $kk)) {
                        $vv = $select->quote($vv);
                        $select->where($k. $this->_where_mark[$kk]. '('. $vv. ')');
                    } else {
                        $select->where($k. $this->_where_mark[$kk]. ' ?', $vv);
                    }
                    continue;
                }
            }
            $select->whereIn($k, $v);
        }
        if (!is_null($this->_expire)) {
            return $this->_proxy->doProxy($this->_conn, 'fetchOne', ['sql'=> $select->getRealSQL()], $this->_expire, $this->_cache_name);
        }
        return $this->_conn->fetchOne($select->getRealSQL());
    }

    /**
     * Get multiple rows of data
     *
     * @param array condition
     * @param array order
     * @param int count
     * @param int offset
     * @param array fields
     * @return array
     */
    public function fetchAll(array $condition = [], array $order = [], $count = 0, $offset = 0, array $fields = ['*'])
    {
        if (!$this->_tb) {
            throw new RuntimeException(Language::get('db.invalid_table_name'));
        }
        $select = $this->_conn->select()->from($this->_tb, $fields)->limit($count, $offset);
        if(!is_null($order) && !empty($order)){
            foreach ($order as $k=> $v) {
                $select->order($k, $v);
            }
        }
        foreach ($condition as $k=> $v) {
            if (is_array($v)) {
                $kk = strtoupper(current(array_keys($v)));
                $vv = current($v);
                if ($this->_where_mark[$kk] && $vv != '') {
                    if (preg_match('/^(IS|ISNOT)/i', $kk)) {
                        $select->where($k. $this->_where_mark[$kk]. $vv);
                    } elseif (preg_match('/^(BETWEEN)/i', $kk) && $vv[0] != '' && $vv[1] != '') {
                        $select->where($k. $this->_where_mark[$kk]. $vv[0]. ' AND '. $vv[1]);
                    } elseif (preg_match('/^(IN|NOTIN)/i', $kk)) {
                        $vv = $select->quote($vv);
                        $select->where($k. $this->_where_mark[$kk]. '('. $vv. ')');
                    } else {
                        $select->where($k. $this->_where_mark[$kk]. ' ?', $vv);
                    }
                    continue;
                }
            }
            $select->whereIn($k, $v);
        }
        if (!is_null($this->_expire)) {
            return $this->_proxy->doProxy($this->_conn, 'fetchAll', ['sql'=> $select->getRealSQL()], $this->_expire, $this->_cache_name);
        }
        return $this->_conn->fetchAll($select->getRealSQL());
    }

}
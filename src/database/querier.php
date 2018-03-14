<?php

class Ark_Database_Querier
{

    /**
     * 当前表名
     *
     * @var string
     */
    protected $_tb;

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
     * @var Ark_Proxy_Cache
     */
    protected $_proxy;

    /**
     * 数据库连接
     *
     * @var Ark_Database_Contract $_conn
     */
    private static $_conn = null;

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
     * 指定数据库连接对象
     *
     * @param Ark_Database_Contract $conn
     */
    static function setConnection(Ark_Database_Contract $conn)
    {
        self::$_conn = $conn;
    }

    /**
     * 获取当前数据库连接对象
     *
     * @return Ark_Database_Contract
     */
    static function getConnection()
    {
        return self::$_conn;
    }

    /**
     * 构造器
     *
     * @param $tb
     */
    private function __construct($tb)
    {
        $this->_tb = $tb;
    }

    /**
     * 静态方法初始化
     *
     * @param $tb
     * @return Ark_Database_Querier
     */
    static function create($tb)
    {
        return new self($tb);
    }

    /**
     * 缓存代理
     *
     * @access public
     * @param int $expire
     * @param null $name
     * @param Ark_Cache_Contract $cache
     * @return Ark_Database_Querier
     */
    function cache($expire, $name, Ark_Cache_Contract $cache)
    {
        $this->_proxy = new Ark_Proxy_Cache();
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
     * @param bool $return 是否返回新增的ID主键
     * @return mixed
     * @throws Exception
     */
    function insert(array $data, $return = false)
    {
        $insert = Ark_Database_SQLBuilder::insert(self::$_conn->getDriverName())->into($this->_tb, $data);
        $added = self::$_conn->query($insert);
        return $added ? ($return ? self::$_conn->lastInsertId() : true) : false;
    }

    /**
     * 编辑数据
     *
     * @access public
     * @final
     * @param array $data 数据键值对
     * @param array $condition 编辑条件
     * @return integer
     * @throws Exception
     */
    function update(array $data, array $condition)
    {
        $update = Ark_Database_SQLBuilder::update(self::$_conn->getDriverName())->set($this->_tb, $data);
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
                        $vv = Ark_Database_SQLBuilder::quote($vv);
                        $update->where($k . $this->_where_mark[$kk] . '('.$vv.')');
                    } else {
                        $update->where($k . $this->_where_mark[$kk] . ' ?', $vv);
                    }
                    continue;
                }
            }
            $update->whereIn($k, $v);
        }
        return self::$_conn->query($update);
    }

    /**
     * 删除表数据
     *
     * @access public
     * @final
     * @param array $condition 删除条件
     * @return int
     * @throws Exception
     */
    function delete(array $condition = array())
    {
        $delete = Ark_Database_SQLBuilder::delete(self::$_conn->getDriverName())->from($this->_tb);
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
                        $vv = Ark_Database_SQLBuilder::quote($vv);
                        $delete->where($k . $this->_where_mark[$kk] . '('.$vv.')');
                    } else {
                        $delete->where($k . $this->_where_mark[$kk] . ' ?', $vv);
                    }
                    continue;
                }
            }
            $delete->whereIn($k, $v);
        }
        return self::$_conn->query($delete);
    }


    /**
     * 取单行数据值
     *
     * @access protected
     * @final
     * @param array $condition 取值条件
     * @param array $fields 取值字段
     * @return array
     * @throws Exception
     */
    function fetch($condition = array(), $fields = array('*'))
    {
        $select = Ark_Database_SQLBuilder::select(self::$_conn->getDriverName())->from($this->_tb, $fields);
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
                        $vv = Ark_Database_SQLBuilder::quote($vv);
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
            return $this->_proxy->doProxy(self::$_conn, 'fetch', array('sql'=> (string)$select), $this->_expire, $this->_cache_name);
        }
        return self::$_conn->fetch($select);
    }

    /**
     * 取聚合函数结果值
     *
     * @access protected
     * @final
     * @param array $condition
     * @param array $fields
     * @return mixed
     * @throws Exception
     * @throws Ark_Proxy_Exception
     */
    function fetchOne($condition = array(), $fields = array('count(*)'))
    {
        $select = Ark_Database_SQLBuilder::select(self::$_conn->getDriverName())->from($this->_tb, $fields);
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
                        $vv = Ark_Database_SQLBuilder::quote($vv);
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
            return $this->_proxy->doProxy(self::$_conn, 'fetchOne', array('sql'=> (string)$select), $this->_expire, $this->_cache_name);
        }
        return self::$_conn->fetchOne($select);
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
     * @throws Exception
     */
    function fetchAll($condition = array(), $order = array(), $count = 0, $offset = 0, $fields = array('*'))
    {
        $select = Ark_Database_SQLBuilder::select(self::$_conn->getDriverName())->from($this->_tb, $fields)->limit($count, $offset);
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
                        $vv = Ark_Database_SQLBuilder::quote($vv);
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
            return $this->_proxy->doProxy(self::$_conn, 'fetchAll', array('sql'=> (string)$select), $this->_expire, $this->_cache_name);
        }
        return self::$_conn->fetchAll($select);
    }

}
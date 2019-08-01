<?php declare(strict_types=1);

namespace Brisk\Db;

use Brisk\Kernel\Language;
use Brisk\Cache\Proxy;
use Brisk\Cache\ICacheDriver;
use Brisk\Exception\RuntimeException;
use Brisk\Toolkit\SqlBuilder\SqlFather;

class DQuery
{

    /**
     * 数据库连接实例
     * 
     * @var IDbDriver
     */
    private $_conn = null;

    /**
     * 操作表名
     *
     * @var string
     */
    private $_tb;

    /**
     * 缓存过期时间
     *
     * @var int
     */
    private $_expire;

    /**
     * 缓存名称
     *
     * @var string
     */
    private $_cache_name;

    /**
     * 代理缓存器
     *
     * @var Proxy
     */
    private $_proxy;

    /**
     * 使用数据库连接
     *
     * @access public
     * @param IDbDriver $conn
     * @param string $table
     * @return DQuery
     */
    public static function open(IDbDriver $conn, string $table = null)
    {
        return new self($conn, $table);
    }

    /**
     * 获取当前数据库连接实例
     *
     * @access public
     * @return IDbDriver
     */
    public function getConn()
    {
        return $this->_conn;
    }

    /**
     * 构造函数
     *
     * @access public
     * @param IDbDriver $conn
     * @param string $table
     * @return void
     */
    private function __construct(IDbDriver $conn, string $table = null)
    {
        $this->_conn = $conn;
        $this->_tb = $table;
        if (is_null($this->_conn)) {
            throw new RuntimeException(Language::format('db.invalid_connection_object'));
        }
    }

    /**
     * 设置要操作的表名
     *
     * @access public
     * @param string $tb
     * @return DQuery
     */
    public function table(string $tb)
    {
        $this->_tb = $tb;
        return $this;
    }

    /**
     * 设置缓存代理器
     *
     * @access public
     * @param int $expire
     * @param ICacheDriver $cache
     * @param string $name
     * @return DQuery
     */
    public function cache(int $expire, ICacheDriver $cache, string $name = null)
    {
        $this->_expire = $expire;
        $this->_cache_name = $name;
        $this->_proxy = new Proxy();
        $this->_proxy->setCacher($cache);
        return $this;
    }

    /**
     * 获取上一次插入的ID
     *
     * @access public
     * @param string|null $seq
     * @return int
     */
    public function getLastInsertId(string $seq = null)
    {
        return $this->_conn->lastInsertId($seq);
    }

    /**
     * 获取上一次SQL执行影响的行数
     *
     * @access public
     * @return int
     */
    public function getLastRowCount()
    {
        return $this->_conn->lastRowCount();
    }

    /**
     * 插入数据
     *
     * @access public
     * @param array $data
     * @return bool
     */
    public function insert(array $data)
    {
        if (!$this->_tb) {
            throw new RuntimeException(Language::format('db.invalid_table_name'));
        }
        $insert = $this->_conn->insert()->into($this->_tb, $data);
        return $this->_conn->query($insert->getRealSQL());
    }

    /**
     * 更新数据
     *
     * @access public
     * @param array $data
     * @param array $condition
     * @return bool
     */
    public function update(array $data, array $condition)
    {
        if (!$this->_tb) {
            throw new RuntimeException(Language::format('db.invalid_table_name'));
        }
        $update = $this->_conn->update()->set([$this->_tb], $data);
        foreach ($condition as $key=> $val) {
            if (is_array($val)) {
                foreach ($val as $k=> $v) {
                    $update = $this->_parseExtendWhere($update, $key, $k, $v);
                }
                continue;
            }
            $update->whereIn($key, $val);
        }
        return $this->_conn->query($update->getRealSQL());
    }

    /**
     * 删除数据
     *
     * @access public
     * @param array $condition
     * @return bool
     */
    public function delete(array $condition)
    {
        if (!$this->_tb) {
            throw new RuntimeException(Language::format('db.invalid_table_name'));
        }
        $delete = $this->_conn->delete()->from([$this->_tb]);
        foreach ($condition as $key=> $val) {
            if (is_array($val)) {
                foreach ($val as $k=> $v) {
                    $delete = $this->_parseExtendWhere($delete, $key, $k, $v);
                }
                continue;
            }
            $delete->whereIn($key, $val);
        }
        return $this->_conn->query($delete->getRealSQL());
    }

    /**
     * 获取单行数据
     *
     * @access public
     * @param array $condition
     * @param array $fields
     * @return array
     */
    public function fetchOne(array $condition, array $fields = ['*'])
    {
        if (!$this->_tb) {
            throw new RuntimeException(Language::format('db.invalid_table_name'));
        }
        $select = $this->_conn->select()->from([$this->_tb], $fields);
        foreach ($condition as $key=> $val) {
            if (is_array($val)) {
                foreach ($val as $k=> $v) {
                    $select = $this->_parseExtendWhere($select, $key, $k, $v);
                }
                continue;
            }
            $select->whereIn($key, $val);
        }
        if (!is_null($this->_expire)) {
            return $this->_proxy->do($this->_conn, 'fetchOne', ['sql'=> $select->getRealSQL()], $this->_expire, $this->_cache_name);
        }
        return $this->_conn->fetchOne($select->getRealSQL());
    }

    /**
     * 获取单行单列数据
     *
     * @access public
     * @param array $condition
     * @param array $fields
     * @return mixed
     */
    public function fetchScalar(array $condition = [], array $fields = ['count(*)'])
    {
        if (!$this->_tb) {
            throw new RuntimeException(Language::format('db.invalid_table_name'));
        }
        $select = $this->_conn->select()->from([$this->_tb], $fields);
        foreach ($condition as $key=> $val) {
            if (is_array($val)) {
                foreach ($val as $k=> $v) {
                    $select = $this->_parseExtendWhere($select, $key, $k, $v);
                }
                continue;
            }
            $select->whereIn($key, $val);
        }
        if (!is_null($this->_expire)) {
            return $this->_proxy->do($this->_conn, 'fetchScalar', ['sql'=> $select->getRealSQL()], $this->_expire, $this->_cache_name);
        }
        return $this->_conn->fetchScalar($select->getRealSQL());
    }

    /**
     * 获取多行数据
     *
     * @access public
     * @param array $condition
     * @param array $order
     * @param int $count
     * @param int $offset
     * @param array $fields
     * @return array
     */
    public function fetchAll(array $condition = [], array $order = [], int $count = 0, int $offset = 0, array $fields = ['*'])
    {
        if (!$this->_tb) {
            throw new RuntimeException(Language::format('db.invalid_table_name'));
        }
        $select = $this->_conn->select()->from([$this->_tb], $fields)->limit($count, $offset);
        if(!is_null($order) && is_array($order)){
            foreach ($order as $key=> $val) {
                $select->orderby($key, $val);
            }
        }
        foreach ($condition as $key=> $val) {
            if (is_array($val)) {
                foreach ($val as $k=> $v) {
                    $select = $this->_parseExtendWhere($select, $key, $k, $v);
                }
                continue;
            }
            $select->whereIn($key, $val);
        }
        if (!is_null($this->_expire)) {
            return $this->_proxy->do($this->_conn, 'fetchAll', ['sql'=> $select->getRealSQL()], $this->_expire, $this->_cache_name);
        }
        return $this->_conn->fetchAll($select->getRealSQL());
    }

    /**
     * 解析扩展Where条件
     *
     * @access private
     * @param SqlFather $sqlbuilder
     * @param string $field
     * @param string $operator
     * @param $value
     * @return SqlFather
     */
    private function _parseExtendWhere(SqlFather $sqlbuilder, string $field, string $operator, $value)
    {
        $operator = strtolower(trim($operator));
        if ($operator == 'is') {
            $sqlbuilder->where($field. ' IS '. $value);
        } elseif ($operator == 'isnot') {
            $sqlbuilder->where($field. ' IS NOT '. $value);
        } elseif ($operator == 'between') {
            if (!is_array($value)) {
                throw new RuntimeException(Language::format('db.invalid_where_condition', 'between操作仅支持数组'));
            }
            $sqlbuilder->where($field. ' BETWEEN '. $value[0]. ' AND '. $value[1]);
        } elseif ($operator == 'in') {
            if (!is_array($value)) {
                throw new RuntimeException(Language::format('db.invalid_where_condition', 'in操作仅支持数组'));
            }
            $sqlbuilder->whereIn($field, $value);
        } elseif ($operator == 'notin') {
            if (!is_array($value)) {
                throw new RuntimeException(Language::format('db.invalid_where_condition', 'notin操作仅支持数组'));
            }
            $sqlbuilder->whereNotIn($field, $value);
        } elseif ($operator == 'like') {
            $sqlbuilder->whereLike($field, $value);
        } elseif ($operator == 'notlike') {
            $sqlbuilder->whereNotLike($field, $value);
        } elseif (in_array($operator, ['>', '<', '>=', '<=', '!=', '<>', '='])) {
            $sqlbuilder->where($field. $operator. '?', $value);
        } else {
            throw new RuntimeException(Language::format('db.invalid_where_condition', '不支持的操作符('. $operator. ')'));
        }
        return $sqlbuilder;
    }

}
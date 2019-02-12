<?php

namespace Brisk\Vendor\Mongo;

abstract class MongoFather
{

    /**
     * db
     * 
     * @var string
     */
    protected $_db;

    /**
     * collection
     * 
     * @var string
     */
    protected $_collection;

    /**
     * mongo object 
     * 
     * @var resource
     */
    protected $_mongo;

    /**
     * 选择数据库
     * 
     * @param string $db
     * @return $this
     */
    public function selectDB($db)
    {
        $this->_db = $db;
        return $this;
    }

    /**
     * 选择表集合
     * 
     * @param string $collection
     * @return $this
     */
    public function selectCollection($collection)
    {
        $this->_collection = $collection;
        return $this;
    }

    /**
     * 获取单条记录
     * 
     * @param array $condition
     * @return array
     */
    public abstract function fetch(array $condition = array());

    /**
     * 获取多条记录
     * 
     * @param array $condition
     * @param array $sort
     * @param int $skip
     * @param int $limit
     * @return array
     */
    public abstract function fetchAll(array $condition = array(), array $sort = array(), $skip = 0, $limit = 0);

    /**
     * 统计总数
     * 
     * @param array $condition
     * @param int $skip
     * @param int $limit
     * @return int
     */
    public abstract function count(array $condition = array(), $skip = 0, $limit = 0);

    /**
     * 新增一条记录
     * 
     * @param array $data
     * @return bool
     */
    public abstract function add(array $data, $once = true);

    /**
     * 修改记录
     * 
     * @param array $condition
     * @param array $update
     * @param bool $once
     * @return bool
     */
    public abstract function modify(array $condition, array $update, $once = false);

    /**
     * 删除记录
     * 
     * @param array $condition
     * @param bool $once
     * @return bool
     */
    public abstract function delete(array $condition, $once = false);

    /**
     * 获取mongodb扩展对象实例
     * 
     * @return 
     */
    public abstract function getInstance();

}
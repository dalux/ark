<?php

namespace Brisk\Vendor\Mongo;

use Exception;
use Brisk\Exception\DbException;

class MongoClient extends MongoFather
{

    /**
     * 构造器
     * 
     * @param string $dsn
     */
    public function __construct($dsn, array $option = array())
    {
        try {
            $this->_mongo = new \MongoClient($dsn, $option);
        } catch (Exception $e) {
            throw new DbException($e->getMessage());
        }
    }

    /**
     * 获取单条记录
     * 
     * @param array $condition
     * @return array
     */
    public function fetch(array $condition = array())
    {
        try {
            $result = $this->_mongo
                ->selectCollection($this->_db, $this->_collection)
                ->findOne($condition);
            return $result ? $result : array();
        } catch (Exception $e) {
            throw new DbException($e->getMessage());
        }
    }

    /**
     * 获取多条记录
     * 
     * @param array $condition
     * @param array $sort
     * @param int $skip
     * @param int $limit
     * @return array
     */
    public function fetchAll(array $condition = array(), array $sort = array(), $skip = 0, $limit = 0)
    {
        try {
            $cursor = $this->_mongo
                ->selectCollection($this->_db, $this->_collection)
                ->find($condition);
            $sort && $cursor = $cursor->sort($sort);
            $skip && $cursor = $cursor->skip($skip);
            $limit && $cursor = $cursor->limit($limit);
            $result = array();
            foreach ($cursor as $val) {
                $result[] = $val;
            }
            return $result;
        } catch (Exception $e) {
            throw new DbException($e->getMessage());
        }
    }

    /**
     * 统计总数
     * 
     * @param array $condition
     * @param int $skip
     * @param int $limit
     * @return int
     */
    public function count(array $condition = array(), $skip = 0, $limit = 0)
    {
        try {
            return $this->_mongo
                ->selectCollection($this->_db, $this->_collection)
                ->count($condition, $limit, $skip);
        } catch (Exception $e) {
            throw new DbException($e->getMessage());
        }
    }

    /**
     * 新增一条记录
     * 
     * @param array $data
     * @return int
     */
    public function add(array $data, $once = true)
    {
        try {
            $collection = $this->_mongo->selectCollection($this->_db, $this->_collection);

            $result = $once
                ? $collection->insert($data, array('w'=> 1))
                : $collection->batchInsert($data, array('w'=> 1));
            return 1;
        } catch (Exception $e) {
            throw new DbException($e->getMessage());
        }
    }

    /**
     * 修改记录
     * 
     * @param array $condition
     * @param array $update
     * @param bool $once
     * @return int
     */
    public function modify(array $condition, array $update, $once = false)
    {
        try {
            $collection = $this->_mongo->selectCollection($this->_db, $this->_collection);
            $option = array('upsert'=> false, 'w'=> 1);
            $once || $option['multiple'] = true;
            $result = $collection->update($condition, $update, $option);
            return $result['n'];
        } catch (Exception $e) {
            throw new DbException($e->getMessage());
        }
    }

    /**
     * 删除记录
     * 
     * @param array $condition
     * @param bool $once
     * @return bool
     */
    public function delete(array $condition, $once = false)
    {
        try {
            $collection = $this->_mongo->selectCollection($this->_db, $this->_collection);
            $option = array('w'=> 1);
            $once || $option['justOne'] = false;
            $result = $collection->remove($condition, $option);
            return $result['n'];
        } catch (Exception $e) {
            throw new DbException($e->getMessage());
        }
    }

    /**
     * 获取mongodb扩展对象实例
     * 
     * @return \MongoClient
     */
    public function getInstance()
    {
        return $this->_mongo;
    }

}
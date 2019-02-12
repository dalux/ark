<?php

namespace Brisk\Vendor\Mongo;

use Exception;
use Brisk\Kernel\Loader;
use Brisk\Exception\DbException;

class MongoDB extends MongoFather
{

    /**
     * 构造器
     * 
     * @param array $config
     * @param array $setting
     */
    public function __construct(array $config, array $setting = array())
    {
        try {
            //注册MongoDB-PHP-Lib类文件自动加载，该库需要mongodb-1.4.x版本扩展库支持
            if (!class_exists('\MongoDB\Client', false)) {
                include_once Loader::realPath('*/Vendor/Mongo/MongoDB/Client.php');
                include_once Loader::realPath('*/Vendor/Mongo/MongoDB/functions.php');
                DLoader::addAutoLoader(function($classname) {
                    $classname = ltrim($classname, '\\');
                    if (preg_match('/^MongoDB\\\\/', $classname)) {
                        $classname = preg_replace('/^MongoDB\\\\/', '', $classname);
                        $classname = str_replace(array('/', '\\'), DIRECTORY_SEPARATOR, $classname);
                        include_once Loader::realpath('*/Vendor/Mongo/MongoDB/'. $classname. '.php');
                    }
                });
            }
            $dsn = sprintf('mongodb://%s:%s@%s:%s/%s', $config['username'], $config['password'], $config['host'], $config['port'], $config['dbname']);
            $this->_mongo = new \MongoDB\Client($dsn, $setting);
            if ($config['dbname']) {
                $this->_mongo->selectDB($config['dbname']);
            }
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
            return $result instanceof ArrayObject 
                ? $result->getArrayCopy()
                : array();
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
            $option = array();
            $sort && $option['sort'] = $sort;
            $skip && $option['skip'] = $skip;
            $limit && $option['limit'] = $limit;
            $cursor = $this->_mongo
                ->selectCollection($this->_db, $this->_collection)
                ->find($condition, $option);
            $result = array();
            foreach ($cursor as $val) {
                if ($val instanceof ArrayObject) {
                    $result[] = $val->getArrayCopy();
                }
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
            $option = array();
            $skip && $option['skip'] = $skip;
            $limit && $option['limit'] = $limit;
            return $this->_mongo
                ->selectCollection($this->_db, $this->_collection)
                ->count($condition, $option);
        } catch (Exception $e) {
            throw new DbException($e->getMessage());
        }
    }

    /**
     * 新增一条记录
     * 
     * @param array $data
     * @return bool
     */
    public function add(array $data, $once = true)
    {
        try {
            $collection = $this->_mongo->selectCollection($this->_db, $this->_collection);

            $result = $once
                ? $collection->insertOne($data)
                : $collection->insertMany($data);
            return $result->getInsertedCount();
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
     * @return bool
     */
    public function modify(array $condition, array $update, $once = false)
    {
        try {
            $collection = $this->_mongo->selectCollection($this->_db, $this->_collection);
            $result = $once 
                ? $collection->updateOne($condition, $update, array('upsert'=> false))
                : $collection->updateMany($condition, $update, array('upsert'=> false));
            return $result->getModifiedCount();
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
            $result = $once
                ? $collection->deleteOne($condition)
                : $collection->deleteMany($condition);
            return $result->getDeletedCount();
        } catch (Exception $e) {
            throw new DbException($e->getMessage());
        }
    }

    /**
     * 获取mongodb扩展对象实例
     * 
     * @return \MongoDB\Client
     */
    public function getInstance()
    {
        return $this->_mongo;
    }


}
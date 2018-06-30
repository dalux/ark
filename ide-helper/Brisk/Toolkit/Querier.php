<?php

namespace Brisk\Toolkit;

use Brisk\Contract\ICache;
use Brisk\Contract\IDatabase;

class Querier
{

    /**
     * 设置数据库连接对象
     *
     * @param IDatabase $conn
     */
    public static function setConnection(IDatabase $conn) {}

    /**
     * 获取数据库连接对象
     *
     * @return IDatabase
     */
    public static function getConnection() {}

    /**
     * 指定操作表
     *
     * @param string $tb
     * @return Querier
     */
    public static function forTable($tb) {}

    /**
     * 设置缓存代理
     *
     * @param int $expire
     * @param ICache $cache
     * @param string $name
     * @return Querier
     */
    public function cache($expire, ICache $cache, $name = "") {}

    /**
     * 插入数据
     *
     * @param array $data
     * @param bool $return_id
     * @return mixed
     */
    public function insert(array $data, $return_id = false) {}

    /**
     * 更新数据
     *
     * @param array $data
     * @param array $condition
     * @return mixed
     */
    public function update(array $data, array $condition) {}

    /**
     * 删除数据
     *
     * @param array $condition
     * @return mixed
     */
    public function delete(array $condition) {}

    /**
     * 获取单行记录
     *
     * @param array $condition
     * @param array $fields
     * @return array
     */
    public function fetchRow(array $condition, array $fields = array()) {}

    /**
     * 获取首行首列记录
     *
     * @param array $condition
     * @param array $fields
     * @return mixed
     */
    public function fetchOne(array $condition = array(), array $fields = array()) {}

    /**
     * 获取多行记录
     *
     * @param array $condition
     * @param array $order
     * @param int $count
     * @param int $offset
     * @param array $fields
     * @return array
     */
    public function fetchAll(array $condition = array(), array $order = array(), $count = 0, $offset = 0, array $fields = array()) {}

}

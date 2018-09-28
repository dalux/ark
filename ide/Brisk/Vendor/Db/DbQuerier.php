<?php

namespace Brisk\Vendor\Db;


class DbQuerier
{

    protected $_tb;


    protected $_expire;


    protected $_cache_name;


    protected $_proxy;


    static private $_conn = null;


    protected $_where_mark = array('=' => ' = ', 'EQ' => ' = ', '!=' => ' != ', 'NEQ' => ' != ', '>' => '>', 'GT' => ' > ', '>=' => ' >= ', 'GTE' => ' >= ', '<' => ' < ', 'LT' => ' < ', '<=' => ' <= ', 'LTE' => ' <= ', 'LIKE' => ' LIKE ', 'NOTLIKE' => ' NOT LIKE ', 'BETWEEN' => ' BETWEEN ', 'IN' => ' IN ', 'NOTIN' => ' NOT IN ', 'IS' => ' IS ', 'ISNOT' => ' IS NOT ');


    /**
     * Setting database connection objects
     *
     * @param DbFather $conn
     * @return null
     */
    public static function setConnection(\Brisk\Vendor\Db\DbFather $conn) {}

    /**
     * Get database connection objects
     *
     * @return DbFather
     */
    public static function getConnection() {}

    /**
     * Construct
     *
     * @param string $tb
     * @return null
     */
    private function __construct($tb) {}

    /**
     * Set the table that you want to operate on
     *
     * @param string $tb
     * @return DbQuerier
     */
    public static function forTable($tb) {}

    /**
     * Set Cache proxy
     *
     * @param int $expire
     * @param CacheFather $cache
     * @param string $name
     * @return DbQuerier
     */
    public function cache($expire, \Brisk\Vendor\Cache\CacheFather $cache, $name = '') {}

    /**
     * Insert new data
     *
     * @param array $data
     * @param bool $return_id
     * @return bool
     */
    public function insert(array $data, $return_id = false) {}

    /**
     * Update data with condition
     *
     * @param array $data
     * @param array $condition
     * @return mixed
     */
    public function update(array $data, array $condition) {}

    /**
     * Delete data
     *
     * @param array $condition
     * @return mixed
     */
    public function delete(array $condition) {}

    /**
     * Get single-row data
     *
     * @param array $condition
     * @param array $fields
     * @return array
     */
    public function fetchRow(array $condition, array $fields = array()) {}

    /**
     * Get single-row and single-colume data
     *
     * @param array $condition
     * @param array $fields
     * @return array
     */
    public function fetchOne(array $condition = array(), array $fields = array()) {}

    /**
     * Get multiple rows of data
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

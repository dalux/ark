<?php

namespace Brisk\Sql;


class SqlBuilder
{

    static private $_db_type = 'mysql';


    /**
     * Setting database type
     *
     * @param string $dbtype
     * @return null
     */
    public static function setDbType($dbtype) {}

    /**
     * Get current database type
     *
     * @return string
     */
    public static function getDbType() {}

    /**
     * Get select sql object
     *
     * @param string $dbtype
     * @return Select
     */
    public static function getSelect($dbtype = '') {}

    /**
     * Get delete sql object
     *
     * @param string $dbtype
     * @return Delete
     */
    public static function getDelete($dbtype = '') {}

    /**
     * Get insert sql object
     *
     * @param string $dbtype
     * @return Insert
     */
    public static function getInsert($dbtype = '') {}

    /**
     * Get Update sql object
     *
     * @param string $dbtype
     * @return Update
     */
    public static function getUpdate($dbtype = '') {}

}

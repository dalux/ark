<?php

namespace Brisk\Vendor\Querier;


class QuerierAdapter
{

    const TYPE_SELECT = 'Select';


    const TYPE_UPDATE = 'Update';


    const TYPE_DELETE = 'Delete';


    const TYPE_INSERT = 'Insert';


    static private $_db_type = 'mysql';


    /**
     * Set Querier database type
     *
     * @param string $dbtype
     * @return null
     */
    public static function setDbType($dbtype) {}

    /**
     * Get Querier object instance
     *
     * @param string $type
     * @param string $dbtype
     * @return QuerierFather
     */
    public static function getQuerier($type, $dbtype = '') {}

    /**
     * Get Select Querier object instance
     *
     * @param string $dbtype
     * @return Select
     */
    public static function getSelectQuerier($dbtype = '') {}

    /**
     * Get Insert Querier object instance
     *
     * @param string $dbtype
     * @return Insert
     */
    public static function getInsertQuerier($dbtype = '') {}

    /**
     * Get Update Querier object instance
     *
     * @param string $dbtype
     * @return Update
     */
    public static function getUpdateQuerier($dbtype = '') {}

    /**
     * Get Delete Querier object instance
     *
     * @param string $dbtype
     * @return Delete
     */
    public static function getDeleteQuerier($dbtype = '') {}

}

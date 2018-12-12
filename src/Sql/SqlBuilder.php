<?php

namespace Brisk\Sql;

use Brisk\Kernel\Language;
use Brisk\Exception\ClassNotFoundException;

class SqlBuilder
{

    /**
     * @var string
     */
    private static $_db_type = 'mysql';

    /**
     * Setting database type
     *
     * @param string dbtype
     * @return null
     */
    public static function setDbType($dbtype)
    {
        self::$_db_type = $dbtype;
    }

    /**
     * Get current database type
     *
     * @return string
     */
    public static function getDbType()
    {
        return self::$_db_type;
    }
    
    /**
     * Get select sql object
     *
     * @param string dbtype
     * @return Select
     */
    public static function getSelect($dbtype = null)
    {
        if (is_null($dbtype)) {
            $dbtype = self::$_db_type;
        }
        $classname = '\\Brisk\\Sql\\Select\\'. ucfirst($dbtype);
        if (!class_exists($classname)) {
            throw new ClassNotFoundException(Language::get('core.class_not_found', $classname));
        }
        $instance = new $classname();
        return $instance;
    }

    /**
     * Get delete sql object
     *
     * @param string dbtype
     * @return Delete
     */
    public static function getDelete($dbtype = null)
    {
        if (is_null($dbtype)) {
            $dbtype = self::$_db_type;
        }
        $classname = '\\Brisk\\Sql\\Delete\\'. ucfirst($dbtype);
        if (!class_exists($classname)) {
            throw new ClassNotFoundException(Language::get('core.class_not_found', $classname));
        }
        $instance = new $classname();
        return $instance;
    }

    /**
     * Get insert sql object
     *
     * @param string dbtype
     * @return Insert
     */
    public static function getInsert($dbtype = null)
    {
        if (is_null($dbtype)) {
            $dbtype = self::$_db_type;
        }
        $classname = '\\Brisk\\Sql\\Insert\\'. ucfirst($dbtype);
        if (!class_exists($classname)) {
            throw new ClassNotFoundException(Language::get('core.class_not_found', $classname));
        }
        $instance = new $classname();
        return $instance;
    }

    /**
     * Get Update sql object
     *
     * @param string dbtype
     * @return Update
     */
    public static function getUpdate($dbtype = null)
    {
        if (is_null($dbtype)) {
            $dbtype = self::$_db_type;
        }
        $classname = '\\Brisk\\Sql\\Update\\'. ucfirst($dbtype);
        if (!class_exists($classname)) {
            throw new ClassNotFoundException(Language::get('core.class_not_found', $classname));
        }
        $instance = new $classname();
        return $instance;
    }

}
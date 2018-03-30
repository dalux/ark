<?php

namespace Brisk\Toolkit;

use Brisk\Toolkit\SQLBuilder\DeleteBuilder;
use Brisk\Toolkit\SQLBuilder\InsertBuilder;
use Brisk\Toolkit\SQLBuilder\SelectBuilder;
use Brisk\Toolkit\SQLBuilder\UpdateBuilder;

class SQLBuilder
{

    /**
     * 数据库类型
     *
     * @var string $dbtype
     */
    private static $_db_type = 'mysql';

    /**
     * 设置数据库类型
     *
     * @access public
     * @param string $dbtype
     * @return mixed
     */
	static function setDbType($dbtype)
	{
		self::$_db_type = $dbtype;
	}

    /**
     * 为值添加引号
     *
     * @access public
     * @param mixed $value
     * @param null $dbtype
     * @return mixed
     */
    static function quote($value, $dbtype = null)
    {
        is_null($dbtype) && $dbtype = self::$_db_type;
        if (is_array($value)) {
            foreach ($value as $key=> $val) { $value[$key] = self::quote($val); }
            return implode(',', $value);
        } elseif (is_int($value) || is_float($value)) {
            return $value;
        }
        switch ($dbtype) {
            case 'oci':
                return "'" . str_replace("'", "''", $value) . "'";
            case 'mysql':
            case 'pgsql':
            case 'sqlite':
            case 'sqlsrv':
            default:
                return "'" . addslashes($value) . "'";
        }
    }

    /**
     * 生成查询对象
     *
     * @param null $dbtype
     * @return SelectBuilder
     */
    static function select($dbtype = null)
    {
        is_null($dbtype) && $dbtype = self::$_db_type;
        $namespace = 'Brisk\Toolkit\SQLBuilder\SelectBuilder\\'. ucfirst($dbtype);
        return new $namespace;
    }

    /**
     * 生成插入对象
     *
     * @param null $dbtype
     * @return InsertBuilder
     */
    static function insert($dbtype = null)
    {
        is_null($dbtype) && $dbtype = self::$_db_type;
        $namespace = 'Brisk\Toolkit\SQLBuilder\InsertBuilder\\'. ucfirst($dbtype);
        return new $namespace;
    }

    /**
     * 生成更新对象
     *
     * @param null $dbtype
     * @return UpdateBuilder
     */
    static function update($dbtype = null)
    {
        is_null($dbtype) && $dbtype = self::$_db_type;
        $namespace = 'Brisk\Toolkit\SQLBuilder\UpdateBuilder\\'. ucfirst($dbtype);
        return new $namespace;
    }

    /**
     * 生成删除对象
     *
     * @param null $dbtype
     * @return DeleteBuilder
     */
    static function delete($dbtype = null)
    {
        is_null($dbtype) && $dbtype = self::$_db_type;
        $namespace = 'Brisk\Toolkit\SQLBuilder\DeleteBuilder\\'. ucfirst($dbtype);
        return new $namespace;
    }

}
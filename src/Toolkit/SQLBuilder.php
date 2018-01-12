<?php

namespace Ark\Toolkit;

use Ark\Core\Noah;
use Ark\Toolkit\SQLBuilder\Select;
use Ark\Toolkit\SQLBuilder\Update;
use Ark\Toolkit\SQLBuilder\Insert;
use Ark\Toolkit\SQLBuilder\Delete;

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
     * @return Select
     */
    static function select($dbtype = null)
    {
        is_null($dbtype) && $dbtype = self::$_db_type;
        $namespace = '\Ark\Toolkit\SQLBuilder\Select\\'. ucfirst($dbtype);
        return new $namespace;
    }

    /**
     * 生成插入对象
     *
     * @param null $dbtype
     * @return Insert
     */
    static function insert($dbtype = null)
    {
        is_null($dbtype) && $dbtype = self::$_db_type;
        $namespace = '\Ark\Toolkit\SQLBuilder\Insert\\'. ucfirst($dbtype);
        return new $namespace;
    }

    /**
     * 生成更新对象
     *
     * @param null $dbtype
     * @return Update
     */
    static function update($dbtype = null)
    {
        is_null($dbtype) && $dbtype = self::$_db_type;
        $namespace = '\Ark\Toolkit\SQLBuilder\Update\\'. ucfirst($dbtype);
        return new $namespace;
    }

    /**
     * 生成删除对象
     *
     * @param null $dbtype
     * @return Delete
     */
    static function delete($dbtype = null)
    {
        is_null($dbtype) && $dbtype = self::$_db_type;
        $namespace = '\Ark\Toolkit\SQLBuilder\Delete\\'. ucfirst($dbtype);
        return new $namespace;
    }

}
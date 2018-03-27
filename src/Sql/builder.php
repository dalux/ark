<?php

class Ark_Sql_Builder
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
     * @return Ark_Sql_Builder_Select
     */
    static function select($dbtype = null)
    {
        is_null($dbtype) && $dbtype = self::$_db_type;
        $namespace = 'Ark_Sql_Builder_Select_'. ucfirst($dbtype);
        return new $namespace;
    }

    /**
     * 生成插入对象
     *
     * @param null $dbtype
     * @return Ark_Sql_Builder_Insert
     */
    static function insert($dbtype = null)
    {
        is_null($dbtype) && $dbtype = self::$_db_type;
        $namespace = 'Ark_Sql_Builder_Insert_'. ucfirst($dbtype);
        return new $namespace;
    }

    /**
     * 生成更新对象
     *
     * @param null $dbtype
     * @return Ark_Sql_Builder_Update
     */
    static function update($dbtype = null)
    {
        is_null($dbtype) && $dbtype = self::$_db_type;
        $namespace = 'Ark_Sql_Builder_Update_'. ucfirst($dbtype);
        return new $namespace;
    }

    /**
     * 生成删除对象
     *
     * @param null $dbtype
     * @return Ark_Sql_Builder_Delete
     */
    static function delete($dbtype = null)
    {
        is_null($dbtype) && $dbtype = self::$_db_type;
        $namespace = 'Ark_Sql_Builder_Delete_'. ucfirst($dbtype);
        return new $namespace;
    }

}
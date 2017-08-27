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
    private $_db_type = 'mysql';

    /**
     * 数据库类型
     *
     * @static
     * @var string $_instance
     */
	private static $_instance = null;

    /**
     * 取实例化对象
     *
     * @access public
     * @return Noah
     */
    static function init($dbtype = null)
    {
        is_null(self::$_instance) 
			&& self::$_instance = new self();
        return is_null($dbtype)
			? self::$_instance
			: self::$_instance->setDbType($dbtype);
    }

    /**
     * 设置数据库类型
     *
     * @access public
     * @param string $dbtype
     * @return mixed
     */
	function setDbType($dbtype)
	{
		$this->_db_type = $dbtype;
		return $this;
	}

    /**
     * 为值添加引号
     *
     * @access public
     * @param mixed $value
     * @return mixed
     */
    function quote($value)
    {
        if (is_array($value)) {
            foreach ($value as $key=> $val) { $value[$key] = $this->quote($val); }
            return implode(',', $value);
        } elseif (is_int($value) || is_float($value)) {
            return $value;
        }
        switch ($this->_db_type) {
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
     * @return Select
     * @throws Exception
     */
    function select()
    {
        $namespace = '\Ark\Toolkit\SQLBuilder\Select\\'. ucfirst($this->_db_type);
        return new $namespace;
    }

    /**
     * 生成插入对象
     *
     * @return Insert
     * @throws Exception
     */
    function insert($dbtype)
    {
        $namespace = '\Ark\Toolkit\SQLBuilder\Insert\\'. ucfirst($this->_db_type);
        return new $namespace;
    }

    /**
     * 生成更新对象
     *
     * @return Update
     * @throws Exception
     */
    function update()
    {
        $namespace = '\Ark\Toolkit\SQLBuilder\Update\\'. ucfirst($this->_db_type);
        return new $namespace;
    }

    /**
     * 生成删除对象
     *
     * @return Delete
     * @throws Exception
     */
    function delete()
    {
        $namespace = '\Ark\Toolkit\SQLBuilder\Delete\\'. ucfirst($this->_db_type);
        return new $namespace;
    }

}
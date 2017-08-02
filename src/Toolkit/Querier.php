<?php

namespace Ark\Toolkit;

use Ark\Core\Noah;
use Ark\Toolkit\Querier\Select;
use Ark\Toolkit\Querier\Update;
use Ark\Toolkit\Querier\Insert;
use Ark\Toolkit\Querier\Delete;

class Querier
{

    /**
     * 数据库类型
     *
     * @static
     * @var string $dbtype
     */
    private static $_db_type = 'mysql';

    /**
     * 设置数据库类型
     *
     * @static
     * @param string $dbtype
     */
    static function setDbType($dbtype)
    {
        self::$_db_type = $dbtype;
    }

    /**
     * 生成查询对象
     *
     * @param $dbtype
     * @return Select
     * @throws Exception
     */
    function select($dbtype = null)
    {
        $dbtype || $dbtype = self::$_db_type;
        if (!$dbtype) {
            throw new Exception(Noah::init()->lang->get('db.querier_type_missing'));
        }
        $namespace = '\Ark\Toolkit\Querier\Select\\'. ucfirst($dbtype);
        return new $namespace;
    }

    /**
     * 生成插入对象
     *
     * @param $dbtype
     * @return Insert
     * @throws Exception
     */
    function insert($dbtype = null)
    {
        $dbtype || $dbtype = self::$_db_type;
        if (!$dbtype) {
            throw new Exception(Noah::init()->lang->get('db.querier_type_missing'));
        }
        $namespace = '\Ark\Toolkit\Querier\Insert\\'. ucfirst($dbtype);
        return new $namespace;
    }

    /**
     * 生成更新对象
     *
     * @param $dbtype
     * @return Update
     * @throws Exception
     */
    function update($dbtype = null)
    {
        $dbtype || $dbtype = self::$_db_type;
        if (!$dbtype) {
            throw new Exception(Noah::init()->lang->get('db.querier_type_missing'));
        }
        $namespace = '\Ark\Toolkit\Querier\Update\\'. ucfirst($dbtype);
        return new $namespace;
    }

    /**
     * 生成删除对象
     *
     * @param $dbtype
     * @return Delete
     * @throws Exception
     */
    function delete($dbtype = null)
    {
        $dbtype || $dbtype = self::$_db_type;
        if (!$dbtype) {
            throw new Exception(Noah::init()->lang->get('db.querier_type_missing'));
        }
        $namespace = '\Ark\Toolkit\Querier\Delete\\'. ucfirst($dbtype);
        return new $namespace;
    }

}
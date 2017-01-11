<?php

namespace Ark\Database;

use Ark\Core\Captain;
use Ark\Database\Querier\Select;
use Ark\Database\Querier\Update;
use Ark\Database\Querier\Insert;
use Ark\Database\Querier\Delete;

class Querier
{

    /**
     * 生成查询对象
     *
     * @param $dbtype
     * @return Select
     * @throws Exception
     */
    static function select($dbtype)
    {
        if (!$dbtype) {
            throw new Exception(Captain::getInstance()->lang->get('db.querier_type_missing'));
        }
        $namespace = '\Ark\Database\Querier\Select\\'. ucfirst($dbtype);
        return new $namespace;
    }

    /**
     * 生成插入对象
     *
     * @param $dbtype
     * @return Insert
     * @throws Exception
     */
    static function insert($dbtype)
    {
        if (!$dbtype) {
            throw new Exception(Captain::getInstance()->lang->get('db.querier_type_missing'));
        }
        $namespace = '\Ark\Database\Querier\Insert\\'. ucfirst($dbtype);
        return new $namespace;
    }

    /**
     * 生成更新对象
     *
     * @param $dbtype
     * @return Update
     * @throws Exception
     */
    static function update($dbtype)
    {
        if (!$dbtype) {
            throw new Exception(Captain::getInstance()->lang->get('db.querier_type_missing'));
        }
        $namespace = '\Ark\Database\Querier\Update\\'. ucfirst($dbtype);
        return new $namespace;
    }

    /**
     * 生成删除对象
     *
     * @param $dbtype
     * @return Delete
     * @throws Exception
     */
    static function delete($dbtype)
    {
        if (!$dbtype) {
            throw new Exception(Captain::getInstance()->lang->get('db.querier_type_missing'));
        }
        $namespace = '\Ark\Database\Querier\Delete\\'. ucfirst($dbtype);
        return new $namespace;
    }

}
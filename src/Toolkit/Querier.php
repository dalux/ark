<?php

namespace Ark\Toolkit;

use Ark\Core\Captain;
use Ark\Toolkit\Querier\Select;
use Ark\Toolkit\Querier\Update;
use Ark\Toolkit\Querier\Insert;
use Ark\Toolkit\Querier\Delete;

class Querier
{

    /**
     * 是否使用绑定变量方式发送生成的SQL语句
     *
     * @var bool
     */
    private static $_use_bind_params = true;

    /**
     * 设置是否绑定变量方式
     *
     * @param $state
     */
    static function setBindParams($state)
    {
        self::$_use_bind_params = (bool)$state;
    }

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
    static function insert($dbtype)
    {
        if (!$dbtype) {
            throw new Exception(Captain::getInstance()->lang->get('db.querier_type_missing'));
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
    static function update($dbtype)
    {
        if (!$dbtype) {
            throw new Exception(Captain::getInstance()->lang->get('db.querier_type_missing'));
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
    static function delete($dbtype)
    {
        if (!$dbtype) {
            throw new Exception(Captain::getInstance()->lang->get('db.querier_type_missing'));
        }
        $namespace = '\Ark\Toolkit\Querier\Delete\\'. ucfirst($dbtype);
        return new $namespace;
    }

}
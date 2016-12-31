<?php

namespace Ark\Database;

class Querier
{

    /**
     * 生成查询对象
     *
     * @param $dbtype
     * @return mixed
     */
    function select($dbtype)
    {
        $namespace = '\Ark\Database\Querier\Select\\'. ucfirst($dbtype);
        return new $namespace;
    }

    /**
     * 生成插入对象
     *
     * @param $dbtype
     * @return mixed
     */
    function insert($dbtype)
    {
        $namespace = '\Ark\Database\Querier\Insert\\'. ucfirst($dbtype);
        return new $namespace;
    }

    /**
     * 生成更新对象
     *
     * @param $dbtype
     * @return mixed
     */
    function update($dbtype)
    {
        $namespace = '\Ark\Database\Querier\Update\\'. ucfirst($dbtype);
        return new $namespace;
    }

    /**
     * 生成删除对象
     *
     * @param $dbtype
     * @return mixed
     */
    function delete($dbtype)
    {
        $namespace = '\Ark\Database\Querier\Delete\\'. ucfirst($dbtype);
        return new $namespace;
    }

}
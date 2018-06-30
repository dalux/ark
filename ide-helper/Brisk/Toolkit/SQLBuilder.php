<?php

namespace Brisk\Toolkit;

use Brisk\Toolkit\SQLBuilder\DeleteBuilder;
use Brisk\Toolkit\SQLBuilder\InsertBuilder;
use Brisk\Toolkit\SQLBuilder\SelectBuilder;
use Brisk\Toolkit\SQLBuilder\UpdateBuilder;

class SQLBuilder
{

    /**
     * 设置数据库类型
     *
     * @param string $dbtype
     * @return null
     */
    public static function setDbType($dbtype) {}

    /**
     * 给指定值加上引号
     *
     * @param mixed $value
     * @param string $dbtype
     * @return string
     */
    public static function quote($value, $dbtype = "") {}

    /**
     * 获取Select语句构建器
     *
     * @param string $dbtype
     * @return SelectBuilder
     */
    public static function select($dbtype = "") {}

    /**
     * 获取Inser语句构建器
     *
     * @param string $dbtype
     * @return InsertBuilder
     */
    public static function insert($dbtype = "") {}

    /**
     * 获取Update语句构建器
     *
     * @param string $dbtype
     * @return UpdateBuilder
     */
    public static function update($dbtype = "") {}

    /**
     * 获取Delete语句构建器
     *
     * @param string $dbtype
     * @return DeleteBuilder
     */
    public static function delete($dbtype = "") {}

}

<?php

namespace Brisk\Toolkit\SQLBuilder;

abstract class SelectBuilder extends \Brisk\Toolkit\SQLBuilder\BuilderFather
{

    /**
     * 设置from子句
     *
     * @param mixed $table
     * @param array $columns
     * @return SelectBuilder
     */
    public function from($table, array $columns = array("*")) {}

    /**
     * 设置group子句
     *
     * @param mixed $column
     * @return SelectBuilder
     */
    public function group($column) {}

    /**
     * 设置having子句
     *
     * @param string $cond
     * @return SelectBuilder
     */
    public function having($cond) {}

    /**
     * 设置limit子句
     *
     * @param mixed $count
     * @param mixed $offset
     * @return SelectBuilder
     */
    public function limit($count = 0, $offset = 0) {}

    /**
     * 设置order子句
     *
     * @param string $col
     * @param bool $asc
     * @return SelectBuilder
     */
    public function order($col, $asc = true) {}

    /**
     * 设置left jon子句
     *
     * @param mixed $table
     * @param string $cond
     * @param array $fields
     * @return SelectBuilder
     */
    public function joinLeft($table, $cond, array $fields = array("*")) {}

    /**
     * 设置inner join子句
     *
     * @param mixed $table
     * @param string $cond
     * @param array $fields
     * @return SelectBuilder
     */
    public function joinInner($table, $cond, array $fields = array("*")) {}

    /**
     * 设置right join子句
     *
     * @param mixed $table
     * @param string $cond
     * @param array $fields
     * @return SelectBuilder
     */
    public function joinRight($table, $cond, array $fields = array("*")) {}

    /**
     * 设置where条件
     *
     * @param string $expr
     * @param mixed $value
     * @return SelectBuilder
     */
    public function where($expr, $value = "") {}

    /**
     * 设置whereIn条件
     *
     * @param string $field
     * @param mixed $value
     * @return SelectBuilder
     */
    public function whereIn($field, $value) {}

    /**
     * 设置whereNotIn条件
     *
     * @param string $field
     * @param mixed $value
     * @return SelectBuilder
     */
    public function whereNotIn($field, $value) {}

    /**
     * 设置whereExists条件
     *
     * @param mixed $query
     * @return SelectBuilder
     */
    public function whereExists($query) {}

    /**
     * 设置whereNotExists子句
     *
     * @param mixed $query
     * @return SelectBuilder
     */
    public function whereNotExists($query) {}

    /**
     * 设置whereLike条件
     *
     * @param string $field
     * @param string $expr
     * @param string $escape
     * @return SelectBuilder
     */
    public function whereLike($field, $expr, $escape = "") {}

    /**
     * 设置WhereNotLike条件
     *
     * @param string $field
     * @param string $expr
     * @param string $escape
     * @return SelectBuilder
     */
    public function whereNotLike($field, $expr, $escape = "") {}

}

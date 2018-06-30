<?php

namespace Brisk\Toolkit\SQLBuilder;

abstract class UpdateBuilder extends \Brisk\Toolkit\SQLBuilder\BuilderFather
{

    /**
     * 设置set子句
     *
     * @param mixed $table
     * @param array $updates
     */
    public function set($table, array $updates = array()) {}

    /**
     * 设置where条件
     *
     * @param string $expr
     * @param mixed $value
     * @return UpdateBuilder
     */
    public function where($expr, $value = "") {}

    /**
     * 设置whereIn条件
     *
     * @param string $field
     * @param mixed $value
     * @return UpdateBuilder
     */
    public function whereIn($field, $value) {}

    /**
     * 设置whereNotIn条件
     *
     * @param string $field
     * @param mixed $value
     * @return UpdateBuilder
     */
    public function whereNotIn($field, $value) {}

    /**
     * 设置whereExists条件
     *
     * @param mixed $query
     * @return UpdateBuilder
     */
    public function whereExists($query) {}

    /**
     * 设置whereNotExists子句
     *
     * @param mixed $query
     * @return UpdateBuilder
     */
    public function whereNotExists($query) {}

    /**
     * 设置whereLike条件
     *
     * @param string $field
     * @param string $expr
     * @param string $escape
     * @return UpdateBuilder
     */
    public function whereLike($field, $expr, $escape = "") {}

    /**
     * 设置WhereNotLike条件
     *
     * @param string $field
     * @param string $expr
     * @param string $escape
     * @return UpdateBuilder
     */
    public function whereNotLike($field, $expr, $escape = "") {}

}

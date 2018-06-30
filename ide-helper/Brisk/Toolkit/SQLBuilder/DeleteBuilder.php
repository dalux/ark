<?php

namespace Brisk\Toolkit\SQLBuilder;

abstract class DeleteBuilder extends \Brisk\Toolkit\SQLBuilder\BuilderFather
{

    /**
     * 设置from子句
     *
     * @param mixed $table
     * @return DeleteBuilder
     */
    public function from($table) {}

    /**
     * 设置where条件
     *
     * @param string $expr
     * @param mixed $value
     * @return DeleteBuilder
     */
    public function where($expr, $value = "") {}

    /**
     * 设置whereIn条件
     *
     * @param string $field
     * @param mixed $value
     * @return DeleteBuilder
     */
    public function whereIn($field, $value) {}

    /**
     * 设置whereNotIn条件
     *
     * @param string $field
     * @param mixed $value
     * @return DeleteBuilder
     */
    public function whereNotIn($field, $value) {}

    /**
     * 设置whereExists条件
     *
     * @param mixed $query
     * @return DeleteBuilder
     */
    public function whereExists($query) {}

    /**
     * 设置whereNotExists子句
     *
     * @param mixed $query
     * @return DeleteBuilder
     */
    public function whereNotExists($query) {}

    /**
     * 设置whereLike条件
     *
     * @param string $field
     * @param string $expr
     * @param string $escape
     * @return DeleteBuilder
     */
    public function whereLike($field, $expr, $escape = "") {}

    /**
     * 设置WhereNotLike条件
     *
     * @param string $field
     * @param string $expr
     * @param string $escape
     * @return DeleteBuilder
     */
    public function whereNotLike($field, $expr, $escape = "") {}

}

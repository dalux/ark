<?php

namespace Brisk\Toolkit\SQLBuilder;

abstract class BuilderFather
{

    /**
     * 设置where条件
     *
     * @param string $expr
     * @param mixed $value
     * @return BuilderFather
     */
    public function where($expr, $value = "") {}

    /**
     * 设置whereIn条件
     *
     * @param string $field
     * @param mixed $value
     * @return BuilderFather
     */
    public function whereIn($field, $value) {}

    /**
     * 设置whereNotIn条件
     *
     * @param string $field
     * @param mixed $value
     * @return BuilderFather
     */
    public function whereNotIn($field, $value) {}

    /**
     * 设置whereExists条件
     *
     * @param mixed $query
     * @return BuilderFather
     */
    public function whereExists($query) {}

    /**
     * 设置WhereNotExists子句
     *
     * @param mixed $query
     * @return BuilderFather
     */
    public function whereNotExists($query) {}

    /**
     * 设置whereLike条件
     *
     * @param string $field
     * @param string $expr
     * @param string $escape
     * @return BuilderFather
     */
    public function whereLike($field, $expr, $escape = "") {}

    /**
     * 设置WhereNotLike条件
     *
     * @param string $field
     * @param string $expr
     * @param string $escape
     * @return BuilderFather
     */
    public function whereNotLike($field, $expr, $escape = "") {}

    /**
     * 获取where条件生成语句
     *
     * @return string
     */
    public function pickWherePart() {}

    /**
     * 获取SQL语句，包含绑定变量占位符
     *
     * @return string
     */
    public function getSQL() {}

    /**
     * 获取SQL语句，最终解析结果
     *
     * @return string
     */
    public function getRealSQL() {}

    /**
     * 获取SQL绑定变量数组
     *
     * @return array
     */
    public function getBind() {}

    /**
     * 魔术方法
     *
     * @return string
     */
    public function __toString() {}

}

<?php

namespace Brisk\Vendor\Querier;


abstract class Select extends \Brisk\Vendor\Querier\QuerierFather
{

    /**
     * Setting the from field in the sql statement
     *
     * @param mixed $table
     * @param array $columns
     * @return Select
     */
    public function from($table, array $columns = array()) {}

    /**
     * Setting the group field in the sql statement
     *
     * @param mixed $column
     * @param mixed $columns
     * @return Select
     */
    public function group($column) {}

    /**
     * Setting the having field in the sql statement
     *
     * @param string $cond
     * @return Select
     */
    public function having($cond) {}

    /**
     * Setting the limit field in the sql statement
     *
     * @param int $count
     * @param int $offset
     * @return Select
     */
    public function limit($count = 0, $offset = 0) {}

    /**
     * Setting the order field in the sql statement
     *
     * @param string $col
     * @param bool $asc
     * @return Select
     */
    public function order($col, $asc = true) {}

    /**
     * Setting the joinLeft field in the sql statement
     *
     * @param mixed $table
     * @param string $cond
     * @param array $fields
     * @return Select
     */
    public function joinLeft($table, $cond, array $fields = array()) {}

    /**
     * Setting the joinInner field in the sql statement
     *
     * @param mixed $table
     * @param string $cond
     * @param array $fields
     * @return Select
     */
    public function joinInner($table, $cond, array $fields = array()) {}

    /**
     * Setting the joinRight field in the sql statement
     *
     * @param mixed $table
     * @param string $cond
     * @param array $fields
     * @return Select
     */
    public function joinRight($table, $cond, array $fields = array()) {}

    /**
     * @param mixed $table
     * @param string $cond
     * @param array $fields
     * @param string $jointype
     */
    protected function _join($table, $cond, array $fields, $jointype) {}

    /**
     * Get the select fragment in the sql statement
     *
     * @return string
     */
    public function pickSelectPart() {}

    /**
     * Get the group fragment in the sql statement
     *
     * @return string
     */
    public function pickGroupPart() {}

    /**
     * Get the having fragment in the sql statement
     *
     * @return string
     */
    public function pickHavingPart() {}

    /**
     * Get the order fragment in the sql statement
     *
     * @return string
     */
    public function pickOrderPart() {}

    /**
     * Get the limit fragment in the sql statement
     *
     * @return string
     */
    public function pickLimitPart() {}

    /**
     * Get the full sql statement
     *
     * @return string
     */
    public function getSQL() {}

}

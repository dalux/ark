<?php

namespace Brisk\Sql;


abstract class SqlFather
{

    protected $_db_type = '';


    protected $_parts = array();


    protected $_sql = '';


    protected $_db_bind = array();


    protected $_compiled = false;


    /**
     * Put quotation marks on a field
     *
     * @param mixed $value
     * @param string $dbtype
     * @return string
     */
    public function quote($value) {}

    /**
     * Setting the sql statement where condition
     *
     * @param string $expr
     * @param mixed $value
     * @param mixed $dbtype
     * @return SqlFather
     */
    public function where($expr, $value = '') {}

    /**
     * Setting the sql statement whereIn condition
     *
     * @param string $field
     * @param mixed $value
     * @return SqlFather
     */
    public function whereIn($field, $value) {}

    /**
     * Setting the sql statement whereNotIn condition
     *
     * @param string $field
     * @param mixed $value
     * @return SqlFather
     */
    public function whereNotIn($field, $value) {}

    /**
     * Setting the sql statement whereExists condition
     *
     * @param string $query
     * @return SqlFather
     */
    public function whereExists($query) {}

    /**
     * Setting the sql statement whereNotExists condition
     *
     * @param string $query
     * @return SqlFather
     */
    public function whereNotExists($query) {}

    /**
     * Setting the sql statement whereLike condition
     *
     * @param string $field
     * @param string $expr
     * @param string $escape
     * @return SqlFather
     */
    public function whereLike($field, $expr, $escape = '') {}

    /**
     * Setting the sql statement whereNotLike condition
     *
     * @param string $field
     * @param string $expr
     * @param string $escape
     * @return SqlFather
     */
    public function whereNotLike($field, $expr, $escape = '') {}

    /**
     * Get the where fragment in the sql statement
     *
     * @return string
     */
    public function pickWherePart() {}

    /**
     * Get the bind data
     *
     * @return array
     */
    public function getBind() {}

    /**
     * Get the full sql statement
     *
     * @return string
     */
    public function getSQL() {}

    /**
     * Get the full sql statement
     *
     * @return string
     */
    public function getRealSQL() {}


    public function __toString() {}

    /**
     * Compile the sql statment and query bind parameter
     *
     * @return SqlFather
     */
    public abstract function compile();

    /**
     * @param string $expr
     * @param mixed $value
     */
    protected function _parseExpr($expr, $value = '') {}

}

<?php

namespace Brisk\Vendor\Querier;


abstract class QuerierFather
{

    protected $_db_type = '';


    protected $_parts = array();


    protected $_db_bind = array();


    /**
     * Put quotation marks on a field
     *
     * @param mixed $value
     * @param string $dbtype
     * @return string
     */
    public function quote($value, $dbtype = '') {}

    /**
     * Setting the sql statement where condition
     *
     * @param string $expr
     * @param mixed $value
     * @param mixed $dbtype
     * @return QuerierFather
     */
    public function where($expr, $value = '') {}

    /**
     * Setting the sql statement whereIn condition
     *
     * @param string $field
     * @param mixed $value
     * @return QuerierFather
     */
    public function whereIn($field, $value) {}

    /**
     * Setting the sql statement whereNotIn condition
     *
     * @param string $field
     * @param mixed $value
     * @return QuerierFather
     */
    public function whereNotIn($field, $value) {}

    /**
     * Setting the sql statement whereExists condition
     *
     * @param string $query
     * @return QuerierFather
     */
    public function whereExists($query) {}

    /**
     * Setting the sql statement whereNotExists condition
     *
     * @param string $query
     * @return QuerierFather
     */
    public function whereNotExists($query) {}

    /**
     * Setting the sql statement whereLike condition
     *
     * @param string $field
     * @param string $expr
     * @param string $escape
     * @return QuerierFather
     */
    public function whereLike($field, $expr, $escape = '') {}

    /**
     * Setting the sql statement whereNotLike condition
     *
     * @param string $field
     * @param string $expr
     * @param string $escape
     * @return QuerierFather
     */
    public function whereNotLike($field, $expr, $escape = '') {}

    /**
     * Get the where fragment in the sql statement
     *
     * @return string
     */
    public function pickWherePart() {}

    /**
     * Get the full sql statement
     *
     * @return string
     */
    public abstract function getSQL();

    /**
     * Get the full sql statement
     *
     * @return string
     */
    public function getRealSQL() {}

    /**
     * Get the bind data
     *
     * @return array
     */
    public function getBind() {}


    public function __toString() {}

    /**
     * @param string $expr
     * @param mixed $value
     */
    protected function _parseExpr($expr, $value = '') {}

}

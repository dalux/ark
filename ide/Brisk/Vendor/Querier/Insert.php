<?php

namespace Brisk\Vendor\Querier;


abstract class Insert extends \Brisk\Vendor\Querier\QuerierFather
{

    /**
     * Setting the into field in the sql statement
     *
     * @param string $table
     * @param array $data
     * @return Insert
     */
    public function into($table, array $data) {}

    /**
     * Get the insert fragment in the sql statement
     *
     * @return string
     */
    public function pickInsertPart() {}

    /**
     * Get the values fragment in the sql statement
     *
     * @return string
     */
    public function pickValuesPart() {}

    /**
     * Get the full sql statement
     *
     * @return string
     */
    public function getSQL() {}

}

<?php

namespace Brisk\Toolkit\SQLBuilder;

abstract class InsertBuilder extends \Brisk\Toolkit\SQLBuilder\BuilderFather
{

    /**
     * 设置into语句
     *
     * @param string $table
     * @param array $data
     * @return InsertBuilder
     */
    public function into($table, array $data) {}

}

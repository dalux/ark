<?php

namespace Brisk\Kernel\Request;

class Get
{

    /**
     * Add request data
     *
     * @param string $name
     * @param mixed $value
     * @return Get
     */
    public function add($name, $value) {}

    /**
     * Del request item
     *
     * @param string $name
     * @return Get
     */
    public function del($name) {}

    /**
     * Gets the specified request data
     *
     * @param string $name
     * @param string $alternative
     * @return mixed
     */
    public function data($name = '', $alternative = '') {}

}
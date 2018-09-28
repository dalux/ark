<?php

namespace Brisk\Kernel\Request;

class Request
{

    /**
     * Add request data
     *
     * @param string $name
     * @param mixed $value
     * @return Request
     */
    public function add($name, $value) {}

    /**
     * Del request item
     *
     * @param string $name
     * @return Request
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
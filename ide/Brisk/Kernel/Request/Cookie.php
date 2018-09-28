<?php

namespace Brisk\Kernel\Request;

class Cookie
{

    /**
     * Add request data
     *
     * @param string $name
     * @param mixed $value
     * @return Cookie
     */
    public function add($name, $value) {}

    /**
     * Del request item
     *
     * @param string $name
     * @return Cookie
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
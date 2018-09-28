<?php

namespace Brisk\Kernel;

class Container
{

    private $_container;

    /**
     * construct
     *
     * @param mixed $data
     * @return null
     */
    public function __construct($data = null) {}

    /**
     * Check if key exists
     *
     * @param string $key
     * @return bool
     */
    public function hasKey($key) {}

    /**
     * Check if value exists
     *
     * @return bool
     */
    public function hasValue() {}

    /**
     * Get data from the current node
     *
     * @param bool $in_loop
     * @return mixed
     */
    public function getValue() {}

    /**
     * Get the data corresponding to the specified key
     *
     * @param string key
     * @return mixed
     */
    public function get($key) {}

    /**
     * @param string $key
     */
    public function __get($key) {}

    /**
     * @param string $key
     * @param mixed $value
     */
    public function __set($key, $value) {}

}

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
     * Get current value
     *
     * @param bool $in_loop
     * @return mixed
     */
    public function getValue($in_loop = false) {}

    /**
     * @param string $name
     */
    public function __get($name) {}

    /**
     * @param string $name
     * @param mixed $value
     */
    public function __set($name, $value) {}

}

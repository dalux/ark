<?php

namespace Brisk\Kernel;

class Container
{

    /**
     * @var array
     */
    private $_container;

    /**
     * construct
     *
     * @param mixed data
     * @return null
     */
    public function __construct($data = null)
    {
        if (is_array($data)) {
            $this->_container = [];
            foreach ($data as $key=> $val) {
                $this->_container[$key] = new self($val);
            }
        } elseif ($data) {
            $this->_container = $data;
        }
    }

    /**
     * Check if key exists
     *
     * @param string key
     * @return bool
     */
    public function hasKey($key)
    {
        $key = str_replace(['>', '.', '/'], '>', $key);
        $key = trim($key, '>');
        if (strpos($key, '>') === false) {
            return is_array($this->_container)
                ? isset($this->_container[$key])
                : false;
        }     
        $nodes = explode('>', $key);
        $node = array_shift($nodes);
        if (!$this->hasKey($node)) {
            return false;
        }
        $instance = $this->$node;
        foreach ($nodes as $k=> $v) {
            if (!$instance->hasKey($v)) {
                return false;
            }
            $instance = $instance->$v;
        }
        return true;
    }

    /**
     * Check whether data exists at the current node
     *
     * @return bool
     */
    public function hasValue()
    {
        if (is_array($this->_container)) {
            return count($this->_container) > 0;
        }
        return $this->_container != null;
    }

    /**
     * Get data from the current node
     *
     * @return mixed
     */
    public function getValue()
    {
        $result = [];
        if (is_array($this->_container)) {
            foreach ($this->_container as $k=> $v) {
                if ($v instanceof Container) {
                    $result[$k] = $v->getValue();
                } else {
                    $result[$k] = $v;
                }
            }
        } else {
            $result = $this->_container;
        }
        if (is_array($result) 
                && count($result) == 1 
                && isset($result[0])
                && !is_array($result[0])) {
            $result = $result[0];
        }
        return $result;
    }

    /**
     * Get the data corresponding to the specified key
     *
     * @param string key
     * @return mixed
     */
    public function get($key)
    {
        $key = str_replace(['>', '.', '/'], '>', $key);
        $key = trim($key, '>');
        $nodes = explode('>', $key);
        $node = array_shift($nodes);
        if ($this->hasKey($node)) {
            $instance = $this->$node;
            foreach ($nodes as $k=> $v) {
                if ($instance->hasKey($v)) {
                    $instance = $instance->$v;
                } else {
                    return null;
                }
            }
            return $instance->getValue();
        }
        return null;
    }

    /**
     *
     *
     * @param string $key
     * @return mixed
     */
    public function __get($key)
    {
        if ($this->hasKey($key)) {
            return $this->_container[$key];
        } else {
            return new self();
        }
    }

    /**
     *
     *
     * @param string $key
     * @param $value
     */
    public function __set($key, $value)
    {
        if (is_null($this->_container)) {
            $this->_container = [];
        }
        $this->_container[$key] = new self($value);
    }

}
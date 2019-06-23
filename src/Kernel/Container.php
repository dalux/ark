<?php declare(strict_types=1);

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
        } elseif (!is_null($data)) {
            $this->_container = $data;
        }
    }

    /**
     * Check if key exists
     *
     * @param string key
     * @return bool
     */
    public function exist(string $key)
    {
        $key = trim($key, '/');
        if (strpos($key, '/') === false) {
            return is_array($this->_container)
                ? isset($this->_container[$key])
                : false;
        }
        $nodes = explode('/', $key);
        $node = array_shift($nodes);
        if (!$this->exist($node)) {
            return false;
        }
        $instance = $this->$node;
        foreach ($nodes as $k=> $v) {
            if (!$instance->exist($v)) {
                return false;
            }
            $instance = $instance->$v;
        }
        return true;
    }

    /**
     * Get data from the current node
     *
     * @return mixed
     */
    public function value()
    {
        $result = [];
        if (is_array($this->_container)) {
            foreach ($this->_container as $k=> $v) {
                if ($v instanceof Container) {
                    $result[$k] = $v->value();
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
     * 取值
     *
     * @param string $key
     * @return mixed
     */
    public function __get(string $key)
    {
        if ($this->exist($key)) {
            return $this->_container[$key];
        } else {
            return new self();
        }
    }

    /**
     * 设值
     *
     * @param string $key
     * @param mixed $value
     * @return $this
     */
    public function __set(string $key, $value)
    {
        if (is_null($this->_container)) {
            $this->_container = [];
        }
        $this->_container[$key] = new self($value);
        return $this;
    }

}
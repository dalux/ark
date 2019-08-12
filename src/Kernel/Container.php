<?php declare(strict_types=1);

namespace Brisk\Kernel;

class Container
{

    /**
     * 数据数组
     * 
     * @var array
     */
    private $_container;

    /**
     * 构造函数
     *
     * @access public
     * @param mixed $data
     * @return void
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
     * 检查指定key是否存在
     *
     * @access public
     * @param string $key
     * @return bool
     */
    public function has(string $key)
    {
        $key = trim($key, '/');
        if (strpos($key, '/') === false) {
            return is_array($this->_container)
                ? isset($this->_container[$key])
                : false;
        }
        $nodes = explode('/', $key);
        $first = array_shift($nodes);
        if (!$this->has($first)) {
            return false;
        }
        $instance = $this->$first;
        foreach ($nodes as $k=> $v) {
            if (!$instance->has($v)) {
                return false;
            }
            $instance = $instance->$v;
        }
        return true;
    }

    /**
     * 获取节点数据
     *
     * @access public
     * @param string $key
     * @return mixed
     */
    public function get(string $key)
    {
        $key = trim($key, '/');
        if (strpos($key, '/') === false) {
            return $this->$key->value();
        }
        $nodes = explode('/', $key);
        $first = array_shift($nodes);
        if ($this->has($first)) {
            $instance = $this->$first;
            foreach ($nodes as $k=> $v) {
                if ($instance->has($v)) {
                    $instance = $instance->$v;
                } else {
                    return null;
                }
            }
            return $instance->value();
        }
        return null;
    }

    /**
     * 获取指定节点数据
     *
     * @access public
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
     * 取指定节点数据
     *
     * @access public
     * @param string $key
     * @return mixed
     */
    public function __get(string $key)
    {
        if ($this->has($key)) {
            return $this->_container[$key];
        } else {
            return new self();
        }
    }

    /**
     * 设置节点数据
     *
     * @access public
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
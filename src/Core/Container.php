<?php

namespace Brisk\Core;

use Countable;
use Iterator;
use ArrayAccess;

class Container implements Countable, Iterator, ArrayAccess
{

    /**
     * 配置项数组
     *
     * @access protected
     * @var array
     */
    protected $_data = array();

    /**
     * 构造函数
     *
     * @access public
     * @param array $data
     * @return mixed
     */    
    function __construct(array $data = array())
    {
        foreach ($data as $key => $val) {
            $this->_data[$key] = is_array($val) ? new self($val) : $val;
        }
    }

    /**
     * 设值
     *
     * @access public
     * @param string $name
     * @param mixed $value
     * @param bool $original
     * @return Container
     */
    function set($name, $value, $original = false)
    {
        if (is_array($value) && !$original) {
            $value = new self($value);
        }
        $this->_data[$name] = $value;
        return $this;
    }

    /**
     * 取值
     *
     * @access public
     * @param string $name
     * @return mixed
     */
    function get($name = null)
    {
        if (is_null($name)) {
            return $this->_data;
        } elseif (isset($this->_data[$name])) {
            return $this->_data[$name];
        } else {
            return null;
        }
    }

    /**
     * 合并配置对象
     *
     * @access public
     * @param $data
     * @return Container
     */
    function merge(self $data)
    {
        foreach ($data as $key => $val) {
            if (isset($this->_data[$key])) {
                if (is_int($key)) {
                    $this->_data[] = $val;
                } elseif ($val instanceof self && $this->_data[$key] instanceof self) {
                    $this->_data[$key]->merge($val);
                } else {
                    if ($val instanceof self) {
                        $this->_data[$key] = new self($val->toArray());
                    } else {
                        $this->_data[$key] = $val;
                    }
                }
            } else {
                if ($val instanceof self) {
                    $this->_data[$key] = new self($val->toArray());
                } else {
                    $this->_data[$key] = $val;
                }
            }
        }
        return $this;
    }

    /**
     * 将配置项值转化为数组
     *
     * @access public
     * @return array
     */
    function toArray()
    {
        $data = array();
        foreach ($this->_data as $key=> $val) {
            if ($val instanceof self) {
                $data[$key] = $val->toArray();
            } else {
                $data[$key] = $val;
            }
        }
        return $data;
    }

    /**
     * 魔术方法取值
     *
     * @access public
     * @param string $name
     * @return mixed
     */
    function __get($name)
    {
        return $this->get($name);
    }

    /**
     * 魔术方法设值
     *
     * @access public
     * @param string $name
     * @param mixed $value
     * @return object
     */
    function __set($name, $value)
    {
        return $this->set($name, $value);
    }

    /**
     * 检查是否设值
     *
     * @access public
     * @param string $name
     * @return bool
     */
    function __isset($name)
    {
        return isset($this->_data[$name]);
    }

    /**
     * 删除数据
     *
     * @access public
     * @param string $name
     * @return mixed
     */
    function __unset($name)
    {
        if (isset($this->_data[$name])) {
            unset($this->_data[$name]);
        }
        return $this;
    }

    /**
     * 实现计数器
     * 
     * @access public
     * @return int
     */
    function count()
    {
        return count($this->_data);
    }

    /**
     * 取数组当前值
     *
     * @access public
     * @return mixed
     */
    function current()
    {
        return current($this->_data);
    }

    /**
     * 取数组当前键名
     *
     * @access public
     * @return mixed
     */
    function key()
    {
        return key($this->_data);
    }

    /**
     * 下一个配置项
     *
     * @access public
     * @return object
     */
    function next()
    {
        next($this->_data);
        return $this;
    }

    /**
     * 重置回滚
     *
     * @access public
     * @return object
     */
    function rewind()
    {
        reset($this->_data);
        return $this;
    }

    /**
     * 当前项是否可用
     *
     * @access public
     * @return bool
     */
    function valid()
    {
        return $this->key() !== null;
    }

    /**
     * 检查是否存在
     *
     * @access public
     * @param string $name
     * @return bool
     */
    function offsetExists($name)
    {
        return $this->__isset($name);
    }

    /**
     * 数组取值
     *
     * @access public
     * @param string $name
     * @return mixed
     */
    function offsetGet($name)
    {
        return $this->__get($name);
    }

    /**
     * 数组设值
     *
     * @access public
     * @param mixed $offset
     * @param mixed $value
     * @return object
     */
    function offsetSet($offset, $value)
    {
        $this->__set($offset, $value);
        return $this;
    }

    /**
     * 数组删除
     *
     * @access public
     * @param string $name
     * @return object
     */
    function offsetUnset($name)
    {
        $this->__unset($name);
        return $this;
    }

}
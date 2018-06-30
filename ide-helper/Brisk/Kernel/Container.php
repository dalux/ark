<?php

namespace Brisk\Kernel;

class Container
{

    /**
     * 初始化容器数据
     *
     * @param mixed $data
     * @return null
     */
    public function __construct($data = null) {}

    /**
     * 是否存在节点
     *
     * @param string $key
     * @return bool
     */
    public function hasKey($key) {}

    /**
     * 当前节点下是否有内容存在
     *
     * @return bool
     */
    public function hasValue() {}

    /**
     * 获取节点最终形式内容
     *
     * @return mixed
     */
    public function getValue() {}

    /**
     * 魔术方法取值
     *
     * @param string $name
     * @return Container
     */
    public function __get($name) {}

    /**
     * 魔术方法设置值
     *
     * @param string $name
     * @param mixed $value
     * @return null
     */
    public function __set($name, $value) {}

}

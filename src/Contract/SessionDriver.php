<?php

namespace Ark\Contract;

interface SessionDriver
{

    /**
     * 启动session会话
     *
     * @access public
     * @param string $session_id
     * @return bool
     */
    function start($session_id = null);

    /**
     * 设置session数据
     *
     * @access public
     * @param string $name
     * @param mixed $value
     * @return mixed
     */
    function set($name, $value);

    /**
     * 取session数据
     *
     * @access public
     * @param string $name
     * @return mixed
     */
    function get($name);

    /**
     * 删除session数据
     *
     * @access public
     * @param string $name
     * @return mixed
     */
    function delete($name);

    /**
     * 清空session数据
     *
     * @access public
     * @return mixed
     */
    function clean();

}
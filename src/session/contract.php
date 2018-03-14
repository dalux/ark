<?php

interface Ark_Session_Contract
{

    /**
     * 启动session会话
     *
     * @access public
     * @param string $session_id
     * @return null
     */
    function start($session_id = null);

    /**
     * 取session数据
     *
     * @access public
     * @param string $name
     * @return mixed
     */
    function get($name = null);

    /**
     * 存session数据
     *
     * @access public
     * @param string $name
     * @param mixed $value
     * @return Ark_Session_Contract
     */
    function set($name, $value);

    /**
     * 删除某session值
     *
     * @access public
     * @param string $name
     * @return Ark_Session_Contract
     */
    function delete($name);

}
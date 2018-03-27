<?php

namespace Ark\Session;

use Ark\Contract\ISession;

abstract class SessionFather implements ISession
{

    /**
     * 启动session会话
     *
     * @access public
     * @param string $session_id
     * @return null
     */
    function start($session_id = null)
    {
        is_null($session_id) || session_id($session_id);
		session_cache_limiter('private,must-revalidate');
        session_start();
    }

    /**
     * 取session数据
     *
     * @access public
     * @param string $name
     * @return mixed
     */
    function get($name = null)
    {
        return is_null($name) ? $_SESSION : $_SESSION[$name];
    }

    /**
     * 存session数据
     *
     * @access public
     * @param string $name
     * @param mixed $value
     * @return SessionFather
     */
    function set($name, $value)
    {
        $_SESSION[$name] = $value;
        return $this;
    }

    /**
     * 删除某session值
     *
     * @access public
     * @param string $name
     * @return SessionFather
     */
    function delete($name)
    {
        unset($_SESSION[$name]);
        return $this;
    }

    /**
     * 清理session数据
     *
     * @access public
     * @return bool
     */
    function clean()
    {
        return session_destroy();
    }

    /**
     * 取session数据
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
     * 存session数据
     *
     * @access public
     * @param string $name
     * @param mixed $value
     * @return mixed
     */
    function __set($name, $value)
    {
        return $this->set($name, $value);
    }

}
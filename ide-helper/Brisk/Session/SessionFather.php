<?php

namespace Brisk\Session;

abstract class SessionFather implements \Brisk\Contract\ISession
{

    /**
     * 启动会话
     *
     * @param int $session_id
     * @return null
     */
    public function start($session_id = 0) {}

    /**
     * 获取会话内容
     *
     * @param string $name
     * @return mixed
     */
    public function get($name = "") {}

    /**
     * 设置会话内容
     *
     * @param string $name
     * @param mixed $value
     * @return SessionFather
     */
    public function set($name, $value) {}

    /**
     * 删除会话内容
     *
     * @param string $name
     * @return SessionFather
     */
    public function delete($name) {}

    /**
     * 清空会话内容
     *
     */
    public function clean() {}

    /**
     * 魔术方法取值
     *
     * @param string $name
     * @return mixed
     */
    public function __get($name) {}

    /**
     * 魔术方法设值
     *
     * @param string $name
     * @param mixed $value
     * @return null
     */
    public function __set($name, $value) {}

}

<?php

namespace Brisk\Contract;

interface ISession
{

    /**
     * 开始会话
     *
     * @param int $session_id
     * @return null
     */
    public function start($session_id = 0);

    /**
     * 获取会话内容
     *
     * @param string $name
     * @return mixed
     */
    public function get($name = "");

    /**
     * 设置会话内容
     *
     * @param string $name
     * @param mixed $value
     * @return ISession
     */
    public function set($name, $value);

    /**
     * 删除会话内容
     *
     * @param string $name
     * @return ISession
     */
    public function delete($name);

}

<?php

namespace Brisk\Session;

class UserSession extends \Brisk\Session\SessionFather
{

    /**
     * 构造器
     *
     */
    public function __construct() {}

    /**
     * 打开会话
     *
     * @param string $save_path
     * @param string $session_name
     * @return null
     */
    public function open($save_path, $session_name) {}

    /**
     * 关闭会话
     *
     * @return null
     */
    public function close() {}

    /**
     * 读取会话内容
     *
     * @param int $session_id
     * @return mixed
     */
    public function read($session_id) {}

    /**
     * 写入会话内容
     *
     * @param int $session_id
     * @param mixed $session_data
     * @return null
     */
    public function write($session_id, $session_data) {}

    /**
     * 销毁会话
     *
     * @param int $session_id
     * @return null
     */
    public function destroy($session_id) {}

    /**
     * GC
     *
     * @param int $max_lifetime
     * @return null
     */
    public function gc($max_lifetime) {}

}

<?php declare(strict_types=1);

namespace Brisk\Session;

interface ISessionDriver
{

    /**
     * 开启session支持
     *
     * @access public
     * @param int $session_id
     * @return void
     */
    public function start(int $session_id = null);

    /**
     * 设置session过期时间
     *
     * @access public
     * @param int $expire_time
     * @return ISessionDriver
     */
    public function setExpireTime(int $expire_time = 1440);

    /**
     * 获取session数据
     *
     * @access public
     * @param string $name
     * @return mixed
     */
    public function get(string $name = null);
    
    /**
     * 设置session数据
     *
     * @access public
     * @param string $name
     * @param mixed $value
     * @return ISessionDriver
     */
    public function set(string $name, $value);

    /**
     * 删除session数据
     *
     * @access public
     * @param string $name
     * @return ISessionDriver
     */
    public function delete(string $name);

    /**
     * 清空session数据
     *
     * @access public
     * @return void
     */
    public function clean();

}
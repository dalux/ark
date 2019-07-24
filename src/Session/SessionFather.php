<?php declare(strict_types=1);

namespace Brisk\Session;

abstract class SessionFather implements ISessionDriver
{

    /**
     * session过期时间
     * 
     * @var int
     */
    protected $_expire_time = 1440;

    /**
     * 构造函数
     *
     * @access public
     * @param array $option
     * @return void
     */
    public function __construct(array $option = [])
    {
        if ($option['setting'] && is_array($option['setting'])) {
            foreach ($option['setting'] as $k=> $v) {
                ini_set($k, $v);
            }
        }
    }

    /**
     * 设置session过期时间
     *
     * @access public
     * @param int $expire_time
     * @return SessionFather
     */
    public function setExpireTime(int $expire_time = 1440)
    {
        $this->_expire_time = $expire_time;
        return $this;
    }

    /**
     * 开启session会话
     *
     * @access public
     * @param string $session_id
     * @return void
     */
    public function start(string $session_id = null)
    {
        if (!is_null($session_id)) {
			session_id($session_id);
		}
		session_cache_limiter('private,must-revalidate');
        session_start();
    }

    /**
     * 获取session数据
     *
     * @access public
     * @param string $name
     * @return mixed
     */
    public function get(string $name = null)
    {
        return is_null($name) ? $_SESSION : $_SESSION[$name];
    }

    /**
     * 设置session数据
     *
     * @access public
     * @param string $name
     * @param mixed $value
     * @return SessionFather
     */
    public function set(string $name, $value)
    {
        $_SESSION[$name] = $value;
        return $this;
    }

    /**
     * 删除session数据
     *
     * @access public
     * @param string $name
     * @return SessionFather
     */
    public function delete(string $name)
    {
        unset($_SESSION[$name]);
        return $this;
    }

    /**
     * 清空session数据
     *
     * @access public
     * @return void
     */
    public function clean()
    {
        return session_destroy();
    }

}
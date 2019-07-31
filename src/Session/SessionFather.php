<?php declare(strict_types=1);

namespace Brisk\Session;

use Brisk\Kernel\Language;
use Brisk\Exception\SessionStartException;

abstract class SessionFather implements ISessionDriver
{

    /**
     * session过期时间
     * 
     * @var int
     */
    protected $_expire_time = 1440;

    /**
     * session附加设置项
     *
     * @var array
     */
    protected $_option = [];

    /**
     * 构造函数
     *
     * @access public
     * @param array $setting
     * @return void
     */
    public function __construct(array $setting = [])
    {
        if (isset($setting['option']) && is_array($setting['option'])) {
            foreach ($setting['option'] as $key=> $val) {
                if (strpos($key, 'session.') !== false) {
                    $key = str_replace('session.', '', $key);
                    $this->_option[$key] = $val;
                }
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
        is_null($session_id) ||  session_id($session_id);
        //使返回上一页时表单中数据依然可用
        session_cache_limiter('private,must-revalidate');
        //会话启动失败时抛出异常
        if (!session_start($this->_option)) {
            throw new SessionStartException(Language::format('core.session_start_failed'));
        }
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
        if (is_null($name)) {
            return $_SESSION;
        }
        return $_SESSION[$name] ?? null;
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
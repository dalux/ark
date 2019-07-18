<?php declare(strict_types=1);

namespace Brisk\Cache;

abstract class CacheFather implements ICacheDriver
{

    /**
     * 缓存目录标识
     * 
     * @var string
     */
    protected $_flag;

    /**
     * 格式化缓存名称函数
     *
     * @var callable
     */
    protected $_format;

    /**
     * 当前是否缓存模式
     *
     * @var bool
     */
    protected $_caching = true;

    /**
     * 缓存默认过期时间
     *
     * @var int
     */
    protected $_expire_time = 86400;

    /**
     * 默认构造方法
     *
     * @access public
     * @param array $setting
     */
    public function __construct(array $setting = [])
    {
        foreach ($setting as $key=> $val) {
            switch ($key) {
                case 'flag':
                    $this->_flag = $val;
                    break;
                case 'expire_time':
                    $this->_expire_time = $val;
                    break;
                case 'format':
                    $this->_format = $val;
                    break;
            }
        }
    }

    /**
     * 设置缓存标识
     *
     * @access public
     * @param string $flag
     * @return CacheFather
     */
    public function setFlag(string $flag)
    {
        $this->_flag = $flag;
        return $this;
    }

    /**
     * 设置格式化缓存名称的方法
     *
     * @access public
     * @param callable $format
     * @return CacheFather
     */
    public function setFormat(callable $format)
    {
        $this->_format = $format;
        return $this;
    }

    /**
     * 设置当前缓存是否生效
     *
     * @access public
     * @param bool $caching
     * @return CacheFather
     */
    public function setCaching(bool $caching = true)
    {
        $this->_caching = $caching;
        return $this;
    }

    /**
     * 设置默认缓存过期时间
     *
     * @access public
     * @param int $expire_time
     * @return CacheFather
     */
    public function setExpireTime(int $expire_time = 86400)
    {
        $this->_expire_time = $expire_time;
        return $this;
    }

    /**
     * 设置缓存数据
     *
     * @access public
     * @param string $name
     * @param mixed $value
     * @param int $expire
     * @return bool
     */
    public abstract function set(string $name, $value, int $expire = 0);

    /**
     * 获取缓存数据
     *
     * @access public
     * @param string $name
     * @return mixed
     */
    public abstract function get(string $name);

    /**
     * 删除缓存数据
     *
     * @access public
     * @param string $name
     * @return bool
     */
    public abstract function delete(string $name);

    /**
     * 获取缓存存储路径
     *
     * @access public
     * @param string $name
     * @return string
     */
    public abstract function getCachePath(string $name);

}

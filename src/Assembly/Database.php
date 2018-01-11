<?php

namespace Ark\Assembly;

use Ark\Core\Noah;
use Ark\Core\Loader;
use Ark\Core\Trace;
use Ark\Assembly\Database\Exception;
use Ark\Contract\Database as DbInterface;

class Database
{

    /**
     * 获取数据库引擎实例
     *
     * @access public
     * @static
     * @param $name
     * @throws Exception
     */
    static function getDriver($name)
    {
        $config = Noah::getInstance()->config->database->$name;
        if (!$config) {
            throw new Exception(Noah::getInstance()->lang->get('db.config_not_found', $name));
        }
        /* @var \Ark\Core\Container $config */
        $config = $config->toArray();
        $driver = $config['driver'];
        $dsn = $config['dsn'];
        $option = $config['option'];
        if (!Loader::findClass($driver)) {
            throw new Exception(Noah::getInstance()->lang->get('db.driver_not_found', $driver));
        }
        $instance = new $driver($dsn, $option);
        if (!$instance instanceof DbInterface) {
            throw new Exception(Noah::getInstance()->lang->get('db.driver_implement_error', $driver, '\\Ark\\Contract\\Database'));
        }
        Trace::set('driver', array('database'=> sprintf('%s[%s]', $name, $driver)));
        return $instance;
    }

    /**
     * 设置SQL取值的偏移量
     *
     * @access public
     * @param integer $limit 每页显示数据量
     * @param integer $page 当前页数
     * @param integer $count 总数据量
     * @return integer
     */
    static function getOffset($limit, $page, $count = 0)
    {
        if ($count) {
            $maxpage = self::getMaxPages($limit, $count);
            $page > $maxpage && $page = $maxpage;
        }
        return $limit * ($page > 0 ? $page - 1 : 0);
    }

    /**
     * 当前数据库最大分页数
     *
     * @access public
     * @param integer $limit 每页显示数据量
     * @param integer $count 总数据量
     * @return integer
     */
    static function getMaxPages($limit, $count = 0)
    {
        return ceil($count/$limit);
    }

    /**
     * 解析数据库连接字符串
     *
     * @access public
     * @param string $url
     * @return mixed
     * @throws Exception
     */
    static function parseConnectUrl($url)
    {
        if (!$parsed = parse_url($url)) {
            throw new Exception(Noah::getInstance()->lang->get('db.invalid_conn_string', $url));
        }
        $config = array(
            'type'=> $parsed['scheme'],
            'host'=> $parsed['host'],
            'port'=> $parsed['port'],
            'user'=> $parsed['user'],
            'pass'=> $parsed['pass'],
            'name'=> trim($parsed['path'], '/'),
        );
        if ($query = $parsed['query']) {
            $query = explode('&', $query);
            foreach ($query as $key=> $val) {
                $expr = explode('=', $val);
                if ($expr[0] && $expr[1] !== '') {
                    $config[$expr[0]] = $expr[1];
                }
            }
        }
        return $config;
    }

}


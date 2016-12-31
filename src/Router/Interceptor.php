<?php

namespace Ark\Router;

use Ark\Core\Captain;

class Interceptor
{

    /**
     * 拦截器
     *
     * @var array
     */
    private static $_interceptor = array();

    /**
     * 添加拦截器规则
     *
     * @param $subspace
     * @param $operator
     * @throws Exception
     */
    static function add($subspace, $operator)
    {
        $subspace = trim($subspace, '\\');
        if (!is_callable($operator)) {
            throw new Exception(sprintf(Captain::getInstance()->lang->get('router.invalid_router_interceptor'), $subspace));
        }
        self::$_interceptor[$subspace] = $operator;
    }

    /**
     * 获取指定类的拦截器
     *
     * @param $namespace
     * @return mixed
     */
    static function get($namespace)
    {
        $namespace = trim($namespace, '\\');
        $result = array();
        foreach (self::$_interceptor as $subspace=> $operator) {
            if (strpos($namespace, $subspace) !== false) {
                $result[$subspace] = $operator;
            }
        }
        //按subspace长短来重新排序
        if ($result) {
            uksort($result, function ($a, $b) {
                $len_a = strlen($a);
                $len_b = strlen($b);
                if ($len_a == $len_b) {
                    return 0;
                }
                return $len_a > $len_b ? 1 : -1;
            });
        }
        return $result;
    }

}
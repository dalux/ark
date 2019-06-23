<?php declare(strict_types=1);

namespace Brisk\Kernel;

use Brisk\Exception\RuntimeException;

class Toolkit
{

    /**
     * Get array variable string
     *
     * @param mixed $params
     * @return string
     */
    public static function sprintr($params)
    {
        ob_start();
        print_r($params);
        return preg_replace('/\\]\\=\\>\\n(\\s+)/m', '] => ', ob_get_clean());
    }

    /**
     * Formatted print variable
     *
     * @param mixed $params
     * @return void
     */
    public static function printr(...$params)
    {
        foreach ($params as $val) {
            $result = self::sprintr($val);
            echo sprintf('<pre>%s</pre>', htmlspecialchars($result));
        }
    }

    /**
     * Get array variable string
     *
     * @param mixed $params
     * @return string
     */
    public static function svardump($params)
    {
        ob_start();
        var_dump($params);
        return preg_replace('/\\]\\=\\>\\n(\\s+)/m', '] => ', ob_get_clean());
    }

    /**
     * Formatted print variable
     *
     * @param mixed $params
     * @return void
     */
    public static function vardump(...$params)
    {
        foreach ($params as $val) {
            $result = self::svardump($val);
            echo sprintf('<pre>%s</pre>', htmlspecialchars($result));
        }
    }

    /**
     * 判断是否是手机号码
     *
     * @access public
     * @static
     * @param string $mobile
     * @return bool
     */
    static function isMobile(string $mobile)
    {
        if (!is_numeric($mobile)) return false;
        return preg_match('#^13[\d]{9}$|^14[5,7]{1}\d{8}$|^15[\d]{9}$|^166[\d]{8}$|^17[\d]{9}$|^18[\d]{9}$|^19[8,9]{1}\d{8}$|^1980000[\d]{4}$#', $mobile) ? true : false;
    }

}
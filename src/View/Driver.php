<?php

namespace Ark\View;

use Ark\Core\Sailor;

abstract class Driver extends Sailor
{

    /**
     * 赋值
     *
     * @access public
     * @param string $var 变量名
     * @param mixed $val 变量值
     * @return Driver
     */
    abstract function set($var, $val = null);

    /**
     * 取值
     *
     * @access public
     * @param string $var 变量名
     * @return mixed
     */
    abstract function get($var = null);

    /**
     * 呈现
     *
     * @access public
     * @param string $template 模板文件路径
     * @param bool $return
     * @return string
     */
    abstract function display($template, $return = false);

}
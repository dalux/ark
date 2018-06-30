<?php

namespace Brisk\View;

class NativeView extends \Brisk\View\ViewFather
{

    /**
     * 构造器
     *
     */
    public function __construct() {}

    /**
     * 设置模板变量
     *
     * @param string $name
     * @param mixed $val
     * @return NativeView
     */
    public function set($name, $val = null) {}

    /**
     * 获取模板变量
     *
     * @param string $name
     * @return mixed
     */
    public function get($name = "") {}

    /**
     * 呈现视图模板
     *
     * @param string $template
     * @param bool $output
     * @return mixed
     */
    public function display($template, $output = true) {}

    /**
     * 导入视图模板
     *
     * @param string $path
     * @param array $params
     * @param bool $output
     * @return mixed
     */
    public function import($path, array $params = array(), $output = true) {}

}

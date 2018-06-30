<?php

namespace Brisk\View;

abstract class ViewFather implements \Brisk\Contract\IView
{

    /**
     * 设置模板变量
     *
     * @param string $name
     * @param mixed $val
     * @return ViewFather
     */
    public abstract function set($name, $val = null);

    /**
     * 获取模板变量
     *
     * @param string $name
     * @return mixed
     */
    public abstract function get($name = null);

    /**
     * 呈现视图模板
     *
     * @param string $template
     * @param bool $output
     * @return mixed
     */
    public abstract function display($template, $output = true);

}

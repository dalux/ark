<?php

namespace Brisk\Contract;

interface IView
{

    /**
     * 设置模板变量
     *
     * @param string $name
     * @param mixed $val
     * @return ISession
     */
    public function set($name, $val = "");

    /**
     * 获取模板变量
     *
     * @param string $name
     * @return mixed
     */
    public function get($name = "");

    /**
     * 显示视图结果
     *
     * @param string $template
     * @param bool $output
     * @return mixed
     */
    public function display($template, $output = true);

}

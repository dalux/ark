<?php declare(strict_types=1);

namespace Brisk\View;

abstract class ViewFather implements IViewDriver
{

    /**
     * 设置模板变量
     *
     * @access public
     * @param string $name
     * @param mixed $val
     * @return IViewDriver
     */
    public abstract function set(string $name, $val = null);

    /**
     * 获取模板变量
     *
     * @access public
     * @param string name
     * @return mixed
     */
    public abstract function get(string $name = null);

    /**
     * 渲染模板
     *
     * @access public
     * @param string $template
     * @return string
     */
    public abstract function render(string $template);

}
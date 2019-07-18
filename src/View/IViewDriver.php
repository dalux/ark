<?php declare(strict_types=1);

namespace Brisk\View;

interface IViewDriver
{

    /**
     * 设置模板数据
     *
     * @access public
     * @param string $name
     * @param mixed $val
     * @return IViewDriver
     */
    public function set(string $name, $val = null);

    /**
     * 获取模板数据
     *
     * @access public
     * @param string $name
     * @return mixed
     */
    public function get(string $name = null);

    /**
     * 渲染模板
     *
     * @access public
     * @param string $template
     * @return string
     */
    public function render(string $template);

}
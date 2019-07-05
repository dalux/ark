<?php declare(strict_types=1);

namespace Brisk\View;

interface IViewDriver
{

    /**
     * Set template data
     *
     * @param string name
     * @param mixed val
     * @return IViewDriver
     */
    public function set(string $name, $val = null);

    /**
     * Get template data
     *
     * @param string name
     * @return mixed
     */
    public function get(string $name = null);

    /**
     * Rendering template data
     *
     * @param string template
     * @return string
     */
    public function render(string $template);

}
<?php declare(strict_types=1);

namespace Brisk\View;

abstract class ViewFather
{

    /**
     * Set template data
     *
     * @param string name
     * @param mixed val
     * @return ViewFather
     */
    public abstract function set(string $name, $val = null);

    /**
     * Get template data
     *
     * @param string name
     * @return mixed
     */
    public abstract function get(string $name = null);

    /**
     * Rendering template data
     *
     * @param string template
     * @return string
     */
    public abstract function display(string $template);

}
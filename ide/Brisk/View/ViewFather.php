<?php

namespace Brisk\View;


abstract class ViewFather
{

    /**
     * Set template data
     *
     * @param string $name
     * @param mixed $val
     * @return ViewFather
     */
    public abstract function set($name, $val = null);

    /**
     * Get template data
     *
     * @param string $name
     * @return mixed
     */
    public abstract function get($name = null);

    /**
     * Rendering template data
     *
     * @param string $template
     * @param bool $output
     * @return string
     */
    public abstract function display($template, $output = true);

}

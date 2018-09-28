<?php

namespace Brisk\Vendor\View;


class Native extends \Brisk\Vendor\View\ViewFather
{

    private $_storage = array();


    private $_template_ext = '.phtml';


    private $_template_dir;


    /**
     * Construct
     *
     * @param array $options
     * @return mixed
     */
    public function __construct(array $options = array()) {}

    /**
     * Set template data
     *
     * @param string $name
     * @param mixed $val
     * @return Native
     */
    public function set($name, $val = null) {}

    /**
     * Get template data
     *
     * @param string $name
     * @return mixed
     */
    public function get($name = '') {}

    /**
     * Rendering template data
     *
     * @param string $template
     * @param bool $output
     * @return string
     */
    public function display($template, $output = true) {}

    /**
     * Import template file
     *
     * @param string $path
     * @param array $params
     * @param bool $output
     * @return string
     */
    public function import($path, array $params = array(), $output = true) {}

}

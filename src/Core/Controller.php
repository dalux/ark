<?php

namespace Ark\Core;

use Ark\Com\View\RuntimeException as ViewRuntimeException;

abstract class Controller extends Sailor
{

    /**
     *  模板路径
     *
     * @var string
     */
    protected $_template;

    /**
     * 设置模板文件路径
     *
     * @access public
     * @param string $template
     * @return mixed
     */
    final function setTemplate($template)
    {
        $this->_template = $template;
        return $this;
    }

    /**
     * 呈现模板
     *
     * @access public
     * @param string $template 模板路径
     * @return string
     * @throws ViewRuntimeException
     */
    final function display($template = null)
    {
        if (!is_null($template)) {
            $this->_template = $template;
        } elseif (is_null($this->_template)) {
            throw new ViewRuntimeException($this->language->get('com.invalid_view_template'));
        }
        return $this->view->display($this->_template);
    }

}
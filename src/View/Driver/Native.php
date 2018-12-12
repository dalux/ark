<?php

namespace Brisk\View\Driver;

use Brisk\Kernel\Event;
use Brisk\Kernel\Language;
use Brisk\Kernel\Loader;
use Brisk\View\ViewFather;
use Brisk\Exception\RuntimeException;

class Native extends ViewFather
{

    /**
     * @var array
     */
    private $_storage = [];

    /**
     * @var mixed|string
     */
    private $_template_ext = '.phtml';

    /**
     * @var string
     */
    private $_template_dir;

    /**
     * Construct
     *
     * @param array options
     * @return mixed
     */
    public function __construct(array $options = [])
    {
		if (isset($options['template_ext'])) {
			$this->_template_ext = $options['template_ext'];
		}
		if (isset($options['template_dir'])) {
			$this->_template_dir = rtrim($options['template_dir'], DIRECTORY_SEPARATOR);
		}
    }

    /**
     * Set template data
     *
     * @param string name
     * @param mixed val
     * @return ViewFather
     */
    public function set($name, $val = null)
    {
        $this->_storage[$name] = $val;
        return $this;
    }

    /**
     * Get template data
     *
     * @param string name
     * @return mixed
     */
    public function get($name = null)
    {
        return is_null($name) ? $this->_storage : $this->_storage[$name];
    }

    /**
     * Rendering template data
     *
     * @param string template
     * @param bool output
     * @return string
     */
    public function display($template, $output = true)
    {
        if (strpos($template, $this->_template_ext) === false) {
            $template = $template. $this->_template_ext;
        }
        $template = $this->_template_dir. DIRECTORY_SEPARATOR. $template;
        if (!is_file($template)) {
            throw new RuntimeException(Language::get('view.template_not_found', Loader::reducePath($template)));
        }
        $data = [
            'template'=> $template,
            'driver'=> 'Native'
        ];
		$data = Event::trigger('event.view.before', $data);
        extract($this->_storage, EXTR_REFS);
        ob_start();
        include($template);
        $data['content'] = ob_get_clean();
        $data = Event::trigger('event.view.finish', $data);
        if ($output) {
			echo $data['content'];
            exit;
        }
        return $data['content'];
    }

    /**
     * Import template file
     *
     * @param string path
     * @param array params
     * @param bool output
     * @return string
     */
    public function import($path, array $params = [], $output = true)
    {
        if (strpos($path, $this->_template_ext) === false) {
            $path = $path. $this->_template_ext;
        }
		$template = $this->_template_dir. DIRECTORY_SEPARATOR. $path;
        if (!is_file($template)) {
            throw new RuntimeException(Language::get('view.include_file_not_found', Loader::reducePath($template)));
        }
        extract($this->_storage, EXTR_REFS);
        extract($params, EXTR_SKIP);
        ob_start();
        include($template);
		$content = ob_get_clean();
        if ($output) {
            echo $content;
        }
        return $content;
    }

}
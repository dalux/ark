<?php declare(strict_types=1);

namespace Brisk\View\Driver;

use Brisk\Kernel\Event;
use Brisk\Kernel\Language;
use Brisk\Kernel\Loader;
use Brisk\View\ViewFather;
use Brisk\Exception\RuntimeException;

class Native extends ViewFather
{

    /**
     * 模板数据
     * 
     * @var array
     */
    private $_storage = [];

    /**
     * 模板文件后缀名
     *
     * @var string
     */
    private $_template_ext = '.phtml';

    /**
     * 模板文件存储目录
     *
     * @var string
     */
    private $_template_dir;

    /**
     * 构造函数
     *
     * @access public
     * @param array $options
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
     * 设置模板变量
     *
     * @access public
     * @param string $name
     * @param mixed $val
     * @return ViewFather
     */
    public function set(string $name, $val = null)
    {
        $this->_storage[$name] = $val;
        return $this;
    }

    /**
     * 获取模板变量
     *
     * @access public
     * @param string $name
     * @return mixed
     */
    public function get(string $name = null)
    {
        return is_null($name) ? $this->_storage : $this->_storage[$name];
    }

    /**
     * 渲染模板
     *
     * @access public
     * @param string $template
     * @return string
     */
    public function render(string $template)
    {
        if (strpos($template, $this->_template_ext) === false) {
            $template = $template. $this->_template_ext;
        }
        $template = $this->_template_dir. DIRECTORY_SEPARATOR. $template;
        if (!is_file($template)) {
            throw new RuntimeException(Language::format('view.template_not_found', Loader::reducePath($template)));
        }
        $data = [
            'template'=> $template,
            'driver'=> 'Native'
        ];
		$data = Event::fire('event.view.before', $data);
        extract($this->_storage, EXTR_REFS);
        ob_start();
        include($template);
        $data['content'] = ob_get_clean();
        $data = Event::fire('event.view.finish', $data);
        return $data['content'];
    }

    /**
     * 导入模板文件
     *
     * @access public
     * @param string $path
     * @param array $params
     * @return string
     */
    public function import(string $path, array $params = [])
    {
        if (strpos($path, $this->_template_ext) === false) {
            $path = $path. $this->_template_ext;
        }
		$template = $this->_template_dir. DIRECTORY_SEPARATOR. $path;
        if (!is_file($template)) {
            throw new RuntimeException(Language::format('view.include_file_not_found', Loader::reducePath($template)));
        }
        extract($this->_storage, EXTR_REFS);
        extract($params, EXTR_SKIP);
        ob_start();
        include($template);
        return ob_get_clean();
    }

}
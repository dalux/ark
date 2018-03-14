<?php

class Ark_View_Native extends Ark_View_Father
{

    /**
     * 数据存储空间
     *
     * @access private
     * @var array
     */
    private $_storage = array();

    /**
     * 默认模板引擎文件后缀名
     *
     * @access private
     * @var string
     */
    private $_template_ext = '.phtml';

    /**
     * 默认模板引擎文件存放目录
     *
     * @access private
     * @var string
     */
    private $_template_dir;

    /**
     * 构造器
     *
     */
    function __construct()
    {
        $config = Ark_Core::getInst()->config->view;
        $config->template_ext && $this->_template_ext = $config->template_ext;
        $config->template_dir && $this->_template_dir = rtrim($config->template_dir, DIRECTORY_SEPARATOR);
    }

    /**
     * 设值
     *
     * @access public
     * @param mixed $var
     * @param mixed $val
     * @return Ark_View_Father
     */
    function set($var, $val = null)
    {
        if (is_array($var)) {
            foreach ($var as $k=> $v) {
                if (is_string($k)) {
                    $this->_storage[$k] = $v;
                }
            }
        } else {
            $this->_storage[$var] = $val;
        }
        return $this;
    }

    /**
     * 取值
     *
     * @access public
     * @param string $var
     * @return mixed
     */
    function get($var = null)
    {
        return is_null($var) ? $this->_storage : $this->_storage[$var];
    }

    /**
     * 呈现页面
     *
     * @access public
     * @param string $template
     * @param bool $return
     * @return string
     * @throws Ark_View_Exception
     * @throws Exception
     */
    function display($template, $return = false)
    {
        if (strpos($template, $this->_template_ext) === false) {
            $template.= $this->_template_ext;
        }
        $template = $this->_template_dir. DIRECTORY_SEPARATOR. $template;
        if (!is_file($template)) {
            throw new Ark_View_Exception(Ark_Core::getInst()->lang->get('view.template_not_found', Ark_Loader::reducePath($template)));
        }
        $data = array(
            'template'=> $template,
            'driver'=> 'Native',
        );
        $data = Ark_Event::onListening('event.view.before', $data);
        extract($this->_storage, EXTR_REFS);
        ob_start();
        include_once($template);
        $data['content'] = ob_get_clean();
        $data = Ark_Event::onListening('event.view.finish', $data);
        if (!$return) {
            exit($data['content']);
        }
        return $data['content'];
    }

    /**
     * 载入其他模板文件，以模板根目录为基准
     *
     * @access public
     * @param string $path 模板文件
     * @param array $params 参数
     * @param bool $return
     * @return mixed
     * @throws Ark_View_Exception
     * @throws Exception
     */
    function import($path, $params = array(), $return = false)
    {
        if (strpos($path, $this->_template_ext) === false) {
            $path.= $this->_template_ext;
        }
        $template = $this->_template_dir. DIRECTORY_SEPARATOR. $path;
        if (!is_file($template)) {
            throw new Ark_View_Exception(Ark_Core::getInst()->lang->get('view.include_file_not_found', Ark_Loader::reducePath($template)));
        }
        extract($this->_storage, EXTR_REFS);
        extract($params, EXTR_SKIP);
        ob_start();
        include_once($template);
        $content = ob_get_clean();
        if (!$return) {
            echo $content;
        }
        return $content;
    }

}
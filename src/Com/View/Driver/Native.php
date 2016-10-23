<?php

namespace Ark\Com\View\Driver;

use Ark\Core\Loader;
use Ark\Core\Noah;
use Ark\Core\Sailor;
use Ark\Core\Struct;
use Ark\Contract\ViewDriver;
use Ark\Com\Event\Adapter as EventAdapter;

class Native extends Sailor implements ViewDriver
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
        $this->_template_dir = Loader::realPath('./view/');
        $config = Noah::getInstance()->config->view;
        $config->template_ext && $this->_template_ext = $config->template_ext;
        $config->template_dir && $this->_template_dir = rtrim($config->template_dir, DIRECTORY_SEPARATOR);
    }

    /**
     * 设值
     *
     * @access public
     * @param mixed $var
     * @param mixed $val
     * @return ViewDriver
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
     * @throws RuntimeException
     */
    function display($template, $return = true)
    {
        if (strpos($template, $this->_template_ext) === false) {
            $template.= $this->_template_ext;
        }
        $template = $this->_template_dir. DIRECTORY_SEPARATOR. $template;
        if (!is_file($template)) {
            throw new RuntimeException(sprintf(Noah::getInstance()->language->get('view.template_not_found'), Loader::reducePath($template)));
        }
        $data = array(
            'template'=> $template,
            'driver'=> 'Native',
        );
        $rule = array(
            'driver'    => array(Struct::FLAG_REQUIRED=> true, Struct::FLAG_TYPE=> Struct::TYPE_STRING),
            'template'  => array(Struct::FLAG_REQUIRED=> true, Struct::FLAG_TYPE=> Struct::TYPE_STRING),
        );
        $data = EventAdapter::onListening('event.view.before', $data, $rule);
        extract($this->_storage, EXTR_REFS);
        ob_start();
        include_once($template);
        $data['content'] = ob_get_clean();
        $rule = array(
            'driver'    => array(Struct::FLAG_REQUIRED=> true, Struct::FLAG_TYPE=> Struct::TYPE_STRING),
            'template'  => array(Struct::FLAG_REQUIRED=> true, Struct::FLAG_TYPE=> Struct::TYPE_STRING),
            'content'   => array(Struct::FLAG_REQUIRED=> true, Struct::FLAG_TYPE=> Struct::TYPE_STRING),
        );
        $data = EventAdapter::onListening('event.view.finish', $data, $rule);
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
     * @throws RuntimeException
     */
    function import($path, $params = array(), $return = false)
    {
        if (strpos($path, $this->_template_ext) === false) {
            $path.= $this->_template_ext;
        }
        $template = $this->_template_dir. DIRECTORY_SEPARATOR. $path;
        if (!is_file($template)) {
            throw new RuntimeException(sprintf(Noah::getInstance()->language->get('view.include_file_not_found'), Loader::reducePath($template)));
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
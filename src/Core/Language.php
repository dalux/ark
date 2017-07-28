<?php

namespace Ark\Core;

class Language
{

    /**
     * 语言包存放路径
     *
     * @var array
     */
    private $_path = array();

    /**
     * 语言包名称
     *
     * @var string
     */
    private $_language = 'Chinese';

    /**
     * 当前语言包内容
     *
     * @var array
     */
    private $_package = array();

    /**
     * 构造器
     *
     * @throws Exception
     */
    function __construct()
    {
        $this->addPath(Loader::realPath('*/Language'));
    }

    /**
     * 添加语言包文件夹
     *
     * @param $path
     * @return $this
     */
    function addPath($path)
    {
        if (is_dir($path)) {
            $this->_path[] = $path;
            $this->restore();
        }
        return $this;
    }

    /**
     * 选择语言
     *
     * @param $language
     * @return $this
     */
    function choose($language)
    {
        $this->_language = $language;
        $this->restore();
        return $this;
    }

    /**
     * 重新整理语言包数据
     *
     * @return $this
     */
    function restore()
    {
        $package = array();
        foreach ($this->_path as $path) {
            $file = $path. DIRECTORY_SEPARATOR . ucfirst($this->_language). '.php';
            if (is_file($file)) {
                $data = include($file);
                if (is_array($data)) {
                    $package += $data;
                }
            }
        }
        $this->_package = $package;
        return $this;
    }

    /**
     * 解析语言包标签
     *
     * @param $label
     * @return mixed
     */
    function get($label)
    {
        $args = func_get_args();
        $label = array_shift($args);
        return vsprintf($this->_package[$label], $args);
    }

}
<?php

namespace Ark\Core;

class Language
{

    /**
     * 语言包文件夹路径
     *
     * @var array
     */
    private $_package = array();

    /**
     * 当前语言文件名
     *
     * @var string
     */
    private $_language = 'zh_cn';

    /**
     * 当前语言包条目清单
     *
     * @var array
     */
    private $_list = array();

    /**
     * 构造器
     *
     * @throws Exception
     */
    function __construct()
    {
        $this->addPackage(Loader::realPath('*/Language'));
    }

    /**
     * 添加语言包文件夹
     *
     * @param $path
     * @return $this
     */
    function addPackage($path)
    {
        if (is_dir($path)) {
            $this->_package[] = $path;
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
    function locate($language)
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
        $list = array();
        foreach ($this->_package as $path) {
            $file = $path. DIRECTORY_SEPARATOR . strtolower($this->_language). '.php';
            if (is_file($file)) {
                $data = include($file);
                if (is_array($data)) {
                    $list += $data;
                }
            }
        }
        $this->_list = $list;
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
        if ($args > 1) {
            $label = array_shift($args);
        }
        return vsprintf($this->_list[$label], $args);
    }

}
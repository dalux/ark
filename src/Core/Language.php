<?php

namespace Ark\Core;

class Language
{

    /**
     * 语言包文件夹路径
     *
     * @var array
     */
    private static $_package = array();

    /**
     * 当前语言文件名
     *
     * @var string
     */
    private static $_language = 'zh_cn';

    /**
     * 当前语言包条目清单
     *
     * @var array
     */
    private static $_list = array();

    /**
     * 添加语言包文件夹
     *
     * @param $path
     * @return void
     */
    static function addPackage($path)
    {
        if (is_dir($path)) {
            self::$_package[] = $path;
            self::restore();
        }
    }

    /**
     * 选择语言
     *
     * @param $language
     * @return void
     */
    static function setLanguage($language)
    {
        self::$_language = $language;
        self::restore();
    }

    /**
     * 重新整理语言包数据
     *
     * @return void
     */
    static function restore()
    {
        $list = array();
        foreach (self::$_package as $path) {
            $file = $path. DIRECTORY_SEPARATOR . strtolower(self::$_language). '.php';
            if (is_file($file)) {
                $data = include($file);
                if (is_array($data)) {
                    $list += $data;
                }
            }
        }
        self::$_list = $list;
    }

    /**
     * 解析语言包标签
     *
     * @param $label
     * @return mixed
     */
    static function get($label)
    {
        $args = func_get_args();
        if ($args > 1) {
            $label = array_shift($args);
        }
        if (!$result = vsprintf(self::$_list[$label], $args)) {
            $result = self::$_list[$label];
        }
        return $result;
    }

}
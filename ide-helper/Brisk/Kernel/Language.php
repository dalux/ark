<?php

namespace Brisk\Kernel;

class Language
{

    /**
     * 添加语言包
     *
     * @param string $language
     * @param string $path
     * @return null
     */
    public static function addPackage($language, $path) {}

    /**
     * 获取语言包
     *
     * @param string $language
     * @return array
     */
    public static function getPackage($language = "") {}

    /**
     * 设置当前语言
     *
     * @param string $language
     * @return null
     */
    public static function setLanguage($language) {}

    /**
     * 获取语言标签内容
     *
     * @param string $label
     * @param array $params
     * @return string
     */
    public static function get($label, array $params = array()) {}

}

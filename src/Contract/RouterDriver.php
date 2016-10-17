<?php

namespace Ark\Contract;

interface RouterDriver
{

    /**
     * 检查是否支持模块化
     *
     * @return bool
     */
    function isAllowModule();

    /**
     * 设置是否支持模块
     *
     * @param bool $allow
     * @return $this
     */
    function setAllowModule($allow);

    /**
     * 设置URL模式
     *
     * @param $mode
     * @return $this
     */
    function setUrlMode($mode);

    /**
     * 获取当前URL模式
     *
     * @return int
     */
    function getUrlMode();

    /**
     * 获取当前URL模式名称
     *
     * @return mixed
     */
    function getUrlModeName();

    /**
     * 解析URI数据
     *
     * @param $uri
     * @return array
     */
    function parseUri($uri);

    /**
     * 组装指定模式的URI
     *
     * @param $controller
     * @param $action
     * @param array $params
     * @param null $module
     * @param null $url_mode
     * @return string
     */
    function makeQuery($controller, $action, array $params, $module = null, $url_mode = null);

}
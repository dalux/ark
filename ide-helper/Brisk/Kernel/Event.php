<?php

namespace Brisk\Kernel;

class Event
{

    /**
     * 添加事件监听器
     *
     * @param string $event
     * @param callable $listener
     * @param string $name
     * @return null
     */
    public static function addListener($event, $listener, $name = "") {}

    /**
     * 获取事件监听器
     *
     * @param string $event
     * @param string $name
     * @return array
     */
    public static function getListener($event = "", $name = "") {}

    /**
     * 移除事件监听器
     *
     * @param string $event
     * @param string $name
     * @return null
     */
    public static function removeListener($event, $name = "") {}

    /**
     * 执行事件监听
     *
     * @param string $event
     * @param array $data
     * @return mixed
     */
    public static function onListening($event, array $data = array()) {}

}

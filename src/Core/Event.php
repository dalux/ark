<?php

namespace Ark\Core;

use Closure;

class Event
{

    /**
     * 事件侦听器
     *
     * @var array
     */
    static $_listener = array();

    /**
     * 新增事件处理器
     *
     * @param $event
     * @param callable|Closure $listener
     * @param bool $prepend
     */
    static function addListener($event, Closure $listener, $prepend = false)
    {
        if (!$prepend) {
            self::$_listener[$event][] = $listener;
        } else {
            array_unshift(self::$_listener[$event], $listener);
        }
    }

    /**
     * 移除事件处理器
     *
     * @param $event
     */
    static function removeListener($event)
    {
        unset(self::$_listener[$event]);
    }

    /**
     * 侦听事件
     *
     * @param $event
     * @param array $data
     * @param array $rule
     * @return array
     * @throws Exception
     */
    static function onListening($event, array $data = array(), array $rule = array())
    {
        if (!isset(self::$_listener[$event])) {
            return $data;
        }
        $listener = self::$_listener[$event];
        $data['event'] = $event;
        foreach ($listener as $item) {
            $data = $item($data);
            if ($rule) {
                $struct = new Struct();
                $struct->setRule($rule);
                $struct->setData($data);
                if (!$data = $struct->checkOut()) {
                    throw new Exception(sprintf(Captain::getInstance()->lang->get('event.struct_check_failed'), $event, $struct->getMessage()));
                }
            } elseif (!is_array($data)) {
                throw new Exception(sprintf(Captain::getInstance()->lang->get('core.data_must_array'), $event));
            }
        }
        return $data;
    }

}
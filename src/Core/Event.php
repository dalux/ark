<?php

namespace Ark\Core;

use Closure;
use Ark\Toolkit\Struct;

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
     * @param string $flag
     */
    static function addListener($event, Closure $listener, $flag = null)
    {
        if (is_null($flag)) {
            self::$_listener[$event][] = $listener;
        } else {
            self::$_listener[$event][$flag] = $listener;
        }
    }

    /**
     * 获取事件处理器
     *
     * @param null $event
     * @param null $flag
     * @return mixed
     */
    static function getListener($event = null, $flag = null)
    {
        if (is_null($event)) {
            return self::$_listener;
        }
        return is_null($flag)
            ? self::$_listener[$event]
            : self::$_listener[$event][$flag];
    }

    /**
     * 移除事件处理器
     *
     * @param $event
     * @param null $name
     */
    static function removeListener($event, $name = null)
    {
        if (is_null($name)) {
            unset(self::$_listener[$event]);
        } else {
            unset(self::$_listener[$event][$name]);
        }
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
        foreach ($listener as $flag=> $item) {
            $data['flag'] = $flag;
            $data = $item($data);
            if ($rule) {
                $struct = new Struct();
                $struct->setRule($rule);
                $struct->setData($data);
                if (!$data = $struct->checkOut()) {
                    throw new Exception(Noah::init()->lang->get('event.struct_check_failed', $event, $struct->getMessage()));
                }
            } elseif (!is_array($data)) {
                throw new Exception(Noah::init()->lang->get('core.data_must_array', $event));
            }
        }
        return $data;
    }

}
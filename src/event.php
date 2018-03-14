<?php

class Ark_Event
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
     * @param string $name
     */
    static function addListener($event, Closure $listener, $name = null)
    {
        if (is_null($name)) {
            self::$_listener[$event][] = $listener;
        } else {
            self::$_listener[$event][$name] = $listener;
        }
    }

    /**
     * 获取事件处理器
     *
     * @param null $event
     * @param null $name
     * @return mixed
     */
    static function getListener($event = null, $name = null)
    {
        if (is_null($event)) {
            return self::$_listener;
        }
        return is_null($name)
            ? self::$_listener[$event]
            : self::$_listener[$event][$name];
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
     * @return array
     * @throws Exception
     */
    static function onListening($event, array $data = array())
    {
        if (!isset(self::$_listener[$event])) {
            return $data;
        }
        $listener = self::$_listener[$event];
        $data['event'] = $event;
        foreach ($listener as $name=> $item) {
            $data['name'] = $name;
            $ori_keys = array_keys($data);
            $data = $item($data);
            if (!is_array($data)) {
                throw new Ark_Exception(Ark_Core::getInst()->lang->get('event.data_must_array', $event));
            }
            $now_keys = array_keys($data);
            if ($diff = array_diff($ori_keys, $now_keys)) {
                throw new Ark_Exception(Ark_Core::getInst()->lang->get('event.data_key_must_equal', $event));
            }
        }
        return $data;
    }

}
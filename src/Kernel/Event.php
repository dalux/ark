<?php declare(strict_types=1);

namespace Brisk\Kernel;

use Brisk\Exception\EventException;

class Event
{

    /**
     * 事件监听器列表
     * 
     * @var array
     */
    private static $_listener = [];

    /**
     * 添加事件监听器
     *
     * @access public
     * @param string $event
     * @param callable $listener
     * @return void
     */
    public static function add(string $event, callable $listener)
    {
        $trace = debug_backtrace();
        $trace = $trace[1];
        $info = [
            'listener'=> $listener,
            'source'=> [
                'file'=> $trace['file'],
                'line'=> $trace['line'],
                'call'=> $trace['class']. $trace['type']. $trace['function']
            ]
        ];
		if (!isset(self::$_listener[$event])) {
			self::$_listener[$event] = [];
        }
        self::$_listener[$event][] = $info;
    }

    /**
     * 获取事件监听器
     *
     * @access public
     * @param string $event
     * @return array
     */
    public static function get(string $event)
    {
        return self::$_listener[$event];
    }

    /**
     * 触发监听事件
     *
     * @access public
     * @param string $event
     * @param array $data
     * @return array
     */
    public static function fire(string $event, array $data = [])
    {
        if (!isset(self::$_listener[$event])) {
            return $data;
        }
        $listener = self::$_listener[$event];
        $data['event'] = $event;
        $result = $data;
        foreach ($listener as $key=> $item) {
            $ori_keys = array_keys($result);
            $func = $item['listener'];
            $result = call_user_func_array($func, [$result]);
            if (!is_array($result)) {
                throw new EventException(Language::format('event.data_must_array', $event));
            }
            $now_keys = array_keys($result);
			$diff = array_diff($ori_keys, $now_keys);
            if (count($diff) > 0) {
                throw new EventException(Language::format('event.data_key_must_equal', $event));
            }
        }
        return $result;
    }

}
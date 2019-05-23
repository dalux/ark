<?php

namespace Brisk\Vendor\Spy;

use Brisk\Kernel\Event;
use Brisk\Kernel\Timer;
use Brisk\Kernel\Trace;

class Tracker
{

    /**
     * 开启跟踪
     */
    public function beginTrace()
    {
        ob_start();
        Event::add('event.dbconnect.finish', function($data) {
            Trace::set('dbconnect', [$data['driver'], $data['dsn'], $data['timeused']]);
            return $data;
        });
        Event::add('event.dbquery.finish', function($data) {
            Trace::set('database', [$data['query'], $data['timeused']]);
            return $data;
        });
        Timer::mark('framework_ready');
    }

    /**
     * 输出调试信息
     *
     * @throws \Exception
     */
    public function endTrace()
    {

        require_once __DIR__. '/FirePHP/Fb.php';

        $trace = Trace::get('database');
        $trace || $trace = [];
        //数据库执行语句
        $db_trace = [['sql', 'time']];
        foreach ($trace as $k=> $v) {
            $db_trace[] = $v;
        }
        Timer::mark('framework_shutdown');
        $used_info = [
            ['name', 'data'],
            ['all timeused', Timer::totalUsed(). 's']
        ];
        $db_connect = Trace::get('dbconnect');
        foreach ($db_connect as $val) {
            $used_info[] = [$val[0]. ' connect', $val[2]. 's('. $val[1]. ')'];
        }
        fb($used_info, 'Load Info', \FirePHP::TABLE);
        fb($db_trace, 'Database Trace (' . (count($db_trace) - 1) . ')', \FirePHP::TABLE);

    }

}
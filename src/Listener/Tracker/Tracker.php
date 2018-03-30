<?php

class Tracker
{

    function handle(array $data)
    {
        if ($data['event'] == 'event.framework.ready') {
            $debug = \Brisk\Core\Captain::getInst()->config->global->debug;
            if ($debug && !\Brisk\Core\Server::isCli()) {
                ob_start();
            }
        } elseif ($data['event'] == 'event.framework.shutdown') {
            //数据库执行语句
            $dbtrace = array(array('sql', 'time'));
            $_trace = \Brisk\Core\Trace::get('database');
            $_trace || $_trace = array();
            foreach ($_trace as $k=> $v) { $dbtrace[] = $v; }
            //内存占用
            $memusage = \Brisk\Core\Trace::get('memory');
            //页面执行完成总耗时
            $all_time = \Brisk\Core\Timer::totalUsed();
            //数据连接时间
            $dbconnect_time = \Brisk\Core\Timer::pick('db_connect_begin', 'db_connect_end');
            $dbconnect_time || $dbconnect_time = '0.0000';
            //引擎加载
            $driver_trace = array(array('name', 'value'));
            $drivers = \Brisk\Core\Trace::get('driver');
            if (is_array($drivers)) {
                foreach ($drivers as $k => $v) {
                    $driver_trace[] = array(key($v), current($v));
                }
            }
            //非CLI模式时，在浏览器调试工具中输出调试信息
            if (ob_get_length() > 0
                    && !\Brisk\Core\Server::isCli()
                    && \Brisk\Core\Captain::getInst()->config->global->debug) {
                $user_agent = $_SERVER['HTTP_USER_AGENT'];
                //chrome、火狐浏览器
                require_once __DIR__ . '/Fb.php';
                if (strpos($user_agent, 'Chrome') !== false || strpos($user_agent, 'Firefox') !== false) {   //firefox下用firephp插件进行调试
                    $usedinfo = array(array('name', 'data'));
                    $usedinfo[] = array('all time', $all_time. 's');
                    $usedinfo[] = array('dbconnect time', $dbconnect_time. 's');
                    $usedinfo[] = array('memory', \Brisk\Core\Toolkit::formatSize($memusage[1]-$memusage[0]));
                    $custom = array(array('name', 'value'));
                    $_custom = \Brisk\Core\Trace::get('custom');
                    if ($_custom) {
                        foreach ($_custom as $k=> $v) {
                            if (is_array($v)) {
                                foreach ($v as $_k=> $_v) {
                                    $custom[] = array($_k, $_v);
                                }
                            } else {
                                $custom[] = array('-', $v);
                            }
                        }
                    }
                    fb($usedinfo, 'General Info ('. (count($usedinfo)-1). ')', \FirePHP::TABLE);
                    fb($driver_trace, 'Driver List ('. (count($driver_trace)-1). ')', \FirePHP::TABLE);
                    fb($dbtrace, 'Database Trace ('. (count($dbtrace) - 1). ')', \FirePHP::TABLE);
                    if ($_custom) fb($custom, 'Custom Info ('. (count($custom)-1). ')', \FirePHP::TABLE);
                }
                //IE sorry
                //当前为CLI模式，并且为调试模式，并且显式的指明了要显示DEBUG信息时
            } elseif (\Brisk\Core\Server::isCli()
                    && \Brisk\Core\Captain::getInst()->request->get('debug')
                    && \Brisk\Core\Captain::getInst()->config->global->debug) {
                echo PHP_EOL. PHP_EOL. str_repeat('=', 20). ' Debug Info '. str_repeat('=', 40). PHP_EOL. PHP_EOL;
                echo '>>> Database Trace'. PHP_EOL;
                $i = 1;
                foreach ($dbtrace as $k=> $v) {
                    if ($k == 'sql') continue;
                    $i < 10 && $i = '0'. $i;
                    echo "\t". '['. $i. '] '. $v[0]. ' ('. $v[1]. 's)'. PHP_EOL;
                    $i ++;
                }
                unset($i);
                echo PHP_EOL. '>>> Time Used'. PHP_EOL;
                echo "\t". $all_time. 's'. PHP_EOL;
                echo PHP_EOL. '>>> DBConnect Time Used'. PHP_EOL;
                echo "\t". $dbconnect_time. 's'. PHP_EOL;
                echo PHP_EOL. '>>> Memory Used'. PHP_EOL;
                echo "\t". \Brisk\Core\Toolkit::formatSize($memusage[1]-$memusage[0]). PHP_EOL;
                echo PHP_EOL. '>>> Url Mode'. PHP_EOL;
                echo "\t". \Brisk\Core\Captain::getInst()->router->getUrlModeName(). PHP_EOL;
                echo PHP_EOL. '>>> Driver List'. PHP_EOL;
                foreach ($driver_trace as $k=> $v) {
                    if ($k == 'name') continue;
                    echo "\t". $v[0]. ': '. $v[1]. PHP_EOL;
                }
            }
        }

        return $data;

    }

}
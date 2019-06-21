<?php declare(strict_types=1);

namespace Brisk\Toolkit;

use Closure;
use swoole_process;
use Brisk\Exception\RuntimeException;

class Executor
{

    const LOG_NOTICE            = 'notice';
    const LOG_WARNING           = 'warning';
    const LOG_ERROR             = 'error';

    private static $_process    = [];
    private static $_queue      = [];
    private static $_action;
    private static $_proc_num;
    private static $_proc_dir;
    private static $_locked     = false;
    private static $_action_timer;
    private static $_wait_timer;

    /**
     * 执行器准备
     * 
     * @param Closure $action
     * @param int $proc_num
     * @param string $proc_dir
     * @return void
     */
    public static function init(Closure $action, int $proc_num = 5, string $proc_dir = '/tmp')
    {
        if (!extension_loaded('swoole')) {
            throw new RuntimeException('无法加载[swoole]扩展');
        }
        self::$_action = $action;
        self::$_proc_num = $proc_num;
        self::$_proc_dir = $proc_dir;
        if (!is_dir(self::$_proc_dir)) {
            File::mkDir(self::$_proc_dir);
        }
        self::_log('正在启动工作进程...');
        for ($i = 0; $i < self::$_proc_num; $i++) {
            self::_createWorker();
        }
        self::_log('启动完成, 开始接受任务');
        //每50毫秒从队列中取一次任务
        $timer = swoole_timer_tick(50, function() {
            if (self::$_locked || !self::$_queue) return;
            self::$_locked = 1;
            $task = array_shift(self::$_queue);
            foreach (self::$_process as $k=> $v) {
                if (!$used = self::_getState($k)) {
                    self::_setState($k, 1);
                    $task = json_encode($task);
                    self::$_process[$k]['process']->write($task);
                    $task = null;
                    break;
                }
            }
            if ($task) {
                self::$_queue[] = $task;
            }
            self::$_locked = 0;
        });
        self::$_action_timer = $timer;
        //每一秒钟检查一次僵尸进程
        $timer = swoole_timer_tick(1000, function() {
            while($ret = swoole_process::wait(false)) {
                $pid = $ret['pid'];
                if (isset(self::$_process[$pid])) {
                    unset(self::$_process[$pid]);
                    self::_delState($pid);
                    self::_createWorker();
                }
            }
        });
        self::$_wait_timer = $timer;
    }

    /**
     * 添加任务数据
     * 
     * @param mixed $data
     * @return void
     */
    public static function addTask($data)
    {
        self::$_queue[] = $data;
    }

    /**
     * 获取当前任务队列长度
     * 
     * @return int
     */
    public static function getQueueLength()
    {
        return count(self::$_queue);
    }
    
    /**
     * 终止执行器
     * 
     * @param bool $wait
     * @return void
     */
    public static function end(bool $now = false)
    {
        $clean = function() {
            swoole_timer_clear(self::$_action_timer);
            swoole_timer_clear(self::$_wait_timer);
            $v = [];
            foreach (self::$_process as $v) {
                swoole_process::kill($v['pid']);
            }
        };
        if (!$now) {
            swoole_timer_tick(50, function($timer) use ($clean) {
                if (!self::$_queue) {
                    $clean();
                    swoole_timer_clear($timer);
                }
            });
        } else {
            $clean();
        }
    }

    /**
     * 创建任务子进程
     *
     * @return int
     */
    private static function _createWorker()
    {
        $process = new swoole_process(function(swoole_process $worker) {
            //接收父进程通过管道传输的任务数据
            swoole_event_add($worker->pipe, function($pipe) use ($worker) {
                $data = json_decode($worker->read(), true);
                try {
                    call_user_func_array(self::$_action, [$data]);
                } catch (RuntimeException $e) {
                    self::_log(sprintf('工作进程[%s]异常未捕获: %s', getmypid(), $e->getMessage()), self::LOG_WARNING);
                }
                self::_setState(getmypid(), 0);
            });
        }, false, 2);
        $pid = $process->start();
        self::$_process[$pid] = [
            'pid'       => $pid,
            'process'   => $process,
            'time'      => time(),
        ];
        self::_setState($pid, 0);
        self::_log('工作进程已启动, pid='. $pid);
        return $pid;
    }

    /**
     * 设置进程工作状态
     *
     * @param int $pid
     * @param int $used
     * @return null
     */
    private static function _setState(int $pid, int $used = 1)
    {
        file_put_contents(self::$_proc_dir . '/proc_' . $pid, (int)$used);
    }

    /**
     * 获取进程工作状态
     *
     * @param int $pid
     * @return int
     */
    private static function _getState(int $pid)
    {
        return file_get_contents(self::$_proc_dir . '/proc_' . $pid);
    }

    /**
     * 删除进程pid状态文件
     *
     * @param int $pid
     * @return bool
     */
    private static function _delState(int $pid)
    {
        $file = self::$_proc_dir. '/proc_'. $pid;
        if (is_file($file)) {
            return unlink($file);
        }
        return true;
    }

    /**
     * 打印日志
     *
     * @param string $log
     * @param string $level
     */
    private function _log(string $log, string $level = self::LOG_NOTICE)
    {
        echo date('Y-m-d H:i:s'). ' / '. $level. ' / '. $log. PHP_EOL;
    }

}
<?php declare(strict_types=1);

namespace Brisk\Toolkit\Executor;

use Closure;
use swoole_process;
use Brisk\Toolkit\File;

class Core
{

    const LOG_NOTICE        = 'notice';
    const LOG_WARNING       = 'warning';
    const LOG_ERROR         = 'error';

    private $_process       = [];
    private $_queue         = [];
    private $_action;
    private $_proc_num;
    private $_proc_dir;
    private $_locked        = false;
    private $_action_timer;
    private $_wait_timer;

    /**
     * 设置相关参数
     *
     * @param Closure $action
     * @param int $proc_num
     * @param string $proc_dir
     * @return void
     */
    public function set(Closure $action, int $proc_num = 5, string $proc_dir = '/tmp')
    {
        $this->_action = $action;
        $this->_proc_num = $proc_num;
        $this->_proc_dir = $proc_dir;
        if (!is_dir($this->_proc_dir)) {
            File::mkDir($this->_proc_dir);
        }
    }

    /**
     * 启动
     *
     * @return void
     */
    public function start()
    {
        $this->_log('正在创建消费者进程');
        for ($i = 0; $i < $this->_proc_num; $i++) {
            $this->_createWorker();
        }
        $this->_log('启动就绪, 开始接受任务');
        //每50毫秒从队列中取一次任务
        $timer = swoole_timer_tick(10, function() {
            if ($this->_locked || !$this->_queue) return;
            $this->_locked = 1;
            $task = array_shift($this->_queue);
            foreach ($this->_process as $k=> $v) {
                if (!$used = $this->_getState($k)) {
                    $this->_setState($k, 1);
                    $task = json_encode($task);
                    $this->_process[$k]['process']->write($task);
                    $task = null;
                    break;
                }
            }
            if ($task) {
                $this->_queue[] = $task;
            }
            $this->_locked = 0;
        });
        $this->_action_timer = $timer;
        //每一秒钟检查一次僵尸进程
        $timer = swoole_timer_tick(1000, function() {
            while($ret = swoole_process::wait(false)) {
                $pid = $ret['pid'];
                if (isset($this->_process[$pid])) {
                    unset($this->_process[$pid]);
                    $this->_delState($pid);
                    $this->_createWorker();
                }
            }
        });
        $this->_wait_timer = $timer;
        //检查父进程，如果父进程退出，任务进程也退出
        $ppid = posix_getppid();
        swoole_timer_tick(1000, function($timer) use ($ppid) {
            $command = "ps ax | awk '{print $1}' | grep $ppid | wc -l";
            exec($command, $count);
            $count = intval(trim($count[0]));
            if ($count < 1) {
                $this->_log('生产者进程已退出,任务中止', self::LOG_ERROR);
                swoole_timer_clear($this->_action_timer);
                swoole_timer_clear($this->_wait_timer);
                foreach ($this->_process as $v) {
                    swoole_process::kill($v['pid']);
                }
                swoole_timer_clear($timer);
                exit();
            }
        });
    }

    /**
     * 添加任务数据
     *
     * @param mixed $data
     * @return void
     */
    public function addTask($data)
    {
        $this->_queue[] = $data;
    }

    /**
     * 获取当前任务队列长度
     *
     * @return int
     */
    public function getQueueLength()
    {
        return count($this->_queue);
    }

    /**
     * 清空队列
     * 
     */
    public function cleanQueue()
    {
        $this->_queue = [];
    }

    /**
     * 创建任务子进程
     *
     * @return int
     */
    private function _createWorker()
    {
        $process = new swoole_process(function(swoole_process $worker) {
            //接收父进程通过管道传输的任务数据
            swoole_event_add($worker->pipe, function($pipe) use ($worker) {
                $data = json_decode($worker->read(), true);
                try {
                    call_user_func_array($this->_action, [$data]);
                } catch (Exception $e) {
                    $this->_log(sprintf('消费者进程[%s]异常未捕获: %s', getmypid(), $e->getMessage()), self::LOG_WARNING);
                }
                $this->_setState(getmypid(), 0);
            });
        }, false, 2);
        $pid = $process->start();
        $this->_process[$pid] = [
            'pid'       => $pid,
            'process'   => $process,
            'time'      => time(),
        ];
        $this->_setState($pid, 0);
        $this->_log('消费者进程已启动, pid='. $pid);
        return $pid;
    }

    /**
     * 设置进程工作状态
     *
     * @param int $pid
     * @param int $used
     * @return null
     */
    private function _setState($pid, $used = 1)
    {
        file_put_contents($this->_proc_dir . '/proc_' . $pid, (int)$used);
    }

    /**
     * 获取进程工作状态
     *
     * @param int $pid
     * @return int
     */
    private function _getState($pid)
    {
        return file_get_contents($this->_proc_dir . '/proc_' . $pid);
    }

    /**
     * 删除进程pid状态文件
     *
     * @param int $pid
     * @return bool
     */
    private function _delState($pid)
    {
        $file = $this->_proc_dir. '/proc_'. $pid;
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
    private function _log($log, $level = self::LOG_NOTICE)
    {
        echo date('Y-m-d H:i:s'). ' / '. $level. ' / '. $log. PHP_EOL;
    }

}
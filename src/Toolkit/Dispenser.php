<?php

namespace Brisk\Toolkit;

use Closure;
use swoole_process;
use Brisk\Exception\RuntimeException;

class Dispenser
{

    /**
     * 日志级别
     *
     * var string
     */
    const LOG_NOTICE            = 'notice';
    const LOG_WARNING           = 'warning';
    const LOG_ERROR             = 'error';

    /**
     * 进程池
     *
     * @var array
     */
    private $_processes         = [];

    /**
     * 执行进程数
     *
     * @var int
     */
    private $_proc_num          = 3;

    /**
     * 取任务时间间隔, 单位s
     *
     * @var int
     */
    private $_interval          = 20;

    /**
     * 进程状态文件目录
     *
     * @var string
     */
    private $_proc_dir          = '/tmp';


    /**
     * 是否等待所有子进程均完成任务
     *
     * @var bool
     */
    private $_wait              = false;

    /**
     * 消费者进程执行超时时间
     *
     * @var int
     */
    private $_proc_timeout      = 120;

    /**
     * 数据消费者
     *
     * @var \Closure
     */
    private $_consumer;

    /**
     * 数据生产者
     *
     * @var Closure
     */
    private $_producer;

    /**
     * 构造器
     *
     * @param int $proc_num
     * @param int $interval
     * @param bool $wait
     * @param int $proc_timeout
     * @param string $proc_dir
     */
    public function __construct(int $proc_num, int $interval, bool $wait = false, int $proc_timeout = 60, string $proc_dir = '/tmp')
    {
        if (!extension_loaded('swoole')) {
            throw new RuntimeException('无法加载[swoole]扩展');
        }
        $this->_proc_num = $proc_num;
        $this->_interval = $interval;
        $this->_wait = $wait;
        $this->_proc_timeout = $proc_timeout;
        $this->_proc_dir = $proc_dir;
        if (!is_dir($this->_proc_dir)) {
            File::mkDir($this->_proc_dir);
        }
    }

    /**
     * 设置任务生产者方法
     *
     * @param Closure $producer
     * @return $this
     */
    public function setProducer(Closure $producer)
    {
        $this->_producer = $producer;
        return $this;
    }

    /**
     * 设置任务消费者方法
     *
     * @param Closure $consumer
     * @return $this
     */
    public function setConsumer(Closure $consumer)
    {
        $this->_consumer = $consumer;
        return $this;
    }

    /**
     * 启动服务
     *
     * @return void
     */
    public function start()
    {
        $this->_log('正在启动工作进程...');
        for ($i = 0; $i < $this->_proc_num; $i ++) {
            $this->_createWorker();
        }
        $this->_log('启动完成, 开始任务处理');
        //异步定时器
        while (true) {
            try {
                //检查进程
                while($ret = swoole_process::wait(false)) {
                    $pid = $ret['pid'];
                    if (isset($this->_processes[$pid])) {
                        unset($this->_processes[$pid]);
                        $this->_delState($pid);
                        $this->_createWorker();
                    }
                }
                //获取任务
                $tasks = call_user_func_array($this->_producer, []);
                if (is_array($tasks) && count($tasks) == 0) {
                    $this->_log('当前任务队列为空');
                    sleep($this->_interval);
                    continue;
                } elseif ($tasks && !is_array($tasks)) {
                    $this->_log((string)$tasks);
                    sleep($this->_interval);
                    continue;
                } elseif (!$tasks) {
                    $this->_log('任务队列返回值异常', self::LOG_WARNING);
                    sleep($this->_interval);
                    continue;
                }
                while ($tasks) {
                    foreach ($tasks as $key => $task) {
                        foreach ($this->_processes as $k => $v) {
                            if (!$used = $this->_getState($k)) {
                                $this->_setState($k, 1);
                                $data = json_encode($task);
                                $this->_processes[$k]['process']->write($data);
                                $this->_processes[$k]['time'] = time();
                                unset($tasks[$key]);
                                break;
                            }
                        }
                    }
                }
                //等待同步状态
                if ($this->_wait) {
                    while (true) {
                        $success = 0;
                        foreach ($this->_processes as $k=> $v) {
                            if (!$used = $this->_getState($k)) {
                                $success += 1;
                                $this->_processes[$k]['time'] = time();
                            }
                            if ($this->_proc_timeout
                                    && time() - $this->_processes[$k]['time'] > $this->_proc_timeout) {
                                swoole_process::kill($k);
                                $this->_log(sprintf('工作进程[%s]执行超时，已退出', $k));
                                $success += 1;
                            }
                        }
                        if ($success >= count($this->_processes)) {
                            break;
                        }
                    }
                }
            } catch (RuntimeException $e) {
                $this->_log('管理进程发生异常: ' . $e->getMessage(), self::LOG_WARNING);
                sleep($this->_interval);
            }
        }
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
                    call_user_func_array($this->_consumer, [$data]);
                } catch (RuntimeException $e) {
                    $this->_log(sprintf('工作进程[%s]异常未捕获: %s', getmypid(), $e->getMessage()), self::LOG_WARNING);
                }
                $this->_setState(getmypid(), 0);
            });
        }, false, 2);
        $pid = $process->start();
        $this->_processes[$pid] = [
            'pid'       => $pid,
            'process'   => $process,
            'time'      => time(),
        ];
        $this->_setState($pid, 0);
        $this->_log('工作进程已启动, pid='. $pid);
        return $pid;
    }

    /**
     * 设置进程工作状态
     *
     * @param int $pid
     * @param int $used
     * @return null
     */
    private function _setState(int $pid, int $used = 1)
    {
        file_put_contents($this->_proc_dir . '/proc_' . $pid, (int)$used);
        return $this;
    }

    /**
     * 获取进程工作状态
     *
     * @param int $pid
     * @return int
     */
    private function _getState(int $pid)
    {
        return file_get_contents($this->_proc_dir . '/proc_' . $pid);
    }

    /**
     * 删除进程pid状态文件
     *
     * @param int $pid
     * @return bool
     */
    private function _delState(int $pid)
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
    private function _log(string $log, string $level = self::LOG_NOTICE)
    {
        echo date('Y-m-d H:i:s'). ' / '. $level. ' / '. $log. PHP_EOL;
    }

}
<?php declare(strict_types=1);

namespace Brisk\Toolkit;

use Closure;
use swoole_process;
use Brisk\Toolkit\Executor\Core;

class Executor
{

    private static $_worker;
    private static $_workerid;

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
        $process = new swoole_process(function(swoole_process $proc) use ($action, $proc_num, $proc_dir) {
            $worker = new Core();
            $worker->set($action, $proc_num, $proc_dir);
            $worker->start();
            //接收父进程通过管道传输的任务数据
            swoole_event_add($proc->pipe, function($pipe) use ($proc, $worker) {
                $data = json_decode($proc->read(), true);
                if ($data['action'] == 'getQueueLength') {
                    $data = ['length'=> $worker->getQueueLength()];
                    $proc->write(json_encode($data));
                } elseif ($data['action'] == 'cleanQueue') {
                    $worker->cleanQueue();
                } else {
                    $worker->addTask($data['data']);
                }
            });
        }, false, 2);
        self::$_workerid = $process->start();
        self::$_worker = $process;
    }

    /**
     * 添加任务数据
     *
     * @param mixed $data
     * @return void
     */
    public static function addTask($data)
    {
        $data = ['action'=> 'addTask', 'data'=> $data];
        self::$_worker->write(json_encode($data));
    }

    /**
     * 获取当前任务队列长度
     *
     * @return int
     */
    public static function getQueueLength()
    {
        $data = ['action'=> 'getQueueLength'];
        self::$_worker->write(json_encode($data));
        $data = json_decode(self::$_worker->read(), true);
        return $data['length'];
    }

    /**
     * 清空队列
     *
     * @return int
     */
    public static function cleanQueue()
    {
        $data = ['action'=> 'cleanQueue'];
        self::$_worker->write(json_encode($data));
    }

}
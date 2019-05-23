<?php

namespace Brisk\Vendor\Crontab;

use Brisk\Exception\RuntimeException;
use Brisk\Kernel\Toolkit;
use swoole_server as Server;
use swoole_process as Process;

class Crond
{

    const NAME          = 'PHPCrond';
    const VERSION       = '1.0';
    const AUTHOR        = 'dalu<guodalu@qq.com>';

    const LEVEL_NOTICE  = 'notice';
    const LEVEL_WARNING = 'warning';
    const LEVEL_ERROR   = 'error';

    /**
     * 主服务状态
     * 
     * @var array
     */
    private $_status = [];

    /**
     * 任务列表
     *
     * @var array
     */
    private $_tasks = [];

    /**
     * 服务监听地址
     *
     * @var string
     */
    private $_host;

    /**
     * 服务监听端口
     *
     * @var int
     */
    private $_port;

    /**
     * 服务输出日志
     *
     * @var string
     */
    private $_log;

    /**
     * 是否守护进程运行
     *
     * @var bool
     */
    private $_daemonize;

    /**
     * 配置文件路径
     *
     * @var string
     */
    private $_config;

    /**
     * 命令执行者
     *
     * @var Process
     */
    private $_soldier;

    /**
     * @var int
     */
    private $_soldier_pid;

    /**
     * 构造器
     * @param string $host
     * @param int $port
     * @param bool $daemonize
     * @param string $log
     */
    public function __construct($host = '0.0.0.0', $port = 9510, $daemonize = true, $log = '/tmp/phpcrond.log')
    {
        date_default_timezone_set('Asia/Shanghai');
        if (!extension_loaded('swoole')) {
            throw new RuntimeException('需要[swoole]扩展支持');
        }
        $this->_host = $host;
        $this->_port = $port;
        $this->_log = $log;
        $this->_daemonize = $daemonize;
        $this->_status['init_memory'] = memory_get_usage();
    }

    /**
     * 运行
     *
     * @param $config
     * @return null
     */
    public function run($config)
    {
        //配置文件路径
        $this->_config = $config;
        //创建用于执行命令的独立进程，避免端口继承
        //SwooleServer中创建的子进程，将自动继承父进程端口及套接字连接等，导致主进程二次启动时无法重新监听端口
        $this->_soldier = new Process(function(Process $worker) {
            //cli_set_process_title('PHPCrond:Soldier');
            swoole_event_add($worker->pipe, function($pipe) use ($worker) {
                $command = $worker->read();
                shell_exec($command);
            });
        }, false, 2);
        $this->_soldier_pid = $this->_soldier->start();
        //socket服务器
        $socket = new Server($this->_host, $this->_port, SWOOLE_BASE, SWOOLE_SOCK_TCP);
        $socket->set([
            'daemonize'=> $this->_daemonize,
            'log_file' => $this->_log,
        ]);
        //进程初始化
        $socket->on('WorkerStart', function(Server $server, $worker_id) {
            //cli_set_process_title('PHPCrond:Server');
            $this->_status['start_time'] = time();
            $this->_show(sprintf('主控服务已就绪，pid=%s', $server->master_pid));
            $this->_loadConfig();
            //每分钟执行一次
            swoole_timer_tick(60000, function($timer_id) {
                $this->_process();
            });
        });
        //接收客户端请求
        $socket->on('Connect', function(Server $server, $fd, $from_id) {
            $server->send($fd, '>>> ');
        });
        //接收客户端发送命令
        $socket->on('Receive', function(Server $server, $fd, $from_id, $data) {
            $command = strtolower(trim($data));
            if ($command == 'help') {
                $response = $this->_drawLine(86). PHP_EOL;
                $response.= $this->_drawField('show status', 30). $this->_drawField('查看主控服务器状态', 50). PHP_EOL;
                $response.= $this->_drawLine(86). PHP_EOL;
                $response.= $this->_drawField('show tasks', 30). $this->_drawField('查看当前已配置的任务情况', 50). PHP_EOL;
                $response.= $this->_drawLine(86). PHP_EOL;
                $response.= $this->_drawField('show running tasks', 30). $this->_drawField('查看当前正在运行的任务情况', 50). PHP_EOL;
                $response.= $this->_drawLine(86). PHP_EOL;
                $response.= $this->_drawField('show task [task_name]', 30). $this->_drawField('查看指定任务运行情况', 50). PHP_EOL;
                $response.= $this->_drawLine(86). PHP_EOL;
                $response.= $this->_drawField('kill task [task_name]', 30). $this->_drawField('杀死指定名称任务', 50). PHP_EOL;
                $response.= $this->_drawLine(86). PHP_EOL;
                $response.= $this->_drawField('run task [task_name]', 30). $this->_drawField('运行指定名称任务', 50). PHP_EOL;
                $response.= $this->_drawLine(86). PHP_EOL;
                $response.= $this->_drawField('reload tasks', 30). $this->_drawField('重载所有配置项', 50). PHP_EOL;
                $response.= $this->_drawLine(86). PHP_EOL;
                $response.= $this->_drawField('reload task [task_name]', 30). $this->_drawField('重载指定任务配置项', 50). PHP_EOL;
                $response.= $this->_drawLine(86). PHP_EOL;
                $response.= $this->_drawField('quit', 30). $this->_drawField('退出当前会话', 50). PHP_EOL;
                $response.= $this->_drawLine(86). PHP_EOL;
                $response.= $this->_drawField('help', 30). $this->_drawField('显示本帮助', 50). PHP_EOL;
                $response.= $this->_drawLine(86). PHP_EOL;
                $response.= '>>> ';
                $server->send($fd, $response);
            } elseif ($command == 'quit' || $command == 'exit') {
                $server->send($fd, 'bye'. PHP_EOL);
                $server->close($fd);
            } elseif ($command == 'show status') {
                //计算服务器运行时长
                $run_days = floor((time() - $this->_status['start_time']) / 86400);
                $remain = (time() - $this->_status['start_time']) % 86400;
                $run_hours = floor($remain / 3600);
                $remain = $remain % 3600;
                $run_minutes = floor($remain / 60);
                //end.
                //有效任务
                $valid_task = 0;
                $close_task = 0;
                foreach ($this->_tasks as $task) {
                    if ($task['running']) {
                        $valid_task += 1;
                    } else {
                        $close_task += 1;
                    }
                }
                $response = $this->_drawLine(86). PHP_EOL;
                $response .= $this->_drawField('系统名称', 20). $this->_drawField(self::NAME, 60). PHP_EOL;
                $response .= $this->_drawLine(86). PHP_EOL;
                $response .= $this->_drawField('系统版本', 20). $this->_drawField(self::VERSION, 60). PHP_EOL;
                $response .= $this->_drawLine(86). PHP_EOL;
                $response .= $this->_drawField('开发作者', 20). $this->_drawField(self::AUTHOR, 60). PHP_EOL;
                $response .= $this->_drawLine(86). PHP_EOL;
                $response .= $this->_drawField('总任务数', 20). $this->_drawField(count($this->_tasks). ' 个', 60). PHP_EOL;
                $response .= $this->_drawLine(86). PHP_EOL;
                $response .= $this->_drawField('有效任务', 20). $this->_drawField($valid_task . ' 个', 60). PHP_EOL;
                $response .= $this->_drawLine(86). PHP_EOL;
                $response .= $this->_drawField('暂停任务', 20). $this->_drawField($close_task . ' 个', 60). PHP_EOL;
                $response .= $this->_drawLine(86). PHP_EOL;
                $response .= $this->_drawField('内存占用', 20). $this->_drawField($this->_formatSize(memory_get_usage() - $this->_status['init_memory']), 60). PHP_EOL;
                $response .= $this->_drawLine(86). PHP_EOL;
                $response .= $this->_drawField('运行时长', 20). $this->_drawField($run_days . ' 天 ' . $run_hours . ' 小时 ' . $run_minutes . ' 分', 60). PHP_EOL;
                $response .= $this->_drawLine(86). PHP_EOL;
                $response .= $this->_drawField('启动时间', 20). $this->_drawField(date('Y-m-d h:i:s', $this->_status['start_time']), 60). PHP_EOL;
                $response .= $this->_drawLine(86). PHP_EOL;
                $response .= '>>> ';
                $server->send($fd, $response);
            } elseif ($command == 'show tasks') {
                $response = $this->_drawLine(154). PHP_EOL;
                $response .= $this->_drawField('任务名称', 20). $this->_drawField('状态', 10). $this->_drawField('运行中', 10). $this->_drawField('最近检查', 25);
                $response .= $this->_drawField('最近执行', 25). $this->_drawField('任务描述', 50). PHP_EOL;
                $response .= $this->_drawLine(154). PHP_EOL;
                foreach ($this->_tasks as $k => $v) {
                    $state = $v['setting']['running'] ? 'open' : 'close';
                    $is_running = $this->_isRunning($v['setting']['file'], $v['setting']['flag']) ? 'yes' : 'no';
                    $last_check_datetime = $v['last_check_datetime'] ? $v['last_check_datetime'] : '-';
                    $last_execute_datetime = $v['last_execute_datetime'] ? $v['last_execute_datetime'] : '-';
                    $description = $v['setting']['description'] ? $v['setting']['description'] : '-';
                    $response .= $this->_drawField($k, 20). $this->_drawField($state, 10). $this->_drawField($is_running, 10). $this->_drawField($last_check_datetime, 25);
                    $response .= $this->_drawField($last_execute_datetime, 25). $this->_drawField($description, 50). PHP_EOL;
                    $response .= $this->_drawLine(154). PHP_EOL;
                }
                $response .= '>>> ';
                $server->send($fd, $response);
            } elseif ($command == 'show running tasks') {
                $response = $this->_drawLine(154). PHP_EOL;
                $response .= $this->_drawField('任务名称', 20). $this->_drawField('状态', 10). $this->_drawField('运行中', 10). $this->_drawField('最近检查', 25);
                $response .= $this->_drawField('最近执行', 25). $this->_drawField('任务描述', 50). PHP_EOL;
                $response .= $this->_drawLine(154). PHP_EOL;
                foreach ($this->_tasks as $k => $v) {
                    if ($this->_isRunning($v['setting']['file'], $v['setting']['flag'])) {
                        $state = $v['setting']['running'] ? 'open' : 'close';
                        $is_running = $this->_isRunning($v['setting']['file'], $v['setting']['flag']) ? 'yes' : 'no';
                        $last_check_datetime = $v['last_check_datetime'] ? $v['last_check_datetime'] : '-';
                        $last_execute_datetime = $v['last_execute_datetime'] ? $v['last_execute_datetime'] : '-';
                        $description = $v['setting']['description'] ? $v['setting']['description'] : '-';
                        $response .= $this->_drawField($k, 20). $this->_drawField($state, 10). $this->_drawField($is_running, 10). $this->_drawField($last_check_datetime, 25);
                        $response .= $this->_drawField($last_execute_datetime, 25). $this->_drawField($description, 50). PHP_EOL;
                        $response .= $this->_drawLine(154). PHP_EOL;
                    }
                }
                $response .= '>>> ';
                $server->send($fd, $response);
            } elseif (preg_match('/^kill\s+task\s+([\w\d]+)$/', $command, $matches)) {
                $task_name = trim($matches[1]);
                if (!isset($this->_tasks[$task_name])) {
                    $response = '未找到该任务' . PHP_EOL;
                    $response .= '>>> ';
                    $server->send($fd, $response);
                    return;
                }
                $setting = $this->_tasks[$task_name]['setting'];
                if ($this->_isRunning($setting['file'], $setting['flag'])) {
                    $this->_psKill($setting['file'], $setting['flag']);
                }
                $response = '任务已中止'. PHP_EOL;
                $response.= '>>> ';
                $server->send($fd, $response);
            } elseif (preg_match('/^run\s+task\s+([\w\d]+)$/', $command, $matches)) {
                $task_name = trim($matches[1]);
                if (!isset($this->_tasks[$task_name])) {
                    $response = '未找到该任务' . PHP_EOL;
                    $response .= '>>> ';
                    $server->send($fd, $response);
                    return;
                }
                $setting = $this->_tasks[$task_name]['setting'];
                $response = '';
                if (!$this->_isRunning($setting['file'], $setting['flag'])) {
                    try {
                        $command = $this->_runTask($task_name, $setting);
                        $this->_show(sprintf('任务[%s]已执行命令：%s', $task_name, $command), self::LEVEL_NOTICE);
                        $response.= '任务运行成功'. PHP_EOL;
                    } catch (\Exception $e) {
                        $this->_show($e->getMessage(), self::LEVEL_ERROR);
                        $response.= '任务运行失败: '. $e->getMessage(). PHP_EOL;
                    }
                } else {
                    $response.= '任务正在运行中'. PHP_EOL;
                }
                $response.= '>>> ';
                $server->send($fd, $response);
            } elseif (preg_match('/^show\s+task\s+([\w\d]+)$/', $command, $matches)) {
                $task_name = trim($matches[1]);
                if (!isset($this->_tasks[$task_name])) {
                    $response = '未找到该任务' . PHP_EOL;
                    $response .= '>>> ';
                    $server->send($fd, $response);
                    return;
                }
                $task = $this->_tasks[$task_name];
                $response = $this->_drawLine(116). PHP_EOL;
                $response .= $this->_drawField('任务名称', 20). $this->_drawField($task_name, 90). PHP_EOL;
                $response .= $this->_drawLine(116). PHP_EOL;
                $response .= $this->_drawField('任务状态', 20). $this->_drawField($task['setting']['running'] ? 'open' : 'close', 90). PHP_EOL;
                $response .= $this->_drawLine(116). PHP_EOL;
                $response .= $this->_drawField('正在运行', 20). $this->_drawField($this->_isRunning($task['setting']['file'], $task['setting']['flag']) ? 'yes' : 'no', 90). PHP_EOL;
                $response .= $this->_drawLine(116). PHP_EOL;
                $response .= $this->_drawField('PHP解释器', 20). $this->_drawField($task['setting']['processer'], 90). PHP_EOL;
                $response .= $this->_drawLine(116). PHP_EOL;
                $response .= $this->_drawField('程序路径', 20). $this->_drawField($task['setting']['file'], 90). PHP_EOL;
                $response .= $this->_drawLine(116). PHP_EOL;
                $response .= $this->_drawField('执行参数', 20). $this->_drawField($task['setting']['parameter'] ? $task['setting']['parameter'] : '-', 90). PHP_EOL;
                $response .= $this->_drawLine(116). PHP_EOL;
                $response .= $this->_drawField('输出路径', 20). $this->_drawField($task['setting']['output'], 90). PHP_EOL;
                $response .= $this->_drawLine(116). PHP_EOL;
                $response .= $this->_drawField('进程标识', 20). $this->_drawField($task['setting']['flag'] ? implode(', ', $task['setting']['flag']) : '-', 90). PHP_EOL;
                $response .= $this->_drawLine(116). PHP_EOL;
                $response .= $this->_drawField('定时设置', 20). $this->_drawField($task['setting']['timer'], 90). PHP_EOL;
                $response .= $this->_drawLine(116). PHP_EOL;
                $response .= $this->_drawField('强制重启', 20). $this->_drawField($task['setting']['force'] ? 'true' : 'false', 90). PHP_EOL;
                $response .= $this->_drawLine(116). PHP_EOL;
                $response .= $this->_drawField('任务描述', 20). $this->_drawField($task['setting']['description'] ? $task['setting']['description'] : '-', 90). PHP_EOL;
                $response .= $this->_drawLine(116). PHP_EOL;
                $response .= $this->_drawField('最近检查', 20). $this->_drawField($task['last_check_datetime'] ? $task['last_check_datetime'] : '-', 90). PHP_EOL;
                $response .= $this->_drawLine(116). PHP_EOL;
                $response .= $this->_drawField('最近执行', 20). $this->_drawField($task['last_execute_datetime'] ? $task['last_execute_datetime'] : '-', 90). PHP_EOL;
                $response .= $this->_drawLine(116). PHP_EOL;
                $response .= '>>> ';
                $server->send($fd, $response);
            } elseif ($command == 'reload tasks') {
                $this->_loadConfig();
                $response = '配置重载成功' . PHP_EOL;
                $response.= '>>> ';
                $server->send($fd, $response);
            } elseif (preg_match('/^reload\s+task\s+([\w\d]+)$/', $command, $matches)) {
                $item = trim($matches[1]);
                try {
                    $this->_loadConfig($item);
                    $response = '配置重载成功' . PHP_EOL;
                    $response .= '>>> ';
                    $server->send($fd, $response);
                } catch (\Exception $e) {
                    $response = '配置重载失败: ' . PHP_EOL;
                    $response .= '>>> ';
                    $server->send($fd, $response);
                }
            } elseif ($command == 'reload task' || $command == 'show task') {
                $response = '缺少任务名称'. PHP_EOL;
                $response.= '>>> ';
                $server->send($fd, $response);
            } elseif ($command == '') {
                $response = '>>> ';
                $server->send($fd, $response);
            } else {
                $response = '不支持该命令'. PHP_EOL;
                $response.= '>>> ';
                $server->send($fd, $response);
            }
        });
        //客户端关闭连接
        $socket->on('Close', function(Server $server, $fd) {

        });
        //启动socket服务
        $socket->start();
    }

    /**
     * 是否在运行
     *
     * @param string $file
     * @param array $flag
     * @return bool
     */
    private function _isRunning($file, array $flag)
    {
        $command = "ps -ef | grep $file |";
        foreach ($flag as $v) {
            $command.= " grep ". $v. " |";
        }
        $command.= " grep -v grep | wc -l";
        exec($command, $count);
        $count = intval(trim($count[0]));
        return $count > 0;
    }

    /**
     * 通过进程号判断进程是否存在
     *
     * @param $pid
     * @return bool
     */
    private function _existProcess($pid)
    {
        $command = "ps ax | awk '{print $1}' | grep $pid | wc -l";
        exec($command, $count);
        $count = intval(trim($count[0]));
        return $count > 0;
    }

    /**
     * kill进程
     *
     * @param string $file
     * @param array $flag
     * @return null
     */
    private function _psKill($file, array $flag)
    {
        $command = "ps -ef | grep $file |";
        foreach ($flag as $v) {
            $command.= " grep ". $v. " |";
        }
        $command.= " grep -v grep | awk '{print $2}' | xargs kill -9";
        exec($command);
    }

    /**
     * 加载配置项
     *
     * @param null $item
     * @return null
     */
    private function _loadConfig($item = null)
    {
        $config = include($this->_config);
        if (!is_array($config)) {
            throw new RuntimeException('配置文件必须返回一个数组');
        }
        if (!$item) {
            $this->_tasks = [];
            foreach ($config as $name => $task) {
                $this->_tasks[$name]['last_execute_time'] = 0;
                $this->_tasks[$name]['last_check_time'] = 0;
                $this->_tasks[$name]['setting'] = $task;
            }
        } elseif ($task = $config[$item]) {
            $this->_tasks[$item]['last_execute_time'] = 0;
            $this->_tasks[$item]['last_check_time'] = 0;
            $this->_tasks[$item]['setting'] = $task;
        } else {
            throw new RuntimeException('无效的配置项['. $item. ']');
        }
    }

    /**
     * 解析并处理
     *
     */
    private function _process()
    {

        foreach ($this->_tasks as $name=> $task) {

            if (!$task['setting']['running']) {
                $this->_show(sprintf('任务[%s]已关闭', $name), self::LEVEL_NOTICE);
                continue;
            }
            if ($task['setting']['host'] != '*') {
                $hosts = array_map('trim', explode(',', $task['setting']['host']));
                $host = `hostname`;
                if (!in_array($host, $hosts)) {
                    $this->_show(sprintf('任务[%s]仅允许在名为[%s]的主机上运行', $name, $task['setting']['host']), self::LEVEL_NOTICE);
                    continue;
                }
            }
            $last_execute_time = $task['last_execute_time'];
            if (is_null($last_execute_time)) {
                $last_execute_time = 0;
            }
            $setting = $task['setting'];
            $timer = array_map('trim', explode(' ', $setting['timer']));

            if (count($timer) != 5) {
                $this->_show(sprintf('任务[%s][timer]配置项格式异常: 时间设置项数量不符合', $name), self::LEVEL_ERROR);
                continue;
            }
            foreach ($timer as $item) {
                if (!preg_match('/^[\*\d\-\,\/]*?$/', $item)) {
                    $this->_show(sprintf('任务[%s][timer]配置项格式异常: 包含非法字符', $name), self::LEVEL_ERROR);
                    continue;
                }
            }

            //计算按周执行方式
            $run_in_week = true;
            $week = $timer[4];
            if ($week != '*') {
                if (strpos($week, '/') !== false) {
                    $this->_show(sprintf('任务[%s][timer]配置项格式异常: 周字段不能包含[/]', $name), self::LEVEL_ERROR);
                    continue;
                }
                $week_days = [];
                if (strpos($week, ',') !== false) {
                    $week_days = array_map('trim', explode(',', $week));
                } elseif (strpos($week, '-') !== false) {
                    $range = array_map('trim', explode('-', $week));
                    $week_days = range($range[0], $range[1]);
                }
                $week_day_list = range(0, 6);
                if (array_diff($week_days, $week_day_list)) {
                    $this->_show(sprintf('任务[%s][timer]配置项异常：周字段格式错误', $name), self::LEVEL_ERROR);
                    continue;
                }
                $timer[3] = '*';
                $timer[2] = '*';
                $week_day = date('w');
                if (!in_array($week_day, $week_days)) {
                    $run_in_week = false;
                }
            }

            //计算按月执行方式
            $run_in_month = true;
            $month = $timer[3];
            if ($month != '*') {
                if (strpos($month, '/') !== false) {
                    $this->_show(sprintf('任务[%s][timer]配置项异常: 月份字段不能包含[/]', $name), self::LEVEL_ERROR);
                    continue;
                }
                $monthes = [];
                if (strpos($month, ',') !== false) {
                    $monthes = array_map('trim', explode(',', $month));
                } elseif (strpos($month, '-') !== false) {
                    $range = array_map('trim', explode('-', $month));
                    $monthes = range($range[0], $range[1]);
                } elseif (is_numeric($month)) {
                    $monthes = [$month];
                }
                $monthes_list = range(1, 12);
                if (array_diff($monthes, $monthes_list)) {
                    $this->_show(sprintf('任务[%s][timer]配置项异常：月份字段格式错误', $name), self::LEVEL_ERROR);
                    continue;
                }
                $month_number = intval(date('m'));
                if (!in_array($month_number, $monthes)) {
                    $run_in_month = false;
                }
            }

            //计算按日执行方式
            $run_in_today = true;
            $day = $timer[2];
            if ($day != '*') {
                $real_days_list = [];
                if (strpos($day, '/') !== false) {
                    $days = explode('/', $day);
                    $range = $days[0];
                    $freq = $days[1];
                    if (!preg_match('/^[\d\-\*]*?$/', $range)) {
                        $this->_show(sprintf('任务[%s][timer]配置项异常：日字段格式错误', $name), self::LEVEL_ERROR);
                        continue;
                    }
                    if ($range == '*') {
                        $days_list = range(1, 31);
                    } elseif (strpos($range, '-') !== false) {
                        $days_range = array_map('trim', explode('-', $range));
                        $days_list = range($days_range[0], $days_range[1]);
                    } else {
                        $this->_show(sprintf('任务[%s][timer]配置项异常：日字段格式错误', $name), self::LEVEL_ERROR);
                        continue;
                    }
                    if (!is_numeric($freq)) {
                        $this->_show(sprintf('任务[%s][timer]配置项异常：日字段格式错误', $name), self::LEVEL_ERROR);
                        continue;
                    }
                    $i = 0;
                    foreach ($days_list as $k=> $v) {
                        if ($i == 0 || $i % $freq == 0) {
                            $real_days_list[] = $v;
                        }
                        $i += 1;
                    }
                } else {
                    if (strpos($day, '-') !== false) {
                        $days_range = array_map('trim', explode('-', $day));
                        $days_list = range($days_range[0], $days_range[1]);
                    } elseif (strpos($day, ',') !== false) {
                        $days_list = array_map('trim', explode(',', $day));
                    } elseif (is_numeric($day)) {
                        $days_list = [$day];
                    } else {
                        $this->_show(sprintf('任务[%s][timer]配置项异常：日字段格式错误', $name), self::LEVEL_ERROR);
                        continue;
                    }
                    $real_days_list = $days_list;
                }
                $today = intval(date('d'));
                if (!in_array($today, $real_days_list)) {
                    $run_in_today = false;
                }
            }

            //计算按小时执行
            $run_in_hour = true;
            $hour = $timer[1];
            if ($hour != '*') {
                $real_hour_list = [];
                if (strpos($hour, '/') !== false) {
                    $hours = explode('/', $hour);
                    $range = $hours[0];
                    $freq = $hours[1];
                    if (!preg_match('/^[\d\-\*]*?$/', $range)) {
                        $this->_show(sprintf('任务[%s][timer]配置项异常：小时字段格式错误', $name), self::LEVEL_ERROR);
                        continue;
                    }
                    if ($range == '*') {
                        $hours_list = range(0, 23);
                    } elseif (strpos($range, '-') !== false) {
                        $hours_range = array_map('trim', explode('-', $range));
                        $hours_list = range($hours_range[0], $hours_range[1]);
                    } else {
                        $this->_show(sprintf('任务[%s][timer]配置项异常：小时字段格式错误', $name), self::LEVEL_ERROR);
                        continue;
                    }
                    if (!is_numeric($freq)) {
                        $this->_show(sprintf('任务[%s][timer]配置项异常：小时字段格式错误', $name), self::LEVEL_ERROR);
                        continue;
                    }
                    $i = 0;
                    foreach ($hours_list as $k=> $v) {
                        if ($i == 0 || $i % $freq == 0) {
                            $real_hour_list[] = $v;
                        }
                        $i += 1;
                    }
                } else {
                    if (strpos($hour, '-') !== false) {
                        $hours_range = array_map('trim', explode('-', $hour));
                        $hours_list = range($hours_range[0], $hours_range[1]);
                    } elseif (strpos($hour, ',') !== false) {
                        $hours_list = array_map('trim', explode(',', $hour));
                    } elseif (is_numeric($hour)) {
                        $hours_list = [$hour];
                    } else {
                        $this->_show(sprintf('任务[%s][timer]配置项异常：小时字段格式错误', $name), self::LEVEL_ERROR);
                        continue;
                    }
                    $real_hour_list = $hours_list;
                }
                $now_hour = intval(date('H'));
                if (!in_array($now_hour, $real_hour_list)) {
                    $run_in_hour = false;
                }
            }

            //计算按分钟执行
            $run_in_minute = true;
            $minute = $timer[0];
            if ($minute != '*') {
                $real_minute_list = [];
                if (strpos($minute, '/') !== false) {
                    $minutes = explode('/', $minute);
                    $range = $minutes[0];
                    $freq = $minutes[1];
                    if (!preg_match('/^[\d\-\*]*?$/', $range)) {
                        $this->_show(sprintf('任务[%s][timer]配置项异常：分钟字段格式错误', $name), self::LEVEL_ERROR);
                        continue;
                    }
                    if ($range == '*') {
                        $minutes_list = range(0, 59);
                    } elseif (strpos($range, '-') !== false) {
                        $minutes_range = array_map('trim', explode('-', $range));
                        $minutes_list = range($minutes_range[0], $minutes_range[1]);
                    } else {
                        $this->_show(sprintf('任务[%s][timer]配置项异常：分钟字段格式错误', $name), self::LEVEL_ERROR);
                        continue;
                    }
                    if (!is_numeric($freq)) {
                        $this->_show(sprintf('任务[%s][timer]配置项异常：分钟字段格式错误', $name), self::LEVEL_ERROR);
                        continue;
                    }
                    $i = 0;
                    foreach ($minutes_list as $k=> $v) {
                        if ($i == 0 || $i % $freq == 0) {
                            $real_minute_list[] = $v;
                        }
                        $i += 1;
                    }
                } else {
                    if (strpos($minute, '-') !== false) {
                        $minutes_range = array_map('trim', explode('-', $minute));
                        $minutes_list = range($minutes_range[0], $minutes_range[1]);
                    } elseif (strpos($minute, ',') !== false) {
                        $minutes_list = array_map('trim', explode(',', $minute));
                    } elseif (is_numeric($minute)) {
                        $minutes_list = [$minute];
                    } else {
                        $this->_show(sprintf('任务[%s][timer]配置项异常：分钟字段格式错误', $name), self::LEVEL_ERROR);
                        continue;
                    }
                    $real_minute_list = $minutes_list;
                }
                $now_minute = intval(date('i'));
                if (!in_array($now_minute, $real_minute_list)) {
                    $run_in_minute = false;
                }
            }

            $this->_tasks[$name]['last_check_time'] = time();
            $this->_tasks[$name]['last_check_datetime'] = date('Y-m-d H:i:s');

            //执行
            if ($run_in_week && $run_in_month
                    && $run_in_today && $run_in_hour && $run_in_minute
                    && time() - $last_execute_time >= 60) {
                try {
                    if ($command = $this->_runTask($name, $setting)) {
                        $this->_show(sprintf('任务[%s]已执行命令：%s', $name, $command), self::LEVEL_NOTICE);
                    }
                } catch (\Exception $e) {
                    $this->_show($e->getMessage(), self::LEVEL_ERROR);
                }
            } else {
                $message = 'week:'. ($run_in_week ? '1' : '0'). ',';
                $message.= 'month:'. ($run_in_month ? '1' : '0'). ',';
                $message.= 'day:'. ($run_in_today ? '1' : '0'). ',';
                $message.= 'hour:'. ($run_in_hour ? '1' : '0'). ',';
                $message.= 'minute:'. ($run_in_minute ? '1' : '0');
                $this->_show(sprintf('任务[%s]未达到执行条件[%s]', $name, $message), self::LEVEL_NOTICE);
            }

        }

    }

    /**
     * 运行任务
     * 
     * @param string $name
     * @param array $setting
     * @return null
     */
    private function _runTask($name, array $setting) 
    {
        if (is_string($setting['output'])) {
            $output = $setting['output'];
        } elseif (is_callable($setting['output'])) {
            $output = call_user_func_array($setting['output'], []);
            if (!is_string($output)) {
                throw new RuntimeException(sprintf('任务[%s][output]配置项异常：匿名函数必须返回字符串', $name));
            }
        }
        if (!$output) {
            $output = '/tmp/task.'. $name. '.log';
        }
        if (!is_dir(dirname($output)) && !Toolkit::mkDir(dirname($output))) {
            throw new RuntimeException(sprintf('任务[%s][output]配置项异常：无法创建输出目录', $name));
        }
        if (!is_file($setting['file'])) {
            throw new RuntimeException(sprintf('任务[%s][file]配置项异常：文件不存在', $name));
        }
        $command = '';
        if ($setting['env']) {
            foreach ($setting['env'] as $k=> $v) {
                $command.= sprintf('export %s=%s', $k, $v). ' && ';
            }
        }
        $command.= $setting['processer']. ' '. $setting['file']. ' '. $setting['parameter']. ' 1>> '. $output. ' 2>> '. $output. ' &';
        if (!$this->_isRunning($setting['file'], (array)$setting['flag'])) {
            if (!$this->_existProcess($this->_soldier_pid)) {
                throw new RuntimeException(sprintf('任务[%s]启动失败：命令执行者进程异常', $name));
            }
            $this->_tasks[$name]['last_execute_time'] = time();
            $this->_tasks[$name]['last_execute_datetime'] = date('Y-m-d H:i:s');
            $this->_soldier->write($command);
        } elseif ($this->_isRunning($setting['file'], (array)$setting['flag']) && $setting['force']) {
            $this->_psKill($setting['file'], (array)$setting['flag']);
            if (!$this->_existProcess($this->_soldier_pid)) {
                throw new RuntimeException(sprintf('任务[%s]启动失败：命令执行者进程异常', $name));
            }
            $this->_tasks[$name]['last_execute_time'] = time();
            $this->_tasks[$name]['last_execute_datetime'] = date('Y-m-d H:i:s');
            $this->_soldier->write($command);
        } else {
            return '';
        }
        return $command;
    }

    /**
     * 打印日志
     *
     * @param string $log
     * @param string $level
     */
    private function _show($log, $level = self::LEVEL_NOTICE)
    {
        $content = date('Y-m-d H:i:s'). ' / '. $level. ' / '. $log. PHP_EOL;
        echo $content;
    }

    /**
     * 格式化大小值
     *
     * @param $size
     * @return string
     */
    private function _formatSize($size)
    {
        $prec = 3;
        $size = round(abs($size));
        $units = array('B', 'KB', 'MB', 'GB', 'TB');
        if (!$size) {
            return str_repeat(' ', $prec). '0'. $units[0];
        }
        $unit = min(4, floor(log($size)/log(2)/10));
        $size = $size*pow(2, -10*$unit);
        $digi = $prec-1- floor(log($size)/log(10));
        $size = round($size*pow(10, $digi))*pow(10, -$digi);
        return $size. ' '. $units[$unit];
    }

    /**
     * 画字段
     *
     * @param $str
     * @param int $length
     * @return string
     */
    private function _drawField($str, $length = 80)
    {
        $str_splited = preg_split('/(?<!^)(?!$)/u', $str);
        $ascii = $mb_char = 0;
        foreach ($str_splited as $k=> $v) {
            if (preg_match('/[\x{4e00}-\x{9fa5}]+/u', $v)) {
                $mb_char += 1;
            } else {
                $ascii += 1;
            }
        }
        return $str. str_pad('', $length - strlen($str) + $mb_char, ' '). '| ';
    }

    /**
     * 画线
     *
     * @param int $length
     * @return string
     */
    private function _drawLine($length = 80)
    {
        return str_pad('', $length, '-');
    }

}
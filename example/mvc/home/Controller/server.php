<?php

namespace App\Controller;

use Ark\Core\Caption;
use Ark\Database\Driver\Oci;

class Server extends Init
{

    function index()
    {

        $serv = new \swoole_server('127.0.0.1', 9501);

        $serv->set(array(
            'worker_num' => 2,
            //'daemonize' => true,
            //'log_file'=> '/tmp/dbpool.log',
        ));

        global $db_pool, $db_conf;
        $db_pool = array(); 
        $db_conf = $this->config->database->master->toArray();

        $serv->on('Start', function(\swoole_server $serv) {
            echo sprintf('[%s] server started.', date('Y-m-d H:i:s')) . PHP_EOL;
        });

        $serv->on('WorkerStart', function(\swoole_server $serv, $worker_id) {
            global $db_pool, $db_conf;
            for ($i = 1; $i <= 3; $i++) {
                try {
                    $driver = new Oci($db_conf['dsn'], array('type'=> 'persistent'));
                    $db_pool[] = array(
                        'worker_id'=> $worker_id,
                        'id'=> (($worker_id + 1) * 10). $i,
                        'driver' => $driver,
                        'fd'=> -1,
                        'hash'=> spl_object_hash($driver),
                    );
                    echo sprintf('[%s] db connection[%s] created on worker[%s] .', date('Y-m-d H:i:s'), $i, $worker_id) . PHP_EOL;
                } catch (\Exception $e) {
                    echo sprintf('[%s] worker[%s] db connection create failed: %s', date('Y-m-d H:i:s'), $worker_id, $e->getMessage()) . PHP_EOL;
                }
            }
        });

        $serv->on('Connect', function (\swoole_server $serv, $fd, $from_id) {
            global $db_pool;
            $assigned = array();
            foreach ($db_pool as $k=> $v) {
                if ($v['fd'] == $fd) {
                    $assigned = $v;
                    break;
                }
            }
            if (!$assigned) {
                foreach ($db_pool as $k=> $v) {
                    if ($v['fd'] == -1) {
                        $db_pool[$k]['fd'] = $fd;
                        $assigned = $db_pool[$k];
                        break;
                    }
                }
            }
            $serv->send($fd, $assigned['id'] ? 1 : 0);
            if ($assigned['id']) {
                echo sprintf('[%s] fd[%s] connected on worker[%s]. assigned db pool: %s', date('Y-m-d H:i:s'), $fd, $serv->worker_id, $assigned['id']) . PHP_EOL;
            }
        });


        $serv->on('Receive', function(\swoole_server $serv, $fd, $from_id, $data) {
            global $db_pool;
            if (!$data = json_decode($data, true)) {
                $serv->send($fd, json_encode(array('status'=> 0, 'message'=> 'client data is wrong.')));
                echo sprintf('[%s] worker[%s] fd[%s] client data is wrong.', date('Y-m-d H:i:s'), $serv->worker_id, $fd) . PHP_EOL;
            } else {
                $driver = null;
                $driver_id = 0;
                $db_hash = '';
                foreach ($db_pool as $k=> $v) {
                    if ($v['fd'] == $fd) {
                        $driver = $v['driver'];
                        $driver_id = $v['id'];
                        $db_hash = $v['hash'];
                        break;
                    }
                }
                if ($driver) {
                    $method = $data['method'];
                    $params = $data['params'] ? $data['params'] : array();
                    try {
                        $data['status'] = 1;
                        if (!method_exists($driver, $method)) {
                            throw new \Exception('Invalid method.');
                        }
                        $data['result'] = call_user_func_array(array($driver, $method), $params);
                        $serv->send($fd, json_encode($data));
                    } catch (\Exception $e) {
                        $serv->send($fd, json_encode(array('status'=> 0, 'message'=> $e->getMessage())));
                        echo sprintf("[%s] worker[%s] fd[%s] has error: %s", date('Y-m-d H:i:s'), $serv->worker_id, $fd, $e->getMessage()). PHP_EOL;
                    }
                } else {
                    $serv->send($fd, json_encode(array('status'=> 0, 'message'=> 'Invalid driver.')));
                    echo sprintf("[%s] worker[%s] fd[%s] have no valid driver.", date('Y-m-d H:i:s'), $serv->worker_id, $fd). PHP_EOL;
                }
            }
        });

        $serv->on('Close', function (\swoole_server $serv, $fd) {
            global $db_pool;
            foreach ($db_pool as $k=> $v) {
                if ($v['fd'] == $fd) {
                    $db_pool[$k]['fd'] = -1;
                }
            }
            echo sprintf('[%s] fd[%s] closed.', date('Y-m-d H:i:s'), $fd) . PHP_EOL;
        });

        $serv->start();

    }

}

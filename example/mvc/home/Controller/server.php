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
            'worker_num' => 4,
            'daemonize' => false,
        ));

        global $db_pool, $db_conf;
        $db_pool = array(); 
        $db_conf = $this->config->database->master->toArray();

        $serv->on('WorkerStart', function(\swoole_server $serv, $worker_id) {
            global $db_pool, $db_conf;
            for ($i = 1; $i <= 9; $i++) {
                try {
                    $driver = new Oci($db_conf['dsn'], array('type'=> 'persistent'));
                    $db_pool[] = array(
                        'worker_id'=> $worker_id,
                        'id'=> (($worker_id + 1) * 10). $i,
                        'driver' => $driver,
                        'fd'=> -1,
                        'hash'=> spl_object_hash($driver),
                    );
                    echo sprintf('[%s] worker[%s] connection [%s] was created.', date('Y-m-d H:i:s'), $worker_id, $i) . PHP_EOL;
                } catch (\Exception $e) {
                    echo sprintf('[%s] worker[%s] connection [%s] create failed.', date('Y-m-d H:i:s'), $worker_id, $i) . PHP_EOL;
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
            echo sprintf('[%s] work[%s] fd[%s] connected.', date('Y-m-d H:i:s'), $serv->worker_id, $fd) . PHP_EOL;
            echo sprintf('[%s] work[%s] fd[%s] assigned db pool: %s', date('Y-m-d H:i:s'), $serv->worker_id, $fd, $assigned['id']) . PHP_EOL;
        });


        $serv->on('Receive', function(\swoole_server $serv, $fd, $from_id, $data) {
            global $db_pool;
            if (!$data = @json_decode($data, true)) {
                echo sprintf('[%s] client[%s] data is wrong.', date('Y-m-d H:i:s'), $fd) . PHP_EOL;
                $serv->send($fd, json_encode(array('status'=> 0, 'message'=> 'invalid data.')), $from_id);
                $serv->close($fd, $from_id);
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
                $method = $data['method'];
                $sql = $data['sql'];
                $params = $data['params'] ? $data['params'] : array();
                try {
                    $result = $driver->$method($sql, $params);
                } catch (\Exception $e) {
                    echo $e->getMessage(). PHP_EOL;
                }
                $data['result'] = $result;
                $serv->send($fd, json_encode($data), $from_id);
                echo sprintf("[%s] work[%s] fd[%s] db hash[%s]", date('Y-m-d H:i:s'), $serv->worker_id, $fd, $db_hash). PHP_EOL;
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

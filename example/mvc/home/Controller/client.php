<?php

namespace App\Controller;

class Client extends Init
{

    function index()
    {
        $client = false;
        $client_id = $this->request->get('client_id');
        echo 'connecting';
        $connected = false;
        $i = 0;
        while ($i < 10) {
            echo '.';
            $client = new \swoole_client(SWOOLE_TCP);
            $client->connect('127.0.0.1', 9501);
            if ($client->recv()) {
                $connected = true;
                break;
            }
            $client->close();
            sleep(1);
            $i ++;
        }
        if (!$connected) {
            echo('failed.'. PHP_EOL);
            exit;
        }
        $i = 0;
        //recv方法尽量每次send后都接收一次，不然同一会话中，下一次接收到的可能是上一个send的响应
        $client->send(json_encode(array('method'=> 'beginTransaction', 'params'=> array())));
        var_dump(json_decode($client->recv(), true));
        $client->send(json_encode(array('method'=> 'fetchRow', 'params'=> array('select * from ext_order where xh=2201 for update'))));
        print_r(json_decode($client->recv(), true));
        var_dump(json_decode($client->recv(), true));
        sleep(20);
        $client->send(json_encode(array('method'=> 'commit', 'params'=> array())));
        echo 'ok'. PHP_EOL;
        $result = json_encode($client->recv(), true);

    }

}
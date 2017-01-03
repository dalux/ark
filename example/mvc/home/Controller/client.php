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
        while ($i < 10) {
            $client->send(json_encode(array('method' => 'fetchAll', 'sql' => 'select * from user_jobs where rownum < '. $client_id)));
            $result = json_decode($client->recv(), true);
            echo sprintf('client[%s] request success. data count[%s]', $client_id, count($result['result'])). PHP_EOL;
            sleep(3);
            $i ++;
        }

    }

}
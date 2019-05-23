<?php

//此为配置文件模板，实际应该时可拷贝到具体环境中并加以修改

use Brisk\Kernel\Loader;
use Brisk\Kernel\Server;

return [

    'test'=> [
        //当前任务是否开启
        'running'       => true,
        //允许运行的主机名
        'host'          => '*',
        //任务PHP解释器
        'processer'     => '/usr/local/php56/bin/php',
        //目标PHP文件
        'file'          => Loader::realPath('./Support/Index.php'),
        //命令行参数
        'parameter'     => sprintf('--domain=%s --uri=/shell/consumer', Server::getDomain()),
        //输出结果路径
        'output'        => '/tmp/consumer.log',
        //定时器设置
        'timer'         => '*/2 * * * *',
        //进程识别符
        'flag'          => ['/shell/consumer'],
        //预设环境变量
        'env'           => [],
        //是否强制重启进程  
        'force'         => true,
        //当前任务描述
        'description'   => '测试进程',
    ],

];
<?php

require_once __DIR__. '/../boot.php';

\Ark\Core\Noah::init()
    //����Ӧ�������ռ估Ŀ¼
    ->setApp('App', \Ark\Core\Loader::realPath('./logic/index'))
    //���ø�Ӧ�������ļ���·��
    ->setConfigPath(\Ark\Core\Loader::realPath('./config/index.localhost.php'))
    ->addPrepare(function() {

    })
    ->run();

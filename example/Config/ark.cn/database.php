<?php

return array(
    'master'=> array(
        'driver'=> '\Ark\Database\Driver\Oci',
        'dsn'=> 'oci://xinhua:sys@orcl_198.198.198.177/?charset=utf8',
        'option'=> array(
            'type'=> 'persistent',
        ),
        #option可选值:
        #type: default|new|persisent 默认重用型链接|新链接|持久链接
        #dsn值示例：
        #oci://root:123456@127.0.0.1:1521/test?charset=gbk
        #sqlite:/dbpath/dbname.db
        #mysql://root:123456@127.0.0.1:3306/test?charset=utf8
        #pgsql://root:123456@127.0.0.1:5432/test?charset=utf8
        #sqlsrv://sys:123456@127.0.0.1:4899/test?charset=gbk
    ),
);
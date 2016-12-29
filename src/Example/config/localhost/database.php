<?php

return array(
    'master'=> array(
        'driver'=> '\Ark\Database\Driver\Pdo\Mysql',
        'dsn'=> 'mysql://username:password@127.0.0.1:3306/dbname?charset=utf8',
        'option'=> array(),
        #dsn值示例：
        #oci://root:123456@127.0.0.1:1521/test?charset=gbk
        #sqlite:/dbpath/dbname.db
        #mysql://root:123456@127.0.0.1:3306/test?charset=utf8
        #pgsql://root:123456@127.0.0.1:5432/test?charset=utf8
        #sqlsrv://sys:123456@127.0.0.1:4899/test?charset=gbk
    ),
);
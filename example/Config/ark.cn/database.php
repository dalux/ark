<?php

return array(
    'master'=> array(
        'driver'=> 'pdo_mysql',     #支持项(mysql|oci|pdo_mysql|pdo_oci|pdo_sqlite|...)
        'dsn'=> 'mysql://root:xinhua@198.198.198.177:3306/agent?charset=utf8',
        'option'=> array(),     #针对诸如pdo的扩展连接选项
        #dsn值示例：
        #oci://root:123456@127.0.0.1:1521/test?charset=gbk
        #sqlite:/dbpath/dbname.db
        #mysql://root:123456@127.0.0.1:3306/test?charset=utf8
        #pgsql://root:123456@127.0.0.1:5432/test?charset=utf8
        #sqlsrv://sys:123456@127.0.0.1:4899/test?charset=gbk
    ),
);
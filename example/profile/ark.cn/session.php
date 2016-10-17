<?php

return array(
    'driver'=> 'file',  #支持项(file|user)
    'expire_time'=> 1440,   #过期时间
    'save_path'=> \Ark\Core\Loader::realPath('./data/session/'),  #会话保存地址
    #如engine为user，则savepath的值格式为接口\Ark\Contract\CacheDriver的实例对象
    #...
);
<?php

return array(
    //说明
    'remark'=> '这是一个配置模板, 正式应用配置时请删除本行',
    //是否调试模式
    'debug'=> true,
    //时区
    'timezone'=> 'Asia/Shanghai',
    //是否显示错误报告
    'show_error'=> true,
    //错误报告级别
    'error_reporting'=> E_ALL^E_NOTICE^E_WARNING^E_DEPRECATED,
    //附加组件目录
    'plugin_dir'=> \Ark\Core\Loader::realPath('./Plugin'),
);
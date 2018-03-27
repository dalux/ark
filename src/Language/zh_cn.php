<?php

return array(

    'core.framework_not_ready'          => '框架尚未初始化',
    'core.invalid_app_name'             => '未设置应用程序名称',
    'core.invalid_app_path'             => '未设置应用程序目录或目录不存在',
    'core.invalid_controller_path'      => '控制器目录必须位于应用程序集目录下',
    'core.invalid_config_path'          => '无效的配置文件路径',
    'core.invalid_configuration'        => '未找到有效的配置信息',
    'core.invalid_config_format'        => '配置文件[%s]必须返回数组格式数据',
    'core.object_not_found'             => '无法找到成员[%s]',
    'core.deny_alias_redeclare'         => '不能重定义系统保留别名[%s]',
    'core.invalid_autoloader'           => '自动加载器不可调用',
    'core.format_path_failed'           => '无法格式化指定的路径',
    'core.class_path_notfound'          => '类名称[%s]对应的文件不存在',
    'core.invlid_custom_member'         => '自定义成员[%s]并须返回一个有效对象',

    'com.invalid_view_template'         => '无有效的视图模板文件',
    'http.request_not_ready'            => 'Http请求数据未就绪',

    'event.struct_check_failed'         => '事件监听器[%s]返回值结构校验失败[%s]',
    'event.data_must_array'             => '事件监听器[%s]必须返回一个数组',
    'event.data_key_must_equal'         => '事件监听器[%s]数组返回键值不完整',

    'cache.config_not_found'            => '找不到缓存配置项[%s]',
    'cache.driver_not_found'            => '缓存驱动器类[%s]不存在',
    'cache.driver_implement_error'      => '缓存驱动器类[%s]必须继承自[%s]类',
    'cache.dir_create_failed'           => '无法创建缓存文件保存目录[%s]',
    'cache.dir_permission_error'        => '缓存目录[%s]读写权限不足',
    'cache.extension_load_failed'       => '加载扩展[%s]失败',
    'cache.cacher_create_failed'        => '缓存器对象[%s]创建失败',
    'cache.path_mustbe_notnull'         => '格式化路径函数返回值不能为空',

    'db.parse_sql_failed'               => 'SQL语句解析失败',
    'db.connect_failed'                 => '数据库连接失败',
    'db.config_not_found'               => '找不到数据库配置项[%s]',
    'db.driver_not_found'               => '数据库驱动器类[%s]不存在',
    'db.driver_implement_error'         => '数据库驱动器类[%s]须实现[%s]及[%s]接口',
    'db.extension_load_failed'          => '加载扩展[%s]失败',
    'db.querier_type_missing'           => '缺少数据库类型参数',
    'db.invalid_conn_string'            => '无效的数据库连接字符串[%s]',

    'router.uri_parse_failed'           => '路由解析结果异常[%s]',
    'router.invalid_controller_name'    => '无有效的控制器名称',
    'router.controller_not_found'       => '请求的控制器[%s]不存在',
    'router.invalid_driver_name'        => '无有效的路由驱动器名称',
    'router.driver_not_found'           => '路由驱动器类[%s]不存在',
    'router.driver_implement_error'     => '路由驱动器类[%s]必须实现[%s]接口',
    'router.call_func_failed'           => '无法调用自定义Uri重写函数[%s]',
    'router.uri_must_string'            => '重写后的Uri必须是一个字符串',
    'router.controller_is_protected'    => '访问了非公开的控制器[%s]',

    'sess.invalid_driver_name'          => '无有效的会话驱动器名称',
    'sess.driver_not_found'             => '会话驱动器类[%s]不存在',
    'sess.driver_implement_error'       => '会话驱动器类[%s]必须实现[%s]接口',
    'sess.cacher_implement_error'       => '会话存储器必须实现[%s]接口',

    'view.invalid_driver_name'          => '无有效的视图驱动器名称',
    'view.driver_not_found'             => '视图驱动器类[%s]不存在',
    'view.driver_implement_error'       => '视图驱动器类[%s]必须实现[%s]接口',
    'view.template_not_found'           => '模板文件[%s]不存在',
    'view.include_file_not_found'       => '要包含的文件[%s]不存在',

    'tbox.invalid_db_connstr'           => '无效的数据库连接字符串[%s]',
    'tbox.invalid_create_path'          => '未指定要创建的目录路径',
    'tbox.parse_string_failed'          => '无法解析字符串[%s]:[%s]',
    'tbox.no_db_instance'               => '未设置数据库连接对象实例',

    'proxy.target_not_callable'         => '指定的对象或方法无法调用',

);
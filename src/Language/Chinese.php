<?php

return array(

    'core.invalid_app_property'         => '未设置应用程序名称及程序集根目录地址',
    'core.invalid_controller_dir'       => '控制器目录必须位于应用程序集目录下',
    'core.invalid_config_dir'           => '无效的配置文件目录',
    'core.invalid_configuration'        => '未找到有效的配置信息',
    'core.object_not_found'             => '无法找到成员[%s]',
    'core.deny_alias_redeclare'         => '不能重定义系统保留别名[%s]',
    'core.invalid_autoloader'           => '自动加载器不可调用',
    'core.format_path_failed'           => '无法格式化指定的路径',

    'com.invalid_view_template'         => '无有效的视图模板文件',

    'event.struct_check_failed'         => '事件监听器[%s]返回值结构校验失败[%s]',
    'event.data_must_array'             => '事件监听器[%s]必须返回一个数组',

    'cache.config_not_found'            => '找不到缓存配置项[%s]',
    'cache.driver_not_found'            => '缓存驱动器类[%s]不存在',
    'cache.driver_implement_error'      => '缓存驱动器类[%s]必须实现[%s]接口',
    'cache.dir_create_failed'           => '无法创建缓存文件保存目录[%s]',
    'cache.dir_permission_error'        => '缓存目录[%s]读写权限不足',
    'cache.extension_load_failed'       => '加载扩展[%s]失败',
    'cache.cacher_create_failed'        => '缓存器对象[%s]创建失败',

    'db.parse_sql_failed'               => 'SQL语句解析失败',
    'db.connect_failed'                 => '数据库连接失败',
    'db.config_not_found'               => '找不到数据库配置项[%s]',
    'db.driver_not_found'               => '数据库驱动器类[%s]不存在',
    'db.driver_implement_error'         => '数据库驱动器类[%s]须实现[%s]及[%s]接口',
    'db.extension_load_failed'          => '加载扩展[%s]失败',

    'router.uri_parse_failed'           => '路由解析结果异常[%s]',
    'router.action_not_found'           => '控制器类[%s]中不存在行为[%s]',
    'router.controller_extends_error'   => '控制器必须继承自类[%s]',
    'router.invalid_action_name'        => '无有效的行为名称',
    'router.invalid_controller_name'    => '无有效的控制器名称',
    'router.controller_not_found'       => '请求的控制器类[%s]不存在',
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

    'struct.load_rulefile_failed'       => '无法加载规则文件[%s]',
    'struct.return_type_error'          => '规则文件[%s]必须返回一个数组',
    'struct.field_is_required'          => '字段[%s]必须填写',
    'struct.field_more_than'            => '字段[%s]必须填写至少一个',
    'struct.field_type_nomatch'         => '字段[%s]类型不匹配, 需要[%s], 目前为[%s]',
    'struct.field_outof_range'          => '字段[%s]范围超出',
    'struct.value_greater_than'         => '字段[%s]值不能小于[%s]',
    'struct.value_less_than'            => '字段[%s]值不能大于[%s]',
    'struct.length_greater_than'        => '字段[%s]长度低于最小值, 需要[%s], 目前为[%s]',
    'struct.length_less_than'           => '字段[%s]长度高于最大值, 需要[%s], 目前为[%s]',
    'struct.content_not_equal'          => '字段[%s]内容不符, 需要[%s], 目前为[%s]',
    'struct.object_not_instanceof'      => '字段[%s]内容不符, 需要继承或实现对象[%s]',
    'struct.regexp_not_match'           => '字段[%s]内容不匹配正则[%s]',

);
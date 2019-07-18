<?php declare(strict_types=1);

namespace Brisk\Kernel;

class Language
{

    /**
     * 当前语言
     *
     * @var string
     */
    private static $_lang = 'zh_cn';

    /**
     * 语言包
     *
     * @var array
     */
    private static $_package = [

        'zh_cn'=> [

            'core.invalid_configuration'        => '未找到有效的配置信息:必须返回一个数组',
            'core.object_not_found'             => '目标对象[%s]未找到',
            'core.format_path_failed'           => '无法格式化指定路径[%s]',
            'core.invlid_custom_member'         => '无效的自定义成员对象[%s]',
            'core.config_not_found'				=> '无法找到配置项[%s]',
            'core.class_extends_error'          => '当前类[%s]必须继承自[%s]类',
            'core.class_implement_error'        => '当前类[%s]必须实现接口[%s]',
            'core.class_not_found'              => '无法加载指定类[%s]',
            
            'event.data_must_array'             => '事件监听器[%s]必须返回一个数组',
            'event.data_key_must_equal'         => '事件监听器[%s]返回前后数组项不一致',

            'http.request_not_ready'            => '请求数据未准备就绪',
            'http.invalid_require_uri'          => '无有效的请求URI地址',

            'cache.dir_create_failed'           => '无法创建目录[%s]',
            'cache.dir_permission_error'        => '无权限读写指定目录[%s]',
            'cache.extension_load_failed'       => '无法载入指定扩展[%s]',
            'cache.cacher_create_failed'        => '缓存器对象[%s]创建失败',
            'cache.path_mustbe_notnull'         => '缓存保存路径不能为空',
            'proxy.target_not_callable'         => '指定的代理对象方法不可调用',
            'proxy.invalid_cacher_object'		=> '无效的缓存器对象',

            'db.extension_load_failed'          => '无法载入指定扩展[%s]',
            'db.invalid_connection_object'      => '未设置数据库连接对象实例',
            'db.invalid_table_name'             => '无有效的数据库表名称',

            'router.route_not_defined'          => '未定义请求地址[%s]的路由解析器',
            'router.processer_not_callable'     => '路由[%s]解析器不可用',
            'router.blocker_not_callable'       => '路由[%s]拦截器不可用',

            'sql.query_compile_failed'          => 'SQL语句编译失败，缺少必要字段',

            'view.template_not_found'           => '未找到模板文件[%s]',
            'view.include_file_not_found'       => '未找到要引入的文件路径[%s]',

            'tool.validator_field_missing'      => '字段[%s]值不能为空',
            'tool.validator_field_errtype'      => '字段[%s]值类型不匹配,需要[%s],目前为[%s]',
            'tool.validator_field_outrange'     => '字段[%s]值不在允许的范围内',
            'tool.validator_filed_lessthan'     => '字段[%s]值不能小于[%s]',
            'tool.validator_filed_morethan'     => '字段[%s]值不能大于[%s]',
            'tool.validator_filed_minlength'    => '字段[%s]值长度低于最小值,需要[%s],目前为[%s]',
            'tool.validator_filed_maxlength'    => '字段[%s]值长度超过最大值,需要[%s],目前为[%s]',
            'tool.validator_field_noequal'      => '字段[%s]值内容不匹配,需要[%s],目前为[%s]',
            'tool.validator_field_errobject'    => '字段[%s]值内容不匹配,需要继承或实现[%s]',
            'tool.validator_filed_nomatch'      => '字段[%s]值不匹配规则[%s]',

            'tool.dir_create_failed'            => '目录[%s]创建失败',

            'tool.upload_error_occurred'        => '上传处理异常，错误代码[%s]',
            'tool.upload_types_unsupport'       => '不支持的上传类型[%s]',
            'tool.upload_bytes_oversize'        => '上传文件字节数不能大于[%s]',
            'tool.upload_filepath_error'        => '上传文件保存路径未设置',

        ],

    ];

    /**
     * 添加语言包
     *
     * @access public
     * @param string $lang
     * @param array $package
     * @return void
     */
    public static function set(string $lang, array $package = [])
    {
        if (!isset(self::$_package[$lang])) {
            self::$_package[$lang] = $package;
        } else {
            self::$_package[$lang] = array_merge(self::$_package[$lang], $package);
        }
    }

    /**
     * 获取指定语言包
     *
     * @access public
     * @param string $lang
     * @return array
     */
    public static function get(string $lang)
    {
        return self::$_package[$lang];
    }

    /**
     * 应用语言包
     *
     * @access public
     * @param string $lang
     * @return void
     */
    public static function apply(string $lang)
    {
        self::$_lang = $lang;
    }

    /**
     * 解析语言
     *
     * @param string $label
     * @param array $args
     * @return string
     */
    public static function format(string $label, ...$args)
    {
        $lang = self::$_lang;
        return vsprintf(self::$_package[$lang][$label], $args);
    }

}
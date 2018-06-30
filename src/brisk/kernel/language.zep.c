
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/array.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"


ZEPHIR_INIT_CLASS(Brisk_Kernel_Language) {

	ZEPHIR_REGISTER_CLASS(Brisk\\Kernel, Language, brisk, kernel_language, brisk_kernel_language_method_entry, 0);

	zend_declare_property_string(brisk_kernel_language_ce, SL("_language"), "zh_cn", ZEND_ACC_PRIVATE|ZEND_ACC_STATIC TSRMLS_CC);

	zend_declare_property_null(brisk_kernel_language_ce, SL("_package"), ZEND_ACC_PRIVATE|ZEND_ACC_STATIC TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Brisk_Kernel_Language, addPackage) {

	zval package;
	zval *language_param = NULL, *package_param = NULL, _0, _1$$3, _2$$3, _3$$3;
	zval language;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&language);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&package);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &language_param, &package_param);

	if (UNEXPECTED(Z_TYPE_P(language_param) != IS_STRING && Z_TYPE_P(language_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'language' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(language_param) == IS_STRING)) {
		zephir_get_strval(&language, language_param);
	} else {
		ZEPHIR_INIT_VAR(&language);
		ZVAL_EMPTY_STRING(&language);
	}
	ZEPHIR_OBS_COPY_OR_DUP(&package, package_param);


	zephir_read_static_property_ce(&_0, brisk_kernel_language_ce, SL("_package"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset(&_0, &language)) {
		ZEPHIR_INIT_VAR(&_1$$3);
		zephir_read_static_property_ce(&_2$$3, brisk_kernel_language_ce, SL("_package"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_3$$3, &_2$$3, &language, PH_NOISY | PH_READONLY, "brisk/Kernel/Language.zep", 91 TSRMLS_CC);
		zephir_fast_array_merge(&_1$$3, &_3$$3, &package TSRMLS_CC);
		zephir_update_static_property_array_multi_ce(brisk_kernel_language_ce, SL("_package"), &_1$$3 TSRMLS_CC, SL("z"), 1, &language);
	} else {
		zephir_update_static_property_array_multi_ce(brisk_kernel_language_ce, SL("_package"), &package TSRMLS_CC, SL("z"), 1, &language);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Brisk_Kernel_Language, setLanguage) {

	zval *language_param = NULL;
	zval language;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&language);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &language_param);

	if (UNEXPECTED(Z_TYPE_P(language_param) != IS_STRING && Z_TYPE_P(language_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'language' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(language_param) == IS_STRING)) {
		zephir_get_strval(&language, language_param);
	} else {
		ZEPHIR_INIT_VAR(&language);
		ZVAL_EMPTY_STRING(&language);
	}


	zend_update_static_property(brisk_kernel_language_ce, ZEND_STRL("_language"), &language);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Brisk_Kernel_Language, get) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval params;
	zval *label_param = NULL, *params_param = NULL, language, result, _0, _1, _2$$3, _3$$3, _4$$3, _5$$4, _6$$4;
	zval label;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&label);
	ZVAL_UNDEF(&language);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&params);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &label_param, &params_param);

	if (UNEXPECTED(Z_TYPE_P(label_param) != IS_STRING && Z_TYPE_P(label_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'label' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(label_param) == IS_STRING)) {
		zephir_get_strval(&label, label_param);
	} else {
		ZEPHIR_INIT_VAR(&label);
		ZVAL_EMPTY_STRING(&label);
	}
	if (!params_param) {
		ZEPHIR_INIT_VAR(&params);
		array_init(&params);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&params, params_param);
	}


	ZEPHIR_OBS_VAR(&language);
	zephir_read_static_property_ce(&language, brisk_kernel_language_ce, SL("_language"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(&result);
	ZVAL_BOOL(&result, 0);
	zephir_read_static_property_ce(&_0, brisk_kernel_language_ce, SL("_package"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch(&_1, &_0, &language, PH_READONLY, "brisk/Kernel/Language.zep", 106 TSRMLS_CC);
	if (zephir_array_isset(&_1, &label)) {
		zephir_read_static_property_ce(&_2$$3, brisk_kernel_language_ce, SL("_package"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_3$$3, &_2$$3, &language, PH_NOISY | PH_READONLY, "brisk/Kernel/Language.zep", 107 TSRMLS_CC);
		zephir_array_fetch(&_4$$3, &_3$$3, &label, PH_NOISY | PH_READONLY, "brisk/Kernel/Language.zep", 107 TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&result, "vsprintf", NULL, 41, &_4$$3, &params);
		zephir_check_call_status();
	}
	if (!zephir_is_true(&result)) {
		zephir_read_static_property_ce(&_5$$4, brisk_kernel_language_ce, SL("_package"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_6$$4, &_5$$4, &language, PH_NOISY | PH_READONLY, "brisk/Kernel/Language.zep", 110 TSRMLS_CC);
		ZEPHIR_OBS_NVAR(&result);
		zephir_array_fetch(&result, &_6$$4, &label, PH_NOISY, "brisk/Kernel/Language.zep", 110 TSRMLS_CC);
	}
	RETURN_CCTOR(&result);

}

void zephir_init_static_properties_Brisk_Kernel_Language(TSRMLS_D) {

	zval _0, _1;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 1, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_1);
	zephir_create_array(&_1, 63, 0 TSRMLS_CC);
	add_assoc_stringl_ex(&_1, SL("core.framework_not_ready"), SL("框架尚未初始化"));
	add_assoc_stringl_ex(&_1, SL("core.invalid_app_name"), SL("未设置应用程序名称"));
	add_assoc_stringl_ex(&_1, SL("core.invalid_app_path"), SL("未设置应用程序目录或目录不存在"));
	add_assoc_stringl_ex(&_1, SL("core.invalid_controller_path"), SL("未设置控制器目录或目录不存在"));
	add_assoc_stringl_ex(&_1, SL("core.invalid_configuration"), SL("未找到有效的配置信息"));
	add_assoc_stringl_ex(&_1, SL("core.invalid_config_format"), SL("配置文件[%s]必须返回数组格式数据"));
	add_assoc_stringl_ex(&_1, SL("core.object_not_found"), SL("无法找到成员[%s]"));
	add_assoc_stringl_ex(&_1, SL("core.invalid_autoloader"), SL("自动加载器不可调用"));
	add_assoc_stringl_ex(&_1, SL("core.format_path_failed"), SL("无法格式化指定的路径[%s]"));
	add_assoc_stringl_ex(&_1, SL("core.class_path_notfound"), SL("类名称[%s]对应的文件不存在"));
	add_assoc_stringl_ex(&_1, SL("core.invlid_custom_member"), SL("自定义成员[%s]必须返回一个有效对象"));
	add_assoc_stringl_ex(&_1, SL("core.invlid_custom_method"), SL("自定义方法[%s]必须可被调用"));
	add_assoc_stringl_ex(&_1, SL("core.custom_method_notfound"), SL("无法找到自定义方法[%s]"));
	add_assoc_stringl_ex(&_1, SL("core.config_not_found"), SL("找不到配置项[%s]"));
	add_assoc_stringl_ex(&_1, SL("com.invalid_view_template"), SL("无有效的视图模板文件"));
	add_assoc_stringl_ex(&_1, SL("http.request_not_ready"), SL("Http请求数据未就绪"));
	add_assoc_stringl_ex(&_1, SL("http.method_not_found"), SL("被调用的方法不存在[%s]"));
	add_assoc_stringl_ex(&_1, SL("http.property_not_found"), SL("被调用的属性对象不存在[%s]"));
	add_assoc_stringl_ex(&_1, SL("event.struct_check_failed"), SL("事件监听器[%s]返回值结构校验失败[%s]"));
	add_assoc_stringl_ex(&_1, SL("event.data_must_array"), SL("事件监听器[%s]必须返回一个数组"));
	add_assoc_stringl_ex(&_1, SL("event.data_key_must_equal"), SL("事件监听器[%s]数组返回键值不完整"));
	add_assoc_stringl_ex(&_1, SL("cache.driver_not_found"), SL("缓存驱动器类[%s]不存在"));
	add_assoc_stringl_ex(&_1, SL("cache.driver_implement_error"), SL("缓存驱动器类[%s]必须继承自[%s]类"));
	add_assoc_stringl_ex(&_1, SL("cache.dir_create_failed"), SL("无法创建缓存文件保存目录[%s]"));
	add_assoc_stringl_ex(&_1, SL("cache.dir_permission_error"), SL("缓存目录[%s]读写权限不足"));
	add_assoc_stringl_ex(&_1, SL("cache.extension_load_failed"), SL("加载扩展[%s]失败"));
	add_assoc_stringl_ex(&_1, SL("cache.cacher_create_failed"), SL("缓存器对象[%s]创建失败"));
	add_assoc_stringl_ex(&_1, SL("cache.path_mustbe_notnull"), SL("格式化路径函数返回值不能为空"));
	add_assoc_stringl_ex(&_1, SL("db.parse_sql_failed"), SL("SQL语句解析失败"));
	add_assoc_stringl_ex(&_1, SL("db.connect_failed"), SL("数据库连接失败"));
	add_assoc_stringl_ex(&_1, SL("db.driver_not_found"), SL("数据库驱动器类[%s]不存在"));
	add_assoc_stringl_ex(&_1, SL("db.driver_implement_error"), SL("数据库驱动器类[%s]须实现[%s]及[%s]接口"));
	add_assoc_stringl_ex(&_1, SL("db.extension_load_failed"), SL("加载扩展[%s]失败"));
	add_assoc_stringl_ex(&_1, SL("db.querier_type_missing"), SL("缺少数据库类型参数"));
	add_assoc_stringl_ex(&_1, SL("db.invalid_conn_string"), SL("无效的数据库连接字符串[%s]"));
	add_assoc_stringl_ex(&_1, SL("router.uri_parse_failed"), SL("路由解析结果异常[%s]"));
	add_assoc_stringl_ex(&_1, SL("router.invalid_controller_name"), SL("无有效的控制器名称"));
	add_assoc_stringl_ex(&_1, SL("router.class_not_found"), SL("请求的控制器类名称[%s]不存在"));
	add_assoc_stringl_ex(&_1, SL("router.action_not_found"), SL("控制器行为[%s]不存在"));
	add_assoc_stringl_ex(&_1, SL("router.controller_not_found"), SL("请求的控制器[%s]不存在"));
	add_assoc_stringl_ex(&_1, SL("router.invalid_driver_name"), SL("无有效的路由驱动器名称"));
	add_assoc_stringl_ex(&_1, SL("router.driver_not_found"), SL("路由驱动器类[%s]不存在"));
	add_assoc_stringl_ex(&_1, SL("router.driver_implement_error"), SL("路由驱动器类[%s]必须实现[%s]接口"));
	add_assoc_stringl_ex(&_1, SL("router.call_func_failed"), SL("无法调用自定义Uri重写函数[%s]"));
	add_assoc_stringl_ex(&_1, SL("router.uri_must_string"), SL("重写后的Uri必须是一个字符串"));
	add_assoc_stringl_ex(&_1, SL("router.controller_is_protected"), SL("访问了非公开的控制器[%s]"));
	add_assoc_stringl_ex(&_1, SL("sess.invalid_driver_name"), SL("无有效的会话驱动器名称"));
	add_assoc_stringl_ex(&_1, SL("sess.driver_not_found"), SL("会话驱动器类[%s]不存在"));
	add_assoc_stringl_ex(&_1, SL("sess.driver_implement_error"), SL("会话驱动器类[%s]必须实现[%s]接口"));
	add_assoc_stringl_ex(&_1, SL("sess.cacher_implement_error"), SL("会话存储器必须实现[%s]接口"));
	add_assoc_stringl_ex(&_1, SL("view.invalid_driver_name"), SL("无有效的视图驱动器名称"));
	add_assoc_stringl_ex(&_1, SL("view.driver_not_found"), SL("视图驱动器类[%s]不存在"));
	add_assoc_stringl_ex(&_1, SL("view.driver_implement_error"), SL("视图驱动器类[%s]必须实现[%s]接口"));
	add_assoc_stringl_ex(&_1, SL("view.template_not_found"), SL("模板文件[%s]不存在"));
	add_assoc_stringl_ex(&_1, SL("view.include_file_not_found"), SL("要包含的文件[%s]不存在"));
	add_assoc_stringl_ex(&_1, SL("tbox.invalid_db_connstr"), SL("无效的数据库连接字符串[%s]"));
	add_assoc_stringl_ex(&_1, SL("tbox.invalid_create_path"), SL("未指定要创建的目录路径"));
	add_assoc_stringl_ex(&_1, SL("tbox.invalid_db_connection"), SL("数据库连接对象必须实现[\\Brisk\\Contract\\IDatabase]接口"));
	add_assoc_stringl_ex(&_1, SL("tbox.invalid_cache_object"), SL("缓存器对象必须实现[\\Brisk\\Contract\\ICache]接口"));
	add_assoc_stringl_ex(&_1, SL("tbox.parse_string_failed"), SL("无法解析字符串[%s]:[%s]"));
	add_assoc_stringl_ex(&_1, SL("tbox.no_db_instance"), SL("未设置数据库连接对象实例"));
	add_assoc_stringl_ex(&_1, SL("proxy.target_not_callable"), SL("指定的对象或方法无法调用"));
	add_assoc_stringl_ex(&_1, SL("proxy.invalid_cacher_object"), SL("代理缓存器必须实现[%s]接口"));
	zephir_array_update_string(&_0, SL("zh_cn"), &_1, PH_COPY | PH_SEPARATE);
	zend_update_static_property(brisk_kernel_language_ce, ZEND_STRL("_package"), &_0);
	ZEPHIR_MM_RESTORE();

}


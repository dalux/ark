
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
#include "kernel/object.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/operators.h"


ZEPHIR_INIT_CLASS(Brisk_Kernel_App) {

	ZEPHIR_REGISTER_CLASS(Brisk\\Kernel, App, brisk, kernel_app, brisk_kernel_app_method_entry, 0);

	zend_declare_property_null(brisk_kernel_app_ce, SL("_config"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(brisk_kernel_app_ce, SL("_instance"), ZEND_ACC_PRIVATE|ZEND_ACC_STATIC TSRMLS_CC);

	zend_declare_property_null(brisk_kernel_app_ce, SL("_storage"), ZEND_ACC_PRIVATE|ZEND_ACC_STATIC TSRMLS_CC);

	zend_declare_property_null(brisk_kernel_app_ce, SL("_methods"), ZEND_ACC_PRIVATE|ZEND_ACC_STATIC TSRMLS_CC);

	zend_declare_class_constant_string(brisk_kernel_app_ce, SL("NAME"), "Brisk" TSRMLS_CC);

	zend_declare_class_constant_string(brisk_kernel_app_ce, SL("AUTHOR"), "guodalu <112183883@qq.com>" TSRMLS_CC);

	zend_declare_class_constant_string(brisk_kernel_app_ce, SL("VERSION"), "1.0.0" TSRMLS_CC);

	return SUCCESS;

}

/**
 * Set get configuration item method
 *
 * @param  callable config
 * @return App
 */
PHP_METHOD(Brisk_Kernel_App, setConfig) {

	zval *config;

	zephir_fetch_params(0, 1, 0, &config);

	if (UNEXPECTED(zephir_is_callable(config TSRMLS_CC) != 1)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'config' must be a callable") TSRMLS_CC);
		RETURN_NULL();
	}


	zephir_update_property_this(getThis(), SL("_config"), config TSRMLS_CC);
	RETURN_THISW();

}

PHP_METHOD(Brisk_Kernel_App, __construct) {

	


}

/**
 * Get current object instance
 *
 * @return App
 */
PHP_METHOD(Brisk_Kernel_App, getInstance) {

	zval *_6$$3 = NULL, *_17$$3 = NULL;
	zval *_0, *_18, *memory_usage$$3 = NULL, *_1$$3 = NULL, _2$$3 = zval_used_for_init, _3$$3, *rootdir$$3 = NULL, *_8$$3 = NULL, *_13$$3 = NULL, *debug_trace$$5 = NULL, *_9$$5, *_10$$5, _16$$7;
	zephir_fcall_cache_entry *_4 = NULL, *_5 = NULL, *_7 = NULL, *_11 = NULL, *_12 = NULL, *_14 = NULL, *_15 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_static_property_ce(brisk_kernel_app_ce, SL("_instance") TSRMLS_CC);
	if (Z_TYPE_P(_0) == IS_NULL) {
		ZEPHIR_CALL_FUNCTION(&memory_usage$$3, "memory_get_usage", NULL, 8);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_1$$3);
		object_init_ex(_1$$3, brisk_kernel_app_ce);
		ZEPHIR_CALL_METHOD(NULL, _1$$3, "__construct", NULL, 9);
		zephir_check_call_status();
		zephir_update_static_property_ce(brisk_kernel_app_ce, SL("_instance"), &_1$$3 TSRMLS_CC);
		ZEPHIR_SINIT_VAR(_2$$3);
		ZVAL_STRING(&_2$$3, "display_errors", 0);
		ZEPHIR_SINIT_VAR(_3$$3);
		ZVAL_STRING(&_3$$3, "1", 0);
		ZEPHIR_CALL_FUNCTION(NULL, "ini_set", NULL, 10, &_2$$3, &_3$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_1$$3);
		ZVAL_STRING(_1$$3, "sys_startup", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_CE_STATIC(NULL, brisk_kernel_timer_ce, "mark", &_4, 11, _1$$3);
		zephir_check_temp_parameter(_1$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_1$$3);
		ZVAL_STRING(_1$$3, "memory", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_CE_STATIC(NULL, brisk_kernel_trace_ce, "set", &_5, 12, _1$$3, memory_usage$$3);
		zephir_check_temp_parameter(_1$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_6$$3);
		zephir_create_array(_6$$3, 2, 0 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(_1$$3);
		object_init_ex(_1$$3, brisk_kernel_container_ce);
		ZEPHIR_CALL_METHOD(NULL, _1$$3, "__construct", &_7, 13);
		zephir_check_call_status();
		zephir_array_update_string(&_6$$3, SL("instance"), &_1$$3, PH_COPY | PH_SEPARATE);
		add_assoc_long_ex(_6$$3, SS("system"), 1);
		zephir_update_static_property_array_multi_ce(brisk_kernel_app_ce, SL("_storage"), &_6$$3 TSRMLS_CC, SL("s"), 2, SL("config"));
		ZEPHIR_SINIT_NVAR(_2$$3);
		ZVAL_STRING(&_2$$3, "__WEB_ROOT__", 0);
		ZEPHIR_CALL_FUNCTION(&_8$$3, "defined", NULL, 14, &_2$$3);
		zephir_check_call_status();
		if (zephir_is_true(_8$$3)) {
			ZEPHIR_INIT_VAR(rootdir$$3);
			ZEPHIR_GET_CONSTANT(rootdir$$3, "__WEB_ROOT__");
		} else {
			ZEPHIR_CALL_FUNCTION(&debug_trace$$5, "debug_backtrace", NULL, 15);
			zephir_check_call_status();
			zephir_array_fetch_long(&_9$$5, debug_trace$$5, 0, PH_NOISY | PH_READONLY, "brisk/Kernel/App.zep", 65 TSRMLS_CC);
			zephir_array_fetch_string(&_10$$5, _9$$5, SL("file"), PH_NOISY | PH_READONLY, "brisk/Kernel/App.zep", 65 TSRMLS_CC);
			ZEPHIR_CALL_FUNCTION(&rootdir$$3, "dirname", NULL, 16, _10$$5);
			zephir_check_call_status();
		}
		ZEPHIR_INIT_NVAR(_1$$3);
		ZVAL_STRING(_1$$3, ".", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_CE_STATIC(NULL, brisk_kernel_loader_ce, "setalias", &_11, 17, _1$$3, rootdir$$3);
		zephir_check_temp_parameter(_1$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_1$$3);
		ZVAL_STRING(_1$$3, "exception", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_CE_STATIC(NULL, brisk_kernel_handler_ce, "sethandler", &_12, 18, _1$$3);
		zephir_check_temp_parameter(_1$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_6$$3);
		zephir_create_array(_6$$3, 2, 0 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(_1$$3);
		ZVAL_STRING(_1$$3, "\\Brisk\\Kernel\\Loader", 1);
		zephir_array_fast_append(_6$$3, _1$$3);
		ZEPHIR_INIT_NVAR(_1$$3);
		ZVAL_STRING(_1$$3, "autoLoad", 1);
		zephir_array_fast_append(_6$$3, _1$$3);
		ZEPHIR_CALL_FUNCTION(NULL, "spl_autoload_register", NULL, 19, _6$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_CE_STATIC(&_13$$3, brisk_kernel_server_ce, "iscli", &_14, 20);
		zephir_check_call_status();
		if (zephir_is_true(_13$$3)) {
			ZEPHIR_CALL_CE_STATIC(NULL, brisk_kernel_server_ce, "initcli", &_15, 21);
			zephir_check_call_status();
		} else {
			ZEPHIR_SINIT_VAR(_16$$7);
			ZVAL_STRING(&_16$$7, "Content-type: text/html; charset=utf-8", 0);
			ZEPHIR_CALL_FUNCTION(NULL, "header", NULL, 22, &_16$$7);
			zephir_check_call_status();
		}
		ZEPHIR_INIT_VAR(_17$$3);
		zephir_create_array(_17$$3, 2, 0 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(_1$$3);
		object_init_ex(_1$$3, brisk_kernel_container_ce);
		ZEPHIR_CALL_METHOD(NULL, _1$$3, "__construct", &_7, 13);
		zephir_check_call_status();
		zephir_array_update_string(&_17$$3, SL("instance"), &_1$$3, PH_COPY | PH_SEPARATE);
		add_assoc_long_ex(_17$$3, SS("system"), 1);
		zephir_update_static_property_array_multi_ce(brisk_kernel_app_ce, SL("_storage"), &_17$$3 TSRMLS_CC, SL("s"), 2, SL("container"));
		ZEPHIR_INIT_NVAR(_17$$3);
		zephir_create_array(_17$$3, 2, 0 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(_1$$3);
		object_init_ex(_1$$3, brisk_kernel_session_ce);
		if (zephir_has_constructor(_1$$3 TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, _1$$3, "__construct", NULL, 0);
			zephir_check_call_status();
		}
		zephir_array_update_string(&_17$$3, SL("instance"), &_1$$3, PH_COPY | PH_SEPARATE);
		add_assoc_long_ex(_17$$3, SS("system"), 1);
		zephir_update_static_property_array_multi_ce(brisk_kernel_app_ce, SL("_storage"), &_17$$3 TSRMLS_CC, SL("s"), 2, SL("session"));
	}
	_18 = zephir_fetch_static_property_ce(brisk_kernel_app_ce, SL("_instance") TSRMLS_CC);
	RETURN_CTOR(_18);

}

/**
 * Set directory path aliases
 *
 * @param string alias
 * @param string path
 * @return App
 */
PHP_METHOD(Brisk_Kernel_App, setAlias) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *alias_param = NULL, *path_param = NULL;
	zval *alias = NULL, *path = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &alias_param, &path_param);

	if (UNEXPECTED(Z_TYPE_P(alias_param) != IS_STRING && Z_TYPE_P(alias_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'alias' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(alias_param) == IS_STRING)) {
		zephir_get_strval(alias, alias_param);
	} else {
		ZEPHIR_INIT_VAR(alias);
		ZVAL_EMPTY_STRING(alias);
	}
	if (UNEXPECTED(Z_TYPE_P(path_param) != IS_STRING && Z_TYPE_P(path_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'path' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(path_param) == IS_STRING)) {
		zephir_get_strval(path, path_param);
	} else {
		ZEPHIR_INIT_VAR(path);
		ZVAL_EMPTY_STRING(path);
	}


	ZEPHIR_CALL_CE_STATIC(NULL, brisk_kernel_loader_ce, "setalias", &_0, 17, alias, path);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Set namespace path
 *
 * @param string nspace
 * @param string path
 * @return App
 */
PHP_METHOD(Brisk_Kernel_App, setNameSpace) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *nspace_param = NULL, *path_param = NULL;
	zval *nspace = NULL, *path = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &nspace_param, &path_param);

	if (UNEXPECTED(Z_TYPE_P(nspace_param) != IS_STRING && Z_TYPE_P(nspace_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'nspace' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(nspace_param) == IS_STRING)) {
		zephir_get_strval(nspace, nspace_param);
	} else {
		ZEPHIR_INIT_VAR(nspace);
		ZVAL_EMPTY_STRING(nspace);
	}
	if (UNEXPECTED(Z_TYPE_P(path_param) != IS_STRING && Z_TYPE_P(path_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'path' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(path_param) == IS_STRING)) {
		zephir_get_strval(path, path_param);
	} else {
		ZEPHIR_INIT_VAR(path);
		ZVAL_EMPTY_STRING(path);
	}


	ZEPHIR_CALL_CE_STATIC(NULL, brisk_kernel_loader_ce, "setnamespace", &_0, 23, nspace, path);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Set the system language pack file
 *
 * @param string language
 * @param string path
 * @return App
 */
PHP_METHOD(Brisk_Kernel_App, addLanguageFile) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *language_param = NULL, *path_param = NULL;
	zval *language = NULL, *path = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &language_param, &path_param);

	if (UNEXPECTED(Z_TYPE_P(language_param) != IS_STRING && Z_TYPE_P(language_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'language' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(language_param) == IS_STRING)) {
		zephir_get_strval(language, language_param);
	} else {
		ZEPHIR_INIT_VAR(language);
		ZVAL_EMPTY_STRING(language);
	}
	if (UNEXPECTED(Z_TYPE_P(path_param) != IS_STRING && Z_TYPE_P(path_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'path' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(path_param) == IS_STRING)) {
		zephir_get_strval(path, path_param);
	} else {
		ZEPHIR_INIT_VAR(path);
		ZVAL_EMPTY_STRING(path);
	}


	ZEPHIR_CALL_CE_STATIC(NULL, brisk_kernel_language_ce, "addpackagefile", &_0, 24, language, path);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Setting the system language
 *
 * @param string language
 * @return App
 */
PHP_METHOD(Brisk_Kernel_App, setLanguage) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *language_param = NULL;
	zval *language = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &language_param);

	if (UNEXPECTED(Z_TYPE_P(language_param) != IS_STRING && Z_TYPE_P(language_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'language' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(language_param) == IS_STRING)) {
		zephir_get_strval(language, language_param);
	} else {
		ZEPHIR_INIT_VAR(language);
		ZVAL_EMPTY_STRING(language);
	}


	ZEPHIR_CALL_CE_STATIC(NULL, brisk_kernel_language_ce, "setlanguage", &_0, 25, language);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Adding event listener
 *
 * @param string event
 * @param callable listener
 * @return App
 */
PHP_METHOD(Brisk_Kernel_App, addEvent) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *event_param = NULL, *listener;
	zval *event = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &event_param, &listener);

	if (UNEXPECTED(Z_TYPE_P(event_param) != IS_STRING && Z_TYPE_P(event_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'event' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(event_param) == IS_STRING)) {
		zephir_get_strval(event, event_param);
	} else {
		ZEPHIR_INIT_VAR(event);
		ZVAL_EMPTY_STRING(event);
	}
	if (UNEXPECTED(zephir_is_callable(listener TSRMLS_CC) != 1)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'listener' must be a callable") TSRMLS_CC);
		RETURN_MM_NULL();
	}


	ZEPHIR_CALL_CE_STATIC(NULL, brisk_kernel_event_ce, "add", &_0, 26, event, listener);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Start the application
 *
 * @return null
 */
PHP_METHOD(Brisk_Kernel_App, start) {

	zval *_31, *_37$$8;
	zend_bool _1, _16;
	zval *_0, *_2, *config = NULL, *_7, *_8, *_12 = NULL, *instance = NULL, *_13, *_14, *_15 = NULL, *_17 = NULL, *timezone = NULL, *_22 = NULL, *_25 = NULL, *_32 = NULL, *_35, *_36, *_41, *_42, *_43, *_44, *_3$$3, *_4$$3 = NULL, *_6$$3, *_9$$4, *_10$$4 = NULL, *_11$$4, *_19$$5, *_20$$5, *_21$$5 = NULL, *_23$$6, *_24$$6, _26$$7, _27$$7, *_28$$7, *_29$$7, *_30$$7 = NULL, *lang$$8 = NULL, *_38$$8 = NULL, *_39$$8, *_40$$8;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_5 = NULL, *_18 = NULL, *_33 = NULL, *_34 = NULL;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_config"), PH_NOISY_CC);
	_1 = Z_TYPE_P(_0) == IS_NULL;
	if (!(_1)) {
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("_config"), PH_NOISY_CC);
		_1 = !(zephir_is_callable(_2 TSRMLS_CC));
	}
	if (_1) {
		ZEPHIR_INIT_VAR(_3$$3);
		object_init_ex(_3$$3, brisk_exception_configurationexception_ce);
		ZEPHIR_INIT_VAR(_6$$3);
		ZVAL_STRING(_6$$3, "core.invalid_configuration", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_CE_STATIC(&_4$$3, brisk_kernel_language_ce, "get", &_5, 27, _6$$3);
		zephir_check_temp_parameter(_6$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, _3$$3, "__construct", NULL, 28, _4$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(_3$$3, "brisk/Kernel/App.zep", 165 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	_7 = zephir_fetch_nproperty_this(this_ptr, SL("_config"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_8);
	array_init(_8);
	ZEPHIR_INIT_VAR(config);
	ZEPHIR_CALL_USER_FUNC_ARRAY(config, _7, _8);
	zephir_check_call_status();
	if (!(Z_TYPE_P(config) == IS_ARRAY)) {
		ZEPHIR_INIT_VAR(_9$$4);
		object_init_ex(_9$$4, brisk_exception_configurationexception_ce);
		ZEPHIR_INIT_VAR(_11$$4);
		ZVAL_STRING(_11$$4, "core.invalid_configuration", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_CE_STATIC(&_10$$4, brisk_kernel_language_ce, "get", &_5, 27, _11$$4);
		zephir_check_temp_parameter(_11$$4);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, _9$$4, "__construct", NULL, 28, _10$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(_9$$4, "brisk/Kernel/App.zep", 170 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(_12);
	object_init_ex(_12, brisk_kernel_container_ce);
	ZEPHIR_CALL_METHOD(NULL, _12, "__construct", NULL, 13, config);
	zephir_check_call_status();
	zephir_update_static_property_array_multi_ce(brisk_kernel_app_ce, SL("_storage"), &_12 TSRMLS_CC, SL("ss"), 4, SL("config"), SL("instance"));
	_13 = zephir_fetch_static_property_ce(brisk_kernel_app_ce, SL("_storage") TSRMLS_CC);
	zephir_array_fetch_string(&_14, _13, SL("config"), PH_NOISY | PH_READONLY, "brisk/Kernel/App.zep", 173 TSRMLS_CC);
	ZEPHIR_OBS_VAR(instance);
	zephir_array_fetch_string(&instance, _14, SL("instance"), PH_NOISY, "brisk/Kernel/App.zep", 173 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(_12);
	ZVAL_STRING(_12, "global/header", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_15, instance, "haskey", NULL, 0, _12);
	zephir_check_temp_parameter(_12);
	zephir_check_call_status();
	_16 = zephir_is_true(_15);
	if (_16) {
		ZEPHIR_CALL_CE_STATIC(&_17, brisk_kernel_server_ce, "iscli", &_18, 20);
		zephir_check_call_status();
		_16 = !zephir_is_true(_17);
	}
	if (_16) {
		ZEPHIR_OBS_VAR(_19$$5);
		zephir_read_property(&_19$$5, instance, SL("global"), PH_NOISY_CC);
		ZEPHIR_OBS_VAR(_20$$5);
		zephir_read_property(&_20$$5, _19$$5, SL("header"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_21$$5, _20$$5, "getvalue", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(NULL, "header", NULL, 22, _21$$5);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(timezone);
	ZVAL_STRING(timezone, "Asia/Shanghai", 1);
	ZEPHIR_INIT_NVAR(_12);
	ZVAL_STRING(_12, "global/timezone", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_22, instance, "haskey", NULL, 0, _12);
	zephir_check_temp_parameter(_12);
	zephir_check_call_status();
	if (zephir_is_true(_22)) {
		ZEPHIR_OBS_VAR(_23$$6);
		zephir_read_property(&_23$$6, instance, SL("global"), PH_NOISY_CC);
		ZEPHIR_OBS_VAR(_24$$6);
		zephir_read_property(&_24$$6, _23$$6, SL("timezone"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&timezone, _24$$6, "getvalue", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_FUNCTION(NULL, "date_default_timezone_set", NULL, 29, timezone);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_12);
	ZVAL_STRING(_12, "global/error_reporting", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_25, instance, "haskey", NULL, 0, _12);
	zephir_check_temp_parameter(_12);
	zephir_check_call_status();
	if (zephir_is_true(_25)) {
		ZEPHIR_SINIT_VAR(_26$$7);
		ZVAL_STRING(&_26$$7, "display_errors", 0);
		ZEPHIR_SINIT_VAR(_27$$7);
		ZVAL_STRING(&_27$$7, "1", 0);
		ZEPHIR_CALL_FUNCTION(NULL, "ini_set", NULL, 10, &_26$$7, &_27$$7);
		zephir_check_call_status();
		ZEPHIR_OBS_VAR(_28$$7);
		zephir_read_property(&_28$$7, instance, SL("global"), PH_NOISY_CC);
		ZEPHIR_OBS_VAR(_29$$7);
		zephir_read_property(&_29$$7, _28$$7, SL("error_reporting"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_30$$7, _29$$7, "getvalue", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(NULL, "error_reporting", NULL, 30, _30$$7);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(_31);
	zephir_create_array(_31, 2, 0 TSRMLS_CC);
	ZEPHIR_CALL_CE_STATIC(&_32, brisk_kernel_router_routeradapter_ce, "getdriver", &_33, 31);
	zephir_check_call_status();
	zephir_array_update_string(&_31, SL("instance"), &_32, PH_COPY | PH_SEPARATE);
	add_assoc_long_ex(_31, SS("system"), 1);
	zephir_update_static_property_array_multi_ce(brisk_kernel_app_ce, SL("_storage"), &_31 TSRMLS_CC, SL("s"), 2, SL("router"));
	ZEPHIR_INIT_NVAR(_12);
	ZVAL_STRING(_12, "event.framework.ready", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_CE_STATIC(NULL, brisk_kernel_event_ce, "fire", &_34, 32, _12);
	zephir_check_temp_parameter(_12);
	zephir_check_call_status();
	_35 = zephir_fetch_static_property_ce(brisk_kernel_app_ce, SL("_instance") TSRMLS_CC);
	ZEPHIR_OBS_VAR(_36);
	zephir_read_property(&_36, _35, SL("router"), PH_NOISY_CC);
	if (!(zephir_instance_of_ev(_36, brisk_kernel_router_routerfather_ce TSRMLS_CC))) {
		ZEPHIR_INIT_VAR(_37$$8);
		zephir_create_array(_37$$8, 2, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_38$$8);
		_39$$8 = zephir_fetch_static_property_ce(brisk_kernel_app_ce, SL("_instance") TSRMLS_CC);
		ZEPHIR_OBS_VAR(_40$$8);
		zephir_read_property(&_40$$8, _39$$8, SL("router"), PH_NOISY_CC);
		zephir_get_class(_38$$8, _40$$8, 0 TSRMLS_CC);
		zephir_array_fast_append(_37$$8, _38$$8);
		ZEPHIR_INIT_NVAR(_38$$8);
		ZVAL_STRING(_38$$8, "\\Brisk\\Kernel\\Router\\RouterFather", 1);
		zephir_array_fast_append(_37$$8, _38$$8);
		ZEPHIR_INIT_NVAR(_38$$8);
		ZVAL_STRING(_38$$8, "router.driver_implement_error", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_CE_STATIC(&lang$$8, brisk_kernel_language_ce, "get", &_5, 27, _38$$8, _37$$8);
		zephir_check_temp_parameter(_38$$8);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_38$$8);
		object_init_ex(_38$$8, brisk_exception_routerexception_ce);
		ZEPHIR_CALL_METHOD(NULL, _38$$8, "__construct", NULL, 28, lang$$8);
		zephir_check_call_status();
		zephir_throw_exception_debug(_38$$8, "brisk/Kernel/App.zep", 197 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	_41 = zephir_fetch_static_property_ce(brisk_kernel_app_ce, SL("_instance") TSRMLS_CC);
	ZEPHIR_OBS_VAR(_42);
	zephir_read_property(&_42, _41, SL("router"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _42, "ready", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_12);
	ZVAL_STRING(_12, "event.router.ready", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_CE_STATIC(NULL, brisk_kernel_event_ce, "fire", &_34, 32, _12);
	zephir_check_temp_parameter(_12);
	zephir_check_call_status();
	_43 = zephir_fetch_static_property_ce(brisk_kernel_app_ce, SL("_instance") TSRMLS_CC);
	ZEPHIR_OBS_VAR(_44);
	zephir_read_property(&_44, _43, SL("router"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _44, "dispatch", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Set up custom singleton components
 *
 * @param string name
 * @param callable value
 * @return App
 */
PHP_METHOD(Brisk_Kernel_App, setComponent) {

	zval *_5$$3;
	zend_bool _1;
	zval *name_param = NULL, *value, *_0, *_2, *_3, *_4;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name_param, &value);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(name, name_param);
	} else {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	}
	if (UNEXPECTED(zephir_is_callable(value TSRMLS_CC) != 1)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'value' must be a callable") TSRMLS_CC);
		RETURN_MM_NULL();
	}


	_0 = zephir_fetch_static_property_ce(brisk_kernel_app_ce, SL("_storage") TSRMLS_CC);
	_1 = !(zephir_array_isset(_0, name));
	if (!(_1)) {
		_2 = zephir_fetch_static_property_ce(brisk_kernel_app_ce, SL("_storage") TSRMLS_CC);
		zephir_array_fetch(&_3, _2, name, PH_NOISY | PH_READONLY, "brisk/Kernel/App.zep", 217 TSRMLS_CC);
		zephir_array_fetch_string(&_4, _3, SL("system"), PH_NOISY | PH_READONLY, "brisk/Kernel/App.zep", 217 TSRMLS_CC);
		_1 = !zephir_is_true(_4);
	}
	if (_1) {
		ZEPHIR_INIT_VAR(_5$$3);
		zephir_create_array(_5$$3, 2, 0 TSRMLS_CC);
		zephir_array_update_string(&_5$$3, SL("instance"), &value, PH_COPY | PH_SEPARATE);
		add_assoc_long_ex(_5$$3, SS("system"), 0);
		zephir_update_static_property_array_multi_ce(brisk_kernel_app_ce, SL("_storage"), &_5$$3 TSRMLS_CC, SL("z"), 1, name);
	}
	RETURN_THIS();

}

/**
 * get custom singleton components
 *
 * @param string name
 * @return mixed
 */
PHP_METHOD(Brisk_Kernel_App, getComponent) {

	zval *_5$$3, *_11$$5;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_4 = NULL;
	zval *name_param = NULL, *instance = NULL, *_0, *_1, *_2$$3, *_3$$3 = NULL, *_6$$3, *_7$$4, *_8$$4, *_9$$5, *_10$$5 = NULL, *_12$$5;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(name, name_param);
	} else {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	}


	_0 = zephir_fetch_static_property_ce(brisk_kernel_app_ce, SL("_storage") TSRMLS_CC);
	zephir_array_fetch(&_1, _0, name, PH_NOISY | PH_READONLY, "brisk/Kernel/App.zep", 232 TSRMLS_CC);
	ZEPHIR_OBS_VAR(instance);
	zephir_array_fetch_string(&instance, _1, SL("instance"), PH_NOISY, "brisk/Kernel/App.zep", 232 TSRMLS_CC);
	if (Z_TYPE_P(instance) == IS_NULL) {
		ZEPHIR_INIT_VAR(_2$$3);
		object_init_ex(_2$$3, brisk_exception_runtimeexception_ce);
		ZEPHIR_INIT_VAR(_5$$3);
		zephir_create_array(_5$$3, 1, 0 TSRMLS_CC);
		zephir_array_fast_append(_5$$3, name);
		ZEPHIR_INIT_VAR(_6$$3);
		ZVAL_STRING(_6$$3, "core.object_not_found", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_CE_STATIC(&_3$$3, brisk_kernel_language_ce, "get", &_4, 27, _6$$3, _5$$3);
		zephir_check_temp_parameter(_6$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, _2$$3, "__construct", NULL, 28, _3$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(_2$$3, "brisk/Kernel/App.zep", 234 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	} else if (zephir_is_callable(instance TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(_7$$4);
		ZEPHIR_INIT_VAR(_8$$4);
		array_init(_8$$4);
		ZEPHIR_CALL_USER_FUNC_ARRAY(_7$$4, instance, _8$$4);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(instance, _7$$4);
		if (!zephir_is_true(instance)) {
			ZEPHIR_INIT_VAR(_9$$5);
			object_init_ex(_9$$5, brisk_exception_runtimeexception_ce);
			ZEPHIR_INIT_VAR(_11$$5);
			zephir_create_array(_11$$5, 1, 0 TSRMLS_CC);
			zephir_array_fast_append(_11$$5, name);
			ZEPHIR_INIT_VAR(_12$$5);
			ZVAL_STRING(_12$$5, "core.invlid_custom_member", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_CE_STATIC(&_10$$5, brisk_kernel_language_ce, "get", &_4, 27, _12$$5, _11$$5);
			zephir_check_temp_parameter(_12$$5);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, _9$$5, "__construct", NULL, 28, _10$$5);
			zephir_check_call_status();
			zephir_throw_exception_debug(_9$$5, "brisk/Kernel/App.zep", 238 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_update_static_property_array_multi_ce(brisk_kernel_app_ce, SL("_storage"), &instance TSRMLS_CC, SL("zs"), 3, name, SL("instance"));
	}
	RETURN_CCTOR(instance);

}

/**
 * Get custom singleton components
 *
 * @param string name
 * @return mixed
 */
PHP_METHOD(Brisk_Kernel_App, __get) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(name, name_param);
	} else {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	}


	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getcomponent", NULL, 0, name);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Set up custom method
 *
 * @param string name
 * @param callable method
 * @return App
 */
PHP_METHOD(Brisk_Kernel_App, setMethod) {

	zval *_3$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_2 = NULL;
	zval *name_param = NULL, *method, *_0$$3, *_1$$3 = NULL, *_4$$3;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name_param, &method);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(name, name_param);
	} else {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	}
	if (UNEXPECTED(zephir_is_callable(method TSRMLS_CC) != 1)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'method' must be a callable") TSRMLS_CC);
		RETURN_MM_NULL();
	}


	if (!(zephir_is_callable(method TSRMLS_CC))) {
		ZEPHIR_INIT_VAR(_0$$3);
		object_init_ex(_0$$3, brisk_exception_runtimeexception_ce);
		ZEPHIR_INIT_VAR(_3$$3);
		zephir_create_array(_3$$3, 1, 0 TSRMLS_CC);
		zephir_array_fast_append(_3$$3, name);
		ZEPHIR_INIT_VAR(_4$$3);
		ZVAL_STRING(_4$$3, "core.invalid_custom_method", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_CE_STATIC(&_1$$3, brisk_kernel_language_ce, "get", &_2, 27, _4$$3, _3$$3);
		zephir_check_temp_parameter(_4$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, _0$$3, "__construct", NULL, 28, _1$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(_0$$3, "brisk/Kernel/App.zep", 266 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_static_property_array_multi_ce(brisk_kernel_app_ce, SL("_methods"), &method TSRMLS_CC, SL("z"), 1, name);
	RETURN_THIS();

}

/**
 * Get custom method
 *
 * @param string name
 * @param array args
 * @return mixed
 */
PHP_METHOD(Brisk_Kernel_App, callMethod) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_3 = NULL;
	zval *args = NULL, *_4$$3;
	zval *name_param = NULL, *args_param = NULL, *_0, *method = NULL, *_6, *_1$$3, *_2$$3 = NULL, *_5$$3;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name_param, &args_param);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(name, name_param);
	} else {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	}
	args = args_param;


	_0 = zephir_fetch_static_property_ce(brisk_kernel_app_ce, SL("_methods") TSRMLS_CC);
	if (!(zephir_array_isset(_0, name))) {
		ZEPHIR_INIT_VAR(_1$$3);
		object_init_ex(_1$$3, brisk_exception_methodnotfoundexception_ce);
		ZEPHIR_INIT_VAR(_4$$3);
		zephir_create_array(_4$$3, 1, 0 TSRMLS_CC);
		zephir_array_fast_append(_4$$3, name);
		ZEPHIR_INIT_VAR(_5$$3);
		ZVAL_STRING(_5$$3, "core.custom_method_notfound", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_CE_STATIC(&_2$$3, brisk_kernel_language_ce, "get", &_3, 27, _5$$3, _4$$3);
		zephir_check_temp_parameter(_5$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, _1$$3, "__construct", NULL, 28, _2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(_1$$3, "brisk/Kernel/App.zep", 282 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	_6 = zephir_fetch_static_property_ce(brisk_kernel_app_ce, SL("_methods") TSRMLS_CC);
	ZEPHIR_OBS_VAR(method);
	zephir_array_fetch(&method, _6, name, PH_NOISY, "brisk/Kernel/App.zep", 284 TSRMLS_CC);
	ZEPHIR_CALL_USER_FUNC_ARRAY(return_value, method, args);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Get custom method
 *
 * @param string name
 * @param array args
 * @return mixed
 */
PHP_METHOD(Brisk_Kernel_App, __call) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *args = NULL;
	zval *name_param = NULL, *args_param = NULL;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name_param, &args_param);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(name, name_param);
	} else {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	}
	args = args_param;


	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "callmethod", NULL, 0, name, args);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * destruct
 *
 * @return null
 */
PHP_METHOD(Brisk_Kernel_App, __destruct) {

	zval *_1 = NULL, *_3 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL, *_2 = NULL, *_4 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "sys_shutdown", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_CE_STATIC(NULL, brisk_kernel_timer_ce, "mark", &_0, 11, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_3, "memory_get_usage", NULL, 8);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "memory", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_CE_STATIC(NULL, brisk_kernel_trace_ce, "set", &_2, 12, _1, _3);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "event.framework.shutdown", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_CE_STATIC(NULL, brisk_kernel_event_ce, "fire", &_4, 32, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

void zephir_init_static_properties_Brisk_Kernel_App(TSRMLS_D) {

	zval *_0, *_1;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_update_static_property_ce(brisk_kernel_app_ce, SL("_methods"), &_0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	array_init(_1);
	zephir_update_static_property_ce(brisk_kernel_app_ce, SL("_storage"), &_1 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}


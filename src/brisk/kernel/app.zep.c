
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
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"


ZEPHIR_INIT_CLASS(Brisk_Kernel_App) {

	ZEPHIR_REGISTER_CLASS(Brisk\\Kernel, App, brisk, kernel_app, brisk_kernel_app_method_entry, 0);

	zend_declare_property_null(brisk_kernel_app_ce, SL("_name"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(brisk_kernel_app_ce, SL("_base_dir"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(brisk_kernel_app_ce, SL("_config"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(brisk_kernel_app_ce, SL("_controller_dir"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(brisk_kernel_app_ce, SL("_instance"), ZEND_ACC_PRIVATE|ZEND_ACC_STATIC TSRMLS_CC);

	zend_declare_property_null(brisk_kernel_app_ce, SL("_storage"), ZEND_ACC_PRIVATE|ZEND_ACC_STATIC TSRMLS_CC);

	zend_declare_property_null(brisk_kernel_app_ce, SL("_methods"), ZEND_ACC_PRIVATE|ZEND_ACC_STATIC TSRMLS_CC);

	zephir_declare_class_constant_string(brisk_kernel_app_ce, SL("NAME"), "Brisk");

	zephir_declare_class_constant_string(brisk_kernel_app_ce, SL("AUTHOR"), "guodalu <112183883@qq.com>");

	zephir_declare_class_constant_string(brisk_kernel_app_ce, SL("VERSION"), "1.0.3");

	return SUCCESS;

}

PHP_METHOD(Brisk_Kernel_App, setApp) {

	zval *name_param = NULL, *base_dir_param = NULL;
	zval name, base_dir;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&base_dir);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &name_param, &base_dir_param);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_EMPTY_STRING(&name);
	}
	if (!base_dir_param) {
		ZEPHIR_INIT_VAR(&base_dir);
		ZVAL_STRING(&base_dir, "");
	} else {
	if (UNEXPECTED(Z_TYPE_P(base_dir_param) != IS_STRING && Z_TYPE_P(base_dir_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'base_dir' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(base_dir_param) == IS_STRING)) {
		zephir_get_strval(&base_dir, base_dir_param);
	} else {
		ZEPHIR_INIT_VAR(&base_dir);
		ZVAL_EMPTY_STRING(&base_dir);
	}
	}


	zephir_update_property_zval(this_ptr, SL("_name"), &name);
	zephir_update_property_zval(this_ptr, SL("_base_dir"), &base_dir);
	RETURN_THIS();

}

PHP_METHOD(Brisk_Kernel_App, setConfig) {

	zval *config, config_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&config_sub);

	zephir_fetch_params(0, 1, 0, &config);

	if (UNEXPECTED(zephir_is_callable(config TSRMLS_CC) != 1)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'config' must be a callable") TSRMLS_CC);
		RETURN_NULL();
	}


	zephir_update_property_zval(this_ptr, SL("_config"), config);
	RETURN_THISW();

}

PHP_METHOD(Brisk_Kernel_App, setControllerDir) {

	zval *path_param = NULL;
	zval path;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&path);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &path_param);

	if (UNEXPECTED(Z_TYPE_P(path_param) != IS_STRING && Z_TYPE_P(path_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'path' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(path_param) == IS_STRING)) {
		zephir_get_strval(&path, path_param);
	} else {
		ZEPHIR_INIT_VAR(&path);
		ZVAL_EMPTY_STRING(&path);
	}


	zephir_update_property_zval(this_ptr, SL("_controller_dir"), &path);
	RETURN_THIS();

}

PHP_METHOD(Brisk_Kernel_App, getApp) {

	zend_bool _1;
	zval *item_param = NULL, info, _0, _2$$3;
	zval item;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&item);
	ZVAL_UNDEF(&info);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &item_param);

	if (!item_param) {
		ZEPHIR_INIT_VAR(&item);
		ZVAL_STRING(&item, "");
	} else {
	if (UNEXPECTED(Z_TYPE_P(item_param) != IS_STRING && Z_TYPE_P(item_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'item' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(item_param) == IS_STRING)) {
		zephir_get_strval(&item, item_param);
	} else {
		ZEPHIR_INIT_VAR(&item);
		ZVAL_EMPTY_STRING(&item);
	}
	}


	ZEPHIR_INIT_VAR(&info);
	zephir_create_array(&info, 2, 0 TSRMLS_CC);
	ZEPHIR_OBS_VAR(&_0);
	zephir_read_property(&_0, this_ptr, SL("_name"), PH_NOISY_CC);
	zephir_array_update_string(&info, SL("name"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_0);
	zephir_read_property(&_0, this_ptr, SL("_base_dir"), PH_NOISY_CC);
	zephir_array_update_string(&info, SL("base_dir"), &_0, PH_COPY | PH_SEPARATE);
	_1 = !ZEPHIR_IS_STRING(&item, "");
	if (_1) {
		_1 = zephir_array_isset(&info, &item);
	}
	if (_1) {
		zephir_array_fetch(&_2$$3, &info, &item, PH_NOISY | PH_READONLY, "brisk/Kernel/App.zep", 45 TSRMLS_CC);
		RETURN_CTOR(&_2$$3);
	}
	RETURN_CCTOR(&info);

}

PHP_METHOD(Brisk_Kernel_App, getControllerDir) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_controller_dir");

}

PHP_METHOD(Brisk_Kernel_App, __construct) {

	zval *this_ptr = getThis();



}

PHP_METHOD(Brisk_Kernel_App, getInstance) {

	zval _5$$3, _17$$3;
	zval _0, _18, memory_usage$$3, _1$$3, _2$$3, debug_trace$$3, _8$$3, _9$$3, _10$$3, _13$$3, _14$$3;
	zephir_fcall_cache_entry *_3 = NULL, *_4 = NULL, *_6 = NULL, *_7 = NULL, *_11 = NULL, *_12 = NULL, *_15 = NULL, *_16 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_18);
	ZVAL_UNDEF(&memory_usage$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&debug_trace$$3);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_10$$3);
	ZVAL_UNDEF(&_13$$3);
	ZVAL_UNDEF(&_14$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_17$$3);

	ZEPHIR_MM_GROW();

	zephir_read_static_property_ce(&_0, brisk_kernel_app_ce, SL("_instance"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_0) == IS_NULL) {
		ZEPHIR_CALL_FUNCTION(&memory_usage$$3, "memory_get_usage", NULL, 21);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, brisk_kernel_app_ce);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 22);
		zephir_check_call_status();
		zend_update_static_property(brisk_kernel_app_ce, ZEND_STRL("_instance"), &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "display_errors");
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "1");
		ZEPHIR_CALL_FUNCTION(NULL, "ini_set", NULL, 23, &_1$$3, &_2$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "sys_startup");
		ZEPHIR_CALL_CE_STATIC(NULL, brisk_kernel_timer_ce, "mark", &_3, 0, &_1$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "memory");
		ZEPHIR_CALL_CE_STATIC(NULL, brisk_kernel_trace_ce, "set", &_4, 0, &_1$$3, &memory_usage$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "Content-type: text/html; charset=utf-8");
		ZEPHIR_CALL_FUNCTION(NULL, "header", NULL, 24, &_1$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_5$$3);
		zephir_create_array(&_5$$3, 2, 0 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(&_1$$3);
		object_init_ex(&_1$$3, brisk_kernel_container_ce);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", &_6, 25);
		zephir_check_call_status();
		zephir_array_update_string(&_5$$3, SL("instance"), &_1$$3, PH_COPY | PH_SEPARATE);
		add_assoc_long_ex(&_5$$3, SL("system"), 1);
		zephir_update_static_property_array_multi_ce(brisk_kernel_app_ce, SL("_storage"), &_5$$3 TSRMLS_CC, SL("s"), 2, SL("config"));
		ZEPHIR_CALL_FUNCTION(&debug_trace$$3, "debug_backtrace", NULL, 26);
		zephir_check_call_status();
		zephir_array_fetch_long(&_8$$3, &debug_trace$$3, 0, PH_NOISY | PH_READONLY, "brisk/Kernel/App.zep", 79 TSRMLS_CC);
		zephir_array_fetch_string(&_9$$3, &_8$$3, SL("file"), PH_NOISY | PH_READONLY, "brisk/Kernel/App.zep", 79 TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&_10$$3, "dirname", NULL, 18, &_9$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, ".");
		ZEPHIR_CALL_CE_STATIC(NULL, brisk_kernel_loader_ce, "setalias", &_7, 0, &_1$$3, &_10$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "exception");
		ZEPHIR_CALL_CE_STATIC(NULL, brisk_kernel_handler_ce, "sethandler", &_11, 0, &_1$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_5$$3);
		zephir_create_array(&_5$$3, 2, 0 TSRMLS_CC);
		ZEPHIR_OBS_VAR(&_13$$3);
		zephir_read_static_property_ce(&_13$$3, brisk_kernel_app_ce, SL("_instance"), PH_NOISY_CC);
		zephir_array_fast_append(&_5$$3, &_13$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "setAutoLoad");
		zephir_array_fast_append(&_5$$3, &_1$$3);
		ZEPHIR_CALL_CE_STATIC(NULL, brisk_kernel_loader_ce, "addautoloader", &_12, 0, &_5$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_CE_STATIC(&_14$$3, brisk_kernel_server_ce, "iscli", &_15, 0);
		zephir_check_call_status();
		if (zephir_is_true(&_14$$3)) {
			ZEPHIR_CALL_CE_STATIC(NULL, brisk_kernel_server_ce, "initcli", &_16, 0);
			zephir_check_call_status();
		}
		ZEPHIR_INIT_VAR(&_17$$3);
		zephir_create_array(&_17$$3, 2, 0 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(&_1$$3);
		object_init_ex(&_1$$3, brisk_kernel_container_ce);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", &_6, 25);
		zephir_check_call_status();
		zephir_array_update_string(&_17$$3, SL("instance"), &_1$$3, PH_COPY | PH_SEPARATE);
		add_assoc_long_ex(&_17$$3, SL("system"), 1);
		zephir_update_static_property_array_multi_ce(brisk_kernel_app_ce, SL("_storage"), &_17$$3 TSRMLS_CC, SL("s"), 2, SL("container"));
		ZEPHIR_INIT_NVAR(&_17$$3);
		zephir_create_array(&_17$$3, 2, 0 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(&_1$$3);
		object_init_ex(&_1$$3, brisk_kernel_response_ce);
		if (zephir_has_constructor(&_1$$3 TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 0);
			zephir_check_call_status();
		}
		zephir_array_update_string(&_17$$3, SL("instance"), &_1$$3, PH_COPY | PH_SEPARATE);
		add_assoc_long_ex(&_17$$3, SL("system"), 1);
		zephir_update_static_property_array_multi_ce(brisk_kernel_app_ce, SL("_storage"), &_17$$3 TSRMLS_CC, SL("s"), 2, SL("response"));
	}
	zephir_read_static_property_ce(&_18, brisk_kernel_app_ce, SL("_instance"), PH_NOISY_CC | PH_READONLY);
	RETURN_CTOR(&_18);

}

PHP_METHOD(Brisk_Kernel_App, setAutoLoad) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *classname_param = NULL;
	zval classname;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&classname);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &classname_param);

	if (UNEXPECTED(Z_TYPE_P(classname_param) != IS_STRING && Z_TYPE_P(classname_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'classname' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(classname_param) == IS_STRING)) {
		zephir_get_strval(&classname, classname_param);
	} else {
		ZEPHIR_INIT_VAR(&classname);
		ZVAL_EMPTY_STRING(&classname);
	}


	ZEPHIR_CALL_CE_STATIC(NULL, brisk_kernel_loader_ce, "autoload", &_0, 0, &classname);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Brisk_Kernel_App, addLanguagePackage) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *language_param = NULL, *path_param = NULL;
	zval language, path;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&language);
	ZVAL_UNDEF(&path);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &language_param, &path_param);

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
	if (UNEXPECTED(Z_TYPE_P(path_param) != IS_STRING && Z_TYPE_P(path_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'path' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(path_param) == IS_STRING)) {
		zephir_get_strval(&path, path_param);
	} else {
		ZEPHIR_INIT_VAR(&path);
		ZVAL_EMPTY_STRING(&path);
	}


	ZEPHIR_CALL_CE_STATIC(NULL, brisk_kernel_language_ce, "addpackage", &_0, 0, &language, &path);
	zephir_check_call_status();
	RETURN_THIS();

}

PHP_METHOD(Brisk_Kernel_App, setLanguage) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
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


	ZEPHIR_CALL_CE_STATIC(NULL, brisk_kernel_language_ce, "setlanguage", &_0, 0, &language);
	zephir_check_call_status();
	RETURN_THIS();

}

PHP_METHOD(Brisk_Kernel_App, addEventListener) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *event_param = NULL, *listener, listener_sub;
	zval event;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&event);
	ZVAL_UNDEF(&listener_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &event_param, &listener);

	if (UNEXPECTED(Z_TYPE_P(event_param) != IS_STRING && Z_TYPE_P(event_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'event' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(event_param) == IS_STRING)) {
		zephir_get_strval(&event, event_param);
	} else {
		ZEPHIR_INIT_VAR(&event);
		ZVAL_EMPTY_STRING(&event);
	}
	if (UNEXPECTED(zephir_is_callable(listener TSRMLS_CC) != 1)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'listener' must be a callable") TSRMLS_CC);
		RETURN_MM_NULL();
	}


	ZEPHIR_CALL_CE_STATIC(NULL, brisk_kernel_event_ce, "addlistener", &_0, 0, &event, listener);
	zephir_check_call_status();
	RETURN_THIS();

}

PHP_METHOD(Brisk_Kernel_App, start) {

	zval _55, _61$$13;
	zend_bool _16;
	zval _0, _5, _9, _10, _15, _17, _21, _24, _25, _30, _31, _33, _34, config, _35, _39, instance, _40, _41, _42, timezone, _46, _49, _56, _59, _60, _65, _66, _67, _68, _1$$3, _2$$3, _4$$3, _6$$4, _8$$4, _12$$5, _13$$5, _14$$5, _18$$6, _19$$6, _20$$6, _22$$7, _23$$7, _26$$8, _27$$8, _28$$8, _36$$9, _37$$9, _38$$9, _43$$10, _44$$10, _45$$10, _47$$11, _48$$11, _50$$12, _51$$12, _52$$12, _53$$12, _54$$12, lang$$13, _62$$13, _63$$13, _64$$13;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_3 = NULL, *_7 = NULL, *_11 = NULL, *_29 = NULL, *_32 = NULL, *_57 = NULL, *_58 = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_17);
	ZVAL_UNDEF(&_21);
	ZVAL_UNDEF(&_24);
	ZVAL_UNDEF(&_25);
	ZVAL_UNDEF(&_30);
	ZVAL_UNDEF(&_31);
	ZVAL_UNDEF(&_33);
	ZVAL_UNDEF(&_34);
	ZVAL_UNDEF(&config);
	ZVAL_UNDEF(&_35);
	ZVAL_UNDEF(&_39);
	ZVAL_UNDEF(&instance);
	ZVAL_UNDEF(&_40);
	ZVAL_UNDEF(&_41);
	ZVAL_UNDEF(&_42);
	ZVAL_UNDEF(&timezone);
	ZVAL_UNDEF(&_46);
	ZVAL_UNDEF(&_49);
	ZVAL_UNDEF(&_56);
	ZVAL_UNDEF(&_59);
	ZVAL_UNDEF(&_60);
	ZVAL_UNDEF(&_65);
	ZVAL_UNDEF(&_66);
	ZVAL_UNDEF(&_67);
	ZVAL_UNDEF(&_68);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_12$$5);
	ZVAL_UNDEF(&_13$$5);
	ZVAL_UNDEF(&_14$$5);
	ZVAL_UNDEF(&_18$$6);
	ZVAL_UNDEF(&_19$$6);
	ZVAL_UNDEF(&_20$$6);
	ZVAL_UNDEF(&_22$$7);
	ZVAL_UNDEF(&_23$$7);
	ZVAL_UNDEF(&_26$$8);
	ZVAL_UNDEF(&_27$$8);
	ZVAL_UNDEF(&_28$$8);
	ZVAL_UNDEF(&_36$$9);
	ZVAL_UNDEF(&_37$$9);
	ZVAL_UNDEF(&_38$$9);
	ZVAL_UNDEF(&_43$$10);
	ZVAL_UNDEF(&_44$$10);
	ZVAL_UNDEF(&_45$$10);
	ZVAL_UNDEF(&_47$$11);
	ZVAL_UNDEF(&_48$$11);
	ZVAL_UNDEF(&_50$$12);
	ZVAL_UNDEF(&_51$$12);
	ZVAL_UNDEF(&_52$$12);
	ZVAL_UNDEF(&_53$$12);
	ZVAL_UNDEF(&_54$$12);
	ZVAL_UNDEF(&lang$$13);
	ZVAL_UNDEF(&_62$$13);
	ZVAL_UNDEF(&_63$$13);
	ZVAL_UNDEF(&_64$$13);
	ZVAL_UNDEF(&_55);
	ZVAL_UNDEF(&_61$$13);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("_name"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_0) == IS_NULL) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, brisk_exception_kernelexception_ce);
		ZEPHIR_INIT_VAR(&_4$$3);
		ZVAL_STRING(&_4$$3, "core.invalid_app_name");
		ZEPHIR_CALL_CE_STATIC(&_2$$3, brisk_kernel_language_ce, "get", &_3, 0, &_4$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 3, &_2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "brisk/Kernel/App.zep", 128 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_read_property(&_5, this_ptr, SL("_base_dir"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_5) == IS_NULL) {
		ZEPHIR_INIT_VAR(&_8$$4);
		ZVAL_STRING(&_8$$4, ".");
		ZEPHIR_CALL_CE_STATIC(&_6$$4, brisk_kernel_loader_ce, "realpath", &_7, 0, &_8$$4);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, SL("_base_dir"), &_6$$4);
	}
	zephir_read_property(&_9, this_ptr, SL("_base_dir"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_FUNCTION(&_10, "is_dir", &_11, 12, &_9);
	zephir_check_call_status();
	if (!zephir_is_true(&_10)) {
		ZEPHIR_INIT_VAR(&_12$$5);
		object_init_ex(&_12$$5, brisk_exception_kernelexception_ce);
		ZEPHIR_INIT_VAR(&_14$$5);
		ZVAL_STRING(&_14$$5, "core.invalid_app_path");
		ZEPHIR_CALL_CE_STATIC(&_13$$5, brisk_kernel_language_ce, "get", &_3, 0, &_14$$5);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_12$$5, "__construct", NULL, 3, &_13$$5);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_12$$5, "brisk/Kernel/App.zep", 134 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_read_property(&_15, this_ptr, SL("_config"), PH_NOISY_CC | PH_READONLY);
	_16 = Z_TYPE_P(&_15) == IS_NULL;
	if (!(_16)) {
		zephir_read_property(&_17, this_ptr, SL("_config"), PH_NOISY_CC | PH_READONLY);
		_16 = !(zephir_is_callable(&_17 TSRMLS_CC));
	}
	if (_16) {
		ZEPHIR_INIT_VAR(&_18$$6);
		object_init_ex(&_18$$6, brisk_exception_kernelexception_ce);
		ZEPHIR_INIT_VAR(&_20$$6);
		ZVAL_STRING(&_20$$6, "core.invalid_configuration");
		ZEPHIR_CALL_CE_STATIC(&_19$$6, brisk_kernel_language_ce, "get", &_3, 0, &_20$$6);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_18$$6, "__construct", NULL, 3, &_19$$6);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_18$$6, "brisk/Kernel/App.zep", 137 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_read_property(&_21, this_ptr, SL("_controller_dir"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_21) == IS_NULL) {
		zephir_read_property(&_22$$7, this_ptr, SL("_base_dir"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_23$$7);
		ZEPHIR_CONCAT_VSS(&_23$$7, &_22$$7, "/", "Controller");
		zephir_update_property_zval(this_ptr, SL("_controller_dir"), &_23$$7);
	}
	zephir_read_property(&_24, this_ptr, SL("_controller_dir"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_FUNCTION(&_25, "is_dir", &_11, 12, &_24);
	zephir_check_call_status();
	if (!zephir_is_true(&_25)) {
		ZEPHIR_INIT_VAR(&_26$$8);
		object_init_ex(&_26$$8, brisk_exception_kernelexception_ce);
		ZEPHIR_INIT_VAR(&_28$$8);
		ZVAL_STRING(&_28$$8, "core.invalid_controller_path");
		ZEPHIR_CALL_CE_STATIC(&_27$$8, brisk_kernel_language_ce, "get", &_3, 0, &_28$$8);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_26$$8, "__construct", NULL, 3, &_27$$8);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_26$$8, "brisk/Kernel/App.zep", 144 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_read_property(&_30, this_ptr, SL("_name"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_31, this_ptr, SL("_base_dir"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_CE_STATIC(NULL, brisk_kernel_loader_ce, "setnamespace", &_29, 0, &_30, &_31);
	zephir_check_call_status();
	zephir_read_property(&_33, this_ptr, SL("_base_dir"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_34);
	ZVAL_STRING(&_34, "@");
	ZEPHIR_CALL_CE_STATIC(NULL, brisk_kernel_loader_ce, "setalias", &_32, 0, &_34, &_33);
	zephir_check_call_status();
	zephir_read_property(&_35, this_ptr, SL("_config"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_NVAR(&_34);
	array_init(&_34);
	ZEPHIR_INIT_VAR(&config);
	ZEPHIR_CALL_USER_FUNC_ARRAY(&config, &_35, &_34);
	zephir_check_call_status();
	if (!(Z_TYPE_P(&config) == IS_ARRAY)) {
		ZEPHIR_INIT_VAR(&_36$$9);
		object_init_ex(&_36$$9, brisk_exception_kernelexception_ce);
		ZEPHIR_INIT_VAR(&_38$$9);
		ZVAL_STRING(&_38$$9, "core.invalid_configuration");
		ZEPHIR_CALL_CE_STATIC(&_37$$9, brisk_kernel_language_ce, "get", &_3, 0, &_38$$9);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_36$$9, "__construct", NULL, 3, &_37$$9);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_36$$9, "brisk/Kernel/App.zep", 152 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&_39);
	object_init_ex(&_39, brisk_kernel_container_ce);
	ZEPHIR_CALL_METHOD(NULL, &_39, "__construct", NULL, 25, &config);
	zephir_check_call_status();
	zephir_update_static_property_array_multi_ce(brisk_kernel_app_ce, SL("_storage"), &_39 TSRMLS_CC, SL("ss"), 4, SL("config"), SL("instance"));
	zephir_read_static_property_ce(&_40, brisk_kernel_app_ce, SL("_storage"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch_string(&_41, &_40, SL("config"), PH_NOISY | PH_READONLY, "brisk/Kernel/App.zep", 155 TSRMLS_CC);
	ZEPHIR_OBS_VAR(&instance);
	zephir_array_fetch_string(&instance, &_41, SL("instance"), PH_NOISY, "brisk/Kernel/App.zep", 155 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(&_39);
	ZVAL_STRING(&_39, "global.header");
	ZEPHIR_CALL_METHOD(&_42, &instance, "haskey", NULL, 0, &_39);
	zephir_check_call_status();
	if (zephir_is_true(&_42)) {
		zephir_read_property(&_43$$10, &instance, SL("global"), PH_NOISY_CC | PH_READONLY);
		zephir_read_property(&_44$$10, &_43$$10, SL("header"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_45$$10, &_44$$10, "getvalue", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(NULL, "header", NULL, 24, &_45$$10);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(&timezone);
	ZVAL_STRING(&timezone, "Asia/Shanghai");
	ZEPHIR_INIT_NVAR(&_39);
	ZVAL_STRING(&_39, "global.timezone");
	ZEPHIR_CALL_METHOD(&_46, &instance, "haskey", NULL, 0, &_39);
	zephir_check_call_status();
	if (zephir_is_true(&_46)) {
		zephir_read_property(&_47$$11, &instance, SL("global"), PH_NOISY_CC | PH_READONLY);
		zephir_read_property(&_48$$11, &_47$$11, SL("timezone"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&timezone, &_48$$11, "getvalue", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_FUNCTION(NULL, "date_default_timezone_set", NULL, 27, &timezone);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_39);
	ZVAL_STRING(&_39, "global.error_reporting");
	ZEPHIR_CALL_METHOD(&_49, &instance, "haskey", NULL, 0, &_39);
	zephir_check_call_status();
	if (zephir_is_true(&_49)) {
		ZEPHIR_INIT_VAR(&_50$$12);
		ZVAL_STRING(&_50$$12, "display_errors");
		ZEPHIR_INIT_VAR(&_51$$12);
		ZVAL_STRING(&_51$$12, "1");
		ZEPHIR_CALL_FUNCTION(NULL, "ini_set", NULL, 23, &_50$$12, &_51$$12);
		zephir_check_call_status();
		zephir_read_property(&_52$$12, &instance, SL("global"), PH_NOISY_CC | PH_READONLY);
		zephir_read_property(&_53$$12, &_52$$12, SL("error_reporting"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_54$$12, &_53$$12, "getvalue", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(NULL, "error_reporting", NULL, 28, &_54$$12);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(&_55);
	zephir_create_array(&_55, 2, 0 TSRMLS_CC);
	ZEPHIR_CALL_CE_STATIC(&_56, brisk_kernel_adapter_ce, "getrouterdriver", &_57, 0);
	zephir_check_call_status();
	zephir_array_update_string(&_55, SL("instance"), &_56, PH_COPY | PH_SEPARATE);
	add_assoc_long_ex(&_55, SL("system"), 1);
	zephir_update_static_property_array_multi_ce(brisk_kernel_app_ce, SL("_storage"), &_55 TSRMLS_CC, SL("s"), 2, SL("router"));
	ZEPHIR_INIT_NVAR(&_39);
	ZVAL_STRING(&_39, "event.framework.ready");
	ZEPHIR_CALL_CE_STATIC(NULL, brisk_kernel_event_ce, "onlistening", &_58, 0, &_39);
	zephir_check_call_status();
	zephir_read_static_property_ce(&_59, brisk_kernel_app_ce, SL("_instance"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_OBS_VAR(&_60);
	zephir_read_property(&_60, &_59, SL("router"), PH_NOISY_CC);
	if (!(zephir_instance_of_ev(&_60, brisk_contract_irouter_ce TSRMLS_CC))) {
		ZEPHIR_INIT_VAR(&_61$$13);
		zephir_create_array(&_61$$13, 2, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_62$$13);
		zephir_read_static_property_ce(&_63$$13, brisk_kernel_app_ce, SL("_instance"), PH_NOISY_CC | PH_READONLY);
		zephir_read_property(&_64$$13, &_63$$13, SL("router"), PH_NOISY_CC | PH_READONLY);
		zephir_get_class(&_62$$13, &_64$$13, 0 TSRMLS_CC);
		zephir_array_fast_append(&_61$$13, &_62$$13);
		ZEPHIR_INIT_NVAR(&_62$$13);
		ZVAL_STRING(&_62$$13, "\\Brisk\\Contract\\IRouter");
		zephir_array_fast_append(&_61$$13, &_62$$13);
		ZEPHIR_INIT_NVAR(&_62$$13);
		ZVAL_STRING(&_62$$13, "router.driver_implement_error");
		ZEPHIR_CALL_CE_STATIC(&lang$$13, brisk_kernel_language_ce, "get", &_3, 0, &_62$$13, &_61$$13);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_62$$13);
		object_init_ex(&_62$$13, brisk_exception_kernelexception_ce);
		ZEPHIR_CALL_METHOD(NULL, &_62$$13, "__construct", NULL, 3, &lang$$13);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_62$$13, "brisk/Kernel/App.zep", 179 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_read_static_property_ce(&_65, brisk_kernel_app_ce, SL("_instance"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_66, &_65, SL("router"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_66, "ready", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_39);
	ZVAL_STRING(&_39, "event.router.ready");
	ZEPHIR_CALL_CE_STATIC(NULL, brisk_kernel_event_ce, "onlistening", &_58, 0, &_39);
	zephir_check_call_status();
	zephir_read_static_property_ce(&_67, brisk_kernel_app_ce, SL("_instance"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_68, &_67, SL("router"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_68, "dispatch", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Brisk_Kernel_App, setComponent) {

	zval _5$$3;
	zend_bool _1;
	zval *name_param = NULL, *value, value_sub, _0, _2, _3, _4;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name_param, &value);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_EMPTY_STRING(&name);
	}
	if (UNEXPECTED(zephir_is_callable(value TSRMLS_CC) != 1)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'value' must be a callable") TSRMLS_CC);
		RETURN_MM_NULL();
	}


	zephir_read_static_property_ce(&_0, brisk_kernel_app_ce, SL("_storage"), PH_NOISY_CC | PH_READONLY);
	_1 = !(zephir_array_isset(&_0, &name));
	if (!(_1)) {
		zephir_read_static_property_ce(&_2, brisk_kernel_app_ce, SL("_storage"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_3, &_2, &name, PH_NOISY | PH_READONLY, "brisk/Kernel/App.zep", 192 TSRMLS_CC);
		zephir_array_fetch_string(&_4, &_3, SL("system"), PH_NOISY | PH_READONLY, "brisk/Kernel/App.zep", 192 TSRMLS_CC);
		_1 = !zephir_is_true(&_4);
	}
	if (_1) {
		ZEPHIR_INIT_VAR(&_5$$3);
		zephir_create_array(&_5$$3, 2, 0 TSRMLS_CC);
		zephir_array_update_string(&_5$$3, SL("instance"), value, PH_COPY | PH_SEPARATE);
		add_assoc_long_ex(&_5$$3, SL("system"), 0);
		zephir_update_static_property_array_multi_ce(brisk_kernel_app_ce, SL("_storage"), &_5$$3 TSRMLS_CC, SL("z"), 1, &name);
	}
	RETURN_THIS();

}

PHP_METHOD(Brisk_Kernel_App, getComponent) {

	zval _5$$3, _11$$5;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_4 = NULL;
	zval *name_param = NULL, instance, _0, _1, _2$$3, _3$$3, _6$$3, _7$$4, _8$$4, _9$$5, _10$$5, _12$$5;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&instance);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_12$$5);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_11$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_EMPTY_STRING(&name);
	}


	zephir_read_static_property_ce(&_0, brisk_kernel_app_ce, SL("_storage"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch(&_1, &_0, &name, PH_NOISY | PH_READONLY, "brisk/Kernel/App.zep", 201 TSRMLS_CC);
	ZEPHIR_OBS_VAR(&instance);
	zephir_array_fetch_string(&instance, &_1, SL("instance"), PH_NOISY, "brisk/Kernel/App.zep", 201 TSRMLS_CC);
	if (Z_TYPE_P(&instance) == IS_NULL) {
		ZEPHIR_INIT_VAR(&_2$$3);
		object_init_ex(&_2$$3, brisk_exception_kernelexception_ce);
		ZEPHIR_INIT_VAR(&_5$$3);
		zephir_create_array(&_5$$3, 1, 0 TSRMLS_CC);
		zephir_array_fast_append(&_5$$3, &name);
		ZEPHIR_INIT_VAR(&_6$$3);
		ZVAL_STRING(&_6$$3, "core.object_not_found");
		ZEPHIR_CALL_CE_STATIC(&_3$$3, brisk_kernel_language_ce, "get", &_4, 0, &_6$$3, &_5$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_2$$3, "__construct", NULL, 3, &_3$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_2$$3, "brisk/Kernel/App.zep", 203 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	} else if (zephir_is_callable(&instance TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(&_7$$4);
		ZEPHIR_INIT_VAR(&_8$$4);
		array_init(&_8$$4);
		ZEPHIR_CALL_USER_FUNC_ARRAY(&_7$$4, &instance, &_8$$4);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&instance, &_7$$4);
		if (!zephir_is_true(&instance)) {
			ZEPHIR_INIT_VAR(&_9$$5);
			object_init_ex(&_9$$5, brisk_exception_kernelexception_ce);
			ZEPHIR_INIT_VAR(&_11$$5);
			zephir_create_array(&_11$$5, 1, 0 TSRMLS_CC);
			zephir_array_fast_append(&_11$$5, &name);
			ZEPHIR_INIT_VAR(&_12$$5);
			ZVAL_STRING(&_12$$5, "core.invlid_custom_member");
			ZEPHIR_CALL_CE_STATIC(&_10$$5, brisk_kernel_language_ce, "get", &_4, 0, &_12$$5, &_11$$5);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &_9$$5, "__construct", NULL, 3, &_10$$5);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_9$$5, "brisk/Kernel/App.zep", 207 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_update_static_property_array_multi_ce(brisk_kernel_app_ce, SL("_storage"), &instance TSRMLS_CC, SL("zs"), 3, &name, SL("instance"));
	}
	RETURN_CCTOR(&instance);

}

PHP_METHOD(Brisk_Kernel_App, __get) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_EMPTY_STRING(&name);
	}


	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getcomponent", NULL, 0, &name);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Brisk_Kernel_App, setMethod) {

	zval _3$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_2 = NULL;
	zval *name_param = NULL, *method, method_sub, _0$$3, _1$$3, _4$$3;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&method_sub);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_3$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name_param, &method);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_EMPTY_STRING(&name);
	}
	if (UNEXPECTED(zephir_is_callable(method TSRMLS_CC) != 1)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'method' must be a callable") TSRMLS_CC);
		RETURN_MM_NULL();
	}


	if (!(zephir_is_callable(method TSRMLS_CC))) {
		ZEPHIR_INIT_VAR(&_0$$3);
		object_init_ex(&_0$$3, brisk_exception_kernelexception_ce);
		ZEPHIR_INIT_VAR(&_3$$3);
		zephir_create_array(&_3$$3, 1, 0 TSRMLS_CC);
		zephir_array_fast_append(&_3$$3, &name);
		ZEPHIR_INIT_VAR(&_4$$3);
		ZVAL_STRING(&_4$$3, "core.invalid_custom_method");
		ZEPHIR_CALL_CE_STATIC(&_1$$3, brisk_kernel_language_ce, "get", &_2, 0, &_4$$3, &_3$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_0$$3, "__construct", NULL, 3, &_1$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_0$$3, "brisk/Kernel/App.zep", 222 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_static_property_array_multi_ce(brisk_kernel_app_ce, SL("_methods"), method TSRMLS_CC, SL("z"), 1, &name);
	RETURN_THIS();

}

PHP_METHOD(Brisk_Kernel_App, callMethod) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_3 = NULL;
	zval args, _4$$3;
	zval *name_param = NULL, *args_param = NULL, _0, method, _6, _1$$3, _2$$3, _5$$3;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&args);
	ZVAL_UNDEF(&_4$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name_param, &args_param);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_EMPTY_STRING(&name);
	}
	ZEPHIR_OBS_COPY_OR_DUP(&args, args_param);


	zephir_read_static_property_ce(&_0, brisk_kernel_app_ce, SL("_methods"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset(&_0, &name))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, brisk_exception_kernelexception_ce);
		ZEPHIR_INIT_VAR(&_4$$3);
		zephir_create_array(&_4$$3, 1, 0 TSRMLS_CC);
		zephir_array_fast_append(&_4$$3, &name);
		ZEPHIR_INIT_VAR(&_5$$3);
		ZVAL_STRING(&_5$$3, "core.custom_method_notfound");
		ZEPHIR_CALL_CE_STATIC(&_2$$3, brisk_kernel_language_ce, "get", &_3, 0, &_5$$3, &_4$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 3, &_2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "brisk/Kernel/App.zep", 231 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_read_static_property_ce(&_6, brisk_kernel_app_ce, SL("_methods"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_OBS_VAR(&method);
	zephir_array_fetch(&method, &_6, &name, PH_NOISY, "brisk/Kernel/App.zep", 233 TSRMLS_CC);
	ZEPHIR_CALL_USER_FUNC_ARRAY(return_value, &method, &args);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Brisk_Kernel_App, __call) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval args;
	zval *name_param = NULL, *args_param = NULL;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&args);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name_param, &args_param);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_EMPTY_STRING(&name);
	}
	ZEPHIR_OBS_COPY_OR_DUP(&args, args_param);


	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "callmethod", NULL, 0, &name, &args);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Brisk_Kernel_App, __destruct) {

	zval _1, _3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL, *_2 = NULL, *_4 = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "sys_shutdown");
	ZEPHIR_CALL_CE_STATIC(NULL, brisk_kernel_timer_ce, "mark", &_0, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_3, "memory_get_usage", NULL, 21);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "memory");
	ZEPHIR_CALL_CE_STATIC(NULL, brisk_kernel_trace_ce, "set", &_2, 0, &_1, &_3);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "event.framework.shutdown");
	ZEPHIR_CALL_CE_STATIC(NULL, brisk_kernel_event_ce, "onlistening", &_4, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

void zephir_init_static_properties_Brisk_Kernel_App(TSRMLS_D) {

	zval _0, _1;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	array_init(&_0);
	zend_update_static_property(brisk_kernel_app_ce, ZEND_STRL("_methods"), &_0);
	ZEPHIR_INIT_VAR(&_1);
	array_init(&_1);
	zend_update_static_property(brisk_kernel_app_ce, ZEND_STRL("_storage"), &_1);
	ZEPHIR_MM_RESTORE();

}


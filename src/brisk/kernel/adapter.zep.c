
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
#include "kernel/concat.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "kernel/array.h"
#include "ext/spl/spl_exceptions.h"


ZEPHIR_INIT_CLASS(Brisk_Kernel_Adapter) {

	ZEPHIR_REGISTER_CLASS(Brisk\\Kernel, Adapter, brisk, kernel_adapter, brisk_kernel_adapter_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Brisk_Kernel_Adapter, getCacheDriver) {

	zval _28, _8$$3, _19$$4, _25$$5;
	zend_class_entry *_22;
	zend_bool _14;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_2 = NULL, *_7 = NULL, *_16 = NULL, *_27 = NULL;
	zval *name_param = NULL, __$false, path, _1, _3, _4, config, _10, _11, _12, _13, driver, save_path, option, _15, instance, _21, _29, _30, _5$$3, _6$$3, _9$$3, _17$$4, _18$$4, _20$$4, _23$$5, _24$$5, _26$$5;
	zval name, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&path);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&config);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&driver);
	ZVAL_UNDEF(&save_path);
	ZVAL_UNDEF(&option);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&instance);
	ZVAL_UNDEF(&_21);
	ZVAL_UNDEF(&_29);
	ZVAL_UNDEF(&_30);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_17$$4);
	ZVAL_UNDEF(&_18$$4);
	ZVAL_UNDEF(&_20$$4);
	ZVAL_UNDEF(&_23$$5);
	ZVAL_UNDEF(&_24$$5);
	ZVAL_UNDEF(&_26$$5);
	ZVAL_UNDEF(&_28);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_19$$4);
	ZVAL_UNDEF(&_25$$5);

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


	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_CONCAT_SV(&_0, "cache.", &name);
	ZEPHIR_CPY_WRT(&path, &_0);
	ZEPHIR_CALL_CE_STATIC(&_1, brisk_kernel_app_ce, "getinstance", &_2, 0);
	zephir_check_call_status();
	zephir_read_property(&_3, &_1, SL("config"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_4, &_3, "haskey", NULL, 0, &path);
	zephir_check_call_status();
	if (!zephir_is_true(&_4)) {
		ZEPHIR_INIT_VAR(&_5$$3);
		object_init_ex(&_5$$3, brisk_exception_kernelexception_ce);
		ZEPHIR_INIT_VAR(&_8$$3);
		zephir_create_array(&_8$$3, 1, 0 TSRMLS_CC);
		zephir_array_fast_append(&_8$$3, &path);
		ZEPHIR_INIT_VAR(&_9$$3);
		ZVAL_STRING(&_9$$3, "core.config_not_found");
		ZEPHIR_CALL_CE_STATIC(&_6$$3, brisk_kernel_language_ce, "get", &_7, 0, &_9$$3, &_8$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_5$$3, "__construct", NULL, 3, &_6$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_5$$3, "brisk/Kernel/Adapter.zep", 18 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_CE_STATIC(&_10, brisk_kernel_app_ce, "getinstance", &_2, 0);
	zephir_check_call_status();
	zephir_read_property(&_11, &_10, SL("config"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_OBS_VAR(&_12);
	zephir_read_property(&_12, &_11, SL("cache"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(&_13);
	zephir_read_property_zval(&_13, &_12, &name, PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&config, &_13, "getvalue", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(&driver);
	zephir_array_fetch_string(&driver, &config, SL("driver"), PH_NOISY, "brisk/Kernel/Adapter.zep", 21 TSRMLS_CC);
	ZEPHIR_OBS_VAR(&save_path);
	zephir_array_fetch_string(&save_path, &config, SL("save_path"), PH_NOISY, "brisk/Kernel/Adapter.zep", 22 TSRMLS_CC);
	ZEPHIR_OBS_VAR(&option);
	zephir_array_fetch_string(&option, &config, SL("option"), PH_NOISY, "brisk/Kernel/Adapter.zep", 23 TSRMLS_CC);
	_14 = !(zephir_class_exists(&driver, zephir_is_true(&__$false)  TSRMLS_CC));
	if (_14) {
		ZEPHIR_CALL_CE_STATIC(&_15, brisk_kernel_loader_ce, "findclass", &_16, 0, &driver);
		zephir_check_call_status();
		_14 = !zephir_is_true(&_15);
	}
	if (_14) {
		ZEPHIR_INIT_VAR(&_17$$4);
		object_init_ex(&_17$$4, brisk_exception_kernelexception_ce);
		ZEPHIR_INIT_VAR(&_19$$4);
		zephir_create_array(&_19$$4, 1, 0 TSRMLS_CC);
		zephir_array_fast_append(&_19$$4, &driver);
		ZEPHIR_INIT_VAR(&_20$$4);
		ZVAL_STRING(&_20$$4, "cache.driver_not_found");
		ZEPHIR_CALL_CE_STATIC(&_18$$4, brisk_kernel_language_ce, "get", &_7, 0, &_20$$4, &_19$$4);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_17$$4, "__construct", NULL, 3, &_18$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_17$$4, "brisk/Kernel/Adapter.zep", 25 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&instance);
	zephir_fetch_safe_class(&_21, &driver);
	_22 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_21), Z_STRLEN_P(&_21), ZEND_FETCH_CLASS_AUTO);
	object_init_ex(&instance, _22);
	if (zephir_has_constructor(&instance TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, &instance, "__construct", NULL, 0, &save_path, &option);
		zephir_check_call_status();
	}
	if (!((zephir_instance_of_ev(&instance, brisk_contract_icache_ce TSRMLS_CC)))) {
		ZEPHIR_INIT_VAR(&_23$$5);
		object_init_ex(&_23$$5, brisk_exception_kernelexception_ce);
		ZEPHIR_INIT_VAR(&_25$$5);
		zephir_create_array(&_25$$5, 2, 0 TSRMLS_CC);
		zephir_array_fast_append(&_25$$5, &driver);
		ZEPHIR_INIT_VAR(&_26$$5);
		ZVAL_STRING(&_26$$5, "\\Brisk\\Contract\\ICache");
		zephir_array_fast_append(&_25$$5, &_26$$5);
		ZEPHIR_INIT_NVAR(&_26$$5);
		ZVAL_STRING(&_26$$5, "cache.driver_implement_error");
		ZEPHIR_CALL_CE_STATIC(&_24$$5, brisk_kernel_language_ce, "get", &_7, 0, &_26$$5, &_25$$5);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_23$$5, "__construct", NULL, 3, &_24$$5);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_23$$5, "brisk/Kernel/Adapter.zep", 30 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&_28);
	zephir_create_array(&_28, 1, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_29);
	ZVAL_STRING(&_29, "%s[%s]");
	ZEPHIR_CALL_FUNCTION(&_30, "sprintf", NULL, 4, &_29, &name, &driver);
	zephir_check_call_status();
	zephir_array_update_string(&_28, SL("cache"), &_30, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_29);
	ZVAL_STRING(&_29, "driver");
	ZEPHIR_CALL_CE_STATIC(NULL, brisk_kernel_trace_ce, "set", &_27, 0, &_29, &_28);
	zephir_check_call_status();
	RETURN_CCTOR(&instance);

}

PHP_METHOD(Brisk_Kernel_Adapter, getDatabaseDriver) {

	zval _28, _8$$3, _19$$4, _25$$5;
	zend_class_entry *_22;
	zend_bool _14;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_2 = NULL, *_7 = NULL, *_16 = NULL, *_27 = NULL;
	zval *name_param = NULL, __$false, path, _1, _3, _4, config, _10, _11, _12, _13, driver, dsn, option, _15, instance, _21, _29, _30, _5$$3, _6$$3, _9$$3, _17$$4, _18$$4, _20$$4, _23$$5, _24$$5, _26$$5;
	zval name, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&path);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&config);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&driver);
	ZVAL_UNDEF(&dsn);
	ZVAL_UNDEF(&option);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&instance);
	ZVAL_UNDEF(&_21);
	ZVAL_UNDEF(&_29);
	ZVAL_UNDEF(&_30);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_17$$4);
	ZVAL_UNDEF(&_18$$4);
	ZVAL_UNDEF(&_20$$4);
	ZVAL_UNDEF(&_23$$5);
	ZVAL_UNDEF(&_24$$5);
	ZVAL_UNDEF(&_26$$5);
	ZVAL_UNDEF(&_28);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_19$$4);
	ZVAL_UNDEF(&_25$$5);

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


	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_CONCAT_SV(&_0, "database.", &name);
	ZEPHIR_CPY_WRT(&path, &_0);
	ZEPHIR_CALL_CE_STATIC(&_1, brisk_kernel_app_ce, "getinstance", &_2, 0);
	zephir_check_call_status();
	zephir_read_property(&_3, &_1, SL("config"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_4, &_3, "haskey", NULL, 0, &path);
	zephir_check_call_status();
	if (!zephir_is_true(&_4)) {
		ZEPHIR_INIT_VAR(&_5$$3);
		object_init_ex(&_5$$3, brisk_exception_kernelexception_ce);
		ZEPHIR_INIT_VAR(&_8$$3);
		zephir_create_array(&_8$$3, 1, 0 TSRMLS_CC);
		zephir_array_fast_append(&_8$$3, &path);
		ZEPHIR_INIT_VAR(&_9$$3);
		ZVAL_STRING(&_9$$3, "core.config_not_found");
		ZEPHIR_CALL_CE_STATIC(&_6$$3, brisk_kernel_language_ce, "get", &_7, 0, &_9$$3, &_8$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_5$$3, "__construct", NULL, 3, &_6$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_5$$3, "brisk/Kernel/Adapter.zep", 41 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_CE_STATIC(&_10, brisk_kernel_app_ce, "getinstance", &_2, 0);
	zephir_check_call_status();
	zephir_read_property(&_11, &_10, SL("config"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_OBS_VAR(&_12);
	zephir_read_property(&_12, &_11, SL("database"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(&_13);
	zephir_read_property_zval(&_13, &_12, &name, PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&config, &_13, "getvalue", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(&driver);
	zephir_array_fetch_string(&driver, &config, SL("driver"), PH_NOISY, "brisk/Kernel/Adapter.zep", 44 TSRMLS_CC);
	ZEPHIR_OBS_VAR(&dsn);
	zephir_array_fetch_string(&dsn, &config, SL("dsn"), PH_NOISY, "brisk/Kernel/Adapter.zep", 45 TSRMLS_CC);
	ZEPHIR_OBS_VAR(&option);
	zephir_array_fetch_string(&option, &config, SL("option"), PH_NOISY, "brisk/Kernel/Adapter.zep", 46 TSRMLS_CC);
	_14 = !(zephir_class_exists(&driver, zephir_is_true(&__$false)  TSRMLS_CC));
	if (_14) {
		ZEPHIR_CALL_CE_STATIC(&_15, brisk_kernel_loader_ce, "findclass", &_16, 0, &driver);
		zephir_check_call_status();
		_14 = !zephir_is_true(&_15);
	}
	if (_14) {
		ZEPHIR_INIT_VAR(&_17$$4);
		object_init_ex(&_17$$4, brisk_exception_kernelexception_ce);
		ZEPHIR_INIT_VAR(&_19$$4);
		zephir_create_array(&_19$$4, 1, 0 TSRMLS_CC);
		zephir_array_fast_append(&_19$$4, &driver);
		ZEPHIR_INIT_VAR(&_20$$4);
		ZVAL_STRING(&_20$$4, "db.driver_not_found");
		ZEPHIR_CALL_CE_STATIC(&_18$$4, brisk_kernel_language_ce, "get", &_7, 0, &_20$$4, &_19$$4);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_17$$4, "__construct", NULL, 3, &_18$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_17$$4, "brisk/Kernel/Adapter.zep", 48 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&instance);
	zephir_fetch_safe_class(&_21, &driver);
	_22 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_21), Z_STRLEN_P(&_21), ZEND_FETCH_CLASS_AUTO);
	object_init_ex(&instance, _22);
	if (zephir_has_constructor(&instance TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, &instance, "__construct", NULL, 0, &dsn, &option);
		zephir_check_call_status();
	}
	if (!((zephir_instance_of_ev(&instance, brisk_contract_idatabase_ce TSRMLS_CC)))) {
		ZEPHIR_INIT_VAR(&_23$$5);
		object_init_ex(&_23$$5, brisk_exception_kernelexception_ce);
		ZEPHIR_INIT_VAR(&_25$$5);
		zephir_create_array(&_25$$5, 2, 0 TSRMLS_CC);
		zephir_array_fast_append(&_25$$5, &driver);
		ZEPHIR_INIT_VAR(&_26$$5);
		ZVAL_STRING(&_26$$5, "\\Brisk\\Contract\\IDatabase");
		zephir_array_fast_append(&_25$$5, &_26$$5);
		ZEPHIR_INIT_NVAR(&_26$$5);
		ZVAL_STRING(&_26$$5, "db.driver_implement_error");
		ZEPHIR_CALL_CE_STATIC(&_24$$5, brisk_kernel_language_ce, "get", &_7, 0, &_26$$5, &_25$$5);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_23$$5, "__construct", NULL, 3, &_24$$5);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_23$$5, "brisk/Kernel/Adapter.zep", 53 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&_28);
	zephir_create_array(&_28, 1, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_29);
	ZVAL_STRING(&_29, "%s[%s]");
	ZEPHIR_CALL_FUNCTION(&_30, "sprintf", NULL, 4, &_29, &name, &driver);
	zephir_check_call_status();
	zephir_array_update_string(&_28, SL("database"), &_30, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_29);
	ZVAL_STRING(&_29, "driver");
	ZEPHIR_CALL_CE_STATIC(NULL, brisk_kernel_trace_ce, "set", &_27, 0, &_29, &_28);
	zephir_check_call_status();
	RETURN_CCTOR(&instance);

}

PHP_METHOD(Brisk_Kernel_Adapter, getRouterDriver) {

	zval _28, _8$$3, _19$$4, _25$$5;
	zend_class_entry *_22;
	zend_bool _14;
	zval __$false, _0, _2, _3, _4, driver, _10, _11, _12, _13, _15, instance, _21, _5$$3, _6$$3, _9$$3, _17$$4, _18$$4, _20$$4, _23$$5, _24$$5, _26$$5;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL, *_7 = NULL, *_16 = NULL, *_27 = NULL;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&driver);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&instance);
	ZVAL_UNDEF(&_21);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_17$$4);
	ZVAL_UNDEF(&_18$$4);
	ZVAL_UNDEF(&_20$$4);
	ZVAL_UNDEF(&_23$$5);
	ZVAL_UNDEF(&_24$$5);
	ZVAL_UNDEF(&_26$$5);
	ZVAL_UNDEF(&_28);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_19$$4);
	ZVAL_UNDEF(&_25$$5);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_CE_STATIC(&_0, brisk_kernel_app_ce, "getinstance", &_1, 0);
	zephir_check_call_status();
	zephir_read_property(&_2, &_0, SL("config"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "router>driver");
	ZEPHIR_CALL_METHOD(&_3, &_2, "haskey", NULL, 0, &_4);
	zephir_check_call_status();
	if (!zephir_is_true(&_3)) {
		ZEPHIR_INIT_VAR(&_5$$3);
		object_init_ex(&_5$$3, brisk_exception_kernelexception_ce);
		ZEPHIR_INIT_VAR(&_8$$3);
		zephir_create_array(&_8$$3, 1, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_9$$3);
		ZVAL_STRING(&_9$$3, "router.driver");
		zephir_array_fast_append(&_8$$3, &_9$$3);
		ZEPHIR_INIT_NVAR(&_9$$3);
		ZVAL_STRING(&_9$$3, "core.config_not_found");
		ZEPHIR_CALL_CE_STATIC(&_6$$3, brisk_kernel_language_ce, "get", &_7, 0, &_9$$3, &_8$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_5$$3, "__construct", NULL, 3, &_6$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_5$$3, "brisk/Kernel/Adapter.zep", 62 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_CE_STATIC(&_10, brisk_kernel_app_ce, "getinstance", &_1, 0);
	zephir_check_call_status();
	zephir_read_property(&_11, &_10, SL("config"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_12, &_11, SL("router"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_13, &_12, SL("driver"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&driver, &_13, "getvalue", NULL, 0);
	zephir_check_call_status();
	_14 = !(zephir_class_exists(&driver, zephir_is_true(&__$false)  TSRMLS_CC));
	if (_14) {
		ZEPHIR_CALL_CE_STATIC(&_15, brisk_kernel_loader_ce, "findclass", &_16, 0, &driver);
		zephir_check_call_status();
		_14 = !zephir_is_true(&_15);
	}
	if (_14) {
		ZEPHIR_INIT_VAR(&_17$$4);
		object_init_ex(&_17$$4, brisk_exception_kernelexception_ce);
		ZEPHIR_INIT_VAR(&_19$$4);
		zephir_create_array(&_19$$4, 1, 0 TSRMLS_CC);
		zephir_array_fast_append(&_19$$4, &driver);
		ZEPHIR_INIT_VAR(&_20$$4);
		ZVAL_STRING(&_20$$4, "router.driver_not_found");
		ZEPHIR_CALL_CE_STATIC(&_18$$4, brisk_kernel_language_ce, "get", &_7, 0, &_20$$4, &_19$$4);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_17$$4, "__construct", NULL, 3, &_18$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_17$$4, "brisk/Kernel/Adapter.zep", 66 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&instance);
	zephir_fetch_safe_class(&_21, &driver);
	_22 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_21), Z_STRLEN_P(&_21), ZEND_FETCH_CLASS_AUTO);
	object_init_ex(&instance, _22);
	if (zephir_has_constructor(&instance TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, &instance, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	if (!((zephir_instance_of_ev(&instance, brisk_contract_irouter_ce TSRMLS_CC)))) {
		ZEPHIR_INIT_VAR(&_23$$5);
		object_init_ex(&_23$$5, brisk_exception_kernelexception_ce);
		ZEPHIR_INIT_VAR(&_25$$5);
		zephir_create_array(&_25$$5, 2, 0 TSRMLS_CC);
		zephir_array_fast_append(&_25$$5, &driver);
		ZEPHIR_INIT_VAR(&_26$$5);
		ZVAL_STRING(&_26$$5, "\\Brisk\\Contract\\IRouter");
		zephir_array_fast_append(&_25$$5, &_26$$5);
		ZEPHIR_INIT_NVAR(&_26$$5);
		ZVAL_STRING(&_26$$5, "router.driver_implement_error");
		ZEPHIR_CALL_CE_STATIC(&_24$$5, brisk_kernel_language_ce, "get", &_7, 0, &_26$$5, &_25$$5);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_23$$5, "__construct", NULL, 3, &_24$$5);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_23$$5, "brisk/Kernel/Adapter.zep", 71 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&_28);
	zephir_create_array(&_28, 1, 0 TSRMLS_CC);
	zephir_array_update_string(&_28, SL("router"), &driver, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_4);
	ZVAL_STRING(&_4, "driver");
	ZEPHIR_CALL_CE_STATIC(NULL, brisk_kernel_trace_ce, "set", &_27, 0, &_4, &_28);
	zephir_check_call_status();
	RETURN_CCTOR(&instance);

}

PHP_METHOD(Brisk_Kernel_Adapter, getSessionDriver) {

	zval _28, _8$$3, _19$$4, _25$$5;
	zend_class_entry *_22;
	zend_bool _14;
	zval __$false, _0, _2, _3, _4, driver, _10, _11, _12, _13, _15, instance, _21, _5$$3, _6$$3, _9$$3, _17$$4, _18$$4, _20$$4, _23$$5, _24$$5, _26$$5;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL, *_7 = NULL, *_16 = NULL, *_27 = NULL;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&driver);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&instance);
	ZVAL_UNDEF(&_21);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_17$$4);
	ZVAL_UNDEF(&_18$$4);
	ZVAL_UNDEF(&_20$$4);
	ZVAL_UNDEF(&_23$$5);
	ZVAL_UNDEF(&_24$$5);
	ZVAL_UNDEF(&_26$$5);
	ZVAL_UNDEF(&_28);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_19$$4);
	ZVAL_UNDEF(&_25$$5);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_CE_STATIC(&_0, brisk_kernel_app_ce, "getinstance", &_1, 0);
	zephir_check_call_status();
	zephir_read_property(&_2, &_0, SL("config"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "session>driver");
	ZEPHIR_CALL_METHOD(&_3, &_2, "haskey", NULL, 0, &_4);
	zephir_check_call_status();
	if (!zephir_is_true(&_3)) {
		ZEPHIR_INIT_VAR(&_5$$3);
		object_init_ex(&_5$$3, brisk_exception_kernelexception_ce);
		ZEPHIR_INIT_VAR(&_8$$3);
		zephir_create_array(&_8$$3, 1, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_9$$3);
		ZVAL_STRING(&_9$$3, "session.driver");
		zephir_array_fast_append(&_8$$3, &_9$$3);
		ZEPHIR_INIT_NVAR(&_9$$3);
		ZVAL_STRING(&_9$$3, "core.config_not_found");
		ZEPHIR_CALL_CE_STATIC(&_6$$3, brisk_kernel_language_ce, "get", &_7, 0, &_9$$3, &_8$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_5$$3, "__construct", NULL, 3, &_6$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_5$$3, "brisk/Kernel/Adapter.zep", 80 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_CE_STATIC(&_10, brisk_kernel_app_ce, "getinstance", &_1, 0);
	zephir_check_call_status();
	zephir_read_property(&_11, &_10, SL("config"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_12, &_11, SL("session"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_13, &_12, SL("driver"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&driver, &_13, "getvalue", NULL, 0);
	zephir_check_call_status();
	_14 = !(zephir_class_exists(&driver, zephir_is_true(&__$false)  TSRMLS_CC));
	if (_14) {
		ZEPHIR_CALL_CE_STATIC(&_15, brisk_kernel_loader_ce, "findclass", &_16, 0, &driver);
		zephir_check_call_status();
		_14 = !zephir_is_true(&_15);
	}
	if (_14) {
		ZEPHIR_INIT_VAR(&_17$$4);
		object_init_ex(&_17$$4, brisk_exception_kernelexception_ce);
		ZEPHIR_INIT_VAR(&_19$$4);
		zephir_create_array(&_19$$4, 1, 0 TSRMLS_CC);
		zephir_array_fast_append(&_19$$4, &driver);
		ZEPHIR_INIT_VAR(&_20$$4);
		ZVAL_STRING(&_20$$4, "sess.driver_not_found");
		ZEPHIR_CALL_CE_STATIC(&_18$$4, brisk_kernel_language_ce, "get", &_7, 0, &_20$$4, &_19$$4);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_17$$4, "__construct", NULL, 3, &_18$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_17$$4, "brisk/Kernel/Adapter.zep", 84 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&instance);
	zephir_fetch_safe_class(&_21, &driver);
	_22 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_21), Z_STRLEN_P(&_21), ZEND_FETCH_CLASS_AUTO);
	object_init_ex(&instance, _22);
	if (zephir_has_constructor(&instance TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, &instance, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	if (!((zephir_instance_of_ev(&instance, brisk_contract_isession_ce TSRMLS_CC)))) {
		ZEPHIR_INIT_VAR(&_23$$5);
		object_init_ex(&_23$$5, brisk_exception_kernelexception_ce);
		ZEPHIR_INIT_VAR(&_25$$5);
		zephir_create_array(&_25$$5, 2, 0 TSRMLS_CC);
		zephir_array_fast_append(&_25$$5, &driver);
		ZEPHIR_INIT_VAR(&_26$$5);
		ZVAL_STRING(&_26$$5, "\\Brisk\\Contract\\ISession");
		zephir_array_fast_append(&_25$$5, &_26$$5);
		ZEPHIR_INIT_NVAR(&_26$$5);
		ZVAL_STRING(&_26$$5, "sess.driver_implement_error");
		ZEPHIR_CALL_CE_STATIC(&_24$$5, brisk_kernel_language_ce, "get", &_7, 0, &_26$$5, &_25$$5);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_23$$5, "__construct", NULL, 3, &_24$$5);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_23$$5, "brisk/Kernel/Adapter.zep", 89 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&_28);
	zephir_create_array(&_28, 1, 0 TSRMLS_CC);
	zephir_array_update_string(&_28, SL("session"), &driver, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_4);
	ZVAL_STRING(&_4, "driver");
	ZEPHIR_CALL_CE_STATIC(NULL, brisk_kernel_trace_ce, "set", &_27, 0, &_4, &_28);
	zephir_check_call_status();
	RETURN_CCTOR(&instance);

}

PHP_METHOD(Brisk_Kernel_Adapter, getViewDriver) {

	zval _28, _8$$3, _19$$4, _25$$5;
	zend_class_entry *_22;
	zend_bool _14;
	zval __$false, _0, _2, _3, _4, driver, _10, _11, _12, _13, _15, instance, _21, _5$$3, _6$$3, _9$$3, _17$$4, _18$$4, _20$$4, _23$$5, _24$$5, _26$$5;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL, *_7 = NULL, *_16 = NULL, *_27 = NULL;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&driver);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&instance);
	ZVAL_UNDEF(&_21);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_17$$4);
	ZVAL_UNDEF(&_18$$4);
	ZVAL_UNDEF(&_20$$4);
	ZVAL_UNDEF(&_23$$5);
	ZVAL_UNDEF(&_24$$5);
	ZVAL_UNDEF(&_26$$5);
	ZVAL_UNDEF(&_28);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_19$$4);
	ZVAL_UNDEF(&_25$$5);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_CE_STATIC(&_0, brisk_kernel_app_ce, "getinstance", &_1, 0);
	zephir_check_call_status();
	zephir_read_property(&_2, &_0, SL("config"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "view>driver");
	ZEPHIR_CALL_METHOD(&_3, &_2, "haskey", NULL, 0, &_4);
	zephir_check_call_status();
	if (!zephir_is_true(&_3)) {
		ZEPHIR_INIT_VAR(&_5$$3);
		object_init_ex(&_5$$3, brisk_exception_kernelexception_ce);
		ZEPHIR_INIT_VAR(&_8$$3);
		zephir_create_array(&_8$$3, 1, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_9$$3);
		ZVAL_STRING(&_9$$3, "view.driver");
		zephir_array_fast_append(&_8$$3, &_9$$3);
		ZEPHIR_INIT_NVAR(&_9$$3);
		ZVAL_STRING(&_9$$3, "core.config_not_found");
		ZEPHIR_CALL_CE_STATIC(&_6$$3, brisk_kernel_language_ce, "get", &_7, 0, &_9$$3, &_8$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_5$$3, "__construct", NULL, 3, &_6$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_5$$3, "brisk/Kernel/Adapter.zep", 98 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_CE_STATIC(&_10, brisk_kernel_app_ce, "getinstance", &_1, 0);
	zephir_check_call_status();
	zephir_read_property(&_11, &_10, SL("config"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_12, &_11, SL("view"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_13, &_12, SL("driver"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&driver, &_13, "getvalue", NULL, 0);
	zephir_check_call_status();
	_14 = !(zephir_class_exists(&driver, zephir_is_true(&__$false)  TSRMLS_CC));
	if (_14) {
		ZEPHIR_CALL_CE_STATIC(&_15, brisk_kernel_loader_ce, "findclass", &_16, 0, &driver);
		zephir_check_call_status();
		_14 = !zephir_is_true(&_15);
	}
	if (_14) {
		ZEPHIR_INIT_VAR(&_17$$4);
		object_init_ex(&_17$$4, brisk_exception_kernelexception_ce);
		ZEPHIR_INIT_VAR(&_19$$4);
		zephir_create_array(&_19$$4, 1, 0 TSRMLS_CC);
		zephir_array_fast_append(&_19$$4, &driver);
		ZEPHIR_INIT_VAR(&_20$$4);
		ZVAL_STRING(&_20$$4, "view.driver_not_found");
		ZEPHIR_CALL_CE_STATIC(&_18$$4, brisk_kernel_language_ce, "get", &_7, 0, &_20$$4, &_19$$4);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_17$$4, "__construct", NULL, 3, &_18$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_17$$4, "brisk/Kernel/Adapter.zep", 102 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&instance);
	zephir_fetch_safe_class(&_21, &driver);
	_22 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_21), Z_STRLEN_P(&_21), ZEND_FETCH_CLASS_AUTO);
	object_init_ex(&instance, _22);
	if (zephir_has_constructor(&instance TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, &instance, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	if (!((zephir_instance_of_ev(&instance, brisk_contract_iview_ce TSRMLS_CC)))) {
		ZEPHIR_INIT_VAR(&_23$$5);
		object_init_ex(&_23$$5, brisk_exception_kernelexception_ce);
		ZEPHIR_INIT_VAR(&_25$$5);
		zephir_create_array(&_25$$5, 2, 0 TSRMLS_CC);
		zephir_array_fast_append(&_25$$5, &driver);
		ZEPHIR_INIT_VAR(&_26$$5);
		ZVAL_STRING(&_26$$5, "\\Brisk\\Contract\\IView");
		zephir_array_fast_append(&_25$$5, &_26$$5);
		ZEPHIR_INIT_NVAR(&_26$$5);
		ZVAL_STRING(&_26$$5, "view.driver_implement_error");
		ZEPHIR_CALL_CE_STATIC(&_24$$5, brisk_kernel_language_ce, "get", &_7, 0, &_26$$5, &_25$$5);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_23$$5, "__construct", NULL, 3, &_24$$5);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_23$$5, "brisk/Kernel/Adapter.zep", 107 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&_28);
	zephir_create_array(&_28, 1, 0 TSRMLS_CC);
	zephir_array_update_string(&_28, SL("view"), &driver, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_4);
	ZVAL_STRING(&_4, "driver");
	ZEPHIR_CALL_CE_STATIC(NULL, brisk_kernel_trace_ce, "set", &_27, 0, &_4, &_28);
	zephir_check_call_status();
	RETURN_CCTOR(&instance);

}


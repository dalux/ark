
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/operators.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/exception.h"
#include "kernel/array.h"
#include "ext/spl/spl_exceptions.h"


ZEPHIR_INIT_CLASS(Brisk_Vendor_View_ViewAdapter) {

	ZEPHIR_REGISTER_CLASS(Brisk\\Vendor\\View, ViewAdapter, brisk, vendor_view_viewadapter, brisk_vendor_view_viewadapter_method_entry, 0);

	return SUCCESS;

}

/**
 * Get View driver
 *
 * @param string driver
 * @param array options
 * @return ViewFather
 */
PHP_METHOD(Brisk_Vendor_View_ViewAdapter, getDriver) {

	zend_class_entry *_9;
	zend_bool _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_2 = NULL, *_5 = NULL, *_14 = NULL;
	zval *options = NULL, *_15, *_6$$3, *_12$$4;
	zval *driver_param = NULL, *options_param = NULL, *_1 = NULL, *instance = NULL, *_8 = NULL, *_16, *_3$$3, *_4$$3 = NULL, *_7$$3, *_10$$4, *_11$$4 = NULL, *_13$$4 = NULL;
	zval *driver = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &driver_param, &options_param);

	if (UNEXPECTED(Z_TYPE_P(driver_param) != IS_STRING && Z_TYPE_P(driver_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'driver' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(driver_param) == IS_STRING)) {
		zephir_get_strval(driver, driver_param);
	} else {
		ZEPHIR_INIT_VAR(driver);
		ZVAL_EMPTY_STRING(driver);
	}
	if (!options_param) {
		ZEPHIR_INIT_VAR(options);
		array_init(options);
	} else {
	options = options_param;
	}


	_0 = !(zephir_class_exists(driver, zephir_is_true(ZEPHIR_GLOBAL(global_false))  TSRMLS_CC));
	if (_0) {
		ZEPHIR_CALL_CE_STATIC(&_1, brisk_kernel_loader_ce, "findclass", &_2, 60, driver);
		zephir_check_call_status();
		_0 = !zephir_is_true(_1);
	}
	if (_0) {
		ZEPHIR_INIT_VAR(_3$$3);
		object_init_ex(_3$$3, brisk_exception_drivernotfoundexception_ce);
		ZEPHIR_INIT_VAR(_6$$3);
		zephir_create_array(_6$$3, 1, 0 TSRMLS_CC);
		zephir_array_fast_append(_6$$3, driver);
		ZEPHIR_INIT_VAR(_7$$3);
		ZVAL_STRING(_7$$3, "view.driver_not_found", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_CE_STATIC(&_4$$3, brisk_kernel_language_ce, "get", &_5, 27, _7$$3, _6$$3);
		zephir_check_temp_parameter(_7$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, _3$$3, "__construct", NULL, 28, _4$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(_3$$3, "brisk/Vendor/View/ViewAdapter.zep", 24 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(instance);
	zephir_fetch_safe_class(_8, driver);
		_9 = zend_fetch_class(Z_STRVAL_P(_8), Z_STRLEN_P(_8), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	object_init_ex(instance, _9);
	if (zephir_has_constructor(instance TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, instance, "__construct", NULL, 0, options);
		zephir_check_call_status();
	}
	if (!((zephir_instance_of_ev(instance, brisk_vendor_view_viewfather_ce TSRMLS_CC)))) {
		ZEPHIR_INIT_VAR(_10$$4);
		object_init_ex(_10$$4, brisk_exception_runtimeexception_ce);
		ZEPHIR_INIT_VAR(_12$$4);
		zephir_create_array(_12$$4, 2, 0 TSRMLS_CC);
		zephir_array_fast_append(_12$$4, driver);
		ZEPHIR_INIT_VAR(_13$$4);
		ZVAL_STRING(_13$$4, "\\Brisk\\Vendor\\View\\ViewFather", 1);
		zephir_array_fast_append(_12$$4, _13$$4);
		ZEPHIR_INIT_NVAR(_13$$4);
		ZVAL_STRING(_13$$4, "view.driver_implement_error", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_CE_STATIC(&_11$$4, brisk_kernel_language_ce, "get", &_5, 27, _13$$4, _12$$4);
		zephir_check_temp_parameter(_13$$4);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, _10$$4, "__construct", NULL, 28, _11$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(_10$$4, "brisk/Vendor/View/ViewAdapter.zep", 29 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(_15);
	zephir_create_array(_15, 1, 0 TSRMLS_CC);
	zephir_array_update_string(&_15, SL("view"), &driver, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(_16);
	ZVAL_STRING(_16, "driver", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_CE_STATIC(NULL, brisk_kernel_trace_ce, "set", &_14, 12, _16, _15);
	zephir_check_temp_parameter(_16);
	zephir_check_call_status();
	RETURN_CCTOR(instance);

}

/**
 * Get View driver from config
 *
 * @return ViewFather
 */
PHP_METHOD(Brisk_Vendor_View_ViewAdapter, getDriverFromConfig) {

	zval *_39, *_11$$3, *_15$$4, *_26$$5, *_36$$6;
	zend_class_entry *_33;
	zend_bool _21;
	zval *_0 = NULL, *_2, *_3 = NULL, *_4 = NULL, *_5 = NULL, *_6, *_7 = NULL, *driver = NULL, *_17 = NULL, *_18, *_19, *_20, *_22 = NULL, *options = NULL, *_28 = NULL, *_29, *_30, *_31, *instance = NULL, *_32 = NULL, *_8$$3, *_9$$3 = NULL, *_12$$3 = NULL, *_13$$4, *_14$$4 = NULL, *_16$$4 = NULL, *_24$$5, *_25$$5 = NULL, *_27$$5, *_34$$6, *_35$$6 = NULL, *_37$$6 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL, *_10 = NULL, *_23 = NULL, *_38 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_CE_STATIC(&_0, brisk_kernel_app_ce, "getinstance", &_1, 46);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(_2);
	zephir_read_property(&_2, _0, SL("config"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_4);
	ZVAL_STRING(_4, "view/driver", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_3, _2, "haskey", NULL, 0, _4);
	zephir_check_temp_parameter(_4);
	zephir_check_call_status();
	ZEPHIR_CALL_CE_STATIC(&_5, brisk_kernel_app_ce, "getinstance", &_1, 46);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(_6);
	zephir_read_property(&_6, _5, SL("config"), PH_NOISY_CC);
	ZEPHIR_INIT_NVAR(_4);
	ZVAL_STRING(_4, "view/options/template_dir", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_7, _6, "haskey", NULL, 0, _4);
	zephir_check_temp_parameter(_4);
	zephir_check_call_status();
	if (!zephir_is_true(_3)) {
		ZEPHIR_INIT_VAR(_8$$3);
		object_init_ex(_8$$3, brisk_exception_configurationexception_ce);
		ZEPHIR_INIT_VAR(_11$$3);
		zephir_create_array(_11$$3, 1, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_12$$3);
		ZVAL_STRING(_12$$3, "view/driver", 1);
		zephir_array_fast_append(_11$$3, _12$$3);
		ZEPHIR_INIT_NVAR(_12$$3);
		ZVAL_STRING(_12$$3, "core.config_not_found", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_CE_STATIC(&_9$$3, brisk_kernel_language_ce, "get", &_10, 27, _12$$3, _11$$3);
		zephir_check_temp_parameter(_12$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, _8$$3, "__construct", NULL, 28, _9$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(_8$$3, "brisk/Vendor/View/ViewAdapter.zep", 43 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	} else if (!zephir_is_true(_7)) {
		ZEPHIR_INIT_VAR(_13$$4);
		object_init_ex(_13$$4, brisk_exception_configurationexception_ce);
		ZEPHIR_INIT_VAR(_15$$4);
		zephir_create_array(_15$$4, 1, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_16$$4);
		ZVAL_STRING(_16$$4, "view/options/template_dir", 1);
		zephir_array_fast_append(_15$$4, _16$$4);
		ZEPHIR_INIT_NVAR(_16$$4);
		ZVAL_STRING(_16$$4, "core.config_not_found", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_CE_STATIC(&_14$$4, brisk_kernel_language_ce, "get", &_10, 27, _16$$4, _15$$4);
		zephir_check_temp_parameter(_16$$4);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, _13$$4, "__construct", NULL, 28, _14$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(_13$$4, "brisk/Vendor/View/ViewAdapter.zep", 45 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_CE_STATIC(&_17, brisk_kernel_app_ce, "getinstance", &_1, 46);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(_18);
	zephir_read_property(&_18, _17, SL("config"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(_19);
	zephir_read_property(&_19, _18, SL("view"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(_20);
	zephir_read_property(&_20, _19, SL("driver"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&driver, _20, "getvalue", NULL, 0);
	zephir_check_call_status();
	_21 = !(zephir_class_exists(driver, zephir_is_true(ZEPHIR_GLOBAL(global_false))  TSRMLS_CC));
	if (_21) {
		ZEPHIR_CALL_CE_STATIC(&_22, brisk_kernel_loader_ce, "findclass", &_23, 60, driver);
		zephir_check_call_status();
		_21 = !zephir_is_true(_22);
	}
	if (_21) {
		ZEPHIR_INIT_VAR(_24$$5);
		object_init_ex(_24$$5, brisk_exception_drivernotfoundexception_ce);
		ZEPHIR_INIT_VAR(_26$$5);
		zephir_create_array(_26$$5, 1, 0 TSRMLS_CC);
		zephir_array_fast_append(_26$$5, driver);
		ZEPHIR_INIT_VAR(_27$$5);
		ZVAL_STRING(_27$$5, "view.driver_not_found", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_CE_STATIC(&_25$$5, brisk_kernel_language_ce, "get", &_10, 27, _27$$5, _26$$5);
		zephir_check_temp_parameter(_27$$5);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, _24$$5, "__construct", NULL, 28, _25$$5);
		zephir_check_call_status();
		zephir_throw_exception_debug(_24$$5, "brisk/Vendor/View/ViewAdapter.zep", 49 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_CE_STATIC(&_28, brisk_kernel_app_ce, "getinstance", &_1, 46);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(_29);
	zephir_read_property(&_29, _28, SL("config"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(_30);
	zephir_read_property(&_30, _29, SL("view"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(_31);
	zephir_read_property(&_31, _30, SL("options"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&options, _31, "getvalue", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(instance);
	zephir_fetch_safe_class(_32, driver);
		_33 = zend_fetch_class(Z_STRVAL_P(_32), Z_STRLEN_P(_32), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	object_init_ex(instance, _33);
	if (zephir_has_constructor(instance TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, instance, "__construct", NULL, 0, options);
		zephir_check_call_status();
	}
	if (!((zephir_instance_of_ev(instance, brisk_vendor_view_viewfather_ce TSRMLS_CC)))) {
		ZEPHIR_INIT_VAR(_34$$6);
		object_init_ex(_34$$6, brisk_exception_runtimeexception_ce);
		ZEPHIR_INIT_VAR(_36$$6);
		zephir_create_array(_36$$6, 2, 0 TSRMLS_CC);
		zephir_array_fast_append(_36$$6, driver);
		ZEPHIR_INIT_VAR(_37$$6);
		ZVAL_STRING(_37$$6, "\\Brisk\\Vendor\\View\\ViewFather", 1);
		zephir_array_fast_append(_36$$6, _37$$6);
		ZEPHIR_INIT_NVAR(_37$$6);
		ZVAL_STRING(_37$$6, "view.driver_implement_error", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_CE_STATIC(&_35$$6, brisk_kernel_language_ce, "get", &_10, 27, _37$$6, _36$$6);
		zephir_check_temp_parameter(_37$$6);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, _34$$6, "__construct", NULL, 28, _35$$6);
		zephir_check_call_status();
		zephir_throw_exception_debug(_34$$6, "brisk/Vendor/View/ViewAdapter.zep", 55 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(_39);
	zephir_create_array(_39, 1, 0 TSRMLS_CC);
	zephir_array_update_string(&_39, SL("view"), &driver, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(_4);
	ZVAL_STRING(_4, "driver", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_CE_STATIC(NULL, brisk_kernel_trace_ce, "set", &_38, 12, _4, _39);
	zephir_check_temp_parameter(_4);
	zephir_check_call_status();
	RETURN_CCTOR(instance);

}


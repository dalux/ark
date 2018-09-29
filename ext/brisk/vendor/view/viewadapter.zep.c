
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
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "kernel/array.h"
#include "kernel/object.h"
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

	zend_class_entry *_11;
	zend_bool _2;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL, *_4 = NULL, *_7 = NULL, *_16 = NULL;
	zval *options = NULL, *_17, *_8$$3, *_14$$4;
	zval *driver_param = NULL, *options_param = NULL, *_0 = NULL, *_3 = NULL, *instance = NULL, *_10 = NULL, *_18, *_5$$3, *_6$$3 = NULL, *_9$$3, *_12$$4, *_13$$4 = NULL, *_15$$4 = NULL;
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


	ZEPHIR_CALL_CE_STATIC(&_0, brisk_kernel_toolkit_ce, "classdeclared", &_1, 61, driver);
	zephir_check_call_status();
	_2 = !zephir_is_true(_0);
	if (_2) {
		ZEPHIR_CALL_CE_STATIC(&_3, brisk_kernel_loader_ce, "findclass", &_4, 62, driver);
		zephir_check_call_status();
		_2 = !zephir_is_true(_3);
	}
	if (_2) {
		ZEPHIR_INIT_VAR(_5$$3);
		object_init_ex(_5$$3, brisk_exception_drivernotfoundexception_ce);
		ZEPHIR_INIT_VAR(_8$$3);
		zephir_create_array(_8$$3, 1, 0 TSRMLS_CC);
		zephir_array_fast_append(_8$$3, driver);
		ZEPHIR_INIT_VAR(_9$$3);
		ZVAL_STRING(_9$$3, "view.driver_not_found", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_CE_STATIC(&_6$$3, brisk_kernel_language_ce, "get", &_7, 27, _9$$3, _8$$3);
		zephir_check_temp_parameter(_9$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, _5$$3, "__construct", NULL, 28, _6$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(_5$$3, "brisk/Vendor/View/ViewAdapter.zep", 25 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(instance);
	zephir_fetch_safe_class(_10, driver);
		_11 = zend_fetch_class(Z_STRVAL_P(_10), Z_STRLEN_P(_10), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	object_init_ex(instance, _11);
	if (zephir_has_constructor(instance TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, instance, "__construct", NULL, 0, options);
		zephir_check_call_status();
	}
	if (!((zephir_instance_of_ev(instance, brisk_vendor_view_viewfather_ce TSRMLS_CC)))) {
		ZEPHIR_INIT_VAR(_12$$4);
		object_init_ex(_12$$4, brisk_exception_runtimeexception_ce);
		ZEPHIR_INIT_VAR(_14$$4);
		zephir_create_array(_14$$4, 2, 0 TSRMLS_CC);
		zephir_array_fast_append(_14$$4, driver);
		ZEPHIR_INIT_VAR(_15$$4);
		ZVAL_STRING(_15$$4, "\\Brisk\\Vendor\\View\\ViewFather", 1);
		zephir_array_fast_append(_14$$4, _15$$4);
		ZEPHIR_INIT_NVAR(_15$$4);
		ZVAL_STRING(_15$$4, "view.driver_implement_error", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_CE_STATIC(&_13$$4, brisk_kernel_language_ce, "get", &_7, 27, _15$$4, _14$$4);
		zephir_check_temp_parameter(_15$$4);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, _12$$4, "__construct", NULL, 28, _13$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(_12$$4, "brisk/Vendor/View/ViewAdapter.zep", 30 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(_17);
	zephir_create_array(_17, 1, 0 TSRMLS_CC);
	zephir_array_update_string(&_17, SL("view"), &driver, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(_18);
	ZVAL_STRING(_18, "driver", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_CE_STATIC(NULL, brisk_kernel_trace_ce, "set", &_16, 12, _18, _17);
	zephir_check_temp_parameter(_18);
	zephir_check_call_status();
	RETURN_CCTOR(instance);

}

/**
 * Get View driver from config
 *
 * @return ViewFather
 */
PHP_METHOD(Brisk_Vendor_View_ViewAdapter, getDriverFromConfig) {

	zval *_37, *_11$$3, *_15$$4, *_28$$5, *_34$$6;
	zend_class_entry *_31;
	zend_bool _23;
	zval *_0 = NULL, *_2, *_3 = NULL, *_4 = NULL, *_5 = NULL, *_6, *_7 = NULL, *driver = NULL, *options = NULL, *instance = NULL, *_17 = NULL, *_18, *_19 = NULL, *_20, *_21 = NULL, *_24 = NULL, *_30 = NULL, *_8$$3, *_9$$3 = NULL, *_12$$3 = NULL, *_13$$4, *_14$$4 = NULL, *_16$$4 = NULL, *_26$$5, *_27$$5 = NULL, *_29$$5, *_32$$6, *_33$$6 = NULL, *_35$$6 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL, *_10 = NULL, *_22 = NULL, *_25 = NULL, *_36 = NULL;

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
		zephir_throw_exception_debug(_8$$3, "brisk/Vendor/View/ViewAdapter.zep", 44 TSRMLS_CC);
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
		zephir_throw_exception_debug(_13$$4, "brisk/Vendor/View/ViewAdapter.zep", 46 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_CE_STATIC(&_17, brisk_kernel_app_ce, "getinstance", &_1, 46);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(_18);
	zephir_read_property(&_18, _17, SL("config"), PH_NOISY_CC);
	ZEPHIR_INIT_NVAR(_4);
	ZVAL_STRING(_4, "view/driver", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&driver, _18, "get", NULL, 0, _4);
	zephir_check_temp_parameter(_4);
	zephir_check_call_status();
	ZEPHIR_CALL_CE_STATIC(&_19, brisk_kernel_app_ce, "getinstance", &_1, 46);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(_20);
	zephir_read_property(&_20, _19, SL("config"), PH_NOISY_CC);
	ZEPHIR_INIT_NVAR(_4);
	ZVAL_STRING(_4, "view/options", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&options, _20, "get", NULL, 0, _4);
	zephir_check_temp_parameter(_4);
	zephir_check_call_status();
	ZEPHIR_CALL_CE_STATIC(&_21, brisk_kernel_toolkit_ce, "classdeclared", &_22, 61, driver);
	zephir_check_call_status();
	_23 = !zephir_is_true(_21);
	if (_23) {
		ZEPHIR_CALL_CE_STATIC(&_24, brisk_kernel_loader_ce, "findclass", &_25, 62, driver);
		zephir_check_call_status();
		_23 = !zephir_is_true(_24);
	}
	if (_23) {
		ZEPHIR_INIT_VAR(_26$$5);
		object_init_ex(_26$$5, brisk_exception_drivernotfoundexception_ce);
		ZEPHIR_INIT_VAR(_28$$5);
		zephir_create_array(_28$$5, 1, 0 TSRMLS_CC);
		zephir_array_fast_append(_28$$5, driver);
		ZEPHIR_INIT_VAR(_29$$5);
		ZVAL_STRING(_29$$5, "view.driver_not_found", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_CE_STATIC(&_27$$5, brisk_kernel_language_ce, "get", &_10, 27, _29$$5, _28$$5);
		zephir_check_temp_parameter(_29$$5);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, _26$$5, "__construct", NULL, 28, _27$$5);
		zephir_check_call_status();
		zephir_throw_exception_debug(_26$$5, "brisk/Vendor/View/ViewAdapter.zep", 52 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(instance);
	zephir_fetch_safe_class(_30, driver);
		_31 = zend_fetch_class(Z_STRVAL_P(_30), Z_STRLEN_P(_30), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	object_init_ex(instance, _31);
	if (zephir_has_constructor(instance TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, instance, "__construct", NULL, 0, options);
		zephir_check_call_status();
	}
	if (!((zephir_instance_of_ev(instance, brisk_vendor_view_viewfather_ce TSRMLS_CC)))) {
		ZEPHIR_INIT_VAR(_32$$6);
		object_init_ex(_32$$6, brisk_exception_runtimeexception_ce);
		ZEPHIR_INIT_VAR(_34$$6);
		zephir_create_array(_34$$6, 2, 0 TSRMLS_CC);
		zephir_array_fast_append(_34$$6, driver);
		ZEPHIR_INIT_VAR(_35$$6);
		ZVAL_STRING(_35$$6, "\\Brisk\\Vendor\\View\\ViewFather", 1);
		zephir_array_fast_append(_34$$6, _35$$6);
		ZEPHIR_INIT_NVAR(_35$$6);
		ZVAL_STRING(_35$$6, "view.driver_implement_error", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_CE_STATIC(&_33$$6, brisk_kernel_language_ce, "get", &_10, 27, _35$$6, _34$$6);
		zephir_check_temp_parameter(_35$$6);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, _32$$6, "__construct", NULL, 28, _33$$6);
		zephir_check_call_status();
		zephir_throw_exception_debug(_32$$6, "brisk/Vendor/View/ViewAdapter.zep", 56 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(_37);
	zephir_create_array(_37, 1, 0 TSRMLS_CC);
	zephir_array_update_string(&_37, SL("view"), &driver, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(_4);
	ZVAL_STRING(_4, "driver", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_CE_STATIC(NULL, brisk_kernel_trace_ce, "set", &_36, 12, _4, _37);
	zephir_check_temp_parameter(_4);
	zephir_check_call_status();
	RETURN_CCTOR(instance);

}


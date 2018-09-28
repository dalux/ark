
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
#include "kernel/concat.h"


ZEPHIR_INIT_CLASS(Brisk_Vendor_Db_DbAdapter) {

	ZEPHIR_REGISTER_CLASS(Brisk\\Vendor\\Db, DbAdapter, brisk, vendor_db_dbadapter, brisk_vendor_db_dbadapter_method_entry, 0);

	return SUCCESS;

}

/**
 * Get Database driver
 *
 * @param string driver
 * @param string dsn
 * @param array option
 * @return DbFather
 */
PHP_METHOD(Brisk_Vendor_Db_DbAdapter, getDriver) {

	zend_class_entry *_9;
	zend_bool _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_2 = NULL, *_5 = NULL, *_14 = NULL;
	zval *option = NULL, *_15, *_6$$3, *_12$$4;
	zval *driver_param = NULL, *dsn_param = NULL, *option_param = NULL, *_1 = NULL, *instance = NULL, *_8 = NULL, _16, _17, *_18 = NULL, *_19, *_3$$3, *_4$$3 = NULL, *_7$$3, *_10$$4, *_11$$4 = NULL, *_13$$4 = NULL;
	zval *driver = NULL, *dsn = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &driver_param, &dsn_param, &option_param);

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
	if (UNEXPECTED(Z_TYPE_P(dsn_param) != IS_STRING && Z_TYPE_P(dsn_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'dsn' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(dsn_param) == IS_STRING)) {
		zephir_get_strval(dsn, dsn_param);
	} else {
		ZEPHIR_INIT_VAR(dsn);
		ZVAL_EMPTY_STRING(dsn);
	}
	if (!option_param) {
		ZEPHIR_INIT_VAR(option);
		array_init(option);
	} else {
	option = option_param;
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
		ZVAL_STRING(_7$$3, "db.driver_not_found", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_CE_STATIC(&_4$$3, brisk_kernel_language_ce, "get", &_5, 27, _7$$3, _6$$3);
		zephir_check_temp_parameter(_7$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, _3$$3, "__construct", NULL, 28, _4$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(_3$$3, "brisk/Vendor/Db/DbAdapter.zep", 25 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(instance);
	zephir_fetch_safe_class(_8, driver);
		_9 = zend_fetch_class(Z_STRVAL_P(_8), Z_STRLEN_P(_8), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	object_init_ex(instance, _9);
	if (zephir_has_constructor(instance TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, instance, "__construct", NULL, 0, dsn, option);
		zephir_check_call_status();
	}
	if (!((zephir_instance_of_ev(instance, brisk_vendor_db_dbfather_ce TSRMLS_CC)))) {
		ZEPHIR_INIT_VAR(_10$$4);
		object_init_ex(_10$$4, brisk_exception_runtimeexception_ce);
		ZEPHIR_INIT_VAR(_12$$4);
		zephir_create_array(_12$$4, 2, 0 TSRMLS_CC);
		zephir_array_fast_append(_12$$4, driver);
		ZEPHIR_INIT_VAR(_13$$4);
		ZVAL_STRING(_13$$4, "\\Brisk\\Vendor\\Db\\DbFather", 1);
		zephir_array_fast_append(_12$$4, _13$$4);
		ZEPHIR_INIT_NVAR(_13$$4);
		ZVAL_STRING(_13$$4, "db.driver_implement_error", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_CE_STATIC(&_11$$4, brisk_kernel_language_ce, "get", &_5, 27, _13$$4, _12$$4);
		zephir_check_temp_parameter(_13$$4);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, _10$$4, "__construct", NULL, 28, _11$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(_10$$4, "brisk/Vendor/Db/DbAdapter.zep", 30 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(_15);
	zephir_create_array(_15, 1, 0 TSRMLS_CC);
	ZEPHIR_SINIT_VAR(_16);
	ZVAL_STRING(&_16, "%s[%s]", 0);
	ZEPHIR_SINIT_VAR(_17);
	ZVAL_STRING(&_17, "-", 0);
	ZEPHIR_CALL_FUNCTION(&_18, "sprintf", NULL, 40, &_16, &_17, driver);
	zephir_check_call_status();
	zephir_array_update_string(&_15, SL("database"), &_18, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(_19);
	ZVAL_STRING(_19, "driver", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_CE_STATIC(NULL, brisk_kernel_trace_ce, "set", &_14, 12, _19, _15);
	zephir_check_temp_parameter(_19);
	zephir_check_call_status();
	RETURN_CCTOR(instance);

}

/**
 * Get Database driver from config
 *
 * @param string name
 * @return DbFather
 */
PHP_METHOD(Brisk_Vendor_Db_DbAdapter, getDriverFromConfig) {

	zval *_54, *_16$$3, *_20$$4, *_25$$5, *_43$$6, *_51$$7;
	zend_class_entry *_46;
	zend_bool _38;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_2 = NULL, *_15 = NULL, *_40 = NULL, *_53 = NULL;
	zval *name_param = NULL, *path = NULL, *_1 = NULL, *_3, *_4 = NULL, *_5 = NULL, *_6, *_7 = NULL, *_8, *_9 = NULL, *_10, *_11 = NULL, *_12, *driver = NULL, *_28 = NULL, *_29, *_30, *_31, *_32, *options = NULL, *_33 = NULL, *_34, *_35, *_36, *_37, *_39 = NULL, *instance = NULL, *_45 = NULL, *_47, *_48, _55, *_56 = NULL, *_57, *_13$$3, *_14$$3 = NULL, *_17$$3, *_18$$4, *_19$$4 = NULL, *_21$$4, *_22$$4, *_23$$5, *_24$$5 = NULL, *_26$$5, *_27$$5, *_41$$6, *_42$$6 = NULL, *_44$$6, *_49$$7, *_50$$7 = NULL, *_52$$7 = NULL;
	zval *name = NULL, *_0;

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


	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_CONCAT_SV(_0, "database/", name);
	ZEPHIR_CPY_WRT(path, _0);
	ZEPHIR_CALL_CE_STATIC(&_1, brisk_kernel_app_ce, "getinstance", &_2, 46);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(_3);
	zephir_read_property(&_3, _1, SL("config"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_4, _3, "haskey", NULL, 0, path);
	zephir_check_call_status();
	ZEPHIR_CALL_CE_STATIC(&_5, brisk_kernel_app_ce, "getinstance", &_2, 46);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(_6);
	zephir_read_property(&_6, _5, SL("config"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_8);
	ZEPHIR_CONCAT_VS(_8, path, "/driver");
	ZEPHIR_CALL_METHOD(&_7, _6, "haskey", NULL, 0, _8);
	zephir_check_call_status();
	ZEPHIR_CALL_CE_STATIC(&_9, brisk_kernel_app_ce, "getinstance", &_2, 46);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(_10);
	zephir_read_property(&_10, _9, SL("config"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_12);
	ZEPHIR_CONCAT_VS(_12, path, "/options/dsn");
	ZEPHIR_CALL_METHOD(&_11, _10, "haskey", NULL, 0, _12);
	zephir_check_call_status();
	if (!zephir_is_true(_4)) {
		ZEPHIR_INIT_VAR(_13$$3);
		object_init_ex(_13$$3, brisk_exception_configurationexception_ce);
		ZEPHIR_INIT_VAR(_16$$3);
		zephir_create_array(_16$$3, 1, 0 TSRMLS_CC);
		zephir_array_fast_append(_16$$3, path);
		ZEPHIR_INIT_VAR(_17$$3);
		ZVAL_STRING(_17$$3, "core.config_not_found", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_CE_STATIC(&_14$$3, brisk_kernel_language_ce, "get", &_15, 27, _17$$3, _16$$3);
		zephir_check_temp_parameter(_17$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, _13$$3, "__construct", NULL, 28, _14$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(_13$$3, "brisk/Vendor/Db/DbAdapter.zep", 47 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	} else if (!zephir_is_true(_7)) {
		ZEPHIR_INIT_VAR(_18$$4);
		object_init_ex(_18$$4, brisk_exception_configurationexception_ce);
		ZEPHIR_INIT_VAR(_20$$4);
		zephir_create_array(_20$$4, 1, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_21$$4);
		ZEPHIR_CONCAT_VS(_21$$4, path, "/driver");
		zephir_array_fast_append(_20$$4, _21$$4);
		ZEPHIR_INIT_VAR(_22$$4);
		ZVAL_STRING(_22$$4, "core.config_not_found", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_CE_STATIC(&_19$$4, brisk_kernel_language_ce, "get", &_15, 27, _22$$4, _20$$4);
		zephir_check_temp_parameter(_22$$4);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, _18$$4, "__construct", NULL, 28, _19$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(_18$$4, "brisk/Vendor/Db/DbAdapter.zep", 49 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	} else if (!zephir_is_true(_11)) {
		ZEPHIR_INIT_VAR(_23$$5);
		object_init_ex(_23$$5, brisk_exception_configurationexception_ce);
		ZEPHIR_INIT_VAR(_25$$5);
		zephir_create_array(_25$$5, 1, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_26$$5);
		ZEPHIR_CONCAT_VS(_26$$5, path, "/options/dsn");
		zephir_array_fast_append(_25$$5, _26$$5);
		ZEPHIR_INIT_VAR(_27$$5);
		ZVAL_STRING(_27$$5, "core.config_not_found", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_CE_STATIC(&_24$$5, brisk_kernel_language_ce, "get", &_15, 27, _27$$5, _25$$5);
		zephir_check_temp_parameter(_27$$5);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, _23$$5, "__construct", NULL, 28, _24$$5);
		zephir_check_call_status();
		zephir_throw_exception_debug(_23$$5, "brisk/Vendor/Db/DbAdapter.zep", 51 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_CE_STATIC(&_28, brisk_kernel_app_ce, "getinstance", &_2, 46);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(_29);
	zephir_read_property(&_29, _28, SL("config"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(_30);
	zephir_read_property(&_30, _29, SL("database"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(_31);
	zephir_read_property_zval(&_31, _30, name, PH_NOISY_CC);
	ZEPHIR_OBS_VAR(_32);
	zephir_read_property(&_32, _31, SL("driver"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&driver, _32, "getvalue", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_CE_STATIC(&_33, brisk_kernel_app_ce, "getinstance", &_2, 46);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(_34);
	zephir_read_property(&_34, _33, SL("config"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(_35);
	zephir_read_property(&_35, _34, SL("database"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(_36);
	zephir_read_property_zval(&_36, _35, name, PH_NOISY_CC);
	ZEPHIR_OBS_VAR(_37);
	zephir_read_property(&_37, _36, SL("options"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&options, _37, "getvalue", NULL, 0);
	zephir_check_call_status();
	_38 = !(zephir_class_exists(driver, zephir_is_true(ZEPHIR_GLOBAL(global_false))  TSRMLS_CC));
	if (_38) {
		ZEPHIR_CALL_CE_STATIC(&_39, brisk_kernel_loader_ce, "findclass", &_40, 60, driver);
		zephir_check_call_status();
		_38 = !zephir_is_true(_39);
	}
	if (_38) {
		ZEPHIR_INIT_VAR(_41$$6);
		object_init_ex(_41$$6, brisk_exception_drivernotfoundexception_ce);
		ZEPHIR_INIT_VAR(_43$$6);
		zephir_create_array(_43$$6, 1, 0 TSRMLS_CC);
		zephir_array_fast_append(_43$$6, driver);
		ZEPHIR_INIT_VAR(_44$$6);
		ZVAL_STRING(_44$$6, "db.driver_not_found", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_CE_STATIC(&_42$$6, brisk_kernel_language_ce, "get", &_15, 27, _44$$6, _43$$6);
		zephir_check_temp_parameter(_44$$6);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, _41$$6, "__construct", NULL, 28, _42$$6);
		zephir_check_call_status();
		zephir_throw_exception_debug(_41$$6, "brisk/Vendor/Db/DbAdapter.zep", 56 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(instance);
	zephir_fetch_safe_class(_45, driver);
		_46 = zend_fetch_class(Z_STRVAL_P(_45), Z_STRLEN_P(_45), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	object_init_ex(instance, _46);
	if (zephir_has_constructor(instance TSRMLS_CC)) {
		zephir_array_fetch_string(&_47, options, SL("dsn"), PH_NOISY | PH_READONLY, "brisk/Vendor/Db/DbAdapter.zep", 59 TSRMLS_CC);
		zephir_array_fetch_string(&_48, options, SL("option"), PH_NOISY | PH_READONLY, "brisk/Vendor/Db/DbAdapter.zep", 59 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(NULL, instance, "__construct", NULL, 0, _47, _48);
		zephir_check_call_status();
	}
	if (!((zephir_instance_of_ev(instance, brisk_vendor_db_dbfather_ce TSRMLS_CC)))) {
		ZEPHIR_INIT_VAR(_49$$7);
		object_init_ex(_49$$7, brisk_exception_runtimeexception_ce);
		ZEPHIR_INIT_VAR(_51$$7);
		zephir_create_array(_51$$7, 2, 0 TSRMLS_CC);
		zephir_array_fast_append(_51$$7, driver);
		ZEPHIR_INIT_VAR(_52$$7);
		ZVAL_STRING(_52$$7, "\\Brisk\\Vendor\\Db\\DbFather", 1);
		zephir_array_fast_append(_51$$7, _52$$7);
		ZEPHIR_INIT_NVAR(_52$$7);
		ZVAL_STRING(_52$$7, "db.driver_implement_error", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_CE_STATIC(&_50$$7, brisk_kernel_language_ce, "get", &_15, 27, _52$$7, _51$$7);
		zephir_check_temp_parameter(_52$$7);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, _49$$7, "__construct", NULL, 28, _50$$7);
		zephir_check_call_status();
		zephir_throw_exception_debug(_49$$7, "brisk/Vendor/Db/DbAdapter.zep", 61 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(_54);
	zephir_create_array(_54, 1, 0 TSRMLS_CC);
	ZEPHIR_SINIT_VAR(_55);
	ZVAL_STRING(&_55, "%s[%s]", 0);
	ZEPHIR_CALL_FUNCTION(&_56, "sprintf", NULL, 40, &_55, name, driver);
	zephir_check_call_status();
	zephir_array_update_string(&_54, SL("database"), &_56, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(_57);
	ZVAL_STRING(_57, "driver", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_CE_STATIC(NULL, brisk_kernel_trace_ce, "set", &_53, 12, _57, _54);
	zephir_check_temp_parameter(_57);
	zephir_check_call_status();
	RETURN_CCTOR(instance);

}


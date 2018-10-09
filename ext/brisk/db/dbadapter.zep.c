
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


ZEPHIR_INIT_CLASS(Brisk_Db_DbAdapter) {

	ZEPHIR_REGISTER_CLASS(Brisk\\Db, DbAdapter, brisk, db_dbadapter, brisk_db_dbadapter_method_entry, 0);

	return SUCCESS;

}

/**
 * Get Database driver from config
 *
 * @param string name
 * @return DbFather
 */
PHP_METHOD(Brisk_Db_DbAdapter, getDriverFromConfig) {

	zval *_52, *_16$$3, *_20$$4, *_25$$5, *_41$$6, *_49$$7;
	zend_class_entry *_44;
	zend_bool _36;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_2 = NULL, *_15 = NULL, *_35 = NULL, *_38 = NULL, *_51 = NULL;
	zval *name_param = NULL, *path = NULL, *_1 = NULL, *_3, *_4 = NULL, *_5 = NULL, *_6, *_7 = NULL, *_8, *_9 = NULL, *_10, *_11 = NULL, *_12, *driver = NULL, *option = NULL, *instance = NULL, *_28 = NULL, *_29, *_30, *_31 = NULL, *_32, *_33, *_34 = NULL, *_37 = NULL, *_43 = NULL, *_45, *_46, _53, *_54 = NULL, *_55, *_13$$3, *_14$$3 = NULL, *_17$$3, *_18$$4, *_19$$4 = NULL, *_21$$4, *_22$$4, *_23$$5, *_24$$5 = NULL, *_26$$5, *_27$$5, *_39$$6, *_40$$6 = NULL, *_42$$6, *_47$$7, *_48$$7 = NULL, *_50$$7 = NULL;
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
	ZEPHIR_CALL_CE_STATIC(&_1, brisk_kernel_app_ce, "getinstance", &_2, 21);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(_3);
	zephir_read_property(&_3, _1, SL("config"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_4, _3, "haskey", NULL, 0, path);
	zephir_check_call_status();
	ZEPHIR_CALL_CE_STATIC(&_5, brisk_kernel_app_ce, "getinstance", &_2, 21);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(_6);
	zephir_read_property(&_6, _5, SL("config"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_8);
	ZEPHIR_CONCAT_VS(_8, path, "/driver");
	ZEPHIR_CALL_METHOD(&_7, _6, "haskey", NULL, 0, _8);
	zephir_check_call_status();
	ZEPHIR_CALL_CE_STATIC(&_9, brisk_kernel_app_ce, "getinstance", &_2, 21);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(_10);
	zephir_read_property(&_10, _9, SL("config"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_12);
	ZEPHIR_CONCAT_VS(_12, path, "/option/config");
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
		ZEPHIR_CALL_CE_STATIC(&_14$$3, brisk_kernel_language_ce, "get", &_15, 12, _17$$3, _16$$3);
		zephir_check_temp_parameter(_17$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, _13$$3, "__construct", NULL, 7, _14$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(_13$$3, "brisk/Db/DbAdapter.zep", 26 TSRMLS_CC);
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
		ZEPHIR_CALL_CE_STATIC(&_19$$4, brisk_kernel_language_ce, "get", &_15, 12, _22$$4, _20$$4);
		zephir_check_temp_parameter(_22$$4);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, _18$$4, "__construct", NULL, 7, _19$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(_18$$4, "brisk/Db/DbAdapter.zep", 28 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	} else if (!zephir_is_true(_11)) {
		ZEPHIR_INIT_VAR(_23$$5);
		object_init_ex(_23$$5, brisk_exception_configurationexception_ce);
		ZEPHIR_INIT_VAR(_25$$5);
		zephir_create_array(_25$$5, 1, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_26$$5);
		ZEPHIR_CONCAT_VS(_26$$5, path, "/option/config");
		zephir_array_fast_append(_25$$5, _26$$5);
		ZEPHIR_INIT_VAR(_27$$5);
		ZVAL_STRING(_27$$5, "core.config_not_found", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_CE_STATIC(&_24$$5, brisk_kernel_language_ce, "get", &_15, 12, _27$$5, _25$$5);
		zephir_check_temp_parameter(_27$$5);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, _23$$5, "__construct", NULL, 7, _24$$5);
		zephir_check_call_status();
		zephir_throw_exception_debug(_23$$5, "brisk/Db/DbAdapter.zep", 30 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_CE_STATIC(&_28, brisk_kernel_app_ce, "getinstance", &_2, 21);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(_29);
	zephir_read_property(&_29, _28, SL("config"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_30);
	ZEPHIR_CONCAT_VS(_30, path, "/driver");
	ZEPHIR_CALL_METHOD(&driver, _29, "get", NULL, 0, _30);
	zephir_check_call_status();
	ZEPHIR_CALL_CE_STATIC(&_31, brisk_kernel_app_ce, "getinstance", &_2, 21);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(_32);
	zephir_read_property(&_32, _31, SL("config"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_33);
	ZEPHIR_CONCAT_VS(_33, path, "/option");
	ZEPHIR_CALL_METHOD(&option, _32, "get", NULL, 0, _33);
	zephir_check_call_status();
	ZEPHIR_CALL_CE_STATIC(&_34, brisk_kernel_toolkit_ce, "classdeclared", &_35, 22, driver);
	zephir_check_call_status();
	_36 = !zephir_is_true(_34);
	if (_36) {
		ZEPHIR_CALL_CE_STATIC(&_37, brisk_kernel_loader_ce, "findclass", &_38, 23, driver);
		zephir_check_call_status();
		_36 = !zephir_is_true(_37);
	}
	if (_36) {
		ZEPHIR_INIT_VAR(_39$$6);
		object_init_ex(_39$$6, brisk_exception_drivernotfoundexception_ce);
		ZEPHIR_INIT_VAR(_41$$6);
		zephir_create_array(_41$$6, 1, 0 TSRMLS_CC);
		zephir_array_fast_append(_41$$6, driver);
		ZEPHIR_INIT_VAR(_42$$6);
		ZVAL_STRING(_42$$6, "db.driver_not_found", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_CE_STATIC(&_40$$6, brisk_kernel_language_ce, "get", &_15, 12, _42$$6, _41$$6);
		zephir_check_temp_parameter(_42$$6);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, _39$$6, "__construct", NULL, 7, _40$$6);
		zephir_check_call_status();
		zephir_throw_exception_debug(_39$$6, "brisk/Db/DbAdapter.zep", 36 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(instance);
	zephir_fetch_safe_class(_43, driver);
		_44 = zend_fetch_class(Z_STRVAL_P(_43), Z_STRLEN_P(_43), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	object_init_ex(instance, _44);
	if (zephir_has_constructor(instance TSRMLS_CC)) {
		zephir_array_fetch_string(&_45, option, SL("config"), PH_NOISY | PH_READONLY, "brisk/Db/DbAdapter.zep", 38 TSRMLS_CC);
		zephir_array_fetch_string(&_46, option, SL("setting"), PH_NOISY | PH_READONLY, "brisk/Db/DbAdapter.zep", 38 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(NULL, instance, "__construct", NULL, 0, _45, _46);
		zephir_check_call_status();
	}
	if (!((zephir_instance_of_ev(instance, brisk_db_dbfather_ce TSRMLS_CC)))) {
		ZEPHIR_INIT_VAR(_47$$7);
		object_init_ex(_47$$7, brisk_exception_runtimeexception_ce);
		ZEPHIR_INIT_VAR(_49$$7);
		zephir_create_array(_49$$7, 2, 0 TSRMLS_CC);
		zephir_array_fast_append(_49$$7, driver);
		ZEPHIR_INIT_VAR(_50$$7);
		ZVAL_STRING(_50$$7, "\\Brisk\\Db\\DbFather", 1);
		zephir_array_fast_append(_49$$7, _50$$7);
		ZEPHIR_INIT_NVAR(_50$$7);
		ZVAL_STRING(_50$$7, "core.class_extends_error", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_CE_STATIC(&_48$$7, brisk_kernel_language_ce, "get", &_15, 12, _50$$7, _49$$7);
		zephir_check_temp_parameter(_50$$7);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, _47$$7, "__construct", NULL, 7, _48$$7);
		zephir_check_call_status();
		zephir_throw_exception_debug(_47$$7, "brisk/Db/DbAdapter.zep", 40 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(_52);
	zephir_create_array(_52, 1, 0 TSRMLS_CC);
	ZEPHIR_SINIT_VAR(_53);
	ZVAL_STRING(&_53, "%s[%s]", 0);
	ZEPHIR_CALL_FUNCTION(&_54, "sprintf", NULL, 11, &_53, name, driver);
	zephir_check_call_status();
	zephir_array_update_string(&_52, SL("database"), &_54, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(_55);
	ZVAL_STRING(_55, "driver", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_CE_STATIC(NULL, brisk_kernel_trace_ce, "set", &_51, 9, _55, _52);
	zephir_check_temp_parameter(_55);
	zephir_check_call_status();
	RETURN_CCTOR(instance);

}


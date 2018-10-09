
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
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "kernel/array.h"


ZEPHIR_INIT_CLASS(Brisk_Session_SessionAdapter) {

	ZEPHIR_REGISTER_CLASS(Brisk\\Session, SessionAdapter, brisk, session_sessionadapter, brisk_session_sessionadapter_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Brisk_Session_SessionAdapter, getDriverFromConfig) {

	zval *_34, *_8$$3, *_25$$5, *_31$$6;
	zend_class_entry *_28;
	zend_bool _20;
	zval *_0 = NULL, *_2, *_3 = NULL, *_4 = NULL, *driver = NULL, *option = NULL, *instance = NULL, *_10 = NULL, *_11, *_12 = NULL, *_13, *_14 = NULL, *_18 = NULL, *_21 = NULL, *_27 = NULL, *_5$$3, *_6$$3 = NULL, *_9$$3 = NULL, *_15$$4 = NULL, *_16$$4, *_17$$4, *_23$$5, *_24$$5 = NULL, *_26$$5, *_29$$6, *_30$$6 = NULL, *_32$$6 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL, *_7 = NULL, *_19 = NULL, *_22 = NULL, *_33 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_CE_STATIC(&_0, brisk_kernel_app_ce, "getinstance", &_1, 21);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(_2);
	zephir_read_property(&_2, _0, SL("config"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_4);
	ZVAL_STRING(_4, "session/driver", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_3, _2, "haskey", NULL, 0, _4);
	zephir_check_temp_parameter(_4);
	zephir_check_call_status();
	if (!zephir_is_true(_3)) {
		ZEPHIR_INIT_VAR(_5$$3);
		object_init_ex(_5$$3, brisk_exception_configurationexception_ce);
		ZEPHIR_INIT_VAR(_8$$3);
		zephir_create_array(_8$$3, 1, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_9$$3);
		ZVAL_STRING(_9$$3, "session/driver", 1);
		zephir_array_fast_append(_8$$3, _9$$3);
		ZEPHIR_INIT_NVAR(_9$$3);
		ZVAL_STRING(_9$$3, "core.config_not_found", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_CE_STATIC(&_6$$3, brisk_kernel_language_ce, "get", &_7, 12, _9$$3, _8$$3);
		zephir_check_temp_parameter(_9$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, _5$$3, "__construct", NULL, 7, _6$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(_5$$3, "brisk/Session/SessionAdapter.zep", 18 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_CE_STATIC(&_10, brisk_kernel_app_ce, "getinstance", &_1, 21);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(_11);
	zephir_read_property(&_11, _10, SL("config"), PH_NOISY_CC);
	ZEPHIR_INIT_NVAR(_4);
	ZVAL_STRING(_4, "session/driver", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&driver, _11, "get", NULL, 0, _4);
	zephir_check_temp_parameter(_4);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(option);
	array_init(option);
	ZEPHIR_CALL_CE_STATIC(&_12, brisk_kernel_app_ce, "getinstance", &_1, 21);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(_13);
	zephir_read_property(&_13, _12, SL("config"), PH_NOISY_CC);
	ZEPHIR_INIT_NVAR(_4);
	ZVAL_STRING(_4, "session/option", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_14, _13, "haskey", NULL, 0, _4);
	zephir_check_temp_parameter(_4);
	zephir_check_call_status();
	if (zephir_is_true(_14)) {
		ZEPHIR_CALL_CE_STATIC(&_15$$4, brisk_kernel_app_ce, "getinstance", &_1, 21);
		zephir_check_call_status();
		ZEPHIR_OBS_VAR(_16$$4);
		zephir_read_property(&_16$$4, _15$$4, SL("config"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_17$$4);
		ZVAL_STRING(_17$$4, "session/option", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&option, _16$$4, "get", NULL, 0, _17$$4);
		zephir_check_temp_parameter(_17$$4);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_CE_STATIC(&_18, brisk_kernel_toolkit_ce, "classdeclared", &_19, 22, driver);
	zephir_check_call_status();
	_20 = !zephir_is_true(_18);
	if (_20) {
		ZEPHIR_CALL_CE_STATIC(&_21, brisk_kernel_loader_ce, "findclass", &_22, 23, driver);
		zephir_check_call_status();
		_20 = !zephir_is_true(_21);
	}
	if (_20) {
		ZEPHIR_INIT_VAR(_23$$5);
		object_init_ex(_23$$5, brisk_exception_drivernotfoundexception_ce);
		ZEPHIR_INIT_VAR(_25$$5);
		zephir_create_array(_25$$5, 1, 0 TSRMLS_CC);
		zephir_array_fast_append(_25$$5, driver);
		ZEPHIR_INIT_VAR(_26$$5);
		ZVAL_STRING(_26$$5, "sess.driver_not_found", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_CE_STATIC(&_24$$5, brisk_kernel_language_ce, "get", &_7, 12, _26$$5, _25$$5);
		zephir_check_temp_parameter(_26$$5);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, _23$$5, "__construct", NULL, 7, _24$$5);
		zephir_check_call_status();
		zephir_throw_exception_debug(_23$$5, "brisk/Session/SessionAdapter.zep", 27 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(instance);
	zephir_fetch_safe_class(_27, driver);
		_28 = zend_fetch_class(Z_STRVAL_P(_27), Z_STRLEN_P(_27), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	object_init_ex(instance, _28);
	if (zephir_has_constructor(instance TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, instance, "__construct", NULL, 0, option);
		zephir_check_call_status();
	}
	if (!((zephir_instance_of_ev(instance, brisk_session_sessionfather_ce TSRMLS_CC)))) {
		ZEPHIR_INIT_VAR(_29$$6);
		object_init_ex(_29$$6, brisk_exception_runtimeexception_ce);
		ZEPHIR_INIT_VAR(_31$$6);
		zephir_create_array(_31$$6, 2, 0 TSRMLS_CC);
		zephir_array_fast_append(_31$$6, driver);
		ZEPHIR_INIT_VAR(_32$$6);
		ZVAL_STRING(_32$$6, "\\Brisk\\Session\\SessionFather", 1);
		zephir_array_fast_append(_31$$6, _32$$6);
		ZEPHIR_INIT_NVAR(_32$$6);
		ZVAL_STRING(_32$$6, "core.class_extends_error", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_CE_STATIC(&_30$$6, brisk_kernel_language_ce, "get", &_7, 12, _32$$6, _31$$6);
		zephir_check_temp_parameter(_32$$6);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, _29$$6, "__construct", NULL, 7, _30$$6);
		zephir_check_call_status();
		zephir_throw_exception_debug(_29$$6, "brisk/Session/SessionAdapter.zep", 31 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(_34);
	zephir_create_array(_34, 1, 0 TSRMLS_CC);
	zephir_array_update_string(&_34, SL("session"), &driver, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(_4);
	ZVAL_STRING(_4, "driver", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_CE_STATIC(NULL, brisk_kernel_trace_ce, "set", &_33, 9, _4, _34);
	zephir_check_temp_parameter(_4);
	zephir_check_call_status();
	RETURN_CCTOR(instance);

}


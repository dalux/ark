
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


ZEPHIR_INIT_CLASS(Brisk_Router_RouterAdapter) {

	ZEPHIR_REGISTER_CLASS(Brisk\\Router, RouterAdapter, brisk, router_routeradapter, brisk_router_routeradapter_method_entry, 0);

	return SUCCESS;

}

/**
 * Get router driver
 *
 * @return RouterFather
 */
PHP_METHOD(Brisk_Router_RouterAdapter, getDriverFromConfig) {

	zval *_28, *_8$$3, *_19$$4, *_25$$5;
	zend_class_entry *_22;
	zend_bool _14;
	zval *_0 = NULL, *_2, *_3 = NULL, *_4 = NULL, *driver = NULL, *instance = NULL, *_10 = NULL, *_11, *_12 = NULL, *_15 = NULL, *_21 = NULL, *_5$$3, *_6$$3 = NULL, *_9$$3 = NULL, *_17$$4, *_18$$4 = NULL, *_20$$4, *_23$$5, *_24$$5 = NULL, *_26$$5 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL, *_7 = NULL, *_13 = NULL, *_16 = NULL, *_27 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_CE_STATIC(&_0, brisk_kernel_app_ce, "getinstance", &_1, 21);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(_2);
	zephir_read_property(&_2, _0, SL("config"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_4);
	ZVAL_STRING(_4, "router/driver", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_3, _2, "haskey", NULL, 0, _4);
	zephir_check_temp_parameter(_4);
	zephir_check_call_status();
	if (!zephir_is_true(_3)) {
		ZEPHIR_INIT_VAR(_5$$3);
		object_init_ex(_5$$3, brisk_exception_configurationexception_ce);
		ZEPHIR_INIT_VAR(_8$$3);
		zephir_create_array(_8$$3, 1, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_9$$3);
		ZVAL_STRING(_9$$3, "router/driver", 1);
		zephir_array_fast_append(_8$$3, _9$$3);
		ZEPHIR_INIT_NVAR(_9$$3);
		ZVAL_STRING(_9$$3, "core.config_not_found", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_CE_STATIC(&_6$$3, brisk_kernel_language_ce, "get", &_7, 12, _9$$3, _8$$3);
		zephir_check_temp_parameter(_9$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, _5$$3, "__construct", NULL, 7, _6$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(_5$$3, "brisk/Router/RouterAdapter.zep", 23 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_CE_STATIC(&_10, brisk_kernel_app_ce, "getinstance", &_1, 21);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(_11);
	zephir_read_property(&_11, _10, SL("config"), PH_NOISY_CC);
	ZEPHIR_INIT_NVAR(_4);
	ZVAL_STRING(_4, "router/driver", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&driver, _11, "get", NULL, 0, _4);
	zephir_check_temp_parameter(_4);
	zephir_check_call_status();
	ZEPHIR_CALL_CE_STATIC(&_12, brisk_kernel_toolkit_ce, "classdeclared", &_13, 22, driver);
	zephir_check_call_status();
	_14 = !zephir_is_true(_12);
	if (_14) {
		ZEPHIR_CALL_CE_STATIC(&_15, brisk_kernel_loader_ce, "findclass", &_16, 23, driver);
		zephir_check_call_status();
		_14 = !zephir_is_true(_15);
	}
	if (_14) {
		ZEPHIR_INIT_VAR(_17$$4);
		object_init_ex(_17$$4, brisk_exception_drivernotfoundexception_ce);
		ZEPHIR_INIT_VAR(_19$$4);
		zephir_create_array(_19$$4, 1, 0 TSRMLS_CC);
		zephir_array_fast_append(_19$$4, driver);
		ZEPHIR_INIT_VAR(_20$$4);
		ZVAL_STRING(_20$$4, "router.driver_not_found", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_CE_STATIC(&_18$$4, brisk_kernel_language_ce, "get", &_7, 12, _20$$4, _19$$4);
		zephir_check_temp_parameter(_20$$4);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, _17$$4, "__construct", NULL, 7, _18$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(_17$$4, "brisk/Router/RouterAdapter.zep", 28 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(instance);
	zephir_fetch_safe_class(_21, driver);
		_22 = zend_fetch_class(Z_STRVAL_P(_21), Z_STRLEN_P(_21), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	object_init_ex(instance, _22);
	if (zephir_has_constructor(instance TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, instance, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	if (!((zephir_instance_of_ev(instance, brisk_router_routerfather_ce TSRMLS_CC)))) {
		ZEPHIR_INIT_VAR(_23$$5);
		object_init_ex(_23$$5, brisk_exception_routerexception_ce);
		ZEPHIR_INIT_VAR(_25$$5);
		zephir_create_array(_25$$5, 2, 0 TSRMLS_CC);
		zephir_array_fast_append(_25$$5, driver);
		ZEPHIR_INIT_VAR(_26$$5);
		ZVAL_STRING(_26$$5, "\\Brisk\\Router\\RouterFather", 1);
		zephir_array_fast_append(_25$$5, _26$$5);
		ZEPHIR_INIT_NVAR(_26$$5);
		ZVAL_STRING(_26$$5, "core.class_extends_error", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_CE_STATIC(&_24$$5, brisk_kernel_language_ce, "get", &_7, 12, _26$$5, _25$$5);
		zephir_check_temp_parameter(_26$$5);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, _23$$5, "__construct", NULL, 7, _24$$5);
		zephir_check_call_status();
		zephir_throw_exception_debug(_23$$5, "brisk/Router/RouterAdapter.zep", 32 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(_28);
	zephir_create_array(_28, 1, 0 TSRMLS_CC);
	zephir_array_update_string(&_28, SL("router"), &driver, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(_4);
	ZVAL_STRING(_4, "driver", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_CE_STATIC(NULL, brisk_kernel_trace_ce, "set", &_27, 9, _4, _28);
	zephir_check_temp_parameter(_4);
	zephir_check_call_status();
	RETURN_CCTOR(instance);

}


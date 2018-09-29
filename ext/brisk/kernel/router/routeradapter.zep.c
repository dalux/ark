
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
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "kernel/array.h"


ZEPHIR_INIT_CLASS(Brisk_Kernel_Router_RouterAdapter) {

	ZEPHIR_REGISTER_CLASS(Brisk\\Kernel\\Router, RouterAdapter, brisk, kernel_router_routeradapter, brisk_kernel_router_routeradapter_method_entry, 0);

	return SUCCESS;

}

/**
 * Get router driver
 *
 * @return RouterFather
 */
PHP_METHOD(Brisk_Kernel_Router_RouterAdapter, getDriver) {

	zval *_35, *_11$$3, *_15$$4, *_26$$5, *_32$$6;
	zend_class_entry *_29;
	zend_bool _21;
	zval *_0 = NULL, *_2, *_3 = NULL, *_4 = NULL, *_5 = NULL, *_6, *_7 = NULL, *driver = NULL, *instance = NULL, *_17 = NULL, *_18, *_19 = NULL, *_22 = NULL, *_28 = NULL, *_8$$3, *_9$$3 = NULL, *_12$$3 = NULL, *_13$$4, *_14$$4 = NULL, *_16$$4 = NULL, *_24$$5, *_25$$5 = NULL, *_27$$5, *_30$$6, *_31$$6 = NULL, *_33$$6 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL, *_10 = NULL, *_20 = NULL, *_23 = NULL, *_34 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_CE_STATIC(&_0, brisk_kernel_app_ce, "getinstance", &_1, 46);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(_2);
	zephir_read_property(&_2, _0, SL("config"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_4);
	ZVAL_STRING(_4, "router/driver", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_3, _2, "haskey", NULL, 0, _4);
	zephir_check_temp_parameter(_4);
	zephir_check_call_status();
	ZEPHIR_CALL_CE_STATIC(&_5, brisk_kernel_app_ce, "getinstance", &_1, 46);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(_6);
	zephir_read_property(&_6, _5, SL("config"), PH_NOISY_CC);
	ZEPHIR_INIT_NVAR(_4);
	ZVAL_STRING(_4, "router/options/base_namespace", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_7, _6, "haskey", NULL, 0, _4);
	zephir_check_temp_parameter(_4);
	zephir_check_call_status();
	if (!zephir_is_true(_3)) {
		ZEPHIR_INIT_VAR(_8$$3);
		object_init_ex(_8$$3, brisk_exception_configurationexception_ce);
		ZEPHIR_INIT_VAR(_11$$3);
		zephir_create_array(_11$$3, 1, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_12$$3);
		ZVAL_STRING(_12$$3, "router/driver", 1);
		zephir_array_fast_append(_11$$3, _12$$3);
		ZEPHIR_INIT_NVAR(_12$$3);
		ZVAL_STRING(_12$$3, "core.config_not_found", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_CE_STATIC(&_9$$3, brisk_kernel_language_ce, "get", &_10, 27, _12$$3, _11$$3);
		zephir_check_temp_parameter(_12$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, _8$$3, "__construct", NULL, 28, _9$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(_8$$3, "brisk/Kernel/Router/RouterAdapter.zep", 23 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	} else if (!zephir_is_true(_7)) {
		ZEPHIR_INIT_VAR(_13$$4);
		object_init_ex(_13$$4, brisk_exception_configurationexception_ce);
		ZEPHIR_INIT_VAR(_15$$4);
		zephir_create_array(_15$$4, 1, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_16$$4);
		ZVAL_STRING(_16$$4, "router/options/base_namespace", 1);
		zephir_array_fast_append(_15$$4, _16$$4);
		ZEPHIR_INIT_NVAR(_16$$4);
		ZVAL_STRING(_16$$4, "core.config_not_found", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_CE_STATIC(&_14$$4, brisk_kernel_language_ce, "get", &_10, 27, _16$$4, _15$$4);
		zephir_check_temp_parameter(_16$$4);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, _13$$4, "__construct", NULL, 28, _14$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(_13$$4, "brisk/Kernel/Router/RouterAdapter.zep", 25 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_CE_STATIC(&_17, brisk_kernel_app_ce, "getinstance", &_1, 46);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(_18);
	zephir_read_property(&_18, _17, SL("config"), PH_NOISY_CC);
	ZEPHIR_INIT_NVAR(_4);
	ZVAL_STRING(_4, "router/driver", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&driver, _18, "get", NULL, 0, _4);
	zephir_check_temp_parameter(_4);
	zephir_check_call_status();
	ZEPHIR_CALL_CE_STATIC(&_19, brisk_kernel_toolkit_ce, "classdeclared", &_20, 61, driver);
	zephir_check_call_status();
	_21 = !zephir_is_true(_19);
	if (_21) {
		ZEPHIR_CALL_CE_STATIC(&_22, brisk_kernel_loader_ce, "findclass", &_23, 62, driver);
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
		ZVAL_STRING(_27$$5, "router.driver_not_found", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_CE_STATIC(&_25$$5, brisk_kernel_language_ce, "get", &_10, 27, _27$$5, _26$$5);
		zephir_check_temp_parameter(_27$$5);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, _24$$5, "__construct", NULL, 28, _25$$5);
		zephir_check_call_status();
		zephir_throw_exception_debug(_24$$5, "brisk/Kernel/Router/RouterAdapter.zep", 30 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(instance);
	zephir_fetch_safe_class(_28, driver);
		_29 = zend_fetch_class(Z_STRVAL_P(_28), Z_STRLEN_P(_28), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	object_init_ex(instance, _29);
	if (zephir_has_constructor(instance TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, instance, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	if (!((zephir_instance_of_ev(instance, brisk_kernel_router_routerfather_ce TSRMLS_CC)))) {
		ZEPHIR_INIT_VAR(_30$$6);
		object_init_ex(_30$$6, brisk_exception_routerexception_ce);
		ZEPHIR_INIT_VAR(_32$$6);
		zephir_create_array(_32$$6, 2, 0 TSRMLS_CC);
		zephir_array_fast_append(_32$$6, driver);
		ZEPHIR_INIT_VAR(_33$$6);
		ZVAL_STRING(_33$$6, "\\Brisk\\Kernel\\Router\\RouterFather", 1);
		zephir_array_fast_append(_32$$6, _33$$6);
		ZEPHIR_INIT_NVAR(_33$$6);
		ZVAL_STRING(_33$$6, "router.driver_implement_error", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_CE_STATIC(&_31$$6, brisk_kernel_language_ce, "get", &_10, 27, _33$$6, _32$$6);
		zephir_check_temp_parameter(_33$$6);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, _30$$6, "__construct", NULL, 28, _31$$6);
		zephir_check_call_status();
		zephir_throw_exception_debug(_30$$6, "brisk/Kernel/Router/RouterAdapter.zep", 34 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(_35);
	zephir_create_array(_35, 1, 0 TSRMLS_CC);
	zephir_array_update_string(&_35, SL("router"), &driver, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(_4);
	ZVAL_STRING(_4, "driver", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_CE_STATIC(NULL, brisk_kernel_trace_ce, "set", &_34, 12, _4, _35);
	zephir_check_temp_parameter(_4);
	zephir_check_call_status();
	RETURN_CCTOR(instance);

}


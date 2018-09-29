
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
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/string.h"
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"
#include "kernel/exit.h"
#include "kernel/file.h"


ZEPHIR_INIT_CLASS(Brisk_Kernel_Router_Classic) {

	ZEPHIR_REGISTER_CLASS_EX(Brisk\\Kernel\\Router, Classic, brisk, kernel_router_classic, brisk_kernel_router_routerfather_ce, brisk_kernel_router_classic_method_entry, 0);

	zend_declare_property_bool(brisk_kernel_router_classic_ce, SL("_module_support"), 0, ZEND_ACC_PRIVATE|ZEND_ACC_STATIC TSRMLS_CC);

	zend_declare_property_null(brisk_kernel_router_classic_ce, SL("_rules"), ZEND_ACC_PRIVATE|ZEND_ACC_STATIC TSRMLS_CC);

	zend_declare_property_string(brisk_kernel_router_classic_ce, SL("_auto_method"), "__init", ZEND_ACC_PRIVATE|ZEND_ACC_STATIC TSRMLS_CC);

	zend_declare_property_string(brisk_kernel_router_classic_ce, SL("_default_module"), "Index", ZEND_ACC_PRIVATE|ZEND_ACC_STATIC TSRMLS_CC);

	zend_declare_property_string(brisk_kernel_router_classic_ce, SL("_default_controller"), "Index", ZEND_ACC_PRIVATE|ZEND_ACC_STATIC TSRMLS_CC);

	zend_declare_property_string(brisk_kernel_router_classic_ce, SL("_default_action"), "index", ZEND_ACC_PRIVATE|ZEND_ACC_STATIC TSRMLS_CC);

	zend_declare_property_string(brisk_kernel_router_classic_ce, SL("_url_suffix"), ".html", ZEND_ACC_PRIVATE|ZEND_ACC_STATIC TSRMLS_CC);

	zend_declare_property_null(brisk_kernel_router_classic_ce, SL("_interceptors"), ZEND_ACC_PRIVATE|ZEND_ACC_STATIC TSRMLS_CC);

	zend_declare_property_null(brisk_kernel_router_classic_ce, SL("_module"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(brisk_kernel_router_classic_ce, SL("_controller"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(brisk_kernel_router_classic_ce, SL("_action"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(brisk_kernel_router_classic_ce, SL("_namespace"), ZEND_ACC_PRIVATE TSRMLS_CC);

	return SUCCESS;

}

/**
 * Turn on routing module support
 *
 * @param string default_module
 * @return null
 */
PHP_METHOD(Brisk_Kernel_Router_Classic, openModuleSupport) {

	zval *default_module_param = NULL;
	zval *default_module = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &default_module_param);

	if (!default_module_param) {
		ZEPHIR_INIT_VAR(default_module);
		ZVAL_STRING(default_module, "", 1);
	} else {
	if (UNEXPECTED(Z_TYPE_P(default_module_param) != IS_STRING && Z_TYPE_P(default_module_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'default_module' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(default_module_param) == IS_STRING)) {
		zephir_get_strval(default_module, default_module_param);
	} else {
		ZEPHIR_INIT_VAR(default_module);
		ZVAL_EMPTY_STRING(default_module);
	}
	}


	zephir_update_static_property_ce(brisk_kernel_router_classic_ce, SL("_module_support"), &ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	if (!ZEPHIR_IS_STRING(default_module, "")) {
		zephir_update_static_property_ce(brisk_kernel_router_classic_ce, SL("_default_module"), &default_module TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Adding routing rewriting rules
 *
 * @param string rule
 * @param mixed redirect
 * @return null
 */
PHP_METHOD(Brisk_Kernel_Router_Classic, addRule) {

	zval *rule_param = NULL, *redirect;
	zval *rule = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &rule_param, &redirect);

	if (UNEXPECTED(Z_TYPE_P(rule_param) != IS_STRING && Z_TYPE_P(rule_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'rule' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(rule_param) == IS_STRING)) {
		zephir_get_strval(rule, rule_param);
	} else {
		ZEPHIR_INIT_VAR(rule);
		ZVAL_EMPTY_STRING(rule);
	}


	zephir_update_static_property_array_multi_ce(brisk_kernel_router_classic_ce, SL("_rules"), &redirect TSRMLS_CC, SL("z"), 1, rule);
	ZEPHIR_MM_RESTORE();

}

/**
 * Add routing interceptors
 *
 * @param string ns_space
 * @param callable operator
 * @return null
 */
PHP_METHOD(Brisk_Kernel_Router_Classic, addInterceptor) {

	zval *ns_space_param = NULL, *operator, *_0, _1;
	zval *ns_space = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &ns_space_param, &operator);

	if (UNEXPECTED(Z_TYPE_P(ns_space_param) != IS_STRING && Z_TYPE_P(ns_space_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'ns_space' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(ns_space_param) == IS_STRING)) {
		zephir_get_strval(ns_space, ns_space_param);
	} else {
		ZEPHIR_INIT_VAR(ns_space);
		ZVAL_EMPTY_STRING(ns_space);
	}
	if (UNEXPECTED(zephir_is_callable(operator TSRMLS_CC) != 1)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'operator' must be a callable") TSRMLS_CC);
		RETURN_MM_NULL();
	}


	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_STRING(&_1, "\\", 0);
	zephir_fast_trim(_0, ns_space, &_1, ZEPHIR_TRIM_LEFT TSRMLS_CC);
	zephir_get_strval(ns_space, _0);
	zephir_update_static_property_array_multi_ce(brisk_kernel_router_classic_ce, SL("_interceptors"), &operator TSRMLS_CC, SL("z"), 1, ns_space);
	ZEPHIR_MM_RESTORE();

}

/**
 * Get routing interceptors
 *
 * @param string ns_space
 * @return null
 */
PHP_METHOD(Brisk_Kernel_Router_Classic, getInterceptors) {

	zval *_7$$5;
	HashTable *_4;
	HashPosition _3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *ns_space_param = NULL, *_0, _1, *result = NULL, *key = NULL, *val = NULL, *_2, **_5, *_6$$3 = NULL, *_8$$5 = NULL;
	zval *ns_space = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &ns_space_param);

	if (UNEXPECTED(Z_TYPE_P(ns_space_param) != IS_STRING && Z_TYPE_P(ns_space_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'ns_space' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(ns_space_param) == IS_STRING)) {
		zephir_get_strval(ns_space, ns_space_param);
	} else {
		ZEPHIR_INIT_VAR(ns_space);
		ZVAL_EMPTY_STRING(ns_space);
	}


	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_STRING(&_1, "\\", 0);
	zephir_fast_trim(_0, ns_space, &_1, ZEPHIR_TRIM_LEFT TSRMLS_CC);
	zephir_get_strval(ns_space, _0);
	ZEPHIR_INIT_VAR(result);
	array_init(result);
	_2 = zephir_fetch_static_property_ce(brisk_kernel_router_classic_ce, SL("_interceptors") TSRMLS_CC);
	zephir_is_iterable(_2, &_4, &_3, 0, 0, "brisk/Kernel/Router/Classic.zep", 100);
	for (
	  ; zend_hash_get_current_data_ex(_4, (void**) &_5, &_3) == SUCCESS
	  ; zend_hash_move_forward_ex(_4, &_3)
	) {
		ZEPHIR_GET_HMKEY(key, _4, _3);
		ZEPHIR_GET_HVALUE(val, _5);
		ZEPHIR_INIT_NVAR(_6$$3);
		zephir_fast_strpos(_6$$3, ns_space, key, 0 );
		if (!ZEPHIR_IS_FALSE_IDENTICAL(_6$$3)) {
			zephir_array_update_zval(&result, key, &val, PH_COPY | PH_SEPARATE);
		}
	}
	if (zephir_fast_count_int(result TSRMLS_CC) > 0) {
		ZEPHIR_INIT_VAR(_7$$5);
		zephir_create_array(_7$$5, 2, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_8$$5);
		object_init_ex(_8$$5, brisk_kernel_router_classic_ce);
		if (zephir_has_constructor(_8$$5 TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, _8$$5, "__construct", NULL, 0);
			zephir_check_call_status();
		}
		zephir_array_fast_append(_7$$5, _8$$5);
		ZEPHIR_INIT_NVAR(_8$$5);
		ZVAL_STRING(_8$$5, "todoUKSort", 1);
		zephir_array_fast_append(_7$$5, _8$$5);
		ZEPHIR_MAKE_REF(result);
		ZEPHIR_CALL_FUNCTION(NULL, "uksort", NULL, 56, result, _7$$5);
		ZEPHIR_UNREF(result);
		zephir_check_call_status();
	}
	RETURN_CCTOR(result);

}

/**
 * Routing ready
 *
 * @return null
 */
PHP_METHOD(Brisk_Kernel_Router_Classic, ready) {

	zval *_8$$3;
	zval *_0 = NULL, *_2, *_3 = NULL, *_4 = NULL, *base_namespace = NULL, *_10 = NULL, *_11, *_12 = NULL, _13, *uri = NULL, *result = NULL, *params = NULL, *_15, *_16, *_17, *ns_space = NULL, *_18, *_22, *_23, *_26, *_5$$3, *_6$$3 = NULL, *_9$$3 = NULL, *_19$$4, *_20$$4, *_21$$4;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL, *_7 = NULL, *_14 = NULL, *_24 = NULL, *_25 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_CE_STATIC(&_0, brisk_kernel_app_ce, "getinstance", &_1, 46);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(_2);
	zephir_read_property(&_2, _0, SL("config"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_4);
	ZVAL_STRING(_4, "router/options/base_namespace", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_3, _2, "haskey", NULL, 0, _4);
	zephir_check_temp_parameter(_4);
	zephir_check_call_status();
	if (!zephir_is_true(_3)) {
		ZEPHIR_INIT_VAR(_5$$3);
		object_init_ex(_5$$3, brisk_exception_configurationexception_ce);
		ZEPHIR_INIT_VAR(_8$$3);
		zephir_create_array(_8$$3, 1, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_9$$3);
		ZVAL_STRING(_9$$3, "router/options/base_namespace", 1);
		zephir_array_fast_append(_8$$3, _9$$3);
		ZEPHIR_INIT_NVAR(_9$$3);
		ZVAL_STRING(_9$$3, "core.config_not_found", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_CE_STATIC(&_6$$3, brisk_kernel_language_ce, "get", &_7, 27, _9$$3, _8$$3);
		zephir_check_temp_parameter(_9$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, _5$$3, "__construct", NULL, 28, _6$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(_5$$3, "brisk/Kernel/Router/Classic.zep", 114 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_CE_STATIC(&_10, brisk_kernel_app_ce, "getinstance", &_1, 46);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(_11);
	zephir_read_property(&_11, _10, SL("config"), PH_NOISY_CC);
	ZEPHIR_INIT_NVAR(_4);
	ZVAL_STRING(_4, "router/options/base_namespace", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_12, _11, "get", NULL, 0, _4);
	zephir_check_temp_parameter(_4);
	zephir_check_call_status();
	ZEPHIR_SINIT_VAR(_13);
	ZVAL_STRING(&_13, "\\", 0);
	ZEPHIR_INIT_VAR(base_namespace);
	zephir_fast_trim(base_namespace, _12, &_13, ZEPHIR_TRIM_BOTH TSRMLS_CC);
	ZEPHIR_INIT_NVAR(_4);
	ZVAL_STRING(_4, "REQUEST_URI", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_CE_STATIC(&uri, brisk_kernel_server_ce, "getitem", &_14, 57, _4);
	zephir_check_temp_parameter(_4);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&result, this_ptr, "_parseuri", NULL, 58, uri);
	zephir_check_call_status();
	zephir_array_fetch_string(&_15, result, SL("module"), PH_NOISY | PH_READONLY, "brisk/Kernel/Router/Classic.zep", 123 TSRMLS_CC);
	zephir_update_property_this(getThis(), SL("_module"), _15 TSRMLS_CC);
	zephir_array_fetch_string(&_16, result, SL("controller"), PH_NOISY | PH_READONLY, "brisk/Kernel/Router/Classic.zep", 124 TSRMLS_CC);
	zephir_update_property_this(getThis(), SL("_controller"), _16 TSRMLS_CC);
	zephir_array_fetch_string(&_17, result, SL("action"), PH_NOISY | PH_READONLY, "brisk/Kernel/Router/Classic.zep", 125 TSRMLS_CC);
	zephir_update_property_this(getThis(), SL("_action"), _17 TSRMLS_CC);
	ZEPHIR_OBS_VAR(params);
	zephir_array_fetch_string(&params, result, SL("params"), PH_NOISY, "brisk/Kernel/Router/Classic.zep", 126 TSRMLS_CC);
	ZEPHIR_CPY_WRT(ns_space, base_namespace);
	_18 = zephir_fetch_nproperty_this(this_ptr, SL("_module"), PH_NOISY_CC);
	if (!ZEPHIR_IS_STRING(_18, "")) {
		ZEPHIR_INIT_VAR(_19$$4);
		_20$$4 = zephir_fetch_nproperty_this(this_ptr, SL("_module"), PH_NOISY_CC);
		zephir_ucfirst(_19$$4, _20$$4);
		ZEPHIR_INIT_VAR(_21$$4);
		ZEPHIR_CONCAT_VSV(_21$$4, ns_space, "\\", _19$$4);
		ZEPHIR_CPY_WRT(ns_space, _21$$4);
	}
	ZEPHIR_INIT_NVAR(_4);
	_22 = zephir_fetch_nproperty_this(this_ptr, SL("_controller"), PH_NOISY_CC);
	zephir_ucfirst(_4, _22);
	ZEPHIR_INIT_VAR(_23);
	ZEPHIR_CONCAT_VSV(_23, ns_space, "\\", _4);
	ZEPHIR_CPY_WRT(ns_space, _23);
	zephir_update_property_this(getThis(), SL("_namespace"), ns_space TSRMLS_CC);
	ZEPHIR_CALL_CE_STATIC(NULL, brisk_kernel_request_ce, "setdata", &_24, 59, params);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_26);
	ZVAL_BOOL(_26, 1);
	ZEPHIR_CALL_CE_STATIC(NULL, brisk_kernel_request_ce, "setready", &_25, 60, _26);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Routing path distribution
 *
 * @return null
 */
PHP_METHOD(Brisk_Kernel_Router_Classic, dispatch) {

	HashTable *_21$$6;
	HashPosition _20$$6;
	zval *_8$$3, *_12$$4, *_17$$5, *_32$$10;
	zend_class_entry *_25;
	zend_bool _2;
	zval *ns_space = NULL, *_0 = NULL, *_3 = NULL, *ref = NULL, *_14 = NULL, *interceptors = NULL, *instance = NULL, *options = NULL, *action = NULL, *auto_method = NULL, *_24 = NULL, *_26 = NULL, *_28, *_29, *output = NULL, *_5$$3, *_6$$3 = NULL, *_9$$3, *_10$$4, *_11$$4 = NULL, *_13$$4, *_15$$5, *_16$$5 = NULL, *_18$$5, *op$$6 = NULL, *result$$6 = NULL, *_19$$6 = NULL, **_22$$6, *_23$$7 = NULL, *_30$$10, *_31$$10 = NULL, *_33$$10;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL, *_4 = NULL, *_7 = NULL, *_27 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(ns_space);
	zephir_read_property_this(&ns_space, this_ptr, SL("_namespace"), PH_NOISY_CC);
	ZEPHIR_CALL_CE_STATIC(&_0, brisk_kernel_toolkit_ce, "classdeclared", &_1, 61, ns_space);
	zephir_check_call_status();
	_2 = !zephir_is_true(_0);
	if (_2) {
		ZEPHIR_CALL_CE_STATIC(&_3, brisk_kernel_loader_ce, "findclass", &_4, 62, ns_space);
		zephir_check_call_status();
		_2 = !zephir_is_true(_3);
	}
	if (_2) {
		ZEPHIR_INIT_VAR(_5$$3);
		object_init_ex(_5$$3, brisk_exception_controllernotfoundexception_ce);
		ZEPHIR_INIT_VAR(_8$$3);
		zephir_create_array(_8$$3, 1, 0 TSRMLS_CC);
		zephir_array_fast_append(_8$$3, ns_space);
		ZEPHIR_INIT_VAR(_9$$3);
		ZVAL_STRING(_9$$3, "router.controller_not_found", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_CE_STATIC(&_6$$3, brisk_kernel_language_ce, "get", &_7, 27, _9$$3, _8$$3);
		zephir_check_temp_parameter(_9$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, _5$$3, "__construct", NULL, 28, _6$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(_5$$3, "brisk/Kernel/Router/Classic.zep", 151 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	} else if (!(zephir_class_exists(ns_space, 1 TSRMLS_CC))) {
		ZEPHIR_INIT_VAR(_10$$4);
		object_init_ex(_10$$4, brisk_exception_classnotfoundexception_ce);
		ZEPHIR_INIT_VAR(_12$$4);
		zephir_create_array(_12$$4, 1, 0 TSRMLS_CC);
		zephir_array_fast_append(_12$$4, ns_space);
		ZEPHIR_INIT_VAR(_13$$4);
		ZVAL_STRING(_13$$4, "router.class_not_found", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_CE_STATIC(&_11$$4, brisk_kernel_language_ce, "get", &_7, 27, _13$$4, _12$$4);
		zephir_check_temp_parameter(_13$$4);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, _10$$4, "__construct", NULL, 28, _11$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(_10$$4, "brisk/Kernel/Router/Classic.zep", 153 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(ref);
	object_init_ex(ref, zephir_get_internal_ce(SS("reflectionclass") TSRMLS_CC));
	ZEPHIR_CALL_METHOD(NULL, ref, "__construct", NULL, 63, ns_space);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_14, ref, "isabstract", NULL, 64);
	zephir_check_call_status();
	if (zephir_is_true(_14)) {
		ZEPHIR_INIT_VAR(_15$$5);
		object_init_ex(_15$$5, brisk_exception_controllerexception_ce);
		ZEPHIR_INIT_VAR(_17$$5);
		zephir_create_array(_17$$5, 1, 0 TSRMLS_CC);
		zephir_array_fast_append(_17$$5, ns_space);
		ZEPHIR_INIT_VAR(_18$$5);
		ZVAL_STRING(_18$$5, "router.controller_is_protected", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_CE_STATIC(&_16$$5, brisk_kernel_language_ce, "get", &_7, 27, _18$$5, _17$$5);
		zephir_check_temp_parameter(_18$$5);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, _15$$5, "__construct", NULL, 28, _16$$5);
		zephir_check_call_status();
		zephir_throw_exception_debug(_15$$5, "brisk/Kernel/Router/Classic.zep", 159 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_SELF(&interceptors, "getinterceptors", NULL, 0, ns_space);
	zephir_check_call_status();
	if (zephir_fast_count_int(interceptors TSRMLS_CC) > 0) {
		ZEPHIR_INIT_VAR(_19$$6);
		zephir_is_iterable(interceptors, &_21$$6, &_20$$6, 0, 0, "brisk/Kernel/Router/Classic.zep", 173);
		for (
		  ; zend_hash_get_current_data_ex(_21$$6, (void**) &_22$$6, &_20$$6) == SUCCESS
		  ; zend_hash_move_forward_ex(_21$$6, &_20$$6)
		) {
			ZEPHIR_GET_HMKEY(_19$$6, _21$$6, _20$$6);
			ZEPHIR_GET_HVALUE(op$$6, _22$$6);
			ZEPHIR_INIT_NVAR(_23$$7);
			array_init(_23$$7);
			ZEPHIR_INIT_NVAR(result$$6);
			ZEPHIR_CALL_USER_FUNC_ARRAY(result$$6, op$$6, _23$$7);
			zephir_check_call_status();
			if (Z_TYPE_P(result$$6) == IS_STRING) {
				zend_print_zval(result$$6, 0);
				ZEPHIR_MM_RESTORE();
				zephir_exit_empty();
			}
		}
	}
	ZEPHIR_INIT_VAR(instance);
	zephir_fetch_safe_class(_24, ns_space);
		_25 = zend_fetch_class(Z_STRVAL_P(_24), Z_STRLEN_P(_24), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	object_init_ex(instance, _25);
	if (zephir_has_constructor(instance TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, instance, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_OBS_VAR(action);
	zephir_read_property_this(&action, this_ptr, SL("_action"), PH_NOISY_CC);
	ZEPHIR_CALL_CE_STATIC(&_26, brisk_kernel_app_ce, "getinstance", &_27, 46);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(_28);
	zephir_read_property(&_28, _26, SL("config"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_29);
	ZVAL_STRING(_29, "router/options", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&options, _28, "get", NULL, 0, _29);
	zephir_check_temp_parameter(_29);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(auto_method);
	zephir_read_static_property_ce(&auto_method, brisk_kernel_router_classic_ce, SL("_auto_method") TSRMLS_CC);
	if (zephir_array_isset_string(options, SS("auto_method"))) {
		ZEPHIR_OBS_NVAR(auto_method);
		zephir_array_fetch_string(&auto_method, options, SL("auto_method"), PH_NOISY, "brisk/Kernel/Router/Classic.zep", 181 TSRMLS_CC);
	}
	if (!((zephir_method_exists(instance, action TSRMLS_CC)  == SUCCESS))) {
		ZEPHIR_INIT_VAR(_30$$10);
		object_init_ex(_30$$10, brisk_exception_actionnotfoundexception_ce);
		ZEPHIR_INIT_VAR(_32$$10);
		zephir_create_array(_32$$10, 1, 0 TSRMLS_CC);
		zephir_array_fast_append(_32$$10, action);
		ZEPHIR_INIT_VAR(_33$$10);
		ZVAL_STRING(_33$$10, "router.action_not_found", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_CE_STATIC(&_31$$10, brisk_kernel_language_ce, "get", &_7, 27, _33$$10, _32$$10);
		zephir_check_temp_parameter(_33$$10);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, _30$$10, "__construct", NULL, 28, _31$$10);
		zephir_check_call_status();
		zephir_throw_exception_debug(_30$$10, "brisk/Kernel/Router/Classic.zep", 184 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(output);
	ZVAL_NULL(output);
	if ((zephir_method_exists(instance, auto_method TSRMLS_CC)  == SUCCESS)) {
		ZEPHIR_CALL_METHOD_ZVAL(&output, instance, auto_method, NULL, 0);
		zephir_check_call_status();
	}
	if (Z_TYPE_P(output) == IS_NULL) {
		ZEPHIR_CALL_METHOD_ZVAL(&output, instance, action, NULL, 0);
		zephir_check_call_status();
	}
	zend_print_zval(output, 0);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Brisk_Kernel_Router_Classic, todoUKSort) {

	zval *a_param = NULL, *b_param = NULL, *len_a = NULL, *len_b = NULL, *_0;
	zval *a = NULL, *b = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &a_param, &b_param);

	if (UNEXPECTED(Z_TYPE_P(a_param) != IS_STRING && Z_TYPE_P(a_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'a' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(a_param) == IS_STRING)) {
		zephir_get_strval(a, a_param);
	} else {
		ZEPHIR_INIT_VAR(a);
		ZVAL_EMPTY_STRING(a);
	}
	if (UNEXPECTED(Z_TYPE_P(b_param) != IS_STRING && Z_TYPE_P(b_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'b' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(b_param) == IS_STRING)) {
		zephir_get_strval(b, b_param);
	} else {
		ZEPHIR_INIT_VAR(b);
		ZVAL_EMPTY_STRING(b);
	}


	ZEPHIR_INIT_VAR(len_a);
	ZVAL_LONG(len_a, zephir_fast_strlen_ev(a));
	ZEPHIR_INIT_VAR(len_b);
	ZVAL_LONG(len_b, zephir_fast_strlen_ev(b));
	if (ZEPHIR_IS_EQUAL(len_a, len_b)) {
		RETURN_MM_LONG(0);
	}
	ZEPHIR_INIT_VAR(_0);
	if (ZEPHIR_GT(len_a, len_b)) {
		ZVAL_LONG(_0, 1);
	} else {
		ZVAL_LONG(_0, -1);
	}
	RETURN_CCTOR(_0);

}

PHP_METHOD(Brisk_Kernel_Router_Classic, _parseUri) {

	HashTable *_26$$12, *_32$$14;
	HashPosition _25$$12, _31$$14;
	zend_bool _9;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL, *_5 = NULL, *_8 = NULL, *_21 = NULL;
	zval *uri_param = NULL, *module = NULL, *controller = NULL, *action = NULL, *url_suffix = NULL, *script_name = NULL, *query = NULL, *pos = NULL, *uri_items = NULL, *result = NULL, *config = NULL, *_0 = NULL, *_2, *_3 = NULL, *_4 = NULL, *_6, *_7 = NULL, _12, *_16 = NULL, _17, *_18, *_19 = NULL, *_20, *val = NULL, *_10$$3, *_11$$3, _13$$8, _14$$8, *_15$$8, _22$$12, *_23$$12 = NULL, *_24$$12 = NULL, **_27$$12, *_28$$13, *_29$$13 = NULL, *_30$$14 = NULL, **_33$$14, *_34$$15 = NULL, *_35$$15, *_36$$15 = NULL;
	zval *uri = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &uri_param);

	if (UNEXPECTED(Z_TYPE_P(uri_param) != IS_STRING && Z_TYPE_P(uri_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'uri' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(uri_param) == IS_STRING)) {
		zephir_get_strval(uri, uri_param);
	} else {
		ZEPHIR_INIT_VAR(uri);
		ZVAL_EMPTY_STRING(uri);
	}


	ZEPHIR_CALL_CE_STATIC(&_0, brisk_kernel_app_ce, "getinstance", &_1, 46);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(_2);
	zephir_read_property(&_2, _0, SL("config"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_3);
	ZVAL_STRING(_3, "router/options", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&config, _2, "get", NULL, 0, _3);
	zephir_check_temp_parameter(_3);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_3);
	ZVAL_STRING(_3, "SCRIPT_FILENAME", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_CE_STATIC(&_4, brisk_kernel_server_ce, "getitem", &_5, 57, _3);
	zephir_check_temp_parameter(_3);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(script_name);
	zephir_basename(script_name, _4 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_6);
	ZEPHIR_CONCAT_SVS(_6, "~/", script_name, "~i");
	ZEPHIR_INIT_NVAR(_3);
	ZVAL_STRING(_3, "", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_FUNCTION(&_7, "preg_replace", &_8, 4, _6, _3, uri);
	zephir_check_temp_parameter(_3);
	zephir_check_call_status();
	zephir_get_strval(uri, _7);
	_9 = ZEPHIR_IS_STRING(uri, "");
	if (!(_9)) {
		_9 = ZEPHIR_IS_STRING(uri, "/");
	}
	if (_9) {
		ZEPHIR_INIT_VAR(module);
		ZVAL_STRING(module, "", 1);
		_10$$3 = zephir_fetch_static_property_ce(brisk_kernel_router_classic_ce, SL("_module_support") TSRMLS_CC);
		if (zephir_is_true(_10$$3)) {
			ZEPHIR_OBS_NVAR(module);
			zephir_read_static_property_ce(&module, brisk_kernel_router_classic_ce, SL("_default_module") TSRMLS_CC);
		}
		ZEPHIR_OBS_VAR(controller);
		zephir_read_static_property_ce(&controller, brisk_kernel_router_classic_ce, SL("_default_controller") TSRMLS_CC);
		ZEPHIR_OBS_VAR(action);
		zephir_read_static_property_ce(&action, brisk_kernel_router_classic_ce, SL("_default_action") TSRMLS_CC);
		if (zephir_array_isset_string(config, SS("default_controller"))) {
			ZEPHIR_OBS_NVAR(controller);
			zephir_array_fetch_string(&controller, config, SL("default_controller"), PH_NOISY, "brisk/Kernel/Router/Classic.zep", 227 TSRMLS_CC);
		}
		if (zephir_array_isset_string(config, SS("default_action"))) {
			ZEPHIR_OBS_NVAR(action);
			zephir_array_fetch_string(&action, config, SL("default_action"), PH_NOISY, "brisk/Kernel/Router/Classic.zep", 230 TSRMLS_CC);
		}
		zephir_create_array(return_value, 4, 0 TSRMLS_CC);
		zephir_array_update_string(&return_value, SL("module"), &module, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&return_value, SL("controller"), &controller, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&return_value, SL("action"), &action, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_VAR(_11$$3);
		array_init(_11$$3);
		zephir_array_update_string(&return_value, SL("params"), &_11$$3, PH_COPY | PH_SEPARATE);
		RETURN_MM();
	}
	ZEPHIR_OBS_VAR(url_suffix);
	zephir_read_static_property_ce(&url_suffix, brisk_kernel_router_classic_ce, SL("_url_suffix") TSRMLS_CC);
	if (zephir_array_isset_string(config, SS("url_suffix"))) {
		ZEPHIR_OBS_NVAR(url_suffix);
		zephir_array_fetch_string(&url_suffix, config, SL("url_suffix"), PH_NOISY, "brisk/Kernel/Router/Classic.zep", 241 TSRMLS_CC);
	}
	ZEPHIR_INIT_VAR(query);
	ZVAL_STRING(query, "", 1);
	ZEPHIR_SINIT_VAR(_12);
	ZVAL_STRING(&_12, "?", 0);
	ZEPHIR_INIT_VAR(pos);
	zephir_fast_strpos(pos, uri, &_12, 0 );
	if (!ZEPHIR_IS_FALSE_IDENTICAL(pos)) {
		ZEPHIR_SINIT_VAR(_13$$8);
		ZVAL_LONG(&_13$$8, (zephir_get_numberval(pos) + 1));
		ZEPHIR_INIT_NVAR(query);
		zephir_substr(query, uri, zephir_get_intval(&_13$$8), 0, ZEPHIR_SUBSTR_NO_LENGTH);
		ZEPHIR_SINIT_VAR(_14$$8);
		ZVAL_LONG(&_14$$8, 0);
		ZEPHIR_INIT_VAR(_15$$8);
		zephir_substr(_15$$8, uri, 0 , zephir_get_intval(pos), 0);
		zephir_get_strval(uri, _15$$8);
	}
	ZEPHIR_CALL_METHOD(&_16, this_ptr, "_rewrite", NULL, 65, uri);
	zephir_check_call_status();
	ZEPHIR_SINIT_VAR(_17);
	ZVAL_STRING(&_17, "/", 0);
	ZEPHIR_INIT_NVAR(uri);
	zephir_fast_trim(uri, _16, &_17, ZEPHIR_TRIM_BOTH TSRMLS_CC);
	ZEPHIR_INIT_VAR(_18);
	ZEPHIR_CONCAT_SVS(_18, "~", url_suffix, "$~i");
	ZEPHIR_INIT_NVAR(_3);
	ZVAL_STRING(_3, "", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_FUNCTION(&_19, "preg_replace", &_8, 4, _18, _3, uri);
	zephir_check_temp_parameter(_3);
	zephir_check_call_status();
	zephir_get_strval(uri, _19);
	ZEPHIR_INIT_VAR(uri_items);
	zephir_fast_explode_str(uri_items, SL("/"), uri, LONG_MAX TSRMLS_CC);
	ZEPHIR_INIT_NVAR(module);
	ZVAL_STRING(module, "", 1);
	_20 = zephir_fetch_static_property_ce(brisk_kernel_router_classic_ce, SL("_module_support") TSRMLS_CC);
	if (zephir_is_true(_20)) {
		ZEPHIR_MAKE_REF(uri_items);
		ZEPHIR_CALL_FUNCTION(&module, "array_shift", &_21, 7, uri_items);
		ZEPHIR_UNREF(uri_items);
		zephir_check_call_status();
	}
	ZEPHIR_MAKE_REF(uri_items);
	ZEPHIR_CALL_FUNCTION(&controller, "array_shift", &_21, 7, uri_items);
	ZEPHIR_UNREF(uri_items);
	zephir_check_call_status();
	if (ZEPHIR_IS_STRING(controller, "")) {
		ZEPHIR_OBS_NVAR(controller);
		zephir_read_static_property_ce(&controller, brisk_kernel_router_classic_ce, SL("_default_controller") TSRMLS_CC);
	}
	ZEPHIR_MAKE_REF(uri_items);
	ZEPHIR_CALL_FUNCTION(&action, "array_shift", &_21, 7, uri_items);
	ZEPHIR_UNREF(uri_items);
	zephir_check_call_status();
	if (ZEPHIR_IS_STRING(action, "")) {
		ZEPHIR_OBS_NVAR(action);
		zephir_read_static_property_ce(&action, brisk_kernel_router_classic_ce, SL("_default_action") TSRMLS_CC);
	}
	ZEPHIR_INIT_VAR(result);
	array_init(result);
	if (zephir_fast_count_int(uri_items TSRMLS_CC) > 0) {
		ZEPHIR_SINIT_VAR(_22$$12);
		ZVAL_LONG(&_22$$12, 2);
		ZEPHIR_CALL_FUNCTION(&_23$$12, "array_chunk", NULL, 66, uri_items, &_22$$12);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(uri_items, _23$$12);
		ZEPHIR_INIT_VAR(_24$$12);
		zephir_is_iterable(uri_items, &_26$$12, &_25$$12, 0, 0, "brisk/Kernel/Router/Classic.zep", 272);
		for (
		  ; zend_hash_get_current_data_ex(_26$$12, (void**) &_27$$12, &_25$$12) == SUCCESS
		  ; zend_hash_move_forward_ex(_26$$12, &_25$$12)
		) {
			ZEPHIR_GET_HMKEY(_24$$12, _26$$12, _25$$12);
			ZEPHIR_GET_HVALUE(val, _27$$12);
			zephir_array_fetch_long(&_28$$13, val, 1, PH_NOISY | PH_READONLY, "brisk/Kernel/Router/Classic.zep", 270 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(_29$$13);
			zephir_array_fetch_long(&_29$$13, val, 0, PH_NOISY, "brisk/Kernel/Router/Classic.zep", 270 TSRMLS_CC);
			zephir_array_update_zval(&result, _29$$13, &_28$$13, PH_COPY | PH_SEPARATE);
		}
	}
	if (!ZEPHIR_IS_STRING(query, "")) {
		ZEPHIR_INIT_VAR(_30$$14);
		zephir_fast_explode_str(_30$$14, SL("&"), query, LONG_MAX TSRMLS_CC);
		ZEPHIR_CPY_WRT(query, _30$$14);
		ZEPHIR_INIT_NVAR(_30$$14);
		zephir_is_iterable(query, &_32$$14, &_31$$14, 0, 0, "brisk/Kernel/Router/Classic.zep", 279);
		for (
		  ; zend_hash_get_current_data_ex(_32$$14, (void**) &_33$$14, &_31$$14) == SUCCESS
		  ; zend_hash_move_forward_ex(_32$$14, &_31$$14)
		) {
			ZEPHIR_GET_HMKEY(_30$$14, _32$$14, _31$$14);
			ZEPHIR_GET_HVALUE(val, _33$$14);
			ZEPHIR_INIT_NVAR(_34$$15);
			zephir_fast_explode_str(_34$$15, SL("="), val, LONG_MAX TSRMLS_CC);
			ZEPHIR_CPY_WRT(val, _34$$15);
			zephir_array_fetch_long(&_35$$15, val, 1, PH_NOISY | PH_READONLY, "brisk/Kernel/Router/Classic.zep", 277 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(_36$$15);
			zephir_array_fetch_long(&_36$$15, val, 0, PH_NOISY, "brisk/Kernel/Router/Classic.zep", 277 TSRMLS_CC);
			zephir_array_update_zval(&result, _36$$15, &_35$$15, PH_COPY | PH_SEPARATE);
		}
	}
	if (zephir_array_isset_string(result, SS("_m"))) {
		ZEPHIR_OBS_NVAR(module);
		zephir_array_fetch_string(&module, result, SL("_m"), PH_NOISY, "brisk/Kernel/Router/Classic.zep", 281 TSRMLS_CC);
		zephir_array_unset_string(&result, SS("_m"), PH_SEPARATE);
	}
	if (zephir_array_isset_string(result, SS("_c"))) {
		ZEPHIR_OBS_NVAR(controller);
		zephir_array_fetch_string(&controller, result, SL("_c"), PH_NOISY, "brisk/Kernel/Router/Classic.zep", 285 TSRMLS_CC);
		zephir_array_unset_string(&result, SS("_c"), PH_SEPARATE);
	}
	if (zephir_array_isset_string(result, SS("_a"))) {
		ZEPHIR_OBS_NVAR(action);
		zephir_array_fetch_string(&action, result, SL("_a"), PH_NOISY, "brisk/Kernel/Router/Classic.zep", 289 TSRMLS_CC);
		zephir_array_unset_string(&result, SS("_a"), PH_SEPARATE);
	}
	zephir_create_array(return_value, 4, 0 TSRMLS_CC);
	zephir_array_update_string(&return_value, SL("module"), &module, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&return_value, SL("controller"), &controller, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&return_value, SL("action"), &action, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&return_value, SL("params"), &result, PH_COPY | PH_SEPARATE);
	RETURN_MM();

}

PHP_METHOD(Brisk_Kernel_Router_Classic, _rewrite) {

	zval *_15$$7 = NULL;
	zend_bool _7$$4;
	HashTable *_2;
	HashPosition _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_9 = NULL, *_11 = NULL, *_14 = NULL, *_20 = NULL;
	zval *uri_param = NULL, *key = NULL, *val = NULL, *_0, **_3, *_4$$3 = NULL, *_5$$3 = NULL, *_6$$3 = NULL, *_8$$5 = NULL, *_10$$6 = NULL, *_12$$7 = NULL, *_13$$7 = NULL, *_16$$7, *_17$$7, *_18$$7 = NULL, *_19$$7 = NULL, *_21$$8, *_22$$8 = NULL, *_23$$8;
	zval *uri = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &uri_param);

	if (UNEXPECTED(Z_TYPE_P(uri_param) != IS_STRING && Z_TYPE_P(uri_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'uri' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(uri_param) == IS_STRING)) {
		zephir_get_strval(uri, uri_param);
	} else {
		ZEPHIR_INIT_VAR(uri);
		ZVAL_EMPTY_STRING(uri);
	}


	_0 = zephir_fetch_static_property_ce(brisk_kernel_router_classic_ce, SL("_rules") TSRMLS_CC);
	zephir_is_iterable(_0, &_2, &_1, 0, 0, "brisk/Kernel/Router/Classic.zep", 317);
	for (
	  ; zend_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zend_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HMKEY(key, _2, _1);
		ZEPHIR_GET_HVALUE(val, _3);
		ZEPHIR_INIT_LNVAR(_4$$3);
		ZEPHIR_CONCAT_SVS(_4$$3, "~", key, "~i");
		ZEPHIR_CPY_WRT(key, _4$$3);
		ZEPHIR_INIT_NVAR(_5$$3);
		ZEPHIR_INIT_NVAR(_6$$3);
		zephir_preg_match(_6$$3, key, uri, _5$$3, 0, 0 , 0  TSRMLS_CC);
		if (zephir_is_true(_6$$3)) {
			_7$$4 = !(zephir_is_callable(val TSRMLS_CC));
			if (_7$$4) {
				_7$$4 = Z_TYPE_P(val) == IS_ARRAY;
			}
			if (Z_TYPE_P(val) == IS_STRING) {
				ZEPHIR_CALL_FUNCTION(&_8$$5, "preg_replace", &_9, 4, key, val, uri);
				zephir_check_call_status();
				zephir_get_strval(uri, _8$$5);
				break;
			} else if (zephir_is_callable(val TSRMLS_CC)) {
				ZEPHIR_CALL_FUNCTION(&_10$$6, "preg_replace_callback", &_11, 67, key, val, uri);
				zephir_check_call_status();
				zephir_get_strval(uri, _10$$6);
				break;
			} else if (_7$$4) {
				ZEPHIR_INIT_NVAR(_12$$7);
				object_init_ex(_12$$7, brisk_exception_routerexception_ce);
				ZEPHIR_INIT_NVAR(_15$$7);
				zephir_create_array(_15$$7, 1, 0 TSRMLS_CC);
				zephir_array_fetch_long(&_16$$7, val, 0, PH_NOISY | PH_READONLY, "brisk/Kernel/Router/Classic.zep", 313 TSRMLS_CC);
				zephir_array_fetch_long(&_17$$7, val, 1, PH_NOISY | PH_READONLY, "brisk/Kernel/Router/Classic.zep", 313 TSRMLS_CC);
				ZEPHIR_INIT_LNVAR(_18$$7);
				ZEPHIR_CONCAT_VSVS(_18$$7, _16$$7, "::", _17$$7, "()");
				zephir_array_fast_append(_15$$7, _18$$7);
				ZEPHIR_INIT_NVAR(_19$$7);
				ZVAL_STRING(_19$$7, "router.call_func_failed", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_CE_STATIC(&_13$$7, brisk_kernel_language_ce, "get", &_14, 0, _19$$7, _15$$7);
				zephir_check_temp_parameter(_19$$7);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, _12$$7, "__construct", &_20, 28, _13$$7);
				zephir_check_call_status();
				zephir_throw_exception_debug(_12$$7, "brisk/Kernel/Router/Classic.zep", 313 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
	}
	if (!(Z_TYPE_P(uri) == IS_STRING)) {
		ZEPHIR_INIT_VAR(_21$$8);
		object_init_ex(_21$$8, brisk_exception_routerexception_ce);
		ZEPHIR_INIT_VAR(_23$$8);
		ZVAL_STRING(_23$$8, "router.uri_must_string", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_CE_STATIC(&_22$$8, brisk_kernel_language_ce, "get", &_14, 27, _23$$8);
		zephir_check_temp_parameter(_23$$8);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, _21$$8, "__construct", &_20, 28, _22$$8);
		zephir_check_call_status();
		zephir_throw_exception_debug(_21$$8, "brisk/Kernel/Router/Classic.zep", 318 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_CTOR(uri);

}

void zephir_init_static_properties_Brisk_Kernel_Router_Classic(TSRMLS_D) {

	zval *_0, *_1;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_update_static_property_ce(brisk_kernel_router_classic_ce, SL("_interceptors"), &_0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	array_init(_1);
	zephir_update_static_property_ce(brisk_kernel_router_classic_ce, SL("_rules"), &_1 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}


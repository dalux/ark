
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
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/string.h"
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"
#include "kernel/exit.h"


ZEPHIR_INIT_CLASS(Brisk_Router_Driver_Rewrite) {

	ZEPHIR_REGISTER_CLASS_EX(Brisk\\Router\\Driver, Rewrite, brisk, router_driver_rewrite, brisk_router_routerfather_ce, brisk_router_driver_rewrite_method_entry, 0);

	zend_declare_property_null(brisk_router_driver_rewrite_ce, SL("_current_namespace"), ZEND_ACC_PRIVATE|ZEND_ACC_STATIC TSRMLS_CC);

	zend_declare_property_null(brisk_router_driver_rewrite_ce, SL("_rules"), ZEND_ACC_PRIVATE|ZEND_ACC_STATIC TSRMLS_CC);

	zend_declare_property_string(brisk_router_driver_rewrite_ce, SL("_auto_method"), "__init", ZEND_ACC_PRIVATE|ZEND_ACC_STATIC TSRMLS_CC);

	zend_declare_property_string(brisk_router_driver_rewrite_ce, SL("_default_controller"), "Index", ZEND_ACC_PRIVATE|ZEND_ACC_STATIC TSRMLS_CC);

	zend_declare_property_string(brisk_router_driver_rewrite_ce, SL("_default_action"), "index", ZEND_ACC_PRIVATE|ZEND_ACC_STATIC TSRMLS_CC);

	zend_declare_property_string(brisk_router_driver_rewrite_ce, SL("_url_suffix"), ".html", ZEND_ACC_PRIVATE|ZEND_ACC_STATIC TSRMLS_CC);

	zend_declare_property_null(brisk_router_driver_rewrite_ce, SL("_interceptors"), ZEND_ACC_PRIVATE|ZEND_ACC_STATIC TSRMLS_CC);

	return SUCCESS;

}

/**
 * Adding routing rewriting rules
 *
 * @param string rule
 * @param mixed redirect
 * @return null
 */
PHP_METHOD(Brisk_Router_Driver_Rewrite, addRule) {

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


	zephir_update_static_property_array_multi_ce(brisk_router_driver_rewrite_ce, SL("_rules"), &redirect TSRMLS_CC, SL("z"), 1, rule);
	ZEPHIR_MM_RESTORE();

}

/**
 * Add routing interceptors
 *
 * @param string ns_space
 * @param callable operator
 * @return null
 */
PHP_METHOD(Brisk_Router_Driver_Rewrite, addInterceptor) {

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
	zephir_update_static_property_array_multi_ce(brisk_router_driver_rewrite_ce, SL("_interceptors"), &operator TSRMLS_CC, SL("z"), 1, ns_space);
	ZEPHIR_MM_RESTORE();

}

/**
 * Get routing interceptors
 *
 * @param string ns_space
 * @return null
 */
PHP_METHOD(Brisk_Router_Driver_Rewrite, getInterceptors) {

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
	_2 = zephir_fetch_static_property_ce(brisk_router_driver_rewrite_ce, SL("_interceptors") TSRMLS_CC);
	zephir_is_iterable(_2, &_4, &_3, 0, 0, "brisk/Router/Driver/Rewrite.zep", 76);
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
		object_init_ex(_8$$5, brisk_router_driver_rewrite_ce);
		if (zephir_has_constructor(_8$$5 TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, _8$$5, "__construct", NULL, 0);
			zephir_check_call_status();
		}
		zephir_array_fast_append(_7$$5, _8$$5);
		ZEPHIR_INIT_NVAR(_8$$5);
		ZVAL_STRING(_8$$5, "todoUKSort", 1);
		zephir_array_fast_append(_7$$5, _8$$5);
		ZEPHIR_MAKE_REF(result);
		ZEPHIR_CALL_FUNCTION(NULL, "uksort", NULL, 102, result, _7$$5);
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
PHP_METHOD(Brisk_Router_Driver_Rewrite, ready) {

	HashTable *_28$$7;
	HashPosition _27$$7;
	zval *_8$$3, *_52$$12;
	zend_bool _38, _25$$6, _48$$11;
	zval *_GET, *_0 = NULL, *_2, *_3 = NULL, *_4 = NULL, *option = NULL, *base_namespace = NULL, *_10 = NULL, *_11, *_12, _13, *uri = NULL, *query = NULL, *controller = NULL, *url_suffix = NULL, _15, *_36 = NULL, _37, *_39, *ns_space = NULL, *_59, *_5$$3, *_6$$3 = NULL, *_9$$3 = NULL, _16$$6, *_17$$6, _18$$6, _19$$6, *_20$$6, _21$$6, *_22$$6, *_23$$6 = NULL, *list_query$$7 = NULL, *query_item$$7 = NULL, *query_name$$7 = NULL, *query_val$$7 = NULL, *_26$$7 = NULL, **_29$$7, _30$$8 = zval_used_for_init, *_31$$8 = NULL, _32$$8 = zval_used_for_init, _33$$8 = zval_used_for_init, *_34$$8 = NULL, _35$$8 = zval_used_for_init, _40$$10, *_41$$10 = NULL, *_42$$10, *_43$$10 = NULL, *controllers$$11 = NULL, *dist$$11 = NULL, *_44$$11, _45$$11 = zval_used_for_init, *_47$$11, _49$$11, *_50$$11, *_51$$12 = NULL, *_53$$12 = NULL, _54$$12, _55$$12, *_56$$12 = NULL, *c$$12 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL, *_7 = NULL, *_14 = NULL, *_24 = NULL, *_46 = NULL, *_57 = NULL, *_58 = NULL;

	ZEPHIR_MM_GROW();
	zephir_get_global(&_GET, SS("_GET") TSRMLS_CC);

	ZEPHIR_CALL_CE_STATIC(&_0, brisk_kernel_app_ce, "getinstance", &_1, 22);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(_2);
	zephir_read_property(&_2, _0, SL("config"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_4);
	ZVAL_STRING(_4, "router/option/base_namespace", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_3, _2, "haskey", NULL, 0, _4);
	zephir_check_temp_parameter(_4);
	zephir_check_call_status();
	if (!zephir_is_true(_3)) {
		ZEPHIR_INIT_VAR(_5$$3);
		object_init_ex(_5$$3, brisk_exception_configurationexception_ce);
		ZEPHIR_INIT_VAR(_8$$3);
		zephir_create_array(_8$$3, 1, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_9$$3);
		ZVAL_STRING(_9$$3, "router/option/base_namespace", 1);
		zephir_array_fast_append(_8$$3, _9$$3);
		ZEPHIR_INIT_NVAR(_9$$3);
		ZVAL_STRING(_9$$3, "core.config_not_found", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_CE_STATIC(&_6$$3, brisk_kernel_language_ce, "get", &_7, 13, _9$$3, _8$$3);
		zephir_check_temp_parameter(_9$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, _5$$3, "__construct", NULL, 8, _6$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(_5$$3, "brisk/Router/Driver/Rewrite.zep", 90 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_CE_STATIC(&_10, brisk_kernel_app_ce, "getinstance", &_1, 22);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(_11);
	zephir_read_property(&_11, _10, SL("config"), PH_NOISY_CC);
	ZEPHIR_INIT_NVAR(_4);
	ZVAL_STRING(_4, "router/option", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&option, _11, "get", NULL, 0, _4);
	zephir_check_temp_parameter(_4);
	zephir_check_call_status();
	zephir_array_fetch_string(&_12, option, SL("base_namespace"), PH_NOISY | PH_READONLY, "brisk/Router/Driver/Rewrite.zep", 94 TSRMLS_CC);
	ZEPHIR_SINIT_VAR(_13);
	ZVAL_STRING(&_13, "\\", 0);
	ZEPHIR_INIT_VAR(base_namespace);
	zephir_fast_trim(base_namespace, _12, &_13, ZEPHIR_TRIM_BOTH TSRMLS_CC);
	ZEPHIR_INIT_NVAR(_4);
	ZVAL_STRING(_4, "REQUEST_URI", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_CE_STATIC(&uri, brisk_kernel_server_ce, "getitem", &_14, 103, _4);
	zephir_check_temp_parameter(_4);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(controller);
	zephir_read_static_property_ce(&controller, brisk_router_driver_rewrite_ce, SL("_default_controller") TSRMLS_CC);
	if (zephir_array_isset_string(option, SS("default_controller"))) {
		ZEPHIR_OBS_NVAR(controller);
		zephir_array_fetch_string(&controller, option, SL("default_controller"), PH_NOISY, "brisk/Router/Driver/Rewrite.zep", 101 TSRMLS_CC);
	}
	ZEPHIR_INIT_NVAR(_4);
	zephir_ucfirst(_4, controller);
	ZEPHIR_CPY_WRT(controller, _4);
	ZEPHIR_OBS_VAR(url_suffix);
	zephir_read_static_property_ce(&url_suffix, brisk_router_driver_rewrite_ce, SL("_url_suffix") TSRMLS_CC);
	if (zephir_array_isset_string(option, SS("url_suffix"))) {
		ZEPHIR_OBS_NVAR(url_suffix);
		zephir_array_fetch_string(&url_suffix, option, SL("url_suffix"), PH_NOISY, "brisk/Router/Driver/Rewrite.zep", 107 TSRMLS_CC);
	}
	ZEPHIR_SINIT_VAR(_15);
	ZVAL_STRING(&_15, "?", 0);
	ZEPHIR_INIT_NVAR(_4);
	zephir_fast_strpos(_4, uri, &_15, 0 );
	if (!ZEPHIR_IS_FALSE(_4)) {
		ZEPHIR_SINIT_VAR(_16$$6);
		ZVAL_STRING(&_16$$6, "?", 0);
		ZEPHIR_INIT_VAR(_17$$6);
		zephir_fast_strpos(_17$$6, uri, &_16$$6, 0 );
		ZEPHIR_SINIT_VAR(_18$$6);
		ZVAL_LONG(&_18$$6, (zephir_get_numberval(_17$$6) + 1));
		ZEPHIR_INIT_VAR(query);
		zephir_substr(query, uri, zephir_get_intval(&_18$$6), 0, ZEPHIR_SUBSTR_NO_LENGTH);
		ZEPHIR_SINIT_VAR(_19$$6);
		ZVAL_STRING(&_19$$6, "?", 0);
		ZEPHIR_INIT_VAR(_20$$6);
		zephir_fast_strpos(_20$$6, uri, &_19$$6, 0 );
		ZEPHIR_SINIT_VAR(_21$$6);
		ZVAL_LONG(&_21$$6, 0);
		ZEPHIR_INIT_VAR(_22$$6);
		zephir_substr(_22$$6, uri, 0 , zephir_get_intval(_20$$6), 0);
		ZEPHIR_CPY_WRT(uri, _22$$6);
		ZEPHIR_CALL_CE_STATIC(&_23$$6, brisk_kernel_server_ce, "iscli", &_24, 57);
		zephir_check_call_status();
		_25$$6 = zephir_is_true(_23$$6);
		if (_25$$6) {
			_25$$6 = !ZEPHIR_IS_STRING(query, "");
		}
		if (_25$$6) {
			ZEPHIR_INIT_VAR(list_query$$7);
			zephir_fast_explode_str(list_query$$7, SL("&"), query, LONG_MAX TSRMLS_CC);
			ZEPHIR_INIT_VAR(_26$$7);
			zephir_is_iterable(list_query$$7, &_28$$7, &_27$$7, 0, 0, "brisk/Router/Driver/Rewrite.zep", 123);
			for (
			  ; zend_hash_get_current_data_ex(_28$$7, (void**) &_29$$7, &_27$$7) == SUCCESS
			  ; zend_hash_move_forward_ex(_28$$7, &_27$$7)
			) {
				ZEPHIR_GET_HMKEY(_26$$7, _28$$7, _27$$7);
				ZEPHIR_GET_HVALUE(query_item$$7, _29$$7);
				ZEPHIR_SINIT_NVAR(_30$$8);
				ZVAL_STRING(&_30$$8, "=", 0);
				ZEPHIR_INIT_NVAR(_31$$8);
				zephir_fast_strpos(_31$$8, query_item$$7, &_30$$8, 0 );
				ZEPHIR_SINIT_NVAR(_32$$8);
				ZVAL_LONG(&_32$$8, 0);
				ZEPHIR_INIT_NVAR(query_name$$7);
				zephir_substr(query_name$$7, query_item$$7, 0 , zephir_get_intval(_31$$8), 0);
				ZEPHIR_SINIT_NVAR(_33$$8);
				ZVAL_STRING(&_33$$8, "=", 0);
				ZEPHIR_INIT_NVAR(_34$$8);
				zephir_fast_strpos(_34$$8, query_item$$7, &_33$$8, 0 );
				ZEPHIR_SINIT_NVAR(_35$$8);
				ZVAL_LONG(&_35$$8, (zephir_get_numberval(_34$$8) + 1));
				ZEPHIR_INIT_NVAR(query_val$$7);
				zephir_substr(query_val$$7, query_item$$7, zephir_get_intval(&_35$$8), 0, ZEPHIR_SUBSTR_NO_LENGTH);
				if (!(zephir_array_isset(_GET, query_name$$7))) {
					zephir_array_update_zval(&_GET, query_name$$7, &query_val$$7, PH_COPY | PH_SEPARATE);
				}
			}
		}
	}
	ZEPHIR_CALL_METHOD(&_36, this_ptr, "_rewrite", NULL, 114, uri);
	zephir_check_call_status();
	ZEPHIR_SINIT_VAR(_37);
	ZVAL_STRING(&_37, "/", 0);
	ZEPHIR_INIT_NVAR(uri);
	zephir_fast_trim(uri, _36, &_37, ZEPHIR_TRIM_BOTH TSRMLS_CC);
	_38 = zephir_is_true(url_suffix);
	if (_38) {
		ZEPHIR_INIT_VAR(_39);
		zephir_fast_strpos(_39, uri, url_suffix, 0 );
		_38 = !ZEPHIR_IS_FALSE_IDENTICAL(_39);
	}
	if (_38) {
		ZEPHIR_SINIT_VAR(_40$$10);
		ZVAL_STRING(&_40$$10, "~%s$~i", 0);
		ZEPHIR_CALL_FUNCTION(&_41$$10, "sprintf", NULL, 12, &_40$$10, url_suffix);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_42$$10);
		ZVAL_STRING(_42$$10, "", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_FUNCTION(&_43$$10, "preg_replace", NULL, 5, _41$$10, _42$$10, uri);
		zephir_check_temp_parameter(_42$$10);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(uri, _43$$10);
	}
	if (!ZEPHIR_IS_STRING(uri, "")) {
		ZEPHIR_INIT_VAR(_44$$11);
		zephir_fast_explode_str(_44$$11, SL("/"), uri, LONG_MAX TSRMLS_CC);
		ZEPHIR_SINIT_VAR(_45$$11);
		ZVAL_STRING(&_45$$11, "ucfirst", 0);
		ZEPHIR_CALL_FUNCTION(&controllers$$11, "array_map", &_46, 115, &_45$$11, _44$$11);
		zephir_check_call_status();
		ZEPHIR_MAKE_REF(controllers$$11);
		ZEPHIR_CALL_FUNCTION(&dist$$11, "end", NULL, 87, controllers$$11);
		ZEPHIR_UNREF(controllers$$11);
		zephir_check_call_status();
		ZEPHIR_SINIT_NVAR(_45$$11);
		ZVAL_STRING(&_45$$11, ".", 0);
		ZEPHIR_INIT_VAR(_47$$11);
		zephir_fast_strpos(_47$$11, dist$$11, &_45$$11, 0 );
		_48$$11 = zephir_is_true(_47$$11);
		if (!(_48$$11)) {
			ZEPHIR_SINIT_VAR(_49$$11);
			ZVAL_STRING(&_49$$11, "_", 0);
			ZEPHIR_INIT_VAR(_50$$11);
			zephir_fast_strpos(_50$$11, dist$$11, &_49$$11, 0 );
			_48$$11 = zephir_is_true(_50$$11);
		}
		if (_48$$11) {
			ZEPHIR_INIT_VAR(_51$$12);
			ZEPHIR_INIT_VAR(_52$$12);
			zephir_create_array(_52$$12, 2, 0 TSRMLS_CC);
			ZEPHIR_INIT_VAR(_53$$12);
			ZVAL_STRING(_53$$12, ".", 1);
			zephir_array_fast_append(_52$$12, _53$$12);
			ZEPHIR_INIT_NVAR(_53$$12);
			ZVAL_STRING(_53$$12, "_", 1);
			zephir_array_fast_append(_52$$12, _53$$12);
			ZEPHIR_SINIT_VAR(_54$$12);
			ZVAL_STRING(&_54$$12, ".", 0);
			zephir_fast_str_replace(&_51$$12, _52$$12, &_54$$12, dist$$11 TSRMLS_CC);
			ZEPHIR_CPY_WRT(dist$$11, _51$$12);
			ZEPHIR_INIT_NVAR(_51$$12);
			zephir_fast_explode_str(_51$$12, SL("."), dist$$11, LONG_MAX TSRMLS_CC);
			ZEPHIR_CPY_WRT(dist$$11, _51$$12);
			ZEPHIR_SINIT_VAR(_55$$12);
			ZVAL_STRING(&_55$$12, "ucfirst", 0);
			ZEPHIR_CALL_FUNCTION(&_56$$12, "array_map", &_46, 115, &_55$$12, dist$$11);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(dist$$11, _56$$12);
			ZEPHIR_INIT_NVAR(_51$$12);
			zephir_fast_join_str(_51$$12, SL(""), dist$$11 TSRMLS_CC);
			ZEPHIR_CPY_WRT(dist$$11, _51$$12);
			ZEPHIR_INIT_VAR(c$$12);
			ZVAL_LONG(c$$12, zephir_fast_count_int(controllers$$11 TSRMLS_CC));
			zephir_array_update_long(&controllers$$11, ((zephir_get_numberval(c$$12) - 1)), &dist$$11, PH_COPY | PH_SEPARATE ZEPHIR_DEBUG_PARAMS_DUMMY);
		}
		ZEPHIR_INIT_NVAR(controller);
		zephir_fast_join_str(controller, SL("\\"), controllers$$11 TSRMLS_CC);
	}
	ZEPHIR_INIT_VAR(ns_space);
	ZEPHIR_CONCAT_VSV(ns_space, base_namespace, "\\", controller);
	zephir_update_static_property_ce(brisk_router_driver_rewrite_ce, SL("_current_namespace"), &ns_space TSRMLS_CC);
	ZEPHIR_CALL_CE_STATIC(NULL, brisk_http_request_ce, "setdata", &_57, 86, _GET);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_59);
	ZVAL_BOOL(_59, 1);
	ZEPHIR_CALL_CE_STATIC(NULL, brisk_http_request_ce, "setready", &_58, 105, _59);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Routing path distribution
 *
 * @return null
 */
PHP_METHOD(Brisk_Router_Driver_Rewrite, dispatch) {

	HashTable *_25$$8;
	HashPosition _24$$8;
	zval *_8$$3, *_12$$4, *_21$$7, *_32$$11;
	zend_class_entry *_29;
	zend_bool _2;
	zval *ns_space = NULL, *_0 = NULL, *_3 = NULL, *option = NULL, *action = NULL, *auto_method = NULL, *_14 = NULL, *_16, *_17, *ref = NULL, *_18 = NULL, *interceptors = NULL, *instance = NULL, *_28 = NULL, *output = NULL, *_5$$3, *_6$$3 = NULL, *_9$$3, *_10$$4, *_11$$4 = NULL, *_13$$4, *_19$$7, *_20$$7 = NULL, *_22$$7, *op$$8 = NULL, *result$$8 = NULL, *_23$$8 = NULL, **_26$$8, *_27$$9 = NULL, *_30$$11, *_31$$11 = NULL, *_33$$11;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL, *_4 = NULL, *_7 = NULL, *_15 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(ns_space);
	zephir_read_static_property_ce(&ns_space, brisk_router_driver_rewrite_ce, SL("_current_namespace") TSRMLS_CC);
	ZEPHIR_CALL_CE_STATIC(&_0, brisk_kernel_toolkit_ce, "classdeclared", &_1, 23, ns_space);
	zephir_check_call_status();
	_2 = !zephir_is_true(_0);
	if (_2) {
		ZEPHIR_CALL_CE_STATIC(&_3, brisk_kernel_loader_ce, "findclass", &_4, 24, ns_space);
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
		ZEPHIR_CALL_CE_STATIC(&_6$$3, brisk_kernel_language_ce, "get", &_7, 13, _9$$3, _8$$3);
		zephir_check_temp_parameter(_9$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, _5$$3, "__construct", NULL, 8, _6$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(_5$$3, "brisk/Router/Driver/Rewrite.zep", 167 TSRMLS_CC);
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
		ZEPHIR_CALL_CE_STATIC(&_11$$4, brisk_kernel_language_ce, "get", &_7, 13, _13$$4, _12$$4);
		zephir_check_temp_parameter(_13$$4);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, _10$$4, "__construct", NULL, 8, _11$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(_10$$4, "brisk/Router/Driver/Rewrite.zep", 169 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_CE_STATIC(&_14, brisk_kernel_app_ce, "getinstance", &_15, 22);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(_16);
	zephir_read_property(&_16, _14, SL("config"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_17);
	ZVAL_STRING(_17, "router/option", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&option, _16, "get", NULL, 0, _17);
	zephir_check_temp_parameter(_17);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(action);
	zephir_read_static_property_ce(&action, brisk_router_driver_rewrite_ce, SL("_default_action") TSRMLS_CC);
	ZEPHIR_OBS_VAR(auto_method);
	zephir_read_static_property_ce(&auto_method, brisk_router_driver_rewrite_ce, SL("_auto_method") TSRMLS_CC);
	if (zephir_array_isset_string(option, SS("default_action"))) {
		ZEPHIR_OBS_NVAR(action);
		zephir_array_fetch_string(&action, option, SL("default_action"), PH_NOISY, "brisk/Router/Driver/Rewrite.zep", 176 TSRMLS_CC);
	}
	if (zephir_array_isset_string(option, SS("auto_method"))) {
		ZEPHIR_OBS_NVAR(auto_method);
		zephir_array_fetch_string(&auto_method, option, SL("auto_method"), PH_NOISY, "brisk/Router/Driver/Rewrite.zep", 179 TSRMLS_CC);
	}
	ZEPHIR_INIT_VAR(ref);
	object_init_ex(ref, zephir_get_internal_ce(SS("reflectionclass") TSRMLS_CC));
	ZEPHIR_CALL_METHOD(NULL, ref, "__construct", NULL, 106, ns_space);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_18, ref, "isabstract", NULL, 107);
	zephir_check_call_status();
	if (zephir_is_true(_18)) {
		ZEPHIR_INIT_VAR(_19$$7);
		object_init_ex(_19$$7, brisk_exception_controllerexception_ce);
		ZEPHIR_INIT_VAR(_21$$7);
		zephir_create_array(_21$$7, 1, 0 TSRMLS_CC);
		zephir_array_fast_append(_21$$7, ns_space);
		ZEPHIR_INIT_VAR(_22$$7);
		ZVAL_STRING(_22$$7, "router.controller_is_protected", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_CE_STATIC(&_20$$7, brisk_kernel_language_ce, "get", &_7, 13, _22$$7, _21$$7);
		zephir_check_temp_parameter(_22$$7);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, _19$$7, "__construct", NULL, 8, _20$$7);
		zephir_check_call_status();
		zephir_throw_exception_debug(_19$$7, "brisk/Router/Driver/Rewrite.zep", 185 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_SELF(&interceptors, "getinterceptors", NULL, 0, ns_space);
	zephir_check_call_status();
	if (zephir_fast_count_int(interceptors TSRMLS_CC) > 0) {
		ZEPHIR_INIT_VAR(_23$$8);
		zephir_is_iterable(interceptors, &_25$$8, &_24$$8, 0, 0, "brisk/Router/Driver/Rewrite.zep", 199);
		for (
		  ; zend_hash_get_current_data_ex(_25$$8, (void**) &_26$$8, &_24$$8) == SUCCESS
		  ; zend_hash_move_forward_ex(_25$$8, &_24$$8)
		) {
			ZEPHIR_GET_HMKEY(_23$$8, _25$$8, _24$$8);
			ZEPHIR_GET_HVALUE(op$$8, _26$$8);
			ZEPHIR_INIT_NVAR(_27$$9);
			array_init(_27$$9);
			ZEPHIR_INIT_NVAR(result$$8);
			ZEPHIR_CALL_USER_FUNC_ARRAY(result$$8, op$$8, _27$$9);
			zephir_check_call_status();
			if (Z_TYPE_P(result$$8) == IS_STRING) {
				zend_print_zval(result$$8, 0);
				ZEPHIR_MM_RESTORE();
				zephir_exit_empty();
			}
		}
	}
	ZEPHIR_INIT_VAR(instance);
	zephir_fetch_safe_class(_28, ns_space);
		_29 = zend_fetch_class(Z_STRVAL_P(_28), Z_STRLEN_P(_28), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	object_init_ex(instance, _29);
	if (zephir_has_constructor(instance TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, instance, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	if (!((zephir_method_exists(instance, action TSRMLS_CC)  == SUCCESS))) {
		ZEPHIR_INIT_VAR(_30$$11);
		object_init_ex(_30$$11, brisk_exception_actionnotfoundexception_ce);
		ZEPHIR_INIT_VAR(_32$$11);
		zephir_create_array(_32$$11, 1, 0 TSRMLS_CC);
		zephir_array_fast_append(_32$$11, action);
		ZEPHIR_INIT_VAR(_33$$11);
		ZVAL_STRING(_33$$11, "router.action_not_found", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_CE_STATIC(&_31$$11, brisk_kernel_language_ce, "get", &_7, 13, _33$$11, _32$$11);
		zephir_check_temp_parameter(_33$$11);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, _30$$11, "__construct", NULL, 8, _31$$11);
		zephir_check_call_status();
		zephir_throw_exception_debug(_30$$11, "brisk/Router/Driver/Rewrite.zep", 204 TSRMLS_CC);
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

PHP_METHOD(Brisk_Router_Driver_Rewrite, todoUKSort) {

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

PHP_METHOD(Brisk_Router_Driver_Rewrite, _rewrite) {

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


	_0 = zephir_fetch_static_property_ce(brisk_router_driver_rewrite_ce, SL("_rules") TSRMLS_CC);
	zephir_is_iterable(_0, &_2, &_1, 0, 0, "brisk/Router/Driver/Rewrite.zep", 246);
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
				ZEPHIR_CALL_FUNCTION(&_8$$5, "preg_replace", &_9, 5, key, val, uri);
				zephir_check_call_status();
				zephir_get_strval(uri, _8$$5);
				break;
			} else if (zephir_is_callable(val TSRMLS_CC)) {
				ZEPHIR_CALL_FUNCTION(&_10$$6, "preg_replace_callback", &_11, 110, key, val, uri);
				zephir_check_call_status();
				zephir_get_strval(uri, _10$$6);
				break;
			} else if (_7$$4) {
				ZEPHIR_INIT_NVAR(_12$$7);
				object_init_ex(_12$$7, brisk_exception_routerexception_ce);
				ZEPHIR_INIT_NVAR(_15$$7);
				zephir_create_array(_15$$7, 1, 0 TSRMLS_CC);
				zephir_array_fetch_long(&_16$$7, val, 0, PH_NOISY | PH_READONLY, "brisk/Router/Driver/Rewrite.zep", 242 TSRMLS_CC);
				zephir_array_fetch_long(&_17$$7, val, 1, PH_NOISY | PH_READONLY, "brisk/Router/Driver/Rewrite.zep", 242 TSRMLS_CC);
				ZEPHIR_INIT_LNVAR(_18$$7);
				ZEPHIR_CONCAT_VSVS(_18$$7, _16$$7, "::", _17$$7, "()");
				zephir_array_fast_append(_15$$7, _18$$7);
				ZEPHIR_INIT_NVAR(_19$$7);
				ZVAL_STRING(_19$$7, "router.call_func_failed", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_CE_STATIC(&_13$$7, brisk_kernel_language_ce, "get", &_14, 0, _19$$7, _15$$7);
				zephir_check_temp_parameter(_19$$7);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, _12$$7, "__construct", &_20, 8, _13$$7);
				zephir_check_call_status();
				zephir_throw_exception_debug(_12$$7, "brisk/Router/Driver/Rewrite.zep", 242 TSRMLS_CC);
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
		ZEPHIR_CALL_CE_STATIC(&_22$$8, brisk_kernel_language_ce, "get", &_14, 13, _23$$8);
		zephir_check_temp_parameter(_23$$8);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, _21$$8, "__construct", &_20, 8, _22$$8);
		zephir_check_call_status();
		zephir_throw_exception_debug(_21$$8, "brisk/Router/Driver/Rewrite.zep", 247 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_CTOR(uri);

}

void zephir_init_static_properties_Brisk_Router_Driver_Rewrite(TSRMLS_D) {

	zval *_0, *_1;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_update_static_property_ce(brisk_router_driver_rewrite_ce, SL("_interceptors"), &_0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	array_init(_1);
	zephir_update_static_property_ce(brisk_router_driver_rewrite_ce, SL("_rules"), &_1 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}


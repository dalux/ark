
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


ZEPHIR_INIT_CLASS(Brisk_Kernel_Router_Rewrite) {

	ZEPHIR_REGISTER_CLASS_EX(Brisk\\Kernel\\Router, Rewrite, brisk, kernel_router_rewrite, brisk_kernel_router_routerfather_ce, brisk_kernel_router_rewrite_method_entry, 0);

	zend_declare_property_null(brisk_kernel_router_rewrite_ce, SL("_current_namespace"), ZEND_ACC_PRIVATE|ZEND_ACC_STATIC TSRMLS_CC);

	zend_declare_property_null(brisk_kernel_router_rewrite_ce, SL("_rules"), ZEND_ACC_PRIVATE|ZEND_ACC_STATIC TSRMLS_CC);

	zend_declare_property_string(brisk_kernel_router_rewrite_ce, SL("_auto_method"), "__init", ZEND_ACC_PRIVATE|ZEND_ACC_STATIC TSRMLS_CC);

	zend_declare_property_string(brisk_kernel_router_rewrite_ce, SL("_default_controller"), "Index", ZEND_ACC_PRIVATE|ZEND_ACC_STATIC TSRMLS_CC);

	zend_declare_property_string(brisk_kernel_router_rewrite_ce, SL("_default_action"), "index", ZEND_ACC_PRIVATE|ZEND_ACC_STATIC TSRMLS_CC);

	zend_declare_property_string(brisk_kernel_router_rewrite_ce, SL("_url_suffix"), ".html", ZEND_ACC_PRIVATE|ZEND_ACC_STATIC TSRMLS_CC);

	zend_declare_property_null(brisk_kernel_router_rewrite_ce, SL("_interceptors"), ZEND_ACC_PRIVATE|ZEND_ACC_STATIC TSRMLS_CC);

	return SUCCESS;

}

/**
 * Adding routing rewriting rules
 *
 * @param string rule
 * @param mixed redirect
 * @return null
 */
PHP_METHOD(Brisk_Kernel_Router_Rewrite, addRule) {

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


	zephir_update_static_property_array_multi_ce(brisk_kernel_router_rewrite_ce, SL("_rules"), &redirect TSRMLS_CC, SL("z"), 1, rule);
	ZEPHIR_MM_RESTORE();

}

/**
 * Add routing interceptors
 *
 * @param string ns_space
 * @param callable operator
 * @return null
 */
PHP_METHOD(Brisk_Kernel_Router_Rewrite, addInterceptor) {

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
	zephir_update_static_property_array_multi_ce(brisk_kernel_router_rewrite_ce, SL("_interceptors"), &operator TSRMLS_CC, SL("z"), 1, ns_space);
	ZEPHIR_MM_RESTORE();

}

/**
 * Get routing interceptors
 *
 * @param string ns_space
 * @return null
 */
PHP_METHOD(Brisk_Kernel_Router_Rewrite, getInterceptors) {

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
	_2 = zephir_fetch_static_property_ce(brisk_kernel_router_rewrite_ce, SL("_interceptors") TSRMLS_CC);
	zephir_is_iterable(_2, &_4, &_3, 0, 0, "brisk/Kernel/Router/Rewrite.zep", 74);
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
		object_init_ex(_8$$5, brisk_kernel_router_rewrite_ce);
		if (zephir_has_constructor(_8$$5 TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, _8$$5, "__construct", NULL, 0);
			zephir_check_call_status();
		}
		zephir_array_fast_append(_7$$5, _8$$5);
		ZEPHIR_INIT_NVAR(_8$$5);
		ZVAL_STRING(_8$$5, "todoUKSort", 1);
		zephir_array_fast_append(_7$$5, _8$$5);
		ZEPHIR_MAKE_REF(result);
		ZEPHIR_CALL_FUNCTION(NULL, "uksort", NULL, 55, result, _7$$5);
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
PHP_METHOD(Brisk_Kernel_Router_Rewrite, ready) {

	HashTable *_38$$8;
	HashPosition _37$$8;
	zval *_8$$3, *_62$$13, *_75$$14;
	zend_bool _48, _70, _35$$7, _58$$12;
	zval *_GET, *_0 = NULL, *_2, *_3 = NULL, *_4 = NULL, *config = NULL, *base_namespace = NULL, *_10 = NULL, *_11, *_12, *_13 = NULL, *_17, *_18, _19, *uri = NULL, *query = NULL, *controller = NULL, *url_suffix = NULL, *_21, *_23, _25, *_46 = NULL, _47, *_49, *nspace = NULL, *_69, *_71 = NULL, *_5$$3, *_6$$3 = NULL, *_9$$3 = NULL, *_14$$4 = NULL, *_15$$4, *_16$$4, *_22$$5, *_24$$6, _26$$7, *_27$$7, _28$$7, _29$$7, *_30$$7, _31$$7, *_32$$7, *_33$$7 = NULL, *list_query$$8 = NULL, *query_item$$8 = NULL, *query_name$$8 = NULL, *query_val$$8 = NULL, *_36$$8 = NULL, **_39$$8, _40$$9 = zval_used_for_init, *_41$$9 = NULL, _42$$9 = zval_used_for_init, _43$$9 = zval_used_for_init, *_44$$9 = NULL, _45$$9 = zval_used_for_init, _50$$11, *_51$$11 = NULL, *_52$$11, *_53$$11 = NULL, *controllers$$12 = NULL, *dist$$12 = NULL, *_54$$12, _55$$12 = zval_used_for_init, *_57$$12, _59$$12, *_60$$12, *_61$$13 = NULL, *_63$$13 = NULL, _64$$13, _65$$13, *_66$$13 = NULL, *c$$13 = NULL, *_73$$14, *_74$$14 = NULL, *_76$$14;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL, *_7 = NULL, *_20 = NULL, *_34 = NULL, *_56 = NULL, *_67 = NULL, *_68 = NULL, *_72 = NULL;

	ZEPHIR_MM_GROW();
	zephir_get_global(&_GET, SS("_GET") TSRMLS_CC);

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
		zephir_throw_exception_debug(_5$$3, "brisk/Kernel/Router/Rewrite.zep", 88 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(config);
	array_init(config);
	ZEPHIR_CALL_CE_STATIC(&_10, brisk_kernel_app_ce, "getinstance", &_1, 46);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(_11);
	zephir_read_property(&_11, _10, SL("config"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(_12);
	zephir_read_property(&_12, _11, SL("router"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_13, _12, "hasvalue", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(_13)) {
		ZEPHIR_CALL_CE_STATIC(&_14$$4, brisk_kernel_app_ce, "getinstance", &_1, 46);
		zephir_check_call_status();
		ZEPHIR_OBS_VAR(_15$$4);
		zephir_read_property(&_15$$4, _14$$4, SL("config"), PH_NOISY_CC);
		ZEPHIR_OBS_VAR(_16$$4);
		zephir_read_property(&_16$$4, _15$$4, SL("router"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&config, _16$$4, "getvalue", NULL, 0);
		zephir_check_call_status();
	}
	zephir_array_fetch_string(&_17, config, SL("options"), PH_NOISY | PH_READONLY, "brisk/Kernel/Router/Rewrite.zep", 95 TSRMLS_CC);
	zephir_array_fetch_string(&_18, _17, SL("base_namespace"), PH_NOISY | PH_READONLY, "brisk/Kernel/Router/Rewrite.zep", 95 TSRMLS_CC);
	ZEPHIR_SINIT_VAR(_19);
	ZVAL_STRING(&_19, "\\", 0);
	ZEPHIR_INIT_VAR(base_namespace);
	zephir_fast_trim(base_namespace, _18, &_19, ZEPHIR_TRIM_BOTH TSRMLS_CC);
	ZEPHIR_INIT_NVAR(_4);
	ZVAL_STRING(_4, "REQUEST_URI", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_CE_STATIC(&uri, brisk_kernel_server_ce, "getitem", &_20, 56, _4);
	zephir_check_temp_parameter(_4);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(controller);
	zephir_read_static_property_ce(&controller, brisk_kernel_router_rewrite_ce, SL("_default_controller") TSRMLS_CC);
	zephir_array_fetch_string(&_21, config, SL("options"), PH_READONLY, "brisk/Kernel/Router/Rewrite.zep", 101 TSRMLS_CC);
	if (zephir_array_isset_string(_21, SS("default_controller"))) {
		zephir_array_fetch_string(&_22$$5, config, SL("options"), PH_NOISY | PH_READONLY, "brisk/Kernel/Router/Rewrite.zep", 102 TSRMLS_CC);
		ZEPHIR_OBS_NVAR(controller);
		zephir_array_fetch_string(&controller, _22$$5, SL("default_controller"), PH_NOISY, "brisk/Kernel/Router/Rewrite.zep", 102 TSRMLS_CC);
	}
	ZEPHIR_INIT_NVAR(_4);
	zephir_ucfirst(_4, controller);
	ZEPHIR_CPY_WRT(controller, _4);
	ZEPHIR_OBS_VAR(url_suffix);
	zephir_read_static_property_ce(&url_suffix, brisk_kernel_router_rewrite_ce, SL("_url_suffix") TSRMLS_CC);
	zephir_array_fetch_string(&_23, config, SL("options"), PH_READONLY, "brisk/Kernel/Router/Rewrite.zep", 107 TSRMLS_CC);
	if (zephir_array_isset_string(_23, SS("url_suffix"))) {
		zephir_array_fetch_string(&_24$$6, config, SL("options"), PH_NOISY | PH_READONLY, "brisk/Kernel/Router/Rewrite.zep", 108 TSRMLS_CC);
		ZEPHIR_OBS_NVAR(url_suffix);
		zephir_array_fetch_string(&url_suffix, _24$$6, SL("url_suffix"), PH_NOISY, "brisk/Kernel/Router/Rewrite.zep", 108 TSRMLS_CC);
	}
	ZEPHIR_SINIT_VAR(_25);
	ZVAL_STRING(&_25, "?", 0);
	ZEPHIR_INIT_NVAR(_4);
	zephir_fast_strpos(_4, uri, &_25, 0 );
	if (!ZEPHIR_IS_FALSE(_4)) {
		ZEPHIR_SINIT_VAR(_26$$7);
		ZVAL_STRING(&_26$$7, "?", 0);
		ZEPHIR_INIT_VAR(_27$$7);
		zephir_fast_strpos(_27$$7, uri, &_26$$7, 0 );
		ZEPHIR_SINIT_VAR(_28$$7);
		ZVAL_LONG(&_28$$7, (zephir_get_numberval(_27$$7) + 1));
		ZEPHIR_INIT_VAR(query);
		zephir_substr(query, uri, zephir_get_intval(&_28$$7), 0, ZEPHIR_SUBSTR_NO_LENGTH);
		ZEPHIR_SINIT_VAR(_29$$7);
		ZVAL_STRING(&_29$$7, "?", 0);
		ZEPHIR_INIT_VAR(_30$$7);
		zephir_fast_strpos(_30$$7, uri, &_29$$7, 0 );
		ZEPHIR_SINIT_VAR(_31$$7);
		ZVAL_LONG(&_31$$7, 0);
		ZEPHIR_INIT_VAR(_32$$7);
		zephir_substr(_32$$7, uri, 0 , zephir_get_intval(_30$$7), 0);
		ZEPHIR_CPY_WRT(uri, _32$$7);
		ZEPHIR_CALL_CE_STATIC(&_33$$7, brisk_kernel_server_ce, "iscli", &_34, 20);
		zephir_check_call_status();
		_35$$7 = zephir_is_true(_33$$7);
		if (_35$$7) {
			_35$$7 = !ZEPHIR_IS_STRING(query, "");
		}
		if (_35$$7) {
			ZEPHIR_INIT_VAR(list_query$$8);
			zephir_fast_explode_str(list_query$$8, SL("&"), query, LONG_MAX TSRMLS_CC);
			ZEPHIR_INIT_VAR(_36$$8);
			zephir_is_iterable(list_query$$8, &_38$$8, &_37$$8, 0, 0, "brisk/Kernel/Router/Rewrite.zep", 124);
			for (
			  ; zend_hash_get_current_data_ex(_38$$8, (void**) &_39$$8, &_37$$8) == SUCCESS
			  ; zend_hash_move_forward_ex(_38$$8, &_37$$8)
			) {
				ZEPHIR_GET_HMKEY(_36$$8, _38$$8, _37$$8);
				ZEPHIR_GET_HVALUE(query_item$$8, _39$$8);
				ZEPHIR_SINIT_NVAR(_40$$9);
				ZVAL_STRING(&_40$$9, "=", 0);
				ZEPHIR_INIT_NVAR(_41$$9);
				zephir_fast_strpos(_41$$9, query_item$$8, &_40$$9, 0 );
				ZEPHIR_SINIT_NVAR(_42$$9);
				ZVAL_LONG(&_42$$9, 0);
				ZEPHIR_INIT_NVAR(query_name$$8);
				zephir_substr(query_name$$8, query_item$$8, 0 , zephir_get_intval(_41$$9), 0);
				ZEPHIR_SINIT_NVAR(_43$$9);
				ZVAL_STRING(&_43$$9, "=", 0);
				ZEPHIR_INIT_NVAR(_44$$9);
				zephir_fast_strpos(_44$$9, query_item$$8, &_43$$9, 0 );
				ZEPHIR_SINIT_NVAR(_45$$9);
				ZVAL_LONG(&_45$$9, (zephir_get_numberval(_44$$9) + 1));
				ZEPHIR_INIT_NVAR(query_val$$8);
				zephir_substr(query_val$$8, query_item$$8, zephir_get_intval(&_45$$9), 0, ZEPHIR_SUBSTR_NO_LENGTH);
				if (!(zephir_array_isset(_GET, query_name$$8))) {
					zephir_array_update_zval(&_GET, query_name$$8, &query_val$$8, PH_COPY | PH_SEPARATE);
				}
			}
		}
	}
	ZEPHIR_CALL_METHOD(&_46, this_ptr, "_rewrite", NULL, 66, uri);
	zephir_check_call_status();
	ZEPHIR_SINIT_VAR(_47);
	ZVAL_STRING(&_47, "/", 0);
	ZEPHIR_INIT_NVAR(uri);
	zephir_fast_trim(uri, _46, &_47, ZEPHIR_TRIM_BOTH TSRMLS_CC);
	_48 = zephir_is_true(url_suffix);
	if (_48) {
		ZEPHIR_INIT_VAR(_49);
		zephir_fast_strpos(_49, uri, url_suffix, 0 );
		_48 = !ZEPHIR_IS_FALSE_IDENTICAL(_49);
	}
	if (_48) {
		ZEPHIR_SINIT_VAR(_50$$11);
		ZVAL_STRING(&_50$$11, "~%s$~i", 0);
		ZEPHIR_CALL_FUNCTION(&_51$$11, "sprintf", NULL, 40, &_50$$11, url_suffix);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_52$$11);
		ZVAL_STRING(_52$$11, "", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_FUNCTION(&_53$$11, "preg_replace", NULL, 4, _51$$11, _52$$11, uri);
		zephir_check_temp_parameter(_52$$11);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(uri, _53$$11);
	}
	if (!ZEPHIR_IS_STRING(uri, "")) {
		ZEPHIR_INIT_VAR(_54$$12);
		zephir_fast_explode_str(_54$$12, SL("/"), uri, LONG_MAX TSRMLS_CC);
		ZEPHIR_SINIT_VAR(_55$$12);
		ZVAL_STRING(&_55$$12, "ucfirst", 0);
		ZEPHIR_CALL_FUNCTION(&controllers$$12, "array_map", &_56, 67, &_55$$12, _54$$12);
		zephir_check_call_status();
		ZEPHIR_MAKE_REF(controllers$$12);
		ZEPHIR_CALL_FUNCTION(&dist$$12, "end", NULL, 68, controllers$$12);
		ZEPHIR_UNREF(controllers$$12);
		zephir_check_call_status();
		ZEPHIR_SINIT_NVAR(_55$$12);
		ZVAL_STRING(&_55$$12, ".", 0);
		ZEPHIR_INIT_VAR(_57$$12);
		zephir_fast_strpos(_57$$12, dist$$12, &_55$$12, 0 );
		_58$$12 = zephir_is_true(_57$$12);
		if (!(_58$$12)) {
			ZEPHIR_SINIT_VAR(_59$$12);
			ZVAL_STRING(&_59$$12, "_", 0);
			ZEPHIR_INIT_VAR(_60$$12);
			zephir_fast_strpos(_60$$12, dist$$12, &_59$$12, 0 );
			_58$$12 = zephir_is_true(_60$$12);
		}
		if (_58$$12) {
			ZEPHIR_INIT_VAR(_61$$13);
			ZEPHIR_INIT_VAR(_62$$13);
			zephir_create_array(_62$$13, 2, 0 TSRMLS_CC);
			ZEPHIR_INIT_VAR(_63$$13);
			ZVAL_STRING(_63$$13, ".", 1);
			zephir_array_fast_append(_62$$13, _63$$13);
			ZEPHIR_INIT_NVAR(_63$$13);
			ZVAL_STRING(_63$$13, "_", 1);
			zephir_array_fast_append(_62$$13, _63$$13);
			ZEPHIR_SINIT_VAR(_64$$13);
			ZVAL_STRING(&_64$$13, ".", 0);
			zephir_fast_str_replace(&_61$$13, _62$$13, &_64$$13, dist$$12 TSRMLS_CC);
			ZEPHIR_CPY_WRT(dist$$12, _61$$13);
			ZEPHIR_INIT_NVAR(_61$$13);
			zephir_fast_explode_str(_61$$13, SL("."), dist$$12, LONG_MAX TSRMLS_CC);
			ZEPHIR_CPY_WRT(dist$$12, _61$$13);
			ZEPHIR_SINIT_VAR(_65$$13);
			ZVAL_STRING(&_65$$13, "ucfirst", 0);
			ZEPHIR_CALL_FUNCTION(&_66$$13, "array_map", &_56, 67, &_65$$13, dist$$12);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(dist$$12, _66$$13);
			ZEPHIR_INIT_NVAR(_61$$13);
			zephir_fast_join_str(_61$$13, SL(""), dist$$12 TSRMLS_CC);
			ZEPHIR_CPY_WRT(dist$$12, _61$$13);
			ZEPHIR_INIT_VAR(c$$13);
			ZVAL_LONG(c$$13, zephir_fast_count_int(controllers$$12 TSRMLS_CC));
			zephir_array_update_long(&controllers$$12, ((zephir_get_numberval(c$$13) - 1)), &dist$$12, PH_COPY | PH_SEPARATE ZEPHIR_DEBUG_PARAMS_DUMMY);
		}
		ZEPHIR_INIT_NVAR(controller);
		zephir_fast_join_str(controller, SL("\\"), controllers$$12 TSRMLS_CC);
	}
	ZEPHIR_INIT_VAR(nspace);
	ZEPHIR_CONCAT_VSV(nspace, base_namespace, "\\", controller);
	ZEPHIR_CALL_CE_STATIC(NULL, brisk_kernel_request_ce, "setdata", &_67, 58, _GET);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_69);
	ZVAL_BOOL(_69, 1);
	ZEPHIR_CALL_CE_STATIC(NULL, brisk_kernel_request_ce, "setready", &_68, 59, _69);
	zephir_check_call_status();
	_70 = !(zephir_class_exists(nspace, zephir_is_true(ZEPHIR_GLOBAL(global_false))  TSRMLS_CC));
	if (_70) {
		ZEPHIR_CALL_CE_STATIC(&_71, brisk_kernel_loader_ce, "findclass", &_72, 60, nspace);
		zephir_check_call_status();
		_70 = !zephir_is_true(_71);
	}
	if (_70) {
		ZEPHIR_INIT_VAR(_73$$14);
		object_init_ex(_73$$14, brisk_exception_controllernotfoundexception_ce);
		ZEPHIR_INIT_VAR(_75$$14);
		zephir_create_array(_75$$14, 1, 0 TSRMLS_CC);
		zephir_array_fast_append(_75$$14, nspace);
		ZEPHIR_INIT_VAR(_76$$14);
		ZVAL_STRING(_76$$14, "router.controller_not_found", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_CE_STATIC(&_74$$14, brisk_kernel_language_ce, "get", &_7, 27, _76$$14, _75$$14);
		zephir_check_temp_parameter(_76$$14);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, _73$$14, "__construct", NULL, 28, _74$$14);
		zephir_check_call_status();
		zephir_throw_exception_debug(_73$$14, "brisk/Kernel/Router/Rewrite.zep", 154 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_static_property_ce(brisk_kernel_router_rewrite_ce, SL("_current_namespace"), &nspace TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Routing path distribution
 *
 * @return null
 */
PHP_METHOD(Brisk_Kernel_Router_Rewrite, dispatch) {

	HashTable *_24$$8;
	HashPosition _23$$8;
	zval *_15$$6, *_20$$7, *_31$$11;
	zend_class_entry *_28;
	zval *nspace = NULL, *action = NULL, *auto_method = NULL, *config = NULL, *_0 = NULL, *_2, *_3, *_4 = NULL, *_8, *_10, *ref = NULL, *_17 = NULL, *interceptors = NULL, *instance = NULL, *_27 = NULL, *output = NULL, *_5$$3 = NULL, *_6$$3, *_7$$3, *_9$$4, *_11$$5, *_12$$6, *_13$$6 = NULL, *_16$$6, *_18$$7, *_19$$7 = NULL, *_21$$7, *op$$8 = NULL, *result$$8 = NULL, *_22$$8 = NULL, **_25$$8, *_26$$9 = NULL, *_29$$11, *_30$$11 = NULL, *_32$$11;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL, *_14 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(nspace);
	zephir_read_static_property_ce(&nspace, brisk_kernel_router_rewrite_ce, SL("_current_namespace") TSRMLS_CC);
	ZEPHIR_INIT_VAR(config);
	array_init(config);
	ZEPHIR_CALL_CE_STATIC(&_0, brisk_kernel_app_ce, "getinstance", &_1, 46);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(_2);
	zephir_read_property(&_2, _0, SL("config"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(_3);
	zephir_read_property(&_3, _2, SL("router"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_4, _3, "hasvalue", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(_4)) {
		ZEPHIR_CALL_CE_STATIC(&_5$$3, brisk_kernel_app_ce, "getinstance", &_1, 46);
		zephir_check_call_status();
		ZEPHIR_OBS_VAR(_6$$3);
		zephir_read_property(&_6$$3, _5$$3, SL("config"), PH_NOISY_CC);
		ZEPHIR_OBS_VAR(_7$$3);
		zephir_read_property(&_7$$3, _6$$3, SL("router"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&config, _7$$3, "getvalue", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_OBS_VAR(action);
	zephir_read_static_property_ce(&action, brisk_kernel_router_rewrite_ce, SL("_default_action") TSRMLS_CC);
	ZEPHIR_OBS_VAR(auto_method);
	zephir_read_static_property_ce(&auto_method, brisk_kernel_router_rewrite_ce, SL("_auto_method") TSRMLS_CC);
	zephir_array_fetch_string(&_8, config, SL("options"), PH_READONLY, "brisk/Kernel/Router/Rewrite.zep", 175 TSRMLS_CC);
	if (zephir_array_isset_string(_8, SS("default_action"))) {
		zephir_array_fetch_string(&_9$$4, config, SL("options"), PH_NOISY | PH_READONLY, "brisk/Kernel/Router/Rewrite.zep", 176 TSRMLS_CC);
		ZEPHIR_OBS_NVAR(action);
		zephir_array_fetch_string(&action, _9$$4, SL("default_action"), PH_NOISY, "brisk/Kernel/Router/Rewrite.zep", 176 TSRMLS_CC);
	}
	zephir_array_fetch_string(&_10, config, SL("options"), PH_READONLY, "brisk/Kernel/Router/Rewrite.zep", 178 TSRMLS_CC);
	if (zephir_array_isset_string(_10, SS("auto_method"))) {
		zephir_array_fetch_string(&_11$$5, config, SL("options"), PH_NOISY | PH_READONLY, "brisk/Kernel/Router/Rewrite.zep", 179 TSRMLS_CC);
		ZEPHIR_OBS_NVAR(auto_method);
		zephir_array_fetch_string(&auto_method, _11$$5, SL("auto_method"), PH_NOISY, "brisk/Kernel/Router/Rewrite.zep", 179 TSRMLS_CC);
	}
	if (!(zephir_class_exists(nspace, 1 TSRMLS_CC))) {
		ZEPHIR_INIT_VAR(_12$$6);
		object_init_ex(_12$$6, brisk_exception_classnotfoundexception_ce);
		ZEPHIR_INIT_VAR(_15$$6);
		zephir_create_array(_15$$6, 1, 0 TSRMLS_CC);
		zephir_array_fast_append(_15$$6, nspace);
		ZEPHIR_INIT_VAR(_16$$6);
		ZVAL_STRING(_16$$6, "router.class_not_found", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_CE_STATIC(&_13$$6, brisk_kernel_language_ce, "get", &_14, 27, _16$$6, _15$$6);
		zephir_check_temp_parameter(_16$$6);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, _12$$6, "__construct", NULL, 28, _13$$6);
		zephir_check_call_status();
		zephir_throw_exception_debug(_12$$6, "brisk/Kernel/Router/Rewrite.zep", 182 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(ref);
	object_init_ex(ref, zephir_get_internal_ce(SS("reflectionclass") TSRMLS_CC));
	ZEPHIR_CALL_METHOD(NULL, ref, "__construct", NULL, 61, nspace);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_17, ref, "isabstract", NULL, 62);
	zephir_check_call_status();
	if (zephir_is_true(_17)) {
		ZEPHIR_INIT_VAR(_18$$7);
		object_init_ex(_18$$7, brisk_exception_controllerexception_ce);
		ZEPHIR_INIT_VAR(_20$$7);
		zephir_create_array(_20$$7, 1, 0 TSRMLS_CC);
		zephir_array_fast_append(_20$$7, nspace);
		ZEPHIR_INIT_VAR(_21$$7);
		ZVAL_STRING(_21$$7, "router.controller_is_protected", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_CE_STATIC(&_19$$7, brisk_kernel_language_ce, "get", &_14, 27, _21$$7, _20$$7);
		zephir_check_temp_parameter(_21$$7);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, _18$$7, "__construct", NULL, 28, _19$$7);
		zephir_check_call_status();
		zephir_throw_exception_debug(_18$$7, "brisk/Kernel/Router/Rewrite.zep", 188 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_SELF(&interceptors, "getinterceptors", NULL, 0, nspace);
	zephir_check_call_status();
	if (zephir_fast_count_int(interceptors TSRMLS_CC) > 0) {
		ZEPHIR_INIT_VAR(_22$$8);
		zephir_is_iterable(interceptors, &_24$$8, &_23$$8, 0, 0, "brisk/Kernel/Router/Rewrite.zep", 202);
		for (
		  ; zend_hash_get_current_data_ex(_24$$8, (void**) &_25$$8, &_23$$8) == SUCCESS
		  ; zend_hash_move_forward_ex(_24$$8, &_23$$8)
		) {
			ZEPHIR_GET_HMKEY(_22$$8, _24$$8, _23$$8);
			ZEPHIR_GET_HVALUE(op$$8, _25$$8);
			ZEPHIR_INIT_NVAR(_26$$9);
			array_init(_26$$9);
			ZEPHIR_INIT_NVAR(result$$8);
			ZEPHIR_CALL_USER_FUNC_ARRAY(result$$8, op$$8, _26$$9);
			zephir_check_call_status();
			if (Z_TYPE_P(result$$8) == IS_STRING) {
				zend_print_zval(result$$8, 0);
				ZEPHIR_MM_RESTORE();
				zephir_exit_empty();
			}
		}
	}
	ZEPHIR_INIT_VAR(instance);
	zephir_fetch_safe_class(_27, nspace);
		_28 = zend_fetch_class(Z_STRVAL_P(_27), Z_STRLEN_P(_27), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	object_init_ex(instance, _28);
	if (zephir_has_constructor(instance TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, instance, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	if (!((zephir_method_exists(instance, action TSRMLS_CC)  == SUCCESS))) {
		ZEPHIR_INIT_VAR(_29$$11);
		object_init_ex(_29$$11, brisk_exception_actionnotfoundexception_ce);
		ZEPHIR_INIT_VAR(_31$$11);
		zephir_create_array(_31$$11, 1, 0 TSRMLS_CC);
		zephir_array_fast_append(_31$$11, action);
		ZEPHIR_INIT_VAR(_32$$11);
		ZVAL_STRING(_32$$11, "router.action_not_found", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_CE_STATIC(&_30$$11, brisk_kernel_language_ce, "get", &_14, 27, _32$$11, _31$$11);
		zephir_check_temp_parameter(_32$$11);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, _29$$11, "__construct", NULL, 28, _30$$11);
		zephir_check_call_status();
		zephir_throw_exception_debug(_29$$11, "brisk/Kernel/Router/Rewrite.zep", 207 TSRMLS_CC);
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

PHP_METHOD(Brisk_Kernel_Router_Rewrite, todoUKSort) {

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

PHP_METHOD(Brisk_Kernel_Router_Rewrite, _rewrite) {

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


	_0 = zephir_fetch_static_property_ce(brisk_kernel_router_rewrite_ce, SL("_rules") TSRMLS_CC);
	zephir_is_iterable(_0, &_2, &_1, 0, 0, "brisk/Kernel/Router/Rewrite.zep", 249);
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
				ZEPHIR_CALL_FUNCTION(&_10$$6, "preg_replace_callback", &_11, 65, key, val, uri);
				zephir_check_call_status();
				zephir_get_strval(uri, _10$$6);
				break;
			} else if (_7$$4) {
				ZEPHIR_INIT_NVAR(_12$$7);
				object_init_ex(_12$$7, brisk_exception_routerexception_ce);
				ZEPHIR_INIT_NVAR(_15$$7);
				zephir_create_array(_15$$7, 1, 0 TSRMLS_CC);
				zephir_array_fetch_long(&_16$$7, val, 0, PH_NOISY | PH_READONLY, "brisk/Kernel/Router/Rewrite.zep", 245 TSRMLS_CC);
				zephir_array_fetch_long(&_17$$7, val, 1, PH_NOISY | PH_READONLY, "brisk/Kernel/Router/Rewrite.zep", 245 TSRMLS_CC);
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
				zephir_throw_exception_debug(_12$$7, "brisk/Kernel/Router/Rewrite.zep", 245 TSRMLS_CC);
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
		zephir_throw_exception_debug(_21$$8, "brisk/Kernel/Router/Rewrite.zep", 250 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_CTOR(uri);

}

void zephir_init_static_properties_Brisk_Kernel_Router_Rewrite(TSRMLS_D) {

	zval *_0, *_1;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_update_static_property_ce(brisk_kernel_router_rewrite_ce, SL("_interceptors"), &_0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	array_init(_1);
	zephir_update_static_property_ce(brisk_kernel_router_rewrite_ce, SL("_rules"), &_1 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}


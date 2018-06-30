
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


ZEPHIR_INIT_CLASS(Brisk_Router_RewriteRouter) {

	ZEPHIR_REGISTER_CLASS_EX(Brisk\\Router, RewriteRouter, brisk, router_rewriterouter, brisk_router_routerfather_ce, brisk_router_rewriterouter_method_entry, 0);

	zend_declare_property_null(brisk_router_rewriterouter_ce, SL("_current_namespace"), ZEND_ACC_PRIVATE|ZEND_ACC_STATIC TSRMLS_CC);

	zend_declare_property_null(brisk_router_rewriterouter_ce, SL("_rules"), ZEND_ACC_PRIVATE|ZEND_ACC_STATIC TSRMLS_CC);

	zend_declare_property_string(brisk_router_rewriterouter_ce, SL("_auto_method"), "__init", ZEND_ACC_PRIVATE|ZEND_ACC_STATIC TSRMLS_CC);

	zend_declare_property_string(brisk_router_rewriterouter_ce, SL("_default_controller"), "Index", ZEND_ACC_PRIVATE|ZEND_ACC_STATIC TSRMLS_CC);

	zend_declare_property_string(brisk_router_rewriterouter_ce, SL("_default_action"), "index", ZEND_ACC_PRIVATE|ZEND_ACC_STATIC TSRMLS_CC);

	zend_declare_property_string(brisk_router_rewriterouter_ce, SL("_url_suffix"), ".html", ZEND_ACC_PRIVATE|ZEND_ACC_STATIC TSRMLS_CC);

	zend_declare_property_null(brisk_router_rewriterouter_ce, SL("_interceptors"), ZEND_ACC_PRIVATE|ZEND_ACC_STATIC TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Brisk_Router_RewriteRouter, addRule) {

	zval *rule_param = NULL, *redirect, redirect_sub;
	zval rule;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&rule);
	ZVAL_UNDEF(&redirect_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &rule_param, &redirect);

	if (UNEXPECTED(Z_TYPE_P(rule_param) != IS_STRING && Z_TYPE_P(rule_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'rule' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(rule_param) == IS_STRING)) {
		zephir_get_strval(&rule, rule_param);
	} else {
		ZEPHIR_INIT_VAR(&rule);
		ZVAL_EMPTY_STRING(&rule);
	}


	zephir_update_static_property_array_multi_ce(brisk_router_rewriterouter_ce, SL("_rules"), redirect TSRMLS_CC, SL("z"), 1, &rule);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Brisk_Router_RewriteRouter, addInterceptor) {

	zval *ns_space_param = NULL, *operator, operator_sub, _0, _1;
	zval ns_space;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&ns_space);
	ZVAL_UNDEF(&operator_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &ns_space_param, &operator);

	if (UNEXPECTED(Z_TYPE_P(ns_space_param) != IS_STRING && Z_TYPE_P(ns_space_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'ns_space' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(ns_space_param) == IS_STRING)) {
		zephir_get_strval(&ns_space, ns_space_param);
	} else {
		ZEPHIR_INIT_VAR(&ns_space);
		ZVAL_EMPTY_STRING(&ns_space);
	}
	if (UNEXPECTED(zephir_is_callable(operator TSRMLS_CC) != 1)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'operator' must be a callable") TSRMLS_CC);
		RETURN_MM_NULL();
	}


	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "\\");
	zephir_fast_trim(&_0, &ns_space, &_1, ZEPHIR_TRIM_LEFT TSRMLS_CC);
	zephir_get_strval(&ns_space, &_0);
	zephir_update_static_property_array_multi_ce(brisk_router_rewriterouter_ce, SL("_interceptors"), operator TSRMLS_CC, SL("z"), 1, &ns_space);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Brisk_Router_RewriteRouter, getInterceptors) {

	zval _7$$5;
	zend_string *_5;
	zend_ulong _4;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *ns_space_param = NULL, _0, _1, result, key, val, _2, *_3, _6$$3, _8$$5;
	zval ns_space;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&ns_space);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&val);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_7$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &ns_space_param);

	if (UNEXPECTED(Z_TYPE_P(ns_space_param) != IS_STRING && Z_TYPE_P(ns_space_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'ns_space' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(ns_space_param) == IS_STRING)) {
		zephir_get_strval(&ns_space, ns_space_param);
	} else {
		ZEPHIR_INIT_VAR(&ns_space);
		ZVAL_EMPTY_STRING(&ns_space);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "\\");
	zephir_fast_trim(&_0, &ns_space, &_1, ZEPHIR_TRIM_LEFT TSRMLS_CC);
	zephir_get_strval(&ns_space, &_0);
	ZEPHIR_INIT_VAR(&result);
	array_init(&result);
	zephir_read_static_property_ce(&_2, brisk_router_rewriterouter_ce, SL("_interceptors"), PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_2, 0, "brisk/Router/RewriteRouter.zep", 50);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_2), _4, _5, _3)
	{
		ZEPHIR_INIT_NVAR(&key);
		if (_5 != NULL) { 
			ZVAL_STR_COPY(&key, _5);
		} else {
			ZVAL_LONG(&key, _4);
		}
		ZEPHIR_INIT_NVAR(&val);
		ZVAL_COPY(&val, _3);
		ZEPHIR_INIT_NVAR(&_6$$3);
		zephir_fast_strpos(&_6$$3, &ns_space, &key, 0 );
		if (!ZEPHIR_IS_FALSE_IDENTICAL(&_6$$3)) {
			zephir_array_update_zval(&result, &key, &val, PH_COPY | PH_SEPARATE);
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&val);
	ZEPHIR_INIT_NVAR(&key);
	if (zephir_fast_count_int(&result TSRMLS_CC) > 0) {
		ZEPHIR_INIT_VAR(&_7$$5);
		zephir_create_array(&_7$$5, 2, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_8$$5);
		object_init_ex(&_8$$5, brisk_router_rewriterouter_ce);
		if (zephir_has_constructor(&_8$$5 TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, &_8$$5, "__construct", NULL, 0);
			zephir_check_call_status();
		}
		zephir_array_fast_append(&_7$$5, &_8$$5);
		ZEPHIR_INIT_NVAR(&_8$$5);
		ZVAL_STRING(&_8$$5, "todoUKSort");
		zephir_array_fast_append(&_7$$5, &_8$$5);
		ZEPHIR_MAKE_REF(&result);
		ZEPHIR_CALL_FUNCTION(NULL, "uksort", NULL, 68, &result, &_7$$5);
		ZEPHIR_UNREF(&result);
		zephir_check_call_status();
	}
	RETURN_CCTOR(&result);

}

PHP_METHOD(Brisk_Router_RewriteRouter, ready) {

	zend_string *_35$$8;
	zend_ulong _34$$8;
	zval _70, _58$$13, _86$$14;
	zend_bool _44, _80, _31$$7, _54$$12;
	zval *_GET, __$false, uri, query, controller, url_suffix, _1, _2, _4, _5, _6, _7, _12, _13, _14, _15, _16, _21, _42, _43, _45, path_now, ns_part, _65, _67, _68, _69, _71, _72, _73, _74, nspace, _79, _81, _8$$3, _9$$3, _10$$3, _11$$3, _17$$5, _18$$5, _19$$5, _20$$5, _22$$7, _23$$7, _24$$7, _25$$7, _26$$7, _27$$7, _28$$7, _29$$7, list_query$$8, query_item$$8, query_name$$8, query_val$$8, _32$$8, *_33$$8, _36$$9, _37$$9, _38$$9, _39$$9, _40$$9, _41$$9, _46$$11, _47$$11, _48$$11, controllers$$12, dist$$12, _50$$12, _51$$12, _53$$12, _55$$12, _56$$12, _61$$12, _62$$12, _63$$12, _64$$12, _57$$13, _59$$13, _60$$13, c$$13, _83$$14, _84$$14, _87$$14;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL, *_3 = NULL, *_30 = NULL, *_49 = NULL, *_52 = NULL, *_66 = NULL, *_75 = NULL, *_76 = NULL, *_77 = NULL, *_78 = NULL, *_82 = NULL, *_85 = NULL;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&uri);
	ZVAL_UNDEF(&query);
	ZVAL_UNDEF(&controller);
	ZVAL_UNDEF(&url_suffix);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_16);
	ZVAL_UNDEF(&_21);
	ZVAL_UNDEF(&_42);
	ZVAL_UNDEF(&_43);
	ZVAL_UNDEF(&_45);
	ZVAL_UNDEF(&path_now);
	ZVAL_UNDEF(&ns_part);
	ZVAL_UNDEF(&_65);
	ZVAL_UNDEF(&_67);
	ZVAL_UNDEF(&_68);
	ZVAL_UNDEF(&_69);
	ZVAL_UNDEF(&_71);
	ZVAL_UNDEF(&_72);
	ZVAL_UNDEF(&_73);
	ZVAL_UNDEF(&_74);
	ZVAL_UNDEF(&nspace);
	ZVAL_UNDEF(&_79);
	ZVAL_UNDEF(&_81);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_10$$3);
	ZVAL_UNDEF(&_11$$3);
	ZVAL_UNDEF(&_17$$5);
	ZVAL_UNDEF(&_18$$5);
	ZVAL_UNDEF(&_19$$5);
	ZVAL_UNDEF(&_20$$5);
	ZVAL_UNDEF(&_22$$7);
	ZVAL_UNDEF(&_23$$7);
	ZVAL_UNDEF(&_24$$7);
	ZVAL_UNDEF(&_25$$7);
	ZVAL_UNDEF(&_26$$7);
	ZVAL_UNDEF(&_27$$7);
	ZVAL_UNDEF(&_28$$7);
	ZVAL_UNDEF(&_29$$7);
	ZVAL_UNDEF(&list_query$$8);
	ZVAL_UNDEF(&query_item$$8);
	ZVAL_UNDEF(&query_name$$8);
	ZVAL_UNDEF(&query_val$$8);
	ZVAL_UNDEF(&_32$$8);
	ZVAL_UNDEF(&_36$$9);
	ZVAL_UNDEF(&_37$$9);
	ZVAL_UNDEF(&_38$$9);
	ZVAL_UNDEF(&_39$$9);
	ZVAL_UNDEF(&_40$$9);
	ZVAL_UNDEF(&_41$$9);
	ZVAL_UNDEF(&_46$$11);
	ZVAL_UNDEF(&_47$$11);
	ZVAL_UNDEF(&_48$$11);
	ZVAL_UNDEF(&controllers$$12);
	ZVAL_UNDEF(&dist$$12);
	ZVAL_UNDEF(&_50$$12);
	ZVAL_UNDEF(&_51$$12);
	ZVAL_UNDEF(&_53$$12);
	ZVAL_UNDEF(&_55$$12);
	ZVAL_UNDEF(&_56$$12);
	ZVAL_UNDEF(&_61$$12);
	ZVAL_UNDEF(&_62$$12);
	ZVAL_UNDEF(&_63$$12);
	ZVAL_UNDEF(&_64$$12);
	ZVAL_UNDEF(&_57$$13);
	ZVAL_UNDEF(&_59$$13);
	ZVAL_UNDEF(&_60$$13);
	ZVAL_UNDEF(&c$$13);
	ZVAL_UNDEF(&_83$$14);
	ZVAL_UNDEF(&_84$$14);
	ZVAL_UNDEF(&_87$$14);
	ZVAL_UNDEF(&_70);
	ZVAL_UNDEF(&_58$$13);
	ZVAL_UNDEF(&_86$$14);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_GET, SL("_GET"));

	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "REQUEST_URI");
	ZEPHIR_CALL_CE_STATIC(&uri, brisk_kernel_server_ce, "getitem", &_0, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_CALL_CE_STATIC(&_2, brisk_kernel_app_ce, "getinstance", &_3, 0);
	zephir_check_call_status();
	zephir_read_property(&_4, &_2, SL("config"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_5, &_4, SL("router"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_6, &_5, SL("default_controller"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_7, &_6, "hasvalue", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&_7)) {
		ZEPHIR_CALL_CE_STATIC(&_8$$3, brisk_kernel_app_ce, "getinstance", &_3, 0);
		zephir_check_call_status();
		zephir_read_property(&_9$$3, &_8$$3, SL("config"), PH_NOISY_CC | PH_READONLY);
		zephir_read_property(&_10$$3, &_9$$3, SL("router"), PH_NOISY_CC | PH_READONLY);
		zephir_read_property(&_11$$3, &_10$$3, SL("default_controller"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&controller, &_11$$3, "getvalue", NULL, 0);
		zephir_check_call_status();
	} else {
		ZEPHIR_OBS_NVAR(&controller);
		zephir_read_static_property_ce(&controller, brisk_router_rewriterouter_ce, SL("_default_controller"), PH_NOISY_CC);
	}
	ZEPHIR_INIT_NVAR(&_1);
	zephir_ucfirst(&_1, &controller);
	ZEPHIR_CPY_WRT(&controller, &_1);
	ZEPHIR_CALL_CE_STATIC(&_12, brisk_kernel_app_ce, "getinstance", &_3, 0);
	zephir_check_call_status();
	zephir_read_property(&_13, &_12, SL("config"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_14, &_13, SL("router"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_15, &_14, SL("url_suffix"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_16, &_15, "hasvalue", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&_16)) {
		ZEPHIR_CALL_CE_STATIC(&_17$$5, brisk_kernel_app_ce, "getinstance", &_3, 0);
		zephir_check_call_status();
		zephir_read_property(&_18$$5, &_17$$5, SL("config"), PH_NOISY_CC | PH_READONLY);
		zephir_read_property(&_19$$5, &_18$$5, SL("router"), PH_NOISY_CC | PH_READONLY);
		zephir_read_property(&_20$$5, &_19$$5, SL("url_suffix"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&url_suffix, &_20$$5, "getvalue", NULL, 0);
		zephir_check_call_status();
	} else {
		ZEPHIR_OBS_NVAR(&url_suffix);
		zephir_read_static_property_ce(&url_suffix, brisk_router_rewriterouter_ce, SL("_url_suffix"), PH_NOISY_CC);
	}
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "?");
	ZEPHIR_INIT_VAR(&_21);
	zephir_fast_strpos(&_21, &uri, &_1, 0 );
	if (!ZEPHIR_IS_FALSE(&_21)) {
		ZEPHIR_INIT_VAR(&_22$$7);
		ZVAL_STRING(&_22$$7, "?");
		ZEPHIR_INIT_VAR(&_23$$7);
		zephir_fast_strpos(&_23$$7, &uri, &_22$$7, 0 );
		ZVAL_LONG(&_24$$7, (zephir_get_numberval(&_23$$7) + 1));
		ZEPHIR_INIT_VAR(&query);
		zephir_substr(&query, &uri, zephir_get_intval(&_24$$7), 0, ZEPHIR_SUBSTR_NO_LENGTH);
		ZEPHIR_INIT_VAR(&_25$$7);
		ZVAL_STRING(&_25$$7, "?");
		ZEPHIR_INIT_VAR(&_26$$7);
		zephir_fast_strpos(&_26$$7, &uri, &_25$$7, 0 );
		ZVAL_LONG(&_27$$7, 0);
		ZEPHIR_INIT_VAR(&_28$$7);
		zephir_substr(&_28$$7, &uri, 0 , zephir_get_intval(&_26$$7), 0);
		ZEPHIR_CPY_WRT(&uri, &_28$$7);
		ZEPHIR_CALL_CE_STATIC(&_29$$7, brisk_kernel_server_ce, "iscli", &_30, 0);
		zephir_check_call_status();
		_31$$7 = zephir_is_true(&_29$$7);
		if (_31$$7) {
			_31$$7 = !ZEPHIR_IS_STRING(&query, "");
		}
		if (_31$$7) {
			ZEPHIR_INIT_VAR(&list_query$$8);
			zephir_fast_explode_str(&list_query$$8, SL("&"), &query, LONG_MAX TSRMLS_CC);
			ZEPHIR_INIT_VAR(&_32$$8);
			zephir_is_iterable(&list_query$$8, 0, "brisk/Router/RewriteRouter.zep", 85);
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&list_query$$8), _34$$8, _35$$8, _33$$8)
			{
				ZEPHIR_INIT_NVAR(&_32$$8);
				if (_35$$8 != NULL) { 
					ZVAL_STR_COPY(&_32$$8, _35$$8);
				} else {
					ZVAL_LONG(&_32$$8, _34$$8);
				}
				ZEPHIR_INIT_NVAR(&query_item$$8);
				ZVAL_COPY(&query_item$$8, _33$$8);
				ZEPHIR_INIT_NVAR(&_36$$9);
				ZVAL_STRING(&_36$$9, "=");
				ZEPHIR_INIT_NVAR(&_37$$9);
				zephir_fast_strpos(&_37$$9, &query_item$$8, &_36$$9, 0 );
				ZVAL_LONG(&_38$$9, 0);
				ZEPHIR_INIT_NVAR(&query_name$$8);
				zephir_substr(&query_name$$8, &query_item$$8, 0 , zephir_get_intval(&_37$$9), 0);
				ZEPHIR_INIT_NVAR(&_39$$9);
				ZVAL_STRING(&_39$$9, "=");
				ZEPHIR_INIT_NVAR(&_40$$9);
				zephir_fast_strpos(&_40$$9, &query_item$$8, &_39$$9, 0 );
				ZVAL_LONG(&_41$$9, (zephir_get_numberval(&_40$$9) + 1));
				ZEPHIR_INIT_NVAR(&query_val$$8);
				zephir_substr(&query_val$$8, &query_item$$8, zephir_get_intval(&_41$$9), 0, ZEPHIR_SUBSTR_NO_LENGTH);
				if (!(zephir_array_isset(_GET, &query_name$$8))) {
					zephir_array_update_zval(_GET, &query_name$$8, &query_val$$8, PH_COPY | PH_SEPARATE);
				}
			} ZEND_HASH_FOREACH_END();
			ZEPHIR_INIT_NVAR(&query_item$$8);
			ZEPHIR_INIT_NVAR(&_32$$8);
		}
	}
	ZEPHIR_CALL_METHOD(&_42, this_ptr, "_rewrite", NULL, 76, &uri);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_43);
	ZVAL_STRING(&_43, "/");
	ZEPHIR_INIT_NVAR(&uri);
	zephir_fast_trim(&uri, &_42, &_43, ZEPHIR_TRIM_BOTH TSRMLS_CC);
	_44 = zephir_is_true(&url_suffix);
	if (_44) {
		ZEPHIR_INIT_VAR(&_45);
		zephir_fast_strpos(&_45, &uri, &url_suffix, 0 );
		_44 = !ZEPHIR_IS_FALSE_IDENTICAL(&_45);
	}
	if (_44) {
		ZEPHIR_INIT_VAR(&_46$$11);
		ZVAL_STRING(&_46$$11, "~%s$~i");
		ZEPHIR_CALL_FUNCTION(&_47$$11, "sprintf", NULL, 4, &_46$$11, &url_suffix);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_46$$11);
		ZVAL_STRING(&_46$$11, "");
		ZEPHIR_CALL_FUNCTION(&_48$$11, "preg_replace", NULL, 2, &_47$$11, &_46$$11, &uri);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&uri, &_48$$11);
	}
	ZEPHIR_CALL_CE_STATIC(&path_now, brisk_kernel_app_ce, "getcontrollerdir", &_49, 0);
	zephir_check_call_status();
	if (!ZEPHIR_IS_STRING(&uri, "")) {
		ZEPHIR_INIT_VAR(&_50$$12);
		zephir_fast_explode_str(&_50$$12, SL("/"), &uri, LONG_MAX TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_51$$12);
		ZVAL_STRING(&_51$$12, "ucfirst");
		ZEPHIR_CALL_FUNCTION(&controllers$$12, "array_map", &_52, 70, &_51$$12, &_50$$12);
		zephir_check_call_status();
		ZEPHIR_MAKE_REF(&controllers$$12);
		ZEPHIR_CALL_FUNCTION(&dist$$12, "end", NULL, 53, &controllers$$12);
		ZEPHIR_UNREF(&controllers$$12);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_51$$12);
		ZVAL_STRING(&_51$$12, ".");
		ZEPHIR_INIT_VAR(&_53$$12);
		zephir_fast_strpos(&_53$$12, &dist$$12, &_51$$12, 0 );
		_54$$12 = zephir_is_true(&_53$$12);
		if (!(_54$$12)) {
			ZEPHIR_INIT_VAR(&_55$$12);
			ZVAL_STRING(&_55$$12, "_");
			ZEPHIR_INIT_VAR(&_56$$12);
			zephir_fast_strpos(&_56$$12, &dist$$12, &_55$$12, 0 );
			_54$$12 = zephir_is_true(&_56$$12);
		}
		if (_54$$12) {
			ZEPHIR_INIT_VAR(&_57$$13);
			ZEPHIR_INIT_VAR(&_58$$13);
			zephir_create_array(&_58$$13, 2, 0 TSRMLS_CC);
			ZEPHIR_INIT_VAR(&_59$$13);
			ZVAL_STRING(&_59$$13, ".");
			zephir_array_fast_append(&_58$$13, &_59$$13);
			ZEPHIR_INIT_NVAR(&_59$$13);
			ZVAL_STRING(&_59$$13, "_");
			zephir_array_fast_append(&_58$$13, &_59$$13);
			ZEPHIR_INIT_NVAR(&_59$$13);
			ZVAL_STRING(&_59$$13, ".");
			zephir_fast_str_replace(&_57$$13, &_58$$13, &_59$$13, &dist$$12 TSRMLS_CC);
			ZEPHIR_CPY_WRT(&dist$$12, &_57$$13);
			ZEPHIR_INIT_NVAR(&_57$$13);
			zephir_fast_explode_str(&_57$$13, SL("."), &dist$$12, LONG_MAX TSRMLS_CC);
			ZEPHIR_CPY_WRT(&dist$$12, &_57$$13);
			ZEPHIR_INIT_NVAR(&_57$$13);
			ZVAL_STRING(&_57$$13, "ucfirst");
			ZEPHIR_CALL_FUNCTION(&_60$$13, "array_map", &_52, 70, &_57$$13, &dist$$12);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&dist$$12, &_60$$13);
			ZEPHIR_INIT_NVAR(&_57$$13);
			zephir_fast_join_str(&_57$$13, SL(""), &dist$$12 TSRMLS_CC);
			ZEPHIR_CPY_WRT(&dist$$12, &_57$$13);
			ZEPHIR_INIT_VAR(&c$$13);
			ZVAL_LONG(&c$$13, zephir_fast_count_int(&controllers$$12 TSRMLS_CC));
			zephir_array_update_long(&controllers$$12, ((zephir_get_numberval(&c$$13) - 1)), &dist$$12, PH_COPY | PH_SEPARATE ZEPHIR_DEBUG_PARAMS_DUMMY);
		}
		ZEPHIR_INIT_NVAR(&controller);
		zephir_fast_join_str(&controller, SL("\\"), &controllers$$12 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_61$$12);
		ZEPHIR_INIT_VAR(&_62$$12);
		ZVAL_STRING(&_62$$12, "/");
		zephir_fast_join(&_61$$12, &_62$$12, &controllers$$12 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_63$$12);
		ZEPHIR_CONCAT_VSV(&_63$$12, &path_now, "/", &_61$$12);
		ZEPHIR_CPY_WRT(&path_now, &_63$$12);
		ZEPHIR_CALL_FUNCTION(&_64$$12, "dirname", NULL, 18, &path_now);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&path_now, &_64$$12);
	}
	ZEPHIR_CALL_CE_STATIC(&_65, brisk_kernel_app_ce, "getbasedir", &_66, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_CE_STATIC(&_67, brisk_kernel_app_ce, "getcontrollerdir", &_49, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_68);
	ZVAL_STRING(&_68, "");
	ZEPHIR_INIT_VAR(&ns_part);
	zephir_fast_str_replace(&ns_part, &_65, &_68, &_67 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_69);
	ZEPHIR_INIT_VAR(&_70);
	zephir_create_array(&_70, 2, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_71);
	ZVAL_STRING(&_71, "/");
	zephir_array_fast_append(&_70, &_71);
	ZEPHIR_INIT_NVAR(&_71);
	ZVAL_STRING(&_71, "\\");
	zephir_array_fast_append(&_70, &_71);
	ZEPHIR_INIT_NVAR(&_71);
	ZVAL_STRING(&_71, "\\");
	zephir_fast_str_replace(&_69, &_70, &_71, &ns_part TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_72);
	ZVAL_STRING(&_72, "\\");
	ZEPHIR_INIT_NVAR(&ns_part);
	zephir_fast_trim(&ns_part, &_69, &_72, ZEPHIR_TRIM_BOTH TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_73);
	zephir_fast_explode_str(&_73, SL("\\"), &ns_part, LONG_MAX TSRMLS_CC);
	ZEPHIR_CPY_WRT(&ns_part, &_73);
	ZEPHIR_INIT_NVAR(&_73);
	ZVAL_STRING(&_73, "ucfirst");
	ZEPHIR_CALL_FUNCTION(&_74, "array_map", &_52, 70, &_73, &ns_part);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&ns_part, &_74);
	ZEPHIR_INIT_NVAR(&_73);
	zephir_fast_join_str(&_73, SL("\\"), &ns_part TSRMLS_CC);
	ZEPHIR_CPY_WRT(&ns_part, &_73);
	ZEPHIR_CALL_CE_STATIC(&_74, brisk_kernel_app_ce, "getname", &_75, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&nspace);
	ZEPHIR_CONCAT_VSVSV(&nspace, &_74, "\\", &ns_part, "\\", &controller);
	ZEPHIR_INIT_NVAR(&_73);
	ZVAL_STRING(&_73, "~");
	ZEPHIR_CALL_CE_STATIC(NULL, brisk_kernel_loader_ce, "setalias", &_76, 0, &_73, &path_now);
	zephir_check_call_status();
	ZEPHIR_CALL_CE_STATIC(NULL, brisk_kernel_request_ce, "setdata", &_77, 0, _GET);
	zephir_check_call_status();
	ZVAL_BOOL(&_79, 1);
	ZEPHIR_CALL_CE_STATIC(NULL, brisk_kernel_request_ce, "setready", &_78, 0, &_79);
	zephir_check_call_status();
	_80 = !(zephir_class_exists(&nspace, zephir_is_true(&__$false)  TSRMLS_CC));
	if (_80) {
		ZEPHIR_CALL_CE_STATIC(&_81, brisk_kernel_loader_ce, "findclass", &_82, 0, &nspace);
		zephir_check_call_status();
		_80 = !zephir_is_true(&_81);
	}
	if (_80) {
		ZEPHIR_INIT_VAR(&_83$$14);
		object_init_ex(&_83$$14, brisk_exception_routerexception_ce);
		ZEPHIR_INIT_VAR(&_86$$14);
		zephir_create_array(&_86$$14, 1, 0 TSRMLS_CC);
		zephir_array_fast_append(&_86$$14, &nspace);
		ZEPHIR_INIT_VAR(&_87$$14);
		ZVAL_STRING(&_87$$14, "router.controller_not_found");
		ZEPHIR_CALL_CE_STATIC(&_84$$14, brisk_kernel_language_ce, "get", &_85, 0, &_87$$14, &_86$$14);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_83$$14, "__construct", NULL, 3, &_84$$14);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_83$$14, "brisk/Router/RewriteRouter.zep", 126 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zend_update_static_property(brisk_router_rewriterouter_ce, ZEND_STRL("_current_namespace"), &nspace);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Brisk_Router_RewriteRouter, dispatch) {

	zend_string *_32$$9;
	zend_ulong _31$$9;
	zval _22$$7, _27$$8, _38$$12;
	zend_class_entry *_35;
	zval nspace, action, auto_method, _0, _2, _3, _4, _5, _10, _11, _12, _13, _14, ref, _24, interceptors, instance, _34, output, _6$$3, _7$$3, _8$$3, _9$$3, _15$$5, _16$$5, _17$$5, _18$$5, _19$$7, _20$$7, _23$$7, _25$$8, _26$$8, _28$$8, op$$9, result$$9, _29$$9, *_30$$9, _33$$10, _36$$12, _37$$12, _39$$12;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL, *_21 = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&nspace);
	ZVAL_UNDEF(&action);
	ZVAL_UNDEF(&auto_method);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&ref);
	ZVAL_UNDEF(&_24);
	ZVAL_UNDEF(&interceptors);
	ZVAL_UNDEF(&instance);
	ZVAL_UNDEF(&_34);
	ZVAL_UNDEF(&output);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_15$$5);
	ZVAL_UNDEF(&_16$$5);
	ZVAL_UNDEF(&_17$$5);
	ZVAL_UNDEF(&_18$$5);
	ZVAL_UNDEF(&_19$$7);
	ZVAL_UNDEF(&_20$$7);
	ZVAL_UNDEF(&_23$$7);
	ZVAL_UNDEF(&_25$$8);
	ZVAL_UNDEF(&_26$$8);
	ZVAL_UNDEF(&_28$$8);
	ZVAL_UNDEF(&op$$9);
	ZVAL_UNDEF(&result$$9);
	ZVAL_UNDEF(&_29$$9);
	ZVAL_UNDEF(&_33$$10);
	ZVAL_UNDEF(&_36$$12);
	ZVAL_UNDEF(&_37$$12);
	ZVAL_UNDEF(&_39$$12);
	ZVAL_UNDEF(&_22$$7);
	ZVAL_UNDEF(&_27$$8);
	ZVAL_UNDEF(&_38$$12);

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(&nspace);
	zephir_read_static_property_ce(&nspace, brisk_router_rewriterouter_ce, SL("_current_namespace"), PH_NOISY_CC);
	ZEPHIR_CALL_CE_STATIC(&_0, brisk_kernel_app_ce, "getinstance", &_1, 0);
	zephir_check_call_status();
	zephir_read_property(&_2, &_0, SL("config"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_3, &_2, SL("router"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_4, &_3, SL("default_action"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_5, &_4, "hasvalue", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&_5)) {
		ZEPHIR_CALL_CE_STATIC(&_6$$3, brisk_kernel_app_ce, "getinstance", &_1, 0);
		zephir_check_call_status();
		zephir_read_property(&_7$$3, &_6$$3, SL("config"), PH_NOISY_CC | PH_READONLY);
		zephir_read_property(&_8$$3, &_7$$3, SL("router"), PH_NOISY_CC | PH_READONLY);
		zephir_read_property(&_9$$3, &_8$$3, SL("default_action"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&action, &_9$$3, "getvalue", NULL, 0);
		zephir_check_call_status();
	} else {
		ZEPHIR_OBS_NVAR(&action);
		zephir_read_static_property_ce(&action, brisk_router_rewriterouter_ce, SL("_default_action"), PH_NOISY_CC);
	}
	ZEPHIR_CALL_CE_STATIC(&_10, brisk_kernel_app_ce, "getinstance", &_1, 0);
	zephir_check_call_status();
	zephir_read_property(&_11, &_10, SL("config"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_12, &_11, SL("router"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_13, &_12, SL("auto_method"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_14, &_13, "hasvalue", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&_14)) {
		ZEPHIR_CALL_CE_STATIC(&_15$$5, brisk_kernel_app_ce, "getinstance", &_1, 0);
		zephir_check_call_status();
		zephir_read_property(&_16$$5, &_15$$5, SL("config"), PH_NOISY_CC | PH_READONLY);
		zephir_read_property(&_17$$5, &_16$$5, SL("router"), PH_NOISY_CC | PH_READONLY);
		zephir_read_property(&_18$$5, &_17$$5, SL("auto_method"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&auto_method, &_18$$5, "getvalue", NULL, 0);
		zephir_check_call_status();
	} else {
		ZEPHIR_OBS_NVAR(&auto_method);
		zephir_read_static_property_ce(&auto_method, brisk_router_rewriterouter_ce, SL("_auto_method"), PH_NOISY_CC);
	}
	if (!(zephir_class_exists(&nspace, 1 TSRMLS_CC))) {
		ZEPHIR_INIT_VAR(&_19$$7);
		object_init_ex(&_19$$7, brisk_exception_routerexception_ce);
		ZEPHIR_INIT_VAR(&_22$$7);
		zephir_create_array(&_22$$7, 1, 0 TSRMLS_CC);
		zephir_array_fast_append(&_22$$7, &nspace);
		ZEPHIR_INIT_VAR(&_23$$7);
		ZVAL_STRING(&_23$$7, "router.class_not_found");
		ZEPHIR_CALL_CE_STATIC(&_20$$7, brisk_kernel_language_ce, "get", &_21, 0, &_23$$7, &_22$$7);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_19$$7, "__construct", NULL, 3, &_20$$7);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_19$$7, "brisk/Router/RewriteRouter.zep", 146 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&ref);
	object_init_ex(&ref, zephir_get_internal_ce(SL("reflectionclass")));
	ZEPHIR_CALL_METHOD(NULL, &ref, "__construct", NULL, 71, &nspace);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_24, &ref, "isabstract", NULL, 72);
	zephir_check_call_status();
	if (zephir_is_true(&_24)) {
		ZEPHIR_INIT_VAR(&_25$$8);
		object_init_ex(&_25$$8, brisk_exception_routerexception_ce);
		ZEPHIR_INIT_VAR(&_27$$8);
		zephir_create_array(&_27$$8, 1, 0 TSRMLS_CC);
		zephir_array_fast_append(&_27$$8, &nspace);
		ZEPHIR_INIT_VAR(&_28$$8);
		ZVAL_STRING(&_28$$8, "router.controller_is_protected");
		ZEPHIR_CALL_CE_STATIC(&_26$$8, brisk_kernel_language_ce, "get", &_21, 0, &_28$$8, &_27$$8);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_25$$8, "__construct", NULL, 3, &_26$$8);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_25$$8, "brisk/Router/RewriteRouter.zep", 152 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_SELF(&interceptors, "getinterceptors", NULL, 0, &nspace);
	zephir_check_call_status();
	if (zephir_fast_count_int(&interceptors TSRMLS_CC) > 0) {
		ZEPHIR_INIT_VAR(&_29$$9);
		zephir_is_iterable(&interceptors, 0, "brisk/Router/RewriteRouter.zep", 166);
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&interceptors), _31$$9, _32$$9, _30$$9)
		{
			ZEPHIR_INIT_NVAR(&_29$$9);
			if (_32$$9 != NULL) { 
				ZVAL_STR_COPY(&_29$$9, _32$$9);
			} else {
				ZVAL_LONG(&_29$$9, _31$$9);
			}
			ZEPHIR_INIT_NVAR(&op$$9);
			ZVAL_COPY(&op$$9, _30$$9);
			ZEPHIR_INIT_NVAR(&_33$$10);
			array_init(&_33$$10);
			ZEPHIR_INIT_NVAR(&result$$9);
			ZEPHIR_CALL_USER_FUNC_ARRAY(&result$$9, &op$$9, &_33$$10);
			zephir_check_call_status();
			if (Z_TYPE_P(&result$$9) == IS_STRING) {
				zend_print_zval(&result$$9, 0);
				ZEPHIR_MM_RESTORE();
				zephir_exit_empty();
			}
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&op$$9);
		ZEPHIR_INIT_NVAR(&_29$$9);
	}
	ZEPHIR_INIT_VAR(&instance);
	zephir_fetch_safe_class(&_34, &nspace);
	_35 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_34), Z_STRLEN_P(&_34), ZEND_FETCH_CLASS_AUTO);
	object_init_ex(&instance, _35);
	if (zephir_has_constructor(&instance TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, &instance, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	if (!((zephir_method_exists(&instance, &action TSRMLS_CC)  == SUCCESS))) {
		ZEPHIR_INIT_VAR(&_36$$12);
		object_init_ex(&_36$$12, brisk_exception_routerexception_ce);
		ZEPHIR_INIT_VAR(&_38$$12);
		zephir_create_array(&_38$$12, 1, 0 TSRMLS_CC);
		zephir_array_fast_append(&_38$$12, &action);
		ZEPHIR_INIT_VAR(&_39$$12);
		ZVAL_STRING(&_39$$12, "router.action_not_found");
		ZEPHIR_CALL_CE_STATIC(&_37$$12, brisk_kernel_language_ce, "get", &_21, 0, &_39$$12, &_38$$12);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_36$$12, "__construct", NULL, 3, &_37$$12);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_36$$12, "brisk/Router/RewriteRouter.zep", 171 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&output);
	ZVAL_NULL(&output);
	if ((zephir_method_exists(&instance, &auto_method TSRMLS_CC)  == SUCCESS)) {
		ZEPHIR_CALL_METHOD_ZVAL(&output, &instance, &auto_method, NULL, 0);
		zephir_check_call_status();
	}
	if (Z_TYPE_P(&output) == IS_NULL) {
		ZEPHIR_CALL_METHOD_ZVAL(&output, &instance, &action, NULL, 0);
		zephir_check_call_status();
	}
	zend_print_zval(&output, 0);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Brisk_Router_RewriteRouter, todoUKSort) {

	zval *a_param = NULL, *b_param = NULL, len_a, len_b, _0;
	zval a, b;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&a);
	ZVAL_UNDEF(&b);
	ZVAL_UNDEF(&len_a);
	ZVAL_UNDEF(&len_b);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &a_param, &b_param);

	if (UNEXPECTED(Z_TYPE_P(a_param) != IS_STRING && Z_TYPE_P(a_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'a' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(a_param) == IS_STRING)) {
		zephir_get_strval(&a, a_param);
	} else {
		ZEPHIR_INIT_VAR(&a);
		ZVAL_EMPTY_STRING(&a);
	}
	if (UNEXPECTED(Z_TYPE_P(b_param) != IS_STRING && Z_TYPE_P(b_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'b' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(b_param) == IS_STRING)) {
		zephir_get_strval(&b, b_param);
	} else {
		ZEPHIR_INIT_VAR(&b);
		ZVAL_EMPTY_STRING(&b);
	}


	ZEPHIR_INIT_VAR(&len_a);
	ZVAL_LONG(&len_a, zephir_fast_strlen_ev(&a));
	ZEPHIR_INIT_VAR(&len_b);
	ZVAL_LONG(&len_b, zephir_fast_strlen_ev(&b));
	if (ZEPHIR_IS_EQUAL(&len_a, &len_b)) {
		RETURN_MM_LONG(0);
	}
	ZEPHIR_INIT_VAR(&_0);
	if (ZEPHIR_GT(&len_a, &len_b)) {
		ZVAL_LONG(&_0, 1);
	} else {
		ZVAL_LONG(&_0, -1);
	}
	RETURN_CCTOR(&_0);

}

PHP_METHOD(Brisk_Router_RewriteRouter, _rewrite) {

	zval _15$$7;
	zend_bool _7$$4;
	zend_string *_3;
	zend_ulong _2;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_9 = NULL, *_11 = NULL, *_14 = NULL, *_20 = NULL;
	zval *uri_param = NULL, key, val, _0, *_1, _4$$3, _5$$3, _6$$3, _8$$5, _10$$6, _12$$7, _13$$7, _16$$7, _17$$7, _18$$7, _19$$7, _21$$8, _22$$8, _23$$8;
	zval uri;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&uri);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&val);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_10$$6);
	ZVAL_UNDEF(&_12$$7);
	ZVAL_UNDEF(&_13$$7);
	ZVAL_UNDEF(&_16$$7);
	ZVAL_UNDEF(&_17$$7);
	ZVAL_UNDEF(&_18$$7);
	ZVAL_UNDEF(&_19$$7);
	ZVAL_UNDEF(&_21$$8);
	ZVAL_UNDEF(&_22$$8);
	ZVAL_UNDEF(&_23$$8);
	ZVAL_UNDEF(&_15$$7);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &uri_param);

	if (UNEXPECTED(Z_TYPE_P(uri_param) != IS_STRING && Z_TYPE_P(uri_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'uri' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(uri_param) == IS_STRING)) {
		zephir_get_strval(&uri, uri_param);
	} else {
		ZEPHIR_INIT_VAR(&uri);
		ZVAL_EMPTY_STRING(&uri);
	}


	zephir_read_static_property_ce(&_0, brisk_router_rewriterouter_ce, SL("_rules"), PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_0, 0, "brisk/Router/RewriteRouter.zep", 213);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_0), _2, _3, _1)
	{
		ZEPHIR_INIT_NVAR(&key);
		if (_3 != NULL) { 
			ZVAL_STR_COPY(&key, _3);
		} else {
			ZVAL_LONG(&key, _2);
		}
		ZEPHIR_INIT_NVAR(&val);
		ZVAL_COPY(&val, _1);
		ZEPHIR_INIT_LNVAR(_4$$3);
		ZEPHIR_CONCAT_SVS(&_4$$3, "~", &key, "~i");
		ZEPHIR_CPY_WRT(&key, &_4$$3);
		ZEPHIR_INIT_NVAR(&_5$$3);
		ZEPHIR_INIT_NVAR(&_6$$3);
		zephir_preg_match(&_6$$3, &key, &uri, &_5$$3, 0, 0 , 0  TSRMLS_CC);
		if (zephir_is_true(&_6$$3)) {
			_7$$4 = !(zephir_is_callable(&val TSRMLS_CC));
			if (_7$$4) {
				_7$$4 = Z_TYPE_P(&val) == IS_ARRAY;
			}
			if (Z_TYPE_P(&val) == IS_STRING) {
				ZEPHIR_CALL_FUNCTION(&_8$$5, "preg_replace", &_9, 2, &key, &val, &uri);
				zephir_check_call_status();
				zephir_get_strval(&uri, &_8$$5);
				break;
			} else if (zephir_is_callable(&val TSRMLS_CC)) {
				ZEPHIR_CALL_FUNCTION(&_10$$6, "preg_replace_callback", &_11, 75, &key, &val, &uri);
				zephir_check_call_status();
				zephir_get_strval(&uri, &_10$$6);
				break;
			} else if (_7$$4) {
				ZEPHIR_INIT_NVAR(&_12$$7);
				object_init_ex(&_12$$7, brisk_exception_routerexception_ce);
				ZEPHIR_INIT_NVAR(&_15$$7);
				zephir_create_array(&_15$$7, 1, 0 TSRMLS_CC);
				zephir_array_fetch_long(&_16$$7, &val, 0, PH_NOISY | PH_READONLY, "brisk/Router/RewriteRouter.zep", 209 TSRMLS_CC);
				zephir_array_fetch_long(&_17$$7, &val, 1, PH_NOISY | PH_READONLY, "brisk/Router/RewriteRouter.zep", 209 TSRMLS_CC);
				ZEPHIR_INIT_LNVAR(_18$$7);
				ZEPHIR_CONCAT_VSVS(&_18$$7, &_16$$7, "::", &_17$$7, "()");
				zephir_array_fast_append(&_15$$7, &_18$$7);
				ZEPHIR_INIT_NVAR(&_19$$7);
				ZVAL_STRING(&_19$$7, "router.call_func_failed");
				ZEPHIR_CALL_CE_STATIC(&_13$$7, brisk_kernel_language_ce, "get", &_14, 0, &_19$$7, &_15$$7);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, &_12$$7, "__construct", &_20, 3, &_13$$7);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_12$$7, "brisk/Router/RewriteRouter.zep", 209 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&val);
	ZEPHIR_INIT_NVAR(&key);
	if (!(Z_TYPE_P(&uri) == IS_STRING)) {
		ZEPHIR_INIT_VAR(&_21$$8);
		object_init_ex(&_21$$8, brisk_exception_routerexception_ce);
		ZEPHIR_INIT_VAR(&_23$$8);
		ZVAL_STRING(&_23$$8, "router.uri_must_string");
		ZEPHIR_CALL_CE_STATIC(&_22$$8, brisk_kernel_language_ce, "get", &_14, 0, &_23$$8);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_21$$8, "__construct", &_20, 3, &_22$$8);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_21$$8, "brisk/Router/RewriteRouter.zep", 214 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_CTOR(&uri);

}

void zephir_init_static_properties_Brisk_Router_RewriteRouter(TSRMLS_D) {

	zval _0, _1;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	array_init(&_0);
	zend_update_static_property(brisk_router_rewriterouter_ce, ZEND_STRL("_interceptors"), &_0);
	ZEPHIR_INIT_VAR(&_1);
	array_init(&_1);
	zend_update_static_property(brisk_router_rewriterouter_ce, ZEND_STRL("_rules"), &_1);
	ZEPHIR_MM_RESTORE();

}


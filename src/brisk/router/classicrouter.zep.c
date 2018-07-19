
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
#include "kernel/file.h"


ZEPHIR_INIT_CLASS(Brisk_Router_ClassicRouter) {

	ZEPHIR_REGISTER_CLASS_EX(Brisk\\Router, ClassicRouter, brisk, router_classicrouter, brisk_router_routerfather_ce, brisk_router_classicrouter_method_entry, 0);

	zend_declare_property_bool(brisk_router_classicrouter_ce, SL("_module_support"), 0, ZEND_ACC_PRIVATE|ZEND_ACC_STATIC TSRMLS_CC);

	zend_declare_property_null(brisk_router_classicrouter_ce, SL("_rules"), ZEND_ACC_PRIVATE|ZEND_ACC_STATIC TSRMLS_CC);

	zend_declare_property_string(brisk_router_classicrouter_ce, SL("_auto_method"), "__init", ZEND_ACC_PRIVATE|ZEND_ACC_STATIC TSRMLS_CC);

	zend_declare_property_string(brisk_router_classicrouter_ce, SL("_default_module"), "Index", ZEND_ACC_PRIVATE|ZEND_ACC_STATIC TSRMLS_CC);

	zend_declare_property_string(brisk_router_classicrouter_ce, SL("_default_controller"), "Index", ZEND_ACC_PRIVATE|ZEND_ACC_STATIC TSRMLS_CC);

	zend_declare_property_string(brisk_router_classicrouter_ce, SL("_default_action"), "index", ZEND_ACC_PRIVATE|ZEND_ACC_STATIC TSRMLS_CC);

	zend_declare_property_string(brisk_router_classicrouter_ce, SL("_url_suffix"), ".html", ZEND_ACC_PRIVATE|ZEND_ACC_STATIC TSRMLS_CC);

	zend_declare_property_null(brisk_router_classicrouter_ce, SL("_interceptors"), ZEND_ACC_PRIVATE|ZEND_ACC_STATIC TSRMLS_CC);

	zend_declare_property_null(brisk_router_classicrouter_ce, SL("_module"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(brisk_router_classicrouter_ce, SL("_controller"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(brisk_router_classicrouter_ce, SL("_action"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(brisk_router_classicrouter_ce, SL("_namespace"), ZEND_ACC_PRIVATE TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Brisk_Router_ClassicRouter, openModuleSupport) {

	zval *default_module_param = NULL, __$true;
	zval default_module;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&default_module);
	ZVAL_BOOL(&__$true, 1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &default_module_param);

	if (UNEXPECTED(Z_TYPE_P(default_module_param) != IS_STRING && Z_TYPE_P(default_module_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'default_module' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(default_module_param) == IS_STRING)) {
		zephir_get_strval(&default_module, default_module_param);
	} else {
		ZEPHIR_INIT_VAR(&default_module);
		ZVAL_EMPTY_STRING(&default_module);
	}


	zend_update_static_property(brisk_router_classicrouter_ce, ZEND_STRL("_module_support"), &__$true);
	zend_update_static_property(brisk_router_classicrouter_ce, ZEND_STRL("_default_module"), &default_module);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Brisk_Router_ClassicRouter, addRule) {

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


	zephir_update_static_property_array_multi_ce(brisk_router_classicrouter_ce, SL("_rules"), redirect TSRMLS_CC, SL("z"), 1, &rule);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Brisk_Router_ClassicRouter, addInterceptor) {

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
	zephir_update_static_property_array_multi_ce(brisk_router_classicrouter_ce, SL("_interceptors"), operator TSRMLS_CC, SL("z"), 1, &ns_space);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Brisk_Router_ClassicRouter, getInterceptors) {

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
	zephir_read_static_property_ce(&_2, brisk_router_classicrouter_ce, SL("_interceptors"), PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_2, 0, "brisk/Router/ClassicRouter.zep", 66);
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
		object_init_ex(&_8$$5, brisk_router_classicrouter_ce);
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

PHP_METHOD(Brisk_Router_ClassicRouter, ready) {

	zend_bool _30;
	zval _12, _36$$4;
	zval __$false, uri, result, params, _1, _2, _3, _4, path_now, _5, ns_part, ns_space, _7, _8, _9, _10, _11, _13, _14, _15, _16, _17, _18, _23, _24, _26, _29, _31, _19$$3, _20$$3, _21$$3, _22$$3, _33$$4, _34$$4, _37$$4;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL, *_6 = NULL, *_25 = NULL, *_27 = NULL, *_28 = NULL, *_32 = NULL, *_35 = NULL;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&uri);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&path_now);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&ns_part);
	ZVAL_UNDEF(&ns_space);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_16);
	ZVAL_UNDEF(&_17);
	ZVAL_UNDEF(&_18);
	ZVAL_UNDEF(&_23);
	ZVAL_UNDEF(&_24);
	ZVAL_UNDEF(&_26);
	ZVAL_UNDEF(&_29);
	ZVAL_UNDEF(&_31);
	ZVAL_UNDEF(&_19$$3);
	ZVAL_UNDEF(&_20$$3);
	ZVAL_UNDEF(&_21$$3);
	ZVAL_UNDEF(&_22$$3);
	ZVAL_UNDEF(&_33$$4);
	ZVAL_UNDEF(&_34$$4);
	ZVAL_UNDEF(&_37$$4);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_36$$4);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "REQUEST_URI");
	ZEPHIR_CALL_CE_STATIC(&uri, brisk_kernel_server_ce, "getitem", &_0, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&result, this_ptr, "_parseuri", NULL, 69, &uri);
	zephir_check_call_status();
	zephir_array_fetch_string(&_2, &result, SL("module"), PH_NOISY | PH_READONLY, "brisk/Router/ClassicRouter.zep", 78 TSRMLS_CC);
	zephir_update_property_zval(this_ptr, SL("_module"), &_2);
	zephir_array_fetch_string(&_3, &result, SL("controller"), PH_NOISY | PH_READONLY, "brisk/Router/ClassicRouter.zep", 79 TSRMLS_CC);
	zephir_update_property_zval(this_ptr, SL("_controller"), &_3);
	zephir_array_fetch_string(&_4, &result, SL("action"), PH_NOISY | PH_READONLY, "brisk/Router/ClassicRouter.zep", 80 TSRMLS_CC);
	zephir_update_property_zval(this_ptr, SL("_action"), &_4);
	ZEPHIR_OBS_VAR(&params);
	zephir_array_fetch_string(&params, &result, SL("params"), PH_NOISY, "brisk/Router/ClassicRouter.zep", 81 TSRMLS_CC);
	ZEPHIR_CALL_CE_STATIC(&_5, brisk_kernel_app_ce, "getinstance", &_6, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&path_now, &_5, "getcontrollerdir", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_CE_STATIC(&_7, brisk_kernel_app_ce, "getinstance", &_6, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "base_dir");
	ZEPHIR_CALL_METHOD(&_8, &_7, "getapp", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_CALL_CE_STATIC(&_9, brisk_kernel_app_ce, "getinstance", &_6, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_10, &_9, "getcontrollerdir", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "");
	ZEPHIR_INIT_VAR(&ns_part);
	zephir_fast_str_replace(&ns_part, &_8, &_1, &_10 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_11);
	ZEPHIR_INIT_VAR(&_12);
	zephir_create_array(&_12, 2, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_13);
	ZVAL_STRING(&_13, "/");
	zephir_array_fast_append(&_12, &_13);
	ZEPHIR_INIT_NVAR(&_13);
	ZVAL_STRING(&_13, "\\");
	zephir_array_fast_append(&_12, &_13);
	ZEPHIR_INIT_NVAR(&_13);
	ZVAL_STRING(&_13, "\\");
	zephir_fast_str_replace(&_11, &_12, &_13, &ns_part TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_14);
	ZVAL_STRING(&_14, "\\");
	ZEPHIR_INIT_NVAR(&ns_part);
	zephir_fast_trim(&ns_part, &_11, &_14, ZEPHIR_TRIM_BOTH TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_15);
	zephir_fast_explode_str(&_15, SL("\\"), &ns_part, LONG_MAX TSRMLS_CC);
	ZEPHIR_CPY_WRT(&ns_part, &_15);
	ZEPHIR_INIT_NVAR(&_15);
	ZVAL_STRING(&_15, "ucfirst");
	ZEPHIR_CALL_FUNCTION(&_16, "array_map", NULL, 70, &_15, &ns_part);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&ns_part, &_16);
	ZEPHIR_INIT_NVAR(&_15);
	zephir_fast_join_str(&_15, SL("\\"), &ns_part TSRMLS_CC);
	ZEPHIR_CPY_WRT(&ns_part, &_15);
	ZEPHIR_CALL_CE_STATIC(&_16, brisk_kernel_app_ce, "getinstance", &_6, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_15);
	ZVAL_STRING(&_15, "name");
	ZEPHIR_CALL_METHOD(&_17, &_16, "getapp", NULL, 0, &_15);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&ns_space);
	ZEPHIR_CONCAT_VSV(&ns_space, &_17, "\\", &ns_part);
	zephir_read_property(&_18, this_ptr, SL("_module"), PH_NOISY_CC | PH_READONLY);
	if (!ZEPHIR_IS_STRING(&_18, "")) {
		zephir_read_property(&_19$$3, this_ptr, SL("_module"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_20$$3);
		ZEPHIR_CONCAT_VSV(&_20$$3, &path_now, "/", &_19$$3);
		ZEPHIR_CPY_WRT(&path_now, &_20$$3);
		ZEPHIR_INIT_VAR(&_21$$3);
		zephir_read_property(&_22$$3, this_ptr, SL("_module"), PH_NOISY_CC | PH_READONLY);
		zephir_ucfirst(&_21$$3, &_22$$3);
		ZEPHIR_INIT_LNVAR(_20$$3);
		ZEPHIR_CONCAT_VSV(&_20$$3, &ns_space, "\\", &_21$$3);
		ZEPHIR_CPY_WRT(&ns_space, &_20$$3);
	}
	ZEPHIR_INIT_NVAR(&_15);
	zephir_read_property(&_23, this_ptr, SL("_controller"), PH_NOISY_CC | PH_READONLY);
	zephir_ucfirst(&_15, &_23);
	ZEPHIR_INIT_VAR(&_24);
	ZEPHIR_CONCAT_VSV(&_24, &ns_space, "\\", &_15);
	ZEPHIR_CPY_WRT(&ns_space, &_24);
	ZEPHIR_INIT_VAR(&_26);
	ZVAL_STRING(&_26, "~");
	ZEPHIR_CALL_CE_STATIC(NULL, brisk_kernel_loader_ce, "setalias", &_25, 0, &_26, &path_now);
	zephir_check_call_status();
	ZEPHIR_CALL_CE_STATIC(NULL, brisk_kernel_request_ce, "setdata", &_27, 0, &params);
	zephir_check_call_status();
	ZVAL_BOOL(&_29, 1);
	ZEPHIR_CALL_CE_STATIC(NULL, brisk_kernel_request_ce, "setready", &_28, 0, &_29);
	zephir_check_call_status();
	_30 = !(zephir_class_exists(&ns_space, zephir_is_true(&__$false)  TSRMLS_CC));
	if (_30) {
		ZEPHIR_CALL_CE_STATIC(&_31, brisk_kernel_loader_ce, "findclass", &_32, 0, &ns_space);
		zephir_check_call_status();
		_30 = !zephir_is_true(&_31);
	}
	if (_30) {
		ZEPHIR_INIT_VAR(&_33$$4);
		object_init_ex(&_33$$4, brisk_exception_routerexception_ce);
		ZEPHIR_INIT_VAR(&_36$$4);
		zephir_create_array(&_36$$4, 1, 0 TSRMLS_CC);
		zephir_array_fast_append(&_36$$4, &ns_space);
		ZEPHIR_INIT_VAR(&_37$$4);
		ZVAL_STRING(&_37$$4, "router.controller_not_found");
		ZEPHIR_CALL_CE_STATIC(&_34$$4, brisk_kernel_language_ce, "get", &_35, 0, &_37$$4, &_36$$4);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_33$$4, "__construct", NULL, 3, &_34$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_33$$4, "brisk/Router/ClassicRouter.zep", 107 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_zval(this_ptr, SL("_namespace"), &ns_space);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Brisk_Router_ClassicRouter, dispatch) {

	zend_string *_24$$7;
	zend_ulong _23$$7;
	zval _13$$5, _19$$6, _30$$10;
	zend_class_entry *_27;
	zval ns_space, action, auto_method, _0, _2, _3, _4, _5, ref, _16, interceptors, instance, _26, output, _6$$3, _7$$3, _8$$3, _9$$3, _10$$5, _11$$5, _14$$5, _15$$5, _17$$6, _18$$6, _20$$6, op$$7, result$$7, _21$$7, *_22$$7, _25$$8, _28$$10, _29$$10, _31$$10;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL, *_12 = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&ns_space);
	ZVAL_UNDEF(&action);
	ZVAL_UNDEF(&auto_method);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&ref);
	ZVAL_UNDEF(&_16);
	ZVAL_UNDEF(&interceptors);
	ZVAL_UNDEF(&instance);
	ZVAL_UNDEF(&_26);
	ZVAL_UNDEF(&output);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_14$$5);
	ZVAL_UNDEF(&_15$$5);
	ZVAL_UNDEF(&_17$$6);
	ZVAL_UNDEF(&_18$$6);
	ZVAL_UNDEF(&_20$$6);
	ZVAL_UNDEF(&op$$7);
	ZVAL_UNDEF(&result$$7);
	ZVAL_UNDEF(&_21$$7);
	ZVAL_UNDEF(&_25$$8);
	ZVAL_UNDEF(&_28$$10);
	ZVAL_UNDEF(&_29$$10);
	ZVAL_UNDEF(&_31$$10);
	ZVAL_UNDEF(&_13$$5);
	ZVAL_UNDEF(&_19$$6);
	ZVAL_UNDEF(&_30$$10);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_CE_STATIC(&_0, brisk_kernel_app_ce, "getinstance", &_1, 0);
	zephir_check_call_status();
	zephir_read_property(&_2, &_0, SL("config"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_3, &_2, SL("router"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_4, &_3, SL("auto_method"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_5, &_4, "hasvalue", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&_5)) {
		ZEPHIR_CALL_CE_STATIC(&_6$$3, brisk_kernel_app_ce, "getinstance", &_1, 0);
		zephir_check_call_status();
		zephir_read_property(&_7$$3, &_6$$3, SL("config"), PH_NOISY_CC | PH_READONLY);
		zephir_read_property(&_8$$3, &_7$$3, SL("router"), PH_NOISY_CC | PH_READONLY);
		zephir_read_property(&_9$$3, &_8$$3, SL("auto_method"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&auto_method, &_9$$3, "getvalue", NULL, 0);
		zephir_check_call_status();
	} else {
		ZEPHIR_OBS_NVAR(&auto_method);
		zephir_read_static_property_ce(&auto_method, brisk_router_classicrouter_ce, SL("_auto_method"), PH_NOISY_CC);
	}
	ZEPHIR_OBS_VAR(&ns_space);
	zephir_read_property(&ns_space, this_ptr, SL("_namespace"), PH_NOISY_CC);
	if (!(zephir_class_exists(&ns_space, 1 TSRMLS_CC))) {
		ZEPHIR_INIT_VAR(&_10$$5);
		object_init_ex(&_10$$5, brisk_exception_routerexception_ce);
		ZEPHIR_INIT_VAR(&_13$$5);
		zephir_create_array(&_13$$5, 1, 0 TSRMLS_CC);
		ZEPHIR_OBS_VAR(&_14$$5);
		zephir_read_property(&_14$$5, this_ptr, SL("_namespace"), PH_NOISY_CC);
		zephir_array_fast_append(&_13$$5, &_14$$5);
		ZEPHIR_INIT_VAR(&_15$$5);
		ZVAL_STRING(&_15$$5, "router.class_not_found");
		ZEPHIR_CALL_CE_STATIC(&_11$$5, brisk_kernel_language_ce, "get", &_12, 0, &_15$$5, &_13$$5);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_10$$5, "__construct", NULL, 3, &_11$$5);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_10$$5, "brisk/Router/ClassicRouter.zep", 123 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&ref);
	object_init_ex(&ref, zephir_get_internal_ce(SL("reflectionclass")));
	ZEPHIR_CALL_METHOD(NULL, &ref, "__construct", NULL, 71, &ns_space);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_16, &ref, "isabstract", NULL, 72);
	zephir_check_call_status();
	if (zephir_is_true(&_16)) {
		ZEPHIR_INIT_VAR(&_17$$6);
		object_init_ex(&_17$$6, brisk_exception_routerexception_ce);
		ZEPHIR_INIT_VAR(&_19$$6);
		zephir_create_array(&_19$$6, 1, 0 TSRMLS_CC);
		zephir_array_fast_append(&_19$$6, &ns_space);
		ZEPHIR_INIT_VAR(&_20$$6);
		ZVAL_STRING(&_20$$6, "router.controller_is_protected");
		ZEPHIR_CALL_CE_STATIC(&_18$$6, brisk_kernel_language_ce, "get", &_12, 0, &_20$$6, &_19$$6);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_17$$6, "__construct", NULL, 3, &_18$$6);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_17$$6, "brisk/Router/ClassicRouter.zep", 129 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_SELF(&interceptors, "getinterceptors", NULL, 0, &ns_space);
	zephir_check_call_status();
	if (zephir_fast_count_int(&interceptors TSRMLS_CC) > 0) {
		ZEPHIR_INIT_VAR(&_21$$7);
		zephir_is_iterable(&interceptors, 0, "brisk/Router/ClassicRouter.zep", 143);
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&interceptors), _23$$7, _24$$7, _22$$7)
		{
			ZEPHIR_INIT_NVAR(&_21$$7);
			if (_24$$7 != NULL) { 
				ZVAL_STR_COPY(&_21$$7, _24$$7);
			} else {
				ZVAL_LONG(&_21$$7, _23$$7);
			}
			ZEPHIR_INIT_NVAR(&op$$7);
			ZVAL_COPY(&op$$7, _22$$7);
			ZEPHIR_INIT_NVAR(&_25$$8);
			array_init(&_25$$8);
			ZEPHIR_INIT_NVAR(&result$$7);
			ZEPHIR_CALL_USER_FUNC_ARRAY(&result$$7, &op$$7, &_25$$8);
			zephir_check_call_status();
			if (Z_TYPE_P(&result$$7) == IS_STRING) {
				zend_print_zval(&result$$7, 0);
				ZEPHIR_MM_RESTORE();
				zephir_exit_empty();
			}
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&op$$7);
		ZEPHIR_INIT_NVAR(&_21$$7);
	}
	ZEPHIR_INIT_VAR(&instance);
	zephir_fetch_safe_class(&_26, &ns_space);
	_27 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_26), Z_STRLEN_P(&_26), ZEND_FETCH_CLASS_AUTO);
	object_init_ex(&instance, _27);
	if (zephir_has_constructor(&instance TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, &instance, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_OBS_VAR(&action);
	zephir_read_property(&action, this_ptr, SL("_action"), PH_NOISY_CC);
	if (!((zephir_method_exists(&instance, &action TSRMLS_CC)  == SUCCESS))) {
		ZEPHIR_INIT_VAR(&_28$$10);
		object_init_ex(&_28$$10, brisk_exception_routerexception_ce);
		ZEPHIR_INIT_VAR(&_30$$10);
		zephir_create_array(&_30$$10, 1, 0 TSRMLS_CC);
		zephir_array_fast_append(&_30$$10, &action);
		ZEPHIR_INIT_VAR(&_31$$10);
		ZVAL_STRING(&_31$$10, "router.action_not_found");
		ZEPHIR_CALL_CE_STATIC(&_29$$10, brisk_kernel_language_ce, "get", &_12, 0, &_31$$10, &_30$$10);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_28$$10, "__construct", NULL, 3, &_29$$10);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_28$$10, "brisk/Router/ClassicRouter.zep", 149 TSRMLS_CC);
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

PHP_METHOD(Brisk_Router_ClassicRouter, todoUKSort) {

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

PHP_METHOD(Brisk_Router_ClassicRouter, _parseUri) {

	zend_string *_36$$15, *_42$$17;
	zend_ulong _35$$15, _41$$17;
	zend_bool _10;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL, *_5 = NULL, *_9 = NULL, *_30 = NULL;
	zval *uri_param = NULL, module, controller, action, url_suffix, script_name, query, pos, uri_items, result, config, _0, _2, _3, _4, _6, _7, _8, _19, _24, _25, _26, _27, _28, _29, val, _11$$3, _12$$3, _13$$3, _15$$3, _16$$3, _18$$3, _14$$5, _17$$7, _20$$9, _21$$11, _22$$11, _23$$11, _31$$15, _32$$15, _33$$15, *_34$$15, _37$$16, _38$$16, _39$$17, *_40$$17, _43$$18, _44$$18, _45$$18;
	zval uri;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&uri);
	ZVAL_UNDEF(&module);
	ZVAL_UNDEF(&controller);
	ZVAL_UNDEF(&action);
	ZVAL_UNDEF(&url_suffix);
	ZVAL_UNDEF(&script_name);
	ZVAL_UNDEF(&query);
	ZVAL_UNDEF(&pos);
	ZVAL_UNDEF(&uri_items);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&config);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_19);
	ZVAL_UNDEF(&_24);
	ZVAL_UNDEF(&_25);
	ZVAL_UNDEF(&_26);
	ZVAL_UNDEF(&_27);
	ZVAL_UNDEF(&_28);
	ZVAL_UNDEF(&_29);
	ZVAL_UNDEF(&val);
	ZVAL_UNDEF(&_11$$3);
	ZVAL_UNDEF(&_12$$3);
	ZVAL_UNDEF(&_13$$3);
	ZVAL_UNDEF(&_15$$3);
	ZVAL_UNDEF(&_16$$3);
	ZVAL_UNDEF(&_18$$3);
	ZVAL_UNDEF(&_14$$5);
	ZVAL_UNDEF(&_17$$7);
	ZVAL_UNDEF(&_20$$9);
	ZVAL_UNDEF(&_21$$11);
	ZVAL_UNDEF(&_22$$11);
	ZVAL_UNDEF(&_23$$11);
	ZVAL_UNDEF(&_31$$15);
	ZVAL_UNDEF(&_32$$15);
	ZVAL_UNDEF(&_33$$15);
	ZVAL_UNDEF(&_37$$16);
	ZVAL_UNDEF(&_38$$16);
	ZVAL_UNDEF(&_39$$17);
	ZVAL_UNDEF(&_43$$18);
	ZVAL_UNDEF(&_44$$18);
	ZVAL_UNDEF(&_45$$18);

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


	ZEPHIR_CALL_CE_STATIC(&_0, brisk_kernel_app_ce, "getinstance", &_1, 0);
	zephir_check_call_status();
	zephir_read_property(&_2, &_0, SL("config"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_3, &_2, SL("router"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&config, &_3);
	ZEPHIR_INIT_VAR(&_6);
	ZVAL_STRING(&_6, "SCRIPT_FILENAME");
	ZEPHIR_CALL_CE_STATIC(&_4, brisk_kernel_server_ce, "getitem", &_5, 0, &_6);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&script_name);
	zephir_basename(&script_name, &_4 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_7);
	ZEPHIR_CONCAT_SVS(&_7, "~/", &script_name, "~i");
	ZEPHIR_INIT_NVAR(&_6);
	ZVAL_STRING(&_6, "");
	ZEPHIR_CALL_FUNCTION(&_8, "preg_replace", &_9, 2, &_7, &_6, &uri);
	zephir_check_call_status();
	zephir_get_strval(&uri, &_8);
	_10 = ZEPHIR_IS_STRING(&uri, "");
	if (!(_10)) {
		_10 = ZEPHIR_IS_STRING(&uri, "/");
	}
	if (_10) {
		ZEPHIR_INIT_VAR(&module);
		ZVAL_STRING(&module, "");
		zephir_read_static_property_ce(&_11$$3, brisk_router_classicrouter_ce, SL("_module_support"), PH_NOISY_CC | PH_READONLY);
		if (zephir_is_true(&_11$$3)) {
			ZEPHIR_OBS_NVAR(&module);
			zephir_read_static_property_ce(&module, brisk_router_classicrouter_ce, SL("_default_module"), PH_NOISY_CC);
		}
		zephir_read_property(&_12$$3, &config, SL("default_controller"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_13$$3, &_12$$3, "hasvalue", NULL, 0);
		zephir_check_call_status();
		if (zephir_is_true(&_13$$3)) {
			zephir_read_property(&_14$$5, &config, SL("default_controller"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_METHOD(&controller, &_14$$5, "getvalue", NULL, 0);
			zephir_check_call_status();
		} else {
			ZEPHIR_OBS_NVAR(&controller);
			zephir_read_static_property_ce(&controller, brisk_router_classicrouter_ce, SL("_default_controller"), PH_NOISY_CC);
		}
		zephir_read_property(&_15$$3, &config, SL("default_action"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_16$$3, &_15$$3, "hasvalue", NULL, 0);
		zephir_check_call_status();
		if (zephir_is_true(&_16$$3)) {
			zephir_read_property(&_17$$7, &config, SL("default_action"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_METHOD(&action, &_17$$7, "getvalue", NULL, 0);
			zephir_check_call_status();
		} else {
			ZEPHIR_OBS_NVAR(&action);
			zephir_read_static_property_ce(&action, brisk_router_classicrouter_ce, SL("_default_action"), PH_NOISY_CC);
		}
		zephir_create_array(return_value, 4, 0 TSRMLS_CC);
		zephir_array_update_string(return_value, SL("module"), &module, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(return_value, SL("controller"), &controller, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(return_value, SL("action"), &action, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_VAR(&_18$$3);
		array_init(&_18$$3);
		zephir_array_update_string(return_value, SL("params"), &_18$$3, PH_COPY | PH_SEPARATE);
		RETURN_MM();
	}
	zephir_read_property(&_3, &config, SL("url_suffix"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_19, &_3, "hasvalue", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&_19)) {
		zephir_read_property(&_20$$9, &config, SL("url_suffix"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&url_suffix, &_20$$9, "getvalue", NULL, 0);
		zephir_check_call_status();
	} else {
		ZEPHIR_OBS_NVAR(&url_suffix);
		zephir_read_static_property_ce(&url_suffix, brisk_router_classicrouter_ce, SL("_url_suffix"), PH_NOISY_CC);
	}
	ZEPHIR_INIT_VAR(&query);
	ZVAL_STRING(&query, "");
	ZEPHIR_INIT_NVAR(&_6);
	ZVAL_STRING(&_6, "?");
	ZEPHIR_INIT_VAR(&pos);
	zephir_fast_strpos(&pos, &uri, &_6, 0 );
	if (!ZEPHIR_IS_FALSE_IDENTICAL(&pos)) {
		ZVAL_LONG(&_21$$11, (zephir_get_numberval(&pos) + 1));
		ZEPHIR_INIT_NVAR(&query);
		zephir_substr(&query, &uri, zephir_get_intval(&_21$$11), 0, ZEPHIR_SUBSTR_NO_LENGTH);
		ZVAL_LONG(&_22$$11, 0);
		ZEPHIR_INIT_VAR(&_23$$11);
		zephir_substr(&_23$$11, &uri, 0 , zephir_get_intval(&pos), 0);
		zephir_get_strval(&uri, &_23$$11);
	}
	ZEPHIR_CALL_METHOD(&_24, this_ptr, "_rewrite", NULL, 73, &uri);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_25);
	ZVAL_STRING(&_25, "/");
	ZEPHIR_INIT_NVAR(&uri);
	zephir_fast_trim(&uri, &_24, &_25, ZEPHIR_TRIM_BOTH TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_26);
	ZEPHIR_CONCAT_SVS(&_26, "~", &url_suffix, "$~i");
	ZEPHIR_INIT_VAR(&_27);
	ZVAL_STRING(&_27, "");
	ZEPHIR_CALL_FUNCTION(&_28, "preg_replace", &_9, 2, &_26, &_27, &uri);
	zephir_check_call_status();
	zephir_get_strval(&uri, &_28);
	ZEPHIR_INIT_VAR(&uri_items);
	zephir_fast_explode_str(&uri_items, SL("/"), &uri, LONG_MAX TSRMLS_CC);
	ZEPHIR_INIT_NVAR(&module);
	ZVAL_STRING(&module, "");
	zephir_read_static_property_ce(&_29, brisk_router_classicrouter_ce, SL("_module_support"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_29)) {
		ZEPHIR_MAKE_REF(&uri_items);
		ZEPHIR_CALL_FUNCTION(&module, "array_shift", &_30, 7, &uri_items);
		ZEPHIR_UNREF(&uri_items);
		zephir_check_call_status();
	}
	ZEPHIR_MAKE_REF(&uri_items);
	ZEPHIR_CALL_FUNCTION(&controller, "array_shift", &_30, 7, &uri_items);
	ZEPHIR_UNREF(&uri_items);
	zephir_check_call_status();
	if (ZEPHIR_IS_STRING(&controller, "")) {
		ZEPHIR_OBS_NVAR(&controller);
		zephir_read_static_property_ce(&controller, brisk_router_classicrouter_ce, SL("_default_controller"), PH_NOISY_CC);
	}
	ZEPHIR_MAKE_REF(&uri_items);
	ZEPHIR_CALL_FUNCTION(&action, "array_shift", &_30, 7, &uri_items);
	ZEPHIR_UNREF(&uri_items);
	zephir_check_call_status();
	if (ZEPHIR_IS_STRING(&action, "")) {
		ZEPHIR_OBS_NVAR(&action);
		zephir_read_static_property_ce(&action, brisk_router_classicrouter_ce, SL("_default_action"), PH_NOISY_CC);
	}
	ZEPHIR_INIT_VAR(&result);
	array_init(&result);
	if (zephir_fast_count_int(&uri_items TSRMLS_CC) > 0) {
		ZVAL_LONG(&_31$$15, 2);
		ZEPHIR_CALL_FUNCTION(&_32$$15, "array_chunk", NULL, 74, &uri_items, &_31$$15);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&uri_items, &_32$$15);
		ZEPHIR_INIT_VAR(&_33$$15);
		zephir_is_iterable(&uri_items, 0, "brisk/Router/ClassicRouter.zep", 240);
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&uri_items), _35$$15, _36$$15, _34$$15)
		{
			ZEPHIR_INIT_NVAR(&_33$$15);
			if (_36$$15 != NULL) { 
				ZVAL_STR_COPY(&_33$$15, _36$$15);
			} else {
				ZVAL_LONG(&_33$$15, _35$$15);
			}
			ZEPHIR_INIT_NVAR(&val);
			ZVAL_COPY(&val, _34$$15);
			zephir_array_fetch_long(&_37$$16, &val, 1, PH_NOISY | PH_READONLY, "brisk/Router/ClassicRouter.zep", 238 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(&_38$$16);
			zephir_array_fetch_long(&_38$$16, &val, 0, PH_NOISY, "brisk/Router/ClassicRouter.zep", 238 TSRMLS_CC);
			zephir_array_update_zval(&result, &_38$$16, &_37$$16, PH_COPY | PH_SEPARATE);
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&val);
		ZEPHIR_INIT_NVAR(&_33$$15);
	}
	if (!ZEPHIR_IS_STRING(&query, "")) {
		ZEPHIR_INIT_VAR(&_39$$17);
		zephir_fast_explode_str(&_39$$17, SL("&"), &query, LONG_MAX TSRMLS_CC);
		ZEPHIR_CPY_WRT(&query, &_39$$17);
		ZEPHIR_INIT_NVAR(&_39$$17);
		zephir_is_iterable(&query, 0, "brisk/Router/ClassicRouter.zep", 247);
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&query), _41$$17, _42$$17, _40$$17)
		{
			ZEPHIR_INIT_NVAR(&_39$$17);
			if (_42$$17 != NULL) { 
				ZVAL_STR_COPY(&_39$$17, _42$$17);
			} else {
				ZVAL_LONG(&_39$$17, _41$$17);
			}
			ZEPHIR_INIT_NVAR(&val);
			ZVAL_COPY(&val, _40$$17);
			ZEPHIR_INIT_NVAR(&_43$$18);
			zephir_fast_explode_str(&_43$$18, SL("="), &val, LONG_MAX TSRMLS_CC);
			ZEPHIR_CPY_WRT(&val, &_43$$18);
			zephir_array_fetch_long(&_44$$18, &val, 1, PH_NOISY | PH_READONLY, "brisk/Router/ClassicRouter.zep", 245 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(&_45$$18);
			zephir_array_fetch_long(&_45$$18, &val, 0, PH_NOISY, "brisk/Router/ClassicRouter.zep", 245 TSRMLS_CC);
			zephir_array_update_zval(&result, &_45$$18, &_44$$18, PH_COPY | PH_SEPARATE);
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&val);
		ZEPHIR_INIT_NVAR(&_39$$17);
	}
	if (zephir_array_isset_string(&result, SL("_m"))) {
		ZEPHIR_OBS_NVAR(&module);
		zephir_array_fetch_string(&module, &result, SL("_m"), PH_NOISY, "brisk/Router/ClassicRouter.zep", 249 TSRMLS_CC);
		zephir_array_unset_string(&result, SL("_m"), PH_SEPARATE);
	}
	if (zephir_array_isset_string(&result, SL("_c"))) {
		ZEPHIR_OBS_NVAR(&controller);
		zephir_array_fetch_string(&controller, &result, SL("_c"), PH_NOISY, "brisk/Router/ClassicRouter.zep", 253 TSRMLS_CC);
		zephir_array_unset_string(&result, SL("_c"), PH_SEPARATE);
	}
	if (zephir_array_isset_string(&result, SL("_a"))) {
		ZEPHIR_OBS_NVAR(&action);
		zephir_array_fetch_string(&action, &result, SL("_a"), PH_NOISY, "brisk/Router/ClassicRouter.zep", 257 TSRMLS_CC);
		zephir_array_unset_string(&result, SL("_a"), PH_SEPARATE);
	}
	zephir_create_array(return_value, 4, 0 TSRMLS_CC);
	zephir_array_update_string(return_value, SL("module"), &module, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(return_value, SL("controller"), &controller, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(return_value, SL("action"), &action, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(return_value, SL("params"), &result, PH_COPY | PH_SEPARATE);
	RETURN_MM();

}

PHP_METHOD(Brisk_Router_ClassicRouter, _rewrite) {

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


	zephir_read_static_property_ce(&_0, brisk_router_classicrouter_ce, SL("_rules"), PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_0, 0, "brisk/Router/ClassicRouter.zep", 285);
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
				zephir_array_fetch_long(&_16$$7, &val, 0, PH_NOISY | PH_READONLY, "brisk/Router/ClassicRouter.zep", 281 TSRMLS_CC);
				zephir_array_fetch_long(&_17$$7, &val, 1, PH_NOISY | PH_READONLY, "brisk/Router/ClassicRouter.zep", 281 TSRMLS_CC);
				ZEPHIR_INIT_LNVAR(_18$$7);
				ZEPHIR_CONCAT_VSVS(&_18$$7, &_16$$7, "::", &_17$$7, "()");
				zephir_array_fast_append(&_15$$7, &_18$$7);
				ZEPHIR_INIT_NVAR(&_19$$7);
				ZVAL_STRING(&_19$$7, "router.call_func_failed");
				ZEPHIR_CALL_CE_STATIC(&_13$$7, brisk_kernel_language_ce, "get", &_14, 0, &_19$$7, &_15$$7);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, &_12$$7, "__construct", &_20, 3, &_13$$7);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_12$$7, "brisk/Router/ClassicRouter.zep", 281 TSRMLS_CC);
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
		zephir_throw_exception_debug(&_21$$8, "brisk/Router/ClassicRouter.zep", 286 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_CTOR(&uri);

}

void zephir_init_static_properties_Brisk_Router_ClassicRouter(TSRMLS_D) {

	zval _0, _1;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	array_init(&_0);
	zend_update_static_property(brisk_router_classicrouter_ce, ZEND_STRL("_interceptors"), &_0);
	ZEPHIR_INIT_VAR(&_1);
	array_init(&_1);
	zend_update_static_property(brisk_router_classicrouter_ce, ZEND_STRL("_rules"), &_1);
	ZEPHIR_MM_RESTORE();

}


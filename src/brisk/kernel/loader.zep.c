
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
#include "kernel/require.h"
#include "kernel/concat.h"


ZEPHIR_INIT_CLASS(Brisk_Kernel_Loader) {

	ZEPHIR_REGISTER_CLASS(Brisk\\Kernel, Loader, brisk, kernel_loader, brisk_kernel_loader_method_entry, 0);

	zend_declare_property_null(brisk_kernel_loader_ce, SL("_alias"), ZEND_ACC_PRIVATE|ZEND_ACC_STATIC TSRMLS_CC);

	zend_declare_property_null(brisk_kernel_loader_ce, SL("_namespaces"), ZEND_ACC_PRIVATE|ZEND_ACC_STATIC TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Brisk_Kernel_Loader, setAlias) {

	zval *alias_param = NULL, *path_param = NULL;
	zval alias, path;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&alias);
	ZVAL_UNDEF(&path);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &alias_param, &path_param);

	if (UNEXPECTED(Z_TYPE_P(alias_param) != IS_STRING && Z_TYPE_P(alias_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'alias' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(alias_param) == IS_STRING)) {
		zephir_get_strval(&alias, alias_param);
	} else {
		ZEPHIR_INIT_VAR(&alias);
		ZVAL_EMPTY_STRING(&alias);
	}
	if (UNEXPECTED(Z_TYPE_P(path_param) != IS_STRING && Z_TYPE_P(path_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'path' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(path_param) == IS_STRING)) {
		zephir_get_strval(&path, path_param);
	} else {
		ZEPHIR_INIT_VAR(&path);
		ZVAL_EMPTY_STRING(&path);
	}


	zephir_update_static_property_array_multi_ce(brisk_kernel_loader_ce, SL("_alias"), &path TSRMLS_CC, SL("z"), 1, &alias);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Brisk_Kernel_Loader, setNameSpace) {

	zval *nspace_param = NULL, *path_param = NULL, _0, _1, nspath, _2, _3$$3;
	zval nspace, path;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&nspace);
	ZVAL_UNDEF(&path);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&nspath);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &nspace_param, &path_param);

	if (UNEXPECTED(Z_TYPE_P(nspace_param) != IS_STRING && Z_TYPE_P(nspace_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'nspace' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(nspace_param) == IS_STRING)) {
		zephir_get_strval(&nspace, nspace_param);
	} else {
		ZEPHIR_INIT_VAR(&nspace);
		ZVAL_EMPTY_STRING(&nspace);
	}
	if (UNEXPECTED(Z_TYPE_P(path_param) != IS_STRING && Z_TYPE_P(path_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'path' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(path_param) == IS_STRING)) {
		zephir_get_strval(&path, path_param);
	} else {
		ZEPHIR_INIT_VAR(&path);
		ZVAL_EMPTY_STRING(&path);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "\\");
	zephir_fast_trim(&_0, &nspace, &_1, ZEPHIR_TRIM_RIGHT TSRMLS_CC);
	zephir_get_strval(&nspace, &_0);
	ZEPHIR_INIT_VAR(&nspath);
	array_init(&nspath);
	zephir_read_static_property_ce(&_2, brisk_kernel_loader_ce, SL("_namespaces"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset(&_2, &nspace)) {
		zephir_read_static_property_ce(&_3$$3, brisk_kernel_loader_ce, SL("_namespaces"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_OBS_NVAR(&nspath);
		zephir_array_fetch(&nspath, &_3$$3, &nspace, PH_NOISY, "brisk/Kernel/Loader.zep", 22 TSRMLS_CC);
	}
	if (!(zephir_fast_in_array(&path, &nspath TSRMLS_CC))) {
		zephir_array_append(&nspath, &path, PH_SEPARATE, "brisk/Kernel/Loader.zep", 25);
	}
	zephir_update_static_property_array_multi_ce(brisk_kernel_loader_ce, SL("_namespaces"), &nspath TSRMLS_CC, SL("z"), 1, &nspace);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Brisk_Kernel_Loader, getAlias) {

	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	zephir_read_static_property_ce(&_0, brisk_kernel_loader_ce, SL("_alias"), PH_NOISY_CC | PH_READONLY);
	RETURN_CTORW(&_0);

}

PHP_METHOD(Brisk_Kernel_Loader, getNameSpace) {

	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	zephir_read_static_property_ce(&_0, brisk_kernel_loader_ce, SL("_namespaces"), PH_NOISY_CC | PH_READONLY);
	RETURN_CTORW(&_0);

}

PHP_METHOD(Brisk_Kernel_Loader, autoLoad) {

	zephir_fcall_cache_entry *_2 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *classname_param = NULL, path, _0$$3, _1$$3, _3$$3;
	zval classname;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&classname);
	ZVAL_UNDEF(&path);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &classname_param);

	if (UNEXPECTED(Z_TYPE_P(classname_param) != IS_STRING && Z_TYPE_P(classname_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'classname' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(classname_param) == IS_STRING)) {
		zephir_get_strval(&classname, classname_param);
	} else {
		ZEPHIR_INIT_VAR(&classname);
		ZVAL_EMPTY_STRING(&classname);
	}


	ZEPHIR_CALL_SELF(&path, "findclass", NULL, 0, &classname);
	zephir_check_call_status();
	if (!zephir_is_true(&path)) {
		ZEPHIR_INIT_VAR(&_0$$3);
		object_init_ex(&_0$$3, brisk_exception_kernelexception_ce);
		ZEPHIR_INIT_VAR(&_3$$3);
		ZVAL_STRING(&_3$$3, "core.class_path_notfound");
		ZEPHIR_CALL_CE_STATIC(&_1$$3, brisk_kernel_language_ce, "get", &_2, 0, &_3$$3, &classname);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_0$$3, "__construct", NULL, 3, &_1$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_0$$3, "brisk/Kernel/Loader.zep", 44 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (zephir_require_zval(&path TSRMLS_CC) == FAILURE) {
		RETURN_MM_NULL();
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Brisk_Kernel_Loader, addAutoLoader) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *loader, loader_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&loader_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &loader);

	if (UNEXPECTED(zephir_is_callable(loader TSRMLS_CC) != 1)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'loader' must be a callable") TSRMLS_CC);
		RETURN_MM_NULL();
	}


	ZEPHIR_CALL_FUNCTION(NULL, "spl_autoload_register", NULL, 42, loader);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Brisk_Kernel_Loader, findClass) {

	zend_bool _11$$4;
	zend_string *_3;
	zend_ulong _2;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_22 = NULL, *_30 = NULL;
	zval *classname_param = NULL, formal, key, val, _0, *_1, item, _13, *_14, _4$$3, _5$$3, _6$$3, _7$$3, _8$$3, _9$$3, _10$$3, _12$$4, _15$$7, _16$$7, _17$$7, _18$$7, _19$$7, _20$$7, _21$$7, path$$7, _23$$7, _24$$7, _25$$7, _26$$7, _27$$7, _29$$7, _28$$8;
	zval classname;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&classname);
	ZVAL_UNDEF(&formal);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&val);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&item);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_10$$3);
	ZVAL_UNDEF(&_12$$4);
	ZVAL_UNDEF(&_15$$7);
	ZVAL_UNDEF(&_16$$7);
	ZVAL_UNDEF(&_17$$7);
	ZVAL_UNDEF(&_18$$7);
	ZVAL_UNDEF(&_19$$7);
	ZVAL_UNDEF(&_20$$7);
	ZVAL_UNDEF(&_21$$7);
	ZVAL_UNDEF(&path$$7);
	ZVAL_UNDEF(&_23$$7);
	ZVAL_UNDEF(&_24$$7);
	ZVAL_UNDEF(&_25$$7);
	ZVAL_UNDEF(&_26$$7);
	ZVAL_UNDEF(&_27$$7);
	ZVAL_UNDEF(&_29$$7);
	ZVAL_UNDEF(&_28$$8);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &classname_param);

	if (UNEXPECTED(Z_TYPE_P(classname_param) != IS_STRING && Z_TYPE_P(classname_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'classname' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(classname_param) == IS_STRING)) {
		zephir_get_strval(&classname, classname_param);
	} else {
		ZEPHIR_INIT_VAR(&classname);
		ZVAL_EMPTY_STRING(&classname);
	}


	ZEPHIR_INIT_VAR(&formal);
	array_init(&formal);
	zephir_read_static_property_ce(&_0, brisk_kernel_loader_ce, SL("_namespaces"), PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_0, 0, "brisk/Kernel/Loader.zep", 68);
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
		ZEPHIR_INIT_NVAR(&_4$$3);
		ZEPHIR_INIT_NVAR(&_5$$3);
		ZVAL_STRING(&_5$$3, "\\");
		zephir_fast_trim(&_4$$3, &key, &_5$$3, ZEPHIR_TRIM_LEFT TSRMLS_CC);
		ZEPHIR_CPY_WRT(&key, &_4$$3);
		ZEPHIR_INIT_NVAR(&_4$$3);
		ZEPHIR_INIT_NVAR(&_6$$3);
		ZVAL_STRING(&_6$$3, "\\");
		zephir_fast_trim(&_4$$3, &classname, &_6$$3, ZEPHIR_TRIM_LEFT TSRMLS_CC);
		zephir_get_strval(&classname, &_4$$3);
		ZEPHIR_INIT_NVAR(&_7$$3);
		ZEPHIR_INIT_NVAR(&_8$$3);
		ZEPHIR_INIT_NVAR(&_9$$3);
		zephir_addslashes(&_9$$3, &key TSRMLS_CC);
		ZEPHIR_INIT_LNVAR(_10$$3);
		ZEPHIR_CONCAT_SVS(&_10$$3, "/^", &_9$$3, "/");
		zephir_preg_match(&_8$$3, &_10$$3, &classname, &_7$$3, 0, 0 , 0  TSRMLS_CC);
		if (zephir_is_true(&_8$$3)) {
			_11$$4 = !zephir_is_true(&formal);
			if (!(_11$$4)) {
				zephir_array_fetch_string(&_12$$4, &formal, SL("key"), PH_NOISY | PH_READONLY, "brisk/Kernel/Loader.zep", 62 TSRMLS_CC);
				_11$$4 = zephir_fast_strlen_ev(&key) > zephir_fast_strlen_ev(&_12$$4);
			}
			if (_11$$4) {
				zephir_array_update_string(&formal, SL("key"), &key, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&formal, SL("val"), &val, PH_COPY | PH_SEPARATE);
			}
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&val);
	ZEPHIR_INIT_NVAR(&key);
	if (!zephir_is_true(&formal)) {
		RETURN_MM_STRING("");
	}
	zephir_array_fetch_string(&_13, &formal, SL("val"), PH_NOISY | PH_READONLY, "brisk/Kernel/Loader.zep", 72 TSRMLS_CC);
	zephir_is_iterable(&_13, 0, "brisk/Kernel/Loader.zep", 83);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_13), _14)
	{
		ZEPHIR_INIT_NVAR(&item);
		ZVAL_COPY(&item, _14);
		ZEPHIR_INIT_NVAR(&_15$$7);
		ZEPHIR_INIT_NVAR(&_16$$7);
		ZVAL_STRING(&_16$$7, "/");
		zephir_fast_trim(&_15$$7, &item, &_16$$7, ZEPHIR_TRIM_RIGHT TSRMLS_CC);
		ZEPHIR_INIT_LNVAR(_17$$7);
		ZEPHIR_CONCAT_VS(&_17$$7, &_15$$7, "/");
		ZEPHIR_CPY_WRT(&item, &_17$$7);
		ZEPHIR_INIT_NVAR(&_18$$7);
		zephir_array_fetch_string(&_19$$7, &formal, SL("key"), PH_NOISY | PH_READONLY, "brisk/Kernel/Loader.zep", 74 TSRMLS_CC);
		zephir_addslashes(&_18$$7, &_19$$7 TSRMLS_CC);
		ZEPHIR_INIT_LNVAR(_17$$7);
		ZEPHIR_CONCAT_SVS(&_17$$7, "/^", &_18$$7, "\\\\/");
		ZEPHIR_INIT_NVAR(&_20$$7);
		ZVAL_STRING(&_20$$7, "");
		ZEPHIR_CALL_FUNCTION(&_21$$7, "preg_replace", &_22, 2, &_17$$7, &_20$$7, &classname);
		zephir_check_call_status();
		zephir_get_strval(&classname, &_21$$7);
		ZEPHIR_INIT_LNVAR(_23$$7);
		ZEPHIR_CONCAT_VV(&_23$$7, &item, &classname);
		ZEPHIR_INIT_NVAR(&_20$$7);
		ZVAL_STRING(&_20$$7, "\\");
		ZEPHIR_INIT_NVAR(&_24$$7);
		ZVAL_STRING(&_24$$7, "/");
		ZEPHIR_INIT_NVAR(&path$$7);
		zephir_fast_str_replace(&path$$7, &_20$$7, &_24$$7, &_23$$7 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(&_25$$7);
		ZEPHIR_INIT_NVAR(&_26$$7);
		ZEPHIR_INIT_NVAR(&_27$$7);
		ZVAL_STRING(&_27$$7, "/\\.php$/");
		zephir_preg_match(&_26$$7, &_27$$7, &path$$7, &_25$$7, 0, 0 , 0  TSRMLS_CC);
		if (!zephir_is_true(&_26$$7)) {
			ZEPHIR_INIT_LNVAR(_28$$8);
			ZEPHIR_CONCAT_VS(&_28$$8, &path$$7, ".php");
			ZEPHIR_CPY_WRT(&path$$7, &_28$$8);
		}
		ZEPHIR_CALL_FUNCTION(&_29$$7, "is_file", &_30, 43, &path$$7);
		zephir_check_call_status();
		if (zephir_is_true(&_29$$7)) {
			RETURN_CCTOR(&path$$7);
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&item);
	RETURN_MM_STRING("");

}

PHP_METHOD(Brisk_Kernel_Loader, realPath) {

	zval _10, _1$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL, *_9 = NULL;
	zval *spacename_param = NULL, parsed, _7, _8, _11, alias$$3, space$$3, _2$$3, _3$$3, _4$$3, _5$$3, _6$$3;
	zval spacename;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&spacename);
	ZVAL_UNDEF(&parsed);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&alias$$3);
	ZVAL_UNDEF(&space$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_1$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &spacename_param);

	if (UNEXPECTED(Z_TYPE_P(spacename_param) != IS_STRING && Z_TYPE_P(spacename_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'spacename' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(spacename_param) == IS_STRING)) {
		zephir_get_strval(&spacename, spacename_param);
	} else {
		ZEPHIR_INIT_VAR(&spacename);
		ZVAL_EMPTY_STRING(&spacename);
	}


	ZEPHIR_CALL_SELF(&parsed, "_parse", &_0, 44, &spacename);
	zephir_check_call_status();
	if (zephir_fast_count_int(&parsed TSRMLS_CC) > 0) {
		ZEPHIR_OBS_VAR(&alias$$3);
		zephir_array_fetch_long(&alias$$3, &parsed, 0, PH_NOISY, "brisk/Kernel/Loader.zep", 91 TSRMLS_CC);
		ZEPHIR_OBS_VAR(&space$$3);
		zephir_array_fetch_long(&space$$3, &parsed, 1, PH_NOISY, "brisk/Kernel/Loader.zep", 92 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_1$$3);
		zephir_create_array(&_1$$3, 2, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "/");
		zephir_array_fast_append(&_1$$3, &_2$$3);
		ZEPHIR_INIT_NVAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "\\");
		zephir_array_fast_append(&_1$$3, &_2$$3);
		zephir_read_static_property_ce(&_3$$3, brisk_kernel_loader_ce, SL("_alias"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_4$$3, &_3$$3, &alias$$3, PH_NOISY | PH_READONLY, "brisk/Kernel/Loader.zep", 93 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_5$$3);
		ZEPHIR_CONCAT_VV(&_5$$3, &_4$$3, &space$$3);
		ZEPHIR_INIT_NVAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "/");
		ZEPHIR_INIT_VAR(&_6$$3);
		zephir_fast_str_replace(&_6$$3, &_1$$3, &_2$$3, &_5$$3 TSRMLS_CC);
		RETURN_CCTOR(&_6$$3);
	}
	ZEPHIR_INIT_VAR(&_7);
	object_init_ex(&_7, brisk_exception_kernelexception_ce);
	ZEPHIR_INIT_VAR(&_10);
	zephir_create_array(&_10, 1, 0 TSRMLS_CC);
	zephir_array_fast_append(&_10, &spacename);
	ZEPHIR_INIT_VAR(&_11);
	ZVAL_STRING(&_11, "core.format_path_failed");
	ZEPHIR_CALL_CE_STATIC(&_8, brisk_kernel_language_ce, "get", &_9, 0, &_11, &_10);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &_7, "__construct", NULL, 3, &_8);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_7, "brisk/Kernel/Loader.zep", 95 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

PHP_METHOD(Brisk_Kernel_Loader, reducePath) {

	zend_string *_3;
	zend_ulong _2;
	zval *path_param = NULL, key, val, _0, *_1, _5, _6, _7, _4$$3;
	zval path;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&path);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&val);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_4$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &path_param);

	if (UNEXPECTED(Z_TYPE_P(path_param) != IS_STRING && Z_TYPE_P(path_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'path' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(path_param) == IS_STRING)) {
		zephir_get_strval(&path, path_param);
	} else {
		ZEPHIR_INIT_VAR(&path);
		ZVAL_EMPTY_STRING(&path);
	}


	zephir_read_static_property_ce(&_0, brisk_kernel_loader_ce, SL("_alias"), PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_0, 0, "brisk/Kernel/Loader.zep", 104);
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
		ZEPHIR_INIT_NVAR(&_4$$3);
		zephir_fast_str_replace(&_4$$3, &val, &key, &path TSRMLS_CC);
		zephir_get_strval(&path, &_4$$3);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&val);
	ZEPHIR_INIT_NVAR(&key);
	ZEPHIR_INIT_VAR(&_5);
	ZVAL_STRING(&_5, "\\");
	ZEPHIR_INIT_VAR(&_6);
	ZVAL_STRING(&_6, "/");
	ZEPHIR_INIT_VAR(&_7);
	zephir_fast_str_replace(&_7, &_5, &_6, &path TSRMLS_CC);
	RETURN_CCTOR(&_7);

}

PHP_METHOD(Brisk_Kernel_Loader, _parse) {

	zval *nspace_param = NULL, alias, _0, _1, path, _2, _3;
	zval nspace;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&nspace);
	ZVAL_UNDEF(&alias);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&path);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &nspace_param);

	if (UNEXPECTED(Z_TYPE_P(nspace_param) != IS_STRING && Z_TYPE_P(nspace_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'nspace' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(nspace_param) == IS_STRING)) {
		zephir_get_strval(&nspace, nspace_param);
	} else {
		ZEPHIR_INIT_VAR(&nspace);
		ZVAL_EMPTY_STRING(&nspace);
	}


	ZVAL_LONG(&_0, 0);
	ZVAL_LONG(&_1, 1);
	ZEPHIR_INIT_VAR(&alias);
	zephir_substr(&alias, &nspace, 0 , 1 , 0);
	ZVAL_LONG(&_2, 1);
	ZEPHIR_INIT_VAR(&path);
	zephir_substr(&path, &nspace, 1 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
	zephir_read_static_property_ce(&_3, brisk_kernel_loader_ce, SL("_alias"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_key_exists(&_3, &alias TSRMLS_CC))) {
		array_init(return_value);
		RETURN_MM();
	}
	zephir_create_array(return_value, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(return_value, &alias);
	zephir_array_fast_append(return_value, &path);
	RETURN_MM();

}

void zephir_init_static_properties_Brisk_Kernel_Loader(TSRMLS_D) {

	zval _0, _1;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	array_init(&_0);
	zend_update_static_property(brisk_kernel_loader_ce, ZEND_STRL("_namespaces"), &_0);
	ZEPHIR_INIT_VAR(&_1);
	array_init(&_1);
	zend_update_static_property(brisk_kernel_loader_ce, ZEND_STRL("_alias"), &_1);
	ZEPHIR_MM_RESTORE();

}


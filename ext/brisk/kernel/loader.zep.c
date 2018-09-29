
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


ZEPHIR_INIT_CLASS(Brisk_Kernel_Loader) {

	ZEPHIR_REGISTER_CLASS(Brisk\\Kernel, Loader, brisk, kernel_loader, brisk_kernel_loader_method_entry, 0);

	zend_declare_property_null(brisk_kernel_loader_ce, SL("_alias"), ZEND_ACC_PRIVATE|ZEND_ACC_STATIC TSRMLS_CC);

	zend_declare_property_null(brisk_kernel_loader_ce, SL("_namespaces"), ZEND_ACC_PRIVATE|ZEND_ACC_STATIC TSRMLS_CC);

	return SUCCESS;

}

/**
 * Set directory path aliases
 *
 * @param string alias
 * @param string path
 * @return null
 */
PHP_METHOD(Brisk_Kernel_Loader, setAlias) {

	zval *alias_param = NULL, *path_param = NULL;
	zval *alias = NULL, *path = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &alias_param, &path_param);

	if (UNEXPECTED(Z_TYPE_P(alias_param) != IS_STRING && Z_TYPE_P(alias_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'alias' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(alias_param) == IS_STRING)) {
		zephir_get_strval(alias, alias_param);
	} else {
		ZEPHIR_INIT_VAR(alias);
		ZVAL_EMPTY_STRING(alias);
	}
	if (UNEXPECTED(Z_TYPE_P(path_param) != IS_STRING && Z_TYPE_P(path_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'path' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(path_param) == IS_STRING)) {
		zephir_get_strval(path, path_param);
	} else {
		ZEPHIR_INIT_VAR(path);
		ZVAL_EMPTY_STRING(path);
	}


	zephir_update_static_property_array_multi_ce(brisk_kernel_loader_ce, SL("_alias"), &path TSRMLS_CC, SL("z"), 1, alias);
	ZEPHIR_MM_RESTORE();

}

/**
 * Set namespace path
 *
 * @param string nspace
 * @param string path
 * @return null
 */
PHP_METHOD(Brisk_Kernel_Loader, setNameSpace) {

	zval *nspace_param = NULL, *path_param = NULL, *_0, _1, *nspath = NULL, *_2, *_3$$3;
	zval *nspace = NULL, *path = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &nspace_param, &path_param);

	if (UNEXPECTED(Z_TYPE_P(nspace_param) != IS_STRING && Z_TYPE_P(nspace_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'nspace' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(nspace_param) == IS_STRING)) {
		zephir_get_strval(nspace, nspace_param);
	} else {
		ZEPHIR_INIT_VAR(nspace);
		ZVAL_EMPTY_STRING(nspace);
	}
	if (UNEXPECTED(Z_TYPE_P(path_param) != IS_STRING && Z_TYPE_P(path_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'path' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(path_param) == IS_STRING)) {
		zephir_get_strval(path, path_param);
	} else {
		ZEPHIR_INIT_VAR(path);
		ZVAL_EMPTY_STRING(path);
	}


	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_STRING(&_1, "\\", 0);
	zephir_fast_trim(_0, nspace, &_1, ZEPHIR_TRIM_RIGHT TSRMLS_CC);
	zephir_get_strval(nspace, _0);
	ZEPHIR_INIT_VAR(nspath);
	array_init(nspath);
	_2 = zephir_fetch_static_property_ce(brisk_kernel_loader_ce, SL("_namespaces") TSRMLS_CC);
	if (zephir_array_isset(_2, nspace)) {
		_3$$3 = zephir_fetch_static_property_ce(brisk_kernel_loader_ce, SL("_namespaces") TSRMLS_CC);
		ZEPHIR_OBS_NVAR(nspath);
		zephir_array_fetch(&nspath, _3$$3, nspace, PH_NOISY, "brisk/Kernel/Loader.zep", 36 TSRMLS_CC);
	}
	if (!(zephir_fast_in_array(path, nspath TSRMLS_CC))) {
		zephir_array_append(&nspath, path, PH_SEPARATE, "brisk/Kernel/Loader.zep", 39);
	}
	zephir_update_static_property_array_multi_ce(brisk_kernel_loader_ce, SL("_namespaces"), &nspath TSRMLS_CC, SL("z"), 1, nspace);
	ZEPHIR_MM_RESTORE();

}

/**
 * Get aliases
 *
 * @return array
 */
PHP_METHOD(Brisk_Kernel_Loader, getAlias) {

	zval *_0;


	_0 = zephir_fetch_static_property_ce(brisk_kernel_loader_ce, SL("_alias") TSRMLS_CC);
	RETURN_CTORW(_0);

}

/**
 * Set namespace path
 *
 * @return array
 */
PHP_METHOD(Brisk_Kernel_Loader, getNameSpace) {

	zval *_0;


	_0 = zephir_fetch_static_property_ce(brisk_kernel_loader_ce, SL("_namespaces") TSRMLS_CC);
	RETURN_CTORW(_0);

}

/**
 * Automatically load class name
 *
 * @param string classname
 * @return null
 */
PHP_METHOD(Brisk_Kernel_Loader, autoLoad) {

	zephir_fcall_cache_entry *_2 = NULL, *_4 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *classname_param = NULL, *path = NULL, *_0$$3, *_1$$3 = NULL, *_3$$3;
	zval *classname = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &classname_param);

	if (UNEXPECTED(Z_TYPE_P(classname_param) != IS_STRING && Z_TYPE_P(classname_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'classname' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(classname_param) == IS_STRING)) {
		zephir_get_strval(classname, classname_param);
	} else {
		ZEPHIR_INIT_VAR(classname);
		ZVAL_EMPTY_STRING(classname);
	}


	ZEPHIR_CALL_SELF(&path, "findclass", NULL, 0, classname);
	zephir_check_call_status();
	if (ZEPHIR_IS_STRING(path, "")) {
		ZEPHIR_INIT_VAR(_0$$3);
		object_init_ex(_0$$3, brisk_exception_runtimeexception_ce);
		ZEPHIR_INIT_VAR(_3$$3);
		ZVAL_STRING(_3$$3, "core.class_path_notfound", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_CE_STATIC(&_1$$3, brisk_kernel_language_ce, "get", &_2, 27, _3$$3, classname);
		zephir_check_temp_parameter(_3$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, _0$$3, "__construct", NULL, 28, _1$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(_0$$3, "brisk/Kernel/Loader.zep", 75 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_CE_STATIC(NULL, brisk_kernel_toolkit_ce, "includeonce", &_4, 51, path);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Find the class name corresponding file
 *
 * @param string classname
 * @return string
 */
PHP_METHOD(Brisk_Kernel_Loader, findClass) {

	zend_bool _11$$4;
	HashTable *_2, *_19;
	HashPosition _1, _18;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_15 = NULL, *_28 = NULL, *_36 = NULL;
	zval *classname_param = NULL, *formal = NULL, *key = NULL, *val = NULL, *_0, **_3, *item = NULL, *path = NULL, *_path = NULL, *_17, **_20, *_4$$3 = NULL, _5$$3 = zval_used_for_init, _6$$3 = zval_used_for_init, *_7$$3 = NULL, *_8$$3 = NULL, *_9$$3 = NULL, *_10$$3 = NULL, *_12$$4, *_13$$6, *_14$$6 = NULL, *_16$$6, *_21$$7 = NULL, _22$$7 = zval_used_for_init, *_23$$7 = NULL, *_24$$7 = NULL, *_25$$7, *_26$$7 = NULL, *_27$$7 = NULL, *_29$$7 = NULL, _30$$7 = zval_used_for_init, _31$$7 = zval_used_for_init, *_32$$7 = NULL, *_33$$7 = NULL, *_34$$7 = NULL, *_35$$7 = NULL;
	zval *classname = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &classname_param);

	if (UNEXPECTED(Z_TYPE_P(classname_param) != IS_STRING && Z_TYPE_P(classname_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'classname' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(classname_param) == IS_STRING)) {
		zephir_get_strval(classname, classname_param);
	} else {
		ZEPHIR_INIT_VAR(classname);
		ZVAL_EMPTY_STRING(classname);
	}


	ZEPHIR_INIT_VAR(formal);
	array_init(formal);
	_0 = zephir_fetch_static_property_ce(brisk_kernel_loader_ce, SL("_namespaces") TSRMLS_CC);
	zephir_is_iterable(_0, &_2, &_1, 0, 0, "brisk/Kernel/Loader.zep", 100);
	for (
	  ; zend_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zend_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HMKEY(key, _2, _1);
		ZEPHIR_GET_HVALUE(val, _3);
		ZEPHIR_INIT_NVAR(_4$$3);
		ZEPHIR_SINIT_NVAR(_5$$3);
		ZVAL_STRING(&_5$$3, "\\", 0);
		zephir_fast_trim(_4$$3, key, &_5$$3, ZEPHIR_TRIM_LEFT TSRMLS_CC);
		ZEPHIR_CPY_WRT(key, _4$$3);
		ZEPHIR_INIT_NVAR(_4$$3);
		ZEPHIR_SINIT_NVAR(_6$$3);
		ZVAL_STRING(&_6$$3, "\\", 0);
		zephir_fast_trim(_4$$3, classname, &_6$$3, ZEPHIR_TRIM_LEFT TSRMLS_CC);
		zephir_get_strval(classname, _4$$3);
		ZEPHIR_INIT_NVAR(_7$$3);
		ZEPHIR_INIT_NVAR(_8$$3);
		ZEPHIR_INIT_NVAR(_9$$3);
		zephir_addslashes(_9$$3, key TSRMLS_CC);
		ZEPHIR_INIT_LNVAR(_10$$3);
		ZEPHIR_CONCAT_SVS(_10$$3, "/^", _9$$3, "\\\\/");
		zephir_preg_match(_8$$3, _10$$3, classname, _7$$3, 0, 0 , 0  TSRMLS_CC);
		if (zephir_is_true(_8$$3)) {
			_11$$4 = !zephir_is_true(formal);
			if (!(_11$$4)) {
				zephir_array_fetch_string(&_12$$4, formal, SL("key"), PH_NOISY | PH_READONLY, "brisk/Kernel/Loader.zep", 94 TSRMLS_CC);
				_11$$4 = zephir_fast_strlen_ev(key) > zephir_fast_strlen_ev(_12$$4);
			}
			if (_11$$4) {
				zephir_array_update_string(&formal, SL("key"), &key, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&formal, SL("val"), &val, PH_COPY | PH_SEPARATE);
			}
		}
	}
	if (!zephir_is_true(formal)) {
		ZEPHIR_INIT_VAR(_13$$6);
		object_init_ex(_13$$6, brisk_exception_runtimeexception_ce);
		ZEPHIR_INIT_VAR(_16$$6);
		ZVAL_STRING(_16$$6, "core.namespace_not_defined", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_CE_STATIC(&_14$$6, brisk_kernel_language_ce, "get", &_15, 27, _16$$6, classname);
		zephir_check_temp_parameter(_16$$6);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, _13$$6, "__construct", NULL, 28, _14$$6);
		zephir_check_call_status();
		zephir_throw_exception_debug(_13$$6, "brisk/Kernel/Loader.zep", 101 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(path);
	ZVAL_STRING(path, "", 1);
	zephir_array_fetch_string(&_17, formal, SL("val"), PH_NOISY | PH_READONLY, "brisk/Kernel/Loader.zep", 105 TSRMLS_CC);
	zephir_is_iterable(_17, &_19, &_18, 0, 0, "brisk/Kernel/Loader.zep", 114);
	for (
	  ; zend_hash_get_current_data_ex(_19, (void**) &_20, &_18) == SUCCESS
	  ; zend_hash_move_forward_ex(_19, &_18)
	) {
		ZEPHIR_GET_HVALUE(item, _20);
		ZEPHIR_INIT_NVAR(_21$$7);
		ZEPHIR_SINIT_NVAR(_22$$7);
		ZVAL_STRING(&_22$$7, "/", 0);
		zephir_fast_trim(_21$$7, item, &_22$$7, ZEPHIR_TRIM_RIGHT TSRMLS_CC);
		ZEPHIR_INIT_LNVAR(_23$$7);
		ZEPHIR_CONCAT_VS(_23$$7, _21$$7, "/");
		ZEPHIR_CPY_WRT(item, _23$$7);
		ZEPHIR_INIT_NVAR(_24$$7);
		zephir_array_fetch_string(&_25$$7, formal, SL("key"), PH_NOISY | PH_READONLY, "brisk/Kernel/Loader.zep", 107 TSRMLS_CC);
		zephir_addslashes(_24$$7, _25$$7 TSRMLS_CC);
		ZEPHIR_INIT_LNVAR(_23$$7);
		ZEPHIR_CONCAT_SVS(_23$$7, "/^", _24$$7, "\\\\/");
		ZEPHIR_INIT_NVAR(_26$$7);
		ZVAL_STRING(_26$$7, "", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_FUNCTION(&_27$$7, "preg_replace", &_28, 4, _23$$7, _26$$7, classname);
		zephir_check_temp_parameter(_26$$7);
		zephir_check_call_status();
		zephir_get_strval(classname, _27$$7);
		ZEPHIR_INIT_LNVAR(_29$$7);
		ZEPHIR_CONCAT_VV(_29$$7, item, classname);
		ZEPHIR_SINIT_NVAR(_30$$7);
		ZVAL_STRING(&_30$$7, "\\", 0);
		ZEPHIR_SINIT_NVAR(_31$$7);
		ZVAL_STRING(&_31$$7, "/", 0);
		ZEPHIR_INIT_NVAR(_path);
		zephir_fast_str_replace(&_path, &_30$$7, &_31$$7, _29$$7 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(_26$$7);
		ZVAL_STRING(_26$$7, "/\\.php$/", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_INIT_NVAR(_32$$7);
		ZVAL_STRING(_32$$7, "", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_FUNCTION(&_33$$7, "preg_replace", &_28, 4, _26$$7, _32$$7, _path);
		zephir_check_temp_parameter(_26$$7);
		zephir_check_temp_parameter(_32$$7);
		zephir_check_call_status();
		ZEPHIR_INIT_LNVAR(_34$$7);
		ZEPHIR_CONCAT_VS(_34$$7, _33$$7, ".php");
		ZEPHIR_CPY_WRT(_path, _34$$7);
		ZEPHIR_CALL_FUNCTION(&_35$$7, "is_file", &_36, 49, _path);
		zephir_check_call_status();
		if (zephir_is_true(_35$$7)) {
			ZEPHIR_CPY_WRT(path, _path);
		}
	}
	RETURN_CCTOR(path);

}

/**
 * Find the corresponding file
 *
 * @param string spacename
 * @return string
 */
PHP_METHOD(Brisk_Kernel_Loader, realPath) {

	zval *_10, *_1$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL, *_9 = NULL;
	zval *spacename_param = NULL, *parsed = NULL, *_7, *_8 = NULL, *_11, *alias$$3 = NULL, *space$$3 = NULL, *_2$$3 = NULL, *_3$$3, *_4$$3, *_5$$3, _6$$3;
	zval *spacename = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &spacename_param);

	if (UNEXPECTED(Z_TYPE_P(spacename_param) != IS_STRING && Z_TYPE_P(spacename_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'spacename' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(spacename_param) == IS_STRING)) {
		zephir_get_strval(spacename, spacename_param);
	} else {
		ZEPHIR_INIT_VAR(spacename);
		ZVAL_EMPTY_STRING(spacename);
	}


	ZEPHIR_CALL_SELF(&parsed, "_parse", &_0, 52, spacename);
	zephir_check_call_status();
	if (zephir_fast_count_int(parsed TSRMLS_CC) > 0) {
		ZEPHIR_OBS_VAR(alias$$3);
		zephir_array_fetch_long(&alias$$3, parsed, 0, PH_NOISY, "brisk/Kernel/Loader.zep", 128 TSRMLS_CC);
		ZEPHIR_OBS_VAR(space$$3);
		zephir_array_fetch_long(&space$$3, parsed, 1, PH_NOISY, "brisk/Kernel/Loader.zep", 129 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_1$$3);
		zephir_create_array(_1$$3, 2, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_2$$3);
		ZVAL_STRING(_2$$3, "/", 1);
		zephir_array_fast_append(_1$$3, _2$$3);
		ZEPHIR_INIT_NVAR(_2$$3);
		ZVAL_STRING(_2$$3, "\\", 1);
		zephir_array_fast_append(_1$$3, _2$$3);
		_3$$3 = zephir_fetch_static_property_ce(brisk_kernel_loader_ce, SL("_alias") TSRMLS_CC);
		zephir_array_fetch(&_4$$3, _3$$3, alias$$3, PH_NOISY | PH_READONLY, "brisk/Kernel/Loader.zep", 130 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_5$$3);
		ZEPHIR_CONCAT_VV(_5$$3, _4$$3, space$$3);
		ZEPHIR_SINIT_VAR(_6$$3);
		ZVAL_STRING(&_6$$3, "/", 0);
		ZEPHIR_INIT_NVAR(_2$$3);
		zephir_fast_str_replace(&_2$$3, _1$$3, &_6$$3, _5$$3 TSRMLS_CC);
		RETURN_CCTOR(_2$$3);
	}
	ZEPHIR_INIT_VAR(_7);
	object_init_ex(_7, brisk_exception_runtimeexception_ce);
	ZEPHIR_INIT_VAR(_10);
	zephir_create_array(_10, 1, 0 TSRMLS_CC);
	zephir_array_fast_append(_10, spacename);
	ZEPHIR_INIT_VAR(_11);
	ZVAL_STRING(_11, "core.format_path_failed", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_CE_STATIC(&_8, brisk_kernel_language_ce, "get", &_9, 27, _11, _10);
	zephir_check_temp_parameter(_11);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, _7, "__construct", NULL, 28, _8);
	zephir_check_call_status();
	zephir_throw_exception_debug(_7, "brisk/Kernel/Loader.zep", 132 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

/**
 * Convert file path format
 *
 * @param string path
 * @return string
 */
PHP_METHOD(Brisk_Kernel_Loader, reducePath) {

	HashTable *_2;
	HashPosition _1;
	zval *path_param = NULL, *key = NULL, *val = NULL, *_0, **_3, _5, _6, *_7, *_4$$3 = NULL;
	zval *path = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &path_param);

	if (UNEXPECTED(Z_TYPE_P(path_param) != IS_STRING && Z_TYPE_P(path_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'path' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(path_param) == IS_STRING)) {
		zephir_get_strval(path, path_param);
	} else {
		ZEPHIR_INIT_VAR(path);
		ZVAL_EMPTY_STRING(path);
	}


	_0 = zephir_fetch_static_property_ce(brisk_kernel_loader_ce, SL("_alias") TSRMLS_CC);
	zephir_is_iterable(_0, &_2, &_1, 0, 0, "brisk/Kernel/Loader.zep", 147);
	for (
	  ; zend_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zend_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HMKEY(key, _2, _1);
		ZEPHIR_GET_HVALUE(val, _3);
		ZEPHIR_INIT_NVAR(_4$$3);
		zephir_fast_str_replace(&_4$$3, val, key, path TSRMLS_CC);
		zephir_get_strval(path, _4$$3);
	}
	ZEPHIR_SINIT_VAR(_5);
	ZVAL_STRING(&_5, "\\", 0);
	ZEPHIR_SINIT_VAR(_6);
	ZVAL_STRING(&_6, "/", 0);
	ZEPHIR_INIT_VAR(_7);
	zephir_fast_str_replace(&_7, &_5, &_6, path TSRMLS_CC);
	RETURN_CCTOR(_7);

}

PHP_METHOD(Brisk_Kernel_Loader, _parse) {

	zval *nspace_param = NULL, *alias = NULL, _0, _1, *path = NULL, _2, *_3;
	zval *nspace = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &nspace_param);

	if (UNEXPECTED(Z_TYPE_P(nspace_param) != IS_STRING && Z_TYPE_P(nspace_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'nspace' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(nspace_param) == IS_STRING)) {
		zephir_get_strval(nspace, nspace_param);
	} else {
		ZEPHIR_INIT_VAR(nspace);
		ZVAL_EMPTY_STRING(nspace);
	}


	ZEPHIR_SINIT_VAR(_0);
	ZVAL_LONG(&_0, 0);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_LONG(&_1, 1);
	ZEPHIR_INIT_VAR(alias);
	zephir_substr(alias, nspace, 0 , 1 , 0);
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_LONG(&_2, 1);
	ZEPHIR_INIT_VAR(path);
	zephir_substr(path, nspace, 1 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
	_3 = zephir_fetch_static_property_ce(brisk_kernel_loader_ce, SL("_alias") TSRMLS_CC);
	if (!(zephir_array_key_exists(_3, alias TSRMLS_CC))) {
		array_init(return_value);
		RETURN_MM();
	}
	zephir_create_array(return_value, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(return_value, alias);
	zephir_array_fast_append(return_value, path);
	RETURN_MM();

}

void zephir_init_static_properties_Brisk_Kernel_Loader(TSRMLS_D) {

	zval *_0, *_1;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_update_static_property_ce(brisk_kernel_loader_ce, SL("_namespaces"), &_0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	array_init(_1);
	zephir_update_static_property_ce(brisk_kernel_loader_ce, SL("_alias"), &_1 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}


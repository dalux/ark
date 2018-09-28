
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
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/array.h"
#include "kernel/variables.h"
#include "kernel/string.h"
#include "kernel/operators.h"
#include "kernel/file.h"
#include "kernel/concat.h"


ZEPHIR_INIT_CLASS(Brisk_Kernel_Toolkit) {

	ZEPHIR_REGISTER_CLASS(Brisk\\Kernel, Toolkit, brisk, kernel_toolkit, brisk_kernel_toolkit_method_entry, 0);

	return SUCCESS;

}

/**
 * Get array variable string
 *
 * @param array params
 * @return string
 */
PHP_METHOD(Brisk_Kernel_Toolkit, sprintr) {

	HashTable *_1;
	HashPosition _0;
	zephir_fcall_cache_entry *_3 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *params_param = NULL, *arg = NULL, **_2, *_5 = NULL, *_6, *_7, *_4$$3 = NULL;
	zval *params = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &params_param);

	params = params_param;


	ZEPHIR_CALL_FUNCTION(NULL, "ob_start", NULL, 78);
	zephir_check_call_status();
	zephir_is_iterable(params, &_1, &_0, 0, 0, "brisk/Kernel/Toolkit.zep", 22);
	for (
	  ; zend_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zend_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HVALUE(arg, _2);
		ZEPHIR_CALL_FUNCTION(NULL, "print_r", &_3, 79, arg);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_4$$3);
		ZEPHIR_GET_CONSTANT(_4$$3, "PHP_EOL");
		zend_print_zval(_4$$3, 0);
	}
	ZEPHIR_CALL_FUNCTION(&_5, "ob_get_clean", NULL, 80);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_6);
	ZVAL_STRING(_6, "/\\]\\=\\>\\n(\\s+)/m", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_7);
	ZVAL_STRING(_7, "] => ", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_FUNCTION("preg_replace", NULL, 4, _6, _7, _5);
	zephir_check_temp_parameter(_6);
	zephir_check_temp_parameter(_7);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Formatted print array variable
 *
 * @param array params
 * @return null
 */
PHP_METHOD(Brisk_Kernel_Toolkit, printr) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *params_param = NULL, *result = NULL, *_1 = NULL, *_3 = NULL, _4, *_5 = NULL;
	zval *params = NULL, *_0, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &params_param);

	params = params_param;


	ZEPHIR_INIT_VAR(_0);
	zephir_create_array(_0, 2, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "Brisk\\Kernel\\Toolkit", 1);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "sprintr", 1);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_VAR(_2);
	zephir_create_array(_2, 1, 0 TSRMLS_CC);
	zephir_array_fast_append(_2, params);
	ZEPHIR_INIT_VAR(result);
	ZEPHIR_CALL_USER_FUNC_ARRAY(result, _0, _2);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_3, "htmlspecialchars", NULL, 41, result);
	zephir_check_call_status();
	ZEPHIR_SINIT_VAR(_4);
	ZVAL_STRING(&_4, "<pre>%s</pre>", 0);
	ZEPHIR_CALL_FUNCTION(&_5, "sprintf", NULL, 40, &_4, _3);
	zephir_check_call_status();
	zend_print_zval(_5, 0);
	ZEPHIR_MM_RESTORE();

}

/**
 * Get array variable string
 *
 * @param array params
 * @return string
 */
PHP_METHOD(Brisk_Kernel_Toolkit, svardump) {

	HashTable *_1;
	HashPosition _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *params_param = NULL, *arg = NULL, **_2, *_3 = NULL, *_4, *_5;
	zval *params = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &params_param);

	params = params_param;


	ZEPHIR_CALL_FUNCTION(NULL, "ob_start", NULL, 78);
	zephir_check_call_status();
	zephir_is_iterable(params, &_1, &_0, 0, 0, "brisk/Kernel/Toolkit.zep", 50);
	for (
	  ; zend_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zend_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HVALUE(arg, _2);
		zephir_var_dump(&arg TSRMLS_CC);
	}
	ZEPHIR_CALL_FUNCTION(&_3, "ob_get_clean", NULL, 80);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_4);
	ZVAL_STRING(_4, "/\\]\\=\\>\\n(\\s+)/m", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_5);
	ZVAL_STRING(_5, "] => ", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_FUNCTION("preg_replace", NULL, 4, _4, _5, _3);
	zephir_check_temp_parameter(_4);
	zephir_check_temp_parameter(_5);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Formatted print array variable
 *
 * @param array params
 * @return null
 */
PHP_METHOD(Brisk_Kernel_Toolkit, vardump) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *params_param = NULL, *result = NULL, *_1 = NULL, *_3 = NULL, _4, *_5 = NULL;
	zval *params = NULL, *_0, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &params_param);

	params = params_param;


	ZEPHIR_INIT_VAR(_0);
	zephir_create_array(_0, 2, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "Brisk\\Kernel\\Toolkit", 1);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "svardump", 1);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_VAR(_2);
	zephir_create_array(_2, 1, 0 TSRMLS_CC);
	zephir_array_fast_append(_2, params);
	ZEPHIR_INIT_VAR(result);
	ZEPHIR_CALL_USER_FUNC_ARRAY(result, _0, _2);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_3, "htmlspecialchars", NULL, 41, result);
	zephir_check_call_status();
	ZEPHIR_SINIT_VAR(_4);
	ZVAL_STRING(&_4, "<pre>%s</pre>", 0);
	ZEPHIR_CALL_FUNCTION(&_5, "sprintf", NULL, 40, &_4, _3);
	zephir_check_call_status();
	zend_print_zval(_5, 0);
	ZEPHIR_MM_RESTORE();

}

/**
 * Recursively create a directory
 *
 * @param string dir
 * @return bool
 */
PHP_METHOD(Brisk_Kernel_Toolkit, mkDir) {

	zend_bool _14$$6;
	HashTable *_10$$5;
	HashPosition _9$$5;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_3 = NULL, *_6 = NULL, *_17 = NULL;
	zval *dir_param = NULL, *_0, *dirs = NULL, *_1$$3, *_2$$3 = NULL, *_4$$3, *_5$$4 = NULL, *_7$$5 = NULL, *v$$5 = NULL, *_8$$5 = NULL, **_11$$5, *_12$$6 = NULL, _13$$6 = zval_used_for_init, _15$$6 = zval_used_for_init, *_16$$6 = NULL;
	zval *dir = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &dir_param);

	if (UNEXPECTED(Z_TYPE_P(dir_param) != IS_STRING && Z_TYPE_P(dir_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'dir' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(dir_param) == IS_STRING)) {
		zephir_get_strval(dir, dir_param);
	} else {
		ZEPHIR_INIT_VAR(dir);
		ZVAL_EMPTY_STRING(dir);
	}


	ZEPHIR_INIT_VAR(_0);
	zephir_fast_trim(_0, dir, NULL , ZEPHIR_TRIM_BOTH TSRMLS_CC);
	zephir_get_strval(dir, _0);
	if (ZEPHIR_IS_STRING(dir, "")) {
		ZEPHIR_INIT_VAR(_1$$3);
		object_init_ex(_1$$3, brisk_exception_runtimeexception_ce);
		ZEPHIR_INIT_VAR(_4$$3);
		ZVAL_STRING(_4$$3, "tbox.invalid_create_path", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_CE_STATIC(&_2$$3, brisk_kernel_language_ce, "get", &_3, 27, _4$$3);
		zephir_check_temp_parameter(_4$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, _1$$3, "__construct", NULL, 28, _2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(_1$$3, "brisk/Kernel/Toolkit.zep", 75 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(dirs);
	zephir_create_array(dirs, 1, 0 TSRMLS_CC);
	zephir_array_fast_append(dirs, dir);
	while (1) {
		if (!(!((zephir_file_exists(dir TSRMLS_CC) == SUCCESS)))) {
			break;
		}
		ZEPHIR_CALL_FUNCTION(&_5$$4, "dirname", &_6, 16, dir);
		zephir_check_call_status();
		zephir_get_strval(dir, _5$$4);
		zephir_array_append(&dirs, dir, PH_SEPARATE, "brisk/Kernel/Toolkit.zep", 80);
	}
	if (zephir_fast_count_int(dirs TSRMLS_CC) > 1) {
		ZEPHIR_CALL_FUNCTION(&_7$$5, "array_reverse", NULL, 81, dirs);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(dirs, _7$$5);
		ZEPHIR_INIT_VAR(_8$$5);
		zephir_is_iterable(dirs, &_10$$5, &_9$$5, 0, 0, "brisk/Kernel/Toolkit.zep", 91);
		for (
		  ; zend_hash_get_current_data_ex(_10$$5, (void**) &_11$$5, &_9$$5) == SUCCESS
		  ; zend_hash_move_forward_ex(_10$$5, &_9$$5)
		) {
			ZEPHIR_GET_HMKEY(_8$$5, _10$$5, _9$$5);
			ZEPHIR_GET_HVALUE(v$$5, _11$$5);
			ZEPHIR_INIT_NVAR(_12$$6);
			ZEPHIR_SINIT_NVAR(_13$$6);
			ZVAL_STRING(&_13$$6, "/", 0);
			zephir_fast_trim(_12$$6, v$$5, &_13$$6, ZEPHIR_TRIM_RIGHT TSRMLS_CC);
			ZEPHIR_CPY_WRT(v$$5, _12$$6);
			_14$$6 = !((zephir_file_exists(v$$5 TSRMLS_CC) == SUCCESS));
			if (_14$$6) {
				ZEPHIR_SINIT_NVAR(_15$$6);
				ZVAL_LONG(&_15$$6, 0777);
				ZEPHIR_CALL_FUNCTION(&_16$$6, "mkdir", &_17, 82, v$$5, &_15$$6);
				zephir_check_call_status();
				_14$$6 = !zephir_is_true(_16$$6);
			}
			if (_14$$6) {
				RETURN_MM_BOOL(0);
			}
		}
	}
	RETURN_MM_BOOL(1);

}

/**
 * Recursively copy a directory
 *
 * @param string src
 * @param string dst
 * @return null
 */
PHP_METHOD(Brisk_Kernel_Toolkit, copyDir) {

	zend_bool _1$$3;
	zephir_fcall_cache_entry *_0 = NULL, *_4 = NULL, *_5 = NULL, *_10 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *src_param = NULL, *dst_param = NULL, *handle = NULL, *file = NULL, *_2$$5 = NULL, *_3$$5 = NULL, *_6$$6 = NULL, *_7$$6 = NULL, *_8$$7 = NULL, *_9$$7 = NULL;
	zval *src = NULL, *dst = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &src_param, &dst_param);

	if (UNEXPECTED(Z_TYPE_P(src_param) != IS_STRING && Z_TYPE_P(src_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'src' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(src_param) == IS_STRING)) {
		zephir_get_strval(src, src_param);
	} else {
		ZEPHIR_INIT_VAR(src);
		ZVAL_EMPTY_STRING(src);
	}
	if (UNEXPECTED(Z_TYPE_P(dst_param) != IS_STRING && Z_TYPE_P(dst_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'dst' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(dst_param) == IS_STRING)) {
		zephir_get_strval(dst, dst_param);
	} else {
		ZEPHIR_INIT_VAR(dst);
		ZVAL_EMPTY_STRING(dst);
	}


	ZEPHIR_CALL_FUNCTION(&handle, "opendir", NULL, 83, src);
	zephir_check_call_status();
	ZEPHIR_CALL_SELF(NULL, "mkdir", NULL, 0, dst);
	zephir_check_call_status();
	while (1) {
		if (!(1)) {
			break;
		}
		ZEPHIR_CALL_FUNCTION(&file, "readdir", &_0, 84, handle);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE(file)) {
			break;
		}
		_1$$3 = (!ZEPHIR_IS_STRING(file, "."));
		if (_1$$3) {
			_1$$3 = (!ZEPHIR_IS_STRING(file, ".."));
		}
		if (_1$$3) {
			ZEPHIR_INIT_LNVAR(_2$$5);
			ZEPHIR_CONCAT_VSV(_2$$5, src, "/", file);
			ZEPHIR_CALL_FUNCTION(&_3$$5, "is_dir", &_4, 85, _2$$5);
			zephir_check_call_status();
			if (zephir_is_true(_3$$5)) {
				ZEPHIR_INIT_LNVAR(_6$$6);
				ZEPHIR_CONCAT_VSV(_6$$6, src, "/", file);
				ZEPHIR_INIT_LNVAR(_7$$6);
				ZEPHIR_CONCAT_VSV(_7$$6, dst, "/", file);
				ZEPHIR_CALL_SELF(NULL, "copydir", &_5, 0, _6$$6, _7$$6);
				zephir_check_call_status();
			} else {
				ZEPHIR_INIT_LNVAR(_8$$7);
				ZEPHIR_CONCAT_VSV(_8$$7, src, "/", file);
				ZEPHIR_INIT_LNVAR(_9$$7);
				ZEPHIR_CONCAT_VSV(_9$$7, dst, "/", file);
				ZEPHIR_CALL_FUNCTION(NULL, "copy", &_10, 86, _8$$7, _9$$7);
				zephir_check_call_status();
			}
		}
	}
	ZEPHIR_CALL_FUNCTION(NULL, "closedir", NULL, 87, handle);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Recursively remove a directory
 *
 * @param string dir_name
 * @return null
 */
PHP_METHOD(Brisk_Kernel_Toolkit, removeDir) {

	zval *_3$$4 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL, *_2 = NULL, *_6 = NULL, *_7 = NULL;
	zval *dir_name_param = NULL, *_0 = NULL, *handle$$3 = NULL, *file$$3 = NULL, *_4$$4 = NULL, *dir$$6 = NULL, *_5$$6 = NULL;
	zval *dir_name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &dir_name_param);

	if (UNEXPECTED(Z_TYPE_P(dir_name_param) != IS_STRING && Z_TYPE_P(dir_name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'dir_name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(dir_name_param) == IS_STRING)) {
		zephir_get_strval(dir_name, dir_name_param);
	} else {
		ZEPHIR_INIT_VAR(dir_name);
		ZVAL_EMPTY_STRING(dir_name);
	}


	ZEPHIR_CALL_FUNCTION(&_0, "is_dir", &_1, 85, dir_name);
	zephir_check_call_status();
	if (zephir_is_true(_0)) {
		ZEPHIR_CALL_FUNCTION(&handle$$3, "opendir", NULL, 83, dir_name);
		zephir_check_call_status();
		while (1) {
			if (!(1)) {
				break;
			}
			ZEPHIR_CALL_FUNCTION(&file$$3, "readdir", &_2, 84, handle$$3);
			zephir_check_call_status();
			if (ZEPHIR_IS_FALSE(file$$3)) {
				break;
			}
			ZEPHIR_INIT_NVAR(_3$$4);
			zephir_create_array(_3$$4, 2, 0 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(_4$$4);
			ZVAL_STRING(_4$$4, ".", 1);
			zephir_array_fast_append(_3$$4, _4$$4);
			ZEPHIR_INIT_NVAR(_4$$4);
			ZVAL_STRING(_4$$4, "..", 1);
			zephir_array_fast_append(_3$$4, _4$$4);
			if (!(zephir_fast_in_array(file$$3, _3$$4 TSRMLS_CC))) {
				ZEPHIR_INIT_NVAR(dir$$6);
				ZEPHIR_CONCAT_VSV(dir$$6, dir_name, "/", file$$3);
				ZEPHIR_CALL_FUNCTION(&_5$$6, "is_dir", &_1, 85, dir$$6);
				zephir_check_call_status();
				if (zephir_is_true(_5$$6)) {
					ZEPHIR_CALL_SELF(NULL, "removedir", &_6, 0, dir$$6);
					zephir_check_call_status();
				} else {
					ZEPHIR_CALL_FUNCTION(NULL, "unlink", &_7, 88, dir$$6);
					zephir_check_call_status();
				}
			}
		}
		ZEPHIR_CALL_FUNCTION(NULL, "closedir", NULL, 87, handle$$3);
		zephir_check_call_status();
		ZEPHIR_RETURN_CALL_FUNCTION("rmdir", NULL, 89, dir_name);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_MM_RESTORE();

}


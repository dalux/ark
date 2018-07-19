
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

PHP_METHOD(Brisk_Kernel_Toolkit, sprintr) {

	zephir_fcall_cache_entry *_1 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *params_param = NULL, arg, *_0, _3, _4, _5, _2$$3;
	zval params;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&arg);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_2$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &params_param);

	ZEPHIR_OBS_COPY_OR_DUP(&params, params_param);


	ZEPHIR_CALL_FUNCTION(NULL, "ob_start", NULL, 57);
	zephir_check_call_status();
	zephir_is_iterable(&params, 0, "brisk/Kernel/Toolkit.zep", 16);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&params), _0)
	{
		ZEPHIR_INIT_NVAR(&arg);
		ZVAL_COPY(&arg, _0);
		ZEPHIR_CALL_FUNCTION(NULL, "print_r", &_1, 58, &arg);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_2$$3);
		ZEPHIR_GET_CONSTANT(&_2$$3, "PHP_EOL");
		zend_print_zval(&_2$$3, 0);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&arg);
	ZEPHIR_CALL_FUNCTION(&_3, "ob_get_clean", NULL, 59);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "/\\]\\=\\>\\n(\\s+)/m");
	ZEPHIR_INIT_VAR(&_5);
	ZVAL_STRING(&_5, "] => ");
	ZEPHIR_RETURN_CALL_FUNCTION("preg_replace", NULL, 2, &_4, &_5, &_3);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Brisk_Kernel_Toolkit, printr) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *params_param = NULL, result, _1, _3, _4;
	zval params, _0, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &params_param);

	ZEPHIR_OBS_COPY_OR_DUP(&params, params_param);


	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 2, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "Brisk\\Kernel\\Toolkit");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "sprintr");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_VAR(&_2);
	zephir_create_array(&_2, 1, 0 TSRMLS_CC);
	zephir_array_fast_append(&_2, &params);
	ZEPHIR_INIT_VAR(&result);
	ZEPHIR_CALL_USER_FUNC_ARRAY(&result, &_0, &_2);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_3, "htmlspecialchars", NULL, 36, &result);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "<pre>%s</pre>");
	ZEPHIR_CALL_FUNCTION(&_4, "sprintf", NULL, 4, &_1, &_3);
	zephir_check_call_status();
	zend_print_zval(&_4, 0);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Brisk_Kernel_Toolkit, svardump) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *params_param = NULL, arg, *_0, _1, _2, _3;
	zval params;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&arg);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &params_param);

	ZEPHIR_OBS_COPY_OR_DUP(&params, params_param);


	ZEPHIR_CALL_FUNCTION(NULL, "ob_start", NULL, 57);
	zephir_check_call_status();
	zephir_is_iterable(&params, 0, "brisk/Kernel/Toolkit.zep", 32);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&params), _0)
	{
		ZEPHIR_INIT_NVAR(&arg);
		ZVAL_COPY(&arg, _0);
		zephir_var_dump(&arg TSRMLS_CC);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&arg);
	ZEPHIR_CALL_FUNCTION(&_1, "ob_get_clean", NULL, 59);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "/\\]\\=\\>\\n(\\s+)/m");
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "] => ");
	ZEPHIR_RETURN_CALL_FUNCTION("preg_replace", NULL, 2, &_2, &_3, &_1);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Brisk_Kernel_Toolkit, vardump) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *params_param = NULL, result, _1, _3, _4;
	zval params, _0, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &params_param);

	ZEPHIR_OBS_COPY_OR_DUP(&params, params_param);


	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 2, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "Brisk\\Kernel\\Toolkit");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "svardump");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_VAR(&_2);
	zephir_create_array(&_2, 1, 0 TSRMLS_CC);
	zephir_array_fast_append(&_2, &params);
	ZEPHIR_INIT_VAR(&result);
	ZEPHIR_CALL_USER_FUNC_ARRAY(&result, &_0, &_2);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_3, "htmlspecialchars", NULL, 36, &result);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "<pre>%s</pre>");
	ZEPHIR_CALL_FUNCTION(&_4, "sprintf", NULL, 4, &_1, &_3);
	zephir_check_call_status();
	zend_print_zval(&_4, 0);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Brisk_Kernel_Toolkit, mkDir) {

	zend_bool _14$$6;
	zend_string *_11$$5;
	zend_ulong _10$$5;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_3 = NULL, *_6 = NULL, *_17 = NULL;
	zval *dir_param = NULL, _0, dirs, _1$$3, _2$$3, _4$$3, _5$$4, _7$$5, v$$5, _8$$5, *_9$$5, _12$$6, _13$$6, _15$$6, _16$$6;
	zval dir;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&dir);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&dirs);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&v$$5);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_12$$6);
	ZVAL_UNDEF(&_13$$6);
	ZVAL_UNDEF(&_15$$6);
	ZVAL_UNDEF(&_16$$6);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &dir_param);

	if (UNEXPECTED(Z_TYPE_P(dir_param) != IS_STRING && Z_TYPE_P(dir_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'dir' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(dir_param) == IS_STRING)) {
		zephir_get_strval(&dir, dir_param);
	} else {
		ZEPHIR_INIT_VAR(&dir);
		ZVAL_EMPTY_STRING(&dir);
	}


	ZEPHIR_INIT_VAR(&_0);
	zephir_fast_trim(&_0, &dir, NULL , ZEPHIR_TRIM_BOTH TSRMLS_CC);
	zephir_get_strval(&dir, &_0);
	if (ZEPHIR_IS_STRING(&dir, "")) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, brisk_exception_kernelexception_ce);
		ZEPHIR_INIT_VAR(&_4$$3);
		ZVAL_STRING(&_4$$3, "tbox.invalid_create_path");
		ZEPHIR_CALL_CE_STATIC(&_2$$3, brisk_kernel_language_ce, "get", &_3, 0, &_4$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 3, &_2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "brisk/Kernel/Toolkit.zep", 45 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&dirs);
	zephir_create_array(&dirs, 1, 0 TSRMLS_CC);
	zephir_array_fast_append(&dirs, &dir);
	while (1) {
		if (!(!((zephir_file_exists(&dir TSRMLS_CC) == SUCCESS)))) {
			break;
		}
		ZEPHIR_CALL_FUNCTION(&_5$$4, "dirname", &_6, 18, &dir);
		zephir_check_call_status();
		zephir_get_strval(&dir, &_5$$4);
		zephir_array_append(&dirs, &dir, PH_SEPARATE, "brisk/Kernel/Toolkit.zep", 50);
	}
	if (zephir_fast_count_int(&dirs TSRMLS_CC) > 1) {
		ZEPHIR_CALL_FUNCTION(&_7$$5, "array_reverse", NULL, 60, &dirs);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&dirs, &_7$$5);
		ZEPHIR_INIT_VAR(&_8$$5);
		zephir_is_iterable(&dirs, 0, "brisk/Kernel/Toolkit.zep", 61);
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&dirs), _10$$5, _11$$5, _9$$5)
		{
			ZEPHIR_INIT_NVAR(&_8$$5);
			if (_11$$5 != NULL) { 
				ZVAL_STR_COPY(&_8$$5, _11$$5);
			} else {
				ZVAL_LONG(&_8$$5, _10$$5);
			}
			ZEPHIR_INIT_NVAR(&v$$5);
			ZVAL_COPY(&v$$5, _9$$5);
			ZEPHIR_INIT_NVAR(&_12$$6);
			ZEPHIR_INIT_NVAR(&_13$$6);
			ZVAL_STRING(&_13$$6, "/");
			zephir_fast_trim(&_12$$6, &v$$5, &_13$$6, ZEPHIR_TRIM_RIGHT TSRMLS_CC);
			ZEPHIR_CPY_WRT(&v$$5, &_12$$6);
			_14$$6 = !((zephir_file_exists(&v$$5 TSRMLS_CC) == SUCCESS));
			if (_14$$6) {
				ZVAL_LONG(&_15$$6, 0777);
				ZEPHIR_CALL_FUNCTION(&_16$$6, "mkdir", &_17, 61, &v$$5, &_15$$6);
				zephir_check_call_status();
				_14$$6 = !zephir_is_true(&_16$$6);
			}
			if (_14$$6) {
				RETURN_MM_BOOL(0);
			}
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&v$$5);
		ZEPHIR_INIT_NVAR(&_8$$5);
	}
	RETURN_MM_BOOL(1);

}

PHP_METHOD(Brisk_Kernel_Toolkit, copyDir) {

	zend_bool _1$$3;
	zephir_fcall_cache_entry *_0 = NULL, *_4 = NULL, *_5 = NULL, *_10 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *src_param = NULL, *dst_param = NULL, handle, file, _2$$5, _3$$5, _6$$6, _7$$6, _8$$7, _9$$7;
	zval src, dst;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&src);
	ZVAL_UNDEF(&dst);
	ZVAL_UNDEF(&handle);
	ZVAL_UNDEF(&file);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_6$$6);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_8$$7);
	ZVAL_UNDEF(&_9$$7);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &src_param, &dst_param);

	if (UNEXPECTED(Z_TYPE_P(src_param) != IS_STRING && Z_TYPE_P(src_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'src' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(src_param) == IS_STRING)) {
		zephir_get_strval(&src, src_param);
	} else {
		ZEPHIR_INIT_VAR(&src);
		ZVAL_EMPTY_STRING(&src);
	}
	if (UNEXPECTED(Z_TYPE_P(dst_param) != IS_STRING && Z_TYPE_P(dst_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'dst' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(dst_param) == IS_STRING)) {
		zephir_get_strval(&dst, dst_param);
	} else {
		ZEPHIR_INIT_VAR(&dst);
		ZVAL_EMPTY_STRING(&dst);
	}


	ZEPHIR_CALL_FUNCTION(&handle, "opendir", NULL, 62, &src);
	zephir_check_call_status();
	ZEPHIR_CALL_SELF(NULL, "mkdir", NULL, 0, &dst);
	zephir_check_call_status();
	while (1) {
		if (!(1)) {
			break;
		}
		ZEPHIR_CALL_FUNCTION(&file, "readdir", &_0, 63, &handle);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE(&file)) {
			break;
		}
		_1$$3 = (!ZEPHIR_IS_STRING(&file, "."));
		if (_1$$3) {
			_1$$3 = (!ZEPHIR_IS_STRING(&file, ".."));
		}
		if (_1$$3) {
			ZEPHIR_INIT_LNVAR(_2$$5);
			ZEPHIR_CONCAT_VSV(&_2$$5, &src, "/", &file);
			ZEPHIR_CALL_FUNCTION(&_3$$5, "is_dir", &_4, 12, &_2$$5);
			zephir_check_call_status();
			if (zephir_is_true(&_3$$5)) {
				ZEPHIR_INIT_LNVAR(_6$$6);
				ZEPHIR_CONCAT_VSV(&_6$$6, &src, "/", &file);
				ZEPHIR_INIT_LNVAR(_7$$6);
				ZEPHIR_CONCAT_VSV(&_7$$6, &dst, "/", &file);
				ZEPHIR_CALL_SELF(NULL, "copydir", &_5, 0, &_6$$6, &_7$$6);
				zephir_check_call_status();
			} else {
				ZEPHIR_INIT_LNVAR(_8$$7);
				ZEPHIR_CONCAT_VSV(&_8$$7, &src, "/", &file);
				ZEPHIR_INIT_LNVAR(_9$$7);
				ZEPHIR_CONCAT_VSV(&_9$$7, &dst, "/", &file);
				ZEPHIR_CALL_FUNCTION(NULL, "copy", &_10, 64, &_8$$7, &_9$$7);
				zephir_check_call_status();
			}
		}
	}
	ZEPHIR_CALL_FUNCTION(NULL, "closedir", NULL, 65, &handle);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Brisk_Kernel_Toolkit, removeDir) {

	zval _3$$4;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL, *_2 = NULL, *_6 = NULL, *_7 = NULL;
	zval *dir_name_param = NULL, _0, handle$$3, file$$3, _4$$4, dir$$6, _5$$6;
	zval dir_name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&dir_name);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&handle$$3);
	ZVAL_UNDEF(&file$$3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&dir$$6);
	ZVAL_UNDEF(&_5$$6);
	ZVAL_UNDEF(&_3$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &dir_name_param);

	if (UNEXPECTED(Z_TYPE_P(dir_name_param) != IS_STRING && Z_TYPE_P(dir_name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'dir_name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(dir_name_param) == IS_STRING)) {
		zephir_get_strval(&dir_name, dir_name_param);
	} else {
		ZEPHIR_INIT_VAR(&dir_name);
		ZVAL_EMPTY_STRING(&dir_name);
	}


	ZEPHIR_CALL_FUNCTION(&_0, "is_dir", &_1, 12, &dir_name);
	zephir_check_call_status();
	if (zephir_is_true(&_0)) {
		ZEPHIR_CALL_FUNCTION(&handle$$3, "opendir", NULL, 62, &dir_name);
		zephir_check_call_status();
		while (1) {
			if (!(1)) {
				break;
			}
			ZEPHIR_CALL_FUNCTION(&file$$3, "readdir", &_2, 63, &handle$$3);
			zephir_check_call_status();
			if (ZEPHIR_IS_FALSE(&file$$3)) {
				break;
			}
			ZEPHIR_INIT_NVAR(&_3$$4);
			zephir_create_array(&_3$$4, 2, 0 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(&_4$$4);
			ZVAL_STRING(&_4$$4, ".");
			zephir_array_fast_append(&_3$$4, &_4$$4);
			ZEPHIR_INIT_NVAR(&_4$$4);
			ZVAL_STRING(&_4$$4, "..");
			zephir_array_fast_append(&_3$$4, &_4$$4);
			if (!(zephir_fast_in_array(&file$$3, &_3$$4 TSRMLS_CC))) {
				ZEPHIR_INIT_NVAR(&dir$$6);
				ZEPHIR_CONCAT_VSV(&dir$$6, &dir_name, "/", &file$$3);
				ZEPHIR_CALL_FUNCTION(&_5$$6, "is_dir", &_1, 12, &dir$$6);
				zephir_check_call_status();
				if (zephir_is_true(&_5$$6)) {
					ZEPHIR_CALL_SELF(NULL, "removedir", &_6, 0, &dir$$6);
					zephir_check_call_status();
				} else {
					ZEPHIR_CALL_FUNCTION(NULL, "unlink", &_7, 16, &dir$$6);
					zephir_check_call_status();
				}
			}
		}
		ZEPHIR_CALL_FUNCTION(NULL, "closedir", NULL, 65, &handle$$3);
		zephir_check_call_status();
		ZEPHIR_RETURN_CALL_FUNCTION("rmdir", NULL, 66, &dir_name);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_MM_RESTORE();

}


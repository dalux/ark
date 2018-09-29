
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
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "kernel/array.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/time.h"
#include "kernel/file.h"
#include "kernel/concat.h"
#include "kernel/string.h"


ZEPHIR_INIT_CLASS(Brisk_Vendor_Cache_File) {

	ZEPHIR_REGISTER_CLASS_EX(Brisk\\Vendor\\Cache, File, brisk, vendor_cache_file, brisk_vendor_cache_cachefather_ce, brisk_vendor_cache_file_method_entry, 0);

	zend_declare_property_string(brisk_vendor_cache_file_ce, SL("_ext_name"), ".cache", ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_string(brisk_vendor_cache_file_ce, SL("_dir"), "", ZEND_ACC_PRIVATE TSRMLS_CC);

	return SUCCESS;

}

/**
 * Construct
 *
 * @param string save_path
 * @param array option
 * @return null
 */
PHP_METHOD(Brisk_Vendor_Cache_File, __construct) {

	zend_bool _2, _8;
	zephir_fcall_cache_entry *_4 = NULL, *_13 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *option = NULL, *_14$$3, *_19$$4;
	zval *save_path_param = NULL, *option_param = NULL, *_0, *_1 = NULL, *_3 = NULL, *_5, *_6, *_7 = NULL, *_9, *_10 = NULL, *_22, *_24, *_11$$3, *_12$$3 = NULL, *_15$$3, *_16$$3, *_17$$4, *_18$$4 = NULL, *_20$$4, *_21$$4, *_23$$5, *_25$$6;
	zval *save_path = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &save_path_param, &option_param);

	if (UNEXPECTED(Z_TYPE_P(save_path_param) != IS_STRING && Z_TYPE_P(save_path_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'save_path' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(save_path_param) == IS_STRING)) {
		zephir_get_strval(save_path, save_path_param);
	} else {
		ZEPHIR_INIT_VAR(save_path);
		ZVAL_EMPTY_STRING(save_path);
	}
	if (!option_param) {
		ZEPHIR_INIT_VAR(option);
		array_init(option);
	} else {
	option = option_param;
	}


	zephir_update_property_this(getThis(), SL("_dir"), save_path TSRMLS_CC);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_dir"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(&_1, "is_dir", NULL, 87, _0);
	zephir_check_call_status();
	_2 = !zephir_is_true(_1);
	if (_2) {
		_5 = zephir_fetch_nproperty_this(this_ptr, SL("_dir"), PH_NOISY_CC);
		ZEPHIR_CALL_CE_STATIC(&_3, brisk_kernel_toolkit_ce, "mkdir", &_4, 96, _5);
		zephir_check_call_status();
		_2 = !zephir_is_true(_3);
	}
	_6 = zephir_fetch_nproperty_this(this_ptr, SL("_dir"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(&_7, "is_readable", NULL, 97, _6);
	zephir_check_call_status();
	_8 = !zephir_is_true(_7);
	if (!(_8)) {
		_9 = zephir_fetch_nproperty_this(this_ptr, SL("_dir"), PH_NOISY_CC);
		ZEPHIR_CALL_FUNCTION(&_10, "is_writable", NULL, 98, _9);
		zephir_check_call_status();
		_8 = !zephir_is_true(_10);
	}
	if (_2) {
		ZEPHIR_INIT_VAR(_11$$3);
		object_init_ex(_11$$3, brisk_exception_runtimeexception_ce);
		ZEPHIR_INIT_VAR(_14$$3);
		zephir_create_array(_14$$3, 1, 0 TSRMLS_CC);
		ZEPHIR_OBS_VAR(_15$$3);
		zephir_read_property_this(&_15$$3, this_ptr, SL("_dir"), PH_NOISY_CC);
		zephir_array_fast_append(_14$$3, _15$$3);
		ZEPHIR_INIT_VAR(_16$$3);
		ZVAL_STRING(_16$$3, "cache.dir_create_failed", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_CE_STATIC(&_12$$3, brisk_kernel_language_ce, "get", &_13, 27, _16$$3, _14$$3);
		zephir_check_temp_parameter(_16$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, _11$$3, "__construct", NULL, 28, _12$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(_11$$3, "brisk/Vendor/Cache/File.zep", 25 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	} else if (_8) {
		ZEPHIR_INIT_VAR(_17$$4);
		object_init_ex(_17$$4, brisk_exception_runtimeexception_ce);
		ZEPHIR_INIT_VAR(_19$$4);
		zephir_create_array(_19$$4, 1, 0 TSRMLS_CC);
		ZEPHIR_OBS_VAR(_20$$4);
		zephir_read_property_this(&_20$$4, this_ptr, SL("_dir"), PH_NOISY_CC);
		zephir_array_fast_append(_19$$4, _20$$4);
		ZEPHIR_INIT_VAR(_21$$4);
		ZVAL_STRING(_21$$4, "cache.dir_permission_error", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_CE_STATIC(&_18$$4, brisk_kernel_language_ce, "get", &_13, 27, _21$$4, _19$$4);
		zephir_check_temp_parameter(_21$$4);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, _17$$4, "__construct", NULL, 28, _18$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(_17$$4, "brisk/Vendor/Cache/File.zep", 27 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_array_fetch_string(&_22, option, SL("ext_name"), PH_NOISY | PH_READONLY, "brisk/Vendor/Cache/File.zep", 29 TSRMLS_CC);
	if (!(Z_TYPE_P(_22) == IS_NULL)) {
		zephir_array_fetch_string(&_23$$5, option, SL("ext_name"), PH_NOISY | PH_READONLY, "brisk/Vendor/Cache/File.zep", 30 TSRMLS_CC);
		zephir_update_property_this(getThis(), SL("_ext_name"), _23$$5 TSRMLS_CC);
	}
	zephir_array_fetch_string(&_24, option, SL("flag"), PH_NOISY | PH_READONLY, "brisk/Vendor/Cache/File.zep", 32 TSRMLS_CC);
	if (!(Z_TYPE_P(_24) == IS_NULL)) {
		zephir_array_fetch_string(&_25$$6, option, SL("flag"), PH_NOISY | PH_READONLY, "brisk/Vendor/Cache/File.zep", 33 TSRMLS_CC);
		zephir_update_property_this(getThis(), SL("_flag"), _25$$6 TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Set Cache data
 *
 * @param string name
 * @param mixed value
 * @param int expire
 * @return bool
 */
PHP_METHOD(Brisk_Vendor_Cache_File, set) {

	zend_long expire, ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *value, *expire_param = NULL, *path = NULL, *expire_time = NULL, *_0, *_1, *_2, *_3 = NULL, *_4;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &name_param, &value, &expire_param);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(name, name_param);
	} else {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	}
	if (!expire_param) {
		expire = 86400;
	} else {
	if (UNEXPECTED(Z_TYPE_P(expire_param) != IS_LONG)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'expire' must be a int") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	expire = Z_LVAL_P(expire_param);
	}


	ZEPHIR_CALL_METHOD(&path, this_ptr, "getcachepath", NULL, 0, name);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_0);
	zephir_time(_0);
	ZEPHIR_INIT_VAR(expire_time);
	ZVAL_LONG(expire_time, (zephir_get_numberval(_0) + expire));
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_INIT_VAR(_2);
	ZEPHIR_CALL_FUNCTION(&_3, "serialize", NULL, 95, value);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_4);
	ZEPHIR_CONCAT_VV(_4, expire_time, _3);
	zephir_file_put_contents(_2, path, _4 TSRMLS_CC);
	if (zephir_is_true(_2)) {
		ZVAL_BOOL(_1, 1);
	} else {
		ZVAL_BOOL(_1, 0);
	}
	RETURN_CCTOR(_1);

}

/**
 * Get Cache data
 *
 * @param string name
 * @return mixed
 */
PHP_METHOD(Brisk_Vendor_Cache_File, get) {

	zend_bool _0;
	zephir_fcall_cache_entry *_2 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *path = NULL, *content = NULL, *_1, *timeflag = NULL, _3, _4, *_5, *_6, *tmp = NULL, _7, *_8;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(name, name_param);
	} else {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	}


	ZEPHIR_CALL_METHOD(&path, this_ptr, "getcachepath", NULL, 0, name);
	zephir_check_call_status();
	_0 = !((zephir_file_exists(path TSRMLS_CC) == SUCCESS));
	if (!(_0)) {
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("_caching"), PH_NOISY_CC);
		_0 = !zephir_is_true(_1);
	}
	if (_0) {
		ZEPHIR_CALL_FUNCTION(NULL, "unlink", &_2, 90, path);
		zephir_check_call_status();
		RETURN_MM_NULL();
	}
	ZEPHIR_INIT_VAR(content);
	zephir_file_get_contents(content, path TSRMLS_CC);
	if (ZEPHIR_IS_FALSE_IDENTICAL(content)) {
		ZEPHIR_CALL_FUNCTION(NULL, "unlink", &_2, 90, path);
		zephir_check_call_status();
		RETURN_MM_NULL();
	}
	ZEPHIR_SINIT_VAR(_3);
	ZVAL_LONG(&_3, 0);
	ZEPHIR_SINIT_VAR(_4);
	ZVAL_LONG(&_4, 10);
	ZEPHIR_INIT_VAR(_5);
	zephir_substr(_5, content, 0 , 10 , 0);
	ZEPHIR_INIT_VAR(timeflag);
	ZVAL_LONG(timeflag, zephir_get_intval(_5));
	ZEPHIR_INIT_VAR(_6);
	zephir_time(_6);
	if (ZEPHIR_LT(timeflag, _6)) {
		ZEPHIR_CALL_FUNCTION(NULL, "unlink", &_2, 90, path);
		zephir_check_call_status();
		RETURN_MM_NULL();
	}
	ZEPHIR_SINIT_VAR(_7);
	ZVAL_LONG(&_7, 10);
	ZEPHIR_INIT_VAR(_8);
	zephir_substr(_8, content, 10 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
	ZEPHIR_CALL_FUNCTION(&tmp, "unserialize", NULL, 99, _8);
	zephir_check_call_status();
	if (!ZEPHIR_IS_FALSE_IDENTICAL(tmp)) {
		RETURN_CCTOR(tmp);
	}
	RETURN_MM_NULL();

}

/**
 * Delete Cache data
 *
 * @param string name
 * @return bool
 */
PHP_METHOD(Brisk_Vendor_Cache_File, delete) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *path = NULL, *deleted$$3 = NULL, *_0$$3;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(name, name_param);
	} else {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	}


	ZEPHIR_CALL_METHOD(&path, this_ptr, "getcachepath", NULL, 0, name);
	zephir_check_call_status();
	if ((zephir_file_exists(path TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_CALL_FUNCTION(&deleted$$3, "unlink", NULL, 90, path);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_0$$3);
		if (zephir_is_true(deleted$$3)) {
			ZVAL_BOOL(_0$$3, 1);
		} else {
			ZVAL_BOOL(_0$$3, 0);
		}
		RETURN_CCTOR(_0$$3);
	}
	RETURN_MM_BOOL(1);

}

PHP_METHOD(Brisk_Vendor_Cache_File, __set) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *value;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name_param, &value);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(name, name_param);
	} else {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	}


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "set", NULL, 0, name, value);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Brisk_Vendor_Cache_File, __get) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(name, name_param);
	} else {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	}


	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "get", NULL, 0, name);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Get cache data save location
 *
 * @param string name
 * @return string
 */
PHP_METHOD(Brisk_Vendor_Cache_File, getCachePath) {

	zend_bool _22;
	zval *_10, *_17, *_7$$4, *_28$$6;
	zephir_fcall_cache_entry *_13 = NULL, *_21 = NULL, *_24 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *path = NULL, *_0, _1, *_2, *_5 = NULL, *_6, *part = NULL, *_9, *_15, *_16, *_18 = NULL, _19, *_20 = NULL, *_23 = NULL, *_25 = NULL, *_3$$3, *_4$$3, *_8$$4, *_11$$5, *_12$$5 = NULL, *_14$$5, *_26$$6, *_27$$6 = NULL, *_29$$6;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(name, name_param);
	} else {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_dir"), PH_NOISY_CC);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_STRING(&_1, "/", 0);
	ZEPHIR_INIT_VAR(path);
	zephir_fast_trim(path, _0, &_1, ZEPHIR_TRIM_RIGHT TSRMLS_CC);
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("_flag"), PH_NOISY_CC);
	if (!ZEPHIR_IS_STRING(_2, "")) {
		_3$$3 = zephir_fetch_nproperty_this(this_ptr, SL("_flag"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_4$$3);
		ZEPHIR_CONCAT_VSV(_4$$3, path, "/", _3$$3);
		ZEPHIR_CPY_WRT(path, _4$$3);
	}
	ZEPHIR_INIT_VAR(_5);
	ZEPHIR_CONCAT_VS(_5, path, "/");
	ZEPHIR_CPY_WRT(path, _5);
	_6 = zephir_fetch_nproperty_this(this_ptr, SL("_format"), PH_NOISY_CC);
	if (!(zephir_is_callable(_6 TSRMLS_CC))) {
		ZEPHIR_INIT_VAR(_7$$4);
		zephir_create_array(_7$$4, 2, 0 TSRMLS_CC);
		zephir_array_fast_append(_7$$4, this_ptr);
		ZEPHIR_INIT_VAR(_8$$4);
		ZVAL_STRING(_8$$4, "_formatPath", 1);
		zephir_array_fast_append(_7$$4, _8$$4);
		zephir_update_property_this(getThis(), SL("_format"), _7$$4 TSRMLS_CC);
	}
	_9 = zephir_fetch_nproperty_this(this_ptr, SL("_format"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_10);
	zephir_create_array(_10, 1, 0 TSRMLS_CC);
	zephir_array_fast_append(_10, name);
	ZEPHIR_INIT_VAR(part);
	ZEPHIR_CALL_USER_FUNC_ARRAY(part, _9, _10);
	zephir_check_call_status();
	if (Z_TYPE_P(part) == IS_NULL) {
		ZEPHIR_INIT_VAR(_11$$5);
		object_init_ex(_11$$5, brisk_exception_runtimeexception_ce);
		ZEPHIR_INIT_VAR(_14$$5);
		ZVAL_STRING(_14$$5, "cache.path_mustbe_notnull", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_CE_STATIC(&_12$$5, brisk_kernel_language_ce, "get", &_13, 27, _14$$5);
		zephir_check_temp_parameter(_14$$5);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, _11$$5, "__construct", NULL, 28, _12$$5);
		zephir_check_call_status();
		zephir_throw_exception_debug(_11$$5, "brisk/Vendor/Cache/File.zep", 134 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	_15 = zephir_fetch_nproperty_this(this_ptr, SL("_ext_name"), PH_NOISY_CC);
	ZEPHIR_INIT_LNVAR(_5);
	ZEPHIR_CONCAT_VVV(_5, path, part, _15);
	ZEPHIR_CPY_WRT(path, _5);
	ZEPHIR_INIT_VAR(_16);
	ZEPHIR_INIT_VAR(_17);
	zephir_create_array(_17, 2, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_18);
	ZVAL_STRING(_18, "\\", 1);
	zephir_array_fast_append(_17, _18);
	ZEPHIR_INIT_NVAR(_18);
	ZVAL_STRING(_18, "/", 1);
	zephir_array_fast_append(_17, _18);
	ZEPHIR_SINIT_VAR(_19);
	ZVAL_STRING(&_19, "/", 0);
	zephir_fast_str_replace(&_16, _17, &_19, path TSRMLS_CC);
	ZEPHIR_CPY_WRT(path, _16);
	ZEPHIR_CALL_FUNCTION(&_20, "dirname", &_21, 16, path);
	zephir_check_call_status();
	_22 = !((zephir_file_exists(_20 TSRMLS_CC) == SUCCESS));
	if (_22) {
		ZEPHIR_CALL_FUNCTION(&_25, "dirname", &_21, 16, path);
		zephir_check_call_status();
		ZEPHIR_CALL_CE_STATIC(&_23, brisk_kernel_toolkit_ce, "mkdir", &_24, 96, _25);
		zephir_check_call_status();
		_22 = !zephir_is_true(_23);
	}
	if (_22) {
		ZEPHIR_INIT_VAR(_26$$6);
		object_init_ex(_26$$6, brisk_exception_runtimeexception_ce);
		ZEPHIR_INIT_VAR(_28$$6);
		zephir_create_array(_28$$6, 1, 0 TSRMLS_CC);
		zephir_array_fast_append(_28$$6, path);
		ZEPHIR_INIT_VAR(_29$$6);
		ZVAL_STRING(_29$$6, "cache.dir_create_failed", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_CE_STATIC(&_27$$6, brisk_kernel_language_ce, "get", &_13, 27, _29$$6, _28$$6);
		zephir_check_temp_parameter(_29$$6);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, _26$$6, "__construct", NULL, 28, _27$$6);
		zephir_check_call_status();
		zephir_throw_exception_debug(_26$$6, "brisk/Vendor/Cache/File.zep", 139 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_CCTOR(path);

}

PHP_METHOD(Brisk_Vendor_Cache_File, _formatPath) {

	zval *name_param = NULL, *_0, _1, _2, *_3, _4, _5, *_6;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(name, name_param);
	} else {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	}


	ZEPHIR_INIT_VAR(_0);
	zephir_md5(_0, name);
	zephir_get_strval(name, _0);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_LONG(&_1, 0);
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_LONG(&_2, 1);
	ZEPHIR_INIT_VAR(_3);
	zephir_substr(_3, name, 0 , 1 , 0);
	ZEPHIR_SINIT_VAR(_4);
	ZVAL_LONG(&_4, 1);
	ZEPHIR_SINIT_VAR(_5);
	ZVAL_LONG(&_5, 1);
	ZEPHIR_INIT_VAR(_6);
	zephir_substr(_6, name, 1 , 1 , 0);
	ZEPHIR_CONCAT_VSVSV(return_value, _3, "/", _6, "/", name);
	RETURN_MM();

}



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
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "kernel/array.h"
#include "kernel/object.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/concat.h"
#include "kernel/string.h"


ZEPHIR_INIT_CLASS(Brisk_Vendor_Cache_Memcached) {

	ZEPHIR_REGISTER_CLASS_EX(Brisk\\Vendor\\Cache, Memcached, brisk, vendor_cache_memcached, brisk_vendor_cache_cachefather_ce, brisk_vendor_cache_memcached_method_entry, 0);

	zend_declare_property_null(brisk_vendor_cache_memcached_ce, SL("_container"), ZEND_ACC_PRIVATE TSRMLS_CC);

	return SUCCESS;

}

/**
 * Construct
 *
 * @param string save_path
 * @param array option
 * @return null
 */
PHP_METHOD(Brisk_Vendor_Cache_Memcached, __construct) {

	zend_bool _14$$6;
	HashTable *_10, *_21;
	HashPosition _9, _20;
	zephir_fcall_cache_entry *_4 = NULL, *_12 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *option = NULL, *_5$$3, *_27$$9;
	zval *save_path_param = NULL, *option_param = NULL, _0, *_1 = NULL, *list_savepath = NULL, *_7, *v = NULL, *url = NULL, *_8 = NULL, **_11, *params = NULL, *_19, *key = NULL, *val = NULL, **_22, *version = NULL, *_24, *_2$$3, *_3$$3 = NULL, *_6$$3 = NULL, *_13$$6, *_15$$6, *_16$$7, *_17$$7, *_18$$7, *_23$$8, *_25$$9, *_26$$9 = NULL, *_28$$9 = NULL;
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


	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "memcached", 0);
	ZEPHIR_CALL_FUNCTION(&_1, "extension_loaded", NULL, 100, &_0);
	zephir_check_call_status();
	if (!zephir_is_true(_1)) {
		ZEPHIR_INIT_VAR(_2$$3);
		object_init_ex(_2$$3, brisk_exception_runtimeexception_ce);
		ZEPHIR_INIT_VAR(_5$$3);
		zephir_create_array(_5$$3, 1, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_6$$3);
		ZVAL_STRING(_6$$3, "php_memcached", 1);
		zephir_array_fast_append(_5$$3, _6$$3);
		ZEPHIR_INIT_NVAR(_6$$3);
		ZVAL_STRING(_6$$3, "cache.extension_load_failed", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_CE_STATIC(&_3$$3, brisk_kernel_language_ce, "get", &_4, 27, _6$$3, _5$$3);
		zephir_check_temp_parameter(_6$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, _2$$3, "__construct", NULL, 28, _3$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(_2$$3, "brisk/Vendor/Cache/Memcached.zep", 21 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (!(Z_TYPE_P(save_path) == IS_ARRAY)) {
		ZEPHIR_INIT_VAR(list_savepath);
		zephir_create_array(list_savepath, 1, 0 TSRMLS_CC);
		zephir_array_fast_append(list_savepath, save_path);
	} else {
		ZEPHIR_CPY_WRT(list_savepath, save_path);
	}
	ZEPHIR_INIT_VAR(_7);
	object_init_ex(_7, zephir_get_internal_ce(SS("memcached") TSRMLS_CC));
	ZEPHIR_CALL_METHOD(NULL, _7, "__construct", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_this(getThis(), SL("_container"), _7 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_8);
	zephir_is_iterable(list_savepath, &_10, &_9, 0, 0, "brisk/Vendor/Cache/Memcached.zep", 37);
	for (
	  ; zend_hash_get_current_data_ex(_10, (void**) &_11, &_9) == SUCCESS
	  ; zend_hash_move_forward_ex(_10, &_9)
	) {
		ZEPHIR_GET_HMKEY(_8, _10, _9);
		ZEPHIR_GET_HVALUE(v, _11);
		ZEPHIR_CALL_FUNCTION(&url, "parse_url", &_12, 72, v);
		zephir_check_call_status();
		zephir_array_fetch_string(&_13$$6, url, SL("host"), PH_NOISY | PH_READONLY, "brisk/Vendor/Cache/Memcached.zep", 33 TSRMLS_CC);
		_14$$6 = !ZEPHIR_IS_STRING(_13$$6, "");
		if (_14$$6) {
			zephir_array_fetch_string(&_15$$6, url, SL("port"), PH_NOISY | PH_READONLY, "brisk/Vendor/Cache/Memcached.zep", 33 TSRMLS_CC);
			_14$$6 = !ZEPHIR_IS_STRING(_15$$6, "");
		}
		if (_14$$6) {
			_16$$7 = zephir_fetch_nproperty_this(this_ptr, SL("_container"), PH_NOISY_CC);
			zephir_array_fetch_string(&_17$$7, url, SL("host"), PH_NOISY | PH_READONLY, "brisk/Vendor/Cache/Memcached.zep", 34 TSRMLS_CC);
			zephir_array_fetch_string(&_18$$7, url, SL("port"), PH_NOISY | PH_READONLY, "brisk/Vendor/Cache/Memcached.zep", 34 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(NULL, _16$$7, "addserver", NULL, 0, _17$$7, _18$$7);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_VAR(params);
	zephir_create_array(params, 5, 0 TSRMLS_CC);
	add_index_long(params, 9, 1);
	zephir_array_update_long(&params, 16, &ZEPHIR_GLOBAL(global_true), PH_COPY ZEPHIR_DEBUG_PARAMS_DUMMY);
	add_index_long(params, 14, 500);
	zephir_array_update_long(&params, -1001, &ZEPHIR_GLOBAL(global_true), PH_COPY ZEPHIR_DEBUG_PARAMS_DUMMY);
	zephir_array_update_long(&params, 35, &ZEPHIR_GLOBAL(global_true), PH_COPY ZEPHIR_DEBUG_PARAMS_DUMMY);
	ZEPHIR_INIT_VAR(_19);
	zephir_fast_array_merge(_19, &(params), &(option) TSRMLS_CC);
	ZEPHIR_CPY_WRT(params, _19);
	zephir_is_iterable(params, &_21, &_20, 0, 0, "brisk/Vendor/Cache/Memcached.zep", 50);
	for (
	  ; zend_hash_get_current_data_ex(_21, (void**) &_22, &_20) == SUCCESS
	  ; zend_hash_move_forward_ex(_21, &_20)
	) {
		ZEPHIR_GET_HMKEY(key, _21, _20);
		ZEPHIR_GET_HVALUE(val, _22);
		_23$$8 = zephir_fetch_nproperty_this(this_ptr, SL("_container"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(NULL, _23$$8, "setoption", NULL, 0, key, val);
		zephir_check_call_status();
	}
	_24 = zephir_fetch_nproperty_this(this_ptr, SL("_container"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&version, _24, "getversion", NULL, 0);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(version)) {
		ZEPHIR_INIT_VAR(_25$$9);
		object_init_ex(_25$$9, brisk_exception_runtimeexception_ce);
		ZEPHIR_INIT_VAR(_27$$9);
		zephir_create_array(_27$$9, 1, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_28$$9);
		ZVAL_STRING(_28$$9, "Memcached", 1);
		zephir_array_fast_append(_27$$9, _28$$9);
		ZEPHIR_INIT_NVAR(_28$$9);
		ZVAL_STRING(_28$$9, "cache.cacher_create_failed", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_CE_STATIC(&_26$$9, brisk_kernel_language_ce, "get", &_4, 27, _28$$9, _27$$9);
		zephir_check_temp_parameter(_28$$9);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, _25$$9, "__construct", NULL, 28, _26$$9);
		zephir_check_call_status();
		zephir_throw_exception_debug(_25$$9, "brisk/Vendor/Cache/Memcached.zep", 53 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
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
PHP_METHOD(Brisk_Vendor_Cache_Memcached, set) {

	zend_long expire, ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *value, *expire_param = NULL, *path = NULL, *_0, *_1, *_2, *_3 = NULL;
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
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_container"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_LONG(_1, expire);
	ZEPHIR_CALL_METHOD(NULL, _0, "set", NULL, 0, path, value, _1);
	zephir_check_call_status();
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("_container"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_3, _2, "getresultcode", NULL, 0);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_LONG(_3, 0));

}

/**
 * Get Cache data
 *
 * @param string name
 * @return mixed
 */
PHP_METHOD(Brisk_Vendor_Cache_Memcached, get) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *data = NULL, *path = NULL, *_0, *_1$$3, *code$$3 = NULL, *_2$$3;
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
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_caching"), PH_NOISY_CC);
	if (zephir_is_true(_0)) {
		_1$$3 = zephir_fetch_nproperty_this(this_ptr, SL("_container"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&data, _1$$3, "get", NULL, 0, path);
		zephir_check_call_status();
		_2$$3 = zephir_fetch_nproperty_this(this_ptr, SL("_container"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&code$$3, _2$$3, "getresultcode", NULL, 0);
		zephir_check_call_status();
		if (!ZEPHIR_IS_LONG(code$$3, 0)) {
			ZEPHIR_INIT_NVAR(data);
			ZVAL_NULL(data);
		}
	}
	RETURN_CCTOR(data);

}

/**
 * Delete Cache data
 *
 * @param string name
 * @return bool
 */
PHP_METHOD(Brisk_Vendor_Cache_Memcached, delete) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *path = NULL, *code = NULL, *_0, *_1;
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
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_container"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _0, "delete", NULL, 0, path);
	zephir_check_call_status();
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_container"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&code, _1, "getresultcode", NULL, 0);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_LONG(code, 0));

}

PHP_METHOD(Brisk_Vendor_Cache_Memcached, __set) {

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


	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "set", NULL, 0, name, value);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Brisk_Vendor_Cache_Memcached, __get) {

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
PHP_METHOD(Brisk_Vendor_Cache_Memcached, getCachePath) {

	zval *_7, *_4$$4;
	zephir_fcall_cache_entry *_10 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *path = NULL, *_0, *_3, *part = NULL, *result = NULL, *_6, *_1$$3, *_2$$3, *_5$$4, *_8$$5, *_9$$5 = NULL, *_11$$5;
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


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_flag"), PH_NOISY_CC);
	if (zephir_is_true(_0)) {
		_1$$3 = zephir_fetch_nproperty_this(this_ptr, SL("_flag"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_2$$3);
		ZEPHIR_CONCAT_VVS(_2$$3, path, _1$$3, "_");
		ZEPHIR_CPY_WRT(path, _2$$3);
	}
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("_format"), PH_NOISY_CC);
	if (!(zephir_is_callable(_3 TSRMLS_CC))) {
		ZEPHIR_INIT_VAR(_4$$4);
		zephir_create_array(_4$$4, 2, 0 TSRMLS_CC);
		zephir_array_fast_append(_4$$4, this_ptr);
		ZEPHIR_INIT_VAR(_5$$4);
		ZVAL_STRING(_5$$4, "_formatPath", 1);
		zephir_array_fast_append(_4$$4, _5$$4);
		zephir_update_property_this(getThis(), SL("_format"), _4$$4 TSRMLS_CC);
	}
	_6 = zephir_fetch_nproperty_this(this_ptr, SL("_format"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_7);
	zephir_create_array(_7, 1, 0 TSRMLS_CC);
	zephir_array_fast_append(_7, name);
	ZEPHIR_INIT_VAR(part);
	ZEPHIR_CALL_USER_FUNC_ARRAY(part, _6, _7);
	zephir_check_call_status();
	if (Z_TYPE_P(part) == IS_NULL) {
		ZEPHIR_INIT_VAR(_8$$5);
		object_init_ex(_8$$5, brisk_exception_runtimeexception_ce);
		ZEPHIR_INIT_VAR(_11$$5);
		ZVAL_STRING(_11$$5, "cache.path_mustbe_notnull", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_CE_STATIC(&_9$$5, brisk_kernel_language_ce, "get", &_10, 27, _11$$5);
		zephir_check_temp_parameter(_11$$5);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, _8$$5, "__construct", NULL, 28, _9$$5);
		zephir_check_call_status();
		zephir_throw_exception_debug(_8$$5, "brisk/Vendor/Cache/Memcached.zep", 137 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(result);
	ZEPHIR_CONCAT_VV(result, path, part);
	RETURN_CCTOR(result);

}

/**
 * Return memcached instance
 *
 * @return \Memcached
 */
PHP_METHOD(Brisk_Vendor_Cache_Memcached, getInstance) {

	

	RETURN_MEMBER(getThis(), "_container");

}

PHP_METHOD(Brisk_Vendor_Cache_Memcached, _formatPath) {

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


	zephir_md5(return_value, name);
	RETURN_MM();

}


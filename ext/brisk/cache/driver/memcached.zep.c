
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


ZEPHIR_INIT_CLASS(Brisk_Cache_Driver_Memcached) {

	ZEPHIR_REGISTER_CLASS_EX(Brisk\\Cache\\Driver, Memcached, brisk, cache_driver_memcached, brisk_cache_cachefather_ce, brisk_cache_driver_memcached_method_entry, 0);

	zend_declare_property_null(brisk_cache_driver_memcached_ce, SL("_container"), ZEND_ACC_PRIVATE TSRMLS_CC);

	return SUCCESS;

}

/**
 * Construct
 *
 * @param string path
 * @param array setting
 * @return null
 */
PHP_METHOD(Brisk_Cache_Driver_Memcached, __construct) {

	zend_bool _20, is_valid = 0, _14$$6;
	HashTable *_10, *_25, *_31;
	HashPosition _9, _24, _30;
	zephir_fcall_cache_entry *_4 = NULL, *_12 = NULL, *_38 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *setting = NULL, *_5$$3, *_36$$12;
	zval *path_param = NULL, *setting_param = NULL, _0, *_1 = NULL, *servers = NULL, *_7, *v = NULL, *url = NULL, *_8 = NULL, **_11, *params = NULL, *_19, *_21, *key = NULL, *val = NULL, **_26, *item = NULL, *stats = NULL, *_28, *_29 = NULL, **_32, *_2$$3, *_3$$3 = NULL, *_6$$3 = NULL, *_13$$6, *_15$$6, *_16$$7, *_17$$7, *_18$$7, *_22$$8, *_23$$8, *_27$$9, *_33$$10, *_34$$12, *_35$$12 = NULL, *_37$$12 = NULL;
	zval *path = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &path_param, &setting_param);

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
	if (!setting_param) {
		ZEPHIR_INIT_VAR(setting);
		array_init(setting);
	} else {
	setting = setting_param;
	}


	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "memcached", 0);
	ZEPHIR_CALL_FUNCTION(&_1, "extension_loaded", NULL, 34, &_0);
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
		ZEPHIR_CALL_CE_STATIC(&_3$$3, brisk_kernel_language_ce, "get", &_4, 12, _6$$3, _5$$3);
		zephir_check_temp_parameter(_6$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, _2$$3, "__construct", NULL, 7, _3$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(_2$$3, "brisk/Cache/Driver/Memcached.zep", 22 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (!(Z_TYPE_P(path) == IS_ARRAY)) {
		ZEPHIR_INIT_VAR(servers);
		zephir_create_array(servers, 1, 0 TSRMLS_CC);
		zephir_array_fast_append(servers, path);
	} else {
		ZEPHIR_CPY_WRT(servers, path);
	}
	ZEPHIR_INIT_VAR(_7);
	object_init_ex(_7, zephir_get_internal_ce(SS("memcached") TSRMLS_CC));
	ZEPHIR_CALL_METHOD(NULL, _7, "__construct", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_this(getThis(), SL("_container"), _7 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_8);
	zephir_is_iterable(servers, &_10, &_9, 0, 0, "brisk/Cache/Driver/Memcached.zep", 38);
	for (
	  ; zend_hash_get_current_data_ex(_10, (void**) &_11, &_9) == SUCCESS
	  ; zend_hash_move_forward_ex(_10, &_9)
	) {
		ZEPHIR_GET_HMKEY(_8, _10, _9);
		ZEPHIR_GET_HVALUE(v, _11);
		ZEPHIR_CALL_FUNCTION(&url, "parse_url", &_12, 35, v);
		zephir_check_call_status();
		zephir_array_fetch_string(&_13$$6, url, SL("host"), PH_NOISY | PH_READONLY, "brisk/Cache/Driver/Memcached.zep", 34 TSRMLS_CC);
		_14$$6 = !ZEPHIR_IS_STRING(_13$$6, "");
		if (_14$$6) {
			zephir_array_fetch_string(&_15$$6, url, SL("port"), PH_NOISY | PH_READONLY, "brisk/Cache/Driver/Memcached.zep", 34 TSRMLS_CC);
			_14$$6 = !ZEPHIR_IS_STRING(_15$$6, "");
		}
		if (_14$$6) {
			_16$$7 = zephir_fetch_nproperty_this(this_ptr, SL("_container"), PH_NOISY_CC);
			zephir_array_fetch_string(&_17$$7, url, SL("host"), PH_NOISY | PH_READONLY, "brisk/Cache/Driver/Memcached.zep", 35 TSRMLS_CC);
			zephir_array_fetch_string(&_18$$7, url, SL("port"), PH_NOISY | PH_READONLY, "brisk/Cache/Driver/Memcached.zep", 35 TSRMLS_CC);
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
	zephir_array_fetch_string(&_19, setting, SL("memcached_options"), PH_NOISY | PH_READONLY, "brisk/Cache/Driver/Memcached.zep", 46 TSRMLS_CC);
	_20 = !(Z_TYPE_P(_19) == IS_NULL);
	if (_20) {
		zephir_array_fetch_string(&_21, setting, SL("memcached_options"), PH_NOISY | PH_READONLY, "brisk/Cache/Driver/Memcached.zep", 46 TSRMLS_CC);
		_20 = Z_TYPE_P(_21) == IS_ARRAY;
	}
	if (_20) {
		ZEPHIR_INIT_VAR(_22$$8);
		zephir_array_fetch_string(&_23$$8, setting, SL("memcached_options"), PH_NOISY | PH_READONLY, "brisk/Cache/Driver/Memcached.zep", 47 TSRMLS_CC);
		zephir_fast_array_merge(_22$$8, &(params), &(_23$$8) TSRMLS_CC);
		ZEPHIR_CPY_WRT(params, _22$$8);
	}
	zephir_is_iterable(params, &_25, &_24, 0, 0, "brisk/Cache/Driver/Memcached.zep", 53);
	for (
	  ; zend_hash_get_current_data_ex(_25, (void**) &_26, &_24) == SUCCESS
	  ; zend_hash_move_forward_ex(_25, &_24)
	) {
		ZEPHIR_GET_HMKEY(key, _25, _24);
		ZEPHIR_GET_HVALUE(val, _26);
		_27$$9 = zephir_fetch_nproperty_this(this_ptr, SL("_container"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(NULL, _27$$9, "setoption", NULL, 0, key, val);
		zephir_check_call_status();
	}
	is_valid = 0;
	_28 = zephir_fetch_nproperty_this(this_ptr, SL("_container"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&stats, _28, "getstats", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_29);
	zephir_is_iterable(stats, &_31, &_30, 0, 0, "brisk/Cache/Driver/Memcached.zep", 62);
	for (
	  ; zend_hash_get_current_data_ex(_31, (void**) &_32, &_30) == SUCCESS
	  ; zend_hash_move_forward_ex(_31, &_30)
	) {
		ZEPHIR_GET_HMKEY(_29, _31, _30);
		ZEPHIR_GET_HVALUE(item, _32);
		zephir_array_fetch_string(&_33$$10, item, SL("pid"), PH_NOISY | PH_READONLY, "brisk/Cache/Driver/Memcached.zep", 57 TSRMLS_CC);
		if (ZEPHIR_GT_LONG(_33$$10, 0)) {
			is_valid = 1;
			break;
		}
	}
	if (!is_valid) {
		ZEPHIR_INIT_VAR(_34$$12);
		object_init_ex(_34$$12, brisk_exception_runtimeexception_ce);
		ZEPHIR_INIT_VAR(_36$$12);
		zephir_create_array(_36$$12, 1, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_37$$12);
		ZVAL_STRING(_37$$12, "Memcached", 1);
		zephir_array_fast_append(_36$$12, _37$$12);
		ZEPHIR_INIT_NVAR(_37$$12);
		ZVAL_STRING(_37$$12, "cache.cacher_create_failed", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_CE_STATIC(&_35$$12, brisk_kernel_language_ce, "get", &_4, 12, _37$$12, _36$$12);
		zephir_check_temp_parameter(_37$$12);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, _34$$12, "__construct", NULL, 7, _35$$12);
		zephir_check_call_status();
		zephir_throw_exception_debug(_34$$12, "brisk/Cache/Driver/Memcached.zep", 63 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_PARENT(NULL, brisk_cache_driver_memcached_ce, getThis(), "__construct", &_38, 30, setting);
	zephir_check_call_status();
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
PHP_METHOD(Brisk_Cache_Driver_Memcached, set) {

	zend_long expire, ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *value, *expire_param = NULL, *path = NULL, *expire_time = NULL, *_0, *_1, *_2 = NULL;
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
		expire = 0;
	} else {
	if (UNEXPECTED(Z_TYPE_P(expire_param) != IS_LONG)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'expire' must be a int") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	expire = Z_LVAL_P(expire_param);
	}


	ZEPHIR_CALL_METHOD(&path, this_ptr, "getcachepath", NULL, 0, name);
	zephir_check_call_status();
	if (expire <= 0) {
		ZEPHIR_OBS_VAR(expire_time);
		zephir_read_property_this(&expire_time, this_ptr, SL("_expire_time"), PH_NOISY_CC);
	} else {
		ZEPHIR_INIT_NVAR(expire_time);
		ZVAL_LONG(expire_time, expire);
	}
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_container"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _0, "set", NULL, 0, path, value, expire_time);
	zephir_check_call_status();
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_container"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_2, _1, "getresultcode", NULL, 0);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_LONG(_2, 0));

}

/**
 * Get Cache data
 *
 * @param string name
 * @return mixed
 */
PHP_METHOD(Brisk_Cache_Driver_Memcached, get) {

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
PHP_METHOD(Brisk_Cache_Driver_Memcached, delete) {

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

PHP_METHOD(Brisk_Cache_Driver_Memcached, __set) {

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

PHP_METHOD(Brisk_Cache_Driver_Memcached, __get) {

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
PHP_METHOD(Brisk_Cache_Driver_Memcached, getCachePath) {

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


	ZEPHIR_INIT_VAR(path);
	ZVAL_STRING(path, "", 1);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_flag"), PH_NOISY_CC);
	if (!(Z_TYPE_P(_0) == IS_NULL)) {
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
		ZEPHIR_CALL_CE_STATIC(&_9$$5, brisk_kernel_language_ce, "get", &_10, 12, _11$$5);
		zephir_check_temp_parameter(_11$$5);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, _8$$5, "__construct", NULL, 7, _9$$5);
		zephir_check_call_status();
		zephir_throw_exception_debug(_8$$5, "brisk/Cache/Driver/Memcached.zep", 154 TSRMLS_CC);
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
PHP_METHOD(Brisk_Cache_Driver_Memcached, getInstance) {

	

	RETURN_MEMBER(getThis(), "_container");

}

PHP_METHOD(Brisk_Cache_Driver_Memcached, _formatPath) {

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



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
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "kernel/array.h"
#include "kernel/object.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/concat.h"
#include "kernel/string.h"


ZEPHIR_INIT_CLASS(Brisk_Cache_MemCache) {

	ZEPHIR_REGISTER_CLASS_EX(Brisk\\Cache, MemCache, brisk, cache_memcache, brisk_cache_cachefather_ce, brisk_cache_memcache_method_entry, 0);

	zend_declare_property_null(brisk_cache_memcache_ce, SL("_container"), ZEND_ACC_PRIVATE TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Brisk_Cache_MemCache, __construct) {

	zend_bool _13$$6;
	zend_string *_10, *_21;
	zend_ulong _9, _20;
	zephir_fcall_cache_entry *_4 = NULL, *_11 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval option, _5$$3, _26$$9;
	zval *save_path_param = NULL, *option_param = NULL, __$true, _0, _1, list_savepath, v, url, _7, *_8, params, _18, key, val, *_19, version, _23, _2$$3, _3$$3, _6$$3, _12$$6, _14$$6, _15$$7, _16$$7, _17$$7, _22$$8, _24$$9, _25$$9, _27$$9;
	zval save_path;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&save_path);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&list_savepath);
	ZVAL_UNDEF(&v);
	ZVAL_UNDEF(&url);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&_18);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&val);
	ZVAL_UNDEF(&version);
	ZVAL_UNDEF(&_23);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_12$$6);
	ZVAL_UNDEF(&_14$$6);
	ZVAL_UNDEF(&_15$$7);
	ZVAL_UNDEF(&_16$$7);
	ZVAL_UNDEF(&_17$$7);
	ZVAL_UNDEF(&_22$$8);
	ZVAL_UNDEF(&_24$$9);
	ZVAL_UNDEF(&_25$$9);
	ZVAL_UNDEF(&_27$$9);
	ZVAL_UNDEF(&option);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_26$$9);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &save_path_param, &option_param);

	if (UNEXPECTED(Z_TYPE_P(save_path_param) != IS_STRING && Z_TYPE_P(save_path_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'save_path' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(save_path_param) == IS_STRING)) {
		zephir_get_strval(&save_path, save_path_param);
	} else {
		ZEPHIR_INIT_VAR(&save_path);
		ZVAL_EMPTY_STRING(&save_path);
	}
	if (!option_param) {
		ZEPHIR_INIT_VAR(&option);
		array_init(&option);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&option, option_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "memcached");
	ZEPHIR_CALL_FUNCTION(&_1, "extension_loaded", NULL, 19, &_0);
	zephir_check_call_status();
	if (!zephir_is_true(&_1)) {
		ZEPHIR_INIT_VAR(&_2$$3);
		object_init_ex(&_2$$3, brisk_exception_cacheexception_ce);
		ZEPHIR_INIT_VAR(&_5$$3);
		zephir_create_array(&_5$$3, 1, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_6$$3);
		ZVAL_STRING(&_6$$3, "php_memcached");
		zephir_array_fast_append(&_5$$3, &_6$$3);
		ZEPHIR_INIT_NVAR(&_6$$3);
		ZVAL_STRING(&_6$$3, "cache.extension_load_failed");
		ZEPHIR_CALL_CE_STATIC(&_3$$3, brisk_kernel_language_ce, "get", &_4, 0, &_6$$3, &_5$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_2$$3, "__construct", NULL, 3, &_3$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_2$$3, "brisk/Cache/MemCache.zep", 14 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (!(Z_TYPE_P(&save_path) == IS_ARRAY)) {
		ZEPHIR_INIT_VAR(&list_savepath);
		zephir_create_array(&list_savepath, 1, 0 TSRMLS_CC);
		zephir_array_fast_append(&list_savepath, &save_path);
	} else {
		ZEPHIR_CPY_WRT(&list_savepath, &save_path);
	}
	ZEPHIR_INIT_NVAR(&_0);
	object_init_ex(&_0, zephir_get_internal_ce(SL("memcached")));
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("_container"), &_0);
	ZEPHIR_INIT_VAR(&_7);
	zephir_is_iterable(&list_savepath, 0, "brisk/Cache/MemCache.zep", 30);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&list_savepath), _9, _10, _8)
	{
		ZEPHIR_INIT_NVAR(&_7);
		if (_10 != NULL) { 
			ZVAL_STR_COPY(&_7, _10);
		} else {
			ZVAL_LONG(&_7, _9);
		}
		ZEPHIR_INIT_NVAR(&v);
		ZVAL_COPY(&v, _8);
		ZEPHIR_CALL_FUNCTION(&url, "parse_url", &_11, 20, &v);
		zephir_check_call_status();
		zephir_array_fetch_string(&_12$$6, &url, SL("host"), PH_NOISY | PH_READONLY, "brisk/Cache/MemCache.zep", 26 TSRMLS_CC);
		_13$$6 = !ZEPHIR_IS_STRING(&_12$$6, "");
		if (_13$$6) {
			zephir_array_fetch_string(&_14$$6, &url, SL("port"), PH_NOISY | PH_READONLY, "brisk/Cache/MemCache.zep", 26 TSRMLS_CC);
			_13$$6 = !ZEPHIR_IS_STRING(&_14$$6, "");
		}
		if (_13$$6) {
			zephir_read_property(&_15$$7, this_ptr, SL("_container"), PH_NOISY_CC | PH_READONLY);
			zephir_array_fetch_string(&_16$$7, &url, SL("host"), PH_NOISY | PH_READONLY, "brisk/Cache/MemCache.zep", 27 TSRMLS_CC);
			zephir_array_fetch_string(&_17$$7, &url, SL("port"), PH_NOISY | PH_READONLY, "brisk/Cache/MemCache.zep", 27 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(NULL, &_15$$7, "addserver", NULL, 0, &_16$$7, &_17$$7);
			zephir_check_call_status();
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&v);
	ZEPHIR_INIT_NVAR(&_7);
	ZEPHIR_INIT_VAR(&params);
	zephir_create_array(&params, 5, 0 TSRMLS_CC);
	add_index_long(&params, 9, 1);
	zephir_array_update_long(&params, 16, &__$true, PH_COPY ZEPHIR_DEBUG_PARAMS_DUMMY);
	add_index_long(&params, 14, 500);
	zephir_array_update_long(&params, -1001, &__$true, PH_COPY ZEPHIR_DEBUG_PARAMS_DUMMY);
	zephir_array_update_long(&params, 35, &__$true, PH_COPY ZEPHIR_DEBUG_PARAMS_DUMMY);
	ZEPHIR_INIT_VAR(&_18);
	zephir_fast_array_merge(&_18, &params, &option TSRMLS_CC);
	ZEPHIR_CPY_WRT(&params, &_18);
	zephir_is_iterable(&params, 0, "brisk/Cache/MemCache.zep", 43);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&params), _20, _21, _19)
	{
		ZEPHIR_INIT_NVAR(&key);
		if (_21 != NULL) { 
			ZVAL_STR_COPY(&key, _21);
		} else {
			ZVAL_LONG(&key, _20);
		}
		ZEPHIR_INIT_NVAR(&val);
		ZVAL_COPY(&val, _19);
		zephir_read_property(&_22$$8, this_ptr, SL("_container"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, &_22$$8, "setoption", NULL, 0, &key, &val);
		zephir_check_call_status();
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&val);
	ZEPHIR_INIT_NVAR(&key);
	zephir_read_property(&_23, this_ptr, SL("_container"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&version, &_23, "getversion", NULL, 0);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(&version)) {
		ZEPHIR_INIT_VAR(&_24$$9);
		object_init_ex(&_24$$9, brisk_exception_cacheexception_ce);
		ZEPHIR_INIT_VAR(&_26$$9);
		zephir_create_array(&_26$$9, 1, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_27$$9);
		ZVAL_STRING(&_27$$9, "Memcached");
		zephir_array_fast_append(&_26$$9, &_27$$9);
		ZEPHIR_INIT_NVAR(&_27$$9);
		ZVAL_STRING(&_27$$9, "cache.cacher_create_failed");
		ZEPHIR_CALL_CE_STATIC(&_25$$9, brisk_kernel_language_ce, "get", &_4, 0, &_27$$9, &_26$$9);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_24$$9, "__construct", NULL, 3, &_25$$9);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_24$$9, "brisk/Cache/MemCache.zep", 46 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Brisk_Cache_MemCache, set) {

	zend_long expire, ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *value, value_sub, *expire_param = NULL, path, _0, _1, _2;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&path);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &name_param, &value, &expire_param);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_EMPTY_STRING(&name);
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


	ZEPHIR_CALL_METHOD(&path, this_ptr, "getcachepath", NULL, 0, &name);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, SL("_container"), PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_1, expire);
	ZEPHIR_CALL_METHOD(NULL, &_0, "set", NULL, 0, &path, value, &_1);
	zephir_check_call_status();
	zephir_read_property(&_1, this_ptr, SL("_container"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_2, &_1, "getresultcode", NULL, 0);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_LONG(&_2, 0));

}

PHP_METHOD(Brisk_Cache_MemCache, get) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, data, path, _0, _1$$3, code$$3, _2$$3;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&path);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&code$$3);
	ZVAL_UNDEF(&_2$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_EMPTY_STRING(&name);
	}


	ZEPHIR_CALL_METHOD(&path, this_ptr, "getcachepath", NULL, 0, &name);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, SL("_caching"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_0)) {
		zephir_read_property(&_1$$3, this_ptr, SL("_container"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&data, &_1$$3, "get", NULL, 0, &path);
		zephir_check_call_status();
		zephir_read_property(&_2$$3, this_ptr, SL("_container"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&code$$3, &_2$$3, "getresultcode", NULL, 0);
		zephir_check_call_status();
		if (!ZEPHIR_IS_LONG(&code$$3, 0)) {
			ZEPHIR_INIT_NVAR(&data);
			ZVAL_NULL(&data);
		}
	}
	RETURN_CCTOR(&data);

}

PHP_METHOD(Brisk_Cache_MemCache, delete) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, path, code, _0, _1;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&path);
	ZVAL_UNDEF(&code);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_EMPTY_STRING(&name);
	}


	ZEPHIR_CALL_METHOD(&path, this_ptr, "getcachepath", NULL, 0, &name);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, SL("_container"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_0, "delete", NULL, 0, &path);
	zephir_check_call_status();
	zephir_read_property(&_1, this_ptr, SL("_container"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&code, &_1, "getresultcode", NULL, 0);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_LONG(&code, 0));

}

PHP_METHOD(Brisk_Cache_MemCache, __set) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *value, value_sub;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&value_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name_param, &value);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_EMPTY_STRING(&name);
	}


	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "set", NULL, 0, &name, value);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Brisk_Cache_MemCache, __get) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_EMPTY_STRING(&name);
	}


	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "get", NULL, 0, &name);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Brisk_Cache_MemCache, getCachePath) {

	zval _7, _4$$4;
	zephir_fcall_cache_entry *_10 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, path, _0, _3, part, result, _6, _1$$3, _2$$3, _5$$4, _8$$5, _9$$5, _11$$5;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&path);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&part);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_4$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_EMPTY_STRING(&name);
	}


	zephir_read_property(&_0, this_ptr, SL("_flag"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_0)) {
		zephir_read_property(&_1$$3, this_ptr, SL("_flag"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZEPHIR_CONCAT_VVS(&_2$$3, &path, &_1$$3, "_");
		ZEPHIR_CPY_WRT(&path, &_2$$3);
	}
	zephir_read_property(&_3, this_ptr, SL("_format"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_is_callable(&_3 TSRMLS_CC))) {
		ZEPHIR_INIT_VAR(&_4$$4);
		zephir_create_array(&_4$$4, 2, 0 TSRMLS_CC);
		zephir_array_fast_append(&_4$$4, this_ptr);
		ZEPHIR_INIT_VAR(&_5$$4);
		ZVAL_STRING(&_5$$4, "_formatPath");
		zephir_array_fast_append(&_4$$4, &_5$$4);
		zephir_update_property_zval(this_ptr, SL("_format"), &_4$$4);
	}
	zephir_read_property(&_6, this_ptr, SL("_format"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_7);
	zephir_create_array(&_7, 1, 0 TSRMLS_CC);
	zephir_array_fast_append(&_7, &name);
	ZEPHIR_INIT_VAR(&part);
	ZEPHIR_CALL_USER_FUNC_ARRAY(&part, &_6, &_7);
	zephir_check_call_status();
	if (Z_TYPE_P(&part) == IS_NULL) {
		ZEPHIR_INIT_VAR(&_8$$5);
		object_init_ex(&_8$$5, brisk_exception_cacheexception_ce);
		ZEPHIR_INIT_VAR(&_11$$5);
		ZVAL_STRING(&_11$$5, "cache.path_mustbe_notnull");
		ZEPHIR_CALL_CE_STATIC(&_9$$5, brisk_kernel_language_ce, "get", &_10, 0, &_11$$5);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_8$$5, "__construct", NULL, 3, &_9$$5);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_8$$5, "brisk/Cache/MemCache.zep", 104 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&result);
	ZEPHIR_CONCAT_VV(&result, &path, &part);
	RETURN_CCTOR(&result);

}

PHP_METHOD(Brisk_Cache_MemCache, getInstance) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_container");

}

PHP_METHOD(Brisk_Cache_MemCache, _formatPath) {

	zval *name_param = NULL;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_EMPTY_STRING(&name);
	}


	zephir_md5(return_value, &name);
	RETURN_MM();

}


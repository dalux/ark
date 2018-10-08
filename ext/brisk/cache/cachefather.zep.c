
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
#include "kernel/operators.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"


ZEPHIR_INIT_CLASS(Brisk_Cache_CacheFather) {

	ZEPHIR_REGISTER_CLASS(Brisk\\Cache, CacheFather, brisk, cache_cachefather, brisk_cache_cachefather_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_property_null(brisk_cache_cachefather_ce, SL("_flag"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(brisk_cache_cachefather_ce, SL("_format"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_bool(brisk_cache_cachefather_ce, SL("_caching"), 1, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_long(brisk_cache_cachefather_ce, SL("_expire_time"), 86400, ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Brisk_Cache_CacheFather, __construct) {

	HashTable *_1;
	HashPosition _0;
	zval *setting_param = NULL, *key = NULL, *val = NULL, **_2;
	zval *setting = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &setting_param);

	if (!setting_param) {
		ZEPHIR_INIT_VAR(setting);
		array_init(setting);
	} else {
	setting = setting_param;
	}


	zephir_is_iterable(setting, &_1, &_0, 0, 0, "brisk/Cache/CacheFather.zep", 33);
	for (
	  ; zend_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zend_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HMKEY(key, _1, _0);
		ZEPHIR_GET_HVALUE(val, _2);
		do {
			if (ZEPHIR_IS_STRING(key, "ext_name")) {
				zephir_update_property_this(getThis(), SL("_ext_name"), val TSRMLS_CC);
				break;
			}
			if (ZEPHIR_IS_STRING(key, "flag")) {
				zephir_update_property_this(getThis(), SL("_flag"), val TSRMLS_CC);
				break;
			}
			if (ZEPHIR_IS_STRING(key, "expire_time")) {
				zephir_update_property_this(getThis(), SL("_expire_time"), val TSRMLS_CC);
				break;
			}
			if (ZEPHIR_IS_STRING(key, "format")) {
				zephir_update_property_this(getThis(), SL("_format"), val TSRMLS_CC);
				break;
			}
		} while(0);

	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Set cache flag
 *
 * @param string flag
 * @return CacheFather
 */
PHP_METHOD(Brisk_Cache_CacheFather, setFlag) {

	zval *flag_param = NULL;
	zval *flag = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &flag_param);

	if (UNEXPECTED(Z_TYPE_P(flag_param) != IS_STRING && Z_TYPE_P(flag_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'flag' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(flag_param) == IS_STRING)) {
		zephir_get_strval(flag, flag_param);
	} else {
		ZEPHIR_INIT_VAR(flag);
		ZVAL_EMPTY_STRING(flag);
	}


	zephir_update_property_this(getThis(), SL("_flag"), flag TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Setting path formatting method
 *
 * @param callable format
 * @return CacheFather
 */
PHP_METHOD(Brisk_Cache_CacheFather, setFormat) {

	zval *format;

	zephir_fetch_params(0, 1, 0, &format);

	if (UNEXPECTED(zephir_is_callable(format TSRMLS_CC) != 1)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'format' must be a callable") TSRMLS_CC);
		RETURN_NULL();
	}


	zephir_update_property_this(getThis(), SL("_format"), format TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Setting whether data is cached
 *
 * @param bool caching
 * @return CacheFather
 */
PHP_METHOD(Brisk_Cache_CacheFather, setCaching) {

	zval *caching_param = NULL;
	zend_bool caching;

	zephir_fetch_params(0, 0, 1, &caching_param);

	if (!caching_param) {
		caching = 1;
	} else {
	if (UNEXPECTED(Z_TYPE_P(caching_param) != IS_BOOL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'caching' must be a bool") TSRMLS_CC);
		RETURN_NULL();
	}
	caching = Z_BVAL_P(caching_param);
	}


	if (caching) {
		zephir_update_property_this(getThis(), SL("_caching"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	} else {
		zephir_update_property_this(getThis(), SL("_caching"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	}
	RETURN_THISW();

}

/**
 * Set cache expire time
 *
 * @param int expire_time
 * @return CacheFather
 */
PHP_METHOD(Brisk_Cache_CacheFather, setExpireTime) {

	zval *expire_time_param = NULL, *_0;
	zend_long expire_time;

	zephir_fetch_params(0, 0, 1, &expire_time_param);

	if (!expire_time_param) {
		expire_time = 86400;
	} else {
	if (UNEXPECTED(Z_TYPE_P(expire_time_param) != IS_LONG)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'expire_time' must be a int") TSRMLS_CC);
		RETURN_NULL();
	}
	expire_time = Z_LVAL_P(expire_time_param);
	}


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, expire_time);
	zephir_update_property_this(getThis(), SL("_expire_time"), _0 TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Set Cache data
 *
 * @param string name
 * @param mixed value
 * @param int expire
 * @return bool
 */
PHP_METHOD(Brisk_Cache_CacheFather, set) {

}

/**
 * Get Cache data
 *
 * @param string name
 * @return mixed
 */
PHP_METHOD(Brisk_Cache_CacheFather, get) {

}

/**
 * Delete Cache data
 *
 * @param string name
 * @return bool
 */
PHP_METHOD(Brisk_Cache_CacheFather, delete) {

}

/**
 * Get cache data save location
 *
 * @param string name
 * @return string
 */
PHP_METHOD(Brisk_Cache_CacheFather, getCachePath) {

}


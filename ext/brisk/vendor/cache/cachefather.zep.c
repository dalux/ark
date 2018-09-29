
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
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/memory.h"


ZEPHIR_INIT_CLASS(Brisk_Vendor_Cache_CacheFather) {

	ZEPHIR_REGISTER_CLASS(Brisk\\Vendor\\Cache, CacheFather, brisk, vendor_cache_cachefather, brisk_vendor_cache_cachefather_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_property_null(brisk_vendor_cache_cachefather_ce, SL("_flag"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(brisk_vendor_cache_cachefather_ce, SL("_format"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_bool(brisk_vendor_cache_cachefather_ce, SL("_caching"), 1, ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * Set cache flag
 *
 * @param string flag
 * @return CacheFather
 */
PHP_METHOD(Brisk_Vendor_Cache_CacheFather, setFlag) {

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
PHP_METHOD(Brisk_Vendor_Cache_CacheFather, setFormat) {

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
PHP_METHOD(Brisk_Vendor_Cache_CacheFather, setCaching) {

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
 * Set Cache data
 *
 * @param string name
 * @param mixed value
 * @param int expire
 * @return bool
 */
PHP_METHOD(Brisk_Vendor_Cache_CacheFather, set) {

}

/**
 * Get Cache data
 *
 * @param string name
 * @return mixed
 */
PHP_METHOD(Brisk_Vendor_Cache_CacheFather, get) {

}

/**
 * Delete Cache data
 *
 * @param string name
 * @return bool
 */
PHP_METHOD(Brisk_Vendor_Cache_CacheFather, delete) {

}

/**
 * Get cache data save location
 *
 * @param string name
 * @return string
 */
PHP_METHOD(Brisk_Vendor_Cache_CacheFather, getCachePath) {

}


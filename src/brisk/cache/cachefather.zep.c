
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


ZEPHIR_INIT_CLASS(Brisk_Cache_CacheFather) {

	ZEPHIR_REGISTER_CLASS(Brisk\\Cache, CacheFather, brisk, cache_cachefather, brisk_cache_cachefather_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_property_null(brisk_cache_cachefather_ce, SL("_flag"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(brisk_cache_cachefather_ce, SL("_format"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_bool(brisk_cache_cachefather_ce, SL("_caching"), 1, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(brisk_cache_cachefather_ce TSRMLS_CC, 1, brisk_contract_icache_ce);
	return SUCCESS;

}

PHP_METHOD(Brisk_Cache_CacheFather, setFlag) {

	zval *flag_param = NULL;
	zval flag;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&flag);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &flag_param);

	if (UNEXPECTED(Z_TYPE_P(flag_param) != IS_STRING && Z_TYPE_P(flag_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'flag' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(flag_param) == IS_STRING)) {
		zephir_get_strval(&flag, flag_param);
	} else {
		ZEPHIR_INIT_VAR(&flag);
		ZVAL_EMPTY_STRING(&flag);
	}


	zephir_update_property_zval(this_ptr, SL("_flag"), &flag);
	RETURN_THIS();

}

PHP_METHOD(Brisk_Cache_CacheFather, setFormat) {

	zval *format, format_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&format_sub);

	zephir_fetch_params(0, 1, 0, &format);

	if (UNEXPECTED(zephir_is_callable(format TSRMLS_CC) != 1)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'format' must be a callable") TSRMLS_CC);
		RETURN_NULL();
	}


	zephir_update_property_zval(this_ptr, SL("_format"), format);
	RETURN_THISW();

}

PHP_METHOD(Brisk_Cache_CacheFather, setCaching) {

	zval *caching_param = NULL, __$true, __$false;
	zend_bool caching;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);

	zephir_fetch_params(0, 0, 1, &caching_param);

	if (!caching_param) {
		caching = 1;
	} else {
	if (UNEXPECTED(Z_TYPE_P(caching_param) != IS_TRUE && Z_TYPE_P(caching_param) != IS_FALSE)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'caching' must be a bool") TSRMLS_CC);
		RETURN_NULL();
	}
	caching = (Z_TYPE_P(caching_param) == IS_TRUE);
	}


	if (caching) {
		zephir_update_property_zval(this_ptr, SL("_caching"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("_caching"), &__$false);
	}
	RETURN_THISW();

}

PHP_METHOD(Brisk_Cache_CacheFather, set) {

}

PHP_METHOD(Brisk_Cache_CacheFather, get) {

}

PHP_METHOD(Brisk_Cache_CacheFather, delete) {

}

PHP_METHOD(Brisk_Cache_CacheFather, getCachePath) {

}


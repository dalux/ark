
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
#include "kernel/array.h"
#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/string.h"
#include "kernel/concat.h"


ZEPHIR_INIT_CLASS(Brisk_Vendor_Cache_CacheProxy) {

	ZEPHIR_REGISTER_CLASS(Brisk\\Vendor\\Cache, CacheProxy, brisk, vendor_cache_cacheproxy, brisk_vendor_cache_cacheproxy_method_entry, 0);

	zend_declare_property_null(brisk_vendor_cache_cacheproxy_ce, SL("_cache"), ZEND_ACC_PRIVATE TSRMLS_CC);

	return SUCCESS;

}

/**
 * Set cache instance
 *
 * @param CacheFather cache
 * @return CacheProxy
 */
PHP_METHOD(Brisk_Vendor_Cache_CacheProxy, setCacheDriver) {

	zval *cache;

	zephir_fetch_params(0, 1, 0, &cache);



	zephir_update_property_this(getThis(), SL("_cache"), cache TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Execute cache proxy
 *
 * @param object target
 * @param string method
 * @param array args
 * @param int expire
 * @param string name
 * @return mixed
 */
PHP_METHOD(Brisk_Vendor_Cache_CacheProxy, doProxy) {

	zend_bool _8$$6;
	zephir_fcall_cache_entry *_3 = NULL;
	zend_long expire, ZEPHIR_LAST_CALL_STATUS;
	zval *args = NULL, *_0, *_7$$6;
	zval *method = NULL, *name = NULL;
	zval *target, *method_param = NULL, *args_param = NULL, *expire_param = NULL, *name_param = NULL, *key = NULL, *data = NULL, *_5, *_1$$3, *_2$$3 = NULL, *_4$$3, *_6$$5, *_9$$7, *_10$$7;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 2, &target, &method_param, &args_param, &expire_param, &name_param);

	if (UNEXPECTED(Z_TYPE_P(method_param) != IS_STRING && Z_TYPE_P(method_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'method' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(method_param) == IS_STRING)) {
		zephir_get_strval(method, method_param);
	} else {
		ZEPHIR_INIT_VAR(method);
		ZVAL_EMPTY_STRING(method);
	}
	args = args_param;
	if (!expire_param) {
		expire = 86400;
	} else {
	if (UNEXPECTED(Z_TYPE_P(expire_param) != IS_LONG)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'expire' must be a int") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	expire = Z_LVAL_P(expire_param);
	}
	if (!name_param) {
		ZEPHIR_INIT_VAR(name);
		ZVAL_STRING(name, "", 1);
	} else {
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
	}


	ZEPHIR_INIT_VAR(_0);
	zephir_create_array(_0, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(_0, target);
	zephir_array_fast_append(_0, method);
	if (!(zephir_is_callable(_0 TSRMLS_CC))) {
		ZEPHIR_INIT_VAR(_1$$3);
		object_init_ex(_1$$3, brisk_exception_runtimeexception_ce);
		ZEPHIR_INIT_VAR(_4$$3);
		ZVAL_STRING(_4$$3, "proxy.target_not_callable", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_CE_STATIC(&_2$$3, brisk_kernel_language_ce, "get", &_3, 26, _4$$3);
		zephir_check_temp_parameter(_4$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, _1$$3, "__construct", NULL, 27, _2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(_1$$3, "brisk/Vendor/Cache/CacheProxy.zep", 37 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CPY_WRT(key, name);
	if (ZEPHIR_IS_STRING(name, "")) {
		ZEPHIR_CALL_METHOD(&key, this_ptr, "_name", NULL, 93, target, method, args);
		zephir_check_call_status();
	}
	_5 = zephir_fetch_nproperty_this(this_ptr, SL("_cache"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&data, _5, "get", NULL, 0, key);
	zephir_check_call_status();
	if (expire < 1) {
		ZEPHIR_INIT_NVAR(data);
		ZVAL_NULL(data);
		_6$$5 = zephir_fetch_nproperty_this(this_ptr, SL("_cache"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(NULL, _6$$5, "delete", NULL, 0, key);
		zephir_check_call_status();
	}
	if (Z_TYPE_P(data) == IS_NULL) {
		ZEPHIR_INIT_VAR(_7$$6);
		zephir_create_array(_7$$6, 2, 0 TSRMLS_CC);
		zephir_array_fast_append(_7$$6, target);
		zephir_array_fast_append(_7$$6, method);
		ZEPHIR_INIT_NVAR(data);
		ZEPHIR_CALL_USER_FUNC_ARRAY(data, _7$$6, args);
		zephir_check_call_status();
		_8$$6 = !(Z_TYPE_P(data) == IS_NULL);
		if (_8$$6) {
			_8$$6 = expire > 0;
		}
		if (_8$$6) {
			_9$$7 = zephir_fetch_nproperty_this(this_ptr, SL("_cache"), PH_NOISY_CC);
			ZEPHIR_INIT_VAR(_10$$7);
			ZVAL_LONG(_10$$7, expire);
			ZEPHIR_CALL_METHOD(NULL, _9$$7, "set", NULL, 0, key, data, _10$$7);
			zephir_check_call_status();
		}
	}
	RETURN_CCTOR(data);

}

PHP_METHOD(Brisk_Vendor_Cache_CacheProxy, _name) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *args = NULL;
	zval *func = NULL;
	zval *target, *func_param = NULL, *args_param = NULL, *_0, *_1 = NULL, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &target, &func_param, &args_param);

	if (UNEXPECTED(Z_TYPE_P(func_param) != IS_STRING && Z_TYPE_P(func_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'func' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(func_param) == IS_STRING)) {
		zephir_get_strval(func, func_param);
	} else {
		ZEPHIR_INIT_VAR(func);
		ZVAL_EMPTY_STRING(func);
	}
	args = args_param;


	ZEPHIR_INIT_VAR(_0);
	zephir_get_class(_0, target, 0 TSRMLS_CC);
	ZEPHIR_CALL_FUNCTION(&_1, "serialize", NULL, 94, args);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_2);
	ZEPHIR_CONCAT_VSVSV(_2, _0, ".", func, ".", _1);
	zephir_md5(return_value, _2);
	RETURN_MM();

}


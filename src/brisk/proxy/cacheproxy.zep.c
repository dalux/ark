
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
#include "kernel/exception.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/operators.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/string.h"
#include "kernel/concat.h"


ZEPHIR_INIT_CLASS(Brisk_Proxy_CacheProxy) {

	ZEPHIR_REGISTER_CLASS(Brisk\\Proxy, CacheProxy, brisk, proxy_cacheproxy, brisk_proxy_cacheproxy_method_entry, 0);

	zend_declare_property_null(brisk_proxy_cacheproxy_ce, SL("_cacher"), ZEND_ACC_PRIVATE TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Brisk_Proxy_CacheProxy, setCacher) {

	zval _3$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_2 = NULL;
	zval *cacher, cacher_sub, _0$$3, _1$$3, _4$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&cacher_sub);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_3$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &cacher);



	if (!((zephir_instance_of_ev(cacher, brisk_contract_icache_ce TSRMLS_CC)))) {
		ZEPHIR_INIT_VAR(&_0$$3);
		object_init_ex(&_0$$3, brisk_exception_proxyexception_ce);
		ZEPHIR_INIT_VAR(&_3$$3);
		zephir_create_array(&_3$$3, 1, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_4$$3);
		ZVAL_STRING(&_4$$3, "\\Brisk\\Contract\\ICache");
		zephir_array_fast_append(&_3$$3, &_4$$3);
		ZEPHIR_INIT_NVAR(&_4$$3);
		ZVAL_STRING(&_4$$3, "proxy.invalid_cacher_object");
		ZEPHIR_CALL_CE_STATIC(&_1$$3, brisk_kernel_language_ce, "get", &_2, 0, &_4$$3, &_3$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_0$$3, "__construct", NULL, 3, &_1$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_0$$3, "brisk/Proxy/CacheProxy.zep", 15 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_zval(this_ptr, SL("_cacher"), cacher);
	RETURN_THIS();

}

PHP_METHOD(Brisk_Proxy_CacheProxy, doProxy) {

	zend_bool _8$$6;
	zephir_fcall_cache_entry *_3 = NULL;
	zend_long expire, ZEPHIR_LAST_CALL_STATUS;
	zval args, _0, _7$$6;
	zval method, name;
	zval *adapter, adapter_sub, *method_param = NULL, *args_param = NULL, *expire_param = NULL, *name_param = NULL, key, data, _5, _1$$3, _2$$3, _4$$3, _6$$5, _9$$7, _10$$7;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&adapter_sub);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_9$$7);
	ZVAL_UNDEF(&_10$$7);
	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&args);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_7$$6);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 2, &adapter, &method_param, &args_param, &expire_param, &name_param);

	if (UNEXPECTED(Z_TYPE_P(method_param) != IS_STRING && Z_TYPE_P(method_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'method' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(method_param) == IS_STRING)) {
		zephir_get_strval(&method, method_param);
	} else {
		ZEPHIR_INIT_VAR(&method);
		ZVAL_EMPTY_STRING(&method);
	}
	ZEPHIR_OBS_COPY_OR_DUP(&args, args_param);
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
		ZEPHIR_INIT_VAR(&name);
		ZVAL_STRING(&name, "");
	} else {
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
	}


	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(&_0, adapter);
	zephir_array_fast_append(&_0, &method);
	if (!(zephir_is_callable(&_0 TSRMLS_CC))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, brisk_exception_proxyexception_ce);
		ZEPHIR_INIT_VAR(&_4$$3);
		ZVAL_STRING(&_4$$3, "proxy.target_not_callable");
		ZEPHIR_CALL_CE_STATIC(&_2$$3, brisk_kernel_language_ce, "get", &_3, 0, &_4$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 3, &_2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "brisk/Proxy/CacheProxy.zep", 24 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CPY_WRT(&key, &name);
	if (ZEPHIR_IS_STRING(&name, "")) {
		ZEPHIR_CALL_METHOD(&key, this_ptr, "name", NULL, 0, adapter, &method, &args);
		zephir_check_call_status();
	}
	zephir_read_property(&_5, this_ptr, SL("_cacher"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&data, &_5, "get", NULL, 0, &key);
	zephir_check_call_status();
	if (expire < 1) {
		ZEPHIR_INIT_NVAR(&data);
		ZVAL_NULL(&data);
		zephir_read_property(&_6$$5, this_ptr, SL("_cacher"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, &_6$$5, "delete", NULL, 0, &key);
		zephir_check_call_status();
	}
	if (Z_TYPE_P(&data) == IS_NULL) {
		ZEPHIR_INIT_VAR(&_7$$6);
		zephir_create_array(&_7$$6, 2, 0 TSRMLS_CC);
		zephir_array_fast_append(&_7$$6, adapter);
		zephir_array_fast_append(&_7$$6, &method);
		ZEPHIR_INIT_NVAR(&data);
		ZEPHIR_CALL_USER_FUNC_ARRAY(&data, &_7$$6, &args);
		zephir_check_call_status();
		_8$$6 = !(Z_TYPE_P(&data) == IS_NULL);
		if (_8$$6) {
			_8$$6 = expire > 0;
		}
		if (_8$$6) {
			zephir_read_property(&_9$$7, this_ptr, SL("_cacher"), PH_NOISY_CC | PH_READONLY);
			ZVAL_LONG(&_10$$7, expire);
			ZEPHIR_CALL_METHOD(NULL, &_9$$7, "set", NULL, 0, &key, &data, &_10$$7);
			zephir_check_call_status();
		}
	}
	RETURN_CCTOR(&data);

}

PHP_METHOD(Brisk_Proxy_CacheProxy, name) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval args;
	zval func;
	zval *adapter, adapter_sub, *func_param = NULL, *args_param = NULL, _0, _1, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&adapter_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&func);
	ZVAL_UNDEF(&args);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &adapter, &func_param, &args_param);

	if (UNEXPECTED(Z_TYPE_P(func_param) != IS_STRING && Z_TYPE_P(func_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'func' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(func_param) == IS_STRING)) {
		zephir_get_strval(&func, func_param);
	} else {
		ZEPHIR_INIT_VAR(&func);
		ZVAL_EMPTY_STRING(&func);
	}
	ZEPHIR_OBS_COPY_OR_DUP(&args, args_param);


	ZEPHIR_INIT_VAR(&_0);
	zephir_get_class(&_0, adapter, 0 TSRMLS_CC);
	ZEPHIR_CALL_FUNCTION(&_1, "serialize", NULL, 15, &args);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	ZEPHIR_CONCAT_VSVSV(&_2, &_0, ".", &func, ".", &_1);
	zephir_md5(return_value, &_2);
	RETURN_MM();

}


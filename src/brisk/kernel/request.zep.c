
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
#include "kernel/array.h"
#include "kernel/object.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/string.h"


ZEPHIR_INIT_CLASS(Brisk_Kernel_Request) {

	ZEPHIR_REGISTER_CLASS(Brisk\\Kernel, Request, brisk, kernel_request, brisk_kernel_request_method_entry, 0);

	zend_declare_property_null(brisk_kernel_request_ce, SL("_instance"), ZEND_ACC_PRIVATE|ZEND_ACC_STATIC TSRMLS_CC);

	zend_declare_property_bool(brisk_kernel_request_ce, SL("_ready"), 0, ZEND_ACC_PRIVATE|ZEND_ACC_STATIC TSRMLS_CC);

	zend_declare_property_null(brisk_kernel_request_ce, SL("_data"), ZEND_ACC_PRIVATE|ZEND_ACC_STATIC TSRMLS_CC);

	zend_declare_property_null(brisk_kernel_request_ce, SL("_request"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(brisk_kernel_request_ce, SL("_get"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(brisk_kernel_request_ce, SL("_post"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(brisk_kernel_request_ce, SL("_files"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(brisk_kernel_request_ce, SL("_cookie"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(brisk_kernel_request_ce, SL("_flag"), ZEND_ACC_PRIVATE TSRMLS_CC);

	brisk_kernel_request_ce->create_object = zephir_init_properties_Brisk_Kernel_Request;
	return SUCCESS;

}

PHP_METHOD(Brisk_Kernel_Request, setData) {

	zval *data_param = NULL, _0, _1;
	zval data;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data_param);

	ZEPHIR_OBS_COPY_OR_DUP(&data, data_param);


	ZEPHIR_INIT_VAR(&_0);
	zephir_read_static_property_ce(&_1, brisk_kernel_request_ce, SL("_data"), PH_NOISY_CC | PH_READONLY);
	zephir_fast_array_merge(&_0, &_1, &data TSRMLS_CC);
	zend_update_static_property(brisk_kernel_request_ce, ZEND_STRL("_data"), &_0);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Brisk_Kernel_Request, setReady) {

	zval *state_param = NULL, _0;
	zend_bool state;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	zephir_fetch_params(0, 1, 0, &state_param);

	if (UNEXPECTED(Z_TYPE_P(state_param) != IS_TRUE && Z_TYPE_P(state_param) != IS_FALSE)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'state' must be a bool") TSRMLS_CC);
		RETURN_NULL();
	}
	state = (Z_TYPE_P(state_param) == IS_TRUE);


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_BOOL(&_0, state);
	zend_update_static_property(brisk_kernel_request_ce, ZEND_STRL("_ready"), &_0);

}

PHP_METHOD(Brisk_Kernel_Request, getInstance) {

	zval _0, _1, _7, _2$$3, _3$$3, _5$$3, _6$$4;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_4 = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$4);

	ZEPHIR_MM_GROW();

	zephir_read_static_property_ce(&_0, brisk_kernel_request_ce, SL("_ready"), PH_NOISY_CC | PH_READONLY);
	zephir_read_static_property_ce(&_1, brisk_kernel_request_ce, SL("_instance"), PH_NOISY_CC | PH_READONLY);
	if (!zephir_is_true(&_0)) {
		ZEPHIR_INIT_VAR(&_2$$3);
		object_init_ex(&_2$$3, brisk_exception_kernelexception_ce);
		ZEPHIR_INIT_VAR(&_5$$3);
		ZVAL_STRING(&_5$$3, "http.request_not_ready");
		ZEPHIR_CALL_CE_STATIC(&_3$$3, brisk_kernel_language_ce, "get", &_4, 0, &_5$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_2$$3, "__construct", NULL, 3, &_3$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_2$$3, "brisk/Kernel/Request.zep", 32 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	} else if (Z_TYPE_P(&_1) == IS_NULL) {
		ZEPHIR_INIT_VAR(&_6$$4);
		object_init_ex(&_6$$4, brisk_kernel_request_ce);
		ZEPHIR_CALL_METHOD(NULL, &_6$$4, "__construct", NULL, 46);
		zephir_check_call_status();
		zend_update_static_property(brisk_kernel_request_ce, ZEND_STRL("_instance"), &_6$$4);
	}
	zephir_read_static_property_ce(&_7, brisk_kernel_request_ce, SL("_instance"), PH_NOISY_CC | PH_READONLY);
	RETURN_CTOR(&_7);

}

PHP_METHOD(Brisk_Kernel_Request, __construct) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_2 = NULL;
	zval *_POST, *_COOKIE, *_FILES, data, _0, _1, _3, _4, _5, _6, _7, _8;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_FILES, SL("_FILES"));
	zephir_get_global(&_COOKIE, SL("_COOKIE"));
	zephir_get_global(&_POST, SL("_POST"));

	ZEPHIR_INIT_VAR(&data);
	zephir_create_array(&data, 4, 0 TSRMLS_CC);
	ZEPHIR_OBS_VAR(&_0);
	zephir_read_static_property_ce(&_0, brisk_kernel_request_ce, SL("_data"), PH_NOISY_CC);
	zephir_array_update_string(&data, SL("get"), &_0, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&data, SL("post"), _POST, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&data, SL("cookie"), _COOKIE, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&data, SL("files"), _FILES, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "event.request.ready");
	ZEPHIR_CALL_CE_STATIC(&_1, brisk_kernel_event_ce, "onlistening", &_2, 0, &_3, &data);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&data, &_1);
	zephir_array_fetch_string(&_4, &data, SL("get"), PH_NOISY | PH_READONLY, "brisk/Kernel/Request.zep", 44 TSRMLS_CC);
	zephir_update_property_zval(this_ptr, SL("_get"), &_4);
	zephir_array_fetch_string(&_5, &data, SL("post"), PH_NOISY | PH_READONLY, "brisk/Kernel/Request.zep", 45 TSRMLS_CC);
	zephir_update_property_zval(this_ptr, SL("_post"), &_5);
	zephir_array_fetch_string(&_6, &data, SL("cookie"), PH_NOISY | PH_READONLY, "brisk/Kernel/Request.zep", 46 TSRMLS_CC);
	zephir_update_property_zval(this_ptr, SL("_cookie"), &_6);
	zephir_array_fetch_string(&_7, &data, SL("files"), PH_NOISY | PH_READONLY, "brisk/Kernel/Request.zep", 47 TSRMLS_CC);
	zephir_update_property_zval(this_ptr, SL("_files"), &_7);
	ZEPHIR_INIT_NVAR(&_3);
	zephir_read_property(&_0, this_ptr, SL("_get"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_8, this_ptr, SL("_post"), PH_NOISY_CC | PH_READONLY);
	zephir_fast_array_merge(&_3, &_0, &_8 TSRMLS_CC);
	zephir_update_property_zval(this_ptr, SL("_request"), &_3);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Brisk_Kernel_Request, isPost) {

	zval *_SERVER, _0, _1, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SERVER, SL("_SERVER"));

	ZEPHIR_INIT_VAR(&_0);
	zephir_array_fetch_string(&_1, _SERVER, SL("REQUEST_METHOD"), PH_NOISY | PH_READONLY, "brisk/Kernel/Request.zep", 53 TSRMLS_CC);
	zephir_fast_strtoupper(&_0, &_1);
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_STRING(&_2, "POST");
	RETURN_MM_BOOL(ZEPHIR_IS_EQUAL(&_2, &_0));

}

PHP_METHOD(Brisk_Kernel_Request, isAjax) {

	zval *_SERVER, _0$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0$$3);

	zephir_get_global(&_SERVER, SL("_SERVER"));

	if (zephir_array_isset_string(_SERVER, SL("HTTP_X_REQUESTED_WITH"))) {
		zephir_array_fetch_string(&_0$$3, _SERVER, SL("HTTP_X_REQUESTED_WITH"), PH_NOISY | PH_READONLY, "brisk/Kernel/Request.zep", 59 TSRMLS_CC);
		RETURN_BOOL(ZEPHIR_IS_STRING(&_0$$3, "XMLHttpRequest"));
	}
	RETURN_BOOL(0);

}

PHP_METHOD(Brisk_Kernel_Request, getIpAddress) {

	zephir_fcall_cache_entry *_8 = NULL, *_10 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *convert_param = NULL, *_SERVER, ip, ips, _7, _11, _12, _0$$3, forwarded$$4, _1$$4, *_2$$4, _3$$6, _4$$7, _5$$8, _6$$9, _9$$10;
	zend_bool convert;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&ip);
	ZVAL_UNDEF(&ips);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&forwarded$$4);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_3$$6);
	ZVAL_UNDEF(&_4$$7);
	ZVAL_UNDEF(&_5$$8);
	ZVAL_UNDEF(&_6$$9);
	ZVAL_UNDEF(&_9$$10);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SERVER, SL("_SERVER"));
	zephir_fetch_params(1, 0, 1, &convert_param);

	if (!convert_param) {
		convert = 0;
	} else {
	if (UNEXPECTED(Z_TYPE_P(convert_param) != IS_TRUE && Z_TYPE_P(convert_param) != IS_FALSE)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'convert' must be a bool") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	convert = (Z_TYPE_P(convert_param) == IS_TRUE);
	}


	ZEPHIR_INIT_VAR(&ips);
	array_init(&ips);
	if (zephir_array_isset_string(_SERVER, SL("HTTP_CLIENT_IP"))) {
		zephir_array_fetch_string(&_0$$3, _SERVER, SL("HTTP_CLIENT_IP"), PH_NOISY | PH_READONLY, "brisk/Kernel/Request.zep", 69 TSRMLS_CC);
		zephir_array_append(&ips, &_0$$3, PH_SEPARATE, "brisk/Kernel/Request.zep", 69);
	}
	if (zephir_array_isset_string(_SERVER, SL("HTTP_X_FORWARDED_FOR"))) {
		zephir_array_fetch_string(&_1$$4, _SERVER, SL("HTTP_X_FORWARDED_FOR"), PH_NOISY | PH_READONLY, "brisk/Kernel/Request.zep", 73 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&forwarded$$4);
		zephir_fast_explode_str(&forwarded$$4, SL(","), &_1$$4, LONG_MAX TSRMLS_CC);
		zephir_is_iterable(&forwarded$$4, 0, "brisk/Kernel/Request.zep", 77);
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&forwarded$$4), _2$$4)
		{
			ZEPHIR_INIT_NVAR(&ip);
			ZVAL_COPY(&ip, _2$$4);
			zephir_array_append(&ips, &ip, PH_SEPARATE, "brisk/Kernel/Request.zep", 75);
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&ip);
	}
	if (zephir_array_isset_string(_SERVER, SL("HTTP_X_FORWARDED"))) {
		zephir_array_fetch_string(&_3$$6, _SERVER, SL("HTTP_X_FORWARDED"), PH_NOISY | PH_READONLY, "brisk/Kernel/Request.zep", 79 TSRMLS_CC);
		zephir_array_append(&ips, &_3$$6, PH_SEPARATE, "brisk/Kernel/Request.zep", 79);
	}
	if (zephir_array_isset_string(_SERVER, SL("HTTP_FORWARDED_FOR"))) {
		zephir_array_fetch_string(&_4$$7, _SERVER, SL("HTTP_FORWARDED_FOR"), PH_NOISY | PH_READONLY, "brisk/Kernel/Request.zep", 82 TSRMLS_CC);
		zephir_array_append(&ips, &_4$$7, PH_SEPARATE, "brisk/Kernel/Request.zep", 82);
	}
	if (zephir_array_isset_string(_SERVER, SL("HTTP_FORWARDED"))) {
		zephir_array_fetch_string(&_5$$8, _SERVER, SL("HTTP_FORWARDED"), PH_NOISY | PH_READONLY, "brisk/Kernel/Request.zep", 85 TSRMLS_CC);
		zephir_array_append(&ips, &_5$$8, PH_SEPARATE, "brisk/Kernel/Request.zep", 85);
	}
	if (zephir_array_isset_string(_SERVER, SL("REMOTE_ADDR"))) {
		zephir_array_fetch_string(&_6$$9, _SERVER, SL("REMOTE_ADDR"), PH_NOISY | PH_READONLY, "brisk/Kernel/Request.zep", 88 TSRMLS_CC);
		zephir_array_append(&ips, &_6$$9, PH_SEPARATE, "brisk/Kernel/Request.zep", 88);
	}
	ZEPHIR_CALL_FUNCTION(&_7, "array_filter", NULL, 47, &ips);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&ips, &_7);
	while (1) {
		if (!(1)) {
			break;
		}
		ZEPHIR_MAKE_REF(&ips);
		ZEPHIR_CALL_FUNCTION(&ip, "array_shift", &_8, 7, &ips);
		ZEPHIR_UNREF(&ips);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&_9$$10, "ip2long", &_10, 48, &ip);
		zephir_check_call_status();
		if (!ZEPHIR_IS_FALSE_IDENTICAL(&_9$$10)) {
			break;
		}
	}
	ZEPHIR_INIT_VAR(&_11);
	if (convert) {
		ZEPHIR_CALL_FUNCTION(&_7, "ip2long", &_10, 48, &ip);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_12);
		ZVAL_STRING(&_12, "%u");
		ZEPHIR_CALL_FUNCTION(&_11, "sprintf", NULL, 4, &_12, &_7);
		zephir_check_call_status();
	} else {
		ZEPHIR_CPY_WRT(&_11, &ip);
	}
	RETURN_CCTOR(&_11);

}

PHP_METHOD(Brisk_Kernel_Request, add) {

	zval _6$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_5 = NULL;
	zval *name_param = NULL, *value, value_sub, __$null, _0, _1, _2, _3$$3, _4$$3, _7$$3;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&value_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_6$$3);

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


	zephir_read_property(&_0, this_ptr, SL("_flag"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_1, this_ptr, SL("_flag"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_2, this_ptr, SL("_flag"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_0) == IS_NULL) {
		ZEPHIR_INIT_VAR(&_3$$3);
		object_init_ex(&_3$$3, brisk_exception_kernelexception_ce);
		ZEPHIR_INIT_VAR(&_6$$3);
		zephir_create_array(&_6$$3, 1, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_7$$3);
		ZVAL_STRING(&_7$$3, "Request:add");
		zephir_array_fast_append(&_6$$3, &_7$$3);
		ZEPHIR_INIT_NVAR(&_7$$3);
		ZVAL_STRING(&_7$$3, "http.method_not_found");
		ZEPHIR_CALL_CE_STATIC(&_4$$3, brisk_kernel_language_ce, "get", &_5, 0, &_7$$3, &_6$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_3$$3, "__construct", NULL, 3, &_4$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_3$$3, "brisk/Kernel/Request.zep", 103 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	} else if (ZEPHIR_IS_STRING(&_1, "get")) {
		zephir_update_property_array(this_ptr, SL("_get"), &name, value TSRMLS_CC);
	} else if (ZEPHIR_IS_STRING(&_2, "post")) {
		zephir_update_property_array(this_ptr, SL("_post"), &name, value TSRMLS_CC);
	}
	zephir_update_property_array(this_ptr, SL("_request"), &name, value TSRMLS_CC);
	zephir_update_property_zval(this_ptr, SL("_flag"), &__$null);
	RETURN_THIS();

}

PHP_METHOD(Brisk_Kernel_Request, del) {

	zval _6$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_5 = NULL;
	zval *name_param = NULL, __$null, _0, _1, _2, _3$$3, _4$$3, _7$$3, _8$$4, _9$$5;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_6$$3);

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
	zephir_read_property(&_1, this_ptr, SL("_flag"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_2, this_ptr, SL("_flag"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_0) == IS_NULL) {
		ZEPHIR_INIT_VAR(&_3$$3);
		object_init_ex(&_3$$3, brisk_exception_kernelexception_ce);
		ZEPHIR_INIT_VAR(&_6$$3);
		zephir_create_array(&_6$$3, 1, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_7$$3);
		ZVAL_STRING(&_7$$3, "Request:del");
		zephir_array_fast_append(&_6$$3, &_7$$3);
		ZEPHIR_INIT_NVAR(&_7$$3);
		ZVAL_STRING(&_7$$3, "http.method_not_found");
		ZEPHIR_CALL_CE_STATIC(&_4$$3, brisk_kernel_language_ce, "get", &_5, 0, &_7$$3, &_6$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_3$$3, "__construct", NULL, 3, &_4$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_3$$3, "brisk/Kernel/Request.zep", 117 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	} else if (ZEPHIR_IS_STRING(&_1, "get")) {
		zephir_read_property(&_8$$4, this_ptr, SL("_get"), PH_NOISY_CC | PH_READONLY);
		zephir_array_unset(&_8$$4, &name, PH_SEPARATE);
	} else if (ZEPHIR_IS_STRING(&_2, "post")) {
		zephir_read_property(&_9$$5, this_ptr, SL("_post"), PH_NOISY_CC | PH_READONLY);
		zephir_array_unset(&_9$$5, &name, PH_SEPARATE);
	}
	zephir_update_property_zval(this_ptr, SL("_flag"), &__$null);
	RETURN_THIS();

}

PHP_METHOD(Brisk_Kernel_Request, data) {

	zval _4$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_3 = NULL;
	zval *name_param = NULL, *alternative_param = NULL, __$null, _0, value, _6, _7, _8, _9, _10, _1$$3, _2$$3, _5$$3, _11$$6, _12$$9, _13$$12, _14$$15, _15$$18;
	zval name, alternative;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&alternative);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_11$$6);
	ZVAL_UNDEF(&_12$$9);
	ZVAL_UNDEF(&_13$$12);
	ZVAL_UNDEF(&_14$$15);
	ZVAL_UNDEF(&_15$$18);
	ZVAL_UNDEF(&_4$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &name_param, &alternative_param);

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
	if (!alternative_param) {
		ZEPHIR_INIT_VAR(&alternative);
		ZVAL_STRING(&alternative, "");
	} else {
	if (UNEXPECTED(Z_TYPE_P(alternative_param) != IS_STRING && Z_TYPE_P(alternative_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'alternative' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(alternative_param) == IS_STRING)) {
		zephir_get_strval(&alternative, alternative_param);
	} else {
		ZEPHIR_INIT_VAR(&alternative);
		ZVAL_EMPTY_STRING(&alternative);
	}
	}


	zephir_read_property(&_0, this_ptr, SL("_flag"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_0) == IS_NULL) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, brisk_exception_kernelexception_ce);
		ZEPHIR_INIT_VAR(&_4$$3);
		zephir_create_array(&_4$$3, 1, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_5$$3);
		ZVAL_STRING(&_5$$3, "Request:data");
		zephir_array_fast_append(&_4$$3, &_5$$3);
		ZEPHIR_INIT_NVAR(&_5$$3);
		ZVAL_STRING(&_5$$3, "http.method_not_found");
		ZEPHIR_CALL_CE_STATIC(&_2$$3, brisk_kernel_language_ce, "get", &_3, 0, &_5$$3, &_4$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 3, &_2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "brisk/Kernel/Request.zep", 130 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_read_property(&_6, this_ptr, SL("_flag"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_7, this_ptr, SL("_flag"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_8, this_ptr, SL("_flag"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_9, this_ptr, SL("_flag"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_10, this_ptr, SL("_flag"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_IS_STRING(&_6, "get")) {
		if (ZEPHIR_IS_STRING(&name, "")) {
			ZEPHIR_OBS_VAR(&value);
			zephir_read_property(&value, this_ptr, SL("_get"), PH_NOISY_CC);
		} else {
			zephir_read_property(&_11$$6, this_ptr, SL("_get"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_OBS_NVAR(&value);
			zephir_array_fetch(&value, &_11$$6, &name, PH_NOISY, "brisk/Kernel/Request.zep", 137 TSRMLS_CC);
		}
	} else if (ZEPHIR_IS_STRING(&_7, "post")) {
		if (ZEPHIR_IS_STRING(&name, "")) {
			ZEPHIR_OBS_NVAR(&value);
			zephir_read_property(&value, this_ptr, SL("_post"), PH_NOISY_CC);
		} else {
			zephir_read_property(&_12$$9, this_ptr, SL("_post"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_OBS_NVAR(&value);
			zephir_array_fetch(&value, &_12$$9, &name, PH_NOISY, "brisk/Kernel/Request.zep", 143 TSRMLS_CC);
		}
	} else if (ZEPHIR_IS_STRING(&_8, "request")) {
		if (ZEPHIR_IS_STRING(&name, "")) {
			ZEPHIR_OBS_NVAR(&value);
			zephir_read_property(&value, this_ptr, SL("_request"), PH_NOISY_CC);
		} else {
			zephir_read_property(&_13$$12, this_ptr, SL("_request"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_OBS_NVAR(&value);
			zephir_array_fetch(&value, &_13$$12, &name, PH_NOISY, "brisk/Kernel/Request.zep", 149 TSRMLS_CC);
		}
	} else if (ZEPHIR_IS_STRING(&_9, "cookie")) {
		if (ZEPHIR_IS_STRING(&name, "")) {
			ZEPHIR_OBS_NVAR(&value);
			zephir_read_property(&value, this_ptr, SL("_cookie"), PH_NOISY_CC);
		} else {
			zephir_read_property(&_14$$15, this_ptr, SL("_cookie"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_OBS_NVAR(&value);
			zephir_array_fetch(&value, &_14$$15, &name, PH_NOISY, "brisk/Kernel/Request.zep", 155 TSRMLS_CC);
		}
	} else if (ZEPHIR_IS_STRING(&_10, "files")) {
		if (ZEPHIR_IS_STRING(&name, "")) {
			ZEPHIR_OBS_NVAR(&value);
			zephir_read_property(&value, this_ptr, SL("_files"), PH_NOISY_CC);
		} else {
			zephir_read_property(&_15$$18, this_ptr, SL("_files"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_OBS_NVAR(&value);
			zephir_array_fetch(&value, &_15$$18, &name, PH_NOISY, "brisk/Kernel/Request.zep", 161 TSRMLS_CC);
		}
	}
	zephir_update_property_zval(this_ptr, SL("_flag"), &__$null);
	if (Z_TYPE_P(&value) == IS_NULL) {
		RETURN_CTOR(&alternative);
	}
	RETURN_CCTOR(&value);

}

PHP_METHOD(Brisk_Kernel_Request, __get) {

	zval _0, _5$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_4 = NULL;
	zval *flag_param = NULL, _1, _2$$3, _3$$3, _6$$3;
	zval flag;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&flag);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_5$$3);

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


	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 5, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "get");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "post");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "files");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "cookie");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "request");
	zephir_array_fast_append(&_0, &_1);
	if (!(zephir_fast_in_array(&flag, &_0 TSRMLS_CC))) {
		ZEPHIR_INIT_VAR(&_2$$3);
		object_init_ex(&_2$$3, brisk_exception_kernelexception_ce);
		ZEPHIR_INIT_VAR(&_5$$3);
		zephir_create_array(&_5$$3, 1, 0 TSRMLS_CC);
		zephir_array_fast_append(&_5$$3, &flag);
		ZEPHIR_INIT_VAR(&_6$$3);
		ZVAL_STRING(&_6$$3, "http.property_not_found");
		ZEPHIR_CALL_CE_STATIC(&_3$$3, brisk_kernel_language_ce, "get", &_4, 0, &_6$$3, &_5$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_2$$3, "__construct", NULL, 3, &_3$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_2$$3, "brisk/Kernel/Request.zep", 174 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_zval(this_ptr, SL("_flag"), &flag);
	RETURN_THIS();

}

void zephir_init_static_properties_Brisk_Kernel_Request(TSRMLS_D) {

	zval _0;
		ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	array_init(&_0);
	zend_update_static_property(brisk_kernel_request_ce, ZEND_STRL("_data"), &_0);
	ZEPHIR_MM_RESTORE();

}

zend_object *zephir_init_properties_Brisk_Kernel_Request(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _2, _4, _6, _8, _1$$3, _3$$4, _5$$5, _7$$6, _9$$7;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_9$$7);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("_cookie"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval(this_ptr, SL("_cookie"), &_1$$3);
		}
		zephir_read_property(&_2, this_ptr, SL("_files"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval(this_ptr, SL("_files"), &_3$$4);
		}
		zephir_read_property(&_4, this_ptr, SL("_post"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_4) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_5$$5);
			array_init(&_5$$5);
			zephir_update_property_zval(this_ptr, SL("_post"), &_5$$5);
		}
		zephir_read_property(&_6, this_ptr, SL("_get"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_6) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_7$$6);
			array_init(&_7$$6);
			zephir_update_property_zval(this_ptr, SL("_get"), &_7$$6);
		}
		zephir_read_property(&_8, this_ptr, SL("_request"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_8) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_9$$7);
			array_init(&_9$$7);
			zephir_update_property_zval(this_ptr, SL("_request"), &_9$$7);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}



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

/**
 * Set Request data
 *
 * @param array data
 * @return null
 */
PHP_METHOD(Brisk_Kernel_Request, setData) {

	zval *data_param = NULL, *_0, *_1;
	zval *data = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data_param);

	data = data_param;


	ZEPHIR_INIT_VAR(_0);
	_1 = zephir_fetch_static_property_ce(brisk_kernel_request_ce, SL("_data") TSRMLS_CC);
	zephir_fast_array_merge(_0, &(_1), &(data) TSRMLS_CC);
	zephir_update_static_property_ce(brisk_kernel_request_ce, SL("_data"), &_0 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Set the request readiness State
 *
 * @param bool state
 * @return null
 */
PHP_METHOD(Brisk_Kernel_Request, setReady) {

	zval *state_param = NULL, *_0;
	zend_bool state;

	zephir_fetch_params(0, 1, 0, &state_param);

	if (UNEXPECTED(Z_TYPE_P(state_param) != IS_BOOL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'state' must be a bool") TSRMLS_CC);
		RETURN_NULL();
	}
	state = Z_BVAL_P(state_param);


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_BOOL(_0, state);
	zephir_update_static_property_ce(brisk_kernel_request_ce, SL("_ready"), &_0 TSRMLS_CC);

}

/**
 * Get the Request component instance
 *
 * @return Request
 */
PHP_METHOD(Brisk_Kernel_Request, getInstance) {

	zval *_0, *_1, *_7, *_2$$3, *_3$$3 = NULL, *_5$$3, *_6$$4;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_4 = NULL;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_static_property_ce(brisk_kernel_request_ce, SL("_ready") TSRMLS_CC);
	_1 = zephir_fetch_static_property_ce(brisk_kernel_request_ce, SL("_instance") TSRMLS_CC);
	if (!zephir_is_true(_0)) {
		ZEPHIR_INIT_VAR(_2$$3);
		object_init_ex(_2$$3, brisk_exception_runtimeexception_ce);
		ZEPHIR_INIT_VAR(_5$$3);
		ZVAL_STRING(_5$$3, "http.request_not_ready", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_CE_STATIC(&_3$$3, brisk_kernel_language_ce, "get", &_4, 27, _5$$3);
		zephir_check_temp_parameter(_5$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, _2$$3, "__construct", NULL, 28, _3$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(_2$$3, "brisk/Kernel/Request.zep", 50 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	} else if (Z_TYPE_P(_1) == IS_NULL) {
		ZEPHIR_INIT_VAR(_6$$4);
		object_init_ex(_6$$4, brisk_kernel_request_ce);
		ZEPHIR_CALL_METHOD(NULL, _6$$4, "__construct", NULL, 53);
		zephir_check_call_status();
		zephir_update_static_property_ce(brisk_kernel_request_ce, SL("_instance"), &_6$$4 TSRMLS_CC);
	}
	_7 = zephir_fetch_static_property_ce(brisk_kernel_request_ce, SL("_instance") TSRMLS_CC);
	RETURN_CTOR(_7);

}

/**
 * construct
 *
 * @return null
 */
PHP_METHOD(Brisk_Kernel_Request, __construct) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_2 = NULL;
	zval *_POST, *_COOKIE, *_FILES, *data = NULL, *_0, *_1 = NULL, *_3 = NULL, *_4, *_5, *_6, *_7, *_8;

	ZEPHIR_MM_GROW();
	zephir_get_global(&_FILES, SS("_FILES") TSRMLS_CC);
	zephir_get_global(&_COOKIE, SS("_COOKIE") TSRMLS_CC);
	zephir_get_global(&_POST, SS("_POST") TSRMLS_CC);

	ZEPHIR_INIT_VAR(data);
	zephir_create_array(data, 4, 0 TSRMLS_CC);
	ZEPHIR_OBS_VAR(_0);
	zephir_read_static_property_ce(&_0, brisk_kernel_request_ce, SL("_data") TSRMLS_CC);
	zephir_array_update_string(&data, SL("get"), &_0, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&data, SL("post"), &_POST, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&data, SL("cookie"), &_COOKIE, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&data, SL("files"), &_FILES, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(_3);
	ZVAL_STRING(_3, "event.request.ready", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_CE_STATIC(&_1, brisk_kernel_event_ce, "fire", &_2, 32, _3, data);
	zephir_check_temp_parameter(_3);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(data, _1);
	zephir_array_fetch_string(&_4, data, SL("get"), PH_NOISY | PH_READONLY, "brisk/Kernel/Request.zep", 67 TSRMLS_CC);
	zephir_update_property_this(getThis(), SL("_get"), _4 TSRMLS_CC);
	zephir_array_fetch_string(&_5, data, SL("post"), PH_NOISY | PH_READONLY, "brisk/Kernel/Request.zep", 68 TSRMLS_CC);
	zephir_update_property_this(getThis(), SL("_post"), _5 TSRMLS_CC);
	zephir_array_fetch_string(&_6, data, SL("cookie"), PH_NOISY | PH_READONLY, "brisk/Kernel/Request.zep", 69 TSRMLS_CC);
	zephir_update_property_this(getThis(), SL("_cookie"), _6 TSRMLS_CC);
	zephir_array_fetch_string(&_7, data, SL("files"), PH_NOISY | PH_READONLY, "brisk/Kernel/Request.zep", 70 TSRMLS_CC);
	zephir_update_property_this(getThis(), SL("_files"), _7 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(_3);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_get"), PH_NOISY_CC);
	_8 = zephir_fetch_nproperty_this(this_ptr, SL("_post"), PH_NOISY_CC);
	zephir_fast_array_merge(_3, &(_0), &(_8) TSRMLS_CC);
	zephir_update_property_this(getThis(), SL("_request"), _3 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Check if request is post
 *
 * @return bool
 */
PHP_METHOD(Brisk_Kernel_Request, isPost) {

	zval *_SERVER, *_0, *_1, _2;

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SERVER, SS("_SERVER") TSRMLS_CC);

	ZEPHIR_INIT_VAR(_0);
	zephir_array_fetch_string(&_1, _SERVER, SL("REQUEST_METHOD"), PH_NOISY | PH_READONLY, "brisk/Kernel/Request.zep", 81 TSRMLS_CC);
	zephir_fast_strtoupper(_0, _1);
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_STRING(&_2, "POST", 0);
	RETURN_MM_BOOL(ZEPHIR_IS_EQUAL(&_2, _0));

}

/**
 * Check if request is ajax
 *
 * @return bool
 */
PHP_METHOD(Brisk_Kernel_Request, isAjax) {

	zval *_SERVER, *_0$$3;

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SERVER, SS("_SERVER") TSRMLS_CC);

	if (zephir_array_isset_string(_SERVER, SS("HTTP_X_REQUESTED_WITH"))) {
		zephir_array_fetch_string(&_0$$3, _SERVER, SL("HTTP_X_REQUESTED_WITH"), PH_NOISY | PH_READONLY, "brisk/Kernel/Request.zep", 92 TSRMLS_CC);
		RETURN_MM_BOOL(ZEPHIR_IS_STRING(_0$$3, "XMLHttpRequest"));
	}
	RETURN_MM_BOOL(0);

}

/**
 * Get client IP Address
 *
 * @return string
 */
PHP_METHOD(Brisk_Kernel_Request, getIpAddress) {

	HashTable *_3$$4;
	HashPosition _2$$4;
	zephir_fcall_cache_entry *_10 = NULL, *_12 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *convert_param = NULL, *_SERVER, *ip = NULL, *ips = NULL, *_9 = NULL, *_13 = NULL, _14, *_0$$3, *forwarded$$4 = NULL, *_1$$4, **_4$$4, *_5$$6, *_6$$7, *_7$$8, *_8$$9, *_11$$10 = NULL;
	zend_bool convert;

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SERVER, SS("_SERVER") TSRMLS_CC);
	zephir_fetch_params(1, 0, 1, &convert_param);

	if (!convert_param) {
		convert = 0;
	} else {
	if (UNEXPECTED(Z_TYPE_P(convert_param) != IS_BOOL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'convert' must be a bool") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	convert = Z_BVAL_P(convert_param);
	}


	ZEPHIR_INIT_VAR(ips);
	array_init(ips);
	if (zephir_array_isset_string(_SERVER, SS("HTTP_CLIENT_IP"))) {
		zephir_array_fetch_string(&_0$$3, _SERVER, SL("HTTP_CLIENT_IP"), PH_NOISY | PH_READONLY, "brisk/Kernel/Request.zep", 107 TSRMLS_CC);
		zephir_array_append(&ips, _0$$3, PH_SEPARATE, "brisk/Kernel/Request.zep", 107);
	}
	if (zephir_array_isset_string(_SERVER, SS("HTTP_X_FORWARDED_FOR"))) {
		zephir_array_fetch_string(&_1$$4, _SERVER, SL("HTTP_X_FORWARDED_FOR"), PH_NOISY | PH_READONLY, "brisk/Kernel/Request.zep", 111 TSRMLS_CC);
		ZEPHIR_INIT_VAR(forwarded$$4);
		zephir_fast_explode_str(forwarded$$4, SL(","), _1$$4, LONG_MAX TSRMLS_CC);
		zephir_is_iterable(forwarded$$4, &_3$$4, &_2$$4, 0, 0, "brisk/Kernel/Request.zep", 115);
		for (
		  ; zend_hash_get_current_data_ex(_3$$4, (void**) &_4$$4, &_2$$4) == SUCCESS
		  ; zend_hash_move_forward_ex(_3$$4, &_2$$4)
		) {
			ZEPHIR_GET_HVALUE(ip, _4$$4);
			zephir_array_append(&ips, ip, PH_SEPARATE, "brisk/Kernel/Request.zep", 113);
		}
	}
	if (zephir_array_isset_string(_SERVER, SS("HTTP_X_FORWARDED"))) {
		zephir_array_fetch_string(&_5$$6, _SERVER, SL("HTTP_X_FORWARDED"), PH_NOISY | PH_READONLY, "brisk/Kernel/Request.zep", 117 TSRMLS_CC);
		zephir_array_append(&ips, _5$$6, PH_SEPARATE, "brisk/Kernel/Request.zep", 117);
	}
	if (zephir_array_isset_string(_SERVER, SS("HTTP_FORWARDED_FOR"))) {
		zephir_array_fetch_string(&_6$$7, _SERVER, SL("HTTP_FORWARDED_FOR"), PH_NOISY | PH_READONLY, "brisk/Kernel/Request.zep", 120 TSRMLS_CC);
		zephir_array_append(&ips, _6$$7, PH_SEPARATE, "brisk/Kernel/Request.zep", 120);
	}
	if (zephir_array_isset_string(_SERVER, SS("HTTP_FORWARDED"))) {
		zephir_array_fetch_string(&_7$$8, _SERVER, SL("HTTP_FORWARDED"), PH_NOISY | PH_READONLY, "brisk/Kernel/Request.zep", 123 TSRMLS_CC);
		zephir_array_append(&ips, _7$$8, PH_SEPARATE, "brisk/Kernel/Request.zep", 123);
	}
	if (zephir_array_isset_string(_SERVER, SS("REMOTE_ADDR"))) {
		zephir_array_fetch_string(&_8$$9, _SERVER, SL("REMOTE_ADDR"), PH_NOISY | PH_READONLY, "brisk/Kernel/Request.zep", 126 TSRMLS_CC);
		zephir_array_append(&ips, _8$$9, PH_SEPARATE, "brisk/Kernel/Request.zep", 126);
	}
	ZEPHIR_CALL_FUNCTION(&_9, "array_filter", NULL, 54, ips);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(ips, _9);
	while (1) {
		if (!(1)) {
			break;
		}
		ZEPHIR_MAKE_REF(ips);
		ZEPHIR_CALL_FUNCTION(&ip, "array_shift", &_10, 7, ips);
		ZEPHIR_UNREF(ips);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&_11$$10, "ip2long", &_12, 55, ip);
		zephir_check_call_status();
		if (!ZEPHIR_IS_FALSE_IDENTICAL(_11$$10)) {
			break;
		}
	}
	ZEPHIR_INIT_VAR(_13);
	if (convert) {
		ZEPHIR_CALL_FUNCTION(&_9, "ip2long", &_12, 55, ip);
		zephir_check_call_status();
		ZEPHIR_SINIT_VAR(_14);
		ZVAL_STRING(&_14, "%u", 0);
		ZEPHIR_CALL_FUNCTION(&_13, "sprintf", NULL, 40, &_14, _9);
		zephir_check_call_status();
	} else {
		ZEPHIR_CPY_WRT(_13, ip);
	}
	RETURN_CCTOR(_13);

}

/**
 * Add request data
 *
 * @param string name
 * @param mixed value
 * @return Request
 */
PHP_METHOD(Brisk_Kernel_Request, add) {

	zval *_6$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_5 = NULL;
	zval *name_param = NULL, *value, *_0, *_1, *_2, *_3$$3, *_4$$3 = NULL, *_7$$3 = NULL;
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


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_flag"), PH_NOISY_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_flag"), PH_NOISY_CC);
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("_flag"), PH_NOISY_CC);
	if (Z_TYPE_P(_0) == IS_NULL) {
		ZEPHIR_INIT_VAR(_3$$3);
		object_init_ex(_3$$3, brisk_exception_methodnotfoundexception_ce);
		ZEPHIR_INIT_VAR(_6$$3);
		zephir_create_array(_6$$3, 1, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_7$$3);
		ZVAL_STRING(_7$$3, "Request:add", 1);
		zephir_array_fast_append(_6$$3, _7$$3);
		ZEPHIR_INIT_NVAR(_7$$3);
		ZVAL_STRING(_7$$3, "http.method_not_found", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_CE_STATIC(&_4$$3, brisk_kernel_language_ce, "get", &_5, 27, _7$$3, _6$$3);
		zephir_check_temp_parameter(_7$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, _3$$3, "__construct", NULL, 28, _4$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(_3$$3, "brisk/Kernel/Request.zep", 148 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	} else if (ZEPHIR_IS_STRING(_1, "get")) {
		zephir_update_property_array(this_ptr, SL("_get"), name, value TSRMLS_CC);
	} else if (ZEPHIR_IS_STRING(_2, "post")) {
		zephir_update_property_array(this_ptr, SL("_post"), name, value TSRMLS_CC);
	}
	zephir_update_property_array(this_ptr, SL("_request"), name, value TSRMLS_CC);
	zephir_update_property_this(getThis(), SL("_flag"), ZEPHIR_GLOBAL(global_null) TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Del request item
 *
 * @param string name
 * @return Request
 */
PHP_METHOD(Brisk_Kernel_Request, del) {

	zval *_6$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_5 = NULL;
	zval *name_param = NULL, *_0, *_1, *_2, *_3$$3, *_4$$3 = NULL, *_7$$3 = NULL, *_8$$4, *_9$$5;
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
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_flag"), PH_NOISY_CC);
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("_flag"), PH_NOISY_CC);
	if (Z_TYPE_P(_0) == IS_NULL) {
		ZEPHIR_INIT_VAR(_3$$3);
		object_init_ex(_3$$3, brisk_exception_methodnotfoundexception_ce);
		ZEPHIR_INIT_VAR(_6$$3);
		zephir_create_array(_6$$3, 1, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_7$$3);
		ZVAL_STRING(_7$$3, "Request:del", 1);
		zephir_array_fast_append(_6$$3, _7$$3);
		ZEPHIR_INIT_NVAR(_7$$3);
		ZVAL_STRING(_7$$3, "http.method_not_found", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_CE_STATIC(&_4$$3, brisk_kernel_language_ce, "get", &_5, 27, _7$$3, _6$$3);
		zephir_check_temp_parameter(_7$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, _3$$3, "__construct", NULL, 28, _4$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(_3$$3, "brisk/Kernel/Request.zep", 168 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	} else if (ZEPHIR_IS_STRING(_1, "get")) {
		_8$$4 = zephir_fetch_nproperty_this(this_ptr, SL("_get"), PH_NOISY_CC);
		zephir_array_unset(&_8$$4, name, PH_SEPARATE);
	} else if (ZEPHIR_IS_STRING(_2, "post")) {
		_9$$5 = zephir_fetch_nproperty_this(this_ptr, SL("_post"), PH_NOISY_CC);
		zephir_array_unset(&_9$$5, name, PH_SEPARATE);
	}
	zephir_update_property_this(getThis(), SL("_flag"), ZEPHIR_GLOBAL(global_null) TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Gets the specified request data
 *
 * @param string name
 * @param string alternative
 * @return mixed
 */
PHP_METHOD(Brisk_Kernel_Request, data) {

	zval *_4$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_3 = NULL;
	zval *name_param = NULL, *alternative_param = NULL, *_0, *value = NULL, *_6, *_7, *_8, *_9, *_10, *_1$$3, *_2$$3 = NULL, *_5$$3 = NULL, *_11$$6, *_12$$9, *_13$$12, *_14$$15, *_15$$18;
	zval *name = NULL, *alternative = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &name_param, &alternative_param);

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
	if (!alternative_param) {
		ZEPHIR_INIT_VAR(alternative);
		ZVAL_STRING(alternative, "", 1);
	} else {
	if (UNEXPECTED(Z_TYPE_P(alternative_param) != IS_STRING && Z_TYPE_P(alternative_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'alternative' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(alternative_param) == IS_STRING)) {
		zephir_get_strval(alternative, alternative_param);
	} else {
		ZEPHIR_INIT_VAR(alternative);
		ZVAL_EMPTY_STRING(alternative);
	}
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_flag"), PH_NOISY_CC);
	if (Z_TYPE_P(_0) == IS_NULL) {
		ZEPHIR_INIT_VAR(_1$$3);
		object_init_ex(_1$$3, brisk_exception_methodnotfoundexception_ce);
		ZEPHIR_INIT_VAR(_4$$3);
		zephir_create_array(_4$$3, 1, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_5$$3);
		ZVAL_STRING(_5$$3, "Request:data", 1);
		zephir_array_fast_append(_4$$3, _5$$3);
		ZEPHIR_INIT_NVAR(_5$$3);
		ZVAL_STRING(_5$$3, "http.method_not_found", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_CE_STATIC(&_2$$3, brisk_kernel_language_ce, "get", &_3, 27, _5$$3, _4$$3);
		zephir_check_temp_parameter(_5$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, _1$$3, "__construct", NULL, 28, _2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(_1$$3, "brisk/Kernel/Request.zep", 188 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	_6 = zephir_fetch_nproperty_this(this_ptr, SL("_flag"), PH_NOISY_CC);
	_7 = zephir_fetch_nproperty_this(this_ptr, SL("_flag"), PH_NOISY_CC);
	_8 = zephir_fetch_nproperty_this(this_ptr, SL("_flag"), PH_NOISY_CC);
	_9 = zephir_fetch_nproperty_this(this_ptr, SL("_flag"), PH_NOISY_CC);
	_10 = zephir_fetch_nproperty_this(this_ptr, SL("_flag"), PH_NOISY_CC);
	if (ZEPHIR_IS_STRING(_6, "get")) {
		if (ZEPHIR_IS_STRING(name, "")) {
			ZEPHIR_OBS_VAR(value);
			zephir_read_property_this(&value, this_ptr, SL("_get"), PH_NOISY_CC);
		} else {
			_11$$6 = zephir_fetch_nproperty_this(this_ptr, SL("_get"), PH_NOISY_CC);
			ZEPHIR_OBS_NVAR(value);
			zephir_array_fetch(&value, _11$$6, name, PH_NOISY, "brisk/Kernel/Request.zep", 195 TSRMLS_CC);
		}
	} else if (ZEPHIR_IS_STRING(_7, "post")) {
		if (ZEPHIR_IS_STRING(name, "")) {
			ZEPHIR_OBS_NVAR(value);
			zephir_read_property_this(&value, this_ptr, SL("_post"), PH_NOISY_CC);
		} else {
			_12$$9 = zephir_fetch_nproperty_this(this_ptr, SL("_post"), PH_NOISY_CC);
			ZEPHIR_OBS_NVAR(value);
			zephir_array_fetch(&value, _12$$9, name, PH_NOISY, "brisk/Kernel/Request.zep", 201 TSRMLS_CC);
		}
	} else if (ZEPHIR_IS_STRING(_8, "request")) {
		if (ZEPHIR_IS_STRING(name, "")) {
			ZEPHIR_OBS_NVAR(value);
			zephir_read_property_this(&value, this_ptr, SL("_request"), PH_NOISY_CC);
		} else {
			_13$$12 = zephir_fetch_nproperty_this(this_ptr, SL("_request"), PH_NOISY_CC);
			ZEPHIR_OBS_NVAR(value);
			zephir_array_fetch(&value, _13$$12, name, PH_NOISY, "brisk/Kernel/Request.zep", 207 TSRMLS_CC);
		}
	} else if (ZEPHIR_IS_STRING(_9, "cookie")) {
		if (ZEPHIR_IS_STRING(name, "")) {
			ZEPHIR_OBS_NVAR(value);
			zephir_read_property_this(&value, this_ptr, SL("_cookie"), PH_NOISY_CC);
		} else {
			_14$$15 = zephir_fetch_nproperty_this(this_ptr, SL("_cookie"), PH_NOISY_CC);
			ZEPHIR_OBS_NVAR(value);
			zephir_array_fetch(&value, _14$$15, name, PH_NOISY, "brisk/Kernel/Request.zep", 213 TSRMLS_CC);
		}
	} else if (ZEPHIR_IS_STRING(_10, "files")) {
		if (ZEPHIR_IS_STRING(name, "")) {
			ZEPHIR_OBS_NVAR(value);
			zephir_read_property_this(&value, this_ptr, SL("_files"), PH_NOISY_CC);
		} else {
			_15$$18 = zephir_fetch_nproperty_this(this_ptr, SL("_files"), PH_NOISY_CC);
			ZEPHIR_OBS_NVAR(value);
			zephir_array_fetch(&value, _15$$18, name, PH_NOISY, "brisk/Kernel/Request.zep", 219 TSRMLS_CC);
		}
	}
	zephir_update_property_this(getThis(), SL("_flag"), ZEPHIR_GLOBAL(global_null) TSRMLS_CC);
	if (Z_TYPE_P(value) == IS_NULL) {
		RETURN_CTOR(alternative);
	}
	RETURN_CCTOR(value);

}

PHP_METHOD(Brisk_Kernel_Request, __get) {

	zval *_0, *_5$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_4 = NULL;
	zval *flag_param = NULL, *_1 = NULL, *_2$$3, *_3$$3 = NULL, *_6$$3;
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


	ZEPHIR_INIT_VAR(_0);
	zephir_create_array(_0, 5, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "get", 1);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "post", 1);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "files", 1);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "cookie", 1);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "request", 1);
	zephir_array_fast_append(_0, _1);
	if (!(zephir_fast_in_array(flag, _0 TSRMLS_CC))) {
		ZEPHIR_INIT_VAR(_2$$3);
		object_init_ex(_2$$3, brisk_exception_runtimeexception_ce);
		ZEPHIR_INIT_VAR(_5$$3);
		zephir_create_array(_5$$3, 1, 0 TSRMLS_CC);
		zephir_array_fast_append(_5$$3, flag);
		ZEPHIR_INIT_VAR(_6$$3);
		ZVAL_STRING(_6$$3, "http.property_not_found", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_CE_STATIC(&_3$$3, brisk_kernel_language_ce, "get", &_4, 27, _6$$3, _5$$3);
		zephir_check_temp_parameter(_6$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, _2$$3, "__construct", NULL, 28, _3$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(_2$$3, "brisk/Kernel/Request.zep", 232 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_this(getThis(), SL("_flag"), flag TSRMLS_CC);
	RETURN_THIS();

}

void zephir_init_static_properties_Brisk_Kernel_Request(TSRMLS_D) {

	zval *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_update_static_property_ce(brisk_kernel_request_ce, SL("_data"), &_0 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

zend_object_value zephir_init_properties_Brisk_Kernel_Request(zend_class_entry *class_type TSRMLS_DC) {

		zval *_0, *_2, *_4, *_6, *_8, *_1$$3, *_3$$4, *_5$$5, *_7$$6, *_9$$7;

		ZEPHIR_MM_GROW();
	
	{
		zval zthis       = zval_used_for_init;
		zval *this_ptr   = &zthis;
		zend_object* obj = ecalloc(1, sizeof(zend_object));
		zend_object_value retval;

		zend_object_std_init(obj, class_type TSRMLS_CC);
		object_properties_init(obj, class_type);
		retval.handle   = zend_objects_store_put(obj, (zend_objects_store_dtor_t)zend_objects_destroy_object, zephir_free_object_storage, NULL TSRMLS_CC);
		retval.handlers = zend_get_std_object_handlers();

		Z_TYPE(zthis)   = IS_OBJECT;
		Z_OBJVAL(zthis) = retval;

		_0 = zephir_fetch_nproperty_this(this_ptr, SL("_cookie"), PH_NOISY_CC);
		if (Z_TYPE_P(_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(_1$$3);
			array_init(_1$$3);
			zephir_update_property_this(getThis(), SL("_cookie"), _1$$3 TSRMLS_CC);
		}
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("_files"), PH_NOISY_CC);
		if (Z_TYPE_P(_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(_3$$4);
			array_init(_3$$4);
			zephir_update_property_this(getThis(), SL("_files"), _3$$4 TSRMLS_CC);
		}
		_4 = zephir_fetch_nproperty_this(this_ptr, SL("_post"), PH_NOISY_CC);
		if (Z_TYPE_P(_4) == IS_NULL) {
			ZEPHIR_INIT_VAR(_5$$5);
			array_init(_5$$5);
			zephir_update_property_this(getThis(), SL("_post"), _5$$5 TSRMLS_CC);
		}
		_6 = zephir_fetch_nproperty_this(this_ptr, SL("_get"), PH_NOISY_CC);
		if (Z_TYPE_P(_6) == IS_NULL) {
			ZEPHIR_INIT_VAR(_7$$6);
			array_init(_7$$6);
			zephir_update_property_this(getThis(), SL("_get"), _7$$6 TSRMLS_CC);
		}
		_8 = zephir_fetch_nproperty_this(this_ptr, SL("_request"), PH_NOISY_CC);
		if (Z_TYPE_P(_8) == IS_NULL) {
			ZEPHIR_INIT_VAR(_9$$7);
			array_init(_9$$7);
			zephir_update_property_this(getThis(), SL("_request"), _9$$7 TSRMLS_CC);
		}
		ZEPHIR_MM_RESTORE();
		return retval;
	}

}


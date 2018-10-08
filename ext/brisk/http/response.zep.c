
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
#include "kernel/array.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/concat.h"
#include "kernel/fcall.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/time.h"
#include "kernel/exit.h"


ZEPHIR_INIT_CLASS(Brisk_Http_Response) {

	ZEPHIR_REGISTER_CLASS(Brisk\\Http, Response, brisk, http_response, brisk_http_response_method_entry, 0);

	zend_declare_property_null(brisk_http_response_ce, SL("_status_texts"), ZEND_ACC_PRIVATE|ZEND_ACC_STATIC TSRMLS_CC);

	return SUCCESS;

}

/**
 * sets gets status text
 *
 * @param int    code 
 * @param string text
 * @return null
 */
PHP_METHOD(Brisk_Http_Response, status) {

	zval *text = NULL;
	zval *code_param = NULL, *text_param = NULL, *_SERVER, *status_text = NULL, *protocol = NULL, *_0, _2, *_3, *_1$$4;
	zend_long code, ZEPHIR_LAST_CALL_STATUS, status_code = 0;

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SERVER, SS("_SERVER") TSRMLS_CC);
	zephir_fetch_params(1, 1, 1, &code_param, &text_param);

	if (UNEXPECTED(Z_TYPE_P(code_param) != IS_LONG)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'code' must be a int") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	code = Z_LVAL_P(code_param);
	if (!text_param) {
		ZEPHIR_INIT_VAR(text);
		ZVAL_STRING(text, "", 1);
	} else {
	if (UNEXPECTED(Z_TYPE_P(text_param) != IS_STRING && Z_TYPE_P(text_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'text' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(text_param) == IS_STRING)) {
		zephir_get_strval(text, text_param);
	} else {
		ZEPHIR_INIT_VAR(text);
		ZVAL_EMPTY_STRING(text);
	}
	}


	status_code = 200;
	_0 = zephir_fetch_static_property_ce(brisk_http_response_ce, SL("_status_texts") TSRMLS_CC);
	if (zephir_array_isset_long(_0, code)) {
		status_code = code;
	}
	ZEPHIR_CPY_WRT(status_text, text);
	if (ZEPHIR_IS_STRING(text, "")) {
		_1$$4 = zephir_fetch_static_property_ce(brisk_http_response_ce, SL("_status_texts") TSRMLS_CC);
		ZEPHIR_OBS_NVAR(status_text);
		zephir_array_fetch_long(&status_text, _1$$4, status_code, PH_NOISY, "brisk/Http/Response.zep", 66 TSRMLS_CC);
	}
	ZEPHIR_OBS_VAR(protocol);
	zephir_array_fetch_string(&protocol, _SERVER, SL("SERVER_PROTOCOL"), PH_NOISY, "brisk/Http/Response.zep", 68 TSRMLS_CC);
	if (Z_TYPE_P(protocol) == IS_NULL) {
		ZEPHIR_INIT_NVAR(protocol);
		ZVAL_STRING(protocol, "HTTP/1.1", 1);
	}
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_LONG(&_2, status_code);
	ZEPHIR_INIT_VAR(_3);
	ZEPHIR_CONCAT_VSVSV(_3, protocol, " ", &_2, " ", status_text);
	ZEPHIR_CALL_FUNCTION(NULL, "header", NULL, 46, _3);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * set cookie
 *
 * @param string name
 * @param string value
 * @param int expire
 * @param string path
 * @param string domain
 * @param boolean secure
 * @param boolean httponly
 * @return null
 */
PHP_METHOD(Brisk_Http_Response, cookie) {

	zend_bool secure, httponly;
	zend_long expire, ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *value_param = NULL, *expire_param = NULL, *path_param = NULL, *domain_param = NULL, *secure_param = NULL, *httponly_param = NULL, *_0, _1, _2, _3;
	zval *name = NULL, *value = NULL, *path = NULL, *domain = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 5, &name_param, &value_param, &expire_param, &path_param, &domain_param, &secure_param, &httponly_param);

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
	if (UNEXPECTED(Z_TYPE_P(value_param) != IS_STRING && Z_TYPE_P(value_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'value' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(value_param) == IS_STRING)) {
		zephir_get_strval(value, value_param);
	} else {
		ZEPHIR_INIT_VAR(value);
		ZVAL_EMPTY_STRING(value);
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
	if (!path_param) {
		ZEPHIR_INIT_VAR(path);
		ZVAL_STRING(path, "/", 1);
	} else {
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
	}
	if (!domain_param) {
		ZEPHIR_INIT_VAR(domain);
		ZVAL_STRING(domain, "", 1);
	} else {
	if (UNEXPECTED(Z_TYPE_P(domain_param) != IS_STRING && Z_TYPE_P(domain_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'domain' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(domain_param) == IS_STRING)) {
		zephir_get_strval(domain, domain_param);
	} else {
		ZEPHIR_INIT_VAR(domain);
		ZVAL_EMPTY_STRING(domain);
	}
	}
	if (!secure_param) {
		secure = 0;
	} else {
	if (UNEXPECTED(Z_TYPE_P(secure_param) != IS_BOOL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'secure' must be a bool") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	secure = Z_BVAL_P(secure_param);
	}
	if (!httponly_param) {
		httponly = 1;
	} else {
	if (UNEXPECTED(Z_TYPE_P(httponly_param) != IS_BOOL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'httponly' must be a bool") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	httponly = Z_BVAL_P(httponly_param);
	}


	ZEPHIR_INIT_VAR(_0);
	zephir_time(_0);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_LONG(&_1, (zephir_get_numberval(_0) + expire));
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_BOOL(&_2, (secure ? 1 : 0));
	ZEPHIR_SINIT_VAR(_3);
	ZVAL_BOOL(&_3, (httponly ? 1 : 0));
	ZEPHIR_CALL_FUNCTION(NULL, "setcookie", NULL, 47, name, value, &_1, path, domain, &_2, &_3);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * redirect page
 *
 * @param string url
 * @param bool script
 * @param string msg
 * @return null
 */
PHP_METHOD(Brisk_Http_Response, redirect) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool script;
	zval *url_param = NULL, *script_param = NULL, *msg_param = NULL, *_0$$3, *str = NULL, *_2, *_1$$4;
	zval *url = NULL, *msg = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &url_param, &script_param, &msg_param);

	if (UNEXPECTED(Z_TYPE_P(url_param) != IS_STRING && Z_TYPE_P(url_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'url' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(url_param) == IS_STRING)) {
		zephir_get_strval(url, url_param);
	} else {
		ZEPHIR_INIT_VAR(url);
		ZVAL_EMPTY_STRING(url);
	}
	if (!script_param) {
		script = 0;
	} else {
	if (UNEXPECTED(Z_TYPE_P(script_param) != IS_BOOL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'script' must be a bool") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	script = Z_BVAL_P(script_param);
	}
	if (!msg_param) {
		ZEPHIR_INIT_VAR(msg);
		ZVAL_STRING(msg, "", 1);
	} else {
	if (UNEXPECTED(Z_TYPE_P(msg_param) != IS_STRING && Z_TYPE_P(msg_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'msg' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(msg_param) == IS_STRING)) {
		zephir_get_strval(msg, msg_param);
	} else {
		ZEPHIR_INIT_VAR(msg);
		ZVAL_EMPTY_STRING(msg);
	}
	}


	if (!script) {
		ZEPHIR_INIT_VAR(_0$$3);
		ZVAL_STRING(_0$$3, "Location", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_SELF(NULL, "header", NULL, 0, _0$$3, url);
		zephir_check_temp_parameter(_0$$3);
		zephir_check_call_status();
		ZEPHIR_MM_RESTORE();
		zephir_exit_empty();
	}
	ZEPHIR_INIT_VAR(str);
	ZVAL_STRING(str, "<script type=text/javascript>", 1);
	if (!ZEPHIR_IS_STRING(msg, "")) {
		ZEPHIR_INIT_VAR(_1$$4);
		ZEPHIR_CONCAT_VSVS(_1$$4, str, "alert('", msg, "');");
		ZEPHIR_CPY_WRT(str, _1$$4);
	}
	ZEPHIR_INIT_VAR(_2);
	ZEPHIR_CONCAT_VSVS(_2, str, "location.href='", url, "';</script>");
	ZEPHIR_CPY_WRT(str, _2);
	zend_print_zval(str, 0);
	ZEPHIR_MM_RESTORE();
	zephir_exit_empty();
	ZEPHIR_MM_RESTORE();

}

/**
 * alert message
 *
 * @param string msg
 * @return null
 */
PHP_METHOD(Brisk_Http_Response, alert) {

	zval *msg_param = NULL;
	zval *msg = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &msg_param);

	if (UNEXPECTED(Z_TYPE_P(msg_param) != IS_STRING && Z_TYPE_P(msg_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'msg' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(msg_param) == IS_STRING)) {
		zephir_get_strval(msg, msg_param);
	} else {
		ZEPHIR_INIT_VAR(msg);
		ZVAL_EMPTY_STRING(msg);
	}


	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_CONCAT_SVS(_0, "<script type=text/javascript>alert('", msg, "');</script>");
	zend_print_zval(_0, 0);
	ZEPHIR_MM_RESTORE();

}

/**
 * sets no cache
 *
 * @return null
 */
PHP_METHOD(Brisk_Http_Response, noCache) {

	zval *_0 = NULL, *_1 = NULL, _2, *_3 = NULL, *_4, *_5;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "Expires", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "Mon, 26 Jul 1999 01:00:00 GMT", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_SELF(NULL, "header", NULL, 0, _0, _1);
	zephir_check_temp_parameter(_0);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_STRING(&_2, "D, d M Y H:i:s", 0);
	ZEPHIR_CALL_FUNCTION(&_3, "gmdate", NULL, 48, &_2);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_4);
	ZEPHIR_CONCAT_VS(_4, _3, " GMT");
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "Last-Modified", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_SELF(NULL, "header", NULL, 0, _0, _4);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "Cache-Control", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "no-store, no-cache, must-revalidate", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_SELF(NULL, "header", NULL, 0, _0, _1);
	zephir_check_temp_parameter(_0);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "Cache-Control", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "post-check=0, pre-check=0", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_5);
	ZVAL_BOOL(_5, 0);
	ZEPHIR_CALL_SELF(NULL, "header", NULL, 0, _0, _1, _5);
	zephir_check_temp_parameter(_0);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "Pragma", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "no-cache", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_SELF(NULL, "header", NULL, 0, _0, _1);
	zephir_check_temp_parameter(_0);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * set expire time
 *
 * @param int sec
 * @return null
 */
PHP_METHOD(Brisk_Http_Response, expires) {

	zval *sec_param = NULL, *_0, _1, _2, *_3 = NULL, *_4, *_5;
	zend_long sec, ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &sec_param);

	if (!sec_param) {
		sec = 3600;
	} else {
	if (UNEXPECTED(Z_TYPE_P(sec_param) != IS_LONG)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'sec' must be a int") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	sec = Z_LVAL_P(sec_param);
	}


	ZEPHIR_INIT_VAR(_0);
	zephir_time(_0);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_STRING(&_1, "D, d M Y H:i:s", 0);
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_LONG(&_2, (zephir_get_numberval(_0) + sec));
	ZEPHIR_CALL_FUNCTION(&_3, "date", NULL, 49, &_1, &_2);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_4);
	ZEPHIR_CONCAT_VS(_4, _3, " GMT");
	ZEPHIR_INIT_VAR(_5);
	ZVAL_STRING(_5, "Expires", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_SELF(NULL, "header", NULL, 0, _5, _4);
	zephir_check_temp_parameter(_5);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * set header parameter
 *
 * @param string var
 * @param mixed val
 * @param bool replace
 * @return mixed
 */
PHP_METHOD(Brisk_Http_Response, header) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool is_replace;
	zval *name_param = NULL, *value_param = NULL, *is_replace_param = NULL, _1;
	zval *name = NULL, *value = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &name_param, &value_param, &is_replace_param);

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
	if (UNEXPECTED(Z_TYPE_P(value_param) != IS_STRING && Z_TYPE_P(value_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'value' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(value_param) == IS_STRING)) {
		zephir_get_strval(value, value_param);
	} else {
		ZEPHIR_INIT_VAR(value);
		ZVAL_EMPTY_STRING(value);
	}
	if (!is_replace_param) {
		is_replace = 1;
	} else {
	if (UNEXPECTED(Z_TYPE_P(is_replace_param) != IS_BOOL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'is_replace' must be a bool") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	is_replace = Z_BVAL_P(is_replace_param);
	}


	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_CONCAT_VSV(_0, name, ": ", value);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_BOOL(&_1, (is_replace ? 1 : 0));
	ZEPHIR_CALL_FUNCTION(NULL, "header", NULL, 46, _0, &_1);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

void zephir_init_static_properties_Brisk_Http_Response(TSRMLS_D) {

	zval *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	zephir_create_array(_0, 41, 0 TSRMLS_CC);
	add_index_stringl(_0, 100, SL("Continue"), 1);
	add_index_stringl(_0, 101, SL("Switching Protocols"), 1);
	add_index_stringl(_0, 200, SL("OK"), 1);
	add_index_stringl(_0, 201, SL("Created"), 1);
	add_index_stringl(_0, 202, SL("Accepted"), 1);
	add_index_stringl(_0, 203, SL("Non-Authoritative Information"), 1);
	add_index_stringl(_0, 204, SL("No Content"), 1);
	add_index_stringl(_0, 205, SL("Reset Content"), 1);
	add_index_stringl(_0, 206, SL("Partial Content"), 1);
	add_index_stringl(_0, 300, SL("Multiple Choices"), 1);
	add_index_stringl(_0, 301, SL("Moved Permanently"), 1);
	add_index_stringl(_0, 302, SL("Found"), 1);
	add_index_stringl(_0, 303, SL("See Other"), 1);
	add_index_stringl(_0, 304, SL("Not Modified"), 1);
	add_index_stringl(_0, 305, SL("Use Proxy"), 1);
	add_index_stringl(_0, 306, SL("Unused"), 1);
	add_index_stringl(_0, 307, SL("Temporary Redirect"), 1);
	add_index_stringl(_0, 400, SL("Bad Request"), 1);
	add_index_stringl(_0, 401, SL("Unauthorized"), 1);
	add_index_stringl(_0, 402, SL("Payment Required"), 1);
	add_index_stringl(_0, 403, SL("Forbidden"), 1);
	add_index_stringl(_0, 404, SL("Not Found"), 1);
	add_index_stringl(_0, 405, SL("Method Not Allowed"), 1);
	add_index_stringl(_0, 406, SL("Not Acceptable"), 1);
	add_index_stringl(_0, 407, SL("Proxy Authentication Required"), 1);
	add_index_stringl(_0, 408, SL("Request Timeout"), 1);
	add_index_stringl(_0, 409, SL("Conflict"), 1);
	add_index_stringl(_0, 410, SL("Gone"), 1);
	add_index_stringl(_0, 411, SL("Length Required"), 1);
	add_index_stringl(_0, 412, SL("Precondition Failed"), 1);
	add_index_stringl(_0, 413, SL("Request Entity Too Large"), 1);
	add_index_stringl(_0, 414, SL("Request-URI Too Long"), 1);
	add_index_stringl(_0, 415, SL("Unsupported Media Type"), 1);
	add_index_stringl(_0, 416, SL("Requested Range Not Satisfiable"), 1);
	add_index_stringl(_0, 417, SL("Expectation Failed"), 1);
	add_index_stringl(_0, 500, SL("Internal Server Error"), 1);
	add_index_stringl(_0, 501, SL("Not Implemented"), 1);
	add_index_stringl(_0, 502, SL("Bad Gateway"), 1);
	add_index_stringl(_0, 503, SL("Service Unavailable"), 1);
	add_index_stringl(_0, 504, SL("Gateway Timeout"), 1);
	add_index_stringl(_0, 505, SL("HTTP Version Not Supported"), 1);
	zephir_update_static_property_ce(brisk_http_response_ce, SL("_status_texts"), &_0 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}


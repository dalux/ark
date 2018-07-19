
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


ZEPHIR_INIT_CLASS(Brisk_Kernel_Response) {

	ZEPHIR_REGISTER_CLASS(Brisk\\Kernel, Response, brisk, kernel_response, brisk_kernel_response_method_entry, 0);

	zend_declare_property_null(brisk_kernel_response_ce, SL("_status_texts"), ZEND_ACC_PRIVATE TSRMLS_CC);

	brisk_kernel_response_ce->create_object = zephir_init_properties_Brisk_Kernel_Response;
	return SUCCESS;

}

PHP_METHOD(Brisk_Kernel_Response, status) {

	zval text;
	zval *code_param = NULL, *text_param = NULL, *_SERVER, _0, status_text, protocol, header_str, _2, _1$$5;
	zend_long code, ZEPHIR_LAST_CALL_STATUS, status_code = 0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&status_text);
	ZVAL_UNDEF(&protocol);
	ZVAL_UNDEF(&header_str);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1$$5);
	ZVAL_UNDEF(&text);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SERVER, SL("_SERVER"));
	zephir_fetch_params(1, 1, 1, &code_param, &text_param);

	if (UNEXPECTED(Z_TYPE_P(code_param) != IS_LONG)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'code' must be a int") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	code = Z_LVAL_P(code_param);
	if (!text_param) {
		ZEPHIR_INIT_VAR(&text);
		ZVAL_STRING(&text, "");
	} else {
	if (UNEXPECTED(Z_TYPE_P(text_param) != IS_STRING && Z_TYPE_P(text_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'text' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(text_param) == IS_STRING)) {
		zephir_get_strval(&text, text_param);
	} else {
		ZEPHIR_INIT_VAR(&text);
		ZVAL_EMPTY_STRING(&text);
	}
	}


	zephir_read_property(&_0, this_ptr, SL("_status_texts"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_long(&_0, code)) {
		status_code = code;
	} else {
		status_code = 200;
	}
	if (ZEPHIR_IS_STRING(&text, "")) {
		zephir_read_property(&_1$$5, this_ptr, SL("_status_texts"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_OBS_VAR(&status_text);
		zephir_array_fetch_long(&status_text, &_1$$5, status_code, PH_NOISY, "brisk/Kernel/Response.zep", 60 TSRMLS_CC);
	} else {
		ZEPHIR_CPY_WRT(&status_text, &text);
	}
	ZEPHIR_OBS_VAR(&protocol);
	zephir_array_fetch_string(&protocol, _SERVER, SL("SERVER_PROTOCOL"), PH_NOISY, "brisk/Kernel/Response.zep", 64 TSRMLS_CC);
	if (Z_TYPE_P(&protocol) == IS_NULL) {
		ZEPHIR_INIT_NVAR(&protocol);
		ZVAL_STRING(&protocol, "HTTP/1.1");
	}
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_LONG(&_2, status_code);
	ZEPHIR_INIT_VAR(&header_str);
	ZEPHIR_CONCAT_VSVSV(&header_str, &protocol, " ", &_2, " ", &status_text);
	ZEPHIR_CALL_FUNCTION(NULL, "header", NULL, 24, &header_str);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Brisk_Kernel_Response, cookie) {

	zend_bool secure, httponly;
	zend_long expire, ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *val, val_sub, *expire_param = NULL, *path_param = NULL, *domain_param = NULL, *secure_param = NULL, *httponly_param = NULL, _0, _1, _2, _3;
	zval name, path, domain;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&path);
	ZVAL_UNDEF(&domain);
	ZVAL_UNDEF(&val_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 5, &name_param, &val, &expire_param, &path_param, &domain_param, &secure_param, &httponly_param);

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
		expire = 0;
	} else {
	if (UNEXPECTED(Z_TYPE_P(expire_param) != IS_LONG)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'expire' must be a int") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	expire = Z_LVAL_P(expire_param);
	}
	if (!path_param) {
		ZEPHIR_INIT_VAR(&path);
		ZVAL_STRING(&path, "/");
	} else {
	if (UNEXPECTED(Z_TYPE_P(path_param) != IS_STRING && Z_TYPE_P(path_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'path' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(path_param) == IS_STRING)) {
		zephir_get_strval(&path, path_param);
	} else {
		ZEPHIR_INIT_VAR(&path);
		ZVAL_EMPTY_STRING(&path);
	}
	}
	if (!domain_param) {
		ZEPHIR_INIT_VAR(&domain);
		ZVAL_STRING(&domain, "");
	} else {
	if (UNEXPECTED(Z_TYPE_P(domain_param) != IS_STRING && Z_TYPE_P(domain_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'domain' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(domain_param) == IS_STRING)) {
		zephir_get_strval(&domain, domain_param);
	} else {
		ZEPHIR_INIT_VAR(&domain);
		ZVAL_EMPTY_STRING(&domain);
	}
	}
	if (!secure_param) {
		secure = 0;
	} else {
	if (UNEXPECTED(Z_TYPE_P(secure_param) != IS_TRUE && Z_TYPE_P(secure_param) != IS_FALSE)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'secure' must be a bool") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	secure = (Z_TYPE_P(secure_param) == IS_TRUE);
	}
	if (!httponly_param) {
		httponly = 1;
	} else {
	if (UNEXPECTED(Z_TYPE_P(httponly_param) != IS_TRUE && Z_TYPE_P(httponly_param) != IS_FALSE)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'httponly' must be a bool") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	httponly = (Z_TYPE_P(httponly_param) == IS_TRUE);
	}


	ZEPHIR_INIT_VAR(&_0);
	zephir_time(&_0);
	ZVAL_LONG(&_1, (zephir_get_numberval(&_0) + expire));
	ZVAL_BOOL(&_2, (secure ? 1 : 0));
	ZVAL_BOOL(&_3, (httponly ? 1 : 0));
	ZEPHIR_CALL_FUNCTION(NULL, "setcookie", NULL, 49, &name, val, &_1, &path, &domain, &_2, &_3);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Brisk_Kernel_Response, redirect) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool script;
	zval *url_param = NULL, *script_param = NULL, *msg_param = NULL, _0$$3, str;
	zval url, msg, _2, _1$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&url);
	ZVAL_UNDEF(&msg);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&str);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &url_param, &script_param, &msg_param);

	if (UNEXPECTED(Z_TYPE_P(url_param) != IS_STRING && Z_TYPE_P(url_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'url' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(url_param) == IS_STRING)) {
		zephir_get_strval(&url, url_param);
	} else {
		ZEPHIR_INIT_VAR(&url);
		ZVAL_EMPTY_STRING(&url);
	}
	if (!script_param) {
		script = 0;
	} else {
	if (UNEXPECTED(Z_TYPE_P(script_param) != IS_TRUE && Z_TYPE_P(script_param) != IS_FALSE)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'script' must be a bool") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	script = (Z_TYPE_P(script_param) == IS_TRUE);
	}
	if (!msg_param) {
		ZEPHIR_INIT_VAR(&msg);
		ZVAL_STRING(&msg, "");
	} else {
	if (UNEXPECTED(Z_TYPE_P(msg_param) != IS_STRING && Z_TYPE_P(msg_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'msg' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(msg_param) == IS_STRING)) {
		zephir_get_strval(&msg, msg_param);
	} else {
		ZEPHIR_INIT_VAR(&msg);
		ZVAL_EMPTY_STRING(&msg);
	}
	}


	if (!script) {
		ZEPHIR_INIT_VAR(&_0$$3);
		ZVAL_STRING(&_0$$3, "Location");
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "header", NULL, 0, &_0$$3, &url);
		zephir_check_call_status();
		ZEPHIR_MM_RESTORE();
		zephir_exit_empty();
	}
	ZEPHIR_INIT_VAR(&str);
	ZVAL_STRING(&str, "<script type='text/javascript'>");
	if (!ZEPHIR_IS_STRING(&msg, "")) {
		ZEPHIR_INIT_VAR(&_1$$4);
		ZEPHIR_CONCAT_SVS(&_1$$4, "alert('", &msg, "');");
		zephir_concat_self(&str, &_1$$4 TSRMLS_CC);
	}
	ZEPHIR_INIT_VAR(&_2);
	ZEPHIR_CONCAT_SVS(&_2, "location.href='", &url, "';</script>");
	zephir_concat_self(&str, &_2 TSRMLS_CC);
	zend_print_zval(&str, 0);
	ZEPHIR_MM_RESTORE();
	zephir_exit_empty();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Brisk_Kernel_Response, alert) {

	zval *msg_param = NULL, str;
	zval msg, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&msg);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&str);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &msg_param);

	if (UNEXPECTED(Z_TYPE_P(msg_param) != IS_STRING && Z_TYPE_P(msg_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'msg' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(msg_param) == IS_STRING)) {
		zephir_get_strval(&msg, msg_param);
	} else {
		ZEPHIR_INIT_VAR(&msg);
		ZVAL_EMPTY_STRING(&msg);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_CONCAT_SVS(&_0, "<script type='text/javascript'>alert('", &msg, "');</script>");
	zephir_concat_self(&str, &_0 TSRMLS_CC);
	zend_print_zval(&str, 0);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Brisk_Kernel_Response, noCache) {

	zval _0, _1, _3, _4, _5;
	zephir_fcall_cache_entry *_2 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "Expires");
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "Mon, 26 Jul 1999 01:00:00 GMT");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "header", &_2, 0, &_0, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "D, d M Y H:i:s");
	ZEPHIR_CALL_FUNCTION(&_3, "gmdate", NULL, 50, &_0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_4);
	ZEPHIR_CONCAT_VS(&_4, &_3, " GMT");
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "Last-Modified");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "header", &_2, 0, &_0, &_4);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "Cache-Control");
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "no-store, no-cache, must-revalidate");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "header", &_2, 0, &_0, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "Cache-Control");
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "post-check=0, pre-check=0");
	ZVAL_BOOL(&_5, 0);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "header", &_2, 0, &_0, &_1, &_5);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "Pragma");
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "no-cache");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "header", &_2, 0, &_0, &_1);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Brisk_Kernel_Response, expires) {

	zval *sec_param = NULL, _0, _1, _2, _3, _4;
	zend_long sec, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);

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


	ZEPHIR_INIT_VAR(&_0);
	zephir_time(&_0);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "D, d M Y H:i:s");
	ZVAL_LONG(&_2, (zephir_get_numberval(&_0) + sec));
	ZEPHIR_CALL_FUNCTION(&_3, "date", NULL, 51, &_1, &_2);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_4);
	ZEPHIR_CONCAT_VS(&_4, &_3, " GMT");
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "Expires");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "header", NULL, 0, &_1, &_4);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Brisk_Kernel_Response, header) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool replace;
	zval *item_param = NULL, *val_param = NULL, *replace_param = NULL, _1;
	zval item, val, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&item);
	ZVAL_UNDEF(&val);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 3, &item_param, &val_param, &replace_param);

	if (!item_param) {
		ZEPHIR_INIT_VAR(&item);
		ZVAL_STRING(&item, "");
	} else {
	if (UNEXPECTED(Z_TYPE_P(item_param) != IS_STRING && Z_TYPE_P(item_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'item' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(item_param) == IS_STRING)) {
		zephir_get_strval(&item, item_param);
	} else {
		ZEPHIR_INIT_VAR(&item);
		ZVAL_EMPTY_STRING(&item);
	}
	}
	if (!val_param) {
		ZEPHIR_INIT_VAR(&val);
		ZVAL_STRING(&val, "");
	} else {
	if (UNEXPECTED(Z_TYPE_P(val_param) != IS_STRING && Z_TYPE_P(val_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'val' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(val_param) == IS_STRING)) {
		zephir_get_strval(&val, val_param);
	} else {
		ZEPHIR_INIT_VAR(&val);
		ZVAL_EMPTY_STRING(&val);
	}
	}
	if (!replace_param) {
		replace = 1;
	} else {
	if (UNEXPECTED(Z_TYPE_P(replace_param) != IS_TRUE && Z_TYPE_P(replace_param) != IS_FALSE)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'replace' must be a bool") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	replace = (Z_TYPE_P(replace_param) == IS_TRUE);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_CONCAT_VSV(&_0, &item, ": ", &val);
	ZVAL_BOOL(&_1, (replace ? 1 : 0));
	ZEPHIR_CALL_FUNCTION(NULL, "header", NULL, 24, &_0, &_1);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

zend_object *zephir_init_properties_Brisk_Kernel_Response(zend_class_entry *class_type TSRMLS_DC) {

		zval _1$$3;
	zval _0;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("_status_texts"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			zephir_create_array(&_1$$3, 41, 0 TSRMLS_CC);
			add_index_stringl(&_1$$3, 100, SL("Continue"));
			add_index_stringl(&_1$$3, 101, SL("Switching Protocols"));
			add_index_stringl(&_1$$3, 200, SL("OK"));
			add_index_stringl(&_1$$3, 201, SL("Created"));
			add_index_stringl(&_1$$3, 202, SL("Accepted"));
			add_index_stringl(&_1$$3, 203, SL("Non-Authoritative Information"));
			add_index_stringl(&_1$$3, 204, SL("No Content"));
			add_index_stringl(&_1$$3, 205, SL("Reset Content"));
			add_index_stringl(&_1$$3, 206, SL("Partial Content"));
			add_index_stringl(&_1$$3, 300, SL("Multiple Choices"));
			add_index_stringl(&_1$$3, 301, SL("Moved Permanently"));
			add_index_stringl(&_1$$3, 302, SL("Found"));
			add_index_stringl(&_1$$3, 303, SL("See Other"));
			add_index_stringl(&_1$$3, 304, SL("Not Modified"));
			add_index_stringl(&_1$$3, 305, SL("Use Proxy"));
			add_index_stringl(&_1$$3, 306, SL("Unused"));
			add_index_stringl(&_1$$3, 307, SL("Temporary Redirect"));
			add_index_stringl(&_1$$3, 400, SL("Bad Request"));
			add_index_stringl(&_1$$3, 401, SL("Unauthorized"));
			add_index_stringl(&_1$$3, 402, SL("Payment Required"));
			add_index_stringl(&_1$$3, 403, SL("Forbidden"));
			add_index_stringl(&_1$$3, 404, SL("Not Found"));
			add_index_stringl(&_1$$3, 405, SL("Method Not Allowed"));
			add_index_stringl(&_1$$3, 406, SL("Not Acceptable"));
			add_index_stringl(&_1$$3, 407, SL("Proxy Authentication Required"));
			add_index_stringl(&_1$$3, 408, SL("Request Timeout"));
			add_index_stringl(&_1$$3, 409, SL("Conflict"));
			add_index_stringl(&_1$$3, 410, SL("Gone"));
			add_index_stringl(&_1$$3, 411, SL("Length Required"));
			add_index_stringl(&_1$$3, 412, SL("Precondition Failed"));
			add_index_stringl(&_1$$3, 413, SL("Request Entity Too Large"));
			add_index_stringl(&_1$$3, 414, SL("Request-URI Too Long"));
			add_index_stringl(&_1$$3, 415, SL("Unsupported Media Type"));
			add_index_stringl(&_1$$3, 416, SL("Requested Range Not Satisfiable"));
			add_index_stringl(&_1$$3, 417, SL("Expectation Failed"));
			add_index_stringl(&_1$$3, 500, SL("Internal Server Error"));
			add_index_stringl(&_1$$3, 501, SL("Not Implemented"));
			add_index_stringl(&_1$$3, 502, SL("Bad Gateway"));
			add_index_stringl(&_1$$3, 503, SL("Service Unavailable"));
			add_index_stringl(&_1$$3, 504, SL("Gateway Timeout"));
			add_index_stringl(&_1$$3, 505, SL("HTTP Version Not Supported"));
			zephir_update_property_zval(this_ptr, SL("_status_texts"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}


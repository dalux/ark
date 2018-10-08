
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
#include "kernel/memory.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"


ZEPHIR_INIT_CLASS(Brisk_Session_UserHandler) {

	ZEPHIR_REGISTER_CLASS(Brisk\\Session, UserHandler, brisk, session_userhandler, brisk_session_userhandler_method_entry, 0);

	zend_declare_property_null(brisk_session_userhandler_ce, SL("_cache"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_class_implements(brisk_session_userhandler_ce TSRMLS_CC, 1, zephir_get_internal_ce(SS("sessionhandlerinterface") TSRMLS_CC));
	return SUCCESS;

}

PHP_METHOD(Brisk_Session_UserHandler, __construct) {

	zval *cache;

	zephir_fetch_params(0, 1, 0, &cache);



	zephir_update_property_this(getThis(), SL("_cache"), cache TSRMLS_CC);

}

PHP_METHOD(Brisk_Session_UserHandler, open) {

	zval *save_path_param = NULL, *session_name_param = NULL;
	zval *save_path = NULL, *session_name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &save_path_param, &session_name_param);

	if (UNEXPECTED(Z_TYPE_P(save_path_param) != IS_STRING && Z_TYPE_P(save_path_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'save_path' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(save_path_param) == IS_STRING)) {
		zephir_get_strval(save_path, save_path_param);
	} else {
		ZEPHIR_INIT_VAR(save_path);
		ZVAL_EMPTY_STRING(save_path);
	}
	if (UNEXPECTED(Z_TYPE_P(session_name_param) != IS_STRING && Z_TYPE_P(session_name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'session_name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(session_name_param) == IS_STRING)) {
		zephir_get_strval(session_name, session_name_param);
	} else {
		ZEPHIR_INIT_VAR(session_name);
		ZVAL_EMPTY_STRING(session_name);
	}


	RETURN_MM_BOOL(1);

}

PHP_METHOD(Brisk_Session_UserHandler, close) {

	

	RETURN_BOOL(1);

}

PHP_METHOD(Brisk_Session_UserHandler, read) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *session_id_param = NULL, *_0;
	zval *session_id = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &session_id_param);

	if (UNEXPECTED(Z_TYPE_P(session_id_param) != IS_STRING && Z_TYPE_P(session_id_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'session_id' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(session_id_param) == IS_STRING)) {
		zephir_get_strval(session_id, session_id_param);
	} else {
		ZEPHIR_INIT_VAR(session_id);
		ZVAL_EMPTY_STRING(session_id);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_cache"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_0, "get", NULL, 0, session_id);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Brisk_Session_UserHandler, write) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *session_id_param = NULL, *session_data_param = NULL, *_0;
	zval *session_id = NULL, *session_data = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &session_id_param, &session_data_param);

	if (UNEXPECTED(Z_TYPE_P(session_id_param) != IS_STRING && Z_TYPE_P(session_id_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'session_id' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(session_id_param) == IS_STRING)) {
		zephir_get_strval(session_id, session_id_param);
	} else {
		ZEPHIR_INIT_VAR(session_id);
		ZVAL_EMPTY_STRING(session_id);
	}
	if (UNEXPECTED(Z_TYPE_P(session_data_param) != IS_STRING && Z_TYPE_P(session_data_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'session_data' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(session_data_param) == IS_STRING)) {
		zephir_get_strval(session_data, session_data_param);
	} else {
		ZEPHIR_INIT_VAR(session_data);
		ZVAL_EMPTY_STRING(session_data);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_cache"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_0, "set", NULL, 0, session_id, session_data);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Brisk_Session_UserHandler, destroy) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *session_id_param = NULL, *_0;
	zval *session_id = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &session_id_param);

	if (UNEXPECTED(Z_TYPE_P(session_id_param) != IS_STRING && Z_TYPE_P(session_id_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'session_id' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(session_id_param) == IS_STRING)) {
		zephir_get_strval(session_id, session_id_param);
	} else {
		ZEPHIR_INIT_VAR(session_id);
		ZVAL_EMPTY_STRING(session_id);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_cache"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_0, "delete", NULL, 0, session_id);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Brisk_Session_UserHandler, gc) {

	zval *max_lifetime_param = NULL;
	zend_long max_lifetime;

	zephir_fetch_params(0, 1, 0, &max_lifetime_param);

	if (UNEXPECTED(Z_TYPE_P(max_lifetime_param) != IS_LONG)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'max_lifetime' must be a int") TSRMLS_CC);
		RETURN_NULL();
	}
	max_lifetime = Z_LVAL_P(max_lifetime_param);


	RETURN_BOOL(1);

}


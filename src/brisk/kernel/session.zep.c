
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
#include "kernel/fcall.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/array.h"


ZEPHIR_INIT_CLASS(Brisk_Kernel_Session) {

	ZEPHIR_REGISTER_CLASS(Brisk\\Kernel, Session, brisk, kernel_session, brisk_kernel_session_method_entry, 0);

	return SUCCESS;

}

/**
 * Start the session service
 *
 * @param int session_id
 * @return null
 */
PHP_METHOD(Brisk_Kernel_Session, start) {

	zval *session_id_param = NULL, _0$$3, _1;
	zend_long session_id, ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &session_id_param);

	if (!session_id_param) {
		session_id = 0;
	} else {
	if (UNEXPECTED(Z_TYPE_P(session_id_param) != IS_LONG)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'session_id' must be a int") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	session_id = Z_LVAL_P(session_id_param);
	}


	if (session_id != 0) {
		ZEPHIR_SINIT_VAR(_0$$3);
		ZVAL_LONG(&_0$$3, session_id);
		ZEPHIR_CALL_FUNCTION(NULL, "session_id", NULL, 71, &_0$$3);
		zephir_check_call_status();
	}
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_STRING(&_1, "private,must-revalidate", 0);
	ZEPHIR_CALL_FUNCTION(NULL, "session_cache_limiter", NULL, 72, &_1);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(NULL, "session_start", NULL, 73);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Get Session data
 *
 * @param string name
 * @return mixed
 */
PHP_METHOD(Brisk_Kernel_Session, get) {

	zval *name_param = NULL, *_SESSION, *_0 = NULL;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SESSION, SS("_SESSION") TSRMLS_CC);
	zephir_fetch_params(1, 0, 1, &name_param);

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
	if (ZEPHIR_IS_STRING(name, "")) {
		ZEPHIR_CPY_WRT(_0, _SESSION);
	} else {
		zephir_array_fetch(&_0, _SESSION, name, PH_NOISY, "brisk/Kernel/Session.zep", 29 TSRMLS_CC);
	}
	RETURN_CCTOR(_0);

}

/**
 * Set Session data
 *
 * @param string name
 * @param mixed value
 * @return Session
 */
PHP_METHOD(Brisk_Kernel_Session, set) {

	zval *name_param = NULL, *value, *_SESSION;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SESSION, SS("_SESSION") TSRMLS_CC);
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


	zephir_array_update_zval(&_SESSION, name, &value, PH_COPY | PH_SEPARATE);
	RETURN_THIS();

}

/**
 * Delete Session data
 *
 * @param string name
 * @return Session
 */
PHP_METHOD(Brisk_Kernel_Session, delete) {

	zval *name_param = NULL, *_SESSION;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SESSION, SS("_SESSION") TSRMLS_CC);
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


	zephir_array_unset(&_SESSION, name, PH_SEPARATE);
	RETURN_THIS();

}

/**
 * Clean all Session data
 *
 * @return null
 */
PHP_METHOD(Brisk_Kernel_Session, clean) {

	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_RETURN_CALL_FUNCTION("session_destroy", NULL, 74);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Brisk_Kernel_Session, __get) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL;
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


	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "get", NULL, 0, name);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Brisk_Kernel_Session, __set) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *value;
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


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "set", NULL, 0, name, value);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}


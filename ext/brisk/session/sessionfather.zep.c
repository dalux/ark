
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
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/object.h"
#include "kernel/operators.h"


ZEPHIR_INIT_CLASS(Brisk_Session_SessionFather) {

	ZEPHIR_REGISTER_CLASS(Brisk\\Session, SessionFather, brisk, session_sessionfather, brisk_session_sessionfather_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_property_long(brisk_session_sessionfather_ce, SL("_expire_time"), 1440, ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Brisk_Session_SessionFather, __construct) {

	HashTable *_2$$3;
	HashPosition _1$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_4 = NULL;
	zval *option_param = NULL, *k$$3 = NULL, *v$$3 = NULL, *_0$$3, **_3$$3;
	zval *option = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &option_param);

	if (!option_param) {
		ZEPHIR_INIT_VAR(option);
		array_init(option);
	} else {
	option = option_param;
	}


	if (zephir_array_isset_string(option, SS("setting"))) {
		zephir_array_fetch_string(&_0$$3, option, SL("setting"), PH_NOISY | PH_READONLY, "brisk/Session/SessionFather.zep", 12 TSRMLS_CC);
		zephir_is_iterable(_0$$3, &_2$$3, &_1$$3, 0, 0, "brisk/Session/SessionFather.zep", 15);
		for (
		  ; zend_hash_get_current_data_ex(_2$$3, (void**) &_3$$3, &_1$$3) == SUCCESS
		  ; zend_hash_move_forward_ex(_2$$3, &_1$$3)
		) {
			ZEPHIR_GET_HMKEY(k$$3, _2$$3, _1$$3);
			ZEPHIR_GET_HVALUE(v$$3, _3$$3);
			ZEPHIR_CALL_FUNCTION(NULL, "ini_set", &_4, 17, k$$3, v$$3);
			zephir_check_call_status();
		}
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Set the session expire time
 *
 * @param int expire_time
 * @return SessionFather
 */
PHP_METHOD(Brisk_Session_SessionFather, setExpireTime) {

	zval *expire_time_param = NULL, *_0;
	zend_long expire_time;

	zephir_fetch_params(0, 0, 1, &expire_time_param);

	if (!expire_time_param) {
		expire_time = 1440;
	} else {
	if (UNEXPECTED(Z_TYPE_P(expire_time_param) != IS_LONG)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'expire_time' must be a int") TSRMLS_CC);
		RETURN_NULL();
	}
	expire_time = Z_LVAL_P(expire_time_param);
	}


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, expire_time);
	zephir_update_property_this(getThis(), SL("_expire_time"), _0 TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Start the session service
 *
 * @param int session_id
 * @return null
 */
PHP_METHOD(Brisk_Session_SessionFather, start) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *session_id_param = NULL, _0;
	zval *session_id = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &session_id_param);

	if (!session_id_param) {
		ZEPHIR_INIT_VAR(session_id);
		ZVAL_STRING(session_id, "", 1);
	} else {
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
	}


	if (!ZEPHIR_IS_STRING(session_id, "")) {
		ZEPHIR_CALL_FUNCTION(NULL, "session_id", NULL, 18, session_id);
		zephir_check_call_status();
	}
	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "private,must-revalidate", 0);
	ZEPHIR_CALL_FUNCTION(NULL, "session_cache_limiter", NULL, 19, &_0);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(NULL, "session_start", NULL, 20);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Get Session data
 *
 * @param string name
 * @return mixed
 */
PHP_METHOD(Brisk_Session_SessionFather, get) {

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
		zephir_array_fetch(&_0, _SESSION, name, PH_NOISY, "brisk/Session/SessionFather.zep", 53 TSRMLS_CC);
	}
	RETURN_CCTOR(_0);

}

/**
 * Set Session data
 *
 * @param string name
 * @param mixed value
 * @return SessionFather
 */
PHP_METHOD(Brisk_Session_SessionFather, set) {

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
 * @return SessionFather
 */
PHP_METHOD(Brisk_Session_SessionFather, delete) {

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
PHP_METHOD(Brisk_Session_SessionFather, clean) {

	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_RETURN_CALL_FUNCTION("session_destroy", NULL, 21);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Brisk_Session_SessionFather, __get) {

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

PHP_METHOD(Brisk_Session_SessionFather, __set) {

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


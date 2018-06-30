
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
#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/operators.h"


ZEPHIR_INIT_CLASS(Brisk_Session_UserSession) {

	ZEPHIR_REGISTER_CLASS_EX(Brisk\\Session, UserSession, brisk, session_usersession, brisk_session_sessionfather_ce, brisk_session_usersession_method_entry, 0);

	zend_declare_property_null(brisk_session_usersession_ce, SL("_container"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_long(brisk_session_usersession_ce, SL("_expire_time"), 86400, ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Brisk_Session_UserSession, __construct) {

	zval _18, _19, _20, _21, _22, _23, _13$$5;
	zval config, _0, _2, _3, _4, _9, _15, _16, _17, _5$$3, _6$$3, _7$$3, _8$$4, _10$$5, _11$$5, _14$$5;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL, *_12 = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&config);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_16);
	ZVAL_UNDEF(&_17);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_14$$5);
	ZVAL_UNDEF(&_18);
	ZVAL_UNDEF(&_19);
	ZVAL_UNDEF(&_20);
	ZVAL_UNDEF(&_21);
	ZVAL_UNDEF(&_22);
	ZVAL_UNDEF(&_23);
	ZVAL_UNDEF(&_13$$5);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_CE_STATIC(&_0, brisk_kernel_app_ce, "getinstance", &_1, 0);
	zephir_check_call_status();
	zephir_read_property(&_2, &_0, SL("config"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_3, &_2, SL("session"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&config, &_3, "getvalue", NULL, 0);
	zephir_check_call_status();
	zephir_array_fetch_string(&_4, &config, SL("save_path"), PH_NOISY | PH_READONLY, "brisk/Session/UserSession.zep", 20 TSRMLS_CC);
	if (zephir_is_callable(&_4 TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(&_5$$3);
		zephir_array_fetch_string(&_6$$3, &config, SL("save_path"), PH_NOISY | PH_READONLY, "brisk/Session/UserSession.zep", 21 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_7$$3);
		array_init(&_7$$3);
		ZEPHIR_CALL_USER_FUNC_ARRAY(&_5$$3, &_6$$3, &_7$$3);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, SL("_container"), &_5$$3);
	} else {
		zephir_array_fetch_string(&_8$$4, &config, SL("save_path"), PH_NOISY | PH_READONLY, "brisk/Session/UserSession.zep", 23 TSRMLS_CC);
		zephir_update_property_zval(this_ptr, SL("_container"), &_8$$4);
	}
	ZEPHIR_OBS_VAR(&_9);
	zephir_read_property(&_9, this_ptr, SL("_container"), PH_NOISY_CC);
	if (!(zephir_instance_of_ev(&_9, brisk_contract_icache_ce TSRMLS_CC))) {
		ZEPHIR_INIT_VAR(&_10$$5);
		object_init_ex(&_10$$5, brisk_exception_sessionexception_ce);
		ZEPHIR_INIT_VAR(&_13$$5);
		zephir_create_array(&_13$$5, 1, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_14$$5);
		ZVAL_STRING(&_14$$5, "\\Brisk\\Contract\\ICache");
		zephir_array_fast_append(&_13$$5, &_14$$5);
		ZEPHIR_INIT_NVAR(&_14$$5);
		ZVAL_STRING(&_14$$5, "sess.cacher_implement_error");
		ZEPHIR_CALL_CE_STATIC(&_11$$5, brisk_kernel_language_ce, "get", &_12, 0, &_14$$5, &_13$$5);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_10$$5, "__construct", NULL, 3, &_11$$5);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_10$$5, "brisk/Session/UserSession.zep", 26 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_read_property(&_15, this_ptr, SL("_container"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_16);
	ZVAL_STRING(&_16, "session");
	ZEPHIR_CALL_METHOD(NULL, &_15, "setflag", NULL, 0, &_16);
	zephir_check_call_status();
	zephir_array_fetch_string(&_17, &config, SL("expire_time"), PH_NOISY | PH_READONLY, "brisk/Session/UserSession.zep", 29 TSRMLS_CC);
	zephir_update_property_zval(this_ptr, SL("_expire_time"), &_17);
	ZEPHIR_INIT_VAR(&_18);
	zephir_create_array(&_18, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(&_18, this_ptr);
	ZEPHIR_INIT_NVAR(&_16);
	ZVAL_STRING(&_16, "open");
	zephir_array_fast_append(&_18, &_16);
	ZEPHIR_INIT_VAR(&_19);
	zephir_create_array(&_19, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(&_19, this_ptr);
	ZEPHIR_INIT_NVAR(&_16);
	ZVAL_STRING(&_16, "close");
	zephir_array_fast_append(&_19, &_16);
	ZEPHIR_INIT_VAR(&_20);
	zephir_create_array(&_20, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(&_20, this_ptr);
	ZEPHIR_INIT_NVAR(&_16);
	ZVAL_STRING(&_16, "read");
	zephir_array_fast_append(&_20, &_16);
	ZEPHIR_INIT_VAR(&_21);
	zephir_create_array(&_21, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(&_21, this_ptr);
	ZEPHIR_INIT_NVAR(&_16);
	ZVAL_STRING(&_16, "write");
	zephir_array_fast_append(&_21, &_16);
	ZEPHIR_INIT_VAR(&_22);
	zephir_create_array(&_22, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(&_22, this_ptr);
	ZEPHIR_INIT_NVAR(&_16);
	ZVAL_STRING(&_16, "destroy");
	zephir_array_fast_append(&_22, &_16);
	ZEPHIR_INIT_VAR(&_23);
	zephir_create_array(&_23, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(&_23, this_ptr);
	ZEPHIR_INIT_NVAR(&_16);
	ZVAL_STRING(&_16, "gc");
	zephir_array_fast_append(&_23, &_16);
	ZEPHIR_CALL_FUNCTION(NULL, "session_set_save_handler", NULL, 77, &_18, &_19, &_20, &_21, &_22, &_23);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Brisk_Session_UserSession, open) {

	zval *save_path_param = NULL, *session_name_param = NULL;
	zval save_path, session_name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&save_path);
	ZVAL_UNDEF(&session_name);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &save_path_param, &session_name_param);

	if (UNEXPECTED(Z_TYPE_P(save_path_param) != IS_STRING && Z_TYPE_P(save_path_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'save_path' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(save_path_param) == IS_STRING)) {
		zephir_get_strval(&save_path, save_path_param);
	} else {
		ZEPHIR_INIT_VAR(&save_path);
		ZVAL_EMPTY_STRING(&save_path);
	}
	if (UNEXPECTED(Z_TYPE_P(session_name_param) != IS_STRING && Z_TYPE_P(session_name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'session_name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(session_name_param) == IS_STRING)) {
		zephir_get_strval(&session_name, session_name_param);
	} else {
		ZEPHIR_INIT_VAR(&session_name);
		ZVAL_EMPTY_STRING(&session_name);
	}


	RETURN_MM_BOOL(1);

}

PHP_METHOD(Brisk_Session_UserSession, close) {

	zval *this_ptr = getThis();


	RETURN_BOOL(1);

}

PHP_METHOD(Brisk_Session_UserSession, read) {

	zval *session_id_param = NULL, _0, _1;
	zend_long session_id, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &session_id_param);

	if (UNEXPECTED(Z_TYPE_P(session_id_param) != IS_LONG)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'session_id' must be a int") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	session_id = Z_LVAL_P(session_id_param);


	zephir_read_property(&_0, this_ptr, SL("_container"), PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_1, session_id);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "get", NULL, 0, &_1);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Brisk_Session_UserSession, write) {

	zval *session_id_param = NULL, *session_data, session_data_sub, _0, _1, _2;
	zend_long session_id, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&session_data_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &session_id_param, &session_data);

	if (UNEXPECTED(Z_TYPE_P(session_id_param) != IS_LONG)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'session_id' must be a int") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	session_id = Z_LVAL_P(session_id_param);


	zephir_read_property(&_0, this_ptr, SL("_container"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_1, this_ptr, SL("_expire_time"), PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_2, session_id);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "set", NULL, 0, &_2, session_data, &_1);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Brisk_Session_UserSession, destroy) {

	zval *session_id_param = NULL, _0, _1;
	zend_long session_id, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &session_id_param);

	if (UNEXPECTED(Z_TYPE_P(session_id_param) != IS_LONG)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'session_id' must be a int") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	session_id = Z_LVAL_P(session_id_param);


	zephir_read_property(&_0, this_ptr, SL("_container"), PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_1, session_id);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "delete", NULL, 0, &_1);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Brisk_Session_UserSession, gc) {

	zval *max_lifetime_param = NULL;
	zend_long max_lifetime;
	zval *this_ptr = getThis();


	zephir_fetch_params(0, 1, 0, &max_lifetime_param);

	if (UNEXPECTED(Z_TYPE_P(max_lifetime_param) != IS_LONG)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'max_lifetime' must be a int") TSRMLS_CC);
		RETURN_NULL();
	}
	max_lifetime = Z_LVAL_P(max_lifetime_param);



}



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
#include "kernel/array.h"
#include "kernel/exception.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/concat.h"
#include "kernel/operators.h"


ZEPHIR_INIT_CLASS(Brisk_Session_Driver_Memcached) {

	ZEPHIR_REGISTER_CLASS_EX(Brisk\\Session\\Driver, Memcached, brisk, session_driver_memcached, brisk_session_sessionfather_ce, brisk_session_driver_memcached_method_entry, 0);

	zend_declare_property_null(brisk_session_driver_memcached_ce, SL("_host"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(brisk_session_driver_memcached_ce, SL("_port"), ZEND_ACC_PRIVATE TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Brisk_Session_Driver_Memcached, __construct) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_2 = NULL, *_9 = NULL;
	zval *option_param = NULL, *_0$$3, *_1$$3 = NULL, *_3$$3, *_4$$3, *server = NULL, *_5, *_6, _7, _8;
	zval *option = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &option_param);

	if (!option_param) {
		ZEPHIR_INIT_VAR(option);
		array_init(option);
	} else {
	option = option_param;
	}


	if (!(zephir_array_isset_string(option, SS("config")))) {
		ZEPHIR_INIT_VAR(_0$$3);
		object_init_ex(_0$$3, brisk_exception_configurationexception_ce);
		ZEPHIR_INIT_VAR(_3$$3);
		ZVAL_STRING(_3$$3, "core.config_not_found", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_INIT_VAR(_4$$3);
		ZVAL_STRING(_4$$3, "session/option/config", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_CE_STATIC(&_1$$3, brisk_kernel_language_ce, "get", &_2, 13, _3$$3, _4$$3);
		zephir_check_temp_parameter(_3$$3);
		zephir_check_temp_parameter(_4$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, _0$$3, "__construct", NULL, 8, _1$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(_0$$3, "brisk/Session/Driver/Memcached.zep", 18 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_OBS_VAR(server);
	zephir_array_fetch_string(&server, option, SL("config"), PH_NOISY, "brisk/Session/Driver/Memcached.zep", 21 TSRMLS_CC);
	zephir_array_fetch_string(&_5, server, SL("host"), PH_NOISY | PH_READONLY, "brisk/Session/Driver/Memcached.zep", 22 TSRMLS_CC);
	zephir_update_property_this(getThis(), SL("_host"), _5 TSRMLS_CC);
	zephir_array_fetch_string(&_6, server, SL("port"), PH_NOISY | PH_READONLY, "brisk/Session/Driver/Memcached.zep", 23 TSRMLS_CC);
	zephir_update_property_this(getThis(), SL("_port"), _6 TSRMLS_CC);
	ZEPHIR_SINIT_VAR(_7);
	ZVAL_STRING(&_7, "session.save_handler", 0);
	ZEPHIR_SINIT_VAR(_8);
	ZVAL_STRING(&_8, "user", 0);
	ZEPHIR_CALL_FUNCTION(NULL, "ini_set", NULL, 17, &_7, &_8);
	zephir_check_call_status();
	ZEPHIR_CALL_PARENT(NULL, brisk_session_driver_memcached_ce, getThis(), "__construct", &_9, 116, option);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Start the session service
 *
 * @param string session_id
 * @return null
 */
PHP_METHOD(Brisk_Session_Driver_Memcached, start) {

	zephir_fcall_cache_entry *_4 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *session_id_param = NULL, *memcached = NULL, *path = NULL, *handler = NULL, *_0, *_1, *_2, *_3;
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


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_host"), PH_NOISY_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_port"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(path);
	ZEPHIR_CONCAT_VSV(path, _0, ":", _1);
	ZEPHIR_INIT_VAR(memcached);
	object_init_ex(memcached, brisk_cache_driver_memcached_ce);
	ZEPHIR_CALL_METHOD(NULL, memcached, "__construct", NULL, 123, path);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_2);
	ZVAL_STRING(_2, "sess", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, memcached, "setflag", NULL, 118, _2);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("_expire_time"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, memcached, "setexpiretime", NULL, 119, _3);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(handler);
	object_init_ex(handler, brisk_session_userhandler_ce);
	ZEPHIR_CALL_METHOD(NULL, handler, "__construct", NULL, 120, memcached);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(NULL, "session_set_save_handler", NULL, 121, handler, ZEPHIR_GLOBAL(global_true));
	zephir_check_call_status();
	ZEPHIR_CALL_PARENT(NULL, brisk_session_driver_memcached_ce, getThis(), "start", &_4, 122, session_id);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}


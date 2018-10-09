
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
#include "kernel/operators.h"


ZEPHIR_INIT_CLASS(Brisk_Session_Driver_FileCache) {

	ZEPHIR_REGISTER_CLASS_EX(Brisk\\Session\\Driver, FileCache, brisk, session_driver_filecache, brisk_session_sessionfather_ce, brisk_session_driver_filecache_method_entry, 0);

	zend_declare_property_null(brisk_session_driver_filecache_ce, SL("_path"), ZEND_ACC_PRIVATE TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Brisk_Session_Driver_FileCache, __construct) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_2 = NULL, *_8 = NULL;
	zval *option_param = NULL, *_0$$3, *_1$$3 = NULL, *_3$$3, *_4$$3, *config = NULL, *_5, _6, _7;
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
		ZEPHIR_CALL_CE_STATIC(&_1$$3, brisk_kernel_language_ce, "get", &_2, 12, _3$$3, _4$$3);
		zephir_check_temp_parameter(_3$$3);
		zephir_check_temp_parameter(_4$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, _0$$3, "__construct", NULL, 7, _1$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(_0$$3, "brisk/Session/Driver/FileCache.zep", 17 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_OBS_VAR(config);
	zephir_array_fetch_string(&config, option, SL("config"), PH_NOISY, "brisk/Session/Driver/FileCache.zep", 20 TSRMLS_CC);
	zephir_array_fetch_string(&_5, config, SL("path"), PH_NOISY | PH_READONLY, "brisk/Session/Driver/FileCache.zep", 21 TSRMLS_CC);
	zephir_update_property_this(getThis(), SL("_path"), _5 TSRMLS_CC);
	ZEPHIR_SINIT_VAR(_6);
	ZVAL_STRING(&_6, "session.save_handler", 0);
	ZEPHIR_SINIT_VAR(_7);
	ZVAL_STRING(&_7, "user", 0);
	ZEPHIR_CALL_FUNCTION(NULL, "ini_set", NULL, 16, &_6, &_7);
	zephir_check_call_status();
	ZEPHIR_CALL_PARENT(NULL, brisk_session_driver_filecache_ce, getThis(), "__construct", &_8, 116, option);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Start the session service
 *
 * @param string session_id
 * @return null
 */
PHP_METHOD(Brisk_Session_Driver_FileCache, start) {

	zephir_fcall_cache_entry *_3 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *session_id_param = NULL, *cache = NULL, *handler = NULL, *_0, *_1, *_2;
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


	ZEPHIR_INIT_VAR(cache);
	object_init_ex(cache, brisk_cache_driver_file_ce);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_path"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, cache, "__construct", NULL, 117, _0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "sess", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, cache, "setflag", NULL, 118, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("_expire_time"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, cache, "setexpiretime", NULL, 119, _2);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(handler);
	object_init_ex(handler, brisk_session_userhandler_ce);
	ZEPHIR_CALL_METHOD(NULL, handler, "__construct", NULL, 120, cache);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(NULL, "session_set_save_handler", NULL, 121, handler, ZEPHIR_GLOBAL(global_true));
	zephir_check_call_status();
	ZEPHIR_CALL_PARENT(NULL, brisk_session_driver_filecache_ce, getThis(), "start", &_3, 122, session_id);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}


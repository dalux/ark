
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
#include "kernel/file.h"
#include "kernel/operators.h"


ZEPHIR_INIT_CLASS(Brisk_Session_FileSession) {

	ZEPHIR_REGISTER_CLASS_EX(Brisk\\Session, FileSession, brisk, session_filesession, brisk_session_sessionfather_ce, brisk_session_filesession_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Brisk_Session_FileSession, __construct) {

	zend_bool _9;
	zval config, _0, _2, _3, _4, _5, _7, _8, _10, _12, _13$$3, _14$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL, *_6 = NULL, *_11 = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&config);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_13$$3);
	ZVAL_UNDEF(&_14$$3);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_CE_STATIC(&_0, brisk_kernel_app_ce, "getinstance", &_1, 0);
	zephir_check_call_status();
	zephir_read_property(&_2, &_0, SL("config"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_3, &_2, SL("session"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&config, &_3, "getvalue", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "session.save_handler");
	ZEPHIR_INIT_VAR(&_5);
	ZVAL_STRING(&_5, "files");
	ZEPHIR_CALL_FUNCTION(NULL, "ini_set", &_6, 23, &_4, &_5);
	zephir_check_call_status();
	zephir_array_fetch_string(&_7, &config, SL("expire_time"), PH_NOISY | PH_READONLY, "brisk/Session/FileSession.zep", 14 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(&_4);
	ZVAL_STRING(&_4, "session.cache_expire");
	ZEPHIR_CALL_FUNCTION(NULL, "ini_set", &_6, 23, &_4, &_7);
	zephir_check_call_status();
	zephir_array_fetch_string(&_8, &config, SL("save_path"), PH_NOISY | PH_READONLY, "brisk/Session/FileSession.zep", 15 TSRMLS_CC);
	_9 = (zephir_file_exists(&_8 TSRMLS_CC) == SUCCESS);
	if (!(_9)) {
		zephir_array_fetch_string(&_12, &config, SL("save_path"), PH_NOISY | PH_READONLY, "brisk/Session/FileSession.zep", 15 TSRMLS_CC);
		ZEPHIR_CALL_CE_STATIC(&_10, brisk_kernel_toolkit_ce, "mkdir", &_11, 0, &_12);
		zephir_check_call_status();
		_9 = zephir_is_true(&_10);
	}
	if (_9) {
		zephir_array_fetch_string(&_13$$3, &config, SL("save_path"), PH_NOISY | PH_READONLY, "brisk/Session/FileSession.zep", 16 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_14$$3);
		ZVAL_STRING(&_14$$3, "session.save_path");
		ZEPHIR_CALL_FUNCTION(NULL, "ini_set", &_6, 23, &_14$$3, &_13$$3);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}



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
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/string.h"
#include "ext/spl/spl_exceptions.h"


ZEPHIR_INIT_CLASS(Brisk_Database_DatabaseToolkit) {

	ZEPHIR_REGISTER_CLASS(Brisk\\Database, DatabaseToolkit, brisk, database_databasetoolkit, brisk_database_databasetoolkit_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Brisk_Database_DatabaseToolkit, parseConnectUrl) {

	zend_bool _14$$5;
	zend_string *_12$$4;
	zend_ulong _11$$4;
	zval _3$$3;
	zephir_fcall_cache_entry *_2 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *url_param = NULL, parsed, config, _5, _6, _7, _8, query, _0$$3, _1$$3, _4$$3, _9$$4, val$$4, expr$$4, *_10$$4, _13$$5, _15$$5, _16$$6, _17$$6;
	zval url;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&url);
	ZVAL_UNDEF(&parsed);
	ZVAL_UNDEF(&config);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&query);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&val$$4);
	ZVAL_UNDEF(&expr$$4);
	ZVAL_UNDEF(&_13$$5);
	ZVAL_UNDEF(&_15$$5);
	ZVAL_UNDEF(&_16$$6);
	ZVAL_UNDEF(&_17$$6);
	ZVAL_UNDEF(&_3$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &url_param);

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


	ZEPHIR_CALL_FUNCTION(&parsed, "parse_url", NULL, 20, &url);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE(&parsed)) {
		ZEPHIR_INIT_VAR(&_0$$3);
		object_init_ex(&_0$$3, brisk_exception_databaseexception_ce);
		ZEPHIR_INIT_VAR(&_3$$3);
		zephir_create_array(&_3$$3, 1, 0 TSRMLS_CC);
		zephir_array_fast_append(&_3$$3, &url);
		ZEPHIR_INIT_VAR(&_4$$3);
		ZVAL_STRING(&_4$$3, "db.invalid_conn_string");
		ZEPHIR_CALL_CE_STATIC(&_1$$3, brisk_kernel_language_ce, "get", &_2, 0, &_4$$3, &_3$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_0$$3, "__construct", NULL, 3, &_1$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_0$$3, "brisk/Database/DatabaseToolkit.zep", 14 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&config);
	zephir_create_array(&config, 6, 0 TSRMLS_CC);
	ZEPHIR_OBS_VAR(&_5);
	zephir_array_fetch_string(&_5, &parsed, SL("scheme"), PH_NOISY, "brisk/Database/DatabaseToolkit.zep", 18 TSRMLS_CC);
	zephir_array_update_string(&config, SL("type"), &_5, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_5);
	zephir_array_fetch_string(&_5, &parsed, SL("host"), PH_NOISY, "brisk/Database/DatabaseToolkit.zep", 19 TSRMLS_CC);
	zephir_array_update_string(&config, SL("host"), &_5, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_5);
	zephir_array_fetch_string(&_5, &parsed, SL("port"), PH_NOISY, "brisk/Database/DatabaseToolkit.zep", 20 TSRMLS_CC);
	zephir_array_update_string(&config, SL("port"), &_5, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_5);
	zephir_array_fetch_string(&_5, &parsed, SL("user"), PH_NOISY, "brisk/Database/DatabaseToolkit.zep", 21 TSRMLS_CC);
	zephir_array_update_string(&config, SL("user"), &_5, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_5);
	zephir_array_fetch_string(&_5, &parsed, SL("pass"), PH_NOISY, "brisk/Database/DatabaseToolkit.zep", 22 TSRMLS_CC);
	zephir_array_update_string(&config, SL("pass"), &_5, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(&_6);
	zephir_array_fetch_string(&_7, &parsed, SL("path"), PH_NOISY | PH_READONLY, "brisk/Database/DatabaseToolkit.zep", 23 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_8);
	ZVAL_STRING(&_8, "/");
	zephir_fast_trim(&_6, &_7, &_8, ZEPHIR_TRIM_BOTH TSRMLS_CC);
	zephir_array_update_string(&config, SL("name"), &_6, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_VAR(&query);
	zephir_array_fetch_string(&query, &parsed, SL("query"), PH_NOISY, "brisk/Database/DatabaseToolkit.zep", 26 TSRMLS_CC);
	if (!ZEPHIR_IS_STRING(&query, "")) {
		ZEPHIR_INIT_VAR(&_9$$4);
		zephir_fast_explode_str(&_9$$4, SL("&"), &query, LONG_MAX TSRMLS_CC);
		ZEPHIR_CPY_WRT(&query, &_9$$4);
		ZEPHIR_INIT_NVAR(&_9$$4);
		zephir_is_iterable(&query, 0, "brisk/Database/DatabaseToolkit.zep", 36);
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&query), _11$$4, _12$$4, _10$$4)
		{
			ZEPHIR_INIT_NVAR(&_9$$4);
			if (_12$$4 != NULL) { 
				ZVAL_STR_COPY(&_9$$4, _12$$4);
			} else {
				ZVAL_LONG(&_9$$4, _11$$4);
			}
			ZEPHIR_INIT_NVAR(&val$$4);
			ZVAL_COPY(&val$$4, _10$$4);
			ZEPHIR_INIT_NVAR(&expr$$4);
			zephir_fast_explode_str(&expr$$4, SL("="), &val$$4, LONG_MAX TSRMLS_CC);
			zephir_array_fetch_long(&_13$$5, &expr$$4, 0, PH_NOISY | PH_READONLY, "brisk/Database/DatabaseToolkit.zep", 32 TSRMLS_CC);
			_14$$5 = zephir_is_true(&_13$$5);
			if (_14$$5) {
				zephir_array_fetch_long(&_15$$5, &expr$$4, 1, PH_NOISY | PH_READONLY, "brisk/Database/DatabaseToolkit.zep", 32 TSRMLS_CC);
				_14$$5 = !ZEPHIR_IS_STRING_IDENTICAL(&_15$$5, "");
			}
			if (_14$$5) {
				zephir_array_fetch_long(&_16$$6, &expr$$4, 1, PH_NOISY | PH_READONLY, "brisk/Database/DatabaseToolkit.zep", 33 TSRMLS_CC);
				ZEPHIR_OBS_NVAR(&_17$$6);
				zephir_array_fetch_long(&_17$$6, &expr$$4, 0, PH_NOISY, "brisk/Database/DatabaseToolkit.zep", 33 TSRMLS_CC);
				zephir_array_update_zval(&config, &_17$$6, &_16$$6, PH_COPY | PH_SEPARATE);
			}
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&val$$4);
		ZEPHIR_INIT_NVAR(&_9$$4);
	}
	RETURN_CCTOR(&config);

}


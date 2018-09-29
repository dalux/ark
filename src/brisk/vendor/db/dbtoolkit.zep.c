
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
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/string.h"
#include "ext/spl/spl_exceptions.h"


ZEPHIR_INIT_CLASS(Brisk_Vendor_Db_DbToolkit) {

	ZEPHIR_REGISTER_CLASS(Brisk\\Vendor\\Db, DbToolkit, brisk, vendor_db_dbtoolkit, brisk_vendor_db_dbtoolkit_method_entry, 0);

	return SUCCESS;

}

/**
 * Parsing database connection strings
 *
 * @param string url
 * @return array
 */
PHP_METHOD(Brisk_Vendor_Db_DbToolkit, parseConnectUrl) {

	zend_bool _14$$5;
	HashTable *_11$$4;
	HashPosition _10$$4;
	zval *_3$$3;
	zephir_fcall_cache_entry *_2 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *url_param = NULL, *parsed = NULL, *config = NULL, *_5 = NULL, *_6, *_7, _8, *query = NULL, *_0$$3, *_1$$3 = NULL, *_4$$3, *_9$$4 = NULL, *val$$4 = NULL, *expr$$4 = NULL, **_12$$4, *_13$$5, *_15$$5, *_16$$6, *_17$$6 = NULL;
	zval *url = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &url_param);

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


	ZEPHIR_CALL_FUNCTION(&parsed, "parse_url", NULL, 72, url);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE(parsed)) {
		ZEPHIR_INIT_VAR(_0$$3);
		object_init_ex(_0$$3, brisk_exception_pdoexception_ce);
		ZEPHIR_INIT_VAR(_3$$3);
		zephir_create_array(_3$$3, 1, 0 TSRMLS_CC);
		zephir_array_fast_append(_3$$3, url);
		ZEPHIR_INIT_VAR(_4$$3);
		ZVAL_STRING(_4$$3, "db.invalid_conn_string", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_CE_STATIC(&_1$$3, brisk_kernel_language_ce, "get", &_2, 27, _4$$3, _3$$3);
		zephir_check_temp_parameter(_4$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, _0$$3, "__construct", NULL, 28, _1$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(_0$$3, "brisk/Vendor/Db/DbToolkit.zep", 20 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(config);
	zephir_create_array(config, 6, 0 TSRMLS_CC);
	ZEPHIR_OBS_VAR(_5);
	zephir_array_fetch_string(&_5, parsed, SL("scheme"), PH_NOISY, "brisk/Vendor/Db/DbToolkit.zep", 24 TSRMLS_CC);
	zephir_array_update_string(&config, SL("type"), &_5, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(_5);
	zephir_array_fetch_string(&_5, parsed, SL("host"), PH_NOISY, "brisk/Vendor/Db/DbToolkit.zep", 25 TSRMLS_CC);
	zephir_array_update_string(&config, SL("host"), &_5, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(_5);
	zephir_array_fetch_string(&_5, parsed, SL("port"), PH_NOISY, "brisk/Vendor/Db/DbToolkit.zep", 26 TSRMLS_CC);
	zephir_array_update_string(&config, SL("port"), &_5, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(_5);
	zephir_array_fetch_string(&_5, parsed, SL("user"), PH_NOISY, "brisk/Vendor/Db/DbToolkit.zep", 27 TSRMLS_CC);
	zephir_array_update_string(&config, SL("user"), &_5, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(_5);
	zephir_array_fetch_string(&_5, parsed, SL("pass"), PH_NOISY, "brisk/Vendor/Db/DbToolkit.zep", 28 TSRMLS_CC);
	zephir_array_update_string(&config, SL("pass"), &_5, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(_6);
	zephir_array_fetch_string(&_7, parsed, SL("path"), PH_NOISY | PH_READONLY, "brisk/Vendor/Db/DbToolkit.zep", 29 TSRMLS_CC);
	ZEPHIR_SINIT_VAR(_8);
	ZVAL_STRING(&_8, "/", 0);
	zephir_fast_trim(_6, _7, &_8, ZEPHIR_TRIM_BOTH TSRMLS_CC);
	zephir_array_update_string(&config, SL("name"), &_6, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_VAR(query);
	zephir_array_fetch_string(&query, parsed, SL("query"), PH_NOISY, "brisk/Vendor/Db/DbToolkit.zep", 32 TSRMLS_CC);
	if (!ZEPHIR_IS_STRING(query, "")) {
		ZEPHIR_INIT_VAR(_9$$4);
		zephir_fast_explode_str(_9$$4, SL("&"), query, LONG_MAX TSRMLS_CC);
		ZEPHIR_CPY_WRT(query, _9$$4);
		ZEPHIR_INIT_NVAR(_9$$4);
		zephir_is_iterable(query, &_11$$4, &_10$$4, 0, 0, "brisk/Vendor/Db/DbToolkit.zep", 42);
		for (
		  ; zend_hash_get_current_data_ex(_11$$4, (void**) &_12$$4, &_10$$4) == SUCCESS
		  ; zend_hash_move_forward_ex(_11$$4, &_10$$4)
		) {
			ZEPHIR_GET_HMKEY(_9$$4, _11$$4, _10$$4);
			ZEPHIR_GET_HVALUE(val$$4, _12$$4);
			ZEPHIR_INIT_NVAR(expr$$4);
			zephir_fast_explode_str(expr$$4, SL("="), val$$4, LONG_MAX TSRMLS_CC);
			zephir_array_fetch_long(&_13$$5, expr$$4, 0, PH_NOISY | PH_READONLY, "brisk/Vendor/Db/DbToolkit.zep", 38 TSRMLS_CC);
			_14$$5 = zephir_is_true(_13$$5);
			if (_14$$5) {
				zephir_array_fetch_long(&_15$$5, expr$$4, 1, PH_NOISY | PH_READONLY, "brisk/Vendor/Db/DbToolkit.zep", 38 TSRMLS_CC);
				_14$$5 = !ZEPHIR_IS_STRING_IDENTICAL(_15$$5, "");
			}
			if (_14$$5) {
				zephir_array_fetch_long(&_16$$6, expr$$4, 1, PH_NOISY | PH_READONLY, "brisk/Vendor/Db/DbToolkit.zep", 39 TSRMLS_CC);
				ZEPHIR_OBS_NVAR(_17$$6);
				zephir_array_fetch_long(&_17$$6, expr$$4, 0, PH_NOISY, "brisk/Vendor/Db/DbToolkit.zep", 39 TSRMLS_CC);
				zephir_array_update_zval(&config, _17$$6, &_16$$6, PH_COPY | PH_SEPARATE);
			}
		}
	}
	RETURN_CCTOR(config);

}


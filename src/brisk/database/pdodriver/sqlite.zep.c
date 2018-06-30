
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
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"


ZEPHIR_INIT_CLASS(Brisk_Database_PdoDriver_Sqlite) {

	ZEPHIR_REGISTER_CLASS_EX(Brisk\\Database\\PdoDriver, Sqlite, brisk, database_pdodriver_sqlite, brisk_database_pdodriver_ce, brisk_database_pdodriver_sqlite_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Brisk_Database_PdoDriver_Sqlite, __construct) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL;
	zval option;
	zval *dsn_param = NULL, *option_param = NULL, __$false, params, _2, _3, _0$$3;
	zval dsn;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&dsn);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&option);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &dsn_param, &option_param);

	if (UNEXPECTED(Z_TYPE_P(dsn_param) != IS_STRING && Z_TYPE_P(dsn_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'dsn' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(dsn_param) == IS_STRING)) {
		zephir_get_strval(&dsn, dsn_param);
	} else {
		ZEPHIR_INIT_VAR(&dsn);
		ZVAL_EMPTY_STRING(&dsn);
	}
	if (!option_param) {
		ZEPHIR_INIT_VAR(&option);
		array_init(&option);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&option, option_param);
	}


	ZEPHIR_INIT_VAR(&params);
	zephir_create_array(&params, 3, 0 TSRMLS_CC);
	add_index_long(&params, 3, 2);
	add_index_long(&params, 11, 1);
	zephir_array_update_long(&params, 20, &__$false, PH_COPY ZEPHIR_DEBUG_PARAMS_DUMMY);
	if (zephir_fast_count_int(&option TSRMLS_CC) > 0) {
		ZEPHIR_INIT_VAR(&_0$$3);
		zephir_fast_array_merge(&_0$$3, &params, &option TSRMLS_CC);
		ZEPHIR_CPY_WRT(&params, &_0$$3);
	}
	ZVAL_NULL(&_2);
	ZVAL_NULL(&_3);
	ZEPHIR_CALL_PARENT(NULL, brisk_database_pdodriver_sqlite_ce, getThis(), "__construct", &_1, 0, &dsn, &_2, &_3, &params);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}


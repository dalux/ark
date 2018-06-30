
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
#include "kernel/array.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"


ZEPHIR_INIT_CLASS(Brisk_Database_PdoDriver_Sqlsrv) {

	ZEPHIR_REGISTER_CLASS_EX(Brisk\\Database\\PdoDriver, Sqlsrv, brisk, database_pdodriver_sqlsrv, brisk_database_pdodriver_ce, brisk_database_pdodriver_sqlsrv_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Brisk_Database_PdoDriver_Sqlsrv, __construct) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL, *_6 = NULL, *_11 = NULL;
	zval option;
	zval *dsn_param = NULL, *option_param = NULL, __$false, database, conn_str, charset, params, _1, _2, _3, _4, _5, _12, _13, _7$$3, _8$$3, _9$$3, _10$$4;
	zval dsn;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&dsn);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&database);
	ZVAL_UNDEF(&conn_str);
	ZVAL_UNDEF(&charset);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_10$$4);
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


	ZEPHIR_CALL_CE_STATIC(&database, brisk_database_databasetoolkit_ce, "parseconnecturl", &_0, 0, &dsn);
	zephir_check_call_status();
	zephir_array_fetch_string(&_1, &database, SL("type"), PH_NOISY | PH_READONLY, "brisk/Database/PdoDriver/Sqlsrv.zep", 15 TSRMLS_CC);
	zephir_array_fetch_string(&_2, &database, SL("host"), PH_NOISY | PH_READONLY, "brisk/Database/PdoDriver/Sqlsrv.zep", 15 TSRMLS_CC);
	zephir_array_fetch_string(&_3, &database, SL("port"), PH_NOISY | PH_READONLY, "brisk/Database/PdoDriver/Sqlsrv.zep", 15 TSRMLS_CC);
	zephir_array_fetch_string(&_4, &database, SL("name"), PH_NOISY | PH_READONLY, "brisk/Database/PdoDriver/Sqlsrv.zep", 15 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_5);
	ZVAL_STRING(&_5, "%s:Server=%s,%s;Database=%s;");
	ZEPHIR_CALL_FUNCTION(&conn_str, "sprintf", &_6, 4, &_5, &_1, &_2, &_3, &_4);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(&charset);
	zephir_array_fetch_string(&charset, &database, SL("charset"), PH_NOISY, "brisk/Database/PdoDriver/Sqlsrv.zep", 16 TSRMLS_CC);
	if (!ZEPHIR_IS_STRING(&charset, "")) {
		ZEPHIR_INIT_VAR(&_7$$3);
		ZVAL_STRING(&_7$$3, "charset=%s");
		ZEPHIR_CALL_FUNCTION(&_8$$3, "sprintf", &_6, 4, &_7$$3, &charset);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_9$$3);
		ZEPHIR_CONCAT_VV(&_9$$3, &conn_str, &_8$$3);
		ZEPHIR_CPY_WRT(&conn_str, &_9$$3);
	}
	ZEPHIR_INIT_VAR(&params);
	zephir_create_array(&params, 3, 0 TSRMLS_CC);
	add_index_long(&params, 3, 2);
	add_index_long(&params, 11, 1);
	zephir_array_update_long(&params, 20, &__$false, PH_COPY ZEPHIR_DEBUG_PARAMS_DUMMY);
	if (zephir_fast_count_int(&option TSRMLS_CC) > 0) {
		ZEPHIR_INIT_VAR(&_10$$4);
		zephir_fast_array_merge(&_10$$4, &params, &option TSRMLS_CC);
		ZEPHIR_CPY_WRT(&params, &_10$$4);
	}
	zephir_array_fetch_string(&_12, &database, SL("user"), PH_NOISY | PH_READONLY, "brisk/Database/PdoDriver/Sqlsrv.zep", 28 TSRMLS_CC);
	zephir_array_fetch_string(&_13, &database, SL("pass"), PH_NOISY | PH_READONLY, "brisk/Database/PdoDriver/Sqlsrv.zep", 28 TSRMLS_CC);
	ZEPHIR_CALL_PARENT(NULL, brisk_database_pdodriver_sqlsrv_ce, getThis(), "__construct", &_11, 0, &conn_str, &_12, &_13, &params);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}


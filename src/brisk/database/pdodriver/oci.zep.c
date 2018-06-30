
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
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"


ZEPHIR_INIT_CLASS(Brisk_Database_PdoDriver_Oci) {

	ZEPHIR_REGISTER_CLASS_EX(Brisk\\Database\\PdoDriver, Oci, brisk, database_pdodriver_oci, brisk_database_pdodriver_ce, brisk_database_pdodriver_oci_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Brisk_Database_PdoDriver_Oci, __construct) {

	zend_bool _2;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL, *_12 = NULL, *_17 = NULL;
	zval option;
	zval *dsn_param = NULL, *option_param = NULL, __$false, database, conn_str, params, _1, _3, _9, _10, _11, charset, _18, _19, _4$$3, _6$$3, _7$$3, _8$$3, _5$$4, _13$$5, _14$$5, _15$$5, _16$$6;
	zval dsn;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&dsn);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&database);
	ZVAL_UNDEF(&conn_str);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&charset);
	ZVAL_UNDEF(&_18);
	ZVAL_UNDEF(&_19);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_13$$5);
	ZVAL_UNDEF(&_14$$5);
	ZVAL_UNDEF(&_15$$5);
	ZVAL_UNDEF(&_16$$6);
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
	ZEPHIR_OBS_VAR(&conn_str);
	zephir_array_fetch_string(&conn_str, &database, SL("host"), PH_NOISY, "brisk/Database/PdoDriver/Oci.zep", 15 TSRMLS_CC);
	zephir_array_fetch_string(&_1, &database, SL("host"), PH_NOISY | PH_READONLY, "brisk/Database/PdoDriver/Oci.zep", 16 TSRMLS_CC);
	_2 = !ZEPHIR_IS_STRING(&_1, "");
	if (_2) {
		zephir_array_fetch_string(&_3, &database, SL("name"), PH_NOISY | PH_READONLY, "brisk/Database/PdoDriver/Oci.zep", 16 TSRMLS_CC);
		_2 = !ZEPHIR_IS_STRING(&_3, "");
	}
	if (_2) {
		zephir_array_fetch_string(&_4$$3, &database, SL("port"), PH_NOISY | PH_READONLY, "brisk/Database/PdoDriver/Oci.zep", 17 TSRMLS_CC);
		if (ZEPHIR_IS_STRING(&_4$$3, "")) {
			ZEPHIR_INIT_VAR(&_5$$4);
			ZVAL_LONG(&_5$$4, 1521);
			zephir_array_update_string(&database, SL("port"), &_5$$4, PH_COPY | PH_SEPARATE);
		}
		zephir_array_fetch_string(&_6$$3, &database, SL("host"), PH_NOISY | PH_READONLY, "brisk/Database/PdoDriver/Oci.zep", 20 TSRMLS_CC);
		zephir_array_fetch_string(&_7$$3, &database, SL("port"), PH_NOISY | PH_READONLY, "brisk/Database/PdoDriver/Oci.zep", 20 TSRMLS_CC);
		zephir_array_fetch_string(&_8$$3, &database, SL("name"), PH_NOISY | PH_READONLY, "brisk/Database/PdoDriver/Oci.zep", 20 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(&conn_str);
		ZEPHIR_CONCAT_SVSVSV(&conn_str, "//", &_6$$3, ":", &_7$$3, "/", &_8$$3);
	}
	zephir_array_fetch_string(&_9, &database, SL("type"), PH_NOISY | PH_READONLY, "brisk/Database/PdoDriver/Oci.zep", 22 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_10);
	ZVAL_STRING(&_10, "%s:dbname=%s;");
	ZEPHIR_CALL_FUNCTION(&_11, "sprintf", &_12, 4, &_10, &_9, &conn_str);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&conn_str, &_11);
	ZEPHIR_OBS_VAR(&charset);
	zephir_array_fetch_string(&charset, &database, SL("charset"), PH_NOISY, "brisk/Database/PdoDriver/Oci.zep", 24 TSRMLS_CC);
	if (!ZEPHIR_IS_STRING(&charset, "")) {
		ZEPHIR_INIT_VAR(&_13$$5);
		ZVAL_STRING(&_13$$5, "charset=%s");
		ZEPHIR_CALL_FUNCTION(&_14$$5, "sprintf", &_12, 4, &_13$$5, &charset);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_15$$5);
		ZEPHIR_CONCAT_VV(&_15$$5, &conn_str, &_14$$5);
		ZEPHIR_CPY_WRT(&conn_str, &_15$$5);
	}
	ZEPHIR_INIT_VAR(&params);
	zephir_create_array(&params, 4, 0 TSRMLS_CC);
	add_index_long(&params, 3, 2);
	add_index_long(&params, 11, 1);
	add_index_long(&params, 8, 2);
	zephir_array_update_long(&params, 20, &__$false, PH_COPY ZEPHIR_DEBUG_PARAMS_DUMMY);
	if (zephir_fast_count_int(&option TSRMLS_CC) > 0) {
		ZEPHIR_INIT_VAR(&_16$$6);
		zephir_fast_array_merge(&_16$$6, &params, &option TSRMLS_CC);
		ZEPHIR_CPY_WRT(&params, &_16$$6);
	}
	zephir_array_fetch_string(&_18, &database, SL("user"), PH_NOISY | PH_READONLY, "brisk/Database/PdoDriver/Oci.zep", 37 TSRMLS_CC);
	zephir_array_fetch_string(&_19, &database, SL("pass"), PH_NOISY | PH_READONLY, "brisk/Database/PdoDriver/Oci.zep", 37 TSRMLS_CC);
	ZEPHIR_CALL_PARENT(NULL, brisk_database_pdodriver_oci_ce, getThis(), "__construct", &_17, 0, &conn_str, &_18, &_19, &params);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}


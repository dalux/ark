
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
#include "kernel/object.h"
#include "ext/pdo/php_pdo_driver.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/operators.h"
#include "kernel/string.h"
#include "kernel/concat.h"


ZEPHIR_INIT_CLASS(Brisk_Vendor_Database_Pdo) {

	ZEPHIR_REGISTER_CLASS_EX(Brisk\\Vendor\\Database, Pdo, brisk, vendor_database_pdo, brisk_vendor_database_dbfather_ce, brisk_vendor_database_pdo_method_entry, 0);

	zend_declare_property_null(brisk_vendor_database_pdo_ce, SL("_instance"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_long(brisk_vendor_database_pdo_ce, SL("_fetch_mode"), 2, ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_long(brisk_vendor_database_pdo_ce, SL("_row_count"), 0, ZEND_ACC_PRIVATE TSRMLS_CC);

	return SUCCESS;

}

/**
 * Construct
 *
 * @param string dsn
 * @param array option
 * @return null
 */
PHP_METHOD(Brisk_Vendor_Database_Pdo, __construct) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL, *_3 = NULL;
	zval *option = NULL;
	zval *dsn_param = NULL, *option_param = NULL, *e = NULL, *_5, *_1$$3 = NULL, *instance$$3 = NULL, *data$$3 = NULL, *_2$$3 = NULL, *_4$$3, *_6$$4, *_7$$4 = NULL;
	zval *dsn = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &dsn_param, &option_param);

	if (UNEXPECTED(Z_TYPE_P(dsn_param) != IS_STRING && Z_TYPE_P(dsn_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'dsn' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(dsn_param) == IS_STRING)) {
		zephir_get_strval(dsn, dsn_param);
	} else {
		ZEPHIR_INIT_VAR(dsn);
		ZVAL_EMPTY_STRING(dsn);
	}
	if (!option_param) {
		ZEPHIR_INIT_VAR(option);
		array_init(option);
	} else {
	option = option_param;
	}



	/* try_start_1: */

		ZEPHIR_INIT_VAR(_1$$3);
		ZVAL_STRING(_1$$3, "db_connect_begin", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_CE_STATIC(NULL, brisk_kernel_timer_ce, "mark", &_0, 11, _1$$3);
		zephir_check_temp_parameter(_1$$3);
		zephir_check_call_status_or_jump(try_end_1);
		ZEPHIR_CALL_METHOD(&instance$$3, this_ptr, "_getconnection", NULL, 106, dsn, option);
		zephir_check_call_status_or_jump(try_end_1);
		ZEPHIR_INIT_NVAR(_1$$3);
		ZVAL_STRING(_1$$3, "db_connect_end", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_CE_STATIC(NULL, brisk_kernel_timer_ce, "mark", &_0, 11, _1$$3);
		zephir_check_temp_parameter(_1$$3);
		zephir_check_call_status_or_jump(try_end_1);
		ZEPHIR_INIT_VAR(data$$3);
		zephir_create_array(data$$3, 3, 0 TSRMLS_CC);
		zephir_array_update_string(&data$$3, SL("container"), &this_ptr, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&data$$3, SL("instance"), &instance$$3, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(_1$$3);
		ZVAL_LONG(_1$$3, 16);
		ZEPHIR_CALL_METHOD(&_2$$3, instance$$3, "getattribute", NULL, 0, _1$$3);
		zephir_check_call_status_or_jump(try_end_1);
		zephir_array_update_string(&data$$3, SL("driver"), &_2$$3, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(_1$$3);
		ZVAL_STRING(_1$$3, "event.dbconnect.finish", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_CE_STATIC(&_2$$3, brisk_kernel_event_ce, "fire", &_3, 32, _1$$3, data$$3);
		zephir_check_temp_parameter(_1$$3);
		zephir_check_call_status_or_jump(try_end_1);
		ZEPHIR_CPY_WRT(data$$3, _2$$3);
		zephir_array_fetch_string(&_4$$3, data$$3, SL("instance"), PH_NOISY | PH_READONLY, "brisk/Vendor/Database/Pdo.zep", 39 TSRMLS_CC);
		zephir_update_property_this(getThis(), SL("_instance"), _4$$3 TSRMLS_CC);

	try_end_1:

	if (EG(exception)) {
		ZEPHIR_INIT_VAR(_5);
		ZEPHIR_CPY_WRT(_5, EG(exception));
		if (zephir_instance_of_ev(_5, php_pdo_get_exception() TSRMLS_CC)) {
			zend_clear_exception(TSRMLS_C);
			ZEPHIR_CPY_WRT(e, _5);
			ZEPHIR_INIT_VAR(_6$$4);
			object_init_ex(_6$$4, brisk_exception_pdoexception_ce);
			ZEPHIR_CALL_METHOD(&_7$$4, e, "getmessage", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, _6$$4, "__construct", NULL, 28, _7$$4);
			zephir_check_call_status();
			zephir_throw_exception_debug(_6$$4, "brisk/Vendor/Database/Pdo.zep", 41 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Execute a sql with bind options
 *
 * @param string sql
 * @param array bind
 * @return mixed
 */
PHP_METHOD(Brisk_Vendor_Database_Pdo, query) {

	zend_bool result = 0;
	zephir_fcall_cache_entry *_1 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *bind = NULL;
	zval *sql_param = NULL, *bind_param = NULL, *data = NULL, *_0 = NULL, *_2 = NULL, *smt = NULL, *_3, *_4, *_5, *_6;
	zval *sql = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &sql_param, &bind_param);

	if (UNEXPECTED(Z_TYPE_P(sql_param) != IS_STRING && Z_TYPE_P(sql_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'sql' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(sql_param) == IS_STRING)) {
		zephir_get_strval(sql, sql_param);
	} else {
		ZEPHIR_INIT_VAR(sql);
		ZVAL_EMPTY_STRING(sql);
	}
	if (!bind_param) {
		ZEPHIR_INIT_VAR(bind);
		array_init(bind);
	} else {
	bind = bind_param;
	}


	ZEPHIR_INIT_VAR(data);
	zephir_create_array(data, 4, 0 TSRMLS_CC);
	add_assoc_stringl_ex(data, SS("method"), SL("Pdo:query"), 1);
	zephir_array_update_string(&data, SL("sql"), &sql, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&data, SL("bind"), &bind, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getdrivername", NULL, 0);
	zephir_check_call_status();
	zephir_array_update_string(&data, SL("driver"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_STRING(_2, "event.query.before", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_CE_STATIC(&_0, brisk_kernel_event_ce, "fire", &_1, 32, _2, data);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(data, _0);
	zephir_array_fetch_string(&_3, data, SL("sql"), PH_NOISY | PH_READONLY, "brisk/Vendor/Database/Pdo.zep", 63 TSRMLS_CC);
	zephir_array_fetch_string(&_4, data, SL("bind"), PH_NOISY | PH_READONLY, "brisk/Vendor/Database/Pdo.zep", 63 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&smt, this_ptr, "_query", NULL, 107, _3, _4);
	zephir_check_call_status();
	result = 1;
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_BOOL(_2, result);
	zephir_array_update_string(&data, SL("result"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(_5);
	ZVAL_STRING(_5, "event.query.finish", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_CE_STATIC(&_0, brisk_kernel_event_ce, "fire", &_1, 32, _5, data);
	zephir_check_temp_parameter(_5);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(data, _0);
	zephir_array_fetch_string(&_6, data, SL("result"), PH_NOISY | PH_READONLY, "brisk/Vendor/Database/Pdo.zep", 67 TSRMLS_CC);
	RETURN_CTOR(_6);

}

/**
 * Execute fetchAll method with bind options
 *
 * @param string sql
 * @param array bind
 * @return array
 */
PHP_METHOD(Brisk_Vendor_Database_Pdo, fetchAll) {

	zephir_fcall_cache_entry *_1 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *bind = NULL;
	zval *sql_param = NULL, *bind_param = NULL, *data = NULL, *_0 = NULL, *_2 = NULL, *smt = NULL, *result = NULL, *_3, *_4, *_5, *_6;
	zval *sql = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &sql_param, &bind_param);

	if (UNEXPECTED(Z_TYPE_P(sql_param) != IS_STRING && Z_TYPE_P(sql_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'sql' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(sql_param) == IS_STRING)) {
		zephir_get_strval(sql, sql_param);
	} else {
		ZEPHIR_INIT_VAR(sql);
		ZVAL_EMPTY_STRING(sql);
	}
	if (!bind_param) {
		ZEPHIR_INIT_VAR(bind);
		array_init(bind);
	} else {
	bind = bind_param;
	}


	ZEPHIR_INIT_VAR(data);
	zephir_create_array(data, 4, 0 TSRMLS_CC);
	add_assoc_stringl_ex(data, SS("method"), SL("Pdo:fetchAll"), 1);
	zephir_array_update_string(&data, SL("sql"), &sql, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&data, SL("bind"), &bind, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getdrivername", NULL, 0);
	zephir_check_call_status();
	zephir_array_update_string(&data, SL("driver"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_STRING(_2, "event.query.before", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_CE_STATIC(&_0, brisk_kernel_event_ce, "fire", &_1, 32, _2, data);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(data, _0);
	zephir_array_fetch_string(&_3, data, SL("sql"), PH_NOISY | PH_READONLY, "brisk/Vendor/Database/Pdo.zep", 88 TSRMLS_CC);
	zephir_array_fetch_string(&_4, data, SL("bind"), PH_NOISY | PH_READONLY, "brisk/Vendor/Database/Pdo.zep", 88 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&smt, this_ptr, "_query", NULL, 107, _3, _4);
	zephir_check_call_status();
	_5 = zephir_fetch_nproperty_this(this_ptr, SL("_fetch_mode"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&result, smt, "fetchall", NULL, 0, _5);
	zephir_check_call_status();
	zephir_array_update_string(&data, SL("result"), &result, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "event.query.finish", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_CE_STATIC(&_0, brisk_kernel_event_ce, "fire", &_1, 32, _2, data);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(data, _0);
	zephir_array_fetch_string(&_6, data, SL("result"), PH_NOISY | PH_READONLY, "brisk/Vendor/Database/Pdo.zep", 92 TSRMLS_CC);
	RETURN_CTOR(_6);

}

/**
 * Execute fetchOne method with bind options
 *
 * @param string sql
 * @param array bind
 * @return mixed
 */
PHP_METHOD(Brisk_Vendor_Database_Pdo, fetchOne) {

	zephir_fcall_cache_entry *_1 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *bind = NULL;
	zval *sql_param = NULL, *bind_param = NULL, *data = NULL, *smt = NULL, *result = NULL, *_0 = NULL, *_2 = NULL, *_3, *_4, *_5;
	zval *sql = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &sql_param, &bind_param);

	if (UNEXPECTED(Z_TYPE_P(sql_param) != IS_STRING && Z_TYPE_P(sql_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'sql' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(sql_param) == IS_STRING)) {
		zephir_get_strval(sql, sql_param);
	} else {
		ZEPHIR_INIT_VAR(sql);
		ZVAL_EMPTY_STRING(sql);
	}
	if (!bind_param) {
		ZEPHIR_INIT_VAR(bind);
		array_init(bind);
	} else {
	bind = bind_param;
	}


	ZEPHIR_INIT_VAR(data);
	zephir_create_array(data, 4, 0 TSRMLS_CC);
	add_assoc_stringl_ex(data, SS("method"), SL("Pdo:fetchOne"), 1);
	zephir_array_update_string(&data, SL("sql"), &sql, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&data, SL("bind"), &bind, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getdrivername", NULL, 0);
	zephir_check_call_status();
	zephir_array_update_string(&data, SL("driver"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_STRING(_2, "event.query.before", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_CE_STATIC(&_0, brisk_kernel_event_ce, "fire", &_1, 32, _2, data);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(data, _0);
	zephir_array_fetch_string(&_3, data, SL("sql"), PH_NOISY | PH_READONLY, "brisk/Vendor/Database/Pdo.zep", 112 TSRMLS_CC);
	zephir_array_fetch_string(&_4, data, SL("bind"), PH_NOISY | PH_READONLY, "brisk/Vendor/Database/Pdo.zep", 112 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&smt, this_ptr, "_query", NULL, 107, _3, _4);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_LONG(_2, 0);
	ZEPHIR_CALL_METHOD(&result, smt, "fetchcolumn", NULL, 0, _2);
	zephir_check_call_status();
	zephir_array_update_string(&data, SL("result"), &result, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "event.query.finish", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_CE_STATIC(&_0, brisk_kernel_event_ce, "fire", &_1, 32, _2, data);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(data, _0);
	zephir_array_fetch_string(&_5, data, SL("result"), PH_NOISY | PH_READONLY, "brisk/Vendor/Database/Pdo.zep", 116 TSRMLS_CC);
	RETURN_CTOR(_5);

}

/**
 * Execute fetchRow method with bind options
 *
 * @param string sql
 * @param array bind
 * @return array
 */
PHP_METHOD(Brisk_Vendor_Database_Pdo, fetchRow) {

	zephir_fcall_cache_entry *_1 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *bind = NULL;
	zval *sql_param = NULL, *bind_param = NULL, *data = NULL, *_0 = NULL, *_2 = NULL, *smt = NULL, *result = NULL, *func = NULL, *_3, *_4, *_5, *_6;
	zval *sql = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &sql_param, &bind_param);

	if (UNEXPECTED(Z_TYPE_P(sql_param) != IS_STRING && Z_TYPE_P(sql_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'sql' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(sql_param) == IS_STRING)) {
		zephir_get_strval(sql, sql_param);
	} else {
		ZEPHIR_INIT_VAR(sql);
		ZVAL_EMPTY_STRING(sql);
	}
	if (!bind_param) {
		ZEPHIR_INIT_VAR(bind);
		array_init(bind);
	} else {
	bind = bind_param;
	}


	ZEPHIR_INIT_VAR(data);
	zephir_create_array(data, 4, 0 TSRMLS_CC);
	add_assoc_stringl_ex(data, SS("method"), SL("Pdo:fetchRow"), 1);
	zephir_array_update_string(&data, SL("sql"), &sql, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&data, SL("bind"), &bind, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getdrivername", NULL, 0);
	zephir_check_call_status();
	zephir_array_update_string(&data, SL("driver"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_STRING(_2, "event.query.before", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_CE_STATIC(&_0, brisk_kernel_event_ce, "fire", &_1, 32, _2, data);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(data, _0);
	zephir_array_fetch_string(&_3, data, SL("sql"), PH_NOISY | PH_READONLY, "brisk/Vendor/Database/Pdo.zep", 137 TSRMLS_CC);
	zephir_array_fetch_string(&_4, data, SL("bind"), PH_NOISY | PH_READONLY, "brisk/Vendor/Database/Pdo.zep", 137 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&smt, this_ptr, "_query", NULL, 107, _3, _4);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(func);
	ZVAL_STRING(func, "fetch", 1);
	_5 = zephir_fetch_nproperty_this(this_ptr, SL("_fetch_mode"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD_ZVAL(&result, smt, func, NULL, 0, _5);
	zephir_check_call_status();
	zephir_array_update_string(&data, SL("result"), &result, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "event.query.finish", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_CE_STATIC(&_0, brisk_kernel_event_ce, "fire", &_1, 32, _2, data);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(data, _0);
	zephir_array_fetch_string(&_6, data, SL("result"), PH_NOISY | PH_READONLY, "brisk/Vendor/Database/Pdo.zep", 142 TSRMLS_CC);
	RETURN_CTOR(_6);

}

/**
 * Start a new Transaction
 *
 * @return bool
 */
PHP_METHOD(Brisk_Vendor_Database_Pdo, beginTransaction) {

	zval *_0;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_instance"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_0, "begintransaction", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Commit a Transaction
 *
 * @return bool
 */
PHP_METHOD(Brisk_Vendor_Database_Pdo, commit) {

	zval *_0;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_instance"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_0, "commit", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Rollback a Transaction
 *
 * @return bool
 */
PHP_METHOD(Brisk_Vendor_Database_Pdo, rollback) {

	zval *_0;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_instance"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_0, "rollback", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Check if the current sql is in a transaction
 *
 * @return bool
 */
PHP_METHOD(Brisk_Vendor_Database_Pdo, inTransaction) {

	zval *_0;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_instance"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_0, "intransaction", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Get next id
 *
 * @return int
 */
PHP_METHOD(Brisk_Vendor_Database_Pdo, nextInsertId) {

	

	RETURN_NULL();

}

/**
 * Get last insert id
 *
 * @param string seq
 * @return int
 */
PHP_METHOD(Brisk_Vendor_Database_Pdo, lastInsertId) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *seq_param = NULL, *_0;
	zval *seq = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &seq_param);

	if (!seq_param) {
		ZEPHIR_INIT_VAR(seq);
		ZVAL_STRING(seq, "", 1);
	} else {
	if (UNEXPECTED(Z_TYPE_P(seq_param) != IS_STRING && Z_TYPE_P(seq_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'seq' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(seq_param) == IS_STRING)) {
		zephir_get_strval(seq, seq_param);
	} else {
		ZEPHIR_INIT_VAR(seq);
		ZVAL_EMPTY_STRING(seq);
	}
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_instance"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_0, "lastinsertid", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Gets the number of rows as a result of the last sql execution
 *
 * @return int
 */
PHP_METHOD(Brisk_Vendor_Database_Pdo, lastRowCount) {

	

	RETURN_MEMBER(getThis(), "_row_count");

}

/**
 * Set Pdo fetch mode
 *
 * @param int mode
 * @return Pdo
 */
PHP_METHOD(Brisk_Vendor_Database_Pdo, setFetchMode) {

	zval *mode_param = NULL, *_0;
	zend_long mode;

	zephir_fetch_params(0, 1, 0, &mode_param);

	if (UNEXPECTED(Z_TYPE_P(mode_param) != IS_LONG)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'mode' must be a int") TSRMLS_CC);
		RETURN_NULL();
	}
	mode = Z_LVAL_P(mode_param);


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, mode);
	zephir_update_property_this(getThis(), SL("_fetch_mode"), _0 TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Get current driver name
 *
 * @return string
 */
PHP_METHOD(Brisk_Vendor_Database_Pdo, getDriverName) {

	zval *_0, *_1;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_instance"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_LONG(_1, 16);
	ZEPHIR_RETURN_CALL_METHOD(_0, "getattribute", NULL, 0, _1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Get pdo instance
 *
 * @return \PDO
 */
PHP_METHOD(Brisk_Vendor_Database_Pdo, getInstance) {

	

	RETURN_MEMBER(getThis(), "_instance");

}

PHP_METHOD(Brisk_Vendor_Database_Pdo, _query) {

	HashTable *_5$$4;
	HashPosition _4$$4;
	zend_long ZEPHIR_LAST_CALL_STATUS, _7$$6;
	zephir_fcall_cache_entry *_0 = NULL, *_9 = NULL, *_12 = NULL, *_16 = NULL, *_22 = NULL;
	zval *bind = NULL, *_13$$3;
	zval *sql_param = NULL, *bind_param = NULL, *e = NULL, *smt = NULL, *_19, *_1$$3 = NULL, *_2$$3, *_10$$3, *_11$$3 = NULL, *_14$$3, *_15$$3 = NULL, _17$$3, *_18$$3 = NULL, *key$$4 = NULL, *_3$$4 = NULL, **_6$$4, *_8$$5, *data$$7 = NULL, *_20$$7, *_21$$7 = NULL, *_23$$7 = NULL, *_24$$7;
	zval *sql = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &sql_param, &bind_param);

	if (UNEXPECTED(Z_TYPE_P(sql_param) != IS_STRING && Z_TYPE_P(sql_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'sql' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(sql_param) == IS_STRING)) {
		zephir_get_strval(sql, sql_param);
	} else {
		ZEPHIR_INIT_VAR(sql);
		ZVAL_EMPTY_STRING(sql);
	}
	if (!bind_param) {
		ZEPHIR_INIT_VAR(bind);
		array_init(bind);
	} else {
	bind = bind_param;
	}



	/* try_start_1: */

		ZEPHIR_INIT_VAR(_1$$3);
		ZVAL_STRING(_1$$3, "db_query_begin", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_CE_STATIC(NULL, brisk_kernel_timer_ce, "mark", &_0, 11, _1$$3);
		zephir_check_temp_parameter(_1$$3);
		zephir_check_call_status_or_jump(try_end_1);
		_2$$3 = zephir_fetch_nproperty_this(this_ptr, SL("_instance"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&smt, _2$$3, "prepare", NULL, 0, sql);
		zephir_check_call_status_or_jump(try_end_1);
		if (zephir_fast_count_int(bind TSRMLS_CC) > 0) {
			ZEPHIR_INIT_VAR(_3$$4);
			zephir_is_iterable(bind, &_5$$4, &_4$$4, 0, 0, "brisk/Vendor/Database/Pdo.zep", 263);
			for (
			  ; zend_hash_get_current_data_ex(_5$$4, (void**) &_6$$4, &_4$$4) == SUCCESS
			  ; zend_hash_move_forward_ex(_5$$4, &_4$$4)
			) {
				ZEPHIR_GET_HMKEY(key$$4, _5$$4, _4$$4);
				ZEPHIR_GET_HVALUE(_3$$4, _6$$4);
				if (!(Z_TYPE_P(key$$4) == IS_STRING)) {
					_7$$6 = (zephir_get_numberval(key$$4) + 1);
					ZEPHIR_INIT_NVAR(key$$4);
					ZVAL_LONG(key$$4, _7$$6);
				}
				zephir_array_fetch(&_8$$5, bind, key$$4, PH_NOISY | PH_READONLY, "brisk/Vendor/Database/Pdo.zep", 261 TSRMLS_CC);
				ZEPHIR_CALL_METHOD(NULL, smt, "bindparam", &_9, 0, key$$4, _8$$5);
				zephir_check_call_status_or_jump(try_end_1);
			}
		}
		ZEPHIR_CALL_METHOD(NULL, smt, "execute", NULL, 0);
		zephir_check_call_status_or_jump(try_end_1);
		_10$$3 = zephir_fetch_nproperty_this(this_ptr, SL("_fetch_mode"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(NULL, smt, "setfetchmode", NULL, 0, _10$$3);
		zephir_check_call_status_or_jump(try_end_1);
		ZEPHIR_CALL_METHOD(&_11$$3, smt, "rowcount", NULL, 0);
		zephir_check_call_status_or_jump(try_end_1);
		zephir_update_property_this(getThis(), SL("_row_count"), _11$$3 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(_1$$3);
		ZVAL_STRING(_1$$3, "db_query_end", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_CE_STATIC(NULL, brisk_kernel_timer_ce, "mark", &_0, 11, _1$$3);
		zephir_check_temp_parameter(_1$$3);
		zephir_check_call_status_or_jump(try_end_1);
		ZEPHIR_INIT_VAR(_13$$3);
		zephir_create_array(_13$$3, 2, 0 TSRMLS_CC);
		ZEPHIR_OBS_VAR(_14$$3);
		zephir_read_property(&_14$$3, smt, SL("queryString"), PH_NOISY_CC);
		zephir_array_fast_append(_13$$3, _14$$3);
		ZEPHIR_CALL_CE_STATIC(&_15$$3, brisk_kernel_timer_ce, "lastused", &_16, 108);
		zephir_check_call_status_or_jump(try_end_1);
		ZEPHIR_SINIT_VAR(_17$$3);
		ZVAL_STRING(&_17$$3, "%.4f", 0);
		ZEPHIR_CALL_FUNCTION(&_18$$3, "sprintf", NULL, 40, &_17$$3, _15$$3);
		zephir_check_call_status_or_jump(try_end_1);
		zephir_array_fast_append(_13$$3, _18$$3);
		ZEPHIR_INIT_NVAR(_1$$3);
		ZVAL_STRING(_1$$3, "database", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_CE_STATIC(NULL, brisk_kernel_trace_ce, "set", &_12, 12, _1$$3, _13$$3);
		zephir_check_temp_parameter(_1$$3);
		zephir_check_call_status_or_jump(try_end_1);
		RETURN_CCTOR(smt);

	try_end_1:

	if (EG(exception)) {
		ZEPHIR_INIT_VAR(_19);
		ZEPHIR_CPY_WRT(_19, EG(exception));
		if (zephir_instance_of_ev(_19, php_pdo_get_exception() TSRMLS_CC)) {
			zend_clear_exception(TSRMLS_C);
			ZEPHIR_CPY_WRT(e, _19);
			ZEPHIR_INIT_VAR(data$$7);
			zephir_create_array(data$$7, 3, 0 TSRMLS_CC);
			ZEPHIR_OBS_VAR(_20$$7);
			zephir_read_property(&_20$$7, smt, SL("queryString"), PH_NOISY_CC);
			zephir_array_update_string(&data$$7, SL("sql"), &_20$$7, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(&_21$$7, e, "getmessage", NULL, 0);
			zephir_check_call_status();
			zephir_array_update_string(&data$$7, SL("error"), &_21$$7, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(&_21$$7, this_ptr, "getdrivername", NULL, 0);
			zephir_check_call_status();
			zephir_array_update_string(&data$$7, SL("driver"), &_21$$7, PH_COPY | PH_SEPARATE);
			ZEPHIR_INIT_VAR(_23$$7);
			ZVAL_STRING(_23$$7, "event.query.failed", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_CE_STATIC(&_21$$7, brisk_kernel_event_ce, "fire", &_22, 32, _23$$7, data$$7);
			zephir_check_temp_parameter(_23$$7);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(data$$7, _21$$7);
			ZEPHIR_INIT_NVAR(_23$$7);
			object_init_ex(_23$$7, brisk_exception_pdoexception_ce);
			zephir_array_fetch_string(&_24$$7, data$$7, SL("error"), PH_NOISY | PH_READONLY, "brisk/Vendor/Database/Pdo.zep", 278 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(NULL, _23$$7, "__construct", NULL, 28, _24$$7);
			zephir_check_call_status();
			zephir_throw_exception_debug(_23$$7, "brisk/Vendor/Database/Pdo.zep", 278 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Brisk_Vendor_Database_Pdo, _getConnection) {

	zend_bool _4$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL, *_14 = NULL;
	zval *option = NULL;
	zval *dsn_param = NULL, *option_param = NULL, *database = NULL, *conn_str = NULL, *params = NULL, *charset = NULL, *_1, *_2, *instance = NULL, *_43, *_44, *_3$$3, *_5$$3, *_11$$3, _12$$3, *_13$$3 = NULL, *_6$$4, *_8$$4, *_9$$4, *_10$$4, *_7$$5, _15$$6, *_16$$6 = NULL, *_17$$6, *_18$$7, *_19$$7, *_20$$7, *_21$$7, _22$$7, _23$$8, *_24$$8 = NULL, *_25$$8, *_26$$9, *_27$$9, *_28$$9, *_29$$9, _30$$9, _31$$10, *_32$$10 = NULL, *_33$$10, *_34$$12, *_35$$12, *_36$$12, *_37$$12, _38$$12, _39$$13, *_40$$13 = NULL, *_41$$13, *_42$$14;
	zval *dsn = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &dsn_param, &option_param);

	if (UNEXPECTED(Z_TYPE_P(dsn_param) != IS_STRING && Z_TYPE_P(dsn_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'dsn' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(dsn_param) == IS_STRING)) {
		zephir_get_strval(dsn, dsn_param);
	} else {
		ZEPHIR_INIT_VAR(dsn);
		ZVAL_EMPTY_STRING(dsn);
	}
	if (!option_param) {
		ZEPHIR_INIT_VAR(option);
		array_init(option);
	} else {
	option = option_param;
	}


	ZEPHIR_CALL_CE_STATIC(&database, brisk_vendor_database_dbtoolkit_ce, "parseconnecturl", &_0, 109, dsn);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_1);
	zephir_array_fetch_string(&_2, database, SL("type"), PH_NOISY | PH_READONLY, "brisk/Vendor/Database/Pdo.zep", 286 TSRMLS_CC);
	zephir_fast_strtolower(_1, _2);
	do {
		if (ZEPHIR_IS_STRING(_1, "oci")) {
			ZEPHIR_OBS_VAR(conn_str);
			zephir_array_fetch_string(&conn_str, database, SL("host"), PH_NOISY, "brisk/Vendor/Database/Pdo.zep", 288 TSRMLS_CC);
			zephir_array_fetch_string(&_3$$3, database, SL("host"), PH_NOISY | PH_READONLY, "brisk/Vendor/Database/Pdo.zep", 289 TSRMLS_CC);
			_4$$3 = !ZEPHIR_IS_STRING(_3$$3, "");
			if (_4$$3) {
				zephir_array_fetch_string(&_5$$3, database, SL("name"), PH_NOISY | PH_READONLY, "brisk/Vendor/Database/Pdo.zep", 289 TSRMLS_CC);
				_4$$3 = !ZEPHIR_IS_STRING(_5$$3, "");
			}
			if (_4$$3) {
				zephir_array_fetch_string(&_6$$4, database, SL("port"), PH_NOISY | PH_READONLY, "brisk/Vendor/Database/Pdo.zep", 290 TSRMLS_CC);
				if (ZEPHIR_IS_STRING(_6$$4, "")) {
					ZEPHIR_INIT_VAR(_7$$5);
					ZVAL_LONG(_7$$5, 1521);
					zephir_array_update_string(&database, SL("port"), &_7$$5, PH_COPY | PH_SEPARATE);
				}
				zephir_array_fetch_string(&_8$$4, database, SL("host"), PH_NOISY | PH_READONLY, "brisk/Vendor/Database/Pdo.zep", 293 TSRMLS_CC);
				zephir_array_fetch_string(&_9$$4, database, SL("port"), PH_NOISY | PH_READONLY, "brisk/Vendor/Database/Pdo.zep", 293 TSRMLS_CC);
				zephir_array_fetch_string(&_10$$4, database, SL("name"), PH_NOISY | PH_READONLY, "brisk/Vendor/Database/Pdo.zep", 293 TSRMLS_CC);
				ZEPHIR_INIT_NVAR(conn_str);
				ZEPHIR_CONCAT_SVSVSV(conn_str, "//", _8$$4, ":", _9$$4, "/", _10$$4);
			}
			zephir_array_fetch_string(&_11$$3, database, SL("type"), PH_NOISY | PH_READONLY, "brisk/Vendor/Database/Pdo.zep", 295 TSRMLS_CC);
			ZEPHIR_SINIT_VAR(_12$$3);
			ZVAL_STRING(&_12$$3, "%s:dbname=%s;", 0);
			ZEPHIR_CALL_FUNCTION(&_13$$3, "sprintf", &_14, 40, &_12$$3, _11$$3, conn_str);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(conn_str, _13$$3);
			ZEPHIR_OBS_VAR(charset);
			zephir_array_fetch_string(&charset, database, SL("charset"), PH_NOISY, "brisk/Vendor/Database/Pdo.zep", 296 TSRMLS_CC);
			if (!ZEPHIR_IS_STRING(charset, "")) {
				ZEPHIR_SINIT_VAR(_15$$6);
				ZVAL_STRING(&_15$$6, "charset=%s", 0);
				ZEPHIR_CALL_FUNCTION(&_16$$6, "sprintf", &_14, 40, &_15$$6, charset);
				zephir_check_call_status();
				ZEPHIR_INIT_VAR(_17$$6);
				ZEPHIR_CONCAT_VV(_17$$6, conn_str, _16$$6);
				ZEPHIR_CPY_WRT(conn_str, _17$$6);
			}
			ZEPHIR_INIT_VAR(params);
			zephir_create_array(params, 4, 0 TSRMLS_CC);
			add_index_long(params, 3, 2);
			add_index_long(params, 11, 1);
			add_index_long(params, 8, 2);
			zephir_array_update_long(&params, 20, &ZEPHIR_GLOBAL(global_false), PH_COPY ZEPHIR_DEBUG_PARAMS_DUMMY);
			break;
		}
		if (ZEPHIR_IS_STRING(_1, "mysql")) {
			zephir_array_fetch_string(&_18$$7, database, SL("type"), PH_NOISY | PH_READONLY, "brisk/Vendor/Database/Pdo.zep", 308 TSRMLS_CC);
			zephir_array_fetch_string(&_19$$7, database, SL("host"), PH_NOISY | PH_READONLY, "brisk/Vendor/Database/Pdo.zep", 308 TSRMLS_CC);
			zephir_array_fetch_string(&_20$$7, database, SL("port"), PH_NOISY | PH_READONLY, "brisk/Vendor/Database/Pdo.zep", 308 TSRMLS_CC);
			zephir_array_fetch_string(&_21$$7, database, SL("name"), PH_NOISY | PH_READONLY, "brisk/Vendor/Database/Pdo.zep", 308 TSRMLS_CC);
			ZEPHIR_SINIT_VAR(_22$$7);
			ZVAL_STRING(&_22$$7, "%s:host=%s;port=%s;dbname=%s;", 0);
			ZEPHIR_CALL_FUNCTION(&conn_str, "sprintf", &_14, 40, &_22$$7, _18$$7, _19$$7, _20$$7, _21$$7);
			zephir_check_call_status();
			ZEPHIR_OBS_NVAR(charset);
			zephir_array_fetch_string(&charset, database, SL("charset"), PH_NOISY, "brisk/Vendor/Database/Pdo.zep", 309 TSRMLS_CC);
			if (!ZEPHIR_IS_STRING(charset, "")) {
				ZEPHIR_SINIT_VAR(_23$$8);
				ZVAL_STRING(&_23$$8, "charset=%s", 0);
				ZEPHIR_CALL_FUNCTION(&_24$$8, "sprintf", &_14, 40, &_23$$8, charset);
				zephir_check_call_status();
				ZEPHIR_INIT_VAR(_25$$8);
				ZEPHIR_CONCAT_VV(_25$$8, conn_str, _24$$8);
				ZEPHIR_CPY_WRT(conn_str, _25$$8);
			}
			ZEPHIR_INIT_NVAR(params);
			zephir_create_array(params, 3, 0 TSRMLS_CC);
			add_index_long(params, 3, 2);
			add_index_long(params, 11, 1);
			zephir_array_update_long(&params, 20, &ZEPHIR_GLOBAL(global_false), PH_COPY ZEPHIR_DEBUG_PARAMS_DUMMY);
			break;
		}
		if (ZEPHIR_IS_STRING(_1, "pgsql")) {
			zephir_array_fetch_string(&_26$$9, database, SL("type"), PH_NOISY | PH_READONLY, "brisk/Vendor/Database/Pdo.zep", 320 TSRMLS_CC);
			zephir_array_fetch_string(&_27$$9, database, SL("host"), PH_NOISY | PH_READONLY, "brisk/Vendor/Database/Pdo.zep", 320 TSRMLS_CC);
			zephir_array_fetch_string(&_28$$9, database, SL("port"), PH_NOISY | PH_READONLY, "brisk/Vendor/Database/Pdo.zep", 320 TSRMLS_CC);
			zephir_array_fetch_string(&_29$$9, database, SL("name"), PH_NOISY | PH_READONLY, "brisk/Vendor/Database/Pdo.zep", 320 TSRMLS_CC);
			ZEPHIR_SINIT_VAR(_30$$9);
			ZVAL_STRING(&_30$$9, "%s:host=%s;port=%s;dbname=%s;", 0);
			ZEPHIR_CALL_FUNCTION(&conn_str, "sprintf", &_14, 40, &_30$$9, _26$$9, _27$$9, _28$$9, _29$$9);
			zephir_check_call_status();
			ZEPHIR_OBS_NVAR(charset);
			zephir_array_fetch_string(&charset, database, SL("charset"), PH_NOISY, "brisk/Vendor/Database/Pdo.zep", 321 TSRMLS_CC);
			if (!ZEPHIR_IS_STRING(charset, "")) {
				ZEPHIR_SINIT_VAR(_31$$10);
				ZVAL_STRING(&_31$$10, "charset=%s", 0);
				ZEPHIR_CALL_FUNCTION(&_32$$10, "sprintf", &_14, 40, &_31$$10, charset);
				zephir_check_call_status();
				ZEPHIR_INIT_VAR(_33$$10);
				ZEPHIR_CONCAT_VV(_33$$10, conn_str, _32$$10);
				ZEPHIR_CPY_WRT(conn_str, _33$$10);
			}
			ZEPHIR_INIT_NVAR(params);
			zephir_create_array(params, 3, 0 TSRMLS_CC);
			add_index_long(params, 3, 2);
			add_index_long(params, 11, 1);
			zephir_array_update_long(&params, 20, &ZEPHIR_GLOBAL(global_false), PH_COPY ZEPHIR_DEBUG_PARAMS_DUMMY);
			break;
		}
		if (ZEPHIR_IS_STRING(_1, "sqlite")) {
			ZEPHIR_INIT_NVAR(params);
			zephir_create_array(params, 3, 0 TSRMLS_CC);
			add_index_long(params, 3, 2);
			add_index_long(params, 11, 1);
			zephir_array_update_long(&params, 20, &ZEPHIR_GLOBAL(global_false), PH_COPY ZEPHIR_DEBUG_PARAMS_DUMMY);
			break;
		}
		if (ZEPHIR_IS_STRING(_1, "sqlsrv")) {
			zephir_array_fetch_string(&_34$$12, database, SL("type"), PH_NOISY | PH_READONLY, "brisk/Vendor/Database/Pdo.zep", 339 TSRMLS_CC);
			zephir_array_fetch_string(&_35$$12, database, SL("host"), PH_NOISY | PH_READONLY, "brisk/Vendor/Database/Pdo.zep", 339 TSRMLS_CC);
			zephir_array_fetch_string(&_36$$12, database, SL("port"), PH_NOISY | PH_READONLY, "brisk/Vendor/Database/Pdo.zep", 339 TSRMLS_CC);
			zephir_array_fetch_string(&_37$$12, database, SL("name"), PH_NOISY | PH_READONLY, "brisk/Vendor/Database/Pdo.zep", 339 TSRMLS_CC);
			ZEPHIR_SINIT_VAR(_38$$12);
			ZVAL_STRING(&_38$$12, "%s:Server=%s,%s;Database=%s;", 0);
			ZEPHIR_CALL_FUNCTION(&conn_str, "sprintf", &_14, 40, &_38$$12, _34$$12, _35$$12, _36$$12, _37$$12);
			zephir_check_call_status();
			ZEPHIR_OBS_NVAR(charset);
			zephir_array_fetch_string(&charset, database, SL("charset"), PH_NOISY, "brisk/Vendor/Database/Pdo.zep", 340 TSRMLS_CC);
			if (!ZEPHIR_IS_STRING(charset, "")) {
				ZEPHIR_SINIT_VAR(_39$$13);
				ZVAL_STRING(&_39$$13, "charset=%s", 0);
				ZEPHIR_CALL_FUNCTION(&_40$$13, "sprintf", &_14, 40, &_39$$13, charset);
				zephir_check_call_status();
				ZEPHIR_INIT_VAR(_41$$13);
				ZEPHIR_CONCAT_VV(_41$$13, conn_str, _40$$13);
				ZEPHIR_CPY_WRT(conn_str, _41$$13);
			}
			ZEPHIR_INIT_NVAR(params);
			zephir_create_array(params, 3, 0 TSRMLS_CC);
			add_index_long(params, 3, 2);
			add_index_long(params, 11, 1);
			zephir_array_update_long(&params, 20, &ZEPHIR_GLOBAL(global_false), PH_COPY ZEPHIR_DEBUG_PARAMS_DUMMY);
			break;
		}
	} while(0);

	if (zephir_fast_count_int(option TSRMLS_CC) > 0) {
		ZEPHIR_INIT_VAR(_42$$14);
		zephir_fast_array_merge(_42$$14, &(params), &(option) TSRMLS_CC);
		ZEPHIR_CPY_WRT(params, _42$$14);
	}
	ZEPHIR_INIT_VAR(instance);
	object_init_ex(instance, php_pdo_get_dbh_ce());
	zephir_array_fetch_string(&_43, database, SL("user"), PH_NOISY | PH_READONLY, "brisk/Vendor/Database/Pdo.zep", 355 TSRMLS_CC);
	zephir_array_fetch_string(&_44, database, SL("pass"), PH_NOISY | PH_READONLY, "brisk/Vendor/Database/Pdo.zep", 355 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(NULL, instance, "__construct", NULL, 0, conn_str, _43, _44, params);
	zephir_check_call_status();
	RETURN_CCTOR(instance);

}


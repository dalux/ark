
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
#include "ext/pdo/php_pdo_driver.h"
#include "kernel/array.h"
#include "kernel/object.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/operators.h"


ZEPHIR_INIT_CLASS(Brisk_Db_Driver_PdoFather) {

	ZEPHIR_REGISTER_CLASS_EX(Brisk\\Db\\Driver, PdoFather, brisk, db_driver_pdofather, brisk_db_dbfather_ce, brisk_db_driver_pdofather_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_property_null(brisk_db_driver_pdofather_ce, SL("_instance"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_long(brisk_db_driver_pdofather_ce, SL("_fetch_mode"), 2, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_long(brisk_db_driver_pdofather_ce, SL("_row_count"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * Construct
 *
 * @param string dsn
 * @param string username
 * @param string password
 * @param array option
 * @return null
 */
PHP_METHOD(Brisk_Db_Driver_PdoFather, __construct) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL, *_3 = NULL;
	zval *option = NULL;
	zval *dsn_param = NULL, *username_param = NULL, *password_param = NULL, *option_param = NULL, *e = NULL, *_5, *_1$$3 = NULL, *instance$$3 = NULL, *data$$3 = NULL, *_2$$3 = NULL, *_4$$3, *_6$$4, *_7$$4 = NULL;
	zval *dsn = NULL, *username = NULL, *password = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 4, &dsn_param, &username_param, &password_param, &option_param);

	if (!dsn_param) {
		ZEPHIR_INIT_VAR(dsn);
		ZVAL_STRING(dsn, "", 1);
	} else {
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
	}
	if (!username_param) {
		ZEPHIR_INIT_VAR(username);
		ZVAL_STRING(username, "", 1);
	} else {
	if (UNEXPECTED(Z_TYPE_P(username_param) != IS_STRING && Z_TYPE_P(username_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'username' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(username_param) == IS_STRING)) {
		zephir_get_strval(username, username_param);
	} else {
		ZEPHIR_INIT_VAR(username);
		ZVAL_EMPTY_STRING(username);
	}
	}
	if (!password_param) {
		ZEPHIR_INIT_VAR(password);
		ZVAL_STRING(password, "", 1);
	} else {
	if (UNEXPECTED(Z_TYPE_P(password_param) != IS_STRING && Z_TYPE_P(password_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'password' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(password_param) == IS_STRING)) {
		zephir_get_strval(password, password_param);
	} else {
		ZEPHIR_INIT_VAR(password);
		ZVAL_EMPTY_STRING(password);
	}
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
		ZEPHIR_CALL_CE_STATIC(NULL, brisk_kernel_timer_ce, "mark", &_0, 6, _1$$3);
		zephir_check_temp_parameter(_1$$3);
		zephir_check_call_status_or_jump(try_end_1);
		ZEPHIR_INIT_VAR(instance$$3);
		object_init_ex(instance$$3, php_pdo_get_dbh_ce());
		ZEPHIR_CALL_METHOD(NULL, instance$$3, "__construct", NULL, 0, dsn, username, password, option);
		zephir_check_call_status_or_jump(try_end_1);
		ZEPHIR_INIT_NVAR(_1$$3);
		ZVAL_STRING(_1$$3, "db_connect_end", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_CE_STATIC(NULL, brisk_kernel_timer_ce, "mark", &_0, 6, _1$$3);
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
		ZEPHIR_CALL_CE_STATIC(&_2$$3, brisk_kernel_event_ce, "fire", &_3, 7, _1$$3, data$$3);
		zephir_check_temp_parameter(_1$$3);
		zephir_check_call_status_or_jump(try_end_1);
		ZEPHIR_CPY_WRT(data$$3, _2$$3);
		zephir_array_fetch_string(&_4$$3, data$$3, SL("instance"), PH_NOISY | PH_READONLY, "brisk/Db/Driver/PdoFather.zep", 42 TSRMLS_CC);
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
			ZEPHIR_CALL_METHOD(NULL, _6$$4, "__construct", NULL, 8, _7$$4);
			zephir_check_call_status();
			zephir_throw_exception_debug(_6$$4, "brisk/Db/Driver/PdoFather.zep", 44 TSRMLS_CC);
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
PHP_METHOD(Brisk_Db_Driver_PdoFather, query) {

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
	add_assoc_stringl_ex(data, SS("method"), SL("PdoFather:query"), 1);
	zephir_array_update_string(&data, SL("sql"), &sql, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&data, SL("bind"), &bind, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getdrivername", NULL, 0);
	zephir_check_call_status();
	zephir_array_update_string(&data, SL("driver"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_STRING(_2, "event.query.before", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_CE_STATIC(&_0, brisk_kernel_event_ce, "fire", &_1, 7, _2, data);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(data, _0);
	zephir_array_fetch_string(&_3, data, SL("sql"), PH_NOISY | PH_READONLY, "brisk/Db/Driver/PdoFather.zep", 66 TSRMLS_CC);
	zephir_array_fetch_string(&_4, data, SL("bind"), PH_NOISY | PH_READONLY, "brisk/Db/Driver/PdoFather.zep", 66 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&smt, this_ptr, "_query", NULL, 9, _3, _4);
	zephir_check_call_status();
	result = 1;
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_BOOL(_2, result);
	zephir_array_update_string(&data, SL("result"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(_5);
	ZVAL_STRING(_5, "event.query.finish", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_CE_STATIC(&_0, brisk_kernel_event_ce, "fire", &_1, 7, _5, data);
	zephir_check_temp_parameter(_5);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(data, _0);
	zephir_array_fetch_string(&_6, data, SL("result"), PH_NOISY | PH_READONLY, "brisk/Db/Driver/PdoFather.zep", 70 TSRMLS_CC);
	RETURN_CTOR(_6);

}

/**
 * Execute fetchAll method with bind options
 *
 * @param string sql
 * @param array bind
 * @return array
 */
PHP_METHOD(Brisk_Db_Driver_PdoFather, fetchAll) {

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
	add_assoc_stringl_ex(data, SS("method"), SL("PdoFather:fetchAll"), 1);
	zephir_array_update_string(&data, SL("sql"), &sql, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&data, SL("bind"), &bind, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getdrivername", NULL, 0);
	zephir_check_call_status();
	zephir_array_update_string(&data, SL("driver"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_STRING(_2, "event.query.before", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_CE_STATIC(&_0, brisk_kernel_event_ce, "fire", &_1, 7, _2, data);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(data, _0);
	zephir_array_fetch_string(&_3, data, SL("sql"), PH_NOISY | PH_READONLY, "brisk/Db/Driver/PdoFather.zep", 91 TSRMLS_CC);
	zephir_array_fetch_string(&_4, data, SL("bind"), PH_NOISY | PH_READONLY, "brisk/Db/Driver/PdoFather.zep", 91 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&smt, this_ptr, "_query", NULL, 9, _3, _4);
	zephir_check_call_status();
	_5 = zephir_fetch_nproperty_this(this_ptr, SL("_fetch_mode"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&result, smt, "fetchall", NULL, 0, _5);
	zephir_check_call_status();
	zephir_array_update_string(&data, SL("result"), &result, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "event.query.finish", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_CE_STATIC(&_0, brisk_kernel_event_ce, "fire", &_1, 7, _2, data);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(data, _0);
	zephir_array_fetch_string(&_6, data, SL("result"), PH_NOISY | PH_READONLY, "brisk/Db/Driver/PdoFather.zep", 95 TSRMLS_CC);
	RETURN_CTOR(_6);

}

/**
 * Execute fetchOne method with bind options
 *
 * @param string sql
 * @param array bind
 * @return mixed
 */
PHP_METHOD(Brisk_Db_Driver_PdoFather, fetchOne) {

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
	add_assoc_stringl_ex(data, SS("method"), SL("PdoFather:fetchOne"), 1);
	zephir_array_update_string(&data, SL("sql"), &sql, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&data, SL("bind"), &bind, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getdrivername", NULL, 0);
	zephir_check_call_status();
	zephir_array_update_string(&data, SL("driver"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_STRING(_2, "event.query.before", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_CE_STATIC(&_0, brisk_kernel_event_ce, "fire", &_1, 7, _2, data);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(data, _0);
	zephir_array_fetch_string(&_3, data, SL("sql"), PH_NOISY | PH_READONLY, "brisk/Db/Driver/PdoFather.zep", 115 TSRMLS_CC);
	zephir_array_fetch_string(&_4, data, SL("bind"), PH_NOISY | PH_READONLY, "brisk/Db/Driver/PdoFather.zep", 115 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&smt, this_ptr, "_query", NULL, 9, _3, _4);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_LONG(_2, 0);
	ZEPHIR_CALL_METHOD(&result, smt, "fetchcolumn", NULL, 0, _2);
	zephir_check_call_status();
	zephir_array_update_string(&data, SL("result"), &result, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "event.query.finish", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_CE_STATIC(&_0, brisk_kernel_event_ce, "fire", &_1, 7, _2, data);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(data, _0);
	zephir_array_fetch_string(&_5, data, SL("result"), PH_NOISY | PH_READONLY, "brisk/Db/Driver/PdoFather.zep", 119 TSRMLS_CC);
	RETURN_CTOR(_5);

}

/**
 * Execute fetchRow method with bind options
 *
 * @param string sql
 * @param array bind
 * @return array
 */
PHP_METHOD(Brisk_Db_Driver_PdoFather, fetchRow) {

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
	add_assoc_stringl_ex(data, SS("method"), SL("PdoFather:fetchRow"), 1);
	zephir_array_update_string(&data, SL("sql"), &sql, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&data, SL("bind"), &bind, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getdrivername", NULL, 0);
	zephir_check_call_status();
	zephir_array_update_string(&data, SL("driver"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_STRING(_2, "event.query.before", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_CE_STATIC(&_0, brisk_kernel_event_ce, "fire", &_1, 7, _2, data);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(data, _0);
	zephir_array_fetch_string(&_3, data, SL("sql"), PH_NOISY | PH_READONLY, "brisk/Db/Driver/PdoFather.zep", 140 TSRMLS_CC);
	zephir_array_fetch_string(&_4, data, SL("bind"), PH_NOISY | PH_READONLY, "brisk/Db/Driver/PdoFather.zep", 140 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&smt, this_ptr, "_query", NULL, 9, _3, _4);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(func);
	ZVAL_STRING(func, "fetch", 1);
	_5 = zephir_fetch_nproperty_this(this_ptr, SL("_fetch_mode"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD_ZVAL(&result, smt, func, NULL, 0, _5);
	zephir_check_call_status();
	zephir_array_update_string(&data, SL("result"), &result, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "event.query.finish", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_CE_STATIC(&_0, brisk_kernel_event_ce, "fire", &_1, 7, _2, data);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(data, _0);
	zephir_array_fetch_string(&_6, data, SL("result"), PH_NOISY | PH_READONLY, "brisk/Db/Driver/PdoFather.zep", 145 TSRMLS_CC);
	RETURN_CTOR(_6);

}

/**
 * Start a new Transaction
 *
 * @return bool
 */
PHP_METHOD(Brisk_Db_Driver_PdoFather, beginTransaction) {

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
PHP_METHOD(Brisk_Db_Driver_PdoFather, commit) {

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
PHP_METHOD(Brisk_Db_Driver_PdoFather, rollback) {

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
PHP_METHOD(Brisk_Db_Driver_PdoFather, inTransaction) {

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
PHP_METHOD(Brisk_Db_Driver_PdoFather, nextInsertId) {

	

	RETURN_NULL();

}

/**
 * Get last insert id
 *
 * @param string seq
 * @return int
 */
PHP_METHOD(Brisk_Db_Driver_PdoFather, lastInsertId) {

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
PHP_METHOD(Brisk_Db_Driver_PdoFather, lastRowCount) {

	

	RETURN_MEMBER(getThis(), "_row_count");

}

/**
 * Set Pdo fetch mode
 *
 * @param int mode
 * @return Pdo
 */
PHP_METHOD(Brisk_Db_Driver_PdoFather, setFetchMode) {

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
PHP_METHOD(Brisk_Db_Driver_PdoFather, getDriverName) {

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
PHP_METHOD(Brisk_Db_Driver_PdoFather, getInstance) {

	

	RETURN_MEMBER(getThis(), "_instance");

}

PHP_METHOD(Brisk_Db_Driver_PdoFather, _query) {

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
		ZEPHIR_CALL_CE_STATIC(NULL, brisk_kernel_timer_ce, "mark", &_0, 6, _1$$3);
		zephir_check_temp_parameter(_1$$3);
		zephir_check_call_status_or_jump(try_end_1);
		_2$$3 = zephir_fetch_nproperty_this(this_ptr, SL("_instance"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&smt, _2$$3, "prepare", NULL, 0, sql);
		zephir_check_call_status_or_jump(try_end_1);
		if (zephir_fast_count_int(bind TSRMLS_CC) > 0) {
			ZEPHIR_INIT_VAR(_3$$4);
			zephir_is_iterable(bind, &_5$$4, &_4$$4, 0, 0, "brisk/Db/Driver/PdoFather.zep", 266);
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
				zephir_array_fetch(&_8$$5, bind, key$$4, PH_NOISY | PH_READONLY, "brisk/Db/Driver/PdoFather.zep", 264 TSRMLS_CC);
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
		ZEPHIR_CALL_CE_STATIC(NULL, brisk_kernel_timer_ce, "mark", &_0, 6, _1$$3);
		zephir_check_temp_parameter(_1$$3);
		zephir_check_call_status_or_jump(try_end_1);
		ZEPHIR_INIT_VAR(_13$$3);
		zephir_create_array(_13$$3, 2, 0 TSRMLS_CC);
		ZEPHIR_OBS_VAR(_14$$3);
		zephir_read_property(&_14$$3, smt, SL("queryString"), PH_NOISY_CC);
		zephir_array_fast_append(_13$$3, _14$$3);
		ZEPHIR_CALL_CE_STATIC(&_15$$3, brisk_kernel_timer_ce, "lastused", &_16, 11);
		zephir_check_call_status_or_jump(try_end_1);
		ZEPHIR_SINIT_VAR(_17$$3);
		ZVAL_STRING(&_17$$3, "%.4f", 0);
		ZEPHIR_CALL_FUNCTION(&_18$$3, "sprintf", NULL, 12, &_17$$3, _15$$3);
		zephir_check_call_status_or_jump(try_end_1);
		zephir_array_fast_append(_13$$3, _18$$3);
		ZEPHIR_INIT_NVAR(_1$$3);
		ZVAL_STRING(_1$$3, "database", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_CE_STATIC(NULL, brisk_kernel_trace_ce, "set", &_12, 10, _1$$3, _13$$3);
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
			ZEPHIR_CALL_CE_STATIC(&_21$$7, brisk_kernel_event_ce, "fire", &_22, 7, _23$$7, data$$7);
			zephir_check_temp_parameter(_23$$7);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(data$$7, _21$$7);
			ZEPHIR_INIT_NVAR(_23$$7);
			object_init_ex(_23$$7, brisk_exception_pdoexception_ce);
			zephir_array_fetch_string(&_24$$7, data$$7, SL("error"), PH_NOISY | PH_READONLY, "brisk/Db/Driver/PdoFather.zep", 281 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(NULL, _23$$7, "__construct", NULL, 8, _24$$7);
			zephir_check_call_status();
			zephir_throw_exception_debug(_23$$7, "brisk/Db/Driver/PdoFather.zep", 281 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	ZEPHIR_MM_RESTORE();

}


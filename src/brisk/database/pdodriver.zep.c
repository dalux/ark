
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
#include "kernel/memory.h"
#include "ext/pdo/php_pdo_driver.h"
#include "kernel/array.h"
#include "kernel/object.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/operators.h"


ZEPHIR_INIT_CLASS(Brisk_Database_PdoDriver) {

	ZEPHIR_REGISTER_CLASS_EX(Brisk\\Database, PdoDriver, brisk, database_pdodriver, brisk_database_databasefather_ce, brisk_database_pdodriver_method_entry, 0);

	zend_declare_property_null(brisk_database_pdodriver_ce, SL("_instance"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_long(brisk_database_pdodriver_ce, SL("_fetch_mode"), 2, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_long(brisk_database_pdodriver_ce, SL("_row_count"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Brisk_Database_PdoDriver, __construct) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL, *_4 = NULL;
	zval options;
	zval *dsn_param = NULL, *user_param = NULL, *pass_param = NULL, *options_param = NULL, e, _6, _1$$3, instance$$3, data$$3, _2$$3, _3$$3, _5$$3, _7$$4, _8$$4;
	zval dsn, user, pass;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&dsn);
	ZVAL_UNDEF(&user);
	ZVAL_UNDEF(&pass);
	ZVAL_UNDEF(&e);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&instance$$3);
	ZVAL_UNDEF(&data$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&options);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 4, &dsn_param, &user_param, &pass_param, &options_param);

	if (!dsn_param) {
		ZEPHIR_INIT_VAR(&dsn);
		ZVAL_STRING(&dsn, "");
	} else {
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
	}
	if (!user_param) {
		ZEPHIR_INIT_VAR(&user);
		ZVAL_STRING(&user, "");
	} else {
	if (UNEXPECTED(Z_TYPE_P(user_param) != IS_STRING && Z_TYPE_P(user_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'user' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(user_param) == IS_STRING)) {
		zephir_get_strval(&user, user_param);
	} else {
		ZEPHIR_INIT_VAR(&user);
		ZVAL_EMPTY_STRING(&user);
	}
	}
	if (!pass_param) {
		ZEPHIR_INIT_VAR(&pass);
		ZVAL_STRING(&pass, "");
	} else {
	if (UNEXPECTED(Z_TYPE_P(pass_param) != IS_STRING && Z_TYPE_P(pass_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'pass' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(pass_param) == IS_STRING)) {
		zephir_get_strval(&pass, pass_param);
	} else {
		ZEPHIR_INIT_VAR(&pass);
		ZVAL_EMPTY_STRING(&pass);
	}
	}
	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&options, options_param);
	}



	/* try_start_1: */

		ZEPHIR_INIT_VAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "db_connect_begin");
		ZEPHIR_CALL_CE_STATIC(NULL, brisk_kernel_timer_ce, "mark", &_0, 0, &_1$$3);
		zephir_check_call_status_or_jump(try_end_1);
		ZEPHIR_INIT_VAR(&instance$$3);
		object_init_ex(&instance$$3, php_pdo_get_dbh_ce());
		ZEPHIR_CALL_METHOD(NULL, &instance$$3, "__construct", NULL, 0, &dsn, &user, &pass, &options);
		zephir_check_call_status_or_jump(try_end_1);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "db_connect_end");
		ZEPHIR_CALL_CE_STATIC(NULL, brisk_kernel_timer_ce, "mark", &_0, 0, &_1$$3);
		zephir_check_call_status_or_jump(try_end_1);
		ZEPHIR_INIT_VAR(&data$$3);
		zephir_create_array(&data$$3, 3, 0 TSRMLS_CC);
		zephir_array_update_string(&data$$3, SL("container"), this_ptr, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&data$$3, SL("instance"), &instance$$3, PH_COPY | PH_SEPARATE);
		ZVAL_LONG(&_3$$3, 16);
		ZEPHIR_CALL_METHOD(&_2$$3, &instance$$3, "getattribute", NULL, 0, &_3$$3);
		zephir_check_call_status_or_jump(try_end_1);
		zephir_array_update_string(&data$$3, SL("driver"), &_2$$3, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "event.dbconnect.finish");
		ZEPHIR_CALL_CE_STATIC(&_2$$3, brisk_kernel_event_ce, "onlistening", &_4, 0, &_1$$3, &data$$3);
		zephir_check_call_status_or_jump(try_end_1);
		ZEPHIR_CPY_WRT(&data$$3, &_2$$3);
		zephir_array_fetch_string(&_5$$3, &data$$3, SL("instance"), PH_NOISY | PH_READONLY, "brisk/Database/PdoDriver.zep", 33 TSRMLS_CC);
		zephir_update_property_zval(this_ptr, SL("_instance"), &_5$$3);

	try_end_1:

	if (EG(exception)) {
		ZEPHIR_INIT_VAR(&_6);
		ZVAL_OBJ(&_6, EG(exception));
		Z_ADDREF_P(&_6);
		if (zephir_instance_of_ev(&_6, php_pdo_get_exception() TSRMLS_CC)) {
			zend_clear_exception(TSRMLS_C);
			ZEPHIR_CPY_WRT(&e, &_6);
			ZEPHIR_INIT_VAR(&_7$$4);
			object_init_ex(&_7$$4, brisk_exception_databaseexception_ce);
			ZEPHIR_CALL_METHOD(&_8$$4, &e, "getmessage", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &_7$$4, "__construct", NULL, 3, &_8$$4);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_7$$4, "brisk/Database/PdoDriver.zep", 35 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Brisk_Database_PdoDriver, _query) {

	zend_string *_6$$4;
	zend_ulong _5$$4;
	zend_long ZEPHIR_LAST_CALL_STATUS, _7$$6;
	zephir_fcall_cache_entry *_0 = NULL, *_9 = NULL, *_12 = NULL, *_16 = NULL, *_21 = NULL;
	zval bind, _13$$3;
	zval *sql_param = NULL, *bind_param = NULL, e, smt, _18, _1$$3, _2$$3, _10$$3, _11$$3, _14$$3, _15$$3, _17$$3, key$$4, _3$$4, *_4$$4, _8$$5, data$$7, _19$$7, _20$$7, _22$$7, _23$$7;
	zval sql;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sql);
	ZVAL_UNDEF(&e);
	ZVAL_UNDEF(&smt);
	ZVAL_UNDEF(&_18);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_10$$3);
	ZVAL_UNDEF(&_11$$3);
	ZVAL_UNDEF(&_14$$3);
	ZVAL_UNDEF(&_15$$3);
	ZVAL_UNDEF(&_17$$3);
	ZVAL_UNDEF(&key$$4);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&data$$7);
	ZVAL_UNDEF(&_19$$7);
	ZVAL_UNDEF(&_20$$7);
	ZVAL_UNDEF(&_22$$7);
	ZVAL_UNDEF(&_23$$7);
	ZVAL_UNDEF(&bind);
	ZVAL_UNDEF(&_13$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &sql_param, &bind_param);

	if (UNEXPECTED(Z_TYPE_P(sql_param) != IS_STRING && Z_TYPE_P(sql_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'sql' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(sql_param) == IS_STRING)) {
		zephir_get_strval(&sql, sql_param);
	} else {
		ZEPHIR_INIT_VAR(&sql);
		ZVAL_EMPTY_STRING(&sql);
	}
	if (!bind_param) {
		ZEPHIR_INIT_VAR(&bind);
		array_init(&bind);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&bind, bind_param);
	}



	/* try_start_1: */

		ZEPHIR_INIT_VAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "db_query_begin");
		ZEPHIR_CALL_CE_STATIC(NULL, brisk_kernel_timer_ce, "mark", &_0, 0, &_1$$3);
		zephir_check_call_status_or_jump(try_end_1);
		zephir_read_property(&_2$$3, this_ptr, SL("_instance"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&smt, &_2$$3, "prepare", NULL, 0, &sql);
		zephir_check_call_status_or_jump(try_end_1);
		if (zephir_fast_count_int(&bind TSRMLS_CC) > 0) {
			ZEPHIR_INIT_VAR(&_3$$4);
			zephir_is_iterable(&bind, 0, "brisk/Database/PdoDriver.zep", 54);
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&bind), _5$$4, _6$$4, _4$$4)
			{
				ZEPHIR_INIT_NVAR(&key$$4);
				if (_6$$4 != NULL) { 
					ZVAL_STR_COPY(&key$$4, _6$$4);
				} else {
					ZVAL_LONG(&key$$4, _5$$4);
				}
				ZEPHIR_INIT_NVAR(&_3$$4);
				ZVAL_COPY(&_3$$4, _4$$4);
				if (!(Z_TYPE_P(&key$$4) == IS_STRING)) {
					_7$$6 = (zephir_get_numberval(&key$$4) + 1);
					ZEPHIR_INIT_NVAR(&key$$4);
					ZVAL_LONG(&key$$4, _7$$6);
				}
				zephir_array_fetch(&_8$$5, &bind, &key$$4, PH_NOISY | PH_READONLY, "brisk/Database/PdoDriver.zep", 52 TSRMLS_CC);
				ZEPHIR_CALL_METHOD(NULL, &smt, "bindparam", &_9, 0, &key$$4, &_8$$5);
				zephir_check_call_status_or_jump(try_end_1);
			} ZEND_HASH_FOREACH_END();
			ZEPHIR_INIT_NVAR(&_3$$4);
			ZEPHIR_INIT_NVAR(&key$$4);
		}
		ZEPHIR_CALL_METHOD(NULL, &smt, "execute", NULL, 0);
		zephir_check_call_status_or_jump(try_end_1);
		zephir_read_property(&_10$$3, this_ptr, SL("_fetch_mode"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, &smt, "setfetchmode", NULL, 0, &_10$$3);
		zephir_check_call_status_or_jump(try_end_1);
		ZEPHIR_CALL_METHOD(&_11$$3, &smt, "rowcount", NULL, 0);
		zephir_check_call_status_or_jump(try_end_1);
		zephir_update_property_zval(this_ptr, SL("_row_count"), &_11$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "db_query_end");
		ZEPHIR_CALL_CE_STATIC(NULL, brisk_kernel_timer_ce, "mark", &_0, 0, &_1$$3);
		zephir_check_call_status_or_jump(try_end_1);
		ZEPHIR_INIT_VAR(&_13$$3);
		zephir_create_array(&_13$$3, 2, 0 TSRMLS_CC);
		ZEPHIR_OBS_VAR(&_14$$3);
		zephir_read_property(&_14$$3, &smt, SL("queryString"), PH_NOISY_CC);
		zephir_array_fast_append(&_13$$3, &_14$$3);
		ZEPHIR_CALL_CE_STATIC(&_15$$3, brisk_kernel_timer_ce, "lastused", &_16, 0);
		zephir_check_call_status_or_jump(try_end_1);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "%.4f");
		ZEPHIR_CALL_FUNCTION(&_17$$3, "sprintf", NULL, 4, &_1$$3, &_15$$3);
		zephir_check_call_status_or_jump(try_end_1);
		zephir_array_fast_append(&_13$$3, &_17$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "database");
		ZEPHIR_CALL_CE_STATIC(NULL, brisk_kernel_trace_ce, "set", &_12, 0, &_1$$3, &_13$$3);
		zephir_check_call_status_or_jump(try_end_1);
		RETURN_CCTOR(&smt);

	try_end_1:

	if (EG(exception)) {
		ZEPHIR_INIT_VAR(&_18);
		ZVAL_OBJ(&_18, EG(exception));
		Z_ADDREF_P(&_18);
		if (zephir_instance_of_ev(&_18, php_pdo_get_exception() TSRMLS_CC)) {
			zend_clear_exception(TSRMLS_C);
			ZEPHIR_CPY_WRT(&e, &_18);
			ZEPHIR_INIT_VAR(&data$$7);
			zephir_create_array(&data$$7, 3, 0 TSRMLS_CC);
			ZEPHIR_OBS_VAR(&_19$$7);
			zephir_read_property(&_19$$7, &smt, SL("queryString"), PH_NOISY_CC);
			zephir_array_update_string(&data$$7, SL("sql"), &_19$$7, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(&_20$$7, &e, "getmessage", NULL, 0);
			zephir_check_call_status();
			zephir_array_update_string(&data$$7, SL("error"), &_20$$7, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(&_20$$7, this_ptr, "getdrivername", NULL, 0);
			zephir_check_call_status();
			zephir_array_update_string(&data$$7, SL("driver"), &_20$$7, PH_COPY | PH_SEPARATE);
			ZEPHIR_INIT_VAR(&_22$$7);
			ZVAL_STRING(&_22$$7, "event.query.failed");
			ZEPHIR_CALL_CE_STATIC(&_20$$7, brisk_kernel_event_ce, "onlistening", &_21, 0, &_22$$7, &data$$7);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&data$$7, &_20$$7);
			ZEPHIR_INIT_NVAR(&_22$$7);
			object_init_ex(&_22$$7, brisk_exception_databaseexception_ce);
			zephir_array_fetch_string(&_23$$7, &data$$7, SL("error"), PH_NOISY | PH_READONLY, "brisk/Database/PdoDriver.zep", 69 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(NULL, &_22$$7, "__construct", NULL, 3, &_23$$7);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_22$$7, "brisk/Database/PdoDriver.zep", 69 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Brisk_Database_PdoDriver, query) {

	zend_bool result = 0;
	zephir_fcall_cache_entry *_1 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval bind;
	zval *sql_param = NULL, *bind_param = NULL, data, _0, _2, smt, _3, _4, _5, _6;
	zval sql;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sql);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&smt);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&bind);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &sql_param, &bind_param);

	if (UNEXPECTED(Z_TYPE_P(sql_param) != IS_STRING && Z_TYPE_P(sql_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'sql' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(sql_param) == IS_STRING)) {
		zephir_get_strval(&sql, sql_param);
	} else {
		ZEPHIR_INIT_VAR(&sql);
		ZVAL_EMPTY_STRING(&sql);
	}
	if (!bind_param) {
		ZEPHIR_INIT_VAR(&bind);
		array_init(&bind);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&bind, bind_param);
	}


	ZEPHIR_INIT_VAR(&data);
	zephir_create_array(&data, 4, 0 TSRMLS_CC);
	add_assoc_stringl_ex(&data, SL("method"), SL("PdoDriver:query"));
	zephir_array_update_string(&data, SL("sql"), &sql, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&data, SL("bind"), &bind, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getdrivername", NULL, 0);
	zephir_check_call_status();
	zephir_array_update_string(&data, SL("driver"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "event.query.before");
	ZEPHIR_CALL_CE_STATIC(&_0, brisk_kernel_event_ce, "onlistening", &_1, 0, &_2, &data);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&data, &_0);
	zephir_array_fetch_string(&_3, &data, SL("sql"), PH_NOISY | PH_READONLY, "brisk/Database/PdoDriver.zep", 84 TSRMLS_CC);
	zephir_array_fetch_string(&_4, &data, SL("bind"), PH_NOISY | PH_READONLY, "brisk/Database/PdoDriver.zep", 84 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&smt, this_ptr, "_query", NULL, 0, &_3, &_4);
	zephir_check_call_status();
	result = 1;
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_BOOL(&_2, result);
	zephir_array_update_string(&data, SL("result"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(&_5);
	ZVAL_STRING(&_5, "event.query.finish");
	ZEPHIR_CALL_CE_STATIC(&_0, brisk_kernel_event_ce, "onlistening", &_1, 0, &_5, &data);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&data, &_0);
	zephir_array_fetch_string(&_6, &data, SL("result"), PH_NOISY | PH_READONLY, "brisk/Database/PdoDriver.zep", 88 TSRMLS_CC);
	RETURN_CTOR(&_6);

}

PHP_METHOD(Brisk_Database_PdoDriver, fetchAll) {

	zephir_fcall_cache_entry *_1 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval bind;
	zval *sql_param = NULL, *bind_param = NULL, data, _0, _2, smt, result, _3, _4, _5, _6;
	zval sql;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sql);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&smt);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&bind);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &sql_param, &bind_param);

	if (UNEXPECTED(Z_TYPE_P(sql_param) != IS_STRING && Z_TYPE_P(sql_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'sql' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(sql_param) == IS_STRING)) {
		zephir_get_strval(&sql, sql_param);
	} else {
		ZEPHIR_INIT_VAR(&sql);
		ZVAL_EMPTY_STRING(&sql);
	}
	if (!bind_param) {
		ZEPHIR_INIT_VAR(&bind);
		array_init(&bind);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&bind, bind_param);
	}


	ZEPHIR_INIT_VAR(&data);
	zephir_create_array(&data, 4, 0 TSRMLS_CC);
	add_assoc_stringl_ex(&data, SL("method"), SL("PdoDriver:fetchAll"));
	zephir_array_update_string(&data, SL("sql"), &sql, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&data, SL("bind"), &bind, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getdrivername", NULL, 0);
	zephir_check_call_status();
	zephir_array_update_string(&data, SL("driver"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "event.query.before");
	ZEPHIR_CALL_CE_STATIC(&_0, brisk_kernel_event_ce, "onlistening", &_1, 0, &_2, &data);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&data, &_0);
	zephir_array_fetch_string(&_3, &data, SL("sql"), PH_NOISY | PH_READONLY, "brisk/Database/PdoDriver.zep", 102 TSRMLS_CC);
	zephir_array_fetch_string(&_4, &data, SL("bind"), PH_NOISY | PH_READONLY, "brisk/Database/PdoDriver.zep", 102 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&smt, this_ptr, "_query", NULL, 0, &_3, &_4);
	zephir_check_call_status();
	zephir_read_property(&_5, this_ptr, SL("_fetch_mode"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&result, &smt, "fetchall", NULL, 0, &_5);
	zephir_check_call_status();
	zephir_array_update_string(&data, SL("result"), &result, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "event.query.finish");
	ZEPHIR_CALL_CE_STATIC(&_0, brisk_kernel_event_ce, "onlistening", &_1, 0, &_2, &data);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&data, &_0);
	zephir_array_fetch_string(&_6, &data, SL("result"), PH_NOISY | PH_READONLY, "brisk/Database/PdoDriver.zep", 106 TSRMLS_CC);
	RETURN_CTOR(&_6);

}

PHP_METHOD(Brisk_Database_PdoDriver, fetchOne) {

	zephir_fcall_cache_entry *_1 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval bind;
	zval *sql_param = NULL, *bind_param = NULL, data, smt, result, _0, _2, _3, _4, _5, _6;
	zval sql;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sql);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&smt);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&bind);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &sql_param, &bind_param);

	if (UNEXPECTED(Z_TYPE_P(sql_param) != IS_STRING && Z_TYPE_P(sql_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'sql' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(sql_param) == IS_STRING)) {
		zephir_get_strval(&sql, sql_param);
	} else {
		ZEPHIR_INIT_VAR(&sql);
		ZVAL_EMPTY_STRING(&sql);
	}
	if (!bind_param) {
		ZEPHIR_INIT_VAR(&bind);
		array_init(&bind);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&bind, bind_param);
	}


	ZEPHIR_INIT_VAR(&data);
	zephir_create_array(&data, 4, 0 TSRMLS_CC);
	add_assoc_stringl_ex(&data, SL("method"), SL("PdoDriver:fetchOne"));
	zephir_array_update_string(&data, SL("sql"), &sql, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&data, SL("bind"), &bind, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getdrivername", NULL, 0);
	zephir_check_call_status();
	zephir_array_update_string(&data, SL("driver"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "event.query.before");
	ZEPHIR_CALL_CE_STATIC(&_0, brisk_kernel_event_ce, "onlistening", &_1, 0, &_2, &data);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&data, &_0);
	zephir_array_fetch_string(&_3, &data, SL("sql"), PH_NOISY | PH_READONLY, "brisk/Database/PdoDriver.zep", 119 TSRMLS_CC);
	zephir_array_fetch_string(&_4, &data, SL("bind"), PH_NOISY | PH_READONLY, "brisk/Database/PdoDriver.zep", 119 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&smt, this_ptr, "_query", NULL, 0, &_3, &_4);
	zephir_check_call_status();
	ZVAL_LONG(&_5, 0);
	ZEPHIR_CALL_METHOD(&result, &smt, "fetchcolumn", NULL, 0, &_5);
	zephir_check_call_status();
	zephir_array_update_string(&data, SL("result"), &result, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "event.query.finish");
	ZEPHIR_CALL_CE_STATIC(&_0, brisk_kernel_event_ce, "onlistening", &_1, 0, &_2, &data);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&data, &_0);
	zephir_array_fetch_string(&_6, &data, SL("result"), PH_NOISY | PH_READONLY, "brisk/Database/PdoDriver.zep", 123 TSRMLS_CC);
	RETURN_CTOR(&_6);

}

PHP_METHOD(Brisk_Database_PdoDriver, fetchRow) {

	zephir_fcall_cache_entry *_1 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval bind;
	zval *sql_param = NULL, *bind_param = NULL, data, _0, _2, smt, result, func, _3, _4, _5, _6;
	zval sql;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sql);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&smt);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&func);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&bind);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &sql_param, &bind_param);

	if (UNEXPECTED(Z_TYPE_P(sql_param) != IS_STRING && Z_TYPE_P(sql_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'sql' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(sql_param) == IS_STRING)) {
		zephir_get_strval(&sql, sql_param);
	} else {
		ZEPHIR_INIT_VAR(&sql);
		ZVAL_EMPTY_STRING(&sql);
	}
	if (!bind_param) {
		ZEPHIR_INIT_VAR(&bind);
		array_init(&bind);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&bind, bind_param);
	}


	ZEPHIR_INIT_VAR(&data);
	zephir_create_array(&data, 4, 0 TSRMLS_CC);
	add_assoc_stringl_ex(&data, SL("method"), SL("PdoDriver:fetchRow"));
	zephir_array_update_string(&data, SL("sql"), &sql, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&data, SL("bind"), &bind, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getdrivername", NULL, 0);
	zephir_check_call_status();
	zephir_array_update_string(&data, SL("driver"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "event.query.before");
	ZEPHIR_CALL_CE_STATIC(&_0, brisk_kernel_event_ce, "onlistening", &_1, 0, &_2, &data);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&data, &_0);
	zephir_array_fetch_string(&_3, &data, SL("sql"), PH_NOISY | PH_READONLY, "brisk/Database/PdoDriver.zep", 137 TSRMLS_CC);
	zephir_array_fetch_string(&_4, &data, SL("bind"), PH_NOISY | PH_READONLY, "brisk/Database/PdoDriver.zep", 137 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&smt, this_ptr, "_query", NULL, 0, &_3, &_4);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&func);
	ZVAL_STRING(&func, "fetch");
	zephir_read_property(&_5, this_ptr, SL("_fetch_mode"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD_ZVAL(&result, &smt, &func, NULL, 0, &_5);
	zephir_check_call_status();
	zephir_array_update_string(&data, SL("result"), &result, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "event.query.finish");
	ZEPHIR_CALL_CE_STATIC(&_0, brisk_kernel_event_ce, "onlistening", &_1, 0, &_2, &data);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&data, &_0);
	zephir_array_fetch_string(&_6, &data, SL("result"), PH_NOISY | PH_READONLY, "brisk/Database/PdoDriver.zep", 142 TSRMLS_CC);
	RETURN_CTOR(&_6);

}

PHP_METHOD(Brisk_Database_PdoDriver, beginTransaction) {

	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("_instance"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "begintransaction", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Brisk_Database_PdoDriver, commit) {

	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("_instance"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "commit", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Brisk_Database_PdoDriver, rollback) {

	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("_instance"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "rollback", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Brisk_Database_PdoDriver, inTransaction) {

	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("_instance"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "intransaction", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Brisk_Database_PdoDriver, nextInsertId) {

	zval *this_ptr = getThis();


	RETURN_NULL();

}

PHP_METHOD(Brisk_Database_PdoDriver, lastInsertId) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *seq_param = NULL, _0;
	zval seq;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&seq);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &seq_param);

	if (!seq_param) {
		ZEPHIR_INIT_VAR(&seq);
		ZVAL_STRING(&seq, "");
	} else {
	if (UNEXPECTED(Z_TYPE_P(seq_param) != IS_STRING && Z_TYPE_P(seq_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'seq' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(seq_param) == IS_STRING)) {
		zephir_get_strval(&seq, seq_param);
	} else {
		ZEPHIR_INIT_VAR(&seq);
		ZVAL_EMPTY_STRING(&seq);
	}
	}


	zephir_read_property(&_0, this_ptr, SL("_instance"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "lastinsertid", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Brisk_Database_PdoDriver, lastRowCount) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_row_count");

}

PHP_METHOD(Brisk_Database_PdoDriver, setFetchMode) {

	zval *mode_param = NULL, _0;
	zend_long mode;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	zephir_fetch_params(0, 1, 0, &mode_param);

	if (UNEXPECTED(Z_TYPE_P(mode_param) != IS_LONG)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'mode' must be a int") TSRMLS_CC);
		RETURN_NULL();
	}
	mode = Z_LVAL_P(mode_param);


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(&_0, mode);
	zephir_update_property_zval(this_ptr, SL("_fetch_mode"), &_0);

}

PHP_METHOD(Brisk_Database_PdoDriver, getDriverName) {

	zval _0, _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("_instance"), PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_1, 16);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "getattribute", NULL, 0, &_1);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Brisk_Database_PdoDriver, getInstance) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_instance");

}


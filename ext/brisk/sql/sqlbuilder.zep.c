
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
#include "kernel/object.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/concat.h"
#include "kernel/string.h"
#include "kernel/fcall.h"
#include "kernel/array.h"


ZEPHIR_INIT_CLASS(Brisk_Sql_SqlBuilder) {

	ZEPHIR_REGISTER_CLASS(Brisk\\Sql, SqlBuilder, brisk, sql_sqlbuilder, brisk_sql_sqlbuilder_method_entry, 0);

	zend_declare_property_string(brisk_sql_sqlbuilder_ce, SL("_db_type"), "mysql", ZEND_ACC_PRIVATE|ZEND_ACC_STATIC TSRMLS_CC);

	return SUCCESS;

}

/**
 * Setting database type
 *
 * @param string dbtype
 * @return null
 */
PHP_METHOD(Brisk_Sql_SqlBuilder, setDbType) {

	zval *dbtype_param = NULL;
	zval *dbtype = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &dbtype_param);

	if (UNEXPECTED(Z_TYPE_P(dbtype_param) != IS_STRING && Z_TYPE_P(dbtype_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'dbtype' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(dbtype_param) == IS_STRING)) {
		zephir_get_strval(dbtype, dbtype_param);
	} else {
		ZEPHIR_INIT_VAR(dbtype);
		ZVAL_EMPTY_STRING(dbtype);
	}


	zephir_update_static_property_ce(brisk_sql_sqlbuilder_ce, SL("_db_type"), &dbtype TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Get current database type
 *
 * @return string
 */
PHP_METHOD(Brisk_Sql_SqlBuilder, getDbType) {

	zval *_0;


	_0 = zephir_fetch_static_property_ce(brisk_sql_sqlbuilder_ce, SL("_db_type") TSRMLS_CC);
	RETURN_CTORW(_0);

}

/**
 * Get select sql object
 *
 * @param string dbtype
 * @return Select
 */
PHP_METHOD(Brisk_Sql_SqlBuilder, getSelect) {

	zval *_9$$4;
	zend_class_entry *_12;
	zend_bool _3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_2 = NULL, *_5 = NULL, *_8 = NULL;
	zval *dbtype_param = NULL, *_dbtype = NULL, *classname = NULL, *instance = NULL, *_0, *_1 = NULL, *_4 = NULL, *_11 = NULL, *_6$$4, *_7$$4 = NULL, *_10$$4;
	zval *dbtype = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &dbtype_param);

	if (!dbtype_param) {
		ZEPHIR_INIT_VAR(dbtype);
		ZVAL_STRING(dbtype, "", 1);
	} else {
	if (UNEXPECTED(Z_TYPE_P(dbtype_param) != IS_STRING && Z_TYPE_P(dbtype_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'dbtype' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(dbtype_param) == IS_STRING)) {
		zephir_get_strval(dbtype, dbtype_param);
	} else {
		ZEPHIR_INIT_VAR(dbtype);
		ZVAL_EMPTY_STRING(dbtype);
	}
	}


	ZEPHIR_CPY_WRT(_dbtype, dbtype);
	if (ZEPHIR_IS_STRING(_dbtype, "")) {
		ZEPHIR_OBS_NVAR(_dbtype);
		zephir_read_static_property_ce(&_dbtype, brisk_sql_sqlbuilder_ce, SL("_db_type") TSRMLS_CC);
	}
	ZEPHIR_INIT_VAR(_0);
	zephir_ucfirst(_0, _dbtype);
	ZEPHIR_INIT_VAR(classname);
	ZEPHIR_CONCAT_SV(classname, "\\Brisk\\Sql\\Select\\", _0);
	ZEPHIR_CALL_CE_STATIC(&_1, brisk_kernel_toolkit_ce, "classdeclared", &_2, 23, classname);
	zephir_check_call_status();
	_3 = !zephir_is_true(_1);
	if (_3) {
		ZEPHIR_CALL_CE_STATIC(&_4, brisk_kernel_loader_ce, "findclass", &_5, 24, classname);
		zephir_check_call_status();
		_3 = !zephir_is_true(_4);
	}
	if (_3) {
		ZEPHIR_INIT_VAR(_6$$4);
		object_init_ex(_6$$4, brisk_exception_runtimeexception_ce);
		ZEPHIR_INIT_VAR(_9$$4);
		zephir_create_array(_9$$4, 1, 0 TSRMLS_CC);
		zephir_array_fast_append(_9$$4, classname);
		ZEPHIR_INIT_VAR(_10$$4);
		ZVAL_STRING(_10$$4, "core.class_path_notfound", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_CE_STATIC(&_7$$4, brisk_kernel_language_ce, "get", &_8, 13, _10$$4, _9$$4);
		zephir_check_temp_parameter(_10$$4);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, _6$$4, "__construct", NULL, 8, _7$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(_6$$4, "brisk/Sql/SqlBuilder.zep", 53 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(instance);
	zephir_fetch_safe_class(_11, classname);
		_12 = zend_fetch_class(Z_STRVAL_P(_11), Z_STRLEN_P(_11), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	object_init_ex(instance, _12);
	if (zephir_has_constructor(instance TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, instance, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	RETURN_CCTOR(instance);

}

/**
 * Get delete sql object
 *
 * @param string dbtype
 * @return Delete
 */
PHP_METHOD(Brisk_Sql_SqlBuilder, getDelete) {

	zval *_9$$4;
	zend_class_entry *_12;
	zend_bool _3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_2 = NULL, *_5 = NULL, *_8 = NULL;
	zval *dbtype_param = NULL, *_dbtype = NULL, *classname = NULL, *instance = NULL, *_0, *_1 = NULL, *_4 = NULL, *_11 = NULL, *_6$$4, *_7$$4 = NULL, *_10$$4;
	zval *dbtype = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &dbtype_param);

	if (!dbtype_param) {
		ZEPHIR_INIT_VAR(dbtype);
		ZVAL_STRING(dbtype, "", 1);
	} else {
	if (UNEXPECTED(Z_TYPE_P(dbtype_param) != IS_STRING && Z_TYPE_P(dbtype_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'dbtype' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(dbtype_param) == IS_STRING)) {
		zephir_get_strval(dbtype, dbtype_param);
	} else {
		ZEPHIR_INIT_VAR(dbtype);
		ZVAL_EMPTY_STRING(dbtype);
	}
	}


	ZEPHIR_CPY_WRT(_dbtype, dbtype);
	if (ZEPHIR_IS_STRING(_dbtype, "")) {
		ZEPHIR_OBS_NVAR(_dbtype);
		zephir_read_static_property_ce(&_dbtype, brisk_sql_sqlbuilder_ce, SL("_db_type") TSRMLS_CC);
	}
	ZEPHIR_INIT_VAR(_0);
	zephir_ucfirst(_0, _dbtype);
	ZEPHIR_INIT_VAR(classname);
	ZEPHIR_CONCAT_SV(classname, "\\Brisk\\Sql\\Delete\\", _0);
	ZEPHIR_CALL_CE_STATIC(&_1, brisk_kernel_toolkit_ce, "classdeclared", &_2, 23, classname);
	zephir_check_call_status();
	_3 = !zephir_is_true(_1);
	if (_3) {
		ZEPHIR_CALL_CE_STATIC(&_4, brisk_kernel_loader_ce, "findclass", &_5, 24, classname);
		zephir_check_call_status();
		_3 = !zephir_is_true(_4);
	}
	if (_3) {
		ZEPHIR_INIT_VAR(_6$$4);
		object_init_ex(_6$$4, brisk_exception_runtimeexception_ce);
		ZEPHIR_INIT_VAR(_9$$4);
		zephir_create_array(_9$$4, 1, 0 TSRMLS_CC);
		zephir_array_fast_append(_9$$4, classname);
		ZEPHIR_INIT_VAR(_10$$4);
		ZVAL_STRING(_10$$4, "core.class_path_notfound", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_CE_STATIC(&_7$$4, brisk_kernel_language_ce, "get", &_8, 13, _10$$4, _9$$4);
		zephir_check_temp_parameter(_10$$4);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, _6$$4, "__construct", NULL, 8, _7$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(_6$$4, "brisk/Sql/SqlBuilder.zep", 74 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(instance);
	zephir_fetch_safe_class(_11, classname);
		_12 = zend_fetch_class(Z_STRVAL_P(_11), Z_STRLEN_P(_11), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	object_init_ex(instance, _12);
	if (zephir_has_constructor(instance TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, instance, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	RETURN_CCTOR(instance);

}

/**
 * Get insert sql object
 *
 * @param string dbtype
 * @return Insert
 */
PHP_METHOD(Brisk_Sql_SqlBuilder, getInsert) {

	zval *_9$$4;
	zend_class_entry *_12;
	zend_bool _3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_2 = NULL, *_5 = NULL, *_8 = NULL;
	zval *dbtype_param = NULL, *_dbtype = NULL, *classname = NULL, *instance = NULL, *_0, *_1 = NULL, *_4 = NULL, *_11 = NULL, *_6$$4, *_7$$4 = NULL, *_10$$4;
	zval *dbtype = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &dbtype_param);

	if (!dbtype_param) {
		ZEPHIR_INIT_VAR(dbtype);
		ZVAL_STRING(dbtype, "", 1);
	} else {
	if (UNEXPECTED(Z_TYPE_P(dbtype_param) != IS_STRING && Z_TYPE_P(dbtype_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'dbtype' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(dbtype_param) == IS_STRING)) {
		zephir_get_strval(dbtype, dbtype_param);
	} else {
		ZEPHIR_INIT_VAR(dbtype);
		ZVAL_EMPTY_STRING(dbtype);
	}
	}


	ZEPHIR_CPY_WRT(_dbtype, dbtype);
	if (ZEPHIR_IS_STRING(_dbtype, "")) {
		ZEPHIR_OBS_NVAR(_dbtype);
		zephir_read_static_property_ce(&_dbtype, brisk_sql_sqlbuilder_ce, SL("_db_type") TSRMLS_CC);
	}
	ZEPHIR_INIT_VAR(_0);
	zephir_ucfirst(_0, _dbtype);
	ZEPHIR_INIT_VAR(classname);
	ZEPHIR_CONCAT_SV(classname, "\\Brisk\\Sql\\Insert\\", _0);
	ZEPHIR_CALL_CE_STATIC(&_1, brisk_kernel_toolkit_ce, "classdeclared", &_2, 23, classname);
	zephir_check_call_status();
	_3 = !zephir_is_true(_1);
	if (_3) {
		ZEPHIR_CALL_CE_STATIC(&_4, brisk_kernel_loader_ce, "findclass", &_5, 24, classname);
		zephir_check_call_status();
		_3 = !zephir_is_true(_4);
	}
	if (_3) {
		ZEPHIR_INIT_VAR(_6$$4);
		object_init_ex(_6$$4, brisk_exception_runtimeexception_ce);
		ZEPHIR_INIT_VAR(_9$$4);
		zephir_create_array(_9$$4, 1, 0 TSRMLS_CC);
		zephir_array_fast_append(_9$$4, classname);
		ZEPHIR_INIT_VAR(_10$$4);
		ZVAL_STRING(_10$$4, "core.class_path_notfound", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_CE_STATIC(&_7$$4, brisk_kernel_language_ce, "get", &_8, 13, _10$$4, _9$$4);
		zephir_check_temp_parameter(_10$$4);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, _6$$4, "__construct", NULL, 8, _7$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(_6$$4, "brisk/Sql/SqlBuilder.zep", 95 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(instance);
	zephir_fetch_safe_class(_11, classname);
		_12 = zend_fetch_class(Z_STRVAL_P(_11), Z_STRLEN_P(_11), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	object_init_ex(instance, _12);
	if (zephir_has_constructor(instance TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, instance, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	RETURN_CCTOR(instance);

}

/**
 * Get Update sql object
 *
 * @param string dbtype
 * @return Update
 */
PHP_METHOD(Brisk_Sql_SqlBuilder, getUpdate) {

	zval *_9$$4;
	zend_class_entry *_12;
	zend_bool _3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_2 = NULL, *_5 = NULL, *_8 = NULL;
	zval *dbtype_param = NULL, *_dbtype = NULL, *classname = NULL, *instance = NULL, *_0, *_1 = NULL, *_4 = NULL, *_11 = NULL, *_6$$4, *_7$$4 = NULL, *_10$$4;
	zval *dbtype = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &dbtype_param);

	if (!dbtype_param) {
		ZEPHIR_INIT_VAR(dbtype);
		ZVAL_STRING(dbtype, "", 1);
	} else {
	if (UNEXPECTED(Z_TYPE_P(dbtype_param) != IS_STRING && Z_TYPE_P(dbtype_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'dbtype' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(dbtype_param) == IS_STRING)) {
		zephir_get_strval(dbtype, dbtype_param);
	} else {
		ZEPHIR_INIT_VAR(dbtype);
		ZVAL_EMPTY_STRING(dbtype);
	}
	}


	ZEPHIR_CPY_WRT(_dbtype, dbtype);
	if (ZEPHIR_IS_STRING(_dbtype, "")) {
		ZEPHIR_OBS_NVAR(_dbtype);
		zephir_read_static_property_ce(&_dbtype, brisk_sql_sqlbuilder_ce, SL("_db_type") TSRMLS_CC);
	}
	ZEPHIR_INIT_VAR(_0);
	zephir_ucfirst(_0, _dbtype);
	ZEPHIR_INIT_VAR(classname);
	ZEPHIR_CONCAT_SV(classname, "\\Brisk\\Sql\\Update\\", _0);
	ZEPHIR_CALL_CE_STATIC(&_1, brisk_kernel_toolkit_ce, "classdeclared", &_2, 23, classname);
	zephir_check_call_status();
	_3 = !zephir_is_true(_1);
	if (_3) {
		ZEPHIR_CALL_CE_STATIC(&_4, brisk_kernel_loader_ce, "findclass", &_5, 24, classname);
		zephir_check_call_status();
		_3 = !zephir_is_true(_4);
	}
	if (_3) {
		ZEPHIR_INIT_VAR(_6$$4);
		object_init_ex(_6$$4, brisk_exception_runtimeexception_ce);
		ZEPHIR_INIT_VAR(_9$$4);
		zephir_create_array(_9$$4, 1, 0 TSRMLS_CC);
		zephir_array_fast_append(_9$$4, classname);
		ZEPHIR_INIT_VAR(_10$$4);
		ZVAL_STRING(_10$$4, "core.class_path_notfound", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_CE_STATIC(&_7$$4, brisk_kernel_language_ce, "get", &_8, 13, _10$$4, _9$$4);
		zephir_check_temp_parameter(_10$$4);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, _6$$4, "__construct", NULL, 8, _7$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(_6$$4, "brisk/Sql/SqlBuilder.zep", 116 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(instance);
	zephir_fetch_safe_class(_11, classname);
		_12 = zend_fetch_class(Z_STRVAL_P(_11), Z_STRLEN_P(_11), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	object_init_ex(instance, _12);
	if (zephir_has_constructor(instance TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, instance, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	RETURN_CCTOR(instance);

}


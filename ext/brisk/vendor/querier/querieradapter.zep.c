
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
#include "kernel/object.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"
#include "kernel/string.h"


ZEPHIR_INIT_CLASS(Brisk_Vendor_Querier_QuerierAdapter) {

	ZEPHIR_REGISTER_CLASS(Brisk\\Vendor\\Querier, QuerierAdapter, brisk, vendor_querier_querieradapter, brisk_vendor_querier_querieradapter_method_entry, 0);

	zend_declare_property_string(brisk_vendor_querier_querieradapter_ce, SL("_db_type"), "mysql", ZEND_ACC_PRIVATE|ZEND_ACC_STATIC TSRMLS_CC);

	zend_declare_class_constant_string(brisk_vendor_querier_querieradapter_ce, SL("TYPE_SELECT"), "Select" TSRMLS_CC);

	zend_declare_class_constant_string(brisk_vendor_querier_querieradapter_ce, SL("TYPE_UPDATE"), "Update" TSRMLS_CC);

	zend_declare_class_constant_string(brisk_vendor_querier_querieradapter_ce, SL("TYPE_DELETE"), "Delete" TSRMLS_CC);

	zend_declare_class_constant_string(brisk_vendor_querier_querieradapter_ce, SL("TYPE_INSERT"), "Insert" TSRMLS_CC);

	return SUCCESS;

}

/**
 * Set Querier database type
 *
 * @param string dbtype
 * @return null
 */
PHP_METHOD(Brisk_Vendor_Querier_QuerierAdapter, setDbType) {

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


	zephir_update_static_property_ce(brisk_vendor_querier_querieradapter_ce, SL("_db_type"), &dbtype TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Get Querier object instance
 *
 * @param string type
 * @param string dbtype
 * @return QuerierFather
 */
PHP_METHOD(Brisk_Vendor_Querier_QuerierAdapter, getQuerier) {

	zval *_2$$4;
	zend_class_entry *_5;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *type_param = NULL, *dbtype_param = NULL, *db_type = NULL, *types = NULL, *classname = NULL, *_0 = NULL, *_4 = NULL, *_1$$4, *_3$$4;
	zval *type = NULL, *dbtype = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &type_param, &dbtype_param);

	if (UNEXPECTED(Z_TYPE_P(type_param) != IS_STRING && Z_TYPE_P(type_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'type' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(type_param) == IS_STRING)) {
		zephir_get_strval(type, type_param);
	} else {
		ZEPHIR_INIT_VAR(type);
		ZVAL_EMPTY_STRING(type);
	}
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


	ZEPHIR_CPY_WRT(db_type, dbtype);
	if (ZEPHIR_IS_STRING(db_type, "")) {
		ZEPHIR_OBS_NVAR(db_type);
		zephir_read_static_property_ce(&db_type, brisk_vendor_querier_querieradapter_ce, SL("_db_type") TSRMLS_CC);
	}
	ZEPHIR_INIT_VAR(types);
	zephir_create_array(types, 4, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "Select", 1);
	zephir_array_fast_append(types, _0);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "Delete", 1);
	zephir_array_fast_append(types, _0);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "Insert", 1);
	zephir_array_fast_append(types, _0);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "Update", 1);
	zephir_array_fast_append(types, _0);
	if (!(zephir_fast_in_array(type, types TSRMLS_CC))) {
		ZEPHIR_INIT_VAR(_1$$4);
		object_init_ex(_1$$4, brisk_exception_runtimeexception_ce);
		ZEPHIR_INIT_VAR(_2$$4);
		zephir_create_array(_2$$4, 1, 0 TSRMLS_CC);
		zephir_array_fast_append(_2$$4, db_type);
		ZEPHIR_INIT_VAR(_3$$4);
		ZVAL_STRING(_3$$4, "querier.type_not_supported", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, _1$$4, "__construct", NULL, 27, _3$$4, _2$$4);
		zephir_check_temp_parameter(_3$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(_1$$4, "brisk/Vendor/Querier/QuerierAdapter.zep", 44 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_NVAR(_0);
	zephir_ucfirst(_0, db_type);
	ZEPHIR_INIT_VAR(classname);
	ZEPHIR_CONCAT_SVSV(classname, "\\Brisk\\Vendor\\Querier\\", type, "\\", _0);
	zephir_fetch_safe_class(_4, classname);
		_5 = zend_fetch_class(Z_STRVAL_P(_4), Z_STRLEN_P(_4), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	object_init_ex(return_value, _5);
	if (zephir_has_constructor(return_value TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	RETURN_MM();

}

/**
 * Get Select Querier object instance
 *
 * @param string dbtype
 * @return Select
 */
PHP_METHOD(Brisk_Vendor_Querier_QuerierAdapter, getSelectQuerier) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *dbtype_param = NULL, *_0;
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


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "Select", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_SELF("getquerier", NULL, 0, _0, dbtype);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Get Insert Querier object instance
 *
 * @param string dbtype
 * @return Insert
 */
PHP_METHOD(Brisk_Vendor_Querier_QuerierAdapter, getInsertQuerier) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *dbtype_param = NULL, *_0;
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


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "Insert", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_SELF("getquerier", NULL, 0, _0, dbtype);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Get Update Querier object instance
 *
 * @param string dbtype
 * @return Update
 */
PHP_METHOD(Brisk_Vendor_Querier_QuerierAdapter, getUpdateQuerier) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *dbtype_param = NULL, *_0;
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


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "Update", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_SELF("getquerier", NULL, 0, _0, dbtype);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Get Delete Querier object instance
 *
 * @param string dbtype
 * @return Delete
 */
PHP_METHOD(Brisk_Vendor_Querier_QuerierAdapter, getDeleteQuerier) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *dbtype_param = NULL, *_0;
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


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "Delete", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_SELF("getquerier", NULL, 0, _0, dbtype);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	RETURN_MM();

}


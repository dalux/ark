
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
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/string.h"
#include "kernel/concat.h"


ZEPHIR_INIT_CLASS(Brisk_Toolkit_SQLBuilder) {

	ZEPHIR_REGISTER_CLASS(Brisk\\Toolkit, SQLBuilder, brisk, toolkit_sqlbuilder, brisk_toolkit_sqlbuilder_method_entry, 0);

	zend_declare_property_string(brisk_toolkit_sqlbuilder_ce, SL("_db_type"), "mysql", ZEND_ACC_PRIVATE|ZEND_ACC_STATIC TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Brisk_Toolkit_SQLBuilder, setDbType) {

	zval *dbtype_param = NULL;
	zval dbtype;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&dbtype);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &dbtype_param);

	if (UNEXPECTED(Z_TYPE_P(dbtype_param) != IS_STRING && Z_TYPE_P(dbtype_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'dbtype' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(dbtype_param) == IS_STRING)) {
		zephir_get_strval(&dbtype, dbtype_param);
	} else {
		ZEPHIR_INIT_VAR(&dbtype);
		ZVAL_EMPTY_STRING(&dbtype);
	}


	zend_update_static_property(brisk_toolkit_sqlbuilder_ce, ZEND_STRL("_db_type"), &dbtype);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Brisk_Toolkit_SQLBuilder, quote) {

	zend_string *_4$$4;
	zend_ulong _3$$4;
	zend_bool _0;
	zephir_fcall_cache_entry *_6 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval dbtype;
	zval *value, value_sub, *dbtype_param = NULL, type, _1, key$$4, val$$4, *_2$$4, _5$$5, _7$$7, _8$$7, _9$$7, _10$$8;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&key$$4);
	ZVAL_UNDEF(&val$$4);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_7$$7);
	ZVAL_UNDEF(&_8$$7);
	ZVAL_UNDEF(&_9$$7);
	ZVAL_UNDEF(&_10$$8);
	ZVAL_UNDEF(&dbtype);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &value, &dbtype_param);

	ZEPHIR_SEPARATE_PARAM(value);
	if (!dbtype_param) {
		ZEPHIR_INIT_VAR(&dbtype);
		ZVAL_STRING(&dbtype, "");
	} else {
	if (UNEXPECTED(Z_TYPE_P(dbtype_param) != IS_STRING && Z_TYPE_P(dbtype_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'dbtype' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(dbtype_param) == IS_STRING)) {
		zephir_get_strval(&dbtype, dbtype_param);
	} else {
		ZEPHIR_INIT_VAR(&dbtype);
		ZVAL_EMPTY_STRING(&dbtype);
	}
	}


	ZEPHIR_CPY_WRT(&type, &dbtype);
	if (ZEPHIR_IS_STRING(&type, "")) {
		ZEPHIR_OBS_NVAR(&type);
		zephir_read_static_property_ce(&type, brisk_toolkit_sqlbuilder_ce, SL("_db_type"), PH_NOISY_CC);
	}
	_0 = Z_TYPE_P(value) == IS_LONG;
	if (!(_0)) {
		ZEPHIR_CALL_FUNCTION(&_1, "is_float", NULL, 79, value);
		zephir_check_call_status();
		_0 = zephir_is_true(&_1);
	}
	if (Z_TYPE_P(value) == IS_ARRAY) {
		zephir_is_iterable(value, 1, "brisk/Toolkit/SQLBuilder.zep", 29);
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(value), _3$$4, _4$$4, _2$$4)
		{
			ZEPHIR_INIT_NVAR(&key$$4);
			if (_4$$4 != NULL) { 
				ZVAL_STR_COPY(&key$$4, _4$$4);
			} else {
				ZVAL_LONG(&key$$4, _3$$4);
			}
			ZEPHIR_INIT_NVAR(&val$$4);
			ZVAL_COPY(&val$$4, _2$$4);
			ZEPHIR_CALL_SELF(&_5$$5, "quote", &_6, 0, &val$$4);
			zephir_check_call_status();
			zephir_array_update_zval(value, &key$$4, &_5$$5, PH_COPY | PH_SEPARATE);
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&val$$4);
		ZEPHIR_INIT_NVAR(&key$$4);
		zephir_fast_join_str(return_value, SL(","), value TSRMLS_CC);
		RETURN_MM();
	} else if (_0) {
		RETVAL_ZVAL(value, 1, 0);
		RETURN_MM();
	}
	do {
		if (ZEPHIR_IS_STRING(&type, "oci")) {
			ZEPHIR_INIT_VAR(&_7$$7);
			ZEPHIR_INIT_VAR(&_8$$7);
			ZVAL_STRING(&_8$$7, "'");
			ZEPHIR_INIT_VAR(&_9$$7);
			ZVAL_STRING(&_9$$7, "''");
			zephir_fast_str_replace(&_7$$7, &_8$$7, &_9$$7, value TSRMLS_CC);
			ZEPHIR_CONCAT_SVS(return_value, "'", &_7$$7, "'");
			RETURN_MM();
		}
		ZEPHIR_INIT_VAR(&_10$$8);
		zephir_addslashes(&_10$$8, value TSRMLS_CC);
		ZEPHIR_CONCAT_SVS(return_value, "'", &_10$$8, "'");
		RETURN_MM();
	} while(0);

	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Brisk_Toolkit_SQLBuilder, select) {

	zend_class_entry *_2;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *dbtype_param = NULL, type, classname, _0, _1;
	zval dbtype;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&dbtype);
	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&classname);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &dbtype_param);

	if (!dbtype_param) {
		ZEPHIR_INIT_VAR(&dbtype);
		ZVAL_STRING(&dbtype, "");
	} else {
	if (UNEXPECTED(Z_TYPE_P(dbtype_param) != IS_STRING && Z_TYPE_P(dbtype_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'dbtype' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(dbtype_param) == IS_STRING)) {
		zephir_get_strval(&dbtype, dbtype_param);
	} else {
		ZEPHIR_INIT_VAR(&dbtype);
		ZVAL_EMPTY_STRING(&dbtype);
	}
	}


	ZEPHIR_CPY_WRT(&type, &dbtype);
	if (ZEPHIR_IS_STRING(&type, "")) {
		ZEPHIR_OBS_NVAR(&type);
		zephir_read_static_property_ce(&type, brisk_toolkit_sqlbuilder_ce, SL("_db_type"), PH_NOISY_CC);
	}
	ZEPHIR_INIT_VAR(&_0);
	zephir_ucfirst(&_0, &type);
	ZEPHIR_INIT_VAR(&classname);
	ZEPHIR_CONCAT_SV(&classname, "\\Brisk\\Toolkit\\SQLBuilder\\SelectBuilder\\", &_0);
	zephir_fetch_safe_class(&_1, &classname);
	_2 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_1), Z_STRLEN_P(&_1), ZEND_FETCH_CLASS_AUTO);
	object_init_ex(return_value, _2);
	if (zephir_has_constructor(return_value TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	RETURN_MM();

}

PHP_METHOD(Brisk_Toolkit_SQLBuilder, insert) {

	zend_class_entry *_2;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *dbtype_param = NULL, type, classname, _0, _1;
	zval dbtype;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&dbtype);
	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&classname);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &dbtype_param);

	if (!dbtype_param) {
		ZEPHIR_INIT_VAR(&dbtype);
		ZVAL_STRING(&dbtype, "");
	} else {
	if (UNEXPECTED(Z_TYPE_P(dbtype_param) != IS_STRING && Z_TYPE_P(dbtype_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'dbtype' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(dbtype_param) == IS_STRING)) {
		zephir_get_strval(&dbtype, dbtype_param);
	} else {
		ZEPHIR_INIT_VAR(&dbtype);
		ZVAL_EMPTY_STRING(&dbtype);
	}
	}


	ZEPHIR_CPY_WRT(&type, &dbtype);
	if (ZEPHIR_IS_STRING(&type, "")) {
		ZEPHIR_OBS_NVAR(&type);
		zephir_read_static_property_ce(&type, brisk_toolkit_sqlbuilder_ce, SL("_db_type"), PH_NOISY_CC);
	}
	ZEPHIR_INIT_VAR(&_0);
	zephir_ucfirst(&_0, &type);
	ZEPHIR_INIT_VAR(&classname);
	ZEPHIR_CONCAT_SV(&classname, "\\Brisk\\Toolkit\\SQLBuilder\\InsertBuilder\\", &_0);
	zephir_fetch_safe_class(&_1, &classname);
	_2 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_1), Z_STRLEN_P(&_1), ZEND_FETCH_CLASS_AUTO);
	object_init_ex(return_value, _2);
	if (zephir_has_constructor(return_value TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	RETURN_MM();

}

PHP_METHOD(Brisk_Toolkit_SQLBuilder, update) {

	zend_class_entry *_2;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *dbtype_param = NULL, type, classname, _0, _1;
	zval dbtype;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&dbtype);
	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&classname);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &dbtype_param);

	if (!dbtype_param) {
		ZEPHIR_INIT_VAR(&dbtype);
		ZVAL_STRING(&dbtype, "");
	} else {
	if (UNEXPECTED(Z_TYPE_P(dbtype_param) != IS_STRING && Z_TYPE_P(dbtype_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'dbtype' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(dbtype_param) == IS_STRING)) {
		zephir_get_strval(&dbtype, dbtype_param);
	} else {
		ZEPHIR_INIT_VAR(&dbtype);
		ZVAL_EMPTY_STRING(&dbtype);
	}
	}


	ZEPHIR_CPY_WRT(&type, &dbtype);
	if (ZEPHIR_IS_STRING(&type, "")) {
		ZEPHIR_OBS_NVAR(&type);
		zephir_read_static_property_ce(&type, brisk_toolkit_sqlbuilder_ce, SL("_db_type"), PH_NOISY_CC);
	}
	ZEPHIR_INIT_VAR(&_0);
	zephir_ucfirst(&_0, &type);
	ZEPHIR_INIT_VAR(&classname);
	ZEPHIR_CONCAT_SV(&classname, "\\Brisk\\Toolkit\\SQLBuilder\\UpdateBuilder\\", &_0);
	zephir_fetch_safe_class(&_1, &classname);
	_2 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_1), Z_STRLEN_P(&_1), ZEND_FETCH_CLASS_AUTO);
	object_init_ex(return_value, _2);
	if (zephir_has_constructor(return_value TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	RETURN_MM();

}

PHP_METHOD(Brisk_Toolkit_SQLBuilder, delete) {

	zend_class_entry *_2;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *dbtype_param = NULL, type, classname, _0, _1;
	zval dbtype;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&dbtype);
	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&classname);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &dbtype_param);

	if (!dbtype_param) {
		ZEPHIR_INIT_VAR(&dbtype);
		ZVAL_STRING(&dbtype, "");
	} else {
	if (UNEXPECTED(Z_TYPE_P(dbtype_param) != IS_STRING && Z_TYPE_P(dbtype_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'dbtype' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(dbtype_param) == IS_STRING)) {
		zephir_get_strval(&dbtype, dbtype_param);
	} else {
		ZEPHIR_INIT_VAR(&dbtype);
		ZVAL_EMPTY_STRING(&dbtype);
	}
	}


	ZEPHIR_CPY_WRT(&type, &dbtype);
	if (ZEPHIR_IS_STRING(&type, "")) {
		ZEPHIR_OBS_NVAR(&type);
		zephir_read_static_property_ce(&type, brisk_toolkit_sqlbuilder_ce, SL("_db_type"), PH_NOISY_CC);
	}
	ZEPHIR_INIT_VAR(&_0);
	zephir_ucfirst(&_0, &type);
	ZEPHIR_INIT_VAR(&classname);
	ZEPHIR_CONCAT_SV(&classname, "\\Brisk\\Toolkit\\SQLBuilder\\DeleteBuilder\\", &_0);
	zephir_fetch_safe_class(&_1, &classname);
	_2 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_1), Z_STRLEN_P(&_1), ZEND_FETCH_CLASS_AUTO);
	object_init_ex(return_value, _2);
	if (zephir_has_constructor(return_value TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	RETURN_MM();

}


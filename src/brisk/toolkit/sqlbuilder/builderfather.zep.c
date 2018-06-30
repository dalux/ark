
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
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/object.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"
#include "kernel/string.h"


ZEPHIR_INIT_CLASS(Brisk_Toolkit_SQLBuilder_BuilderFather) {

	ZEPHIR_REGISTER_CLASS(Brisk\\Toolkit\\SQLBuilder, BuilderFather, brisk, toolkit_sqlbuilder_builderfather, brisk_toolkit_sqlbuilder_builderfather_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_property_null(brisk_toolkit_sqlbuilder_builderfather_ce, SL("_db_type"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(brisk_toolkit_sqlbuilder_builderfather_ce, SL("_parts"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(brisk_toolkit_sqlbuilder_builderfather_ce, SL("_db_bind"), ZEND_ACC_PROTECTED TSRMLS_CC);

	brisk_toolkit_sqlbuilder_builderfather_ce->create_object = zephir_init_properties_Brisk_Toolkit_SQLBuilder_BuilderFather;
	return SUCCESS;

}

PHP_METHOD(Brisk_Toolkit_SQLBuilder_BuilderFather, where) {

	zval _0;
	zval *expr_param = NULL, *value = NULL, value_sub, val;
	zval expr;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&expr);
	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&val);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &expr_param, &value);

	if (UNEXPECTED(Z_TYPE_P(expr_param) != IS_STRING && Z_TYPE_P(expr_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'expr' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(expr_param) == IS_STRING)) {
		zephir_get_strval(&expr, expr_param);
	} else {
		ZEPHIR_INIT_VAR(&expr);
		ZVAL_EMPTY_STRING(&expr);
	}
	if (!value) {
		value = &value_sub;
		ZEPHIR_INIT_VAR(value);
		ZVAL_STRING(value, "");
	}


	ZEPHIR_INIT_VAR(&val);
	array_init(&val);
	if (!ZEPHIR_IS_STRING(value, "")) {
		if (!(Z_TYPE_P(value) == IS_ARRAY)) {
			ZEPHIR_INIT_NVAR(&val);
			zephir_create_array(&val, 1, 0 TSRMLS_CC);
			zephir_array_fast_append(&val, value);
		} else {
			ZEPHIR_CPY_WRT(&val, value);
		}
	}
	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 2, 0 TSRMLS_CC);
	zephir_array_update_string(&_0, SL("cond"), &expr, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_0, SL("val"), &val, PH_COPY | PH_SEPARATE);
	zephir_update_property_array_multi(this_ptr, SL("_parts"), &_0 TSRMLS_CC, SL("sa"), 3, SL("where"));
	RETURN_THIS();

}

PHP_METHOD(Brisk_Toolkit_SQLBuilder_BuilderFather, whereIn) {

	zend_bool _0;
	zephir_fcall_cache_entry *_3 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *field_param = NULL, *value = NULL, value_sub, expr, _1$$3, _2$$4, _4$$5, _5$$6;
	zval field;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&field);
	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&expr);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_5$$6);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &field_param, &value);

	if (UNEXPECTED(Z_TYPE_P(field_param) != IS_STRING && Z_TYPE_P(field_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'field' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(field_param) == IS_STRING)) {
		zephir_get_strval(&field, field_param);
	} else {
		ZEPHIR_INIT_VAR(&field);
		ZVAL_EMPTY_STRING(&field);
	}
	ZEPHIR_SEPARATE_PARAM(value);


	_0 = Z_TYPE_P(value) == IS_ARRAY;
	if (_0) {
		_0 = zephir_fast_count_int(value TSRMLS_CC) == 1;
	}
	if (zephir_instance_of_ev(value, brisk_toolkit_sqlbuilder_selectbuilder_ce TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(&_1$$3, value, "getrealsql", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(value, &_1$$3);
		ZEPHIR_INIT_VAR(&expr);
		ZEPHIR_CONCAT_VSVS(&expr, &field, " IN (", value, ")");
	} else if (_0) {
		ZEPHIR_CALL_FUNCTION(&_2$$4, "current", NULL, 1, value);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(value, &_2$$4);
		ZEPHIR_CALL_CE_STATIC(&_2$$4, brisk_toolkit_sqlbuilder_ce, "quote", &_3, 0, value);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&expr);
		ZEPHIR_CONCAT_VSV(&expr, &field, "=", &_2$$4);
	} else if (Z_TYPE_P(value) == IS_ARRAY) {
		ZEPHIR_CALL_CE_STATIC(&_4$$5, brisk_toolkit_sqlbuilder_ce, "quote", &_3, 0, value);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(value, &_4$$5);
		ZEPHIR_INIT_NVAR(&expr);
		ZEPHIR_CONCAT_VSVS(&expr, &field, " IN (", value, ")");
	} else {
		ZEPHIR_CALL_CE_STATIC(&_5$$6, brisk_toolkit_sqlbuilder_ce, "quote", &_3, 0, value);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&expr);
		ZEPHIR_CONCAT_VSV(&expr, &field, "=", &_5$$6);
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "where", NULL, 0, &expr);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Brisk_Toolkit_SQLBuilder_BuilderFather, whereNotIn) {

	zend_bool _0;
	zephir_fcall_cache_entry *_3 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *field_param = NULL, *value = NULL, value_sub, expr, _1$$3, _2$$4, _4$$5, _5$$6;
	zval field;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&field);
	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&expr);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_5$$6);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &field_param, &value);

	if (UNEXPECTED(Z_TYPE_P(field_param) != IS_STRING && Z_TYPE_P(field_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'field' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(field_param) == IS_STRING)) {
		zephir_get_strval(&field, field_param);
	} else {
		ZEPHIR_INIT_VAR(&field);
		ZVAL_EMPTY_STRING(&field);
	}
	ZEPHIR_SEPARATE_PARAM(value);


	_0 = Z_TYPE_P(value) == IS_ARRAY;
	if (_0) {
		_0 = zephir_fast_count_int(value TSRMLS_CC) == 1;
	}
	if (zephir_instance_of_ev(value, brisk_toolkit_sqlbuilder_selectbuilder_ce TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(&_1$$3, value, "getrealsql", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(value, &_1$$3);
		ZEPHIR_INIT_VAR(&expr);
		ZEPHIR_CONCAT_VSVS(&expr, &field, " NOT IN (", value, ")");
	} else if (_0) {
		ZEPHIR_CALL_FUNCTION(&_2$$4, "current", NULL, 1, value);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(value, &_2$$4);
		ZEPHIR_CALL_CE_STATIC(&_2$$4, brisk_toolkit_sqlbuilder_ce, "quote", &_3, 0, value);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&expr);
		ZEPHIR_CONCAT_VSV(&expr, &field, "!=", &_2$$4);
	} else if (Z_TYPE_P(value) == IS_ARRAY) {
		ZEPHIR_CALL_CE_STATIC(&_4$$5, brisk_toolkit_sqlbuilder_ce, "quote", &_3, 0, value);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(value, &_4$$5);
		ZEPHIR_INIT_NVAR(&expr);
		ZEPHIR_CONCAT_VSVS(&expr, &field, " NOT IN (", value, ")");
	} else {
		ZEPHIR_CALL_CE_STATIC(&_5$$6, brisk_toolkit_sqlbuilder_ce, "quote", &_3, 0, value);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&expr);
		ZEPHIR_CONCAT_VSV(&expr, &field, "!=", &_5$$6);
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "where", NULL, 0, &expr);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Brisk_Toolkit_SQLBuilder_BuilderFather, whereExists) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *query = NULL, query_sub, expr, _1, _2, _0$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&query_sub);
	ZVAL_UNDEF(&expr);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_0$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &query);

	ZEPHIR_SEPARATE_PARAM(query);


	ZEPHIR_INIT_VAR(&expr);
	ZVAL_STRING(&expr, "EXISTS (?)");
	if (zephir_instance_of_ev(query, brisk_toolkit_sqlbuilder_selectbuilder_ce TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(&_0$$3, query, "getrealsql", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(query, &_0$$3);
	}
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "?");
	zephir_fast_str_replace(&_1, &_2, query, &expr TSRMLS_CC);
	ZEPHIR_CPY_WRT(&expr, &_1);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "where", NULL, 0, &expr);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Brisk_Toolkit_SQLBuilder_BuilderFather, whereNotExists) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *query = NULL, query_sub, expr, _1, _2, _0$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&query_sub);
	ZVAL_UNDEF(&expr);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_0$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &query);

	ZEPHIR_SEPARATE_PARAM(query);


	ZEPHIR_INIT_VAR(&expr);
	ZVAL_STRING(&expr, "NOT EXISTS (?)");
	if (zephir_instance_of_ev(query, brisk_toolkit_sqlbuilder_selectbuilder_ce TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(&_0$$3, query, "getrealsql", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(query, &_0$$3);
	}
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "?");
	zephir_fast_str_replace(&_1, &_2, query, &expr TSRMLS_CC);
	ZEPHIR_CPY_WRT(&expr, &_1);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "where", NULL, 0, &expr);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Brisk_Toolkit_SQLBuilder_BuilderFather, whereLike) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *field_param = NULL, expr, *expr_param = NULL, *escape_param = NULL, _0, _1$$3;
	zval field, escape;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&field);
	ZVAL_UNDEF(&escape);
	ZVAL_UNDEF(&expr);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &field_param, &expr_param, &escape_param);

	if (UNEXPECTED(Z_TYPE_P(field_param) != IS_STRING && Z_TYPE_P(field_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'field' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(field_param) == IS_STRING)) {
		zephir_get_strval(&field, field_param);
	} else {
		ZEPHIR_INIT_VAR(&field);
		ZVAL_EMPTY_STRING(&field);
	}
	if (UNEXPECTED(Z_TYPE_P(expr_param) != IS_STRING && Z_TYPE_P(expr_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'expr' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(expr_param) == IS_STRING)) {
		zephir_get_strval(&expr, expr_param);
	} else {
		ZEPHIR_INIT_VAR(&expr);
		ZVAL_EMPTY_STRING(&expr);
	}
	if (!escape_param) {
		ZEPHIR_INIT_VAR(&escape);
		ZVAL_STRING(&escape, "");
	} else {
	if (UNEXPECTED(Z_TYPE_P(escape_param) != IS_STRING && Z_TYPE_P(escape_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'escape' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(escape_param) == IS_STRING)) {
		zephir_get_strval(&escape, escape_param);
	} else {
		ZEPHIR_INIT_VAR(&escape);
		ZVAL_EMPTY_STRING(&escape);
	}
	}


	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_CONCAT_VSVS(&_0, &field, " LIKE '", &expr, "'");
	ZEPHIR_CPY_WRT(&expr, &_0);
	if (!ZEPHIR_IS_STRING(&escape, "")) {
		ZEPHIR_INIT_VAR(&_1$$3);
		ZEPHIR_CONCAT_VSVS(&_1$$3, &expr, " ESCAPE '", &escape, "'");
		ZEPHIR_CPY_WRT(&expr, &_1$$3);
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "where", NULL, 0, &expr);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Brisk_Toolkit_SQLBuilder_BuilderFather, whereNotLike) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *field_param = NULL, expr, *expr_param = NULL, *escape_param = NULL, _0, _1$$3;
	zval field, escape;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&field);
	ZVAL_UNDEF(&escape);
	ZVAL_UNDEF(&expr);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &field_param, &expr_param, &escape_param);

	if (UNEXPECTED(Z_TYPE_P(field_param) != IS_STRING && Z_TYPE_P(field_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'field' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(field_param) == IS_STRING)) {
		zephir_get_strval(&field, field_param);
	} else {
		ZEPHIR_INIT_VAR(&field);
		ZVAL_EMPTY_STRING(&field);
	}
	if (UNEXPECTED(Z_TYPE_P(expr_param) != IS_STRING && Z_TYPE_P(expr_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'expr' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(expr_param) == IS_STRING)) {
		zephir_get_strval(&expr, expr_param);
	} else {
		ZEPHIR_INIT_VAR(&expr);
		ZVAL_EMPTY_STRING(&expr);
	}
	if (!escape_param) {
		ZEPHIR_INIT_VAR(&escape);
		ZVAL_STRING(&escape, "");
	} else {
	if (UNEXPECTED(Z_TYPE_P(escape_param) != IS_STRING && Z_TYPE_P(escape_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'escape' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(escape_param) == IS_STRING)) {
		zephir_get_strval(&escape, escape_param);
	} else {
		ZEPHIR_INIT_VAR(&escape);
		ZVAL_EMPTY_STRING(&escape);
	}
	}


	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_CONCAT_VSVS(&_0, &field, " NOT LIKE '", &expr, "'");
	ZEPHIR_CPY_WRT(&expr, &_0);
	if (!ZEPHIR_IS_STRING(&escape, "")) {
		ZEPHIR_INIT_VAR(&_1$$3);
		ZEPHIR_CONCAT_VSVS(&_1$$3, &expr, " ESCAPE '", &escape, "'");
		ZEPHIR_CPY_WRT(&expr, &_1$$3);
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "where", NULL, 0, &expr);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Brisk_Toolkit_SQLBuilder_BuilderFather, pickWherePart) {

	zend_string *_3$$3;
	zend_ulong _2$$3;
	zval where, where_part, _0, _12, key$$3, val$$3, part$$3, cond$$3, value$$3, *_1$$3, _4$$6, _6$$6, _7$$7, _9$$7, _10$$4, _11$$8;
	zephir_fcall_cache_entry *_5 = NULL, *_8 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&where);
	ZVAL_UNDEF(&where_part);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&key$$3);
	ZVAL_UNDEF(&val$$3);
	ZVAL_UNDEF(&part$$3);
	ZVAL_UNDEF(&cond$$3);
	ZVAL_UNDEF(&value$$3);
	ZVAL_UNDEF(&_4$$6);
	ZVAL_UNDEF(&_6$$6);
	ZVAL_UNDEF(&_7$$7);
	ZVAL_UNDEF(&_9$$7);
	ZVAL_UNDEF(&_10$$4);
	ZVAL_UNDEF(&_11$$8);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&where);
	array_init(&where);
	zephir_read_property(&_0, this_ptr, SL("_parts"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_OBS_VAR(&where_part);
	zephir_array_fetch_string(&where_part, &_0, SL("where"), PH_NOISY, "brisk/Toolkit/SQLBuilder/BuilderFather.zep", 108 TSRMLS_CC);
	if (!(Z_TYPE_P(&where_part) == IS_NULL)) {
		zephir_is_iterable(&where_part, 0, "brisk/Toolkit/SQLBuilder/BuilderFather.zep", 129);
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&where_part), _2$$3, _3$$3, _1$$3)
		{
			ZEPHIR_INIT_NVAR(&key$$3);
			if (_3$$3 != NULL) { 
				ZVAL_STR_COPY(&key$$3, _3$$3);
			} else {
				ZVAL_LONG(&key$$3, _2$$3);
			}
			ZEPHIR_INIT_NVAR(&val$$3);
			ZVAL_COPY(&val$$3, _1$$3);
			ZEPHIR_INIT_NVAR(&part$$3);
			ZVAL_STRING(&part$$3, "");
			ZEPHIR_OBS_NVAR(&cond$$3);
			zephir_array_fetch_string(&cond$$3, &val$$3, SL("cond"), PH_NOISY, "brisk/Toolkit/SQLBuilder/BuilderFather.zep", 114 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(&value$$3);
			zephir_array_fetch_string(&value$$3, &val$$3, SL("val"), PH_NOISY, "brisk/Toolkit/SQLBuilder/BuilderFather.zep", 115 TSRMLS_CC);
			if (Z_TYPE_P(&value$$3) == IS_NULL) {
				ZEPHIR_CPY_WRT(&part$$3, &cond$$3);
				if (zephir_is_instance_of(&cond$$3, SL("Brisk\\Toolkit\\SQLBuilder\\BuildFather") TSRMLS_CC)) {
					ZEPHIR_CALL_METHOD(&_4$$6, &cond$$3, "pickwherepart", &_5, 0);
					zephir_check_call_status();
					ZEPHIR_INIT_LNVAR(_6$$6);
					ZEPHIR_CONCAT_VSVS(&_6$$6, &part$$3, "(", &_4$$6, ")");
					ZEPHIR_CPY_WRT(&part$$3, &_6$$6);
				}
			} else {
				ZEPHIR_CALL_METHOD(&_7$$7, this_ptr, "_parseexpr", &_8, 0, &cond$$3, &value$$3);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_9$$7);
				ZEPHIR_CONCAT_VV(&_9$$7, &part$$3, &_7$$7);
				ZEPHIR_CPY_WRT(&part$$3, &_9$$7);
			}
			zephir_array_fetch_long(&_10$$4, &where_part, (zephir_get_numberval(&key$$3) + 1), PH_NOISY | PH_READONLY, "brisk/Toolkit/SQLBuilder/BuilderFather.zep", 124 TSRMLS_CC);
			if (!(Z_TYPE_P(&_10$$4) == IS_NULL)) {
				ZEPHIR_INIT_LNVAR(_11$$8);
				ZEPHIR_CONCAT_VS(&_11$$8, &part$$3, " AND ");
				ZEPHIR_CPY_WRT(&part$$3, &_11$$8);
			}
			zephir_array_append(&where, &part$$3, PH_SEPARATE, "brisk/Toolkit/SQLBuilder/BuilderFather.zep", 127);
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&val$$3);
		ZEPHIR_INIT_NVAR(&key$$3);
	}
	ZEPHIR_INIT_VAR(&_12);
	if (zephir_is_true(&where)) {
		zephir_fast_join_str(&_12, SL(" "), &where TSRMLS_CC);
	} else {
		ZVAL_STRING(&_12, "");
	}
	RETURN_CCTOR(&_12);

}

PHP_METHOD(Brisk_Toolkit_SQLBuilder_BuilderFather, getSQL) {

}

PHP_METHOD(Brisk_Toolkit_SQLBuilder_BuilderFather, getRealSQL) {

	zend_string *_2;
	zend_ulong _1;
	zval sql, bind, key, val, *_0, _3$$3, _4$$3, _6$$3, _7$$3;
	zephir_fcall_cache_entry *_5 = NULL, *_8 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sql);
	ZVAL_UNDEF(&bind);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&val);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$3);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&sql, this_ptr, "getsql", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&bind, this_ptr, "getbind", NULL, 0);
	zephir_check_call_status();
	zephir_is_iterable(&bind, 0, "brisk/Toolkit/SQLBuilder/BuilderFather.zep", 144);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&bind), _1, _2, _0)
	{
		ZEPHIR_INIT_NVAR(&key);
		if (_2 != NULL) { 
			ZVAL_STR_COPY(&key, _2);
		} else {
			ZVAL_LONG(&key, _1);
		}
		ZEPHIR_INIT_NVAR(&val);
		ZVAL_COPY(&val, _0);
		ZEPHIR_INIT_LNVAR(_3$$3);
		ZEPHIR_CONCAT_SVS(&_3$$3, "/", &key, "/");
		ZEPHIR_CALL_CE_STATIC(&_4$$3, brisk_toolkit_sqlbuilder_ce, "quote", &_5, 0, &val);
		zephir_check_call_status();
		ZVAL_LONG(&_6$$3, 1);
		ZEPHIR_CALL_FUNCTION(&_7$$3, "preg_replace", &_8, 2, &_3$$3, &_4$$3, &sql, &_6$$3);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&sql, &_7$$3);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&val);
	ZEPHIR_INIT_NVAR(&key);
	RETURN_CCTOR(&sql);

}

PHP_METHOD(Brisk_Toolkit_SQLBuilder_BuilderFather, getBind) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_db_bind");

}

PHP_METHOD(Brisk_Toolkit_SQLBuilder_BuilderFather, __toString) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();


	ZEPHIR_MM_GROW();

	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getrealsql", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Brisk_Toolkit_SQLBuilder_BuilderFather, _parseExpr) {

	zval _15$$8, _35$$13;
	zend_bool _8$$5, _26$$10;
	zend_string *_4$$3;
	zend_ulong _3$$3;
	zephir_fcall_cache_entry *_13 = NULL, *_18 = NULL, *_22 = NULL, *_31 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *expr_param = NULL, *value = NULL, value_sub, is_match, matches, _0, _1$$3, k$$3, v$$3, val$$3, *_2$$3, _5$$5, _6$$5, _7$$5, _9$$5, _10$$5, _11$$5, _19$$5, _20$$5, _21$$5, _12$$7, _14$$8, _16$$8, _17$$9, _23$$10, _24$$10, _25$$10, _27$$10, _28$$10, _29$$10, _30$$12, _32$$12, _33$$12, _34$$13, _36$$13, _37$$13, _38$$13;
	zval expr;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&expr);
	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&is_match);
	ZVAL_UNDEF(&matches);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&k$$3);
	ZVAL_UNDEF(&v$$3);
	ZVAL_UNDEF(&val$$3);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_19$$5);
	ZVAL_UNDEF(&_20$$5);
	ZVAL_UNDEF(&_21$$5);
	ZVAL_UNDEF(&_12$$7);
	ZVAL_UNDEF(&_14$$8);
	ZVAL_UNDEF(&_16$$8);
	ZVAL_UNDEF(&_17$$9);
	ZVAL_UNDEF(&_23$$10);
	ZVAL_UNDEF(&_24$$10);
	ZVAL_UNDEF(&_25$$10);
	ZVAL_UNDEF(&_27$$10);
	ZVAL_UNDEF(&_28$$10);
	ZVAL_UNDEF(&_29$$10);
	ZVAL_UNDEF(&_30$$12);
	ZVAL_UNDEF(&_32$$12);
	ZVAL_UNDEF(&_33$$12);
	ZVAL_UNDEF(&_34$$13);
	ZVAL_UNDEF(&_36$$13);
	ZVAL_UNDEF(&_37$$13);
	ZVAL_UNDEF(&_38$$13);
	ZVAL_UNDEF(&_15$$8);
	ZVAL_UNDEF(&_35$$13);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &expr_param, &value);

	if (UNEXPECTED(Z_TYPE_P(expr_param) != IS_STRING && Z_TYPE_P(expr_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'expr' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(expr_param) == IS_STRING)) {
		zephir_get_strval(&expr, expr_param);
	} else {
		ZEPHIR_INIT_VAR(&expr);
		ZVAL_EMPTY_STRING(&expr);
	}
	if (!value) {
		value = &value_sub;
		ZEPHIR_INIT_VAR(value);
		ZVAL_STRING(value, "");
	}


	ZEPHIR_INIT_VAR(&matches);
	array_init(&matches);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "/(\\?|\\:[\\w\\d]+)/i");
	ZEPHIR_INIT_VAR(&is_match);
	zephir_preg_match(&is_match, &_0, &expr, &matches, 1, 0 , 0  TSRMLS_CC);
	if (ZEPHIR_GT_LONG(&is_match, 0)) {
		zephir_array_fetch_long(&_1$$3, &matches, 1, PH_NOISY | PH_READONLY, "brisk/Toolkit/SQLBuilder/BuilderFather.zep", 163 TSRMLS_CC);
		ZEPHIR_CPY_WRT(&matches, &_1$$3);
		zephir_is_iterable(&matches, 0, "brisk/Toolkit/SQLBuilder/BuilderFather.zep", 195);
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&matches), _3$$3, _4$$3, _2$$3)
		{
			ZEPHIR_INIT_NVAR(&k$$3);
			if (_4$$3 != NULL) { 
				ZVAL_STR_COPY(&k$$3, _4$$3);
			} else {
				ZVAL_LONG(&k$$3, _3$$3);
			}
			ZEPHIR_INIT_NVAR(&v$$3);
			ZVAL_COPY(&v$$3, _2$$3);
			if (ZEPHIR_IS_STRING(&v$$3, "?")) {
				ZEPHIR_CPY_WRT(&val$$3, value);
				if (Z_TYPE_P(value) == IS_ARRAY) {
					ZEPHIR_OBS_NVAR(&val$$3);
					zephir_array_fetch(&val$$3, value, &k$$3, PH_NOISY, "brisk/Toolkit/SQLBuilder/BuilderFather.zep", 169 TSRMLS_CC);
				}
				ZEPHIR_INIT_NVAR(&_5$$5);
				ZEPHIR_INIT_NVAR(&_6$$5);
				ZEPHIR_INIT_NVAR(&_7$$5);
				ZVAL_STRING(&_7$$5, "/^\\{\\{.*?\\}\\}/");
				zephir_preg_match(&_6$$5, &_7$$5, &val$$3, &_5$$5, 0, 0 , 0  TSRMLS_CC);
				_8$$5 = zephir_is_true(&_6$$5);
				if (!(_8$$5)) {
					ZEPHIR_INIT_NVAR(&_9$$5);
					ZEPHIR_INIT_NVAR(&_10$$5);
					ZEPHIR_INIT_NVAR(&_11$$5);
					ZVAL_STRING(&_11$$5, "/.*?\\(.*?\\)/");
					zephir_preg_match(&_10$$5, &_11$$5, &val$$3, &_9$$5, 0, 0 , 0  TSRMLS_CC);
					_8$$5 = zephir_is_true(&_10$$5);
				}
				if (zephir_instance_of_ev(&val$$3, brisk_toolkit_sqlbuilder_builderfather_ce TSRMLS_CC)) {
					ZEPHIR_CALL_METHOD(&_12$$7, &val$$3, "getrealsql", &_13, 0);
					zephir_check_call_status();
					ZEPHIR_CPY_WRT(&val$$3, &_12$$7);
				} else if (_8$$5) {
					ZEPHIR_INIT_NVAR(&_14$$8);
					ZEPHIR_INIT_NVAR(&_15$$8);
					zephir_create_array(&_15$$8, 2, 0 TSRMLS_CC);
					ZEPHIR_INIT_NVAR(&_16$$8);
					ZVAL_STRING(&_16$$8, "{{");
					zephir_array_fast_append(&_15$$8, &_16$$8);
					ZEPHIR_INIT_NVAR(&_16$$8);
					ZVAL_STRING(&_16$$8, "}}");
					zephir_array_fast_append(&_15$$8, &_16$$8);
					ZEPHIR_INIT_NVAR(&_16$$8);
					ZVAL_STRING(&_16$$8, "");
					zephir_fast_str_replace(&_14$$8, &_15$$8, &_16$$8, &val$$3 TSRMLS_CC);
					ZEPHIR_CPY_WRT(&val$$3, &_14$$8);
				} else {
					ZEPHIR_CALL_CE_STATIC(&_17$$9, brisk_toolkit_sqlbuilder_ce, "quote", &_18, 0, &val$$3);
					zephir_check_call_status();
					ZEPHIR_CPY_WRT(&val$$3, &_17$$9);
				}
				ZEPHIR_INIT_NVAR(&_19$$5);
				ZVAL_STRING(&_19$$5, "/\\?/");
				ZVAL_LONG(&_20$$5, 1);
				ZEPHIR_CALL_FUNCTION(&_21$$5, "preg_replace", &_22, 2, &_19$$5, &val$$3, &expr, &_20$$5);
				zephir_check_call_status();
				zephir_get_strval(&expr, &_21$$5);
			} else {
				ZEPHIR_CPY_WRT(&val$$3, value);
				if (Z_TYPE_P(value) == IS_ARRAY) {
					ZEPHIR_OBS_NVAR(&val$$3);
					zephir_array_fetch(&val$$3, value, &k$$3, PH_NOISY, "brisk/Toolkit/SQLBuilder/BuilderFather.zep", 182 TSRMLS_CC);
				}
				ZEPHIR_INIT_NVAR(&_23$$10);
				ZEPHIR_INIT_NVAR(&_24$$10);
				ZEPHIR_INIT_NVAR(&_25$$10);
				ZVAL_STRING(&_25$$10, "/^\\{\\{.*?\\}\\}/");
				zephir_preg_match(&_24$$10, &_25$$10, &val$$3, &_23$$10, 0, 0 , 0  TSRMLS_CC);
				_26$$10 = zephir_is_true(&_24$$10);
				if (!(_26$$10)) {
					ZEPHIR_INIT_NVAR(&_27$$10);
					ZEPHIR_INIT_NVAR(&_28$$10);
					ZEPHIR_INIT_NVAR(&_29$$10);
					ZVAL_STRING(&_29$$10, "/.*?\\(.*?\\)/");
					zephir_preg_match(&_28$$10, &_29$$10, &val$$3, &_27$$10, 0, 0 , 0  TSRMLS_CC);
					_26$$10 = zephir_is_true(&_28$$10);
				}
				if (zephir_instance_of_ev(&val$$3, brisk_toolkit_sqlbuilder_builderfather_ce TSRMLS_CC)) {
					ZEPHIR_CALL_METHOD(&_30$$12, &val$$3, "getrealsql", &_31, 0);
					zephir_check_call_status();
					ZEPHIR_CPY_WRT(&val$$3, &_30$$12);
					ZEPHIR_INIT_NVAR(&_32$$12);
					ZVAL_STRING(&_32$$12, "/v/");
					ZVAL_LONG(&_33$$12, 1);
					ZEPHIR_CALL_FUNCTION(&_30$$12, "preg_replace", &_22, 2, &_32$$12, &val$$3, &expr, &_33$$12);
					zephir_check_call_status();
					zephir_get_strval(&expr, &_30$$12);
				} else if (_26$$10) {
					ZEPHIR_INIT_NVAR(&_34$$13);
					ZEPHIR_INIT_NVAR(&_35$$13);
					zephir_create_array(&_35$$13, 2, 0 TSRMLS_CC);
					ZEPHIR_INIT_NVAR(&_36$$13);
					ZVAL_STRING(&_36$$13, "{{");
					zephir_array_fast_append(&_35$$13, &_36$$13);
					ZEPHIR_INIT_NVAR(&_36$$13);
					ZVAL_STRING(&_36$$13, "}}");
					zephir_array_fast_append(&_35$$13, &_36$$13);
					ZEPHIR_INIT_NVAR(&_36$$13);
					ZVAL_STRING(&_36$$13, "");
					zephir_fast_str_replace(&_34$$13, &_35$$13, &_36$$13, &val$$3 TSRMLS_CC);
					ZEPHIR_CPY_WRT(&val$$3, &_34$$13);
					ZEPHIR_INIT_NVAR(&_34$$13);
					ZVAL_STRING(&_34$$13, "/v/");
					ZVAL_LONG(&_37$$13, 1);
					ZEPHIR_CALL_FUNCTION(&_38$$13, "preg_replace", &_22, 2, &_34$$13, &val$$3, &expr, &_37$$13);
					zephir_check_call_status();
					zephir_get_strval(&expr, &_38$$13);
				} else {
					zephir_update_property_array(this_ptr, SL("_db_bind"), &v$$3, &val$$3 TSRMLS_CC);
				}
			}
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&v$$3);
		ZEPHIR_INIT_NVAR(&k$$3);
	}
	RETURN_CTOR(&expr);

}

zend_object *zephir_init_properties_Brisk_Toolkit_SQLBuilder_BuilderFather(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _2, _1$$3, _3$$4;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("_db_bind"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval(this_ptr, SL("_db_bind"), &_1$$3);
		}
		zephir_read_property(&_2, this_ptr, SL("_parts"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval(this_ptr, SL("_parts"), &_3$$4);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}


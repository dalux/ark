
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
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/string.h"
#include "kernel/concat.h"
#include "kernel/object.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"


ZEPHIR_INIT_CLASS(Brisk_Sql_SqlFather) {

	ZEPHIR_REGISTER_CLASS(Brisk\\Sql, SqlFather, brisk, sql_sqlfather, brisk_sql_sqlfather_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_property_string(brisk_sql_sqlfather_ce, SL("_db_type"), "", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(brisk_sql_sqlfather_ce, SL("_parts"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_string(brisk_sql_sqlfather_ce, SL("_sql"), "", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(brisk_sql_sqlfather_ce, SL("_db_bind"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_bool(brisk_sql_sqlfather_ce, SL("_compiled"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	brisk_sql_sqlfather_ce->create_object = zephir_init_properties_Brisk_Sql_SqlFather;
	return SUCCESS;

}

/**
 * Put quotation marks on a field
 *
 * @param mixed value
 * @param string dbtype
 * @return string
 */
PHP_METHOD(Brisk_Sql_SqlFather, quote) {

	HashTable *_3$$3;
	HashPosition _2$$3;
	zend_bool _0;
	zephir_fcall_cache_entry *_6 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *value, *_1 = NULL, *_7, *key$$3 = NULL, *val$$3 = NULL, **_4$$3, *_5$$4 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &value);

	ZEPHIR_SEPARATE_PARAM(value);


	_0 = Z_TYPE_P(value) == IS_LONG;
	if (!(_0)) {
		ZEPHIR_CALL_FUNCTION(&_1, "is_float", NULL, 1, value);
		zephir_check_call_status();
		_0 = zephir_is_true(_1);
	}
	if (Z_TYPE_P(value) == IS_ARRAY) {
		zephir_is_iterable(value, &_3$$3, &_2$$3, 1, 0, "brisk/Sql/SqlFather.zep", 26);
		for (
		  ; zend_hash_get_current_data_ex(_3$$3, (void**) &_4$$3, &_2$$3) == SUCCESS
		  ; zend_hash_move_forward_ex(_3$$3, &_2$$3)
		) {
			ZEPHIR_GET_HMKEY(key$$3, _3$$3, _2$$3);
			ZEPHIR_GET_HVALUE(val$$3, _4$$3);
			ZEPHIR_CALL_METHOD(&_5$$4, this_ptr, "quote", &_6, 2, val$$3);
			zephir_check_call_status();
			zephir_array_update_zval(&value, key$$3, &_5$$4, PH_COPY | PH_SEPARATE);
		}
		zend_hash_destroy(_3$$3);
		FREE_HASHTABLE(_3$$3);
		zephir_fast_join_str(return_value, SL(","), value TSRMLS_CC);
		RETURN_MM();
	} else if (_0) {
		RETVAL_ZVAL(value, 1, 0);
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(_7);
	zephir_addslashes(_7, value TSRMLS_CC);
	ZEPHIR_CONCAT_SVS(return_value, "'", _7, "'");
	RETURN_MM();

}

/**
 * Setting the sql statement where condition
 *
 * @param string expr
 * @param mixed dbtype
 * @return SqlFather
 */
PHP_METHOD(Brisk_Sql_SqlFather, where) {

	zval *_0;
	zval *expr_param = NULL, *value = NULL, *val = NULL;
	zval *expr = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &expr_param, &value);

	if (UNEXPECTED(Z_TYPE_P(expr_param) != IS_STRING && Z_TYPE_P(expr_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'expr' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(expr_param) == IS_STRING)) {
		zephir_get_strval(expr, expr_param);
	} else {
		ZEPHIR_INIT_VAR(expr);
		ZVAL_EMPTY_STRING(expr);
	}
	if (!value) {
		ZEPHIR_INIT_VAR(value);
		ZVAL_STRING(value, "", 1);
	}


	ZEPHIR_INIT_VAR(val);
	array_init(val);
	if (!ZEPHIR_IS_STRING(value, "")) {
		if (!(Z_TYPE_P(value) == IS_ARRAY)) {
			ZEPHIR_INIT_NVAR(val);
			zephir_create_array(val, 1, 0 TSRMLS_CC);
			zephir_array_fast_append(val, value);
		} else {
			ZEPHIR_CPY_WRT(val, value);
		}
	}
	ZEPHIR_INIT_VAR(_0);
	zephir_create_array(_0, 2, 0 TSRMLS_CC);
	zephir_array_update_string(&_0, SL("cond"), &expr, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_0, SL("val"), &val, PH_COPY | PH_SEPARATE);
	zephir_update_property_array_multi(this_ptr, SL("_parts"), &_0 TSRMLS_CC, SL("sa"), 3, SL("where"));
	RETURN_THIS();

}

/**
 * Setting the sql statement whereIn condition
 *
 * @param string field
 * @param mixed value
 * @return SqlFather
 */
PHP_METHOD(Brisk_Sql_SqlFather, whereIn) {

	zend_bool _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *field_param = NULL, *value = NULL, *expr = NULL, *_1$$3 = NULL, *_2$$4 = NULL, *_3$$5 = NULL, *_4$$6 = NULL;
	zval *field = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &field_param, &value);

	if (UNEXPECTED(Z_TYPE_P(field_param) != IS_STRING && Z_TYPE_P(field_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'field' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(field_param) == IS_STRING)) {
		zephir_get_strval(field, field_param);
	} else {
		ZEPHIR_INIT_VAR(field);
		ZVAL_EMPTY_STRING(field);
	}
	ZEPHIR_SEPARATE_PARAM(value);


	_0 = Z_TYPE_P(value) == IS_ARRAY;
	if (_0) {
		_0 = zephir_fast_count_int(value TSRMLS_CC) == 1;
	}
	if (zephir_instance_of_ev(value, brisk_sql_select_ce TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(&_1$$3, value, "getrealsql", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(value, _1$$3);
		ZEPHIR_INIT_VAR(expr);
		ZEPHIR_CONCAT_VSVS(expr, field, " IN (", value, ")");
	} else if (_0) {
		ZEPHIR_MAKE_REF(value);
		ZEPHIR_CALL_FUNCTION(&_2$$4, "current", NULL, 3, value);
		ZEPHIR_UNREF(value);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(value, _2$$4);
		ZEPHIR_CALL_METHOD(&_2$$4, this_ptr, "quote", NULL, 0, value);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(expr);
		ZEPHIR_CONCAT_VSV(expr, field, "=", _2$$4);
	} else if (Z_TYPE_P(value) == IS_ARRAY) {
		ZEPHIR_CALL_METHOD(&_3$$5, this_ptr, "quote", NULL, 2, value);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(value, _3$$5);
		ZEPHIR_INIT_NVAR(expr);
		ZEPHIR_CONCAT_VSVS(expr, field, " IN (", value, ")");
	} else {
		ZEPHIR_CALL_METHOD(&_4$$6, this_ptr, "quote", NULL, 2, value);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(expr);
		ZEPHIR_CONCAT_VSV(expr, field, "=", _4$$6);
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "where", NULL, 0, expr);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Setting the sql statement whereNotIn condition
 *
 * @param string field
 * @param mixed value
 * @return SqlFather
 */
PHP_METHOD(Brisk_Sql_SqlFather, whereNotIn) {

	zend_bool _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *field_param = NULL, *value = NULL, *expr = NULL, *_1$$3 = NULL, *_2$$4 = NULL, *_3$$5 = NULL, *_4$$6 = NULL;
	zval *field = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &field_param, &value);

	if (UNEXPECTED(Z_TYPE_P(field_param) != IS_STRING && Z_TYPE_P(field_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'field' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(field_param) == IS_STRING)) {
		zephir_get_strval(field, field_param);
	} else {
		ZEPHIR_INIT_VAR(field);
		ZVAL_EMPTY_STRING(field);
	}
	ZEPHIR_SEPARATE_PARAM(value);


	_0 = Z_TYPE_P(value) == IS_ARRAY;
	if (_0) {
		_0 = zephir_fast_count_int(value TSRMLS_CC) == 1;
	}
	if (zephir_instance_of_ev(value, brisk_sql_select_ce TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(&_1$$3, value, "getrealsql", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(value, _1$$3);
		ZEPHIR_INIT_VAR(expr);
		ZEPHIR_CONCAT_VSVS(expr, field, " NOT IN (", value, ")");
	} else if (_0) {
		ZEPHIR_MAKE_REF(value);
		ZEPHIR_CALL_FUNCTION(&_2$$4, "current", NULL, 3, value);
		ZEPHIR_UNREF(value);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(value, _2$$4);
		ZEPHIR_CALL_METHOD(&_2$$4, this_ptr, "quote", NULL, 0, value);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(expr);
		ZEPHIR_CONCAT_VSV(expr, field, "!=", _2$$4);
	} else if (Z_TYPE_P(value) == IS_ARRAY) {
		ZEPHIR_CALL_METHOD(&_3$$5, this_ptr, "quote", NULL, 2, value);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(value, _3$$5);
		ZEPHIR_INIT_NVAR(expr);
		ZEPHIR_CONCAT_VSVS(expr, field, " NOT IN (", value, ")");
	} else {
		ZEPHIR_CALL_METHOD(&_4$$6, this_ptr, "quote", NULL, 2, value);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(expr);
		ZEPHIR_CONCAT_VSV(expr, field, "!=", _4$$6);
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "where", NULL, 0, expr);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Setting the sql statement whereExists condition
 *
 * @param string query
 * @return SqlFather
 */
PHP_METHOD(Brisk_Sql_SqlFather, whereExists) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *query = NULL, *expr = NULL, *_1, _2, *_0$$3 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &query);

	ZEPHIR_SEPARATE_PARAM(query);


	ZEPHIR_INIT_VAR(expr);
	ZVAL_STRING(expr, "EXISTS (?)", 1);
	if (zephir_instance_of_ev(query, brisk_sql_select_ce TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(&_0$$3, query, "getrealsql", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(query, _0$$3);
	}
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_STRING(&_2, "?", 0);
	zephir_fast_str_replace(&_1, &_2, query, expr TSRMLS_CC);
	ZEPHIR_CPY_WRT(expr, _1);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "where", NULL, 0, expr);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Setting the sql statement whereNotExists condition
 *
 * @param string query
 * @return SqlFather
 */
PHP_METHOD(Brisk_Sql_SqlFather, whereNotExists) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *query = NULL, *expr = NULL, *_1, _2, *_0$$3 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &query);

	ZEPHIR_SEPARATE_PARAM(query);


	ZEPHIR_INIT_VAR(expr);
	ZVAL_STRING(expr, "NOT EXISTS (?)", 1);
	if (zephir_instance_of_ev(query, brisk_sql_select_ce TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(&_0$$3, query, "getrealsql", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(query, _0$$3);
	}
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_STRING(&_2, "?", 0);
	zephir_fast_str_replace(&_1, &_2, query, expr TSRMLS_CC);
	ZEPHIR_CPY_WRT(expr, _1);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "where", NULL, 0, expr);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Setting the sql statement whereLike condition
 *
 * @param string field
 * @param string expr
 * @param string escape
 * @return SqlFather
 */
PHP_METHOD(Brisk_Sql_SqlFather, whereLike) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *field_param = NULL, *expr = NULL, *expr_param = NULL, *escape_param = NULL, *_0, *_1$$3;
	zval *field = NULL, *escape = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &field_param, &expr_param, &escape_param);

	if (UNEXPECTED(Z_TYPE_P(field_param) != IS_STRING && Z_TYPE_P(field_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'field' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(field_param) == IS_STRING)) {
		zephir_get_strval(field, field_param);
	} else {
		ZEPHIR_INIT_VAR(field);
		ZVAL_EMPTY_STRING(field);
	}
	if (UNEXPECTED(Z_TYPE_P(expr_param) != IS_STRING && Z_TYPE_P(expr_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'expr' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(expr_param) == IS_STRING)) {
		zephir_get_strval(expr, expr_param);
	} else {
		ZEPHIR_INIT_VAR(expr);
		ZVAL_EMPTY_STRING(expr);
	}
	if (!escape_param) {
		ZEPHIR_INIT_VAR(escape);
		ZVAL_STRING(escape, "", 1);
	} else {
	if (UNEXPECTED(Z_TYPE_P(escape_param) != IS_STRING && Z_TYPE_P(escape_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'escape' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(escape_param) == IS_STRING)) {
		zephir_get_strval(escape, escape_param);
	} else {
		ZEPHIR_INIT_VAR(escape);
		ZVAL_EMPTY_STRING(escape);
	}
	}


	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_CONCAT_VSVS(_0, field, " LIKE '", expr, "'");
	ZEPHIR_CPY_WRT(expr, _0);
	if (!ZEPHIR_IS_STRING(escape, "")) {
		ZEPHIR_INIT_VAR(_1$$3);
		ZEPHIR_CONCAT_VSVS(_1$$3, expr, " ESCAPE '", escape, "'");
		ZEPHIR_CPY_WRT(expr, _1$$3);
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "where", NULL, 0, expr);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Setting the sql statement whereNotLike condition
 *
 * @param string field
 * @param string expr
 * @param string escape
 * @return SqlFather
 */
PHP_METHOD(Brisk_Sql_SqlFather, whereNotLike) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *field_param = NULL, *expr = NULL, *expr_param = NULL, *escape_param = NULL, *_0, *_1$$3;
	zval *field = NULL, *escape = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &field_param, &expr_param, &escape_param);

	if (UNEXPECTED(Z_TYPE_P(field_param) != IS_STRING && Z_TYPE_P(field_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'field' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(field_param) == IS_STRING)) {
		zephir_get_strval(field, field_param);
	} else {
		ZEPHIR_INIT_VAR(field);
		ZVAL_EMPTY_STRING(field);
	}
	if (UNEXPECTED(Z_TYPE_P(expr_param) != IS_STRING && Z_TYPE_P(expr_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'expr' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(expr_param) == IS_STRING)) {
		zephir_get_strval(expr, expr_param);
	} else {
		ZEPHIR_INIT_VAR(expr);
		ZVAL_EMPTY_STRING(expr);
	}
	if (!escape_param) {
		ZEPHIR_INIT_VAR(escape);
		ZVAL_STRING(escape, "", 1);
	} else {
	if (UNEXPECTED(Z_TYPE_P(escape_param) != IS_STRING && Z_TYPE_P(escape_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'escape' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(escape_param) == IS_STRING)) {
		zephir_get_strval(escape, escape_param);
	} else {
		ZEPHIR_INIT_VAR(escape);
		ZVAL_EMPTY_STRING(escape);
	}
	}


	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_CONCAT_VSVS(_0, field, " NOT LIKE '", expr, "'");
	ZEPHIR_CPY_WRT(expr, _0);
	if (!ZEPHIR_IS_STRING(escape, "")) {
		ZEPHIR_INIT_VAR(_1$$3);
		ZEPHIR_CONCAT_VSVS(_1$$3, expr, " ESCAPE '", escape, "'");
		ZEPHIR_CPY_WRT(expr, _1$$3);
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "where", NULL, 0, expr);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Get the where fragment in the sql statement
 *
 * @return string
 */
PHP_METHOD(Brisk_Sql_SqlFather, pickWherePart) {

	HashTable *_2$$3;
	HashPosition _1$$3;
	zval *where = NULL, *where_part = NULL, *_0, *_12, *key$$3 = NULL, *val$$3 = NULL, *part$$3 = NULL, *cond$$3 = NULL, *value$$3 = NULL, **_3$$3, *_4$$6 = NULL, *_6$$6 = NULL, *_7$$7 = NULL, *_9$$7 = NULL, *_10$$4, *_11$$8 = NULL;
	zephir_fcall_cache_entry *_5 = NULL, *_8 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(where);
	array_init(where);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_parts"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(where_part);
	zephir_array_fetch_string(&where_part, _0, SL("where"), PH_NOISY, "brisk/Sql/SqlFather.zep", 183 TSRMLS_CC);
	if (!(Z_TYPE_P(where_part) == IS_NULL)) {
		zephir_is_iterable(where_part, &_2$$3, &_1$$3, 0, 0, "brisk/Sql/SqlFather.zep", 204);
		for (
		  ; zend_hash_get_current_data_ex(_2$$3, (void**) &_3$$3, &_1$$3) == SUCCESS
		  ; zend_hash_move_forward_ex(_2$$3, &_1$$3)
		) {
			ZEPHIR_GET_HMKEY(key$$3, _2$$3, _1$$3);
			ZEPHIR_GET_HVALUE(val$$3, _3$$3);
			ZEPHIR_INIT_NVAR(part$$3);
			ZVAL_STRING(part$$3, "", 1);
			ZEPHIR_OBS_NVAR(cond$$3);
			zephir_array_fetch_string(&cond$$3, val$$3, SL("cond"), PH_NOISY, "brisk/Sql/SqlFather.zep", 189 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(value$$3);
			zephir_array_fetch_string(&value$$3, val$$3, SL("val"), PH_NOISY, "brisk/Sql/SqlFather.zep", 190 TSRMLS_CC);
			if (Z_TYPE_P(value$$3) == IS_NULL) {
				ZEPHIR_CPY_WRT(part$$3, cond$$3);
				if (zephir_instance_of_ev(cond$$3, brisk_sql_sqlfather_ce TSRMLS_CC)) {
					ZEPHIR_CALL_METHOD(&_4$$6, cond$$3, "pickwherepart", &_5, 0);
					zephir_check_call_status();
					ZEPHIR_INIT_LNVAR(_6$$6);
					ZEPHIR_CONCAT_VSVS(_6$$6, part$$3, "(", _4$$6, ")");
					ZEPHIR_CPY_WRT(part$$3, _6$$6);
				}
			} else {
				ZEPHIR_CALL_METHOD(&_7$$7, this_ptr, "_parseexpr", &_8, 0, cond$$3, value$$3);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_9$$7);
				ZEPHIR_CONCAT_VV(_9$$7, part$$3, _7$$7);
				ZEPHIR_CPY_WRT(part$$3, _9$$7);
			}
			zephir_array_fetch_long(&_10$$4, where_part, (zephir_get_numberval(key$$3) + 1), PH_NOISY | PH_READONLY, "brisk/Sql/SqlFather.zep", 199 TSRMLS_CC);
			if (!(Z_TYPE_P(_10$$4) == IS_NULL)) {
				ZEPHIR_INIT_LNVAR(_11$$8);
				ZEPHIR_CONCAT_VS(_11$$8, part$$3, " AND ");
				ZEPHIR_CPY_WRT(part$$3, _11$$8);
			}
			zephir_array_append(&where, part$$3, PH_SEPARATE, "brisk/Sql/SqlFather.zep", 202);
		}
	}
	ZEPHIR_INIT_VAR(_12);
	if (zephir_is_true(where)) {
		zephir_fast_join_str(_12, SL(" "), where TSRMLS_CC);
	} else {
		ZVAL_STRING(_12, "", 1);
	}
	RETURN_CCTOR(_12);

}

/**
 * Get the bind data
 *
 * @return array
 */
PHP_METHOD(Brisk_Sql_SqlFather, getBind) {

	

	RETURN_MEMBER(getThis(), "_db_bind");

}

/**
 * Get the full sql statement
 *
 * @return string
 */
PHP_METHOD(Brisk_Sql_SqlFather, getSQL) {

	zval *_0;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_compiled"), PH_NOISY_CC);
	if (!zephir_is_true(_0)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "compile", NULL, 0);
		zephir_check_call_status();
	}
	RETURN_MM_MEMBER(getThis(), "_sql");

}

/**
 * Get the full sql statement
 *
 * @return string
 */
PHP_METHOD(Brisk_Sql_SqlFather, getRealSQL) {

	HashTable *_1;
	HashPosition _0;
	zval *sql = NULL, *bind = NULL, *key = NULL, *val = NULL, **_2, *_3$$3 = NULL, *_4$$3 = NULL, *_6$$3 = NULL, *_7$$3 = NULL;
	zephir_fcall_cache_entry *_5 = NULL, *_8 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&sql, this_ptr, "getsql", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&bind, this_ptr, "getbind", NULL, 0);
	zephir_check_call_status();
	zephir_is_iterable(bind, &_1, &_0, 0, 0, "brisk/Sql/SqlFather.zep", 245);
	for (
	  ; zend_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zend_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HMKEY(key, _1, _0);
		ZEPHIR_GET_HVALUE(val, _2);
		ZEPHIR_INIT_LNVAR(_3$$3);
		ZEPHIR_CONCAT_SVS(_3$$3, "/", key, "/");
		ZEPHIR_CALL_METHOD(&_4$$3, this_ptr, "quote", &_5, 0, val);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_6$$3);
		ZVAL_LONG(_6$$3, 1);
		ZEPHIR_CALL_FUNCTION(&_7$$3, "preg_replace", &_8, 4, _3$$3, _4$$3, sql, _6$$3);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(sql, _7$$3);
	}
	RETURN_CCTOR(sql);

}

PHP_METHOD(Brisk_Sql_SqlFather, __toString) {

	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getrealsql", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Compile the sql statment and query bind parameter
 *
 * @return SqlFather
 */
PHP_METHOD(Brisk_Sql_SqlFather, compile) {

}

PHP_METHOD(Brisk_Sql_SqlFather, _parseExpr) {

	zval *_15$$8 = NULL, *_36$$13 = NULL;
	zend_bool _8$$5, _27$$10;
	HashTable *_3$$3;
	HashPosition _2$$3;
	zephir_fcall_cache_entry *_13 = NULL, *_19 = NULL, *_23 = NULL, *_32 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *expr_param = NULL, *value = NULL, *is_match = NULL, *matches = NULL, _0, *_1$$3, *k$$3 = NULL, *v$$3 = NULL, *val$$3 = NULL, **_4$$3, *_5$$5 = NULL, *_6$$5 = NULL, _7$$5 = zval_used_for_init, *_9$$5 = NULL, *_10$$5 = NULL, _11$$5 = zval_used_for_init, *_20$$5 = NULL, *_21$$5 = NULL, *_22$$5 = NULL, *_12$$7 = NULL, *_14$$8 = NULL, *_16$$8 = NULL, _17$$8 = zval_used_for_init, *_18$$9 = NULL, *_24$$10 = NULL, *_25$$10 = NULL, _26$$10 = zval_used_for_init, *_28$$10 = NULL, *_29$$10 = NULL, _30$$10 = zval_used_for_init, *_31$$12 = NULL, *_33$$12 = NULL, *_34$$12 = NULL, *_35$$13 = NULL, *_37$$13 = NULL, _38$$13 = zval_used_for_init, *_39$$13 = NULL;
	zval *expr = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &expr_param, &value);

	if (UNEXPECTED(Z_TYPE_P(expr_param) != IS_STRING && Z_TYPE_P(expr_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'expr' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(expr_param) == IS_STRING)) {
		zephir_get_strval(expr, expr_param);
	} else {
		ZEPHIR_INIT_VAR(expr);
		ZVAL_EMPTY_STRING(expr);
	}
	if (!value) {
		ZEPHIR_INIT_VAR(value);
		ZVAL_STRING(value, "", 1);
	}


	ZEPHIR_INIT_VAR(matches);
	array_init(matches);
	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "/(\\?|\\:[\\w\\d]+)/i", 0);
	ZEPHIR_INIT_VAR(is_match);
	zephir_preg_match(is_match, &_0, expr, matches, 1, 0 , 0  TSRMLS_CC);
	if (ZEPHIR_GT_LONG(is_match, 0)) {
		zephir_array_fetch_long(&_1$$3, matches, 1, PH_NOISY | PH_READONLY, "brisk/Sql/SqlFather.zep", 266 TSRMLS_CC);
		ZEPHIR_CPY_WRT(matches, _1$$3);
		zephir_is_iterable(matches, &_3$$3, &_2$$3, 0, 0, "brisk/Sql/SqlFather.zep", 298);
		for (
		  ; zend_hash_get_current_data_ex(_3$$3, (void**) &_4$$3, &_2$$3) == SUCCESS
		  ; zend_hash_move_forward_ex(_3$$3, &_2$$3)
		) {
			ZEPHIR_GET_HMKEY(k$$3, _3$$3, _2$$3);
			ZEPHIR_GET_HVALUE(v$$3, _4$$3);
			if (ZEPHIR_IS_STRING(v$$3, "?")) {
				ZEPHIR_CPY_WRT(val$$3, value);
				if (Z_TYPE_P(value) == IS_ARRAY) {
					ZEPHIR_OBS_NVAR(val$$3);
					zephir_array_fetch(&val$$3, value, k$$3, PH_NOISY, "brisk/Sql/SqlFather.zep", 272 TSRMLS_CC);
				}
				ZEPHIR_INIT_NVAR(_5$$5);
				ZEPHIR_INIT_NVAR(_6$$5);
				ZEPHIR_SINIT_NVAR(_7$$5);
				ZVAL_STRING(&_7$$5, "/^\\{\\{.*?\\}\\}/", 0);
				zephir_preg_match(_6$$5, &_7$$5, val$$3, _5$$5, 0, 0 , 0  TSRMLS_CC);
				_8$$5 = zephir_is_true(_6$$5);
				if (!(_8$$5)) {
					ZEPHIR_INIT_NVAR(_9$$5);
					ZEPHIR_INIT_NVAR(_10$$5);
					ZEPHIR_SINIT_NVAR(_11$$5);
					ZVAL_STRING(&_11$$5, "/.*?\\(.*?\\)/", 0);
					zephir_preg_match(_10$$5, &_11$$5, val$$3, _9$$5, 0, 0 , 0  TSRMLS_CC);
					_8$$5 = zephir_is_true(_10$$5);
				}
				if (zephir_instance_of_ev(val$$3, brisk_sql_sqlfather_ce TSRMLS_CC)) {
					ZEPHIR_CALL_METHOD(&_12$$7, val$$3, "getrealsql", &_13, 0);
					zephir_check_call_status();
					ZEPHIR_CPY_WRT(val$$3, _12$$7);
				} else if (_8$$5) {
					ZEPHIR_INIT_NVAR(_14$$8);
					ZEPHIR_INIT_NVAR(_15$$8);
					zephir_create_array(_15$$8, 2, 0 TSRMLS_CC);
					ZEPHIR_INIT_NVAR(_16$$8);
					ZVAL_STRING(_16$$8, "{{", 1);
					zephir_array_fast_append(_15$$8, _16$$8);
					ZEPHIR_INIT_NVAR(_16$$8);
					ZVAL_STRING(_16$$8, "}}", 1);
					zephir_array_fast_append(_15$$8, _16$$8);
					ZEPHIR_SINIT_NVAR(_17$$8);
					ZVAL_STRING(&_17$$8, "", 0);
					zephir_fast_str_replace(&_14$$8, _15$$8, &_17$$8, val$$3 TSRMLS_CC);
					ZEPHIR_CPY_WRT(val$$3, _14$$8);
				} else {
					ZEPHIR_CALL_METHOD(&_18$$9, this_ptr, "quote", &_19, 0, val$$3);
					zephir_check_call_status();
					ZEPHIR_CPY_WRT(val$$3, _18$$9);
				}
				ZEPHIR_INIT_NVAR(_20$$5);
				ZVAL_STRING(_20$$5, "/\\?/", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_INIT_NVAR(_21$$5);
				ZVAL_LONG(_21$$5, 1);
				ZEPHIR_CALL_FUNCTION(&_22$$5, "preg_replace", &_23, 4, _20$$5, val$$3, expr, _21$$5);
				zephir_check_temp_parameter(_20$$5);
				zephir_check_call_status();
				zephir_get_strval(expr, _22$$5);
			} else {
				ZEPHIR_CPY_WRT(val$$3, value);
				if (Z_TYPE_P(value) == IS_ARRAY) {
					ZEPHIR_OBS_NVAR(val$$3);
					zephir_array_fetch(&val$$3, value, k$$3, PH_NOISY, "brisk/Sql/SqlFather.zep", 285 TSRMLS_CC);
				}
				ZEPHIR_INIT_NVAR(_24$$10);
				ZEPHIR_INIT_NVAR(_25$$10);
				ZEPHIR_SINIT_NVAR(_26$$10);
				ZVAL_STRING(&_26$$10, "/^\\{\\{.*?\\}\\}/", 0);
				zephir_preg_match(_25$$10, &_26$$10, val$$3, _24$$10, 0, 0 , 0  TSRMLS_CC);
				_27$$10 = zephir_is_true(_25$$10);
				if (!(_27$$10)) {
					ZEPHIR_INIT_NVAR(_28$$10);
					ZEPHIR_INIT_NVAR(_29$$10);
					ZEPHIR_SINIT_NVAR(_30$$10);
					ZVAL_STRING(&_30$$10, "/.*?\\(.*?\\)/", 0);
					zephir_preg_match(_29$$10, &_30$$10, val$$3, _28$$10, 0, 0 , 0  TSRMLS_CC);
					_27$$10 = zephir_is_true(_29$$10);
				}
				if (zephir_instance_of_ev(val$$3, brisk_sql_sqlfather_ce TSRMLS_CC)) {
					ZEPHIR_CALL_METHOD(&_31$$12, val$$3, "getrealsql", &_32, 0);
					zephir_check_call_status();
					ZEPHIR_CPY_WRT(val$$3, _31$$12);
					ZEPHIR_INIT_NVAR(_33$$12);
					ZVAL_STRING(_33$$12, "/v/", ZEPHIR_TEMP_PARAM_COPY);
					ZEPHIR_INIT_NVAR(_34$$12);
					ZVAL_LONG(_34$$12, 1);
					ZEPHIR_CALL_FUNCTION(&_31$$12, "preg_replace", &_23, 4, _33$$12, val$$3, expr, _34$$12);
					zephir_check_temp_parameter(_33$$12);
					zephir_check_call_status();
					zephir_get_strval(expr, _31$$12);
				} else if (_27$$10) {
					ZEPHIR_INIT_NVAR(_35$$13);
					ZEPHIR_INIT_NVAR(_36$$13);
					zephir_create_array(_36$$13, 2, 0 TSRMLS_CC);
					ZEPHIR_INIT_NVAR(_37$$13);
					ZVAL_STRING(_37$$13, "{{", 1);
					zephir_array_fast_append(_36$$13, _37$$13);
					ZEPHIR_INIT_NVAR(_37$$13);
					ZVAL_STRING(_37$$13, "}}", 1);
					zephir_array_fast_append(_36$$13, _37$$13);
					ZEPHIR_SINIT_NVAR(_38$$13);
					ZVAL_STRING(&_38$$13, "", 0);
					zephir_fast_str_replace(&_35$$13, _36$$13, &_38$$13, val$$3 TSRMLS_CC);
					ZEPHIR_CPY_WRT(val$$3, _35$$13);
					ZEPHIR_INIT_NVAR(_35$$13);
					ZVAL_STRING(_35$$13, "/v/", ZEPHIR_TEMP_PARAM_COPY);
					ZEPHIR_INIT_NVAR(_37$$13);
					ZVAL_LONG(_37$$13, 1);
					ZEPHIR_CALL_FUNCTION(&_39$$13, "preg_replace", &_23, 4, _35$$13, val$$3, expr, _37$$13);
					zephir_check_temp_parameter(_35$$13);
					zephir_check_call_status();
					zephir_get_strval(expr, _39$$13);
				} else {
					zephir_update_property_array(this_ptr, SL("_db_bind"), v$$3, val$$3 TSRMLS_CC);
				}
			}
		}
	}
	RETURN_CTOR(expr);

}

zend_object_value zephir_init_properties_Brisk_Sql_SqlFather(zend_class_entry *class_type TSRMLS_DC) {

		zval *_0, *_2, *_1$$3, *_3$$4;

		ZEPHIR_MM_GROW();
	
	{
		zval zthis       = zval_used_for_init;
		zval *this_ptr   = &zthis;
		zend_object* obj = ecalloc(1, sizeof(zend_object));
		zend_object_value retval;

		zend_object_std_init(obj, class_type TSRMLS_CC);
		object_properties_init(obj, class_type);
		retval.handle   = zend_objects_store_put(obj, (zend_objects_store_dtor_t)zend_objects_destroy_object, zephir_free_object_storage, NULL TSRMLS_CC);
		retval.handlers = zend_get_std_object_handlers();

		Z_TYPE(zthis)   = IS_OBJECT;
		Z_OBJVAL(zthis) = retval;

		_0 = zephir_fetch_nproperty_this(this_ptr, SL("_db_bind"), PH_NOISY_CC);
		if (Z_TYPE_P(_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(_1$$3);
			array_init(_1$$3);
			zephir_update_property_this(getThis(), SL("_db_bind"), _1$$3 TSRMLS_CC);
		}
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("_parts"), PH_NOISY_CC);
		if (Z_TYPE_P(_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(_3$$4);
			array_init(_3$$4);
			zephir_update_property_this(getThis(), SL("_parts"), _3$$4 TSRMLS_CC);
		}
		ZEPHIR_MM_RESTORE();
		return retval;
	}

}


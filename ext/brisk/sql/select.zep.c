
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
#include "kernel/array.h"
#include "kernel/object.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "kernel/string.h"


ZEPHIR_INIT_CLASS(Brisk_Sql_Select) {

	ZEPHIR_REGISTER_CLASS_EX(Brisk\\Sql, Select, brisk, sql_select, brisk_sql_sqlfather_ce, brisk_sql_select_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	return SUCCESS;

}

/**
 * Setting the from field in the sql statement
 *
 * @param mixed table
 * @param array columns
 * @return Select
 */
PHP_METHOD(Brisk_Sql_Select, from) {

	zval *columns = NULL, *_1;
	zval *table, *columns_param = NULL, *_0$$3, *tables = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &table, &columns_param);

	if (!columns_param) {
		ZEPHIR_INIT_VAR(columns);
		array_init(columns);
	} else {
	columns = columns_param;
	}


	if (zephir_fast_count_int(columns TSRMLS_CC) < 1) {
		ZEPHIR_INIT_NVAR(columns);
		zephir_create_array(columns, 1, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_0$$3);
		ZVAL_STRING(_0$$3, "*", 1);
		zephir_array_fast_append(columns, _0$$3);
	}
	if (!(Z_TYPE_P(table) == IS_ARRAY)) {
		ZEPHIR_INIT_VAR(tables);
		zephir_create_array(tables, 1, 0 TSRMLS_CC);
		zephir_array_fast_append(tables, table);
	} else {
		ZEPHIR_CPY_WRT(tables, table);
	}
	ZEPHIR_INIT_VAR(_1);
	zephir_create_array(_1, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(_1, tables);
	zephir_array_fast_append(_1, columns);
	zephir_update_property_array_multi(this_ptr, SL("_parts"), &_1 TSRMLS_CC, SL("sa"), 3, SL("from"));
	RETURN_THIS();

}

/**
 * Setting the group field in the sql statement
 *
 * @param mixed columns
 * @return Select
 */
PHP_METHOD(Brisk_Sql_Select, group) {

	HashTable *_2;
	HashPosition _1;
	zval *column, *columns = NULL, *v = NULL, *_0 = NULL, **_3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &column);



	if (!(Z_TYPE_P(column) == IS_ARRAY)) {
		ZEPHIR_INIT_VAR(columns);
		zephir_create_array(columns, 1, 0 TSRMLS_CC);
		zephir_array_fast_append(columns, column);
	} else {
		ZEPHIR_CPY_WRT(columns, column);
	}
	ZEPHIR_INIT_VAR(_0);
	zephir_is_iterable(columns, &_2, &_1, 0, 0, "brisk/Sql/Select.zep", 49);
	for (
	  ; zend_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zend_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HMKEY(_0, _2, _1);
		ZEPHIR_GET_HVALUE(v, _3);
		zephir_update_property_array_multi(this_ptr, SL("_parts"), &v TSRMLS_CC, SL("sa"), 3, SL("group"));
	}
	RETURN_THIS();

}

/**
 * Setting the having field in the sql statement
 *
 * @param string cond
 * @return Select
 */
PHP_METHOD(Brisk_Sql_Select, having) {

	zval *_0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *cond_param = NULL, *values = NULL;
	zval *cond = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &cond_param);

	if (UNEXPECTED(Z_TYPE_P(cond_param) != IS_STRING && Z_TYPE_P(cond_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'cond' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(cond_param) == IS_STRING)) {
		zephir_get_strval(cond, cond_param);
	} else {
		ZEPHIR_INIT_VAR(cond);
		ZVAL_EMPTY_STRING(cond);
	}


	ZEPHIR_INIT_VAR(values);
	zephir_get_args(values TSRMLS_CC);
	ZEPHIR_MAKE_REF(values);
	ZEPHIR_CALL_FUNCTION(NULL, "array_shift", NULL, 15, values);
	ZEPHIR_UNREF(values);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_0);
	zephir_create_array(_0, 2, 0 TSRMLS_CC);
	zephir_array_update_string(&_0, SL("cond"), &cond, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_0, SL("val"), &values, PH_COPY | PH_SEPARATE);
	zephir_update_property_array_multi(this_ptr, SL("_parts"), &_0 TSRMLS_CC, SL("sa"), 3, SL("having"));
	RETURN_THIS();

}

/**
 * Setting the limit field in the sql statement
 *
 * @param int count
 * @param int offset
 * @return Select
 */
PHP_METHOD(Brisk_Sql_Select, limit) {

	zval *count_param = NULL, *offset_param = NULL, *_0$$3, *_1$$3, *_2$$4, *_3$$4;
	zend_long count, offset;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &count_param, &offset_param);

	if (!count_param) {
		count = 0;
	} else {
	if (UNEXPECTED(Z_TYPE_P(count_param) != IS_LONG)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'count' must be a int") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	count = Z_LVAL_P(count_param);
	}
	if (!offset_param) {
		offset = 0;
	} else {
	if (UNEXPECTED(Z_TYPE_P(offset_param) != IS_LONG)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'offset' must be a int") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	offset = Z_LVAL_P(offset_param);
	}


	if (count > 0) {
		ZEPHIR_INIT_VAR(_0$$3);
		ZVAL_STRING(_0$$3, "limit", 1);
		ZEPHIR_INIT_VAR(_1$$3);
		ZVAL_LONG(_1$$3, count);
		zephir_update_property_array(this_ptr, SL("_parts"), _0$$3, _1$$3 TSRMLS_CC);
	}
	if (offset > 0) {
		ZEPHIR_INIT_VAR(_2$$4);
		ZVAL_STRING(_2$$4, "offset", 1);
		ZEPHIR_INIT_VAR(_3$$4);
		ZVAL_LONG(_3$$4, offset);
		zephir_update_property_array(this_ptr, SL("_parts"), _2$$4, _3$$4 TSRMLS_CC);
	}
	RETURN_THIS();

}

/**
 * Setting the order field in the sql statement
 *
 * @param string col
 * @param bool asc
 * @return Select
 */
PHP_METHOD(Brisk_Sql_Select, order) {

	zval *_0;
	zend_bool asc;
	zval *col_param = NULL, *asc_param = NULL, *_1;
	zval *col = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &col_param, &asc_param);

	if (UNEXPECTED(Z_TYPE_P(col_param) != IS_STRING && Z_TYPE_P(col_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'col' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(col_param) == IS_STRING)) {
		zephir_get_strval(col, col_param);
	} else {
		ZEPHIR_INIT_VAR(col);
		ZVAL_EMPTY_STRING(col);
	}
	if (!asc_param) {
		asc = 1;
	} else {
	if (UNEXPECTED(Z_TYPE_P(asc_param) != IS_BOOL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'asc' must be a bool") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	asc = Z_BVAL_P(asc_param);
	}


	ZEPHIR_INIT_VAR(_0);
	zephir_create_array(_0, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(_0, col);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_BOOL(_1, asc);
	zephir_array_fast_append(_0, _1);
	zephir_update_property_array_multi(this_ptr, SL("_parts"), &_0 TSRMLS_CC, SL("sa"), 3, SL("order"));
	RETURN_THIS();

}

/**
 * Setting the joinLeft field in the sql statement
 *
 * @param mixed table
 * @param string cond
 * @param array fields
 * @return Select
 */
PHP_METHOD(Brisk_Sql_Select, joinLeft) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *fields = NULL;
	zval *cond = NULL;
	zval *table, *cond_param = NULL, *fields_param = NULL, *_0$$3, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &table, &cond_param, &fields_param);

	if (UNEXPECTED(Z_TYPE_P(cond_param) != IS_STRING && Z_TYPE_P(cond_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'cond' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(cond_param) == IS_STRING)) {
		zephir_get_strval(cond, cond_param);
	} else {
		ZEPHIR_INIT_VAR(cond);
		ZVAL_EMPTY_STRING(cond);
	}
	if (!fields_param) {
		ZEPHIR_INIT_VAR(fields);
		array_init(fields);
	} else {
	fields = fields_param;
	}


	if (zephir_fast_count_int(fields TSRMLS_CC) < 1) {
		ZEPHIR_INIT_NVAR(fields);
		zephir_create_array(fields, 1, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_0$$3);
		ZVAL_STRING(_0$$3, "*", 1);
		zephir_array_fast_append(fields, _0$$3);
	}
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "joinLeft", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "_join", NULL, 0, table, cond, fields, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Setting the joinInner field in the sql statement
 *
 * @param mixed table
 * @param string cond
 * @param array fields
 * @return Select
 */
PHP_METHOD(Brisk_Sql_Select, joinInner) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *fields = NULL;
	zval *cond = NULL;
	zval *table, *cond_param = NULL, *fields_param = NULL, *_0$$3, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &table, &cond_param, &fields_param);

	if (UNEXPECTED(Z_TYPE_P(cond_param) != IS_STRING && Z_TYPE_P(cond_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'cond' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(cond_param) == IS_STRING)) {
		zephir_get_strval(cond, cond_param);
	} else {
		ZEPHIR_INIT_VAR(cond);
		ZVAL_EMPTY_STRING(cond);
	}
	if (!fields_param) {
		ZEPHIR_INIT_VAR(fields);
		array_init(fields);
	} else {
	fields = fields_param;
	}


	if (zephir_fast_count_int(fields TSRMLS_CC) < 1) {
		ZEPHIR_INIT_NVAR(fields);
		zephir_create_array(fields, 1, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_0$$3);
		ZVAL_STRING(_0$$3, "*", 1);
		zephir_array_fast_append(fields, _0$$3);
	}
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "joinInner", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "_join", NULL, 0, table, cond, fields, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Setting the joinRight field in the sql statement
 *
 * @param mixed table
 * @param string cond
 * @param array fields
 * @return Select
 */
PHP_METHOD(Brisk_Sql_Select, joinRight) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *fields = NULL;
	zval *cond = NULL;
	zval *table, *cond_param = NULL, *fields_param = NULL, *_0$$3, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &table, &cond_param, &fields_param);

	if (UNEXPECTED(Z_TYPE_P(cond_param) != IS_STRING && Z_TYPE_P(cond_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'cond' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(cond_param) == IS_STRING)) {
		zephir_get_strval(cond, cond_param);
	} else {
		ZEPHIR_INIT_VAR(cond);
		ZVAL_EMPTY_STRING(cond);
	}
	if (!fields_param) {
		ZEPHIR_INIT_VAR(fields);
		array_init(fields);
	} else {
	fields = fields_param;
	}


	if (zephir_fast_count_int(fields TSRMLS_CC) < 1) {
		ZEPHIR_INIT_NVAR(fields);
		zephir_create_array(fields, 1, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_0$$3);
		ZVAL_STRING(_0$$3, "*", 1);
		zephir_array_fast_append(fields, _0$$3);
	}
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "joinRight", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "_join", NULL, 0, table, cond, fields, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Brisk_Sql_Select, _join) {

	zval *fields = NULL, *_0;
	zval *cond = NULL, *jointype = NULL;
	zval *table, *cond_param = NULL, *fields_param = NULL, *jointype_param = NULL, *tables = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 0, &table, &cond_param, &fields_param, &jointype_param);

	if (UNEXPECTED(Z_TYPE_P(cond_param) != IS_STRING && Z_TYPE_P(cond_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'cond' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(cond_param) == IS_STRING)) {
		zephir_get_strval(cond, cond_param);
	} else {
		ZEPHIR_INIT_VAR(cond);
		ZVAL_EMPTY_STRING(cond);
	}
	fields = fields_param;
	if (UNEXPECTED(Z_TYPE_P(jointype_param) != IS_STRING && Z_TYPE_P(jointype_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'jointype' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(jointype_param) == IS_STRING)) {
		zephir_get_strval(jointype, jointype_param);
	} else {
		ZEPHIR_INIT_VAR(jointype);
		ZVAL_EMPTY_STRING(jointype);
	}


	if (!(Z_TYPE_P(table) == IS_ARRAY)) {
		ZEPHIR_INIT_VAR(tables);
		zephir_create_array(tables, 1, 0 TSRMLS_CC);
		zephir_array_fast_append(tables, table);
	} else {
		ZEPHIR_CPY_WRT(tables, table);
	}
	ZEPHIR_INIT_VAR(_0);
	zephir_create_array(_0, 4, 0 TSRMLS_CC);
	zephir_array_fast_append(_0, jointype);
	zephir_array_fast_append(_0, tables);
	zephir_array_fast_append(_0, cond);
	zephir_array_fast_append(_0, fields);
	zephir_update_property_array_multi(this_ptr, SL("_parts"), &_0 TSRMLS_CC, SL("sa"), 3, SL("join"));
	RETURN_THIS();

}

/**
 * Get the select fragment in the sql statement
 *
 * @return string
 */
PHP_METHOD(Brisk_Sql_Select, pickSelectPart) {

	zval *_18$$8 = NULL, *_34$$19 = NULL, *_48$$24 = NULL;
	HashTable *_3$$3, *_12$$4, *_32$$18, *_42$$20;
	HashPosition _2$$3, _11$$4, _31$$18, _41$$20;
	zend_bool _58;
	zval *fields = NULL, *table = NULL, *join = NULL, *from_part = NULL, *_0, *val = NULL, *k = NULL, *v = NULL, *from_table$$3 = NULL, *alias$$3 = NULL, *_1$$3 = NULL, **_4$$3, *join_part$$3 = NULL, *_29$$3, *_5$$4, *_7$$4 = NULL, *_10$$4, **_13$$4, *_9$$6 = NULL, *_14$$7 = NULL, *_15$$7 = NULL, _16$$7 = zval_used_for_init, *_27$$7, *_28$$7, *_17$$8 = NULL, *_19$$8 = NULL, _20$$8 = zval_used_for_init, *_21$$8 = NULL, *_22$$10 = NULL, *_23$$11 = NULL, *_24$$13 = NULL, *_25$$16 = NULL, *_26$$17 = NULL, *join_flag$$18 = NULL, *join_table$$18 = NULL, *join_cond$$18 = NULL, *join_fields$$18 = NULL, *keys$$18 = NULL, *_30$$18 = NULL, **_33$$18, *_35$$19 = NULL, *_36$$20 = NULL, **_43$$20, *_37$$21, *_38$$21 = NULL, *_39$$22, *_40$$22 = NULL, *_44$$23 = NULL, *_45$$23 = NULL, _46$$23 = zval_used_for_init, *_57$$23, *_47$$24 = NULL, *_49$$24 = NULL, _50$$24 = zval_used_for_init, *_51$$24 = NULL, *_52$$26 = NULL, *_53$$27 = NULL, *_54$$29 = NULL, *_55$$32 = NULL, *_56$$33 = NULL, *select$$34 = NULL, *_59$$34, *_60$$34, *_61$$35, *_62$$35;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_6 = NULL, *_8 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(fields);
	array_init(fields);
	ZEPHIR_INIT_VAR(table);
	array_init(table);
	ZEPHIR_INIT_VAR(join);
	array_init(join);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_parts"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(from_part);
	zephir_array_fetch_string(&from_part, _0, SL("from"), PH_NOISY, "brisk/Sql/Select.zep", 170 TSRMLS_CC);
	if (zephir_fast_count_int(from_part TSRMLS_CC) > 0) {
		ZEPHIR_INIT_VAR(_1$$3);
		zephir_is_iterable(from_part, &_3$$3, &_2$$3, 0, 0, "brisk/Sql/Select.zep", 217);
		for (
		  ; zend_hash_get_current_data_ex(_3$$3, (void**) &_4$$3, &_2$$3) == SUCCESS
		  ; zend_hash_move_forward_ex(_3$$3, &_2$$3)
		) {
			ZEPHIR_GET_HMKEY(_1$$3, _3$$3, _2$$3);
			ZEPHIR_GET_HVALUE(val, _4$$3);
			zephir_array_fetch_long(&_5$$4, val, 0, PH_NOISY | PH_READONLY, "brisk/Sql/Select.zep", 177 TSRMLS_CC);
			ZEPHIR_MAKE_REF(_5$$4);
			ZEPHIR_CALL_FUNCTION(&from_table$$3, "each", &_6, 13, _5$$4);
			ZEPHIR_UNREF(_5$$4);
			zephir_check_call_status();
			ZEPHIR_OBS_NVAR(k);
			zephir_array_fetch_string(&k, from_table$$3, SL("key"), PH_NOISY, "brisk/Sql/Select.zep", 178 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(v);
			zephir_array_fetch_string(&v, from_table$$3, SL("value"), PH_NOISY, "brisk/Sql/Select.zep", 179 TSRMLS_CC);
			ZEPHIR_CALL_FUNCTION(&_7$$4, "is_integer", &_8, 14, k);
			zephir_check_call_status();
			if (zephir_is_true(_7$$4)) {
				ZEPHIR_INIT_NVAR(alias$$3);
				ZVAL_STRING(alias$$3, "", 1);
				zephir_array_append(&table, v, PH_SEPARATE, "brisk/Sql/Select.zep", 183);
			} else {
				ZEPHIR_CPY_WRT(alias$$3, k);
				ZEPHIR_INIT_LNVAR(_9$$6);
				ZEPHIR_CONCAT_VSV(_9$$6, v, " ", alias$$3);
				zephir_array_append(&table, _9$$6, PH_SEPARATE, "brisk/Sql/Select.zep", 186);
			}
			zephir_array_fetch_long(&_10$$4, val, 1, PH_NOISY | PH_READONLY, "brisk/Sql/Select.zep", 189 TSRMLS_CC);
			zephir_is_iterable(_10$$4, &_12$$4, &_11$$4, 0, 0, "brisk/Sql/Select.zep", 216);
			for (
			  ; zend_hash_get_current_data_ex(_12$$4, (void**) &_13$$4, &_11$$4) == SUCCESS
			  ; zend_hash_move_forward_ex(_12$$4, &_11$$4)
			) {
				ZEPHIR_GET_HMKEY(k, _12$$4, _11$$4);
				ZEPHIR_GET_HVALUE(v, _13$$4);
				ZEPHIR_INIT_NVAR(_14$$7);
				zephir_fast_trim(_14$$7, v, NULL , ZEPHIR_TRIM_BOTH TSRMLS_CC);
				ZEPHIR_CPY_WRT(v, _14$$7);
				ZEPHIR_INIT_NVAR(_15$$7);
				ZEPHIR_INIT_NVAR(_14$$7);
				ZEPHIR_SINIT_NVAR(_16$$7);
				ZVAL_STRING(&_16$$7, "/^\\{\\{.*?\\}\\}/", 0);
				zephir_preg_match(_14$$7, &_16$$7, v, _15$$7, 0, 0 , 0  TSRMLS_CC);
				if (zephir_is_true(_14$$7)) {
					ZEPHIR_INIT_NVAR(_17$$8);
					ZEPHIR_INIT_NVAR(_18$$8);
					zephir_create_array(_18$$8, 2, 0 TSRMLS_CC);
					ZEPHIR_INIT_NVAR(_19$$8);
					ZVAL_STRING(_19$$8, "{{", 1);
					zephir_array_fast_append(_18$$8, _19$$8);
					ZEPHIR_INIT_NVAR(_19$$8);
					ZVAL_STRING(_19$$8, "}}", 1);
					zephir_array_fast_append(_18$$8, _19$$8);
					ZEPHIR_SINIT_NVAR(_20$$8);
					ZVAL_STRING(&_20$$8, "", 0);
					zephir_fast_str_replace(&_17$$8, _18$$8, &_20$$8, v TSRMLS_CC);
					ZEPHIR_CPY_WRT(v, _17$$8);
					ZEPHIR_CALL_FUNCTION(&_21$$8, "is_integer", &_8, 14, k);
					zephir_check_call_status();
					if (zephir_is_true(_21$$8)) {
						zephir_array_update_multi(&val, &v TSRMLS_CC, SL("lz"), 2, 1, k);
					} else {
						ZEPHIR_INIT_LNVAR(_22$$10);
						ZEPHIR_CONCAT_VSV(_22$$10, v, " ", k);
						zephir_array_update_multi(&val, &_22$$10 TSRMLS_CC, SL("lz"), 2, 1, k);
					}
				} else {
					ZEPHIR_CALL_FUNCTION(&_23$$11, "is_integer", &_8, 14, k);
					zephir_check_call_status();
					if (zephir_is_true(_23$$11)) {
						if (!ZEPHIR_IS_STRING(alias$$3, "")) {
							ZEPHIR_INIT_LNVAR(_24$$13);
							ZEPHIR_CONCAT_VSV(_24$$13, alias$$3, ".", v);
							zephir_array_update_multi(&val, &_24$$13 TSRMLS_CC, SL("lz"), 2, 1, k);
						} else {
							zephir_array_update_multi(&val, &v TSRMLS_CC, SL("lz"), 2, 1, k);
						}
					} else {
						if (!ZEPHIR_IS_STRING(alias$$3, "")) {
							ZEPHIR_INIT_LNVAR(_25$$16);
							ZEPHIR_CONCAT_VSVSV(_25$$16, alias$$3, ".", v, " ", k);
							zephir_array_update_multi(&val, &_25$$16 TSRMLS_CC, SL("lz"), 2, 1, k);
						} else {
							ZEPHIR_INIT_LNVAR(_26$$17);
							ZEPHIR_CONCAT_VSV(_26$$17, v, " ", k);
							zephir_array_update_multi(&val, &_26$$17 TSRMLS_CC, SL("lz"), 2, 1, k);
						}
					}
				}
				zephir_array_fetch_long(&_27$$7, val, 1, PH_NOISY | PH_READONLY, "brisk/Sql/Select.zep", 214 TSRMLS_CC);
				zephir_array_fetch(&_28$$7, _27$$7, k, PH_NOISY | PH_READONLY, "brisk/Sql/Select.zep", 214 TSRMLS_CC);
				zephir_array_append(&fields, _28$$7, PH_SEPARATE, "brisk/Sql/Select.zep", 214);
			}
		}
		_29$$3 = zephir_fetch_nproperty_this(this_ptr, SL("_parts"), PH_NOISY_CC);
		ZEPHIR_OBS_VAR(join_part$$3);
		zephir_array_fetch_string(&join_part$$3, _29$$3, SL("join"), PH_NOISY, "brisk/Sql/Select.zep", 218 TSRMLS_CC);
		if (zephir_fast_count_int(join_part$$3 TSRMLS_CC) > 0) {
			ZEPHIR_INIT_VAR(_30$$18);
			zephir_is_iterable(join_part$$3, &_32$$18, &_31$$18, 0, 0, "brisk/Sql/Select.zep", 275);
			for (
			  ; zend_hash_get_current_data_ex(_32$$18, (void**) &_33$$18, &_31$$18) == SUCCESS
			  ; zend_hash_move_forward_ex(_32$$18, &_31$$18)
			) {
				ZEPHIR_GET_HMKEY(_30$$18, _32$$18, _31$$18);
				ZEPHIR_GET_HVALUE(val, _33$$18);
				ZEPHIR_OBS_NVAR(join_flag$$18);
				zephir_array_fetch_long(&join_flag$$18, val, 0, PH_NOISY, "brisk/Sql/Select.zep", 223 TSRMLS_CC);
				ZEPHIR_OBS_NVAR(join_table$$18);
				zephir_array_fetch_long(&join_table$$18, val, 1, PH_NOISY, "brisk/Sql/Select.zep", 224 TSRMLS_CC);
				ZEPHIR_OBS_NVAR(join_cond$$18);
				zephir_array_fetch_long(&join_cond$$18, val, 2, PH_NOISY, "brisk/Sql/Select.zep", 225 TSRMLS_CC);
				ZEPHIR_OBS_NVAR(join_fields$$18);
				zephir_array_fetch_long(&join_fields$$18, val, 3, PH_NOISY, "brisk/Sql/Select.zep", 226 TSRMLS_CC);
				ZEPHIR_INIT_NVAR(_34$$19);
				zephir_create_array(_34$$19, 4, 0 TSRMLS_CC);
				ZEPHIR_INIT_NVAR(_35$$19);
				ZVAL_STRING(_35$$19, "joinLeft", 1);
				zephir_array_fast_append(_34$$19, _35$$19);
				ZEPHIR_INIT_NVAR(_35$$19);
				ZVAL_STRING(_35$$19, "joinInner", 1);
				zephir_array_fast_append(_34$$19, _35$$19);
				ZEPHIR_INIT_NVAR(_35$$19);
				ZVAL_STRING(_35$$19, "joinRight", 1);
				zephir_array_fast_append(_34$$19, _35$$19);
				ZEPHIR_INIT_NVAR(_35$$19);
				ZVAL_STRING(_35$$19, "joinFull", 1);
				zephir_array_fast_append(_34$$19, _35$$19);
				if (zephir_fast_in_array(join_flag$$18, _34$$19 TSRMLS_CC)) {
					ZEPHIR_INIT_NVAR(keys$$18);
					zephir_create_array(keys$$18, 4, 0 TSRMLS_CC);
					add_assoc_stringl_ex(keys$$18, SS("joinLeft"), SL("LEFT JOIN"), 1);
					add_assoc_stringl_ex(keys$$18, SS("joinInner"), SL("INNER JOIN"), 1);
					add_assoc_stringl_ex(keys$$18, SS("joinRight"), SL("RIGHT JOIN"), 1);
					add_assoc_stringl_ex(keys$$18, SS("joinFull"), SL("FULL JOIN"), 1);
					ZEPHIR_MAKE_REF(join_table$$18);
					ZEPHIR_CALL_FUNCTION(&_36$$20, "each", &_6, 13, join_table$$18);
					ZEPHIR_UNREF(join_table$$18);
					zephir_check_call_status();
					ZEPHIR_CPY_WRT(join_table$$18, _36$$20);
					ZEPHIR_OBS_NVAR(k);
					zephir_array_fetch_long(&k, join_table$$18, 0, PH_NOISY, "brisk/Sql/Select.zep", 235 TSRMLS_CC);
					ZEPHIR_OBS_NVAR(v);
					zephir_array_fetch_long(&v, join_table$$18, 1, PH_NOISY, "brisk/Sql/Select.zep", 236 TSRMLS_CC);
					ZEPHIR_CALL_FUNCTION(&_36$$20, "is_integer", &_8, 14, k);
					zephir_check_call_status();
					if (zephir_is_true(_36$$20)) {
						ZEPHIR_INIT_NVAR(alias$$3);
						ZVAL_STRING(alias$$3, "", 1);
						zephir_array_fetch(&_37$$21, keys$$18, join_flag$$18, PH_NOISY | PH_READONLY, "brisk/Sql/Select.zep", 240 TSRMLS_CC);
						ZEPHIR_INIT_LNVAR(_38$$21);
						ZEPHIR_CONCAT_VSVSVS(_38$$21, _37$$21, " ", v, " ON ", join_cond$$18, " ");
						zephir_array_append(&join, _38$$21, PH_SEPARATE, "brisk/Sql/Select.zep", 240);
					} else {
						ZEPHIR_CPY_WRT(alias$$3, k);
						zephir_array_fetch(&_39$$22, keys$$18, join_flag$$18, PH_NOISY | PH_READONLY, "brisk/Sql/Select.zep", 243 TSRMLS_CC);
						ZEPHIR_INIT_LNVAR(_40$$22);
						ZEPHIR_CONCAT_VSVSVSVS(_40$$22, _39$$22, " ", v, " ", alias$$3, " ON ", join_cond$$18, " ");
						zephir_array_append(&join, _40$$22, PH_SEPARATE, "brisk/Sql/Select.zep", 243);
					}
					zephir_is_iterable(join_fields$$18, &_42$$20, &_41$$20, 0, 0, "brisk/Sql/Select.zep", 273);
					for (
					  ; zend_hash_get_current_data_ex(_42$$20, (void**) &_43$$20, &_41$$20) == SUCCESS
					  ; zend_hash_move_forward_ex(_42$$20, &_41$$20)
					) {
						ZEPHIR_GET_HMKEY(k, _42$$20, _41$$20);
						ZEPHIR_GET_HVALUE(v, _43$$20);
						ZEPHIR_INIT_NVAR(_44$$23);
						zephir_fast_trim(_44$$23, v, NULL , ZEPHIR_TRIM_BOTH TSRMLS_CC);
						ZEPHIR_CPY_WRT(v, _44$$23);
						ZEPHIR_INIT_NVAR(_45$$23);
						ZEPHIR_INIT_NVAR(_44$$23);
						ZEPHIR_SINIT_NVAR(_46$$23);
						ZVAL_STRING(&_46$$23, "/^\\{\\{.*?\\}\\}/", 0);
						zephir_preg_match(_44$$23, &_46$$23, v, _45$$23, 0, 0 , 0  TSRMLS_CC);
						if (zephir_is_true(_44$$23)) {
							ZEPHIR_INIT_NVAR(_47$$24);
							ZEPHIR_INIT_NVAR(_48$$24);
							zephir_create_array(_48$$24, 2, 0 TSRMLS_CC);
							ZEPHIR_INIT_NVAR(_49$$24);
							ZVAL_STRING(_49$$24, "{{", 1);
							zephir_array_fast_append(_48$$24, _49$$24);
							ZEPHIR_INIT_NVAR(_49$$24);
							ZVAL_STRING(_49$$24, "}}", 1);
							zephir_array_fast_append(_48$$24, _49$$24);
							ZEPHIR_SINIT_NVAR(_50$$24);
							ZVAL_STRING(&_50$$24, "", 0);
							zephir_fast_str_replace(&_47$$24, _48$$24, &_50$$24, v TSRMLS_CC);
							ZEPHIR_CPY_WRT(v, _47$$24);
							ZEPHIR_CALL_FUNCTION(&_51$$24, "is_integer", &_8, 14, k);
							zephir_check_call_status();
							if (zephir_is_true(_51$$24)) {
								zephir_array_update_zval(&join_fields$$18, k, &v, PH_COPY | PH_SEPARATE);
							} else {
								ZEPHIR_INIT_LNVAR(_52$$26);
								ZEPHIR_CONCAT_VSV(_52$$26, v, " ", k);
								zephir_array_update_zval(&join_fields$$18, k, &_52$$26, PH_COPY | PH_SEPARATE);
							}
						} else {
							ZEPHIR_CALL_FUNCTION(&_53$$27, "is_integer", &_8, 14, k);
							zephir_check_call_status();
							if (zephir_is_true(_53$$27)) {
								if (!ZEPHIR_IS_STRING(alias$$3, "")) {
									ZEPHIR_INIT_LNVAR(_54$$29);
									ZEPHIR_CONCAT_VSV(_54$$29, alias$$3, ".", v);
									zephir_array_update_zval(&join_fields$$18, k, &_54$$29, PH_COPY | PH_SEPARATE);
								} else {
									zephir_array_update_zval(&join_fields$$18, k, &v, PH_COPY | PH_SEPARATE);
								}
							} else {
								if (!ZEPHIR_IS_STRING(alias$$3, "")) {
									ZEPHIR_INIT_LNVAR(_55$$32);
									ZEPHIR_CONCAT_VSVSV(_55$$32, alias$$3, ".", v, " ", k);
									zephir_array_update_zval(&join_fields$$18, k, &_55$$32, PH_COPY | PH_SEPARATE);
								} else {
									ZEPHIR_INIT_LNVAR(_56$$33);
									ZEPHIR_CONCAT_VSV(_56$$33, v, " ", k);
									zephir_array_update_zval(&join_fields$$18, k, &_56$$33, PH_COPY | PH_SEPARATE);
								}
							}
						}
						zephir_array_fetch(&_57$$23, join_fields$$18, k, PH_NOISY | PH_READONLY, "brisk/Sql/Select.zep", 271 TSRMLS_CC);
						zephir_array_append(&fields, _57$$23, PH_SEPARATE, "brisk/Sql/Select.zep", 271);
					}
				}
			}
		}
	}
	_58 = !ZEPHIR_IS_STRING(fields, "");
	if (_58) {
		_58 = !ZEPHIR_IS_STRING(table, "");
	}
	if (_58) {
		ZEPHIR_INIT_VAR(_59$$34);
		zephir_fast_join_str(_59$$34, SL(", "), fields TSRMLS_CC);
		ZEPHIR_INIT_VAR(_60$$34);
		zephir_fast_join_str(_60$$34, SL(", "), table TSRMLS_CC);
		ZEPHIR_INIT_VAR(select$$34);
		ZEPHIR_CONCAT_SVSV(select$$34, "SELECT ", _59$$34, " FROM ", _60$$34);
		if (zephir_fast_count_int(join TSRMLS_CC) > 0) {
			ZEPHIR_INIT_VAR(_61$$35);
			zephir_fast_join_str(_61$$35, SL(" "), join TSRMLS_CC);
			ZEPHIR_INIT_VAR(_62$$35);
			ZEPHIR_CONCAT_VSV(_62$$35, select$$34, " ", _61$$35);
			ZEPHIR_CPY_WRT(select$$34, _62$$35);
		}
		RETURN_CCTOR(select$$34);
	}
	RETURN_MM_NULL();

}

/**
 * Get the group fragment in the sql statement
 *
 * @return string
 */
PHP_METHOD(Brisk_Sql_Select, pickGroupPart) {

	HashTable *_3$$3;
	HashPosition _2$$3;
	zval *group = NULL, *group_part = NULL, *val = NULL, *_0, *_1$$3 = NULL, **_4$$3;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(group);
	array_init(group);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_parts"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(group_part);
	zephir_array_fetch_string(&group_part, _0, SL("group"), PH_NOISY, "brisk/Sql/Select.zep", 297 TSRMLS_CC);
	if (zephir_fast_count_int(group_part TSRMLS_CC) > 0) {
		ZEPHIR_INIT_VAR(_1$$3);
		zephir_is_iterable(group_part, &_3$$3, &_2$$3, 0, 0, "brisk/Sql/Select.zep", 302);
		for (
		  ; zend_hash_get_current_data_ex(_3$$3, (void**) &_4$$3, &_2$$3) == SUCCESS
		  ; zend_hash_move_forward_ex(_3$$3, &_2$$3)
		) {
			ZEPHIR_GET_HMKEY(_1$$3, _3$$3, _2$$3);
			ZEPHIR_GET_HVALUE(val, _4$$3);
			zephir_array_append(&group, val, PH_SEPARATE, "brisk/Sql/Select.zep", 300);
		}
	}
	zephir_fast_join_str(return_value, SL(", "), group TSRMLS_CC);
	RETURN_MM();

}

/**
 * Get the having fragment in the sql statement
 *
 * @return string
 */
PHP_METHOD(Brisk_Sql_Select, pickHavingPart) {

	HashTable *_2$$3;
	HashPosition _1$$3;
	zval *having = NULL, *having_part = NULL, *key = NULL, *val = NULL, *part = NULL, *cond = NULL, *value = NULL, *_0, *_11, **_3$$3, *_4$$6 = NULL, *_5$$6 = NULL, *_6$$7 = NULL, *_8$$7 = NULL, *_9$$4, *_10$$8 = NULL;
	zephir_fcall_cache_entry *_7 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(having);
	array_init(having);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_parts"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(having_part);
	zephir_array_fetch_string(&having_part, _0, SL("having"), PH_NOISY, "brisk/Sql/Select.zep", 316 TSRMLS_CC);
	if (zephir_fast_count_int(having_part TSRMLS_CC) > 0) {
		zephir_is_iterable(having_part, &_2$$3, &_1$$3, 0, 0, "brisk/Sql/Select.zep", 335);
		for (
		  ; zend_hash_get_current_data_ex(_2$$3, (void**) &_3$$3, &_1$$3) == SUCCESS
		  ; zend_hash_move_forward_ex(_2$$3, &_1$$3)
		) {
			ZEPHIR_GET_HMKEY(key, _2$$3, _1$$3);
			ZEPHIR_GET_HVALUE(val, _3$$3);
			ZEPHIR_INIT_NVAR(part);
			ZVAL_STRING(part, "", 1);
			ZEPHIR_OBS_NVAR(cond);
			zephir_array_fetch_string(&cond, val, SL("cond"), PH_NOISY, "brisk/Sql/Select.zep", 320 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(value);
			zephir_array_fetch_string(&value, val, SL("val"), PH_NOISY, "brisk/Sql/Select.zep", 321 TSRMLS_CC);
			if (Z_TYPE_P(value) == IS_NULL) {
				ZEPHIR_CPY_WRT(part, cond);
				if (zephir_instance_of_ev(cond, brisk_sql_select_ce TSRMLS_CC)) {
					ZEPHIR_CALL_METHOD(&_4$$6, cond, "pickhavingpart", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_INIT_LNVAR(_5$$6);
					ZEPHIR_CONCAT_VSVS(_5$$6, part, "(", _4$$6, ")");
					ZEPHIR_CPY_WRT(part, _5$$6);
				}
			} else {
				ZEPHIR_CALL_METHOD(&_6$$7, this_ptr, "_parseexpr", &_7, 0, cond, value);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_8$$7);
				ZEPHIR_CONCAT_VV(_8$$7, part, _6$$7);
				ZEPHIR_CPY_WRT(part, _8$$7);
			}
			zephir_array_fetch_long(&_9$$4, having_part, (zephir_get_numberval(key) + 1), PH_NOISY | PH_READONLY, "brisk/Sql/Select.zep", 330 TSRMLS_CC);
			if (!(Z_TYPE_P(_9$$4) == IS_NULL)) {
				ZEPHIR_INIT_LNVAR(_10$$8);
				ZEPHIR_CONCAT_VS(_10$$8, part, " AND ");
				ZEPHIR_CPY_WRT(part, _10$$8);
			}
			zephir_array_append(&having, part, PH_SEPARATE, "brisk/Sql/Select.zep", 333);
		}
	}
	ZEPHIR_INIT_VAR(_11);
	if (zephir_is_true(having)) {
		zephir_fast_join_str(_11, SL(" "), having TSRMLS_CC);
	} else {
		ZVAL_NULL(_11);
	}
	RETURN_CCTOR(_11);

}

/**
 * Get the order fragment in the sql statement
 *
 * @return string
 */
PHP_METHOD(Brisk_Sql_Select, pickOrderPart) {

	HashTable *_3$$3;
	HashPosition _2$$3;
	zend_bool by = 0;
	zval *order = NULL, *order_part = NULL, *v = NULL, *_0, *_11, *_1$$3 = NULL, **_4$$3, *_5$$4, *_6$$5, *_7$$6 = NULL, *_8$$6, *_9$$6 = NULL, *_10$$6 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(order);
	array_init(order);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_parts"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(order_part);
	zephir_array_fetch_string(&order_part, _0, SL("order"), PH_NOISY, "brisk/Sql/Select.zep", 348 TSRMLS_CC);
	if (zephir_fast_count_int(order_part TSRMLS_CC) > 0) {
		ZEPHIR_INIT_VAR(_1$$3);
		zephir_is_iterable(order_part, &_3$$3, &_2$$3, 0, 0, "brisk/Sql/Select.zep", 358);
		for (
		  ; zend_hash_get_current_data_ex(_3$$3, (void**) &_4$$3, &_2$$3) == SUCCESS
		  ; zend_hash_move_forward_ex(_3$$3, &_2$$3)
		) {
			ZEPHIR_GET_HMKEY(_1$$3, _3$$3, _2$$3);
			ZEPHIR_GET_HVALUE(v, _4$$3);
			zephir_array_fetch_long(&_5$$4, v, 1, PH_NOISY | PH_READONLY, "brisk/Sql/Select.zep", 351 TSRMLS_CC);
			if (Z_TYPE_P(_5$$4) == IS_NULL) {
				zephir_array_fetch_long(&_6$$5, v, 0, PH_NOISY | PH_READONLY, "brisk/Sql/Select.zep", 352 TSRMLS_CC);
				zephir_array_append(&order, _6$$5, PH_SEPARATE, "brisk/Sql/Select.zep", 352);
			} else {
				ZEPHIR_OBS_NVAR(_7$$6);
				zephir_array_fetch_long(&_7$$6, v, 1, PH_NOISY, "brisk/Sql/Select.zep", 354 TSRMLS_CC);
				by = zephir_get_boolval(_7$$6);
				zephir_array_fetch_long(&_8$$6, v, 0, PH_NOISY | PH_READONLY, "brisk/Sql/Select.zep", 355 TSRMLS_CC);
				ZEPHIR_INIT_LNVAR(_9$$6);
				if (by) {
					ZEPHIR_INIT_NVAR(_9$$6);
					ZVAL_STRING(_9$$6, "ASC", 1);
				} else {
					ZEPHIR_INIT_NVAR(_9$$6);
					ZVAL_STRING(_9$$6, "DESC", 1);
				}
				ZEPHIR_INIT_LNVAR(_10$$6);
				ZEPHIR_CONCAT_VSV(_10$$6, _8$$6, " ", _9$$6);
				zephir_array_append(&order, _10$$6, PH_SEPARATE, "brisk/Sql/Select.zep", 355);
			}
		}
	}
	ZEPHIR_INIT_VAR(_11);
	if (zephir_is_true(order)) {
		zephir_fast_join_str(_11, SL(", "), order TSRMLS_CC);
	} else {
		ZVAL_NULL(_11);
	}
	RETURN_CCTOR(_11);

}

/**
 * Get the limit fragment in the sql statement
 *
 * @return string
 */
PHP_METHOD(Brisk_Sql_Select, pickLimitPart) {

	zval *limit = NULL, *limit_part = NULL, *_0, *offset_part$$3 = NULL, *_1$$3;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(limit);
	ZVAL_STRING(limit, "", 1);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_parts"), PH_NOISY_CC);
	zephir_array_fetch_string(&limit_part, _0, SL("limit"), PH_NOISY | PH_READONLY, "brisk/Sql/Select.zep", 371 TSRMLS_CC);
	if (!ZEPHIR_IS_STRING(limit_part, "")) {
		_1$$3 = zephir_fetch_nproperty_this(this_ptr, SL("_parts"), PH_NOISY_CC);
		ZEPHIR_OBS_VAR(offset_part$$3);
		zephir_array_fetch_string(&offset_part$$3, _1$$3, SL("offset"), PH_NOISY, "brisk/Sql/Select.zep", 374 TSRMLS_CC);
		if (!ZEPHIR_IS_STRING(offset_part$$3, "")) {
			ZEPHIR_INIT_NVAR(limit);
			ZEPHIR_CONCAT_VSV(limit, limit_part, " OFFSET ", offset_part$$3);
		} else {
			ZEPHIR_CPY_WRT(limit, limit_part);
		}
	}
	RETURN_CCTOR(limit);

}

/**
 * Compile the select statment
 *
 * @return Select
 */
PHP_METHOD(Brisk_Sql_Select, compile) {

	zval *select = NULL, *where = NULL, *group = NULL, *having = NULL, *order = NULL, *limit = NULL, *_0$$3, *_1$$3 = NULL, *_3$$3, *_4$$4, *_5$$5, *_6$$6, *_7$$7, *_8$$8;
	zephir_fcall_cache_entry *_2 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&select, this_ptr, "pickselectpart", NULL, 0);
	zephir_check_call_status();
	if (ZEPHIR_IS_STRING(select, "")) {
		ZEPHIR_INIT_VAR(_0$$3);
		object_init_ex(_0$$3, brisk_exception_sqlcompileexception_ce);
		ZEPHIR_INIT_VAR(_3$$3);
		ZVAL_STRING(_3$$3, "querier.sql_compile_failed", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_CE_STATIC(&_1$$3, brisk_kernel_language_ce, "get", &_2, 12, _3$$3);
		zephir_check_temp_parameter(_3$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, _0$$3, "__construct", NULL, 7, _1$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(_0$$3, "brisk/Sql/Select.zep", 394 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD(&where, this_ptr, "pickwherepart", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&group, this_ptr, "pickgrouppart", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&having, this_ptr, "pickhavingpart", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&order, this_ptr, "pickorderpart", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&limit, this_ptr, "picklimitpart", NULL, 0);
	zephir_check_call_status();
	if (!ZEPHIR_IS_STRING(where, "")) {
		ZEPHIR_INIT_VAR(_4$$4);
		ZEPHIR_CONCAT_VSV(_4$$4, select, " WHERE ", where);
		ZEPHIR_CPY_WRT(select, _4$$4);
	}
	if (!ZEPHIR_IS_STRING(group, "")) {
		ZEPHIR_INIT_VAR(_5$$5);
		ZEPHIR_CONCAT_VSV(_5$$5, select, " GROUP BY ", group);
		ZEPHIR_CPY_WRT(select, _5$$5);
	}
	if (!ZEPHIR_IS_STRING(having, "")) {
		ZEPHIR_INIT_VAR(_6$$6);
		ZEPHIR_CONCAT_VSV(_6$$6, select, " HAVING ", having);
		ZEPHIR_CPY_WRT(select, _6$$6);
	}
	if (!ZEPHIR_IS_STRING(order, "")) {
		ZEPHIR_INIT_VAR(_7$$7);
		ZEPHIR_CONCAT_VSV(_7$$7, select, " ORDER BY ", order);
		ZEPHIR_CPY_WRT(select, _7$$7);
	}
	if (!ZEPHIR_IS_STRING(limit, "")) {
		ZEPHIR_INIT_VAR(_8$$8);
		ZEPHIR_CONCAT_VSV(_8$$8, select, " LIMIT ", limit);
		ZEPHIR_CPY_WRT(select, _8$$8);
	}
	zephir_update_property_this(getThis(), SL("_sql"), select TSRMLS_CC);
	if (1) {
		zephir_update_property_this(getThis(), SL("_compiled"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	} else {
		zephir_update_property_this(getThis(), SL("_compiled"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	}
	RETURN_THIS();

}


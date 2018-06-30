
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
#include "kernel/array.h"
#include "kernel/object.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "kernel/string.h"


ZEPHIR_INIT_CLASS(Brisk_Toolkit_SQLBuilder_SelectBuilder) {

	ZEPHIR_REGISTER_CLASS_EX(Brisk\\Toolkit\\SQLBuilder, SelectBuilder, brisk, toolkit_sqlbuilder_selectbuilder, brisk_toolkit_sqlbuilder_builderfather_ce, brisk_toolkit_sqlbuilder_selectbuilder_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	return SUCCESS;

}

PHP_METHOD(Brisk_Toolkit_SQLBuilder_SelectBuilder, from) {

	zval columns, _1;
	zval *table, table_sub, *columns_param = NULL, _0$$3, tables;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&table_sub);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&tables);
	ZVAL_UNDEF(&columns);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &table, &columns_param);

	if (!columns_param) {
		ZEPHIR_INIT_VAR(&columns);
		array_init(&columns);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&columns, columns_param);
	}


	if (zephir_fast_count_int(&columns TSRMLS_CC) < 1) {
		ZEPHIR_INIT_NVAR(&columns);
		zephir_create_array(&columns, 1, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_0$$3);
		ZVAL_STRING(&_0$$3, "*");
		zephir_array_fast_append(&columns, &_0$$3);
	}
	if (!(Z_TYPE_P(table) == IS_ARRAY)) {
		ZEPHIR_INIT_VAR(&tables);
		zephir_create_array(&tables, 1, 0 TSRMLS_CC);
		zephir_array_fast_append(&tables, table);
	} else {
		ZEPHIR_CPY_WRT(&tables, table);
	}
	ZEPHIR_INIT_VAR(&_1);
	zephir_create_array(&_1, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(&_1, &tables);
	zephir_array_fast_append(&_1, &columns);
	zephir_update_property_array_multi(this_ptr, SL("_parts"), &_1 TSRMLS_CC, SL("sa"), 3, SL("from"));
	RETURN_THIS();

}

PHP_METHOD(Brisk_Toolkit_SQLBuilder_SelectBuilder, group) {

	zend_string *_3;
	zend_ulong _2;
	zval *column, column_sub, columns, v, _0, *_1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&column_sub);
	ZVAL_UNDEF(&columns);
	ZVAL_UNDEF(&v);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &column);



	if (!(Z_TYPE_P(column) == IS_ARRAY)) {
		ZEPHIR_INIT_VAR(&columns);
		zephir_create_array(&columns, 1, 0 TSRMLS_CC);
		zephir_array_fast_append(&columns, column);
	} else {
		ZEPHIR_CPY_WRT(&columns, column);
	}
	ZEPHIR_INIT_VAR(&_0);
	zephir_is_iterable(&columns, 0, "brisk/Toolkit/SQLBuilder/SelectBuilder.zep", 33);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&columns), _2, _3, _1)
	{
		ZEPHIR_INIT_NVAR(&_0);
		if (_3 != NULL) { 
			ZVAL_STR_COPY(&_0, _3);
		} else {
			ZVAL_LONG(&_0, _2);
		}
		ZEPHIR_INIT_NVAR(&v);
		ZVAL_COPY(&v, _1);
		zephir_update_property_array_multi(this_ptr, SL("_parts"), &v TSRMLS_CC, SL("sa"), 3, SL("group"));
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&v);
	ZEPHIR_INIT_NVAR(&_0);
	RETURN_THIS();

}

PHP_METHOD(Brisk_Toolkit_SQLBuilder_SelectBuilder, having) {

	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *cond_param = NULL, values;
	zval cond;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&cond);
	ZVAL_UNDEF(&values);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &cond_param);

	if (UNEXPECTED(Z_TYPE_P(cond_param) != IS_STRING && Z_TYPE_P(cond_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'cond' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(cond_param) == IS_STRING)) {
		zephir_get_strval(&cond, cond_param);
	} else {
		ZEPHIR_INIT_VAR(&cond);
		ZVAL_EMPTY_STRING(&cond);
	}


	ZEPHIR_INIT_VAR(&values);
	zephir_get_args(&values);
	ZEPHIR_MAKE_REF(&values);
	ZEPHIR_CALL_FUNCTION(NULL, "array_shift", NULL, 7, &values);
	ZEPHIR_UNREF(&values);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 2, 0 TSRMLS_CC);
	zephir_array_update_string(&_0, SL("cond"), &cond, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_0, SL("val"), &values, PH_COPY | PH_SEPARATE);
	zephir_update_property_array_multi(this_ptr, SL("_parts"), &_0 TSRMLS_CC, SL("sa"), 3, SL("having"));
	RETURN_THIS();

}

PHP_METHOD(Brisk_Toolkit_SQLBuilder_SelectBuilder, limit) {

	zval *count = NULL, count_sub, *offset = NULL, offset_sub, _0$$3, _1$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&count_sub);
	ZVAL_UNDEF(&offset_sub);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &count, &offset);

	if (!count) {
		count = &count_sub;
		ZEPHIR_INIT_VAR(count);
		ZVAL_LONG(count, 0);
	}
	if (!offset) {
		offset = &offset_sub;
		ZEPHIR_INIT_VAR(offset);
		ZVAL_LONG(offset, 0);
	}


	if (ZEPHIR_GT_LONG(count, 0)) {
		ZEPHIR_INIT_VAR(&_0$$3);
		ZVAL_STRING(&_0$$3, "limit");
		zephir_update_property_array(this_ptr, SL("_parts"), &_0$$3, count TSRMLS_CC);
	}
	if (ZEPHIR_GT_LONG(offset, 0)) {
		ZEPHIR_INIT_VAR(&_1$$4);
		ZVAL_STRING(&_1$$4, "offset");
		zephir_update_property_array(this_ptr, SL("_parts"), &_1$$4, offset TSRMLS_CC);
	}
	RETURN_THIS();

}

PHP_METHOD(Brisk_Toolkit_SQLBuilder_SelectBuilder, order) {

	zval _0;
	zend_bool asc;
	zval *col_param = NULL, *asc_param = NULL, _1;
	zval col;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&col);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &col_param, &asc_param);

	if (UNEXPECTED(Z_TYPE_P(col_param) != IS_STRING && Z_TYPE_P(col_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'col' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(col_param) == IS_STRING)) {
		zephir_get_strval(&col, col_param);
	} else {
		ZEPHIR_INIT_VAR(&col);
		ZVAL_EMPTY_STRING(&col);
	}
	if (!asc_param) {
		asc = 1;
	} else {
	if (UNEXPECTED(Z_TYPE_P(asc_param) != IS_TRUE && Z_TYPE_P(asc_param) != IS_FALSE)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'asc' must be a bool") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	asc = (Z_TYPE_P(asc_param) == IS_TRUE);
	}


	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(&_0, &col);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_BOOL(&_1, asc);
	zephir_array_fast_append(&_0, &_1);
	zephir_update_property_array_multi(this_ptr, SL("_parts"), &_0 TSRMLS_CC, SL("sa"), 3, SL("order"));
	RETURN_THIS();

}

PHP_METHOD(Brisk_Toolkit_SQLBuilder_SelectBuilder, joinLeft) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval fields;
	zval cond;
	zval *table, table_sub, *cond_param = NULL, *fields_param = NULL, _0$$3, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&table_sub);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&cond);
	ZVAL_UNDEF(&fields);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &table, &cond_param, &fields_param);

	if (UNEXPECTED(Z_TYPE_P(cond_param) != IS_STRING && Z_TYPE_P(cond_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'cond' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(cond_param) == IS_STRING)) {
		zephir_get_strval(&cond, cond_param);
	} else {
		ZEPHIR_INIT_VAR(&cond);
		ZVAL_EMPTY_STRING(&cond);
	}
	if (!fields_param) {
		ZEPHIR_INIT_VAR(&fields);
		array_init(&fields);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&fields, fields_param);
	}


	if (zephir_fast_count_int(&fields TSRMLS_CC) < 1) {
		ZEPHIR_INIT_NVAR(&fields);
		zephir_create_array(&fields, 1, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_0$$3);
		ZVAL_STRING(&_0$$3, "*");
		zephir_array_fast_append(&fields, &_0$$3);
	}
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "joinLeft");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "_join", NULL, 0, table, &cond, &fields, &_1);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Brisk_Toolkit_SQLBuilder_SelectBuilder, joinInner) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval fields;
	zval cond;
	zval *table, table_sub, *cond_param = NULL, *fields_param = NULL, _0$$3, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&table_sub);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&cond);
	ZVAL_UNDEF(&fields);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &table, &cond_param, &fields_param);

	if (UNEXPECTED(Z_TYPE_P(cond_param) != IS_STRING && Z_TYPE_P(cond_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'cond' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(cond_param) == IS_STRING)) {
		zephir_get_strval(&cond, cond_param);
	} else {
		ZEPHIR_INIT_VAR(&cond);
		ZVAL_EMPTY_STRING(&cond);
	}
	if (!fields_param) {
		ZEPHIR_INIT_VAR(&fields);
		array_init(&fields);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&fields, fields_param);
	}


	if (zephir_fast_count_int(&fields TSRMLS_CC) < 1) {
		ZEPHIR_INIT_NVAR(&fields);
		zephir_create_array(&fields, 1, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_0$$3);
		ZVAL_STRING(&_0$$3, "*");
		zephir_array_fast_append(&fields, &_0$$3);
	}
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "joinInner");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "_join", NULL, 0, table, &cond, &fields, &_1);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Brisk_Toolkit_SQLBuilder_SelectBuilder, joinRight) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval fields;
	zval cond;
	zval *table, table_sub, *cond_param = NULL, *fields_param = NULL, _0$$3, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&table_sub);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&cond);
	ZVAL_UNDEF(&fields);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &table, &cond_param, &fields_param);

	if (UNEXPECTED(Z_TYPE_P(cond_param) != IS_STRING && Z_TYPE_P(cond_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'cond' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(cond_param) == IS_STRING)) {
		zephir_get_strval(&cond, cond_param);
	} else {
		ZEPHIR_INIT_VAR(&cond);
		ZVAL_EMPTY_STRING(&cond);
	}
	if (!fields_param) {
		ZEPHIR_INIT_VAR(&fields);
		array_init(&fields);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&fields, fields_param);
	}


	if (zephir_fast_count_int(&fields TSRMLS_CC) < 1) {
		ZEPHIR_INIT_NVAR(&fields);
		zephir_create_array(&fields, 1, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_0$$3);
		ZVAL_STRING(&_0$$3, "*");
		zephir_array_fast_append(&fields, &_0$$3);
	}
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "joinRight");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "_join", NULL, 0, table, &cond, &fields, &_1);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Brisk_Toolkit_SQLBuilder_SelectBuilder, _join) {

	zval fields, _0;
	zval cond, jointype;
	zval *table, table_sub, *cond_param = NULL, *fields_param = NULL, *jointype_param = NULL, tables;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&table_sub);
	ZVAL_UNDEF(&tables);
	ZVAL_UNDEF(&cond);
	ZVAL_UNDEF(&jointype);
	ZVAL_UNDEF(&fields);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 0, &table, &cond_param, &fields_param, &jointype_param);

	if (UNEXPECTED(Z_TYPE_P(cond_param) != IS_STRING && Z_TYPE_P(cond_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'cond' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(cond_param) == IS_STRING)) {
		zephir_get_strval(&cond, cond_param);
	} else {
		ZEPHIR_INIT_VAR(&cond);
		ZVAL_EMPTY_STRING(&cond);
	}
	ZEPHIR_OBS_COPY_OR_DUP(&fields, fields_param);
	if (UNEXPECTED(Z_TYPE_P(jointype_param) != IS_STRING && Z_TYPE_P(jointype_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'jointype' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(jointype_param) == IS_STRING)) {
		zephir_get_strval(&jointype, jointype_param);
	} else {
		ZEPHIR_INIT_VAR(&jointype);
		ZVAL_EMPTY_STRING(&jointype);
	}


	if (!(Z_TYPE_P(table) == IS_ARRAY)) {
		ZEPHIR_INIT_VAR(&tables);
		zephir_create_array(&tables, 1, 0 TSRMLS_CC);
		zephir_array_fast_append(&tables, table);
	} else {
		ZEPHIR_CPY_WRT(&tables, table);
	}
	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 4, 0 TSRMLS_CC);
	zephir_array_fast_append(&_0, &jointype);
	zephir_array_fast_append(&_0, &tables);
	zephir_array_fast_append(&_0, &cond);
	zephir_array_fast_append(&_0, &fields);
	zephir_update_property_array_multi(this_ptr, SL("_parts"), &_0 TSRMLS_CC, SL("sa"), 3, SL("join"));
	RETURN_THIS();

}

PHP_METHOD(Brisk_Toolkit_SQLBuilder_SelectBuilder, pickSelectPart) {

	zval _18$$8, _33$$19, _47$$24;
	zend_string *_4$$3, *_13$$4, *_32$$18, *_42$$20;
	zend_ulong _3$$3, _12$$4, _31$$18, _41$$20;
	zend_bool _56;
	zval fields, table, join, from_part, _0, val, k, v, from_table$$3, alias$$3, _1$$3, *_2$$3, join_part$$3, _28$$3, _5$$4, _7$$4, _10$$4, *_11$$4, _9$$6, _14$$7, _15$$7, _16$$7, _26$$7, _27$$7, _17$$8, _19$$8, _20$$8, _21$$10, _22$$11, _23$$13, _24$$16, _25$$17, join_flag$$18, join_table$$18, join_cond$$18, join_fields$$18, keys$$18, _29$$18, *_30$$18, _34$$19, _35$$20, *_40$$20, _36$$21, _37$$21, _38$$22, _39$$22, _43$$23, _44$$23, _45$$23, _55$$23, _46$$24, _48$$24, _49$$24, _50$$26, _51$$27, _52$$29, _53$$32, _54$$33, select$$34, _57$$34, _58$$34, _59$$35, _60$$35;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_6 = NULL, *_8 = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&fields);
	ZVAL_UNDEF(&table);
	ZVAL_UNDEF(&join);
	ZVAL_UNDEF(&from_part);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&val);
	ZVAL_UNDEF(&k);
	ZVAL_UNDEF(&v);
	ZVAL_UNDEF(&from_table$$3);
	ZVAL_UNDEF(&alias$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&join_part$$3);
	ZVAL_UNDEF(&_28$$3);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_10$$4);
	ZVAL_UNDEF(&_9$$6);
	ZVAL_UNDEF(&_14$$7);
	ZVAL_UNDEF(&_15$$7);
	ZVAL_UNDEF(&_16$$7);
	ZVAL_UNDEF(&_26$$7);
	ZVAL_UNDEF(&_27$$7);
	ZVAL_UNDEF(&_17$$8);
	ZVAL_UNDEF(&_19$$8);
	ZVAL_UNDEF(&_20$$8);
	ZVAL_UNDEF(&_21$$10);
	ZVAL_UNDEF(&_22$$11);
	ZVAL_UNDEF(&_23$$13);
	ZVAL_UNDEF(&_24$$16);
	ZVAL_UNDEF(&_25$$17);
	ZVAL_UNDEF(&join_flag$$18);
	ZVAL_UNDEF(&join_table$$18);
	ZVAL_UNDEF(&join_cond$$18);
	ZVAL_UNDEF(&join_fields$$18);
	ZVAL_UNDEF(&keys$$18);
	ZVAL_UNDEF(&_29$$18);
	ZVAL_UNDEF(&_34$$19);
	ZVAL_UNDEF(&_35$$20);
	ZVAL_UNDEF(&_36$$21);
	ZVAL_UNDEF(&_37$$21);
	ZVAL_UNDEF(&_38$$22);
	ZVAL_UNDEF(&_39$$22);
	ZVAL_UNDEF(&_43$$23);
	ZVAL_UNDEF(&_44$$23);
	ZVAL_UNDEF(&_45$$23);
	ZVAL_UNDEF(&_55$$23);
	ZVAL_UNDEF(&_46$$24);
	ZVAL_UNDEF(&_48$$24);
	ZVAL_UNDEF(&_49$$24);
	ZVAL_UNDEF(&_50$$26);
	ZVAL_UNDEF(&_51$$27);
	ZVAL_UNDEF(&_52$$29);
	ZVAL_UNDEF(&_53$$32);
	ZVAL_UNDEF(&_54$$33);
	ZVAL_UNDEF(&select$$34);
	ZVAL_UNDEF(&_57$$34);
	ZVAL_UNDEF(&_58$$34);
	ZVAL_UNDEF(&_59$$35);
	ZVAL_UNDEF(&_60$$35);
	ZVAL_UNDEF(&_18$$8);
	ZVAL_UNDEF(&_33$$19);
	ZVAL_UNDEF(&_47$$24);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&fields);
	array_init(&fields);
	ZEPHIR_INIT_VAR(&table);
	array_init(&table);
	ZEPHIR_INIT_VAR(&join);
	array_init(&join);
	zephir_read_property(&_0, this_ptr, SL("_parts"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_OBS_VAR(&from_part);
	zephir_array_fetch_string(&from_part, &_0, SL("from"), PH_NOISY, "brisk/Toolkit/SQLBuilder/SelectBuilder.zep", 105 TSRMLS_CC);
	if (zephir_fast_count_int(&from_part TSRMLS_CC) > 0) {
		ZEPHIR_INIT_VAR(&_1$$3);
		zephir_is_iterable(&from_part, 0, "brisk/Toolkit/SQLBuilder/SelectBuilder.zep", 152);
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&from_part), _3$$3, _4$$3, _2$$3)
		{
			ZEPHIR_INIT_NVAR(&_1$$3);
			if (_4$$3 != NULL) { 
				ZVAL_STR_COPY(&_1$$3, _4$$3);
			} else {
				ZVAL_LONG(&_1$$3, _3$$3);
			}
			ZEPHIR_INIT_NVAR(&val);
			ZVAL_COPY(&val, _2$$3);
			zephir_array_fetch_long(&_5$$4, &val, 0, PH_NOISY | PH_READONLY, "brisk/Toolkit/SQLBuilder/SelectBuilder.zep", 112 TSRMLS_CC);
			ZEPHIR_MAKE_REF(&_5$$4);
			ZEPHIR_CALL_FUNCTION(&from_table$$3, "each", &_6, 5, &_5$$4);
			ZEPHIR_UNREF(&_5$$4);
			zephir_check_call_status();
			ZEPHIR_OBS_NVAR(&k);
			zephir_array_fetch_string(&k, &from_table$$3, SL("key"), PH_NOISY, "brisk/Toolkit/SQLBuilder/SelectBuilder.zep", 113 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(&v);
			zephir_array_fetch_string(&v, &from_table$$3, SL("value"), PH_NOISY, "brisk/Toolkit/SQLBuilder/SelectBuilder.zep", 114 TSRMLS_CC);
			ZEPHIR_CALL_FUNCTION(&_7$$4, "is_integer", &_8, 6, &k);
			zephir_check_call_status();
			if (zephir_is_true(&_7$$4)) {
				ZEPHIR_INIT_NVAR(&alias$$3);
				ZVAL_STRING(&alias$$3, "");
				zephir_array_append(&table, &v, PH_SEPARATE, "brisk/Toolkit/SQLBuilder/SelectBuilder.zep", 118);
			} else {
				ZEPHIR_CPY_WRT(&alias$$3, &k);
				ZEPHIR_INIT_LNVAR(_9$$6);
				ZEPHIR_CONCAT_VSV(&_9$$6, &v, " ", &alias$$3);
				zephir_array_append(&table, &_9$$6, PH_SEPARATE, "brisk/Toolkit/SQLBuilder/SelectBuilder.zep", 121);
			}
			zephir_array_fetch_long(&_10$$4, &val, 1, PH_NOISY | PH_READONLY, "brisk/Toolkit/SQLBuilder/SelectBuilder.zep", 124 TSRMLS_CC);
			zephir_is_iterable(&_10$$4, 0, "brisk/Toolkit/SQLBuilder/SelectBuilder.zep", 151);
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_10$$4), _12$$4, _13$$4, _11$$4)
			{
				ZEPHIR_INIT_NVAR(&k);
				if (_13$$4 != NULL) { 
					ZVAL_STR_COPY(&k, _13$$4);
				} else {
					ZVAL_LONG(&k, _12$$4);
				}
				ZEPHIR_INIT_NVAR(&v);
				ZVAL_COPY(&v, _11$$4);
				ZEPHIR_INIT_NVAR(&_14$$7);
				zephir_fast_trim(&_14$$7, &v, NULL , ZEPHIR_TRIM_BOTH TSRMLS_CC);
				ZEPHIR_CPY_WRT(&v, &_14$$7);
				ZEPHIR_INIT_NVAR(&_15$$7);
				ZEPHIR_INIT_NVAR(&_14$$7);
				ZEPHIR_INIT_NVAR(&_16$$7);
				ZVAL_STRING(&_16$$7, "/^\\{\\{.*?\\}\\}/");
				zephir_preg_match(&_14$$7, &_16$$7, &v, &_15$$7, 0, 0 , 0  TSRMLS_CC);
				if (zephir_is_true(&_14$$7)) {
					ZEPHIR_INIT_NVAR(&_17$$8);
					ZEPHIR_INIT_NVAR(&_18$$8);
					zephir_create_array(&_18$$8, 2, 0 TSRMLS_CC);
					ZEPHIR_INIT_NVAR(&_19$$8);
					ZVAL_STRING(&_19$$8, "{{");
					zephir_array_fast_append(&_18$$8, &_19$$8);
					ZEPHIR_INIT_NVAR(&_19$$8);
					ZVAL_STRING(&_19$$8, "}}");
					zephir_array_fast_append(&_18$$8, &_19$$8);
					ZEPHIR_INIT_NVAR(&_19$$8);
					ZVAL_STRING(&_19$$8, "");
					zephir_fast_str_replace(&_17$$8, &_18$$8, &_19$$8, &v TSRMLS_CC);
					ZEPHIR_CPY_WRT(&v, &_17$$8);
					ZEPHIR_CALL_FUNCTION(&_20$$8, "is_integer", &_8, 6, &k);
					zephir_check_call_status();
					if (zephir_is_true(&_20$$8)) {
						zephir_array_update_multi(&val, &v TSRMLS_CC, SL("lz"), 2, 1, &k);
					} else {
						ZEPHIR_INIT_LNVAR(_21$$10);
						ZEPHIR_CONCAT_VSV(&_21$$10, &v, " ", &k);
						zephir_array_update_multi(&val, &_21$$10 TSRMLS_CC, SL("lz"), 2, 1, &k);
					}
				} else {
					ZEPHIR_CALL_FUNCTION(&_22$$11, "is_integer", &_8, 6, &k);
					zephir_check_call_status();
					if (zephir_is_true(&_22$$11)) {
						if (!ZEPHIR_IS_STRING(&alias$$3, "")) {
							ZEPHIR_INIT_LNVAR(_23$$13);
							ZEPHIR_CONCAT_VSV(&_23$$13, &alias$$3, ".", &v);
							zephir_array_update_multi(&val, &_23$$13 TSRMLS_CC, SL("lz"), 2, 1, &k);
						} else {
							zephir_array_update_multi(&val, &v TSRMLS_CC, SL("lz"), 2, 1, &k);
						}
					} else {
						if (!ZEPHIR_IS_STRING(&alias$$3, "")) {
							ZEPHIR_INIT_LNVAR(_24$$16);
							ZEPHIR_CONCAT_VSVSV(&_24$$16, &alias$$3, ".", &v, " ", &k);
							zephir_array_update_multi(&val, &_24$$16 TSRMLS_CC, SL("lz"), 2, 1, &k);
						} else {
							ZEPHIR_INIT_LNVAR(_25$$17);
							ZEPHIR_CONCAT_VSV(&_25$$17, &v, " ", &k);
							zephir_array_update_multi(&val, &_25$$17 TSRMLS_CC, SL("lz"), 2, 1, &k);
						}
					}
				}
				zephir_array_fetch_long(&_26$$7, &val, 1, PH_NOISY | PH_READONLY, "brisk/Toolkit/SQLBuilder/SelectBuilder.zep", 149 TSRMLS_CC);
				zephir_array_fetch(&_27$$7, &_26$$7, &k, PH_NOISY | PH_READONLY, "brisk/Toolkit/SQLBuilder/SelectBuilder.zep", 149 TSRMLS_CC);
				zephir_array_append(&fields, &_27$$7, PH_SEPARATE, "brisk/Toolkit/SQLBuilder/SelectBuilder.zep", 149);
			} ZEND_HASH_FOREACH_END();
			ZEPHIR_INIT_NVAR(&v);
			ZEPHIR_INIT_NVAR(&k);
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&val);
		ZEPHIR_INIT_NVAR(&_1$$3);
		zephir_read_property(&_28$$3, this_ptr, SL("_parts"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_OBS_VAR(&join_part$$3);
		zephir_array_fetch_string(&join_part$$3, &_28$$3, SL("join"), PH_NOISY, "brisk/Toolkit/SQLBuilder/SelectBuilder.zep", 153 TSRMLS_CC);
		if (zephir_fast_count_int(&join_part$$3 TSRMLS_CC) > 0) {
			ZEPHIR_INIT_VAR(&_29$$18);
			zephir_is_iterable(&join_part$$3, 0, "brisk/Toolkit/SQLBuilder/SelectBuilder.zep", 210);
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&join_part$$3), _31$$18, _32$$18, _30$$18)
			{
				ZEPHIR_INIT_NVAR(&_29$$18);
				if (_32$$18 != NULL) { 
					ZVAL_STR_COPY(&_29$$18, _32$$18);
				} else {
					ZVAL_LONG(&_29$$18, _31$$18);
				}
				ZEPHIR_INIT_NVAR(&val);
				ZVAL_COPY(&val, _30$$18);
				ZEPHIR_OBS_NVAR(&join_flag$$18);
				zephir_array_fetch_long(&join_flag$$18, &val, 0, PH_NOISY, "brisk/Toolkit/SQLBuilder/SelectBuilder.zep", 158 TSRMLS_CC);
				ZEPHIR_OBS_NVAR(&join_table$$18);
				zephir_array_fetch_long(&join_table$$18, &val, 1, PH_NOISY, "brisk/Toolkit/SQLBuilder/SelectBuilder.zep", 159 TSRMLS_CC);
				ZEPHIR_OBS_NVAR(&join_cond$$18);
				zephir_array_fetch_long(&join_cond$$18, &val, 2, PH_NOISY, "brisk/Toolkit/SQLBuilder/SelectBuilder.zep", 160 TSRMLS_CC);
				ZEPHIR_OBS_NVAR(&join_fields$$18);
				zephir_array_fetch_long(&join_fields$$18, &val, 3, PH_NOISY, "brisk/Toolkit/SQLBuilder/SelectBuilder.zep", 161 TSRMLS_CC);
				ZEPHIR_INIT_NVAR(&_33$$19);
				zephir_create_array(&_33$$19, 4, 0 TSRMLS_CC);
				ZEPHIR_INIT_NVAR(&_34$$19);
				ZVAL_STRING(&_34$$19, "joinLeft");
				zephir_array_fast_append(&_33$$19, &_34$$19);
				ZEPHIR_INIT_NVAR(&_34$$19);
				ZVAL_STRING(&_34$$19, "joinInner");
				zephir_array_fast_append(&_33$$19, &_34$$19);
				ZEPHIR_INIT_NVAR(&_34$$19);
				ZVAL_STRING(&_34$$19, "joinRight");
				zephir_array_fast_append(&_33$$19, &_34$$19);
				ZEPHIR_INIT_NVAR(&_34$$19);
				ZVAL_STRING(&_34$$19, "joinFull");
				zephir_array_fast_append(&_33$$19, &_34$$19);
				if (zephir_fast_in_array(&join_flag$$18, &_33$$19 TSRMLS_CC)) {
					ZEPHIR_INIT_NVAR(&keys$$18);
					zephir_create_array(&keys$$18, 4, 0 TSRMLS_CC);
					add_assoc_stringl_ex(&keys$$18, SL("joinLeft"), SL("LEFT JOIN"));
					add_assoc_stringl_ex(&keys$$18, SL("joinInner"), SL("INNER JOIN"));
					add_assoc_stringl_ex(&keys$$18, SL("joinRight"), SL("RIGHT JOIN"));
					add_assoc_stringl_ex(&keys$$18, SL("joinFull"), SL("FULL JOIN"));
					ZEPHIR_MAKE_REF(&join_table$$18);
					ZEPHIR_CALL_FUNCTION(&_35$$20, "each", &_6, 5, &join_table$$18);
					ZEPHIR_UNREF(&join_table$$18);
					zephir_check_call_status();
					ZEPHIR_CPY_WRT(&join_table$$18, &_35$$20);
					ZEPHIR_OBS_NVAR(&k);
					zephir_array_fetch_long(&k, &join_table$$18, 0, PH_NOISY, "brisk/Toolkit/SQLBuilder/SelectBuilder.zep", 170 TSRMLS_CC);
					ZEPHIR_OBS_NVAR(&v);
					zephir_array_fetch_long(&v, &join_table$$18, 1, PH_NOISY, "brisk/Toolkit/SQLBuilder/SelectBuilder.zep", 171 TSRMLS_CC);
					ZEPHIR_CALL_FUNCTION(&_35$$20, "is_integer", &_8, 6, &k);
					zephir_check_call_status();
					if (zephir_is_true(&_35$$20)) {
						ZEPHIR_INIT_NVAR(&alias$$3);
						ZVAL_STRING(&alias$$3, "");
						zephir_array_fetch(&_36$$21, &keys$$18, &join_flag$$18, PH_NOISY | PH_READONLY, "brisk/Toolkit/SQLBuilder/SelectBuilder.zep", 175 TSRMLS_CC);
						ZEPHIR_INIT_LNVAR(_37$$21);
						ZEPHIR_CONCAT_VSVSVS(&_37$$21, &_36$$21, " ", &v, " ON ", &join_cond$$18, " ");
						zephir_array_append(&join, &_37$$21, PH_SEPARATE, "brisk/Toolkit/SQLBuilder/SelectBuilder.zep", 175);
					} else {
						ZEPHIR_CPY_WRT(&alias$$3, &k);
						zephir_array_fetch(&_38$$22, &keys$$18, &join_flag$$18, PH_NOISY | PH_READONLY, "brisk/Toolkit/SQLBuilder/SelectBuilder.zep", 178 TSRMLS_CC);
						ZEPHIR_INIT_LNVAR(_39$$22);
						ZEPHIR_CONCAT_VSVSVSVS(&_39$$22, &_38$$22, " ", &v, " ", &alias$$3, " ON ", &join_cond$$18, " ");
						zephir_array_append(&join, &_39$$22, PH_SEPARATE, "brisk/Toolkit/SQLBuilder/SelectBuilder.zep", 178);
					}
					zephir_is_iterable(&join_fields$$18, 0, "brisk/Toolkit/SQLBuilder/SelectBuilder.zep", 208);
					ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&join_fields$$18), _41$$20, _42$$20, _40$$20)
					{
						ZEPHIR_INIT_NVAR(&k);
						if (_42$$20 != NULL) { 
							ZVAL_STR_COPY(&k, _42$$20);
						} else {
							ZVAL_LONG(&k, _41$$20);
						}
						ZEPHIR_INIT_NVAR(&v);
						ZVAL_COPY(&v, _40$$20);
						ZEPHIR_INIT_NVAR(&_43$$23);
						zephir_fast_trim(&_43$$23, &v, NULL , ZEPHIR_TRIM_BOTH TSRMLS_CC);
						ZEPHIR_CPY_WRT(&v, &_43$$23);
						ZEPHIR_INIT_NVAR(&_44$$23);
						ZEPHIR_INIT_NVAR(&_43$$23);
						ZEPHIR_INIT_NVAR(&_45$$23);
						ZVAL_STRING(&_45$$23, "/^\\{\\{.*?\\}\\}/");
						zephir_preg_match(&_43$$23, &_45$$23, &v, &_44$$23, 0, 0 , 0  TSRMLS_CC);
						if (zephir_is_true(&_43$$23)) {
							ZEPHIR_INIT_NVAR(&_46$$24);
							ZEPHIR_INIT_NVAR(&_47$$24);
							zephir_create_array(&_47$$24, 2, 0 TSRMLS_CC);
							ZEPHIR_INIT_NVAR(&_48$$24);
							ZVAL_STRING(&_48$$24, "{{");
							zephir_array_fast_append(&_47$$24, &_48$$24);
							ZEPHIR_INIT_NVAR(&_48$$24);
							ZVAL_STRING(&_48$$24, "}}");
							zephir_array_fast_append(&_47$$24, &_48$$24);
							ZEPHIR_INIT_NVAR(&_48$$24);
							ZVAL_STRING(&_48$$24, "");
							zephir_fast_str_replace(&_46$$24, &_47$$24, &_48$$24, &v TSRMLS_CC);
							ZEPHIR_CPY_WRT(&v, &_46$$24);
							ZEPHIR_CALL_FUNCTION(&_49$$24, "is_integer", &_8, 6, &k);
							zephir_check_call_status();
							if (zephir_is_true(&_49$$24)) {
								zephir_array_update_zval(&join_fields$$18, &k, &v, PH_COPY | PH_SEPARATE);
							} else {
								ZEPHIR_INIT_LNVAR(_50$$26);
								ZEPHIR_CONCAT_VSV(&_50$$26, &v, " ", &k);
								zephir_array_update_zval(&join_fields$$18, &k, &_50$$26, PH_COPY | PH_SEPARATE);
							}
						} else {
							ZEPHIR_CALL_FUNCTION(&_51$$27, "is_integer", &_8, 6, &k);
							zephir_check_call_status();
							if (zephir_is_true(&_51$$27)) {
								if (!ZEPHIR_IS_STRING(&alias$$3, "")) {
									ZEPHIR_INIT_LNVAR(_52$$29);
									ZEPHIR_CONCAT_VSV(&_52$$29, &alias$$3, ".", &v);
									zephir_array_update_zval(&join_fields$$18, &k, &_52$$29, PH_COPY | PH_SEPARATE);
								} else {
									zephir_array_update_zval(&join_fields$$18, &k, &v, PH_COPY | PH_SEPARATE);
								}
							} else {
								if (!ZEPHIR_IS_STRING(&alias$$3, "")) {
									ZEPHIR_INIT_LNVAR(_53$$32);
									ZEPHIR_CONCAT_VSVSV(&_53$$32, &alias$$3, ".", &v, " ", &k);
									zephir_array_update_zval(&join_fields$$18, &k, &_53$$32, PH_COPY | PH_SEPARATE);
								} else {
									ZEPHIR_INIT_LNVAR(_54$$33);
									ZEPHIR_CONCAT_VSV(&_54$$33, &v, " ", &k);
									zephir_array_update_zval(&join_fields$$18, &k, &_54$$33, PH_COPY | PH_SEPARATE);
								}
							}
						}
						zephir_array_fetch(&_55$$23, &join_fields$$18, &k, PH_NOISY | PH_READONLY, "brisk/Toolkit/SQLBuilder/SelectBuilder.zep", 206 TSRMLS_CC);
						zephir_array_append(&fields, &_55$$23, PH_SEPARATE, "brisk/Toolkit/SQLBuilder/SelectBuilder.zep", 206);
					} ZEND_HASH_FOREACH_END();
					ZEPHIR_INIT_NVAR(&v);
					ZEPHIR_INIT_NVAR(&k);
				}
			} ZEND_HASH_FOREACH_END();
			ZEPHIR_INIT_NVAR(&val);
			ZEPHIR_INIT_NVAR(&_29$$18);
		}
	}
	_56 = !ZEPHIR_IS_STRING(&fields, "");
	if (_56) {
		_56 = !ZEPHIR_IS_STRING(&table, "");
	}
	if (_56) {
		ZEPHIR_INIT_VAR(&_57$$34);
		zephir_fast_join_str(&_57$$34, SL(", "), &fields TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_58$$34);
		zephir_fast_join_str(&_58$$34, SL(", "), &table TSRMLS_CC);
		ZEPHIR_INIT_VAR(&select$$34);
		ZEPHIR_CONCAT_SVSV(&select$$34, "SELECT ", &_57$$34, " FROM ", &_58$$34);
		if (zephir_fast_count_int(&join TSRMLS_CC) > 0) {
			ZEPHIR_INIT_VAR(&_59$$35);
			zephir_fast_join_str(&_59$$35, SL(" "), &join TSRMLS_CC);
			ZEPHIR_INIT_VAR(&_60$$35);
			ZEPHIR_CONCAT_VSV(&_60$$35, &select$$34, " ", &_59$$35);
			ZEPHIR_CPY_WRT(&select$$34, &_60$$35);
		}
		RETURN_CCTOR(&select$$34);
	}
	RETURN_MM_NULL();

}

PHP_METHOD(Brisk_Toolkit_SQLBuilder_SelectBuilder, pickGroupPart) {

	zend_string *_4$$3;
	zend_ulong _3$$3;
	zval group, group_part, val, _0, _1$$3, *_2$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&group);
	ZVAL_UNDEF(&group_part);
	ZVAL_UNDEF(&val);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&group);
	array_init(&group);
	zephir_read_property(&_0, this_ptr, SL("_parts"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_OBS_VAR(&group_part);
	zephir_array_fetch_string(&group_part, &_0, SL("group"), PH_NOISY, "brisk/Toolkit/SQLBuilder/SelectBuilder.zep", 227 TSRMLS_CC);
	if (zephir_fast_count_int(&group_part TSRMLS_CC) > 0) {
		ZEPHIR_INIT_VAR(&_1$$3);
		zephir_is_iterable(&group_part, 0, "brisk/Toolkit/SQLBuilder/SelectBuilder.zep", 232);
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&group_part), _3$$3, _4$$3, _2$$3)
		{
			ZEPHIR_INIT_NVAR(&_1$$3);
			if (_4$$3 != NULL) { 
				ZVAL_STR_COPY(&_1$$3, _4$$3);
			} else {
				ZVAL_LONG(&_1$$3, _3$$3);
			}
			ZEPHIR_INIT_NVAR(&val);
			ZVAL_COPY(&val, _2$$3);
			zephir_array_append(&group, &val, PH_SEPARATE, "brisk/Toolkit/SQLBuilder/SelectBuilder.zep", 230);
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&val);
		ZEPHIR_INIT_NVAR(&_1$$3);
	}
	zephir_fast_join_str(return_value, SL(", "), &group TSRMLS_CC);
	RETURN_MM();

}

PHP_METHOD(Brisk_Toolkit_SQLBuilder_SelectBuilder, pickHavingPart) {

	zend_string *_3$$3;
	zend_ulong _2$$3;
	zval having, having_part, key, val, part, cond, value, _0, _11, *_1$$3, _4$$6, _5$$6, _6$$7, _8$$7, _9$$4, _10$$8;
	zephir_fcall_cache_entry *_7 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&having);
	ZVAL_UNDEF(&having_part);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&val);
	ZVAL_UNDEF(&part);
	ZVAL_UNDEF(&cond);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_4$$6);
	ZVAL_UNDEF(&_5$$6);
	ZVAL_UNDEF(&_6$$7);
	ZVAL_UNDEF(&_8$$7);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_10$$8);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&having);
	array_init(&having);
	zephir_read_property(&_0, this_ptr, SL("_parts"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_OBS_VAR(&having_part);
	zephir_array_fetch_string(&having_part, &_0, SL("having"), PH_NOISY, "brisk/Toolkit/SQLBuilder/SelectBuilder.zep", 241 TSRMLS_CC);
	if (zephir_fast_count_int(&having_part TSRMLS_CC) > 0) {
		zephir_is_iterable(&having_part, 0, "brisk/Toolkit/SQLBuilder/SelectBuilder.zep", 260);
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&having_part), _2$$3, _3$$3, _1$$3)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_3$$3 != NULL) { 
				ZVAL_STR_COPY(&key, _3$$3);
			} else {
				ZVAL_LONG(&key, _2$$3);
			}
			ZEPHIR_INIT_NVAR(&val);
			ZVAL_COPY(&val, _1$$3);
			ZEPHIR_INIT_NVAR(&part);
			ZVAL_STRING(&part, "");
			ZEPHIR_OBS_NVAR(&cond);
			zephir_array_fetch_string(&cond, &val, SL("cond"), PH_NOISY, "brisk/Toolkit/SQLBuilder/SelectBuilder.zep", 245 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(&value);
			zephir_array_fetch_string(&value, &val, SL("val"), PH_NOISY, "brisk/Toolkit/SQLBuilder/SelectBuilder.zep", 246 TSRMLS_CC);
			if (Z_TYPE_P(&value) == IS_NULL) {
				ZEPHIR_CPY_WRT(&part, &cond);
				if (zephir_instance_of_ev(&cond, brisk_toolkit_sqlbuilder_selectbuilder_ce TSRMLS_CC)) {
					ZEPHIR_CALL_METHOD(&_4$$6, &cond, "pickhavingpart", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_INIT_LNVAR(_5$$6);
					ZEPHIR_CONCAT_VSVS(&_5$$6, &part, "(", &_4$$6, ")");
					ZEPHIR_CPY_WRT(&part, &_5$$6);
				}
			} else {
				ZEPHIR_CALL_METHOD(&_6$$7, this_ptr, "_parseexpr", &_7, 0, &cond, &value);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_8$$7);
				ZEPHIR_CONCAT_VV(&_8$$7, &part, &_6$$7);
				ZEPHIR_CPY_WRT(&part, &_8$$7);
			}
			zephir_array_fetch_long(&_9$$4, &having_part, (zephir_get_numberval(&key) + 1), PH_NOISY | PH_READONLY, "brisk/Toolkit/SQLBuilder/SelectBuilder.zep", 255 TSRMLS_CC);
			if (!(Z_TYPE_P(&_9$$4) == IS_NULL)) {
				ZEPHIR_INIT_LNVAR(_10$$8);
				ZEPHIR_CONCAT_VS(&_10$$8, &part, " AND ");
				ZEPHIR_CPY_WRT(&part, &_10$$8);
			}
			zephir_array_append(&having, &part, PH_SEPARATE, "brisk/Toolkit/SQLBuilder/SelectBuilder.zep", 258);
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&val);
		ZEPHIR_INIT_NVAR(&key);
	}
	ZEPHIR_INIT_VAR(&_11);
	if (zephir_is_true(&having)) {
		zephir_fast_join_str(&_11, SL(" "), &having TSRMLS_CC);
	} else {
		ZVAL_NULL(&_11);
	}
	RETURN_CCTOR(&_11);

}

PHP_METHOD(Brisk_Toolkit_SQLBuilder_SelectBuilder, pickOrderPart) {

	zend_string *_4$$3;
	zend_ulong _3$$3;
	zend_bool by = 0;
	zval order, order_part, v, _0, _11, _1$$3, *_2$$3, _5$$4, _6$$5, _7$$6, _8$$6, _9$$6, _10$$6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&order);
	ZVAL_UNDEF(&order_part);
	ZVAL_UNDEF(&v);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_8$$6);
	ZVAL_UNDEF(&_9$$6);
	ZVAL_UNDEF(&_10$$6);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&order);
	array_init(&order);
	zephir_read_property(&_0, this_ptr, SL("_parts"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_OBS_VAR(&order_part);
	zephir_array_fetch_string(&order_part, &_0, SL("order"), PH_NOISY, "brisk/Toolkit/SQLBuilder/SelectBuilder.zep", 268 TSRMLS_CC);
	if (zephir_fast_count_int(&order_part TSRMLS_CC) > 0) {
		ZEPHIR_INIT_VAR(&_1$$3);
		zephir_is_iterable(&order_part, 0, "brisk/Toolkit/SQLBuilder/SelectBuilder.zep", 278);
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&order_part), _3$$3, _4$$3, _2$$3)
		{
			ZEPHIR_INIT_NVAR(&_1$$3);
			if (_4$$3 != NULL) { 
				ZVAL_STR_COPY(&_1$$3, _4$$3);
			} else {
				ZVAL_LONG(&_1$$3, _3$$3);
			}
			ZEPHIR_INIT_NVAR(&v);
			ZVAL_COPY(&v, _2$$3);
			zephir_array_fetch_long(&_5$$4, &v, 1, PH_NOISY | PH_READONLY, "brisk/Toolkit/SQLBuilder/SelectBuilder.zep", 271 TSRMLS_CC);
			if (Z_TYPE_P(&_5$$4) == IS_NULL) {
				zephir_array_fetch_long(&_6$$5, &v, 0, PH_NOISY | PH_READONLY, "brisk/Toolkit/SQLBuilder/SelectBuilder.zep", 272 TSRMLS_CC);
				zephir_array_append(&order, &_6$$5, PH_SEPARATE, "brisk/Toolkit/SQLBuilder/SelectBuilder.zep", 272);
			} else {
				ZEPHIR_OBS_NVAR(&_7$$6);
				zephir_array_fetch_long(&_7$$6, &v, 1, PH_NOISY, "brisk/Toolkit/SQLBuilder/SelectBuilder.zep", 274 TSRMLS_CC);
				by = zephir_get_boolval(&_7$$6);
				zephir_array_fetch_long(&_8$$6, &v, 0, PH_NOISY | PH_READONLY, "brisk/Toolkit/SQLBuilder/SelectBuilder.zep", 275 TSRMLS_CC);
				ZEPHIR_INIT_LNVAR(_9$$6);
				if (by) {
					ZEPHIR_INIT_NVAR(&_9$$6);
					ZVAL_STRING(&_9$$6, "ASC");
				} else {
					ZEPHIR_INIT_NVAR(&_9$$6);
					ZVAL_STRING(&_9$$6, "DESC");
				}
				ZEPHIR_INIT_LNVAR(_10$$6);
				ZEPHIR_CONCAT_VSV(&_10$$6, &_8$$6, " ", &_9$$6);
				zephir_array_append(&order, &_10$$6, PH_SEPARATE, "brisk/Toolkit/SQLBuilder/SelectBuilder.zep", 275);
			}
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&v);
		ZEPHIR_INIT_NVAR(&_1$$3);
	}
	ZEPHIR_INIT_VAR(&_11);
	if (zephir_is_true(&order)) {
		zephir_fast_join_str(&_11, SL(", "), &order TSRMLS_CC);
	} else {
		ZVAL_NULL(&_11);
	}
	RETURN_CCTOR(&_11);

}

PHP_METHOD(Brisk_Toolkit_SQLBuilder_SelectBuilder, pickLimitPart) {

	zval limit, limit_part, _0, offset_part$$3, _1$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&limit);
	ZVAL_UNDEF(&limit_part);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&offset_part$$3);
	ZVAL_UNDEF(&_1$$3);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&limit);
	ZVAL_STRING(&limit, "");
	zephir_read_property(&_0, this_ptr, SL("_parts"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch_string(&limit_part, &_0, SL("limit"), PH_NOISY | PH_READONLY, "brisk/Toolkit/SQLBuilder/SelectBuilder.zep", 286 TSRMLS_CC);
	if (!ZEPHIR_IS_STRING(&limit_part, "")) {
		zephir_read_property(&_1$$3, this_ptr, SL("_parts"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_OBS_VAR(&offset_part$$3);
		zephir_array_fetch_string(&offset_part$$3, &_1$$3, SL("offset"), PH_NOISY, "brisk/Toolkit/SQLBuilder/SelectBuilder.zep", 289 TSRMLS_CC);
		if (!ZEPHIR_IS_STRING(&offset_part$$3, "")) {
			ZEPHIR_INIT_NVAR(&limit);
			ZEPHIR_CONCAT_VSV(&limit, &limit_part, " OFFSET ", &offset_part$$3);
		} else {
			ZEPHIR_CPY_WRT(&limit, &limit_part);
		}
	}
	RETURN_CCTOR(&limit);

}

PHP_METHOD(Brisk_Toolkit_SQLBuilder_SelectBuilder, getSQL) {

	zval select, where$$3, group$$3, having$$3, order$$3, limit$$3, _0$$4, _1$$5, _2$$6, _3$$7, _4$$8;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&select);
	ZVAL_UNDEF(&where$$3);
	ZVAL_UNDEF(&group$$3);
	ZVAL_UNDEF(&having$$3);
	ZVAL_UNDEF(&order$$3);
	ZVAL_UNDEF(&limit$$3);
	ZVAL_UNDEF(&_0$$4);
	ZVAL_UNDEF(&_1$$5);
	ZVAL_UNDEF(&_2$$6);
	ZVAL_UNDEF(&_3$$7);
	ZVAL_UNDEF(&_4$$8);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&select, this_ptr, "pickselectpart", NULL, 0);
	zephir_check_call_status();
	if (!ZEPHIR_IS_STRING(&select, "")) {
		ZEPHIR_CALL_METHOD(&where$$3, this_ptr, "pickwherepart", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&group$$3, this_ptr, "pickgrouppart", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&having$$3, this_ptr, "pickhavingpart", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&order$$3, this_ptr, "pickorderpart", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&limit$$3, this_ptr, "picklimitpart", NULL, 0);
		zephir_check_call_status();
		if (!ZEPHIR_IS_STRING(&where$$3, "")) {
			ZEPHIR_INIT_VAR(&_0$$4);
			ZEPHIR_CONCAT_VSV(&_0$$4, &select, " WHERE ", &where$$3);
			ZEPHIR_CPY_WRT(&select, &_0$$4);
		}
		if (!ZEPHIR_IS_STRING(&group$$3, "")) {
			ZEPHIR_INIT_VAR(&_1$$5);
			ZEPHIR_CONCAT_VSV(&_1$$5, &select, " GROUP BY ", &group$$3);
			ZEPHIR_CPY_WRT(&select, &_1$$5);
		}
		if (!ZEPHIR_IS_STRING(&having$$3, "")) {
			ZEPHIR_INIT_VAR(&_2$$6);
			ZEPHIR_CONCAT_VSV(&_2$$6, &select, " HAVING ", &having$$3);
			ZEPHIR_CPY_WRT(&select, &_2$$6);
		}
		if (!ZEPHIR_IS_STRING(&order$$3, "")) {
			ZEPHIR_INIT_VAR(&_3$$7);
			ZEPHIR_CONCAT_VSV(&_3$$7, &select, " ORDER BY ", &order$$3);
			ZEPHIR_CPY_WRT(&select, &_3$$7);
		}
		if (!ZEPHIR_IS_STRING(&limit$$3, "")) {
			ZEPHIR_INIT_VAR(&_4$$8);
			ZEPHIR_CONCAT_VSV(&_4$$8, &select, " LIMIT ", &limit$$3);
			ZEPHIR_CPY_WRT(&select, &_4$$8);
		}
		RETURN_CCTOR(&select);
	}
	RETURN_MM_NULL();

}



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
#include "kernel/memory.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/concat.h"
#include "kernel/string.h"
#include "kernel/fcall.h"


ZEPHIR_INIT_CLASS(Brisk_Toolkit_SQLBuilder_InsertBuilder) {

	ZEPHIR_REGISTER_CLASS_EX(Brisk\\Toolkit\\SQLBuilder, InsertBuilder, brisk, toolkit_sqlbuilder_insertbuilder, brisk_toolkit_sqlbuilder_builderfather_ce, brisk_toolkit_sqlbuilder_insertbuilder_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	return SUCCESS;

}

PHP_METHOD(Brisk_Toolkit_SQLBuilder_InsertBuilder, into) {

	zval data;
	zval *table_param = NULL, *data_param = NULL, _0, _1;
	zval table;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&table);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&data);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &table_param, &data_param);

	if (UNEXPECTED(Z_TYPE_P(table_param) != IS_STRING && Z_TYPE_P(table_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'table' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(table_param) == IS_STRING)) {
		zephir_get_strval(&table, table_param);
	} else {
		ZEPHIR_INIT_VAR(&table);
		ZVAL_EMPTY_STRING(&table);
	}
	ZEPHIR_OBS_COPY_OR_DUP(&data, data_param);


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "table");
	zephir_update_property_array(this_ptr, SL("_parts"), &_0, &table TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "data");
	zephir_update_property_array(this_ptr, SL("_parts"), &_1, &data TSRMLS_CC);
	RETURN_THIS();

}

PHP_METHOD(Brisk_Toolkit_SQLBuilder_InsertBuilder, pickInsertPart) {

	zend_bool _2;
	zval table, data, result, _0, _1, _3$$3, _4$$3, _5$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&table);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("_parts"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_OBS_VAR(&table);
	zephir_array_fetch_string(&table, &_0, SL("table"), PH_NOISY, "brisk/Toolkit/SQLBuilder/InsertBuilder.zep", 16 TSRMLS_CC);
	zephir_read_property(&_1, this_ptr, SL("_parts"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_OBS_VAR(&data);
	zephir_array_fetch_string(&data, &_1, SL("data"), PH_NOISY, "brisk/Toolkit/SQLBuilder/InsertBuilder.zep", 17 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&result);
	ZVAL_STRING(&result, "");
	_2 = !ZEPHIR_IS_STRING(&table, "");
	if (_2) {
		_2 = zephir_fast_count_int(&data TSRMLS_CC) > 0;
	}
	if (_2) {
		ZEPHIR_INIT_VAR(&_3$$3);
		ZEPHIR_CONCAT_VSV(&_3$$3, &result, "INSERT INTO ", &table);
		ZEPHIR_CPY_WRT(&result, &_3$$3);
		ZEPHIR_INIT_VAR(&_4$$3);
		ZEPHIR_INIT_VAR(&_5$$3);
		zephir_array_keys(&_5$$3, &data TSRMLS_CC);
		zephir_fast_join_str(&_4$$3, SL(", "), &_5$$3 TSRMLS_CC);
		ZEPHIR_INIT_LNVAR(_3$$3);
		ZEPHIR_CONCAT_VSVS(&_3$$3, &result, "(", &_4$$3, ")");
		ZEPHIR_CPY_WRT(&result, &_3$$3);
	}
	RETURN_CCTOR(&result);

}

PHP_METHOD(Brisk_Toolkit_SQLBuilder_InsertBuilder, pickValuesPart) {

	zval _8$$4;
	zend_string *_3;
	zend_ulong _2;
	zval data, result, k, v, _0, *_1, _12, _13, _4$$3, _5$$3, _6$$3, _7$$4, _9$$4, _10$$5, _11$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&k);
	ZVAL_UNDEF(&v);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_8$$4);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("_parts"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_OBS_VAR(&data);
	zephir_array_fetch_string(&data, &_0, SL("data"), PH_NOISY, "brisk/Toolkit/SQLBuilder/InsertBuilder.zep", 29 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&result);
	ZVAL_STRING(&result, "VALUES");
	zephir_is_iterable(&data, 1, "brisk/Toolkit/SQLBuilder/InsertBuilder.zep", 40);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&data), _2, _3, _1)
	{
		ZEPHIR_INIT_NVAR(&k);
		if (_3 != NULL) { 
			ZVAL_STR_COPY(&k, _3);
		} else {
			ZVAL_LONG(&k, _2);
		}
		ZEPHIR_INIT_NVAR(&v);
		ZVAL_COPY(&v, _1);
		ZEPHIR_INIT_NVAR(&_4$$3);
		ZEPHIR_INIT_NVAR(&_5$$3);
		ZEPHIR_INIT_NVAR(&_6$$3);
		ZVAL_STRING(&_6$$3, "/^\\{\\{.*?\\}\\}$/");
		zephir_preg_match(&_5$$3, &_6$$3, &v, &_4$$3, 0, 0 , 0  TSRMLS_CC);
		if (zephir_is_true(&_5$$3)) {
			ZEPHIR_INIT_NVAR(&_7$$4);
			ZEPHIR_INIT_NVAR(&_8$$4);
			zephir_create_array(&_8$$4, 2, 0 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(&_9$$4);
			ZVAL_STRING(&_9$$4, "{{");
			zephir_array_fast_append(&_8$$4, &_9$$4);
			ZEPHIR_INIT_NVAR(&_9$$4);
			ZVAL_STRING(&_9$$4, "}}");
			zephir_array_fast_append(&_8$$4, &_9$$4);
			ZEPHIR_INIT_NVAR(&_9$$4);
			ZVAL_STRING(&_9$$4, "");
			zephir_fast_str_replace(&_7$$4, &_8$$4, &_9$$4, &v TSRMLS_CC);
			ZEPHIR_CPY_WRT(&v, &_7$$4);
			zephir_array_update_zval(&data, &k, &v, PH_COPY | PH_SEPARATE);
		} else {
			ZEPHIR_INIT_LNVAR(_10$$5);
			ZEPHIR_CONCAT_SV(&_10$$5, ":", &k);
			zephir_update_property_array(this_ptr, SL("_db_bind"), &_10$$5, &v TSRMLS_CC);
			ZEPHIR_INIT_LNVAR(_11$$5);
			ZEPHIR_CONCAT_SV(&_11$$5, ":", &k);
			zephir_array_update_zval(&data, &k, &_11$$5, PH_COPY | PH_SEPARATE);
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&v);
	ZEPHIR_INIT_NVAR(&k);
	ZEPHIR_INIT_VAR(&_12);
	zephir_fast_join_str(&_12, SL(", "), &data TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_13);
	ZEPHIR_CONCAT_VSVS(&_13, &result, "(", &_12, ")");
	ZEPHIR_CPY_WRT(&result, &_13);
	RETURN_CCTOR(&result);

}

PHP_METHOD(Brisk_Toolkit_SQLBuilder_InsertBuilder, getSQL) {

	zend_bool _0;
	zval insert, values;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&insert);
	ZVAL_UNDEF(&values);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&insert, this_ptr, "pickinsertpart", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&values, this_ptr, "pickvaluespart", NULL, 0);
	zephir_check_call_status();
	_0 = !ZEPHIR_IS_STRING(&insert, "");
	if (_0) {
		_0 = !ZEPHIR_IS_STRING(&values, "");
	}
	if (_0) {
		ZEPHIR_CONCAT_VSV(return_value, &insert, " ", &values);
		RETURN_MM();
	}
	RETURN_MM_NULL();

}


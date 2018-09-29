
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


ZEPHIR_INIT_CLASS(Brisk_Vendor_Querier_Insert) {

	ZEPHIR_REGISTER_CLASS_EX(Brisk\\Vendor\\Querier, Insert, brisk, vendor_querier_insert, brisk_vendor_querier_querierfather_ce, brisk_vendor_querier_insert_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	return SUCCESS;

}

/**
 * Setting the into field in the sql statement
 *
 * @param string table
 * @param array data
 * @return Insert
 */
PHP_METHOD(Brisk_Vendor_Querier_Insert, into) {

	zval *data = NULL;
	zval *table_param = NULL, *data_param = NULL, *_0, *_1;
	zval *table = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &table_param, &data_param);

	if (UNEXPECTED(Z_TYPE_P(table_param) != IS_STRING && Z_TYPE_P(table_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'table' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(table_param) == IS_STRING)) {
		zephir_get_strval(table, table_param);
	} else {
		ZEPHIR_INIT_VAR(table);
		ZVAL_EMPTY_STRING(table);
	}
	data = data_param;


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "table", 1);
	zephir_update_property_array(this_ptr, SL("_parts"), _0, table TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "data", 1);
	zephir_update_property_array(this_ptr, SL("_parts"), _1, data TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Get the insert fragment in the sql statement
 *
 * @return string
 */
PHP_METHOD(Brisk_Vendor_Querier_Insert, pickInsertPart) {

	zend_bool _2;
	zval *table = NULL, *data = NULL, *result = NULL, *_0, *_1, *_3$$3 = NULL, *_4$$3, *_5$$3;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_parts"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(table);
	zephir_array_fetch_string(&table, _0, SL("table"), PH_NOISY, "brisk/Vendor/Querier/Insert.zep", 28 TSRMLS_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_parts"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(data);
	zephir_array_fetch_string(&data, _1, SL("data"), PH_NOISY, "brisk/Vendor/Querier/Insert.zep", 29 TSRMLS_CC);
	ZEPHIR_INIT_VAR(result);
	ZVAL_STRING(result, "", 1);
	_2 = !ZEPHIR_IS_STRING(table, "");
	if (_2) {
		_2 = zephir_fast_count_int(data TSRMLS_CC) > 0;
	}
	if (_2) {
		ZEPHIR_INIT_VAR(_3$$3);
		ZEPHIR_CONCAT_VSV(_3$$3, result, "INSERT INTO ", table);
		ZEPHIR_CPY_WRT(result, _3$$3);
		ZEPHIR_INIT_VAR(_4$$3);
		ZEPHIR_INIT_VAR(_5$$3);
		zephir_array_keys(_5$$3, data TSRMLS_CC);
		zephir_fast_join_str(_4$$3, SL(", "), _5$$3 TSRMLS_CC);
		ZEPHIR_INIT_LNVAR(_3$$3);
		ZEPHIR_CONCAT_VSVS(_3$$3, result, "(", _4$$3, ")");
		ZEPHIR_CPY_WRT(result, _3$$3);
	}
	RETURN_CCTOR(result);

}

/**
 * Get the values fragment in the sql statement
 *
 * @return string
 */
PHP_METHOD(Brisk_Vendor_Querier_Insert, pickValuesPart) {

	zval *_8$$4 = NULL;
	HashTable *_2;
	HashPosition _1;
	zval *data = NULL, *result = NULL, *k = NULL, *v = NULL, *_0, **_3, *_13, *_14, *_4$$3 = NULL, *_5$$3 = NULL, _6$$3 = zval_used_for_init, *_7$$4 = NULL, *_9$$4 = NULL, _10$$4 = zval_used_for_init, *_11$$5 = NULL, *_12$$5 = NULL;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_parts"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(data);
	zephir_array_fetch_string(&data, _0, SL("data"), PH_NOISY, "brisk/Vendor/Querier/Insert.zep", 46 TSRMLS_CC);
	ZEPHIR_INIT_VAR(result);
	ZVAL_STRING(result, "VALUES", 1);
	zephir_is_iterable(data, &_2, &_1, 1, 0, "brisk/Vendor/Querier/Insert.zep", 57);
	for (
	  ; zend_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zend_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HMKEY(k, _2, _1);
		ZEPHIR_GET_HVALUE(v, _3);
		ZEPHIR_INIT_NVAR(_4$$3);
		ZEPHIR_INIT_NVAR(_5$$3);
		ZEPHIR_SINIT_NVAR(_6$$3);
		ZVAL_STRING(&_6$$3, "/^\\{\\{.*?\\}\\}$/", 0);
		zephir_preg_match(_5$$3, &_6$$3, v, _4$$3, 0, 0 , 0  TSRMLS_CC);
		if (zephir_is_true(_5$$3)) {
			ZEPHIR_INIT_NVAR(_7$$4);
			ZEPHIR_INIT_NVAR(_8$$4);
			zephir_create_array(_8$$4, 2, 0 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(_9$$4);
			ZVAL_STRING(_9$$4, "{{", 1);
			zephir_array_fast_append(_8$$4, _9$$4);
			ZEPHIR_INIT_NVAR(_9$$4);
			ZVAL_STRING(_9$$4, "}}", 1);
			zephir_array_fast_append(_8$$4, _9$$4);
			ZEPHIR_SINIT_NVAR(_10$$4);
			ZVAL_STRING(&_10$$4, "", 0);
			zephir_fast_str_replace(&_7$$4, _8$$4, &_10$$4, v TSRMLS_CC);
			ZEPHIR_CPY_WRT(v, _7$$4);
			zephir_array_update_zval(&data, k, &v, PH_COPY | PH_SEPARATE);
		} else {
			ZEPHIR_INIT_LNVAR(_11$$5);
			ZEPHIR_CONCAT_SV(_11$$5, ":", k);
			zephir_update_property_array(this_ptr, SL("_db_bind"), _11$$5, v TSRMLS_CC);
			ZEPHIR_INIT_LNVAR(_12$$5);
			ZEPHIR_CONCAT_SV(_12$$5, ":", k);
			zephir_array_update_zval(&data, k, &_12$$5, PH_COPY | PH_SEPARATE);
		}
	}
	zend_hash_destroy(_2);
	FREE_HASHTABLE(_2);
	ZEPHIR_INIT_VAR(_13);
	zephir_fast_join_str(_13, SL(", "), data TSRMLS_CC);
	ZEPHIR_INIT_VAR(_14);
	ZEPHIR_CONCAT_VSVS(_14, result, "(", _13, ")");
	ZEPHIR_CPY_WRT(result, _14);
	RETURN_CCTOR(result);

}

/**
 * Get the full sql statement
 *
 * @return string
 */
PHP_METHOD(Brisk_Vendor_Querier_Insert, getSQL) {

	zend_bool _0;
	zval *insert = NULL, *values = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&insert, this_ptr, "pickinsertpart", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&values, this_ptr, "pickvaluespart", NULL, 0);
	zephir_check_call_status();
	_0 = !ZEPHIR_IS_STRING(insert, "");
	if (_0) {
		_0 = !ZEPHIR_IS_STRING(values, "");
	}
	if (_0) {
		ZEPHIR_CONCAT_VSV(return_value, insert, " ", values);
		RETURN_MM();
	}
	RETURN_MM_NULL();

}

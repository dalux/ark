
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
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "kernel/string.h"


ZEPHIR_INIT_CLASS(Brisk_Vendor_Querier_Update) {

	ZEPHIR_REGISTER_CLASS_EX(Brisk\\Vendor\\Querier, Update, brisk, vendor_querier_update, brisk_vendor_querier_querierfather_ce, brisk_vendor_querier_update_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	return SUCCESS;

}

/**
 * Setting the set field in the sql statement
 *
 * @param mixed table
 * @param array updates
 * @return Update
 */
PHP_METHOD(Brisk_Vendor_Querier_Update, set) {

	zval *updates = NULL;
	zval *table, *updates_param = NULL, *tables = NULL, *_0, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &table, &updates_param);

	if (!updates_param) {
		ZEPHIR_INIT_VAR(updates);
		array_init(updates);
	} else {
	updates = updates_param;
	}


	if (!(Z_TYPE_P(table) == IS_ARRAY)) {
		ZEPHIR_INIT_VAR(tables);
		zephir_create_array(tables, 1, 0 TSRMLS_CC);
		zephir_array_fast_append(tables, table);
	} else {
		ZEPHIR_CPY_WRT(tables, table);
	}
	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "update", 1);
	zephir_update_property_array(this_ptr, SL("_parts"), _0, tables TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "set", 1);
	zephir_update_property_array(this_ptr, SL("_parts"), _1, updates TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Get the full sql statement
 *
 * @return string
 */
PHP_METHOD(Brisk_Vendor_Querier_Update, getSQL) {

	zval *_11$$7 = NULL;
	HashTable *_5$$3;
	HashPosition _4$$3;
	zend_bool _2;
	zval *update_part = NULL, *set_part = NULL, *_0, *_1, *sql$$3 = NULL, *update$$3 = NULL, *set$$3 = NULL, *alias$$3 = NULL, *k$$3 = NULL, *v$$3 = NULL, *_3$$3 = NULL, *_key$$3 = NULL, *_val$$3 = NULL, **_6$$3, *_19$$3, *_20$$3, *where$$3 = NULL, *_7$$6 = NULL, *_8$$6 = NULL, _9$$6 = zval_used_for_init, *_10$$7 = NULL, *_12$$7 = NULL, _13$$7 = zval_used_for_init, *_14$$8 = NULL, *_15$$9 = NULL, *_16$$10 = NULL, *_17$$11 = NULL, *_18$$12 = NULL, *_21$$13;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_parts"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(update_part);
	zephir_array_fetch_string(&update_part, _0, SL("update"), PH_NOISY, "brisk/Vendor/Querier/Update.zep", 34 TSRMLS_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_parts"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(set_part);
	zephir_array_fetch_string(&set_part, _1, SL("set"), PH_NOISY, "brisk/Vendor/Querier/Update.zep", 35 TSRMLS_CC);
	_2 = zephir_fast_count_int(update_part TSRMLS_CC) > 0;
	if (_2) {
		_2 = zephir_fast_count_int(set_part TSRMLS_CC) > 0;
	}
	if (_2) {
		ZEPHIR_INIT_VAR(update$$3);
		ZVAL_STRING(update$$3, "UPDATE", 1);
		ZEPHIR_INIT_VAR(set$$3);
		array_init(set$$3);
		ZEPHIR_MAKE_REF(update_part);
		ZEPHIR_CALL_FUNCTION(&_3$$3, "each", NULL, 5, update_part);
		ZEPHIR_UNREF(update_part);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(update_part, _3$$3);
		ZEPHIR_OBS_VAR(k$$3);
		zephir_array_fetch_string(&k$$3, update_part, SL("key"), PH_NOISY, "brisk/Vendor/Querier/Update.zep", 41 TSRMLS_CC);
		ZEPHIR_OBS_VAR(v$$3);
		zephir_array_fetch_string(&v$$3, update_part, SL("value"), PH_NOISY, "brisk/Vendor/Querier/Update.zep", 42 TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&_3$$3, "is_integer", NULL, 6, k$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(sql$$3);
		if (zephir_is_true(_3$$3)) {
			ZEPHIR_INIT_VAR(alias$$3);
			ZVAL_STRING(alias$$3, "", 1);
			ZEPHIR_CONCAT_VSV(sql$$3, update$$3, " ", v$$3);
		} else {
			ZEPHIR_CPY_WRT(alias$$3, k$$3);
			ZEPHIR_CONCAT_VSVSV(sql$$3, update$$3, " ", v$$3, " ", alias$$3);
		}
		zephir_is_iterable(set_part, &_5$$3, &_4$$3, 0, 0, "brisk/Vendor/Querier/Update.zep", 68);
		for (
		  ; zend_hash_get_current_data_ex(_5$$3, (void**) &_6$$3, &_4$$3) == SUCCESS
		  ; zend_hash_move_forward_ex(_5$$3, &_4$$3)
		) {
			ZEPHIR_GET_HMKEY(_key$$3, _5$$3, _4$$3);
			ZEPHIR_GET_HVALUE(_val$$3, _6$$3);
			ZEPHIR_INIT_NVAR(_7$$6);
			ZEPHIR_INIT_NVAR(_8$$6);
			ZEPHIR_SINIT_NVAR(_9$$6);
			ZVAL_STRING(&_9$$6, "/^\\{\\{.*?\\}\\}$/", 0);
			zephir_preg_match(_8$$6, &_9$$6, _val$$3, _7$$6, 0, 0 , 0  TSRMLS_CC);
			if (zephir_is_true(_8$$6)) {
				ZEPHIR_INIT_NVAR(_10$$7);
				ZEPHIR_INIT_NVAR(_11$$7);
				zephir_create_array(_11$$7, 2, 0 TSRMLS_CC);
				ZEPHIR_INIT_NVAR(_12$$7);
				ZVAL_STRING(_12$$7, "{{", 1);
				zephir_array_fast_append(_11$$7, _12$$7);
				ZEPHIR_INIT_NVAR(_12$$7);
				ZVAL_STRING(_12$$7, "}}", 1);
				zephir_array_fast_append(_11$$7, _12$$7);
				ZEPHIR_SINIT_NVAR(_13$$7);
				ZVAL_STRING(&_13$$7, "", 0);
				zephir_fast_str_replace(&_10$$7, _11$$7, &_13$$7, _val$$3 TSRMLS_CC);
				ZEPHIR_CPY_WRT(_val$$3, _10$$7);
				if (!ZEPHIR_IS_STRING(alias$$3, "")) {
					ZEPHIR_INIT_LNVAR(_14$$8);
					ZEPHIR_CONCAT_VSVSV(_14$$8, alias$$3, ".", _key$$3, "=", _val$$3);
					zephir_array_append(&set$$3, _14$$8, PH_SEPARATE, "brisk/Vendor/Querier/Update.zep", 55);
				} else {
					ZEPHIR_INIT_LNVAR(_15$$9);
					ZEPHIR_CONCAT_VSV(_15$$9, _key$$3, "=", _val$$3);
					zephir_array_append(&set$$3, _15$$9, PH_SEPARATE, "brisk/Vendor/Querier/Update.zep", 57);
				}
			} else {
				ZEPHIR_INIT_LNVAR(_16$$10);
				ZEPHIR_CONCAT_SV(_16$$10, ":", _key$$3);
				zephir_update_property_array(this_ptr, SL("_db_bind"), _16$$10, _val$$3 TSRMLS_CC);
				if (!ZEPHIR_IS_STRING(alias$$3, "")) {
					ZEPHIR_INIT_LNVAR(_17$$11);
					ZEPHIR_CONCAT_VSVSSV(_17$$11, alias$$3, ".", _key$$3, "=", ":", _key$$3);
					zephir_array_append(&set$$3, _17$$11, PH_SEPARATE, "brisk/Vendor/Querier/Update.zep", 62);
				} else {
					ZEPHIR_INIT_LNVAR(_18$$12);
					ZEPHIR_CONCAT_VSSV(_18$$12, _key$$3, "=", ":", _key$$3);
					zephir_array_append(&set$$3, _18$$12, PH_SEPARATE, "brisk/Vendor/Querier/Update.zep", 64);
				}
			}
		}
		ZEPHIR_INIT_VAR(_19$$3);
		zephir_fast_join_str(_19$$3, SL(", "), set$$3 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_20$$3);
		ZEPHIR_CONCAT_VSV(_20$$3, sql$$3, " SET ", _19$$3);
		ZEPHIR_CPY_WRT(sql$$3, _20$$3);
		ZEPHIR_CALL_METHOD(&where$$3, this_ptr, "pickwherepart", NULL, 0);
		zephir_check_call_status();
		if (!ZEPHIR_IS_STRING(where$$3, "")) {
			ZEPHIR_INIT_VAR(_21$$13);
			ZEPHIR_CONCAT_VSV(_21$$13, sql$$3, " WHERE ", where$$3);
			ZEPHIR_CPY_WRT(sql$$3, _21$$13);
		}
		RETURN_CCTOR(sql$$3);
	}
	RETURN_MM_NULL();

}


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
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "kernel/string.h"


ZEPHIR_INIT_CLASS(Brisk_Sql_Update) {

	ZEPHIR_REGISTER_CLASS_EX(Brisk\\Sql, Update, brisk, sql_update, brisk_sql_sqlfather_ce, brisk_sql_update_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	return SUCCESS;

}

/**
 * Setting the set field in the sql statement
 *
 * @param mixed table
 * @param array updates
 * @return Update
 */
PHP_METHOD(Brisk_Sql_Update, set) {

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
 * Compile the update statment
 *
 * @return Update
 */
PHP_METHOD(Brisk_Sql_Update, compile) {

	zval *_15$$7 = NULL;
	HashTable *_9;
	HashPosition _8;
	zend_bool _2;
	zval *update_part = NULL, *set_part = NULL, *_0, *_1, *sql = NULL, *update = NULL, *set = NULL, *alias = NULL, *k = NULL, *v = NULL, *_7 = NULL, *_key = NULL, *_val = NULL, **_10, *_23, *_24, *where = NULL, *_3$$3, *_4$$3 = NULL, *_6$$3, *_11$$6 = NULL, *_12$$6 = NULL, _13$$6 = zval_used_for_init, *_14$$7 = NULL, *_16$$7 = NULL, _17$$7 = zval_used_for_init, *_18$$8 = NULL, *_19$$9 = NULL, *_20$$10 = NULL, *_21$$11 = NULL, *_22$$12 = NULL, *_25$$13;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_5 = NULL;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_parts"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(update_part);
	zephir_array_fetch_string(&update_part, _0, SL("update"), PH_NOISY, "brisk/Sql/Update.zep", 37 TSRMLS_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_parts"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(set_part);
	zephir_array_fetch_string(&set_part, _1, SL("set"), PH_NOISY, "brisk/Sql/Update.zep", 38 TSRMLS_CC);
	_2 = zephir_fast_count_int(update_part TSRMLS_CC) == 0;
	if (!(_2)) {
		_2 = zephir_fast_count_int(set_part TSRMLS_CC) == 0;
	}
	if (_2) {
		ZEPHIR_INIT_VAR(_3$$3);
		object_init_ex(_3$$3, brisk_exception_sqlcompileexception_ce);
		ZEPHIR_INIT_VAR(_6$$3);
		ZVAL_STRING(_6$$3, "querier.sql_compile_failed", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_CE_STATIC(&_4$$3, brisk_kernel_language_ce, "get", &_5, 13, _6$$3);
		zephir_check_temp_parameter(_6$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, _3$$3, "__construct", NULL, 8, _4$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(_3$$3, "brisk/Sql/Update.zep", 40 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(update);
	ZVAL_STRING(update, "UPDATE", 1);
	ZEPHIR_INIT_VAR(set);
	array_init(set);
	ZEPHIR_MAKE_REF(update_part);
	ZEPHIR_CALL_FUNCTION(&_7, "each", NULL, 14, update_part);
	ZEPHIR_UNREF(update_part);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(update_part, _7);
	ZEPHIR_OBS_VAR(k);
	zephir_array_fetch_string(&k, update_part, SL("key"), PH_NOISY, "brisk/Sql/Update.zep", 46 TSRMLS_CC);
	ZEPHIR_OBS_VAR(v);
	zephir_array_fetch_string(&v, update_part, SL("value"), PH_NOISY, "brisk/Sql/Update.zep", 47 TSRMLS_CC);
	ZEPHIR_CALL_FUNCTION(&_7, "is_integer", NULL, 15, k);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(sql);
	if (zephir_is_true(_7)) {
		ZEPHIR_INIT_VAR(alias);
		ZVAL_STRING(alias, "", 1);
		ZEPHIR_CONCAT_VSV(sql, update, " ", v);
	} else {
		ZEPHIR_CPY_WRT(alias, k);
		ZEPHIR_CONCAT_VSVSV(sql, update, " ", v, " ", alias);
	}
	zephir_is_iterable(set_part, &_9, &_8, 0, 0, "brisk/Sql/Update.zep", 73);
	for (
	  ; zend_hash_get_current_data_ex(_9, (void**) &_10, &_8) == SUCCESS
	  ; zend_hash_move_forward_ex(_9, &_8)
	) {
		ZEPHIR_GET_HMKEY(_key, _9, _8);
		ZEPHIR_GET_HVALUE(_val, _10);
		ZEPHIR_INIT_NVAR(_11$$6);
		ZEPHIR_INIT_NVAR(_12$$6);
		ZEPHIR_SINIT_NVAR(_13$$6);
		ZVAL_STRING(&_13$$6, "/^\\{\\{.*?\\}\\}$/", 0);
		zephir_preg_match(_12$$6, &_13$$6, _val, _11$$6, 0, 0 , 0  TSRMLS_CC);
		if (zephir_is_true(_12$$6)) {
			ZEPHIR_INIT_NVAR(_14$$7);
			ZEPHIR_INIT_NVAR(_15$$7);
			zephir_create_array(_15$$7, 2, 0 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(_16$$7);
			ZVAL_STRING(_16$$7, "{{", 1);
			zephir_array_fast_append(_15$$7, _16$$7);
			ZEPHIR_INIT_NVAR(_16$$7);
			ZVAL_STRING(_16$$7, "}}", 1);
			zephir_array_fast_append(_15$$7, _16$$7);
			ZEPHIR_SINIT_NVAR(_17$$7);
			ZVAL_STRING(&_17$$7, "", 0);
			zephir_fast_str_replace(&_14$$7, _15$$7, &_17$$7, _val TSRMLS_CC);
			ZEPHIR_CPY_WRT(_val, _14$$7);
			if (!ZEPHIR_IS_STRING(alias, "")) {
				ZEPHIR_INIT_LNVAR(_18$$8);
				ZEPHIR_CONCAT_VSVSV(_18$$8, alias, ".", _key, "=", _val);
				zephir_array_append(&set, _18$$8, PH_SEPARATE, "brisk/Sql/Update.zep", 60);
			} else {
				ZEPHIR_INIT_LNVAR(_19$$9);
				ZEPHIR_CONCAT_VSV(_19$$9, _key, "=", _val);
				zephir_array_append(&set, _19$$9, PH_SEPARATE, "brisk/Sql/Update.zep", 62);
			}
		} else {
			ZEPHIR_INIT_LNVAR(_20$$10);
			ZEPHIR_CONCAT_SV(_20$$10, ":", _key);
			zephir_update_property_array(this_ptr, SL("_db_bind"), _20$$10, _val TSRMLS_CC);
			if (!ZEPHIR_IS_STRING(alias, "")) {
				ZEPHIR_INIT_LNVAR(_21$$11);
				ZEPHIR_CONCAT_VSVSSV(_21$$11, alias, ".", _key, "=", ":", _key);
				zephir_array_append(&set, _21$$11, PH_SEPARATE, "brisk/Sql/Update.zep", 67);
			} else {
				ZEPHIR_INIT_LNVAR(_22$$12);
				ZEPHIR_CONCAT_VSSV(_22$$12, _key, "=", ":", _key);
				zephir_array_append(&set, _22$$12, PH_SEPARATE, "brisk/Sql/Update.zep", 69);
			}
		}
	}
	ZEPHIR_INIT_VAR(_23);
	zephir_fast_join_str(_23, SL(", "), set TSRMLS_CC);
	ZEPHIR_INIT_VAR(_24);
	ZEPHIR_CONCAT_VSV(_24, sql, " SET ", _23);
	ZEPHIR_CPY_WRT(sql, _24);
	ZEPHIR_CALL_METHOD(&where, this_ptr, "pickwherepart", NULL, 0);
	zephir_check_call_status();
	if (!ZEPHIR_IS_STRING(where, "")) {
		ZEPHIR_INIT_VAR(_25$$13);
		ZEPHIR_CONCAT_VSV(_25$$13, sql, " WHERE ", where);
		ZEPHIR_CPY_WRT(sql, _25$$13);
	}
	zephir_update_property_this(getThis(), SL("_sql"), sql TSRMLS_CC);
	if (1) {
		zephir_update_property_this(getThis(), SL("_compiled"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	} else {
		zephir_update_property_this(getThis(), SL("_compiled"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	}
	RETURN_THIS();

}


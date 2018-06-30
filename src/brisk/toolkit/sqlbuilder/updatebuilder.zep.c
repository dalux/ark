
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


ZEPHIR_INIT_CLASS(Brisk_Toolkit_SQLBuilder_UpdateBuilder) {

	ZEPHIR_REGISTER_CLASS_EX(Brisk\\Toolkit\\SQLBuilder, UpdateBuilder, brisk, toolkit_sqlbuilder_updatebuilder, brisk_toolkit_sqlbuilder_builderfather_ce, brisk_toolkit_sqlbuilder_updatebuilder_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	return SUCCESS;

}

PHP_METHOD(Brisk_Toolkit_SQLBuilder_UpdateBuilder, set) {

	zval updates;
	zval *table, table_sub, *updates_param = NULL, tables, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&table_sub);
	ZVAL_UNDEF(&tables);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&updates);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &table, &updates_param);

	if (!updates_param) {
		ZEPHIR_INIT_VAR(&updates);
		array_init(&updates);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&updates, updates_param);
	}


	if (!(Z_TYPE_P(table) == IS_ARRAY)) {
		ZEPHIR_INIT_VAR(&tables);
		zephir_create_array(&tables, 1, 0 TSRMLS_CC);
		zephir_array_fast_append(&tables, table);
	} else {
		ZEPHIR_CPY_WRT(&tables, table);
	}
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "update");
	zephir_update_property_array(this_ptr, SL("_parts"), &_0, &tables TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "set");
	zephir_update_property_array(this_ptr, SL("_parts"), &_1, &updates TSRMLS_CC);
	RETURN_THIS();

}

PHP_METHOD(Brisk_Toolkit_SQLBuilder_UpdateBuilder, getSQL) {

	zval _11$$7;
	zend_string *_6$$3;
	zend_ulong _5$$3;
	zend_bool _2;
	zval update_part, set_part, _0, _1, sql$$3, update$$3, set$$3, alias$$3, k$$3, v$$3, _3$$3, _key$$3, _val$$3, *_4$$3, _18$$3, _19$$3, where$$3, _7$$6, _8$$6, _9$$6, _10$$7, _12$$7, _13$$8, _14$$9, _15$$10, _16$$11, _17$$12, _20$$13;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&update_part);
	ZVAL_UNDEF(&set_part);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&sql$$3);
	ZVAL_UNDEF(&update$$3);
	ZVAL_UNDEF(&set$$3);
	ZVAL_UNDEF(&alias$$3);
	ZVAL_UNDEF(&k$$3);
	ZVAL_UNDEF(&v$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_key$$3);
	ZVAL_UNDEF(&_val$$3);
	ZVAL_UNDEF(&_18$$3);
	ZVAL_UNDEF(&_19$$3);
	ZVAL_UNDEF(&where$$3);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_8$$6);
	ZVAL_UNDEF(&_9$$6);
	ZVAL_UNDEF(&_10$$7);
	ZVAL_UNDEF(&_12$$7);
	ZVAL_UNDEF(&_13$$8);
	ZVAL_UNDEF(&_14$$9);
	ZVAL_UNDEF(&_15$$10);
	ZVAL_UNDEF(&_16$$11);
	ZVAL_UNDEF(&_17$$12);
	ZVAL_UNDEF(&_20$$13);
	ZVAL_UNDEF(&_11$$7);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("_parts"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_OBS_VAR(&update_part);
	zephir_array_fetch_string(&update_part, &_0, SL("update"), PH_NOISY, "brisk/Toolkit/SQLBuilder/UpdateBuilder.zep", 22 TSRMLS_CC);
	zephir_read_property(&_1, this_ptr, SL("_parts"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_OBS_VAR(&set_part);
	zephir_array_fetch_string(&set_part, &_1, SL("set"), PH_NOISY, "brisk/Toolkit/SQLBuilder/UpdateBuilder.zep", 23 TSRMLS_CC);
	_2 = zephir_fast_count_int(&update_part TSRMLS_CC) > 0;
	if (_2) {
		_2 = zephir_fast_count_int(&set_part TSRMLS_CC) > 0;
	}
	if (_2) {
		ZEPHIR_INIT_VAR(&update$$3);
		ZVAL_STRING(&update$$3, "UPDATE");
		ZEPHIR_INIT_VAR(&set$$3);
		array_init(&set$$3);
		ZEPHIR_MAKE_REF(&update_part);
		ZEPHIR_CALL_FUNCTION(&_3$$3, "each", NULL, 5, &update_part);
		ZEPHIR_UNREF(&update_part);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&update_part, &_3$$3);
		ZEPHIR_OBS_VAR(&k$$3);
		zephir_array_fetch_string(&k$$3, &update_part, SL("key"), PH_NOISY, "brisk/Toolkit/SQLBuilder/UpdateBuilder.zep", 29 TSRMLS_CC);
		ZEPHIR_OBS_VAR(&v$$3);
		zephir_array_fetch_string(&v$$3, &update_part, SL("value"), PH_NOISY, "brisk/Toolkit/SQLBuilder/UpdateBuilder.zep", 30 TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&_3$$3, "is_integer", NULL, 6, &k$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&sql$$3);
		if (zephir_is_true(&_3$$3)) {
			ZEPHIR_INIT_VAR(&alias$$3);
			ZVAL_STRING(&alias$$3, "");
			ZEPHIR_CONCAT_VSV(&sql$$3, &update$$3, " ", &v$$3);
		} else {
			ZEPHIR_CPY_WRT(&alias$$3, &k$$3);
			ZEPHIR_CONCAT_VSVSV(&sql$$3, &update$$3, " ", &v$$3, " ", &alias$$3);
		}
		zephir_is_iterable(&set_part, 0, "brisk/Toolkit/SQLBuilder/UpdateBuilder.zep", 56);
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&set_part), _5$$3, _6$$3, _4$$3)
		{
			ZEPHIR_INIT_NVAR(&_key$$3);
			if (_6$$3 != NULL) { 
				ZVAL_STR_COPY(&_key$$3, _6$$3);
			} else {
				ZVAL_LONG(&_key$$3, _5$$3);
			}
			ZEPHIR_INIT_NVAR(&_val$$3);
			ZVAL_COPY(&_val$$3, _4$$3);
			ZEPHIR_INIT_NVAR(&_7$$6);
			ZEPHIR_INIT_NVAR(&_8$$6);
			ZEPHIR_INIT_NVAR(&_9$$6);
			ZVAL_STRING(&_9$$6, "/^\\{\\{.*?\\}\\}$/");
			zephir_preg_match(&_8$$6, &_9$$6, &_val$$3, &_7$$6, 0, 0 , 0  TSRMLS_CC);
			if (zephir_is_true(&_8$$6)) {
				ZEPHIR_INIT_NVAR(&_10$$7);
				ZEPHIR_INIT_NVAR(&_11$$7);
				zephir_create_array(&_11$$7, 2, 0 TSRMLS_CC);
				ZEPHIR_INIT_NVAR(&_12$$7);
				ZVAL_STRING(&_12$$7, "{{");
				zephir_array_fast_append(&_11$$7, &_12$$7);
				ZEPHIR_INIT_NVAR(&_12$$7);
				ZVAL_STRING(&_12$$7, "}}");
				zephir_array_fast_append(&_11$$7, &_12$$7);
				ZEPHIR_INIT_NVAR(&_12$$7);
				ZVAL_STRING(&_12$$7, "");
				zephir_fast_str_replace(&_10$$7, &_11$$7, &_12$$7, &_val$$3 TSRMLS_CC);
				ZEPHIR_CPY_WRT(&_val$$3, &_10$$7);
				if (!ZEPHIR_IS_STRING(&alias$$3, "")) {
					ZEPHIR_INIT_LNVAR(_13$$8);
					ZEPHIR_CONCAT_VSVSV(&_13$$8, &alias$$3, ".", &_key$$3, "=", &_val$$3);
					zephir_array_append(&set$$3, &_13$$8, PH_SEPARATE, "brisk/Toolkit/SQLBuilder/UpdateBuilder.zep", 43);
				} else {
					ZEPHIR_INIT_LNVAR(_14$$9);
					ZEPHIR_CONCAT_VSV(&_14$$9, &_key$$3, "=", &_val$$3);
					zephir_array_append(&set$$3, &_14$$9, PH_SEPARATE, "brisk/Toolkit/SQLBuilder/UpdateBuilder.zep", 45);
				}
			} else {
				ZEPHIR_INIT_LNVAR(_15$$10);
				ZEPHIR_CONCAT_SV(&_15$$10, ":", &_key$$3);
				zephir_update_property_array(this_ptr, SL("_db_bind"), &_15$$10, &_val$$3 TSRMLS_CC);
				if (!ZEPHIR_IS_STRING(&alias$$3, "")) {
					ZEPHIR_INIT_LNVAR(_16$$11);
					ZEPHIR_CONCAT_VSVSSV(&_16$$11, &alias$$3, ".", &_key$$3, "=", ":", &_key$$3);
					zephir_array_append(&set$$3, &_16$$11, PH_SEPARATE, "brisk/Toolkit/SQLBuilder/UpdateBuilder.zep", 50);
				} else {
					ZEPHIR_INIT_LNVAR(_17$$12);
					ZEPHIR_CONCAT_VSSV(&_17$$12, &_key$$3, "=", ":", &_key$$3);
					zephir_array_append(&set$$3, &_17$$12, PH_SEPARATE, "brisk/Toolkit/SQLBuilder/UpdateBuilder.zep", 52);
				}
			}
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&_val$$3);
		ZEPHIR_INIT_NVAR(&_key$$3);
		ZEPHIR_INIT_VAR(&_18$$3);
		zephir_fast_join_str(&_18$$3, SL(", "), &set$$3 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_19$$3);
		ZEPHIR_CONCAT_VSV(&_19$$3, &sql$$3, " SET ", &_18$$3);
		ZEPHIR_CPY_WRT(&sql$$3, &_19$$3);
		ZEPHIR_CALL_METHOD(&where$$3, this_ptr, "pickwherepart", NULL, 0);
		zephir_check_call_status();
		if (!ZEPHIR_IS_STRING(&where$$3, "")) {
			ZEPHIR_INIT_VAR(&_20$$13);
			ZEPHIR_CONCAT_VSV(&_20$$13, &sql$$3, " WHERE ", &where$$3);
			ZEPHIR_CPY_WRT(&sql$$3, &_20$$13);
		}
		RETURN_CCTOR(&sql$$3);
	}
	RETURN_MM_NULL();

}


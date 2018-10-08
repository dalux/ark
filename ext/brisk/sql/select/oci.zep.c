
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
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/string.h"
#include "kernel/concat.h"
#include "kernel/exception.h"
#include "kernel/object.h"


ZEPHIR_INIT_CLASS(Brisk_Sql_Select_Oci) {

	ZEPHIR_REGISTER_CLASS_EX(Brisk\\Sql\\Select, Oci, brisk, sql_select_oci, brisk_sql_select_ce, brisk_sql_select_oci_method_entry, 0);

	zend_declare_property_string(brisk_sql_select_oci_ce, SL("_db_type"), "Oci", ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * Put quotation marks on a field
 *
 * @param mixed value
 * @return string
 */
PHP_METHOD(Brisk_Sql_Select_Oci, quote) {

	HashTable *_3$$3;
	HashPosition _2$$3;
	zend_bool _0;
	zephir_fcall_cache_entry *_6 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *value, *_1 = NULL, *_7, _8, _9, *key$$3 = NULL, *val$$3 = NULL, **_4$$3, *_5$$4 = NULL;

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
		zephir_is_iterable(value, &_3$$3, &_2$$3, 1, 0, "brisk/Sql/Select/Oci.zep", 26);
		for (
		  ; zend_hash_get_current_data_ex(_3$$3, (void**) &_4$$3, &_2$$3) == SUCCESS
		  ; zend_hash_move_forward_ex(_3$$3, &_2$$3)
		) {
			ZEPHIR_GET_HMKEY(key$$3, _3$$3, _2$$3);
			ZEPHIR_GET_HVALUE(val$$3, _4$$3);
			ZEPHIR_CALL_METHOD(&_5$$4, this_ptr, "quote", &_6, 127, val$$3);
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
	ZEPHIR_SINIT_VAR(_8);
	ZVAL_STRING(&_8, "'", 0);
	ZEPHIR_SINIT_VAR(_9);
	ZVAL_STRING(&_9, "''", 0);
	zephir_fast_str_replace(&_7, &_8, &_9, value TSRMLS_CC);
	ZEPHIR_CONCAT_SVS(return_value, "'", _7, "'");
	RETURN_MM();

}

PHP_METHOD(Brisk_Sql_Select_Oci, pickLimitPart) {

	

	RETURN_NULL();

}

/**
 * Compile the select statment
 *
 * @return Select
 */
PHP_METHOD(Brisk_Sql_Select_Oci, compile) {

	zval *select = NULL, *where = NULL, *group = NULL, *having = NULL, *order = NULL, *limit = NULL, *_8, *_0$$3, *_1$$3 = NULL, *_3$$3, *_4$$4, *_5$$5, *_6$$6, *_7$$7, *offset$$8 = NULL, *_9$$8, _10$$9, _11$$9, *_12$$9 = NULL, _14$$10, *_15$$10 = NULL;
	zephir_fcall_cache_entry *_2 = NULL, *_13 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&select, this_ptr, "pickselectpart", NULL, 0);
	zephir_check_call_status();
	if (ZEPHIR_IS_STRING(select, "")) {
		ZEPHIR_INIT_VAR(_0$$3);
		object_init_ex(_0$$3, brisk_exception_sqlcompileexception_ce);
		ZEPHIR_INIT_VAR(_3$$3);
		ZVAL_STRING(_3$$3, "querier.sql_compile_failed", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_CE_STATIC(&_1$$3, brisk_kernel_language_ce, "get", &_2, 13, _3$$3);
		zephir_check_temp_parameter(_3$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, _0$$3, "__construct", NULL, 8, _1$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(_0$$3, "brisk/Sql/Select/Oci.zep", 48 TSRMLS_CC);
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
	_8 = zephir_fetch_nproperty_this(this_ptr, SL("_parts"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(limit);
	zephir_array_fetch_string(&limit, _8, SL("limit"), PH_NOISY, "brisk/Sql/Select/Oci.zep", 68 TSRMLS_CC);
	if (!ZEPHIR_IS_STRING(limit, "")) {
		_9$$8 = zephir_fetch_nproperty_this(this_ptr, SL("_parts"), PH_NOISY_CC);
		ZEPHIR_OBS_VAR(offset$$8);
		zephir_array_fetch_string(&offset$$8, _9$$8, SL("offset"), PH_NOISY, "brisk/Sql/Select/Oci.zep", 71 TSRMLS_CC);
		if (!ZEPHIR_IS_STRING(offset$$8, "")) {
			ZEPHIR_SINIT_VAR(_10$$9);
			zephir_add_function(&_10$$9, offset$$8, limit);
			ZEPHIR_SINIT_VAR(_11$$9);
			ZVAL_STRING(&_11$$9, "select * from (select tmptable1.*, rownum tmprn from (%s) tmptable1 where rownum<=%u) where tmprn>%u", 0);
			ZEPHIR_CALL_FUNCTION(&_12$$9, "sprintf", &_13, 12, &_11$$9, select, &_10$$9, offset$$8);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(select, _12$$9);
		} else {
			ZEPHIR_SINIT_VAR(_14$$10);
			ZVAL_STRING(&_14$$10, "select tmptable1.* from (%s) tmptable1 where rownum<=%u", 0);
			ZEPHIR_CALL_FUNCTION(&_15$$10, "sprintf", &_13, 12, &_14$$10, select, limit);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(select, _15$$10);
		}
	}
	zephir_update_property_this(getThis(), SL("_sql"), select TSRMLS_CC);
	if (1) {
		zephir_update_property_this(getThis(), SL("_compiled"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	} else {
		zephir_update_property_this(getThis(), SL("_compiled"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	}
	RETURN_THIS();

}


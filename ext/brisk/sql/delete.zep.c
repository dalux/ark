
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
#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/concat.h"


ZEPHIR_INIT_CLASS(Brisk_Sql_Delete) {

	ZEPHIR_REGISTER_CLASS_EX(Brisk\\Sql, Delete, brisk, sql_delete, brisk_sql_sqlfather_ce, brisk_sql_delete_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	return SUCCESS;

}

/**
 * Setting the from field in the sql statement
 *
 * @param mixed table
 * @return Delete
 */
PHP_METHOD(Brisk_Sql_Delete, from) {

	zval *table, *tables = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &table);



	if (!(Z_TYPE_P(table) == IS_ARRAY)) {
		ZEPHIR_INIT_VAR(tables);
		zephir_create_array(tables, 1, 0 TSRMLS_CC);
		zephir_array_fast_append(tables, table);
	} else {
		ZEPHIR_CPY_WRT(tables, table);
	}
	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "from", 1);
	zephir_update_property_array(this_ptr, SL("_parts"), _0, tables TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Compile the delete statment
 *
 * @return Delete
 */
PHP_METHOD(Brisk_Sql_Delete, compile) {

	zval *from = NULL, *_0, *alias = NULL, *table = NULL, *_5 = NULL, *delete = NULL, *where = NULL, *_1$$3, *_2$$3 = NULL, *_4$$3, *_6$$6;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_3 = NULL;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_parts"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(from);
	zephir_array_fetch_string(&from, _0, SL("from"), PH_NOISY, "brisk/Sql/Delete.zep", 35 TSRMLS_CC);
	if (zephir_fast_count_int(from TSRMLS_CC) == 0) {
		ZEPHIR_INIT_VAR(_1$$3);
		object_init_ex(_1$$3, brisk_exception_sqlcompileexception_ce);
		ZEPHIR_INIT_VAR(_4$$3);
		ZVAL_STRING(_4$$3, "querier.sql_compile_failed", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_CE_STATIC(&_2$$3, brisk_kernel_language_ce, "get", &_3, 12, _4$$3);
		zephir_check_temp_parameter(_4$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, _1$$3, "__construct", NULL, 7, _2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(_1$$3, "brisk/Sql/Delete.zep", 37 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_MAKE_REF(from);
	ZEPHIR_CALL_FUNCTION(&_5, "each", NULL, 13, from);
	ZEPHIR_UNREF(from);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(from, _5);
	ZEPHIR_OBS_VAR(alias);
	zephir_array_fetch_string(&alias, from, SL("key"), PH_NOISY, "brisk/Sql/Delete.zep", 41 TSRMLS_CC);
	ZEPHIR_OBS_VAR(table);
	zephir_array_fetch_string(&table, from, SL("value"), PH_NOISY, "brisk/Sql/Delete.zep", 42 TSRMLS_CC);
	ZEPHIR_CALL_FUNCTION(&_5, "is_integer", NULL, 14, alias);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(delete);
	if (zephir_is_true(_5)) {
		ZEPHIR_CONCAT_SV(delete, "DELETE FROM ", table);
	} else {
		ZEPHIR_CONCAT_SVSV(delete, "DELETE FROM ", table, " ", alias);
	}
	ZEPHIR_CALL_METHOD(&where, this_ptr, "pickwherepart", NULL, 0);
	zephir_check_call_status();
	if (!ZEPHIR_IS_STRING(where, "")) {
		ZEPHIR_INIT_VAR(_6$$6);
		ZEPHIR_CONCAT_VSV(_6$$6, delete, " WHERE ", where);
		ZEPHIR_CPY_WRT(delete, _6$$6);
	}
	zephir_update_property_this(getThis(), SL("_sql"), delete TSRMLS_CC);
	if (1) {
		zephir_update_property_this(getThis(), SL("_compiled"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	} else {
		zephir_update_property_this(getThis(), SL("_compiled"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	}
	RETURN_THIS();

}


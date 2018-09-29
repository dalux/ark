
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
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/concat.h"


ZEPHIR_INIT_CLASS(Brisk_Vendor_Querier_Delete) {

	ZEPHIR_REGISTER_CLASS_EX(Brisk\\Vendor\\Querier, Delete, brisk, vendor_querier_delete, brisk_vendor_querier_querierfather_ce, brisk_vendor_querier_delete_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	return SUCCESS;

}

/**
 * Setting the from field in the sql statement
 *
 * @param mixed table
 * @return Delete
 */
PHP_METHOD(Brisk_Vendor_Querier_Delete, from) {

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
 * Get the full sql statement
 *
 * @return string
 */
PHP_METHOD(Brisk_Vendor_Querier_Delete, getSQL) {

	zval *from = NULL, *_0, *alias$$3 = NULL, *table$$3 = NULL, *_1$$3 = NULL, *delete$$3 = NULL, *where$$3 = NULL, *_2$$6;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_parts"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(from);
	zephir_array_fetch_string(&from, _0, SL("from"), PH_NOISY, "brisk/Vendor/Querier/Delete.zep", 32 TSRMLS_CC);
	if (zephir_fast_count_int(from TSRMLS_CC) > 0) {
		ZEPHIR_MAKE_REF(from);
		ZEPHIR_CALL_FUNCTION(&_1$$3, "each", NULL, 5, from);
		ZEPHIR_UNREF(from);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(from, _1$$3);
		ZEPHIR_OBS_VAR(alias$$3);
		zephir_array_fetch_string(&alias$$3, from, SL("key"), PH_NOISY, "brisk/Vendor/Querier/Delete.zep", 36 TSRMLS_CC);
		ZEPHIR_OBS_VAR(table$$3);
		zephir_array_fetch_string(&table$$3, from, SL("value"), PH_NOISY, "brisk/Vendor/Querier/Delete.zep", 37 TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&_1$$3, "is_integer", NULL, 6, alias$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(delete$$3);
		if (zephir_is_true(_1$$3)) {
			ZEPHIR_CONCAT_SV(delete$$3, "DELETE FROM ", table$$3);
		} else {
			ZEPHIR_CONCAT_SVSV(delete$$3, "DELETE FROM ", table$$3, " ", alias$$3);
		}
		ZEPHIR_CALL_METHOD(&where$$3, this_ptr, "pickwherepart", NULL, 0);
		zephir_check_call_status();
		if (!ZEPHIR_IS_STRING(where$$3, "")) {
			ZEPHIR_INIT_VAR(_2$$6);
			ZEPHIR_CONCAT_VSV(_2$$6, delete$$3, " WHERE ", where$$3);
			ZEPHIR_CPY_WRT(delete$$3, _2$$6);
		}
		RETURN_CCTOR(delete$$3);
	}
	RETURN_MM_NULL();

}


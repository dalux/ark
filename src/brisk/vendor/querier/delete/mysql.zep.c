
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/concat.h"


ZEPHIR_INIT_CLASS(Brisk_Vendor_Querier_Delete_Mysql) {

	ZEPHIR_REGISTER_CLASS_EX(Brisk\\Vendor\\Querier\\Delete, Mysql, brisk, vendor_querier_delete_mysql, brisk_vendor_querier_delete_ce, brisk_vendor_querier_delete_mysql_method_entry, 0);

	zend_declare_property_string(brisk_vendor_querier_delete_mysql_ce, SL("_db_type"), "mysql", ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * Get the full sql statement
 *
 * @return string
 */
PHP_METHOD(Brisk_Vendor_Querier_Delete_Mysql, getSQL) {

	zval *from = NULL, *_0, *alias$$3 = NULL, *table$$3 = NULL, *_1$$3 = NULL, *delete$$3 = NULL, *where$$3 = NULL, *_2$$5;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_parts"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(from);
	zephir_array_fetch_string(&from, _0, SL("from"), PH_NOISY, "brisk/Vendor/Querier/Delete/Mysql.zep", 18 TSRMLS_CC);
	if (zephir_fast_count_int(from TSRMLS_CC) > 0) {
		ZEPHIR_MAKE_REF(from);
		ZEPHIR_CALL_FUNCTION(&_1$$3, "each", NULL, 5, from);
		ZEPHIR_UNREF(from);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(from, _1$$3);
		ZEPHIR_OBS_VAR(alias$$3);
		zephir_array_fetch_long(&alias$$3, from, 0, PH_NOISY, "brisk/Vendor/Querier/Delete/Mysql.zep", 22 TSRMLS_CC);
		ZEPHIR_OBS_VAR(table$$3);
		zephir_array_fetch_long(&table$$3, from, 1, PH_NOISY, "brisk/Vendor/Querier/Delete/Mysql.zep", 23 TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&_1$$3, "is_integer", NULL, 6, alias$$3);
		zephir_check_call_status();
		if (zephir_is_true(_1$$3)) {
			ZEPHIR_INIT_NVAR(alias$$3);
			ZVAL_STRING(alias$$3, "", 1);
		}
		ZEPHIR_INIT_VAR(delete$$3);
		ZEPHIR_CONCAT_SVSV(delete$$3, "DELETE FROM ", table$$3, " ", alias$$3);
		ZEPHIR_CALL_METHOD(&where$$3, this_ptr, "pickwherepart", NULL, 0);
		zephir_check_call_status();
		if (!ZEPHIR_IS_STRING(where$$3, "")) {
			ZEPHIR_INIT_VAR(_2$$5);
			ZEPHIR_CONCAT_VSV(_2$$5, delete$$3, " WHERE ", where$$3);
			ZEPHIR_CPY_WRT(delete$$3, _2$$5);
		}
		RETURN_CCTOR(delete$$3);
	}
	RETURN_MM_NULL();

}

